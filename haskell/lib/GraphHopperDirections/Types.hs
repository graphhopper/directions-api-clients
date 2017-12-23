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
  GeocodingLocation (..),
  GeocodingPoint (..),
  GeocodingResponse (..),
  IsochroneResponse (..),
  IsochroneResponsePolygon (..),
  IsochroneResponsePolygon_geometry (..),
  IsochroneResponsePolygon_properties (..),
  JobId (..),
  Location (..),
  MatrixRequest (..),
  MatrixResponse (..),
  Objective (..),
  Relation (..),
  Request (..),
  Response (..),
  ResponseCoordinates (..),
  ResponseCoordinatesArray (..),
  ResponseInfo (..),
  ResponseInstruction (..),
  ResponseInstructions (..),
  Route (..),
  RoutePoint (..),
  RouteResponse (..),
  RouteResponsePath (..),
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
  , activityLocation'Underscoreid :: Text -- ^ id that refers to address
  , activityArr'Underscoretime :: Integer -- ^ arrival time at this activity in ms
  , activityEnd'Underscoretime :: Integer -- ^ end time of and thus departure time at this activity
  , activityWaiting'Underscoretime :: Integer -- ^ waiting time at this activity in ms
  , activityDistance :: Integer -- ^ cumulated distance from start to this activity in m
  , activityDriving'Underscoretime :: Integer -- ^ driving time of driver in ms
  , activityLoad'Underscorebefore :: [Int] -- ^ Array with size/capacity dimensions before this activity
  , activityLoad'Underscoreafter :: [Int] -- ^ Array with size/capacity dimensions after this activity
  } deriving (Show, Eq, Generic)

instance FromJSON Activity where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "activity")
instance ToJSON Activity where
  toJSON = genericToJSON (removeFieldLabelPrefix False "activity")

-- | 
data Address = Address
  { addressLocation'Underscoreid :: Text -- ^ Unique identifier of location
  , addressName :: Text -- ^ name of location, e.g. street name plus house number
  , addressLon :: Double -- ^ longitude
  , addressLat :: Double -- ^ latitude
  } deriving (Show, Eq, Generic)

instance FromJSON Address where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "address")
instance ToJSON Address where
  toJSON = genericToJSON (removeFieldLabelPrefix False "address")

-- | 
data Algorithm = Algorithm
  { algorithmProblem'Underscoretype :: Text -- ^ 
  , algorithmObjective :: Text -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON Algorithm where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "algorithm")
instance ToJSON Algorithm where
  toJSON = genericToJSON (removeFieldLabelPrefix False "algorithm")

-- | 
data Break = Break
  { breakEarliest :: Integer -- ^ earliest start of break
  , breakLatest :: Integer -- ^ latest start of break
  , breakDuration :: Integer -- ^ duration of break
  , breakMax'Underscoredriving'Underscoretime :: Integer -- ^ max driving time without break
  , breakInitial'Underscoredriving'Underscoretime :: Integer -- ^ initial driving time, i.e. the time your driver has already spent for driving
  , breakPossible'Underscoresplit :: [Integer] -- ^ array of splits
  } deriving (Show, Eq, Generic)

instance FromJSON Break where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "break")
instance ToJSON Break where
  toJSON = genericToJSON (removeFieldLabelPrefix False "break")

-- | 
data Configuration = Configuration
  { configurationRouting :: Routing -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON Configuration where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "configuration")
instance ToJSON Configuration where
  toJSON = genericToJSON (removeFieldLabelPrefix False "configuration")

-- | 
data CostMatrix = CostMatrix
  { costMatrixType :: Text -- ^ type of cost matrix, currently default or google are supported
  , costMatrixUrl :: Text -- ^ URL of matrix service
  , costMatrixLocation'Underscoreids :: [Text] -- ^ 
  , costMatrixData :: CostMatrix_data -- ^ 
  , costMatrixProfile :: Text -- ^ vehicle profile or empty if catch all fallback
  } deriving (Show, Eq, Generic)

instance FromJSON CostMatrix where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "costMatrix")
instance ToJSON CostMatrix where
  toJSON = genericToJSON (removeFieldLabelPrefix False "costMatrix")

-- | JSON data of matrix response
data CostMatrix_data = CostMatrix_data
  { costMatrixDataTimes :: [[Integer]] -- ^ 
  , costMatrixDataDistances :: [[Double]] -- ^ 
  , costMatrixDataInfo :: CostMatrix_data_info -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON CostMatrix_data where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "costMatrixData")
instance ToJSON CostMatrix_data where
  toJSON = genericToJSON (removeFieldLabelPrefix False "costMatrixData")

-- | Additional information for your request
data CostMatrix_data_info = CostMatrix_data_info
  { costMatrixDataInfoCopyrights :: [Text] -- ^ 
  , costMatrixDataInfoTook :: Double -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON CostMatrix_data_info where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "costMatrixDataInfo")
instance ToJSON CostMatrix_data_info where
  toJSON = genericToJSON (removeFieldLabelPrefix False "costMatrixDataInfo")

-- | 
data GHError = GHError
  { gHErrorCode :: Int -- ^ 
  , gHErrorMessage :: Text -- ^ 
  , gHErrorHints :: [GHError_hints] -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON GHError where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "gHError")
instance ToJSON GHError where
  toJSON = genericToJSON (removeFieldLabelPrefix False "gHError")

-- | 
data GHError_hints = GHError_hints
  { gHErrorHintsMessage :: Text -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON GHError_hints where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "gHErrorHints")
instance ToJSON GHError_hints where
  toJSON = genericToJSON (removeFieldLabelPrefix False "gHErrorHints")

-- | 
data GeocodingLocation = GeocodingLocation
  { geocodingLocationPoint :: GeocodingPoint -- ^ 
  , geocodingLocationOsm'Underscoreid :: Text -- ^ OSM Id
  , geocodingLocationOsm'Underscoretype :: Text -- ^ N = node, R = relation, W = way
  , geocodingLocationOsm'Underscorekey :: Text -- ^ The osm key of the result like `place` or `amenity`
  , geocodingLocationName :: Text -- ^ 
  , geocodingLocationCountry :: Text -- ^ 
  , geocodingLocationCity :: Text -- ^ 
  , geocodingLocationState :: Text -- ^ 
  , geocodingLocationStreet :: Text -- ^ 
  , geocodingLocationHousenumber :: Text -- ^ 
  , geocodingLocationPostcode :: Text -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON GeocodingLocation where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "geocodingLocation")
instance ToJSON GeocodingLocation where
  toJSON = genericToJSON (removeFieldLabelPrefix False "geocodingLocation")

-- | 
data GeocodingPoint = GeocodingPoint
  { geocodingPointLat :: Double -- ^ Latitude
  , geocodingPointLng :: Double -- ^ Longitude
  } deriving (Show, Eq, Generic)

instance FromJSON GeocodingPoint where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "geocodingPoint")
instance ToJSON GeocodingPoint where
  toJSON = genericToJSON (removeFieldLabelPrefix False "geocodingPoint")

-- | 
data GeocodingResponse = GeocodingResponse
  { geocodingResponseHits :: [GeocodingLocation] -- ^ 
  , geocodingResponseLocale :: Text -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON GeocodingResponse where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "geocodingResponse")
instance ToJSON GeocodingResponse where
  toJSON = genericToJSON (removeFieldLabelPrefix False "geocodingResponse")

-- | 
data IsochroneResponse = IsochroneResponse
  { isochroneResponsePolygons :: [IsochroneResponsePolygon] -- ^ 
  , isochroneResponseCopyrights :: [Text] -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON IsochroneResponse where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "isochroneResponse")
instance ToJSON IsochroneResponse where
  toJSON = genericToJSON (removeFieldLabelPrefix False "isochroneResponse")

-- | A found path
data IsochroneResponsePolygon = IsochroneResponsePolygon
  { isochroneResponsePolygonProperties :: IsochroneResponsePolygon_properties -- ^ 
  , isochroneResponsePolygonType :: Text -- ^ 
  , isochroneResponsePolygonGeometry :: IsochroneResponsePolygon_geometry -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON IsochroneResponsePolygon where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "isochroneResponsePolygon")
instance ToJSON IsochroneResponsePolygon where
  toJSON = genericToJSON (removeFieldLabelPrefix False "isochroneResponsePolygon")

-- | 
data IsochroneResponsePolygon_geometry = IsochroneResponsePolygon_geometry
  { isochroneResponsePolygonGeometryType :: Text -- ^ 
  , isochroneResponsePolygonGeometryCoordinates :: [ResponseCoordinatesArray] -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON IsochroneResponsePolygon_geometry where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "isochroneResponsePolygonGeometry")
instance ToJSON IsochroneResponsePolygon_geometry where
  toJSON = genericToJSON (removeFieldLabelPrefix False "isochroneResponsePolygonGeometry")

-- | 
data IsochroneResponsePolygon_properties = IsochroneResponsePolygon_properties
  { isochroneResponsePolygonPropertiesBucket :: Int -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON IsochroneResponsePolygon_properties where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "isochroneResponsePolygonProperties")
instance ToJSON IsochroneResponsePolygon_properties where
  toJSON = genericToJSON (removeFieldLabelPrefix False "isochroneResponsePolygonProperties")

-- | 
data JobId = JobId
  { jobIdJob'Underscoreid :: Text -- ^ unique id for your job/request with which you can fetch your solution
  } deriving (Show, Eq, Generic)

instance FromJSON JobId where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "jobId")
instance ToJSON JobId where
  toJSON = genericToJSON (removeFieldLabelPrefix False "jobId")

-- | 
data Location = Location
  { locationLon :: Double -- ^ longitude
  , locationLat :: Double -- ^ latitude
  } deriving (Show, Eq, Generic)

instance FromJSON Location where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "location")
instance ToJSON Location where
  toJSON = genericToJSON (removeFieldLabelPrefix False "location")

-- | 
data MatrixRequest = MatrixRequest
  { matrixRequestPoints :: [[Double]] -- ^ Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format longitude,latitude.
  , matrixRequestFrom'Underscorepoints :: Text -- ^ The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format longitude,latitude.
  , matrixRequestTo'Underscorepoints :: Text -- ^ The destination points for the routes. Is a string with the format longitude,latitude.
  , matrixRequestOut'Underscorearrays :: [Text] -- ^ Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&amp;out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
  , matrixRequestVehicle :: Text -- ^ The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc, see here for the details.
  } deriving (Show, Eq, Generic)

instance FromJSON MatrixRequest where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "matrixRequest")
instance ToJSON MatrixRequest where
  toJSON = genericToJSON (removeFieldLabelPrefix False "matrixRequest")

-- | 
data MatrixResponse = MatrixResponse
  { matrixResponseDistances :: [[Double]] -- ^ 
  , matrixResponseTimes :: [[Double]] -- ^ 
  , matrixResponseWeights :: [[Double]] -- ^ 
  , matrixResponseInfo :: ResponseInfo -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON MatrixResponse where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "matrixResponse")
instance ToJSON MatrixResponse where
  toJSON = genericToJSON (removeFieldLabelPrefix False "matrixResponse")

-- | 
data Objective = Objective
  { objectiveType :: Text -- ^ type of objective function, i.e. min or min-max 
  , objectiveValue :: Text -- ^ objective function value
  } deriving (Show, Eq, Generic)

instance FromJSON Objective where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "objective")
instance ToJSON Objective where
  toJSON = genericToJSON (removeFieldLabelPrefix False "objective")

-- | 
data Relation = Relation
  { relationType :: Text -- ^ identifier of relation
  , relationIds :: [Text] -- ^ An array of ids that should be related
  , relationVehicle'Underscoreid :: Text -- ^ vehicle id
  } deriving (Show, Eq, Generic)

instance FromJSON Relation where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "relation")
instance ToJSON Relation where
  toJSON = genericToJSON (removeFieldLabelPrefix False "relation")

-- | 
data Request = Request
  { requestVehicles :: [Vehicle] -- ^ An array of vehicles that can be employed
  , requestVehicle'Underscoretypes :: [VehicleType] -- ^ An array of vehicle types
  , requestServices :: [Service] -- ^ An array of services
  , requestShipments :: [Shipment] -- ^ An array of shipments
  , requestRelations :: [Relation] -- ^ An array of relations
  , requestAlgorithm :: Algorithm -- ^ 
  , requestObjectives :: [Objective] -- ^ An array of objectives
  , requestCost'Underscorematrices :: [CostMatrix] -- ^ An array of cost matrices
  , requestConfiguration :: Configuration -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON Request where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "request")
instance ToJSON Request where
  toJSON = genericToJSON (removeFieldLabelPrefix False "request")

-- | 
data Response = Response
  { responseCopyrights :: [Text] -- ^ 
  , responseJob'Underscoreid :: Text -- ^ unique identify of job - which you get when posting your request to the large problem solver
  , responseStatus :: Text -- ^ indicates the current status of the job
  , responseWaiting'Underscorein'Underscorequeue :: Integer -- ^ waiting time in ms
  , responseProcessing'Underscoretime :: Integer -- ^ processing time in ms. if job is still waiting in queue, processing_time is 0
  , responseSolution :: Solution -- ^ the solution. only available if status field indicates finished
  } deriving (Show, Eq, Generic)

instance FromJSON Response where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "response")
instance ToJSON Response where
  toJSON = genericToJSON (removeFieldLabelPrefix False "response")

-- | 
data ResponseCoordinates = ResponseCoordinates
  { responseCoordinatesCoordinates :: ResponseCoordinatesArray -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON ResponseCoordinates where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "responseCoordinates")
instance ToJSON ResponseCoordinates where
  toJSON = genericToJSON (removeFieldLabelPrefix False "responseCoordinates")

-- | An array containing coordinates
newtype ResponseCoordinatesArray = ResponseCoordinatesArray { unResponseCoordinatesArray :: List }
  deriving (Show, Eq, FromJSON, ToJSON, Generic)

-- | Additional information for your request
data ResponseInfo = ResponseInfo
  { responseInfoCopyrights :: [Text] -- ^ 
  , responseInfoTook :: Double -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON ResponseInfo where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "responseInfo")
instance ToJSON ResponseInfo where
  toJSON = genericToJSON (removeFieldLabelPrefix False "responseInfo")

-- | 
data ResponseInstruction = ResponseInstruction
  { responseInstructionText :: Text -- ^ A description what the user has to do in order to follow the route. The language depends on the locale parameter.
  , responseInstructionStreet'Underscorename :: Text -- ^ The name of the street to turn onto in order to follow the route.
  , responseInstructionDistance :: Double -- ^ The distance for this instruction, in meter
  , responseInstructionTime :: Int -- ^ The duration for this instruction, in ms
  , responseInstructionInterval :: [Int] -- ^ An array containing the first and the last index (relative to paths[0].points) of the points for this instruction. This is useful to know for which part of the route the instructions are valid.
  , responseInstructionSign :: Int -- ^ A number which specifies the sign to show e.g. for right turn etc <br>TURN_SHARP_LEFT = -3<br>TURN_LEFT = -2<br>TURN_SLIGHT_LEFT = -1<br>CONTINUE_ON_STREET = 0<br>TURN_SLIGHT_RIGHT = 1<br>TURN_RIGHT = 2<br>TURN_SHARP_RIGHT = 3<br>FINISH = 4<br>VIA_REACHED = 5<br>USE_ROUNDABOUT = 6
  , responseInstructionAnnotation'Underscoretext :: Text -- ^ optional - A text describing the instruction in more detail, e.g. like surface of the way, warnings or involved costs.
  , responseInstructionAnnotation'Underscoreimportance :: Int -- ^ optional - 0 stands for INFO, 1 for warning, 2 for costs, 3 for costs and warning
  , responseInstructionExit'Underscorenumber :: Int -- ^ optional - Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout.
  , responseInstructionTurn'Underscoreangle :: Double -- ^ optional - Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout - 0&lt;r&lt;2*PI for clockwise and -2PI&lt;r&lt;0 for counterclockwise transit. Null if the direction of rotation is undefined.
  } deriving (Show, Eq, Generic)

instance FromJSON ResponseInstruction where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "responseInstruction")
instance ToJSON ResponseInstruction where
  toJSON = genericToJSON (removeFieldLabelPrefix False "responseInstruction")

-- | Contains information about the instructions for this route. The last instruction is always the Finish instruction and takes 0ms and 0meter. Keep in mind that instructions are currently under active development and can sometimes contain misleading information, so, make sure you always show an image of the map at the same time when navigating your users!
newtype ResponseInstructions = ResponseInstructions { unResponseInstructions :: ResponseInstruction }
  deriving (Show, Eq, FromJSON, ToJSON, Generic)

-- | 
data Route = Route
  { routeVehicle'Underscoreid :: Text -- ^ id of vehicle that operates route
  , routeDistance :: Integer -- ^ distance of route in meter
  , routeTransport'Underscoretime :: Integer -- ^ transport time of route in ms
  , routeCompletion'Underscoretime :: Integer -- ^ completion time of route in ms
  , routeWaiting'Underscoretime :: Integer -- ^ waiting time of route in ms
  , routeActivities :: [Activity] -- ^ array of activities
  , routePoints :: [RoutePoint] -- ^ array of route planning points
  } deriving (Show, Eq, Generic)

instance FromJSON Route where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "route")
instance ToJSON Route where
  toJSON = genericToJSON (removeFieldLabelPrefix False "route")

-- | 
data RoutePoint = RoutePoint
  { routePointType :: Text -- ^ 
  , routePointCoordinates :: [Value] -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON RoutePoint where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "routePoint")
instance ToJSON RoutePoint where
  toJSON = genericToJSON (removeFieldLabelPrefix False "routePoint")

-- | 
data RouteResponse = RouteResponse
  { routeResponsePaths :: [RouteResponsePath] -- ^ 
  , routeResponseInfo :: ResponseInfo -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON RouteResponse where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "routeResponse")
instance ToJSON RouteResponse where
  toJSON = genericToJSON (removeFieldLabelPrefix False "routeResponse")

-- | A found path
data RouteResponsePath = RouteResponsePath
  { routeResponsePathDistance :: Double -- ^ The total distance of the route, in meter
  , routeResponsePathTime :: Integer -- ^ The total time of the route, in ms
  , routeResponsePathAscend :: Double -- ^ 
  , routeResponsePathDescend :: Double -- ^ The total descend (downhill) of the route, in meter
  , routeResponsePathPoints :: ResponseCoordinates -- ^ 
  , routeResponsePathPoints'Underscoreencoded :: Bool -- ^ Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version
  , routeResponsePathBbox :: [Double] -- ^ The bounding box of the route, format <br> minLon, minLat, maxLon, maxLat
  , routeResponsePathSnapped'Underscorewaypoints :: ResponseCoordinates -- ^ 
  , routeResponsePathInstructions :: ResponseInstructions -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON RouteResponsePath where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "routeResponsePath")
instance ToJSON RouteResponsePath where
  toJSON = genericToJSON (removeFieldLabelPrefix False "routeResponsePath")

-- | 
data Routing = Routing
  { routingCalc'Underscorepoints :: Bool -- ^ indicates whether solution should come with route geometries
  } deriving (Show, Eq, Generic)

instance FromJSON Routing where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "routing")
instance ToJSON Routing where
  toJSON = genericToJSON (removeFieldLabelPrefix False "routing")

-- | 
data Service = Service
  { serviceId :: Text -- ^ Unique identifier of service
  , serviceType :: Text -- ^ type of service
  , servicePriority :: Int -- ^ priority of service
  , serviceName :: Text -- ^ name of service
  , serviceAddress :: Address -- ^ 
  , serviceDuration :: Integer -- ^ duration of service, i.e. time in ms the corresponding activity takes
  , servicePreparation'Underscoretime :: Integer -- ^ preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location
  , serviceTime'Underscorewindows :: [TimeWindow] -- ^ array of time windows. currently, only a single time window is allowed
  , serviceSize :: [Int] -- ^ array of capacity dimensions
  , serviceRequired'Underscoreskills :: [Text] -- ^ array of required skills
  , serviceAllowed'Underscorevehicles :: [Text] -- ^ array of allowed vehicle ids
  } deriving (Show, Eq, Generic)

instance FromJSON Service where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "service")
instance ToJSON Service where
  toJSON = genericToJSON (removeFieldLabelPrefix False "service")

-- | 
data Shipment = Shipment
  { shipmentId :: Text -- ^ Unique identifier of service
  , shipmentName :: Text -- ^ name of shipment
  , shipmentPriority :: Int -- ^ priority of service, i.e. 1 = high, 2 = normal, 3 = low. default is 2.
  , shipmentPickup :: Stop -- ^ 
  , shipmentDelivery :: Stop -- ^ 
  , shipmentSize :: [Int] -- ^ array of capacity dimensions
  , shipmentRequired'Underscoreskills :: [Text] -- ^ array of required skills
  , shipmentAllowed'Underscorevehicles :: [Text] -- ^ array of allowed vehicle ids
  } deriving (Show, Eq, Generic)

instance FromJSON Shipment where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "shipment")
instance ToJSON Shipment where
  toJSON = genericToJSON (removeFieldLabelPrefix False "shipment")

-- | 
data Solution = Solution
  { solutionCosts :: Int -- ^ overall costs of solution
  , solutionDistance :: Int -- ^ overall travel distance in meters
  , solutionTime :: Integer -- ^ overall transport time in ms
  , solutionTransport'Underscoretime :: Integer -- ^ overall transport time in ms
  , solutionMax'Underscoreoperation'Underscoretime :: Integer -- ^ operation time of the longest route in ms
  , solutionWaiting'Underscoretime :: Integer -- ^ total waiting time in ms
  , solutionNo'Underscorevehicles :: Int -- ^ number of employed vehicles
  , solutionNo'Underscoreunassigned :: Int -- ^ number of jobs that could not be assigned to final solution
  , solutionRoutes :: [Route] -- ^ An array of routes
  , solutionUnassigned :: Solution_unassigned -- ^ 
  } deriving (Show, Eq, Generic)

instance FromJSON Solution where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "solution")
instance ToJSON Solution where
  toJSON = genericToJSON (removeFieldLabelPrefix False "solution")

-- | 
data Solution_unassigned = Solution_unassigned
  { solutionUnassignedServices :: [Text] -- ^ An array of ids of unassigned services
  , solutionUnassignedShipments :: [Text] -- ^ An array of ids of unassigned shipments
  } deriving (Show, Eq, Generic)

instance FromJSON Solution_unassigned where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "solutionUnassigned")
instance ToJSON Solution_unassigned where
  toJSON = genericToJSON (removeFieldLabelPrefix False "solutionUnassigned")

-- | 
data Stop = Stop
  { stopAddress :: Address -- ^ 
  , stopDuration :: Integer -- ^ duration of stop, i.e. time in ms the corresponding activity takes
  , stopPreparation'Underscoretime :: Integer -- ^ preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location
  , stopTime'Underscorewindows :: [TimeWindow] -- ^ array of time windows. currently, only a single time window is allowed
  } deriving (Show, Eq, Generic)

instance FromJSON Stop where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "stop")
instance ToJSON Stop where
  toJSON = genericToJSON (removeFieldLabelPrefix False "stop")

-- | 
data TimeWindow = TimeWindow
  { timeWindowEarliest :: Integer -- ^ earliest start time of corresponding activity
  , timeWindowLatest :: Integer -- ^ latest start time of corresponding activity
  } deriving (Show, Eq, Generic)

instance FromJSON TimeWindow where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "timeWindow")
instance ToJSON TimeWindow where
  toJSON = genericToJSON (removeFieldLabelPrefix False "timeWindow")

-- | 
data Vehicle = Vehicle
  { vehicleVehicle'Underscoreid :: Text -- ^ Unique identifier of vehicle
  , vehicleType'Underscoreid :: Text -- ^ Unique identifier referring to the available vehicle types
  , vehicleStart'Underscoreaddress :: Address -- ^ 
  , vehicleEnd'Underscoreaddress :: Address -- ^ 
  , vehicleBreak :: Break -- ^ 
  , vehicleReturn'Underscoreto'Underscoredepot :: Bool -- ^ Indicates whether vehicle should return to start address or not. If not, it can end at any service activity.
  , vehicleEarliest'Underscorestart :: Integer -- ^ earliest start of vehicle at its start location
  , vehicleLatest'Underscoreend :: Integer -- ^ latest end of vehicle at its end location
  , vehicleSkills :: [Text] -- ^ array of skills
  , vehicleMax'Underscoredistance :: Integer -- ^ max distance of vehicle
  } deriving (Show, Eq, Generic)

instance FromJSON Vehicle where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "vehicle")
instance ToJSON Vehicle where
  toJSON = genericToJSON (removeFieldLabelPrefix False "vehicle")

-- | 
data VehicleType = VehicleType
  { vehicleTypeType'Underscoreid :: Text -- ^ Unique identifier for the vehicle type
  , vehicleTypeProfile :: Text -- ^ Profile of vehicle type
  , vehicleTypeCapacity :: [Int] -- ^ array of capacity dimensions
  , vehicleTypeSpeed'Underscorefactor :: Double -- ^ speed_factor of vehicle type
  , vehicleTypeService'Underscoretime'Underscorefactor :: Double -- ^ service time factor of vehicle type
  , vehicleTypeCost'Underscoreper'Underscoremeter :: Double -- ^ cost parameter per distance unit, here meter is used
  , vehicleTypeCost'Underscoreper'Underscoresecond :: Double -- ^ cost parameter per time unit, here second is used
  , vehicleTypeCost'Underscoreper'Underscoreactivation :: Double -- ^ cost parameter vehicle activation, i.e. fixed costs per vehicle
  } deriving (Show, Eq, Generic)

instance FromJSON VehicleType where
  parseJSON = genericParseJSON (removeFieldLabelPrefix True "vehicleType")
instance ToJSON VehicleType where
  toJSON = genericToJSON (removeFieldLabelPrefix False "vehicleType")

-- Remove a field label prefix during JSON parsing.
-- Also perform any replacements for special characters.
removeFieldLabelPrefix :: Bool -> String -> Options
removeFieldLabelPrefix forParsing prefix =
  defaultOptions
  {fieldLabelModifier = fromMaybe (error ("did not find prefix " ++ prefix)) . stripPrefix prefix . replaceSpecialChars}
  where
    replaceSpecialChars field = foldl (&) field (map mkCharReplacement specialChars)
    specialChars =
      [ ("@", "'At")
      , ("\\", "'Back_Slash")
      , ("<=", "'Less_Than_Or_Equal_To")
      , ("\"", "'Double_Quote")
      , ("[", "'Left_Square_Bracket")
      , ("]", "'Right_Square_Bracket")
      , ("^", "'Caret")
      , ("_", "'Underscore")
      , ("`", "'Backtick")
      , ("!", "'Exclamation")
      , ("#", "'Hash")
      , ("$", "'Dollar")
      , ("%", "'Percent")
      , ("&", "'Ampersand")
      , ("'", "'Quote")
      , ("(", "'Left_Parenthesis")
      , (")", "'Right_Parenthesis")
      , ("*", "'Star")
      , ("+", "'Plus")
      , (",", "'Comma")
      , ("-", "'Dash")
      , (".", "'Period")
      , ("/", "'Slash")
      , (":", "'Colon")
      , ("{", "'Left_Curly_Bracket")
      , ("|", "'Pipe")
      , ("<", "'LessThan")
      , ("!=", "'Not_Equal")
      , ("=", "'Equal")
      , ("}", "'Right_Curly_Bracket")
      , (">", "'GreaterThan")
      , ("~", "'Tilde")
      , ("?", "'Question_Mark")
      , (">=", "'Greater_Than_Or_Equal_To")
      ]
    mkCharReplacement (replaceStr, searchStr) = T.unpack . replacer (T.pack searchStr) (T.pack replaceStr) . T.pack
    replacer =
      if forParsing
        then flip T.replace
        else T.replace
