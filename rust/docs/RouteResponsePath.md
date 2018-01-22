# RouteResponsePath

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distance** | **f64** | The total distance of the route, in meter | [optional] [default to null]
**time** | **i64** | The total time of the route, in ms | [optional] [default to null]
**ascend** | **f64** |  | [optional] [default to null]
**descend** | **f64** | The total descend (downhill) of the route, in meter | [optional] [default to null]
**points** | [***::models::ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] [default to null]
**points_encoded** | **bool** | Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version | [optional] [default to null]
**bbox** | **Vec<f64>** | The bounding box of the route, format &lt;br&gt; minLon, minLat, maxLon, maxLat | [optional] [default to null]
**snapped_waypoints** | [***::models::ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] [default to null]
**instructions** | [***::models::ResponseInstructions**](ResponseInstructions.md) |  | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


