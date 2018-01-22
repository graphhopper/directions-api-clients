# swagger.model.Route

## Load the model package
```dart
import 'package:swagger/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicleId** | **String** | id of vehicle that operates route | [optional] [default to null]
**distance** | **int** | distance of route in meter | [optional] [default to null]
**transportTime** | **int** | transport time of route in ms | [optional] [default to null]
**completionTime** | **int** | completion time of route in ms | [optional] [default to null]
**waitingTime** | **int** | waiting time of route in ms | [optional] [default to null]
**activities** | [**List&lt;Activity&gt;**](Activity.md) | array of activities | [optional] [default to []]
**points** | [**List&lt;RoutePoint&gt;**](RoutePoint.md) | array of route planning points | [optional] [default to []]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


