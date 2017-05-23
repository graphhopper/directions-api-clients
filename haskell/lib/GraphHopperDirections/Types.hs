{-# LANGUAGE DeriveGeneric #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# OPTIONS_GHC -fno-warn-unused-binds -fno-warn-unused-imports #-}

module GraphHopperDirections.Types (
    Activity (..),
    Address (..),
    Algorithm (..),
    Break (..),
    Configuration (..),
    CostMatrix (..),
    CostMatrix_data (..),
    CostMatrix_data_info (..),
    GHError (..),
    GHError_hints (..),
    GHGeocodingLocation (..),
    GHGeocodingPoint (..),
    GHGeocodingResponse (..),
    GHIsochroneResponse (..),
    GHIsochroneResponsePolygon (..),
    GHIsochroneResponsePolygon_geometry (..),
    GHIsochroneResponsePolygon_properties (..),
    GHMatrixRequest (..),
    GHMatrixResponse (..),
    GHResponseCoordinates (..),
    GHResponseCoordinatesArray (..),
    GHResponseInfo (..),
    GHResponseInstruction (..),
    GHResponseInstructions (..),
    GHRouteResponse (..),
    GHRouteResponsePath (..),
    JobId (..),
    Location (..),
    Objective (..),
    Relation (..),
    Request (..),
    Response (..),
    Route (..),
    RoutePoint (..),
    Routing (..),
    Service (..),
    Shipment (..),
    Solution (..),
    Solution_unassigned (..),
    Stop (..),
    TimeWindow (..),
    Vehicle (..),
    VehicleType (..),
    ) where

import Data.List (stripPrefix)
import Data.Maybe (fromMaybe)
import Data.Aeson (Value, FromJSON(..), ToJSON(..), genericToJSON, genericParseJSON)
import Data.Aeson.Types (Options(..), defaultOptions)
import Data.Text (Text)
import qualified Data.Text as T
import qualified Data.Map as Map
import GHC.Generics (Generic)
import Data.Function ((&))


-- | 
data Activity = Activity
    { activityType :: Text -- ^ type of activity
    , activityId :: Text -- ^ id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to
    , activityLocationId :: Text -- ^ id that refers to address
    , activityArrTime :: Integer -- ^ arrival time at this activity in ms
    , activityEndTime :: Integer -- ^ end time of and thus departure time at this activity
    , activityWaitingTime :: Integer -- ^ waiting time at this activity in ms
    , activityDistance :: Integer -- ^ cumulated distance from start to this activity in m
    , activityDrivingTime :: Integer -- ^ driving time of driver in ms
    , activityLoadBefore :: [Int] -- ^ Array with size/capacity dimensions before this activity
    , activityLoadAfter :: [Int] -- ^ Array with size/capacity dimensions after this activity
    } deriving (Show, Eq, Generic)

instance FromJSON Activity where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "activity")
instance ToJSON Activity where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "activity")

-- | 
data Address = Address
    { addressLocationId :: Text -- ^ Unique identifier of location
    , addressName :: Text -- ^ name of location, e.g. street name plus house number
    , addressLon :: Double -- ^ longitude
    , addressLat :: Double -- ^ latitude
    } deriving (Show, Eq, Generic)

instance FromJSON Address where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "address")
instance ToJSON Address where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "address")

-- | 
data Algorithm = Algorithm
    { algorithmProblemType :: Text -- ^ 
    , algorithmObjective :: Text -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON Algorithm where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "algorithm")
instance ToJSON Algorithm where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "algorithm")

-- | 
data Break = Break
    { breakEarliest :: Integer -- ^ earliest start of break
    , breakLatest :: Integer -- ^ latest start of break
    , breakDuration :: Integer -- ^ duration of break
    , breakMaxDrivingTime :: Integer -- ^ max driving time without break
    , breakInitialDrivingTime :: Integer -- ^ initial driving time, i.e. the time your driver has already spent for driving
    , breakPossibleSplit :: [Integer] -- ^ array of splits
    } deriving (Show, Eq, Generic)

instance FromJSON Break where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "break")
instance ToJSON Break where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "break")

-- | 
data Configuration = Configuration
    { configurationRouting :: Routing -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON Configuration where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "configuration")
instance ToJSON Configuration where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "configuration")

-- | 
data CostMatrix = CostMatrix
    { costMatrixType :: Text -- ^ type of cost matrix, currently default or google are supported
    , costMatrixUrl :: Text -- ^ URL of matrix service
    , costMatrixLocationIds :: [Text] -- ^ 
    , costMatrixData :: CostMatrix_data -- ^ 
    , costMatrixProfile :: Text -- ^ vehicle profile or empty if catch all fallback
    } deriving (Show, Eq, Generic)

instance FromJSON CostMatrix where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "costMatrix")
instance ToJSON CostMatrix where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "costMatrix")

-- | JSON data of matrix response
data CostMatrix_data = CostMatrix_data
    { costMatrixDataTimes :: [[Integer]] -- ^ 
    , costMatrixDataDistances :: [[Double]] -- ^ 
    , costMatrixDataInfo :: CostMatrix_data_info -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON CostMatrix_data where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "costMatrixData")
instance ToJSON CostMatrix_data where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "costMatrixData")

-- | Additional information for your request
data CostMatrix_data_info = CostMatrix_data_info
    { costMatrixDataInfoCopyrights :: [Text] -- ^ 
    , costMatrixDataInfoTook :: Double -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON CostMatrix_data_info where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "costMatrixDataInfo")
instance ToJSON CostMatrix_data_info where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "costMatrixDataInfo")

-- | 
data GHError = GHError
    { gHErrorCode :: Int -- ^ 
    , gHErrorMessage :: Text -- ^ 
    , gHErrorHints :: [GHError_hints] -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHError where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHError")
instance ToJSON GHError where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHError")

-- | 
data GHError_hints = GHError_hints
    { gHErrorHintsMessage :: Text -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHError_hints where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHErrorHints")
instance ToJSON GHError_hints where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHErrorHints")

-- | 
data GHGeocodingLocation = GHGeocodingLocation
    { gHGeocodingLocationPoint :: GHGeocodingPoint -- ^ 
    , gHGeocodingLocationOsmId :: Text -- ^ OSM Id
    , gHGeocodingLocationOsmType :: Text -- ^ N = node, R = relation, W = way
    , gHGeocodingLocationName :: Text -- ^ 
    , gHGeocodingLocationCountry :: Text -- ^ 
    , gHGeocodingLocationCity :: Text -- ^ 
    , gHGeocodingLocationState :: Text -- ^ 
    , gHGeocodingLocationStreet :: Text -- ^ 
    , gHGeocodingLocationHousenumber :: Text -- ^ 
    , gHGeocodingLocationPostcode :: Text -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHGeocodingLocation where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHGeocodingLocation")
instance ToJSON GHGeocodingLocation where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHGeocodingLocation")

-- | 
data GHGeocodingPoint = GHGeocodingPoint
    { gHGeocodingPointLat :: Double -- ^ Latitude
    , gHGeocodingPointLng :: Double -- ^ Longitude
    } deriving (Show, Eq, Generic)

instance FromJSON GHGeocodingPoint where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHGeocodingPoint")
instance ToJSON GHGeocodingPoint where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHGeocodingPoint")

-- | 
data GHGeocodingResponse = GHGeocodingResponse
    { gHGeocodingResponseHits :: [GHGeocodingLocation] -- ^ 
    , gHGeocodingResponseLocale :: Text -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHGeocodingResponse where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHGeocodingResponse")
instance ToJSON GHGeocodingResponse where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHGeocodingResponse")

-- | 
data GHIsochroneResponse = GHIsochroneResponse
    { gHIsochroneResponsePolygons :: [GHIsochroneResponsePolygon] -- ^ 
    , gHIsochroneResponseCopyrights :: [Text] -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHIsochroneResponse where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHIsochroneResponse")
instance ToJSON GHIsochroneResponse where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHIsochroneResponse")

-- | A found path
data GHIsochroneResponsePolygon = GHIsochroneResponsePolygon
    { gHIsochroneResponsePolygonProperties :: GHIsochroneResponsePolygon_properties -- ^ 
    , gHIsochroneResponsePolygonType :: Text -- ^ 
    , gHIsochroneResponsePolygonGeometry :: GHIsochroneResponsePolygon_geometry -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHIsochroneResponsePolygon where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHIsochroneResponsePolygon")
instance ToJSON GHIsochroneResponsePolygon where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHIsochroneResponsePolygon")

-- | 
data GHIsochroneResponsePolygon_geometry = GHIsochroneResponsePolygon_geometry
    { gHIsochroneResponsePolygonGeometryType :: Text -- ^ 
    , gHIsochroneResponsePolygonGeometryCoordinates :: GHResponseCoordinatesArray -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHIsochroneResponsePolygon_geometry where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHIsochroneResponsePolygonGeometry")
instance ToJSON GHIsochroneResponsePolygon_geometry where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHIsochroneResponsePolygonGeometry")

-- | 
data GHIsochroneResponsePolygon_properties = GHIsochroneResponsePolygon_properties
    { gHIsochroneResponsePolygonPropertiesBucket :: Int -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHIsochroneResponsePolygon_properties where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHIsochroneResponsePolygonProperties")
instance ToJSON GHIsochroneResponsePolygon_properties where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHIsochroneResponsePolygonProperties")

-- | 
data GHMatrixRequest = GHMatrixRequest
    { gHMatrixRequestPoints :: [[Double]] -- ^ Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format longitude,latitude.
    , gHMatrixRequestFromPoints :: Text -- ^ The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format longitude,latitude.
    , gHMatrixRequestToPoints :: Text -- ^ The destination points for the routes. Is a string with the format longitude,latitude.
    , gHMatrixRequestOutArrays :: [Text] -- ^ Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&amp;out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
    , gHMatrixRequestVehicle :: Text -- ^ The vehicle for which the route should be calculated. Other vehicles are foot, bike, mtb, racingbike, motorcycle, small_truck, bus and truck. See here for the details.
    } deriving (Show, Eq, Generic)

instance FromJSON GHMatrixRequest where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHMatrixRequest")
instance ToJSON GHMatrixRequest where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHMatrixRequest")

-- | 
data GHMatrixResponse = GHMatrixResponse
    { gHMatrixResponseDistances :: [[Double]] -- ^ 
    , gHMatrixResponseTimes :: [[Double]] -- ^ 
    , gHMatrixResponseWeights :: [[Double]] -- ^ 
    , gHMatrixResponseInfo :: GHResponseInfo -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHMatrixResponse where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHMatrixResponse")
instance ToJSON GHMatrixResponse where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHMatrixResponse")

-- | 
data GHResponseCoordinates = GHResponseCoordinates
    { gHResponseCoordinatesCoordinates :: GHResponseCoordinatesArray -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHResponseCoordinates where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHResponseCoordinates")
instance ToJSON GHResponseCoordinates where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHResponseCoordinates")

-- | An array containing coordinates
newtype GHResponseCoordinatesArray = GHResponseCoordinatesArray { unGHResponseCoordinatesArray :: List }
  deriving (Show, Eq, FromJSON, ToJSON, Generic)

-- | Additional information for your request
data GHResponseInfo = GHResponseInfo
    { gHResponseInfoCopyrights :: [Text] -- ^ 
    , gHResponseInfoTook :: Int -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHResponseInfo where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHResponseInfo")
instance ToJSON GHResponseInfo where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHResponseInfo")

-- | 
data GHResponseInstruction = GHResponseInstruction
    { gHResponseInstructionText :: Text -- ^ A description what the user has to do in order to follow the route. The language depends on the locale parameter.
    , gHResponseInstructionStreetName :: Text -- ^ The name of the street to turn onto in order to follow the route.
    , gHResponseInstructionDistance :: Double -- ^ The distance for this instruction, in meter
    , gHResponseInstructionTime :: Int -- ^ The duration for this instruction, in ms
    , gHResponseInstructionInterval :: [Int] -- ^ An array containing the first and the last index (relative to paths[0].points) of the points for this instruction. This is useful to know for which part of the route the instructions are valid.
    , gHResponseInstructionSign :: Int -- ^ A number which specifies the sign to show e.g. for right turn etc <br>TURN_SHARP_LEFT = -3<br>TURN_LEFT = -2<br>TURN_SLIGHT_LEFT = -1<br>CONTINUE_ON_STREET = 0<br>TURN_SLIGHT_RIGHT = 1<br>TURN_RIGHT = 2<br>TURN_SHARP_RIGHT = 3<br>FINISH = 4<br>VIA_REACHED = 5<br>USE_ROUNDABOUT = 6
    , gHResponseInstructionAnnotationText :: Text -- ^ optional - A text describing the instruction in more detail, e.g. like surface of the way, warnings or involved costs.
    , gHResponseInstructionAnnotationImportance :: Int -- ^ optional - 0 stands for INFO, 1 for warning, 2 for costs, 3 for costs and warning
    , gHResponseInstructionExitNumber :: Int -- ^ optional - Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout.
    , gHResponseInstructionTurnAngle :: Double -- ^ optional - Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout - 0&lt;r&lt;2*PI for clockwise and -2PI&lt;r&lt;0 for counterclockwise transit. Null if the direction of rotation is undefined.
    } deriving (Show, Eq, Generic)

instance FromJSON GHResponseInstruction where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHResponseInstruction")
instance ToJSON GHResponseInstruction where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHResponseInstruction")

-- | Contains information about the instructions for this route. The last instruction is always the Finish instruction and takes 0ms and 0meter. Keep in mind that instructions are currently under active development and can sometimes contain misleading information, so, make sure you always show an image of the map at the same time when navigating your users!
newtype GHResponseInstructions = GHResponseInstructions { unGHResponseInstructions :: GHResponseInstruction }
  deriving (Show, Eq, FromJSON, ToJSON, Generic)

-- | 
data GHRouteResponse = GHRouteResponse
    { gHRouteResponsePaths :: [GHRouteResponsePath] -- ^ 
    , gHRouteResponseInfo :: GHResponseInfo -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHRouteResponse where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHRouteResponse")
instance ToJSON GHRouteResponse where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHRouteResponse")

-- | A found path
data GHRouteResponsePath = GHRouteResponsePath
    { gHRouteResponsePathDistance :: Double -- ^ The total distance of the route, in meter
    , gHRouteResponsePathTime :: Integer -- ^ The total time of the route, in ms
    , gHRouteResponsePathAscend :: Double -- ^ 
    , gHRouteResponsePathDescend :: Double -- ^ The total descend (downhill) of the route, in meter
    , gHRouteResponsePathPoints :: GHResponseCoordinates -- ^ 
    , gHRouteResponsePathPointsEncoded :: Bool -- ^ Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version
    , gHRouteResponsePathBbox :: [Double] -- ^ The bounding box of the route, format <br> minLon, minLat, maxLon, maxLat
    , gHRouteResponsePathSnappedWaypoints :: GHResponseCoordinates -- ^ 
    , gHRouteResponsePathInstructions :: GHResponseInstructions -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON GHRouteResponsePath where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "gHRouteResponsePath")
instance ToJSON GHRouteResponsePath where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "gHRouteResponsePath")

-- | 
data JobId = JobId
    { jobIdJobId :: Text -- ^ unique id for your job/request with which you can fetch your solution
    } deriving (Show, Eq, Generic)

instance FromJSON JobId where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "jobId")
instance ToJSON JobId where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "jobId")

-- | 
data Location = Location
    { locationLon :: Double -- ^ longitude
    , locationLat :: Double -- ^ latitude
    } deriving (Show, Eq, Generic)

instance FromJSON Location where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "location")
instance ToJSON Location where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "location")

-- | 
data Objective = Objective
    { objectiveType :: Text -- ^ type of objective function, i.e. min or min-max 
    , objectiveValue :: Text -- ^ objective function value
    } deriving (Show, Eq, Generic)

instance FromJSON Objective where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "objective")
instance ToJSON Objective where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "objective")

-- | 
data Relation = Relation
    { relationType :: Text -- ^ identifier of relation
    , relationIds :: [Text] -- ^ An array of ids that should be related
    , relationVehicleId :: Text -- ^ vehicle id
    } deriving (Show, Eq, Generic)

instance FromJSON Relation where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "relation")
instance ToJSON Relation where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "relation")

-- | 
data Request = Request
    { requestVehicles :: [Vehicle] -- ^ An array of vehicles that can be employed
    , requestVehicleTypes :: [VehicleType] -- ^ An array of vehicle types
    , requestServices :: [Service] -- ^ An array of services
    , requestShipments :: [Shipment] -- ^ An array of shipments
    , requestRelations :: [Relation] -- ^ An array of relations
    , requestAlgorithm :: Algorithm -- ^ 
    , requestObjectives :: [Objective] -- ^ An array of objectives
    , requestCostMatrices :: [CostMatrix] -- ^ An array of cost matrices
    , requestConfiguration :: Configuration -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON Request where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "request")
instance ToJSON Request where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "request")

-- | 
data Response = Response
    { responseCopyrights :: [Text] -- ^ 
    , responseJobId :: Text -- ^ unique identify of job - which you get when posting your request to the large problem solver
    , responseStatus :: Text -- ^ indicates the current status of the job
    , responseWaitingInQueue :: Integer -- ^ waiting time in ms
    , responseProcessingTime :: Integer -- ^ processing time in ms. if job is still waiting in queue, processing_time is 0
    , responseSolution :: Solution -- ^ the solution. only available if status field indicates finished
    } deriving (Show, Eq, Generic)

instance FromJSON Response where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "response")
instance ToJSON Response where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "response")

-- | 
data Route = Route
    { routeVehicleId :: Text -- ^ id of vehicle that operates route
    , routeDistance :: Integer -- ^ distance of route in meter
    , routeTransportTime :: Integer -- ^ transport time of route in ms
    , routeCompletionTime :: Integer -- ^ completion time of route in ms
    , routeWaitingTime :: Integer -- ^ waiting time of route in ms
    , routeActivities :: [Activity] -- ^ array of activities
    , routePoints :: [RoutePoint] -- ^ array of route planning points
    } deriving (Show, Eq, Generic)

instance FromJSON Route where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "route")
instance ToJSON Route where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "route")

-- | 
data RoutePoint = RoutePoint
    { routePointType :: Text -- ^ 
    , routePointCoordinates :: [Value] -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON RoutePoint where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "routePoint")
instance ToJSON RoutePoint where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "routePoint")

-- | 
data Routing = Routing
    { routingCalcPoints :: Bool -- ^ indicates whether solution should come with route geometries
    } deriving (Show, Eq, Generic)

instance FromJSON Routing where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "routing")
instance ToJSON Routing where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "routing")

-- | 
data Service = Service
    { serviceId :: Text -- ^ Unique identifier of service
    , serviceType :: Text -- ^ type of service
    , servicePriority :: Int -- ^ priority of service
    , serviceName :: Text -- ^ name of service
    , serviceAddress :: Address -- ^ 
    , serviceDuration :: Integer -- ^ duration of service, i.e. time in ms the corresponding activity takes
    , servicePreparationTime :: Integer -- ^ preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location
    , serviceTimeWindows :: [TimeWindow] -- ^ array of time windows. currently, only a single time window is allowed
    , serviceSize :: [Int] -- ^ array of capacity dimensions
    , serviceRequiredSkills :: [Text] -- ^ array of required skills
    , serviceAllowedVehicles :: [Text] -- ^ array of allowed vehicle ids
    } deriving (Show, Eq, Generic)

instance FromJSON Service where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "service")
instance ToJSON Service where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "service")

-- | 
data Shipment = Shipment
    { shipmentId :: Text -- ^ Unique identifier of service
    , shipmentName :: Text -- ^ name of shipment
    , shipmentPriority :: Int -- ^ priority of service, i.e. 1 = high, 2 = normal, 3 = low. default is 2.
    , shipmentPickup :: Stop -- ^ 
    , shipmentDelivery :: Stop -- ^ 
    , shipmentSize :: [Int] -- ^ array of capacity dimensions
    , shipmentRequiredSkills :: [Text] -- ^ array of required skills
    , shipmentAllowedVehicles :: [Text] -- ^ array of allowed vehicle ids
    } deriving (Show, Eq, Generic)

instance FromJSON Shipment where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "shipment")
instance ToJSON Shipment where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "shipment")

-- | 
data Solution = Solution
    { solutionCosts :: Int -- ^ overall costs of solution
    , solutionDistance :: Int -- ^ overall travel distance in meters
    , solutionTime :: Integer -- ^ overall transport time in ms
    , solutionTransportTime :: Integer -- ^ overall transport time in ms
    , solutionMaxOperationTime :: Integer -- ^ operation time of the longest route in ms
    , solutionWaitingTime :: Integer -- ^ total waiting time in ms
    , solutionNoVehicles :: Int -- ^ number of employed vehicles
    , solutionNoUnassigned :: Int -- ^ number of jobs that could not be assigned to final solution
    , solutionRoutes :: [Route] -- ^ An array of routes
    , solutionUnassigned :: Solution_unassigned -- ^ 
    } deriving (Show, Eq, Generic)

instance FromJSON Solution where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "solution")
instance ToJSON Solution where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "solution")

-- | 
data Solution_unassigned = Solution_unassigned
    { solutionUnassignedServices :: [Text] -- ^ An array of ids of unassigned services
    , solutionUnassignedShipments :: [Text] -- ^ An array of ids of unassigned shipments
    } deriving (Show, Eq, Generic)

instance FromJSON Solution_unassigned where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "solutionUnassigned")
instance ToJSON Solution_unassigned where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "solutionUnassigned")

-- | 
data Stop = Stop
    { stopAddress :: Address -- ^ 
    , stopDuration :: Integer -- ^ duration of stop, i.e. time in ms the corresponding activity takes
    , stopPreparationTime :: Integer -- ^ preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location
    , stopTimeWindows :: [TimeWindow] -- ^ array of time windows. currently, only a single time window is allowed
    } deriving (Show, Eq, Generic)

instance FromJSON Stop where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "stop")
instance ToJSON Stop where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "stop")

-- | 
data TimeWindow = TimeWindow
    { timeWindowEarliest :: Integer -- ^ earliest start time of corresponding activity
    , timeWindowLatest :: Integer -- ^ latest start time of corresponding activity
    } deriving (Show, Eq, Generic)

instance FromJSON TimeWindow where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "timeWindow")
instance ToJSON TimeWindow where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "timeWindow")

-- | 
data Vehicle = Vehicle
    { vehicleVehicleId :: Text -- ^ Unique identifier of vehicle
    , vehicleTypeId :: Text -- ^ Unique identifier referring to the available vehicle types
    , vehicleStartAddress :: Address -- ^ 
    , vehicleEndAddress :: Address -- ^ 
    , vehicleBreak :: Break -- ^ 
    , vehicleReturnToDepot :: Bool -- ^ Indicates whether vehicle should return to start address or not. If not, it can end at any service activity.
    , vehicleEarliestStart :: Integer -- ^ earliest start of vehicle at its start location
    , vehicleLatestEnd :: Integer -- ^ latest end of vehicle at its end location
    , vehicleSkills :: [Text] -- ^ array of skills
    , vehicleMaxDistance :: Integer -- ^ max distance of vehicle
    } deriving (Show, Eq, Generic)

instance FromJSON Vehicle where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "vehicle")
instance ToJSON Vehicle where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "vehicle")

-- | 
data VehicleType = VehicleType
    { vehicleTypeTypeId :: Text -- ^ Unique identifier for the vehicle type
    , vehicleTypeProfile :: Text -- ^ Profile of vehicle type
    , vehicleTypeCapacity :: [Int] -- ^ array of capacity dimensions
    , vehicleTypeSpeedFactor :: Double -- ^ speed_factor of vehicle type
    , vehicleTypeServiceTimeFactor :: Double -- ^ service time factor of vehicle type
    } deriving (Show, Eq, Generic)

instance FromJSON VehicleType where
  parseJSON  = genericParseJSON  (removeFieldLabelPrefix True "vehicleType")
instance ToJSON VehicleType where
  toJSON     = genericToJSON     (removeFieldLabelPrefix False "vehicleType")

-- Remove a field label prefix during JSON parsing.
-- Also perform any replacements for special characters.
removeFieldLabelPrefix :: Bool -> String -> Options
removeFieldLabelPrefix forParsing prefix =
  defaultOptions
    { fieldLabelModifier = fromMaybe (error ("did not find prefix " ++ prefix)) . stripPrefix prefix . replaceSpecialChars
    }
  where
    replaceSpecialChars field = foldl (&) field (map mkCharReplacement specialChars)
    specialChars = [("@", "'At"), ("<=", "'Less_Than_Or_Equal_To"), ("[", "'Left_Square_Bracket"), ("\", "'Back_Slash"), ("]", "'Right_Square_Bracket"), ("^", "'Caret"), ("_", "'Underscore"), ("`", "'Backtick"), ("!", "'Exclamation"), (""", "'Double_Quote"), ("#", "'Hash"), ("$", "'Dollar"), ("%", "'Percent"), ("&", "'Ampersand"), ("'", "'Quote"), ("(", "'Left_Parenthesis"), (")", "'Right_Parenthesis"), ("*", "'Star"), ("+", "'Plus"), (",", "'Comma"), ("-", "'Dash"), (".", "'Period"), ("/", "'Slash"), (":", "'Colon"), ("{", "'Left_Curly_Bracket"), ("|", "'Pipe"), ("<", "'LessThan"), ("!=", "'Not_Equal"), ("=", "'Equal"), ("}", "'Right_Curly_Bracket"), (">", "'GreaterThan"), ("~", "'Tilde"), ("?", "'Question_Mark"), (">=", "'Greater_Than_Or_Equal_To")]
    mkCharReplacement (replaceStr, searchStr) = T.unpack . replacer (T.pack searchStr) (T.pack replaceStr) . T.pack
    replacer = if forParsing then flip T.replace else T.replace


