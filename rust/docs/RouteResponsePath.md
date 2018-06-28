# RouteResponsePath

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distance** | **f64** | The total distance of the route, in meter | [optional] 
**time** | **i64** | The total time of the route, in ms | [optional] 
**ascend** | **f64** |  | [optional] 
**descend** | **f64** | The total descend (downhill) of the route, in meter | [optional] 
**points** | [***::models::ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] 
**points_encoded** | **bool** | Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version | [optional] 
**bbox** | **Vec<f64>** | The bounding box of the route, format &lt;br&gt; minLon, minLat, maxLon, maxLat | [optional] 
**snapped_waypoints** | [***::models::ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] 
**instructions** | [***::models::ResponseInstructions**](ResponseInstructions.md) |  | [optional] 
**details** | [***Value**](Value.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


