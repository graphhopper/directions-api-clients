# openapi.model.Shipment

## Load the model package
```dart
import 'package:openapi/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service | [optional] [default to null]
**name** | **String** | name of shipment | [optional] [default to null]
**priority** | **int** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] [default to null]
**pickup** | [**Stop**](Stop.md) |  | [optional] [default to null]
**delivery** | [**Stop**](Stop.md) |  | [optional] [default to null]
**size** | **List&lt;int&gt;** | array of capacity dimensions | [optional] [default to []]
**requiredSkills** | **List&lt;String&gt;** | array of required skills | [optional] [default to []]
**allowedVehicles** | **List&lt;String&gt;** | array of allowed vehicle ids | [optional] [default to []]
**disallowedVehicles** | **List&lt;String&gt;** | array of disallowed vehicle ids | [optional] [default to []]
**maxTimeInVehicle** | **int** | max time shipment can stay in vehicle | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


