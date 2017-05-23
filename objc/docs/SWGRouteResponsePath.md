# SWGRouteResponsePath

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distance** | **NSNumber*** | The total distance of the route, in meter | [optional] 
**time** | **NSNumber*** | The total time of the route, in ms | [optional] 
**ascend** | **NSNumber*** |  | [optional] 
**descend** | **NSNumber*** | The total descend (downhill) of the route, in meter | [optional] 
**points** | [**SWGResponseCoordinates***](SWGResponseCoordinates.md) |  | [optional] 
**pointsEncoded** | **NSNumber*** | Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version | [optional] 
**bbox** | **NSArray&lt;NSNumber*&gt;*** | The bounding box of the route, format &lt;br&gt; minLon, minLat, maxLon, maxLat | [optional] 
**snappedWaypoints** | [**SWGResponseCoordinates***](SWGResponseCoordinates.md) |  | [optional] 
**instructions** | [**SWGResponseInstructions***](SWGResponseInstructions.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


