# swagger.model.Vehicle

## Load the model package
```dart
import 'package:swagger/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicleId** | **String** | Unique identifier of vehicle | [optional] [default to null]
**typeId** | **String** | Unique identifier referring to the available vehicle types | [optional] [default to null]
**startAddress** | [**Address**](Address.md) |  | [optional] [default to null]
**endAddress** | [**Address**](Address.md) |  | [optional] [default to null]
**break_** | [**ModelBreak**](ModelBreak.md) |  | [optional] [default to null]
**returnToDepot** | **bool** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. | [optional] [default to null]
**earliestStart** | **int** | earliest start of vehicle at its start location | [optional] [default to null]
**latestEnd** | **int** | latest end of vehicle at its end location | [optional] [default to null]
**skills** | **List&lt;String&gt;** | array of skills | [optional] [default to []]
**maxDistance** | **int** | max distance of vehicle | [optional] [default to null]
**maxDrivingTime** | **int** | max drive time of vehicle | [optional] [default to null]
**maxJobs** | **int** | max number of jobs the vehicle can load | [optional] [default to null]
**maxActivities** | **int** | max number of activities the vehicle can conduct | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


