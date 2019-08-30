# RouteResponsePath

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distance** | **double** | The total distance, in meters. | [optional] 
**time** | **int** | The total travel time, in milliseconds. | [optional] 
**ascend** | **double** | The total ascent, in meters. | [optional] 
**descend** | **double** | The total descent, in meters. | [optional] 
**points** | [****](.md) |  | [optional] 
**snapped_waypoints** | [****](.md) |  | [optional] 
**points_encoded** | **bool** | Whether the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields are encoded strings rather than GeoJSON LineStrings. | [optional] 
**bbox** | **double[]** | The bounding box of the route geometry. Format: &#x60;[minLon, minLat, maxLon, maxLat]&#x60;. | [optional] 
**instructions** | [**\Swagger\Client\Model\RouteResponsePathInstructions[]**](RouteResponsePathInstructions.md) | The instructions for this route. This feature is under active development, and our instructions can sometimes be misleading, so be mindful when using them for navigation. | [optional] 
**details** | **object** | Details, as requested with the &#x60;details&#x60; parameter. Consider the value &#x60;{\&quot;street_name\&quot;: [[0,2,\&quot;Frankfurter Straße\&quot;],[2,6,\&quot;Zollweg\&quot;]]}&#x60;. In this example, the route uses two streets: The first, Frankfurter Straße, is used between &#x60;points[0]&#x60; and &#x60;points[2]&#x60;, and the second, Zollweg, between &#x60;points[2]&#x60; and &#x60;points[6]&#x60;. See [here](https://discuss.graphhopper.com/t/2539) for discussion. | [optional] 
**points_order** | **int[]** | An array of indices (zero-based), specifiying the order in which the input points are visited. Only present if the &#x60;optimize&#x60; parameter was used. | [optional] 

[[Back to Model list]](../../README.md#documentation-for-models) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to README]](../../README.md)

