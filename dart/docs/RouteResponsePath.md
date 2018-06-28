# openapi.model.RouteResponsePath

## Load the model package
```dart
import 'package:openapi/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distance** | **double** | The total distance of the route, in meter | [optional] [default to null]
**time** | **int** | The total time of the route, in ms | [optional] [default to null]
**ascend** | **double** |  | [optional] [default to null]
**descend** | **double** | The total descend (downhill) of the route, in meter | [optional] [default to null]
**points** | [**ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] [default to null]
**pointsEncoded** | **bool** | Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version | [optional] [default to null]
**bbox** | **List&lt;double&gt;** | The bounding box of the route, format &lt;br&gt; minLon, minLat, maxLon, maxLat | [optional] [default to []]
**snappedWaypoints** | [**ResponseCoordinates**](ResponseCoordinates.md) |  | [optional] [default to null]
**instructions** | [**ResponseInstructions**](ResponseInstructions.md) |  | [optional] [default to null]
**details** | [**Object**](Object.md) |  | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


