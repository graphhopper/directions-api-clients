{-# LANGUAGE DataKinds #-}
{-# LANGUAGE DeriveGeneric #-}
{-# LANGUAGE DeriveTraversable #-}
{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE RecordWildCards #-}
{-# LANGUAGE TypeFamilies #-}
{-# LANGUAGE TypeOperators #-}
{-# LANGUAGE ViewPatterns #-}
{-# OPTIONS_GHC
-fno-warn-unused-binds -fno-warn-unused-imports -fcontext-stack=328 #-}

module GraphHopperDirections.API
  -- * Client and Server
  ( ServerConfig(..)
  , GraphHopperDirectionsBackend
  , createGraphHopperDirectionsClient
  , runGraphHopperDirectionsServer
  , runGraphHopperDirectionsClient
  , runGraphHopperDirectionsClientWithManager
  , GraphHopperDirectionsClient
  -- ** Servant
  , GraphHopperDirectionsAPI
  ) where

import GraphHopperDirections.Types

import Control.Monad.Except (ExceptT)
import Control.Monad.IO.Class
import Data.Aeson (Value)
import Data.Coerce (coerce)
import Data.Function ((&))
import qualified Data.Map as Map
import Data.Monoid ((<>))
import Data.Proxy (Proxy(..))
import Data.Text (Text)
import qualified Data.Text as T
import GHC.Exts (IsString(..))
import GHC.Generics (Generic)
import Network.HTTP.Client (Manager, defaultManagerSettings, newManager)
import Network.HTTP.Types.Method (methodOptions)
import qualified Network.Wai.Handler.Warp as Warp
import Servant (ServantErr, serve)
import Servant.API
import Servant.API.Verbs (StdMethod(..), Verb)
import Servant.Client (Scheme(Http), ServantError, client)
import Servant.Common.BaseUrl (BaseUrl(..))
import Web.HttpApiData




-- For the form data code generation.
lookupEither :: FromHttpApiData b => Text -> [(Text, Text)] -> Either String b
lookupEither key assocs =
  case lookup key assocs of
    Nothing -> Left $ "Could not find parameter " <> (T.unpack key) <> " in form data"
    Just value ->
      case parseQueryParam value of
        Left result -> Left $ T.unpack result
        Right result -> Right $ result

-- | Servant type-level API, generated from the Swagger spec for GraphHopperDirections.
type GraphHopperDirectionsAPI
    =    "geocode" :> QueryParam "q" Text :> QueryParam "locale" Text :> QueryParam "limit" Int :> QueryParam "reverse" Bool :> QueryParam "point" Text :> QueryParam "provider" Text :> QueryParam "key" Text :> Verb 'GET 200 '[JSON] GeocodingResponse -- 'geocodeGet' route
    :<|> "isochrone" :> QueryParam "point" Text :> QueryParam "time_limit" Int :> QueryParam "distance_limit" Int :> QueryParam "vehicle" Text :> QueryParam "buckets" Int :> QueryParam "reverse_flow" Bool :> QueryParam "key" Text :> Verb 'GET 200 '[JSON] IsochroneResponse -- 'isochroneGet' route
    :<|> "matrix" :> QueryParam "point" (QueryList 'MultiParamArray (Text)) :> QueryParam "from_point" Text :> QueryParam "to_point" Text :> QueryParam "out_array" (QueryList 'MultiParamArray (Text)) :> QueryParam "vehicle" Text :> QueryParam "key" Text :> Verb 'GET 200 '[JSON] MatrixResponse -- 'matrixGet' route
    :<|> "matrix" :> QueryParam "key" Text :> ReqBody '[JSON] MatrixRequest :> Verb 'POST 200 '[JSON] MatrixResponse -- 'matrixPost' route
    :<|> "route" :> QueryParam "point" (QueryList 'MultiParamArray (Text)) :> QueryParam "locale" Text :> QueryParam "instructions" Bool :> QueryParam "vehicle" Text :> QueryParam "elevation" Bool :> QueryParam "points_encoded" Bool :> QueryParam "calc_points" Bool :> QueryParam "point_hint" (QueryList 'MultiParamArray (Text)) :> QueryParam "ch.disable" Bool :> QueryParam "weighting" Text :> QueryParam "edge_traversal" Bool :> QueryParam "algorithm" Text :> QueryParam "heading" Int :> QueryParam "heading_penalty" Int :> QueryParam "pass_through" Bool :> QueryParam "round_trip.distance" Int :> QueryParam "round_trip.seed" Integer :> QueryParam "alternative_route.max_paths" Int :> QueryParam "alternative_route.max_weight_factor" Int :> QueryParam "alternative_route.max_share_factor" Int :> QueryParam "key" Text :> Verb 'GET 200 '[JSON] RouteResponse -- 'routeGet' route
    :<|> "vrp" :> "solution" :> Capture "jobId" Text :> QueryParam "key" Text :> Verb 'GET 200 '[JSON] Response -- 'getSolution' route
    :<|> "vrp" :> "optimize" :> QueryParam "key" Text :> ReqBody '[JSON] Request :> Verb 'POST 200 '[JSON] JobId -- 'postVrp' route

-- | Server or client configuration, specifying the host and port to query or serve on.
data ServerConfig = ServerConfig
  { configHost :: String  -- ^ Hostname to serve on, e.g. "127.0.0.1"
  , configPort :: Int      -- ^ Port to serve on, e.g. 8080
  } deriving (Eq, Ord, Show, Read)

-- | List of elements parsed from a query.
newtype QueryList (p :: CollectionFormat) a = QueryList
  { fromQueryList :: [a]
  } deriving (Functor, Applicative, Monad, Foldable, Traversable)

-- | Formats in which a list can be encoded into a HTTP path.
data CollectionFormat
  = CommaSeparated -- ^ CSV format for multiple parameters.
  | SpaceSeparated -- ^ Also called "SSV"
  | TabSeparated -- ^ Also called "TSV"
  | PipeSeparated -- ^ `value1|value2|value2`
  | MultiParamArray -- ^ Using multiple GET parameters, e.g. `foo=bar&foo=baz`. Only for GET params.

instance FromHttpApiData a => FromHttpApiData (QueryList 'CommaSeparated a) where
  parseQueryParam = parseSeparatedQueryList ','

instance FromHttpApiData a => FromHttpApiData (QueryList 'TabSeparated a) where
  parseQueryParam = parseSeparatedQueryList '\t'

instance FromHttpApiData a => FromHttpApiData (QueryList 'SpaceSeparated a) where
  parseQueryParam = parseSeparatedQueryList ' '

instance FromHttpApiData a => FromHttpApiData (QueryList 'PipeSeparated a) where
  parseQueryParam = parseSeparatedQueryList '|'

instance FromHttpApiData a => FromHttpApiData (QueryList 'MultiParamArray a) where
  parseQueryParam = error "unimplemented FromHttpApiData for MultiParamArray collection format"

parseSeparatedQueryList :: FromHttpApiData a => Char -> Text -> Either Text (QueryList p a)
parseSeparatedQueryList char = fmap QueryList . mapM parseQueryParam . T.split (== char)

instance ToHttpApiData a => ToHttpApiData (QueryList 'CommaSeparated a) where
  toQueryParam = formatSeparatedQueryList ','

instance ToHttpApiData a => ToHttpApiData (QueryList 'TabSeparated a) where
  toQueryParam = formatSeparatedQueryList '\t'

instance ToHttpApiData a => ToHttpApiData (QueryList 'SpaceSeparated a) where
  toQueryParam = formatSeparatedQueryList ' '

instance ToHttpApiData a => ToHttpApiData (QueryList 'PipeSeparated a) where
  toQueryParam = formatSeparatedQueryList '|'

instance ToHttpApiData a => ToHttpApiData (QueryList 'MultiParamArray a) where
  toQueryParam = error "unimplemented ToHttpApiData for MultiParamArray collection format"

formatSeparatedQueryList :: ToHttpApiData a => Char ->  QueryList p a -> Text
formatSeparatedQueryList char = T.intercalate (T.singleton char) . map toQueryParam . fromQueryList


-- | Backend for GraphHopperDirections.
-- The backend can be used both for the client and the server. The client generated from the GraphHopperDirections Swagger spec
-- is a backend that executes actions by sending HTTP requests (see @createGraphHopperDirectionsClient@). Alternatively, provided
-- a backend, the API can be served using @runGraphHopperDirectionsServer@.
data GraphHopperDirectionsBackend m = GraphHopperDirectionsBackend
  { geocodeGet :: Maybe Text -> Maybe Text -> Maybe Int -> Maybe Bool -> Maybe Text -> Maybe Text -> Maybe Text -> m GeocodingResponse{- ^ This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/  -}
  , isochroneGet :: Maybe Text -> Maybe Int -> Maybe Int -> Maybe Text -> Maybe Int -> Maybe Bool -> Maybe Text -> m IsochroneResponse{- ^ The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**.  -}
  , matrixGet :: Maybe [Text] -> Maybe Text -> Maybe Text -> Maybe [Text] -> Maybe Text -> Maybe Text -> m MatrixResponse{- ^ The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called 'via points', which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this.  -}
  , matrixPost :: Maybe Text -> MatrixRequest -> m MatrixResponse{- ^ The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request.  -}
  , routeGet :: Maybe [Text] -> Maybe Text -> Maybe Bool -> Maybe Text -> Maybe Bool -> Maybe Bool -> Maybe Bool -> Maybe [Text] -> Maybe Bool -> Maybe Text -> Maybe Bool -> Maybe Text -> Maybe Int -> Maybe Int -> Maybe Bool -> Maybe Int -> Maybe Integer -> Maybe Int -> Maybe Int -> Maybe Int -> Maybe Text -> m RouteResponse{- ^ The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions -}
  , getSolution :: Text -> Maybe Text -> m Response{- ^ This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent.  -}
  , postVrp :: Maybe Text -> Request -> m JobId{- ^ This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution. -}
  }

newtype GraphHopperDirectionsClient a = GraphHopperDirectionsClient
  { runClient :: Manager -> BaseUrl -> ExceptT ServantError IO a
  } deriving Functor

instance Applicative GraphHopperDirectionsClient where
  pure x = GraphHopperDirectionsClient (\_ _ -> pure x)
  (GraphHopperDirectionsClient f) <*> (GraphHopperDirectionsClient x) =
    GraphHopperDirectionsClient (\manager url -> f manager url <*> x manager url)

instance Monad GraphHopperDirectionsClient where
  (GraphHopperDirectionsClient a) >>= f =
    GraphHopperDirectionsClient (\manager url -> do
      value <- a manager url
      runClient (f value) manager url)

instance MonadIO GraphHopperDirectionsClient where
  liftIO io = GraphHopperDirectionsClient (\_ _ -> liftIO io)

createGraphHopperDirectionsClient :: GraphHopperDirectionsBackend GraphHopperDirectionsClient
createGraphHopperDirectionsClient = GraphHopperDirectionsBackend{..}
  where
    ((coerce -> geocodeGet) :<|>
     (coerce -> isochroneGet) :<|>
     (coerce -> matrixGet) :<|>
     (coerce -> matrixPost) :<|>
     (coerce -> routeGet) :<|>
     (coerce -> getSolution) :<|>
     (coerce -> postVrp)) = client (Proxy :: Proxy GraphHopperDirectionsAPI)

-- | Run requests in the GraphHopperDirectionsClient monad.
runGraphHopperDirectionsClient :: ServerConfig -> GraphHopperDirectionsClient a -> ExceptT ServantError IO a
runGraphHopperDirectionsClient clientConfig cl = do
  manager <- liftIO $ newManager defaultManagerSettings
  runGraphHopperDirectionsClientWithManager manager clientConfig cl

-- | Run requests in the GraphHopperDirectionsClient monad using a custom manager.
runGraphHopperDirectionsClientWithManager :: Manager -> ServerConfig -> GraphHopperDirectionsClient a -> ExceptT ServantError IO a
runGraphHopperDirectionsClientWithManager manager clientConfig cl =
  runClient cl manager $ BaseUrl Http (configHost clientConfig) (configPort clientConfig) ""

-- | Run the GraphHopperDirections server at the provided host and port.
runGraphHopperDirectionsServer :: MonadIO m => ServerConfig -> GraphHopperDirectionsBackend (ExceptT ServantErr IO)  -> m ()
runGraphHopperDirectionsServer ServerConfig{..} backend =
  liftIO $ Warp.runSettings warpSettings $ serve (Proxy :: Proxy GraphHopperDirectionsAPI) (serverFromBackend backend)
  where
    warpSettings = Warp.defaultSettings & Warp.setPort configPort & Warp.setHost (fromString configHost)
    serverFromBackend GraphHopperDirectionsBackend{..} =
      (coerce geocodeGet :<|>
       coerce isochroneGet :<|>
       coerce matrixGet :<|>
       coerce matrixPost :<|>
       coerce routeGet :<|>
       coerce getSolution :<|>
       coerce postVrp)
