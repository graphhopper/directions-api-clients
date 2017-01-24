
# GHRouteResponsePath

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distance** | **Double** | The total distance of the route, in meter |  [optional]
**time** | **Long** | The total time of the route, in ms |  [optional]
**ascend** | **Double** |  |  [optional]
**descend** | **Double** | The total descend (downhill) of the route, in meter |  [optional]
**points** | [**GHResponseCoordinates**](GHResponseCoordinates.md) |  |  [optional]
**pointsEncoded** | **Boolean** | Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version |  [optional]
**bbox** | **List&lt;Double&gt;** | The bounding box of the route, format &lt;br&gt; minLon, minLat, maxLon, maxLat |  [optional]
**snappedWaypoints** | [**GHResponseCoordinates**](GHResponseCoordinates.md) |  |  [optional]
**instructions** | [**GHResponseInstructions**](GHResponseInstructions.md) |  |  [optional]



