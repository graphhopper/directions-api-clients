# openapi.model.Service

## Load the model package
```dart
import 'package:openapi/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service | [optional] [default to null]
**type** | **String** | type of service | [optional] [default to null]
**priority** | **int** | priority of service | [optional] [default to null]
**name** | **String** | name of service | [optional] [default to null]
**address** | [**Address**](Address.md) |  | [optional] [default to null]
**duration** | **int** | duration of service, i.e. time in seconds the corresponding activity takes | [optional] [default to null]
**preparationTime** | **int** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] [default to null]
**timeWindows** | [**List&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] [default to []]
**size** | **List&lt;int&gt;** | array of capacity dimensions | [optional] [default to []]
**requiredSkills** | **List&lt;String&gt;** | array of required skills | [optional] [default to []]
**allowedVehicles** | **List&lt;String&gt;** | array of allowed vehicle ids | [optional] [default to []]
**disallowedVehicles** | **List&lt;String&gt;** | array of disallowed vehicle ids | [optional] [default to []]
**maxTimeInVehicle** | **int** | max time service can stay in vehicle | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


