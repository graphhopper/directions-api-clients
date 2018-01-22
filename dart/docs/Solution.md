# swagger.model.Solution

## Load the model package
```dart
import 'package:swagger/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**costs** | **int** | overall costs of solution | [optional] [default to null]
**distance** | **int** | overall travel distance in meters | [optional] [default to null]
**time** | **int** | overall transport time in ms | [optional] [default to null]
**transportTime** | **int** | overall transport time in ms | [optional] [default to null]
**maxOperationTime** | **int** | operation time of the longest route in ms | [optional] [default to null]
**waitingTime** | **int** | total waiting time in ms | [optional] [default to null]
**noVehicles** | **int** | number of employed vehicles | [optional] [default to null]
**noUnassigned** | **int** | number of jobs that could not be assigned to final solution | [optional] [default to null]
**routes** | [**List&lt;Route&gt;**](Route.md) | An array of routes | [optional] [default to []]
**unassigned** | [**SolutionUnassigned**](SolutionUnassigned.md) |  | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


