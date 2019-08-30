# RouteResponsePath

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distance** | **Double** | The total distance, in meters.  |  [optional]
**time** | **Long** | The total travel time, in milliseconds.  |  [optional]
**ascend** | **Double** | The total ascent, in meters.  |  [optional]
**descend** | **Double** | The total descent, in meters.  |  [optional]
**points** | [**Object**](.md) |  |  [optional]
**snappedWaypoints** | [**Object**](.md) |  |  [optional]
**pointsEncoded** | **Boolean** | Whether the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields are encoded strings rather than GeoJSON LineStrings.  |  [optional]
**bbox** | **List&lt;Double&gt;** | The bounding box of the route geometry. Format: &#x60;[minLon, minLat, maxLon, maxLat]&#x60;.  |  [optional]
**instructions** | [**List&lt;RouteResponsePathInstructions&gt;**](RouteResponsePathInstructions.md) | The instructions for this route. This feature is under active development, and our instructions can sometimes be misleading, so be mindful when using them for navigation.  |  [optional]
**details** | **Object** | Details, as requested with the &#x60;details&#x60; parameter. Consider the value &#x60;{\&quot;street_name\&quot;: [[0,2,\&quot;Frankfurter Straße\&quot;],[2,6,\&quot;Zollweg\&quot;]]}&#x60;. In this example, the route uses two streets: The first, Frankfurter Straße, is used between &#x60;points[0]&#x60; and &#x60;points[2]&#x60;, and the second, Zollweg, between &#x60;points[2]&#x60; and &#x60;points[6]&#x60;. See [here](https://discuss.graphhopper.com/t/2539) for discussion.  |  [optional]
**pointsOrder** | **List&lt;Integer&gt;** | An array of indices (zero-based), specifiying the order in which the input points are visited. Only present if the &#x60;optimize&#x60; parameter was used.  |  [optional]
