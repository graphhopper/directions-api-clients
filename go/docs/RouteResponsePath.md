# RouteResponsePath

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Distance** | **float64** | The total distance of the route, in meter | [optional] 
**Time** | **int64** | The total time of the route, in ms | [optional] 
**Ascend** | **float64** |  | [optional] 
**Descend** | **float64** | The total descend (downhill) of the route, in meter | [optional] 
**Points** | [**ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] 
**PointsEncoded** | **bool** | Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version | [optional] 
**Bbox** | **[]float64** | The bounding box of the route, format &lt;br&gt; minLon, minLat, maxLon, maxLat | [optional] 
**SnappedWaypoints** | [**ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] 
**Instructions** | [**ResponseInstructions**](ResponseInstructions.md) |  | [optional] 
**Details** | [**map[string]interface{}**](map[string]interface{}.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


