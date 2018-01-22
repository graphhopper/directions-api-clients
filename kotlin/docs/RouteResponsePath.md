
# RouteResponsePath

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distance** | **kotlin.Double** | The total distance of the route, in meter |  [optional]
**time** | **kotlin.Long** | The total time of the route, in ms |  [optional]
**ascend** | **kotlin.Double** |  |  [optional]
**descend** | **kotlin.Double** | The total descend (downhill) of the route, in meter |  [optional]
**points** | [**ResponseCoordinates**](ResponseCoordinates.md) |  |  [optional]
**points_encoded** | **kotlin.Boolean** | Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version |  [optional]
**bbox** | **kotlin.Array&lt;kotlin.Double&gt;** | The bounding box of the route, format &lt;br&gt; minLon, minLat, maxLon, maxLat |  [optional]
**snapped_waypoints** | [**ResponseCoordinates**](ResponseCoordinates.md) |  |  [optional]
**instructions** | [**ResponseInstructions**](ResponseInstructions.md) |  |  [optional]



