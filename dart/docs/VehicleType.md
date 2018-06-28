# openapi.model.VehicleType

## Load the model package
```dart
import 'package:openapi/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**typeId** | **String** | Unique identifier for the vehicle type | [optional] [default to null]
**profile** | **String** | Profile of vehicle type | [optional] [default to null]
**capacity** | **List&lt;int&gt;** | array of capacity dimensions | [optional] [default to []]
**speedFactor** | **double** | speed_factor of vehicle type | [optional] [default to null]
**serviceTimeFactor** | **double** | service time factor of vehicle type | [optional] [default to null]
**costPerMeter** | **double** | cost parameter per distance unit, here meter is used | [optional] [default to null]
**costPerSecond** | **double** | cost parameter per time unit, here second is used | [optional] [default to null]
**costPerActivation** | **double** | cost parameter vehicle activation, i.e. fixed costs per vehicle | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


