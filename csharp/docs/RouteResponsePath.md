# IO.Swagger.Model.RouteResponsePath
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Distance** | **double?** | The total distance of the route, in meter | [optional] 
**Time** | **long?** | The total time of the route, in ms | [optional] 
**Ascend** | **double?** |  | [optional] 
**Descend** | **double?** | The total descend (downhill) of the route, in meter | [optional] 
**Points** | [**ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] 
**PointsEncoded** | **bool?** | Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version | [optional] 
**Bbox** | **List&lt;double?&gt;** | The bounding box of the route, format &lt;br&gt; minLon, minLat, maxLon, maxLat | [optional] 
**SnappedWaypoints** | [**ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] 
**Instructions** | [**ResponseInstructions**](ResponseInstructions.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

