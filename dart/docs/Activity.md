# swagger.model.Activity

## Load the model package
```dart
import 'package:swagger/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **String** | type of activity | [optional] [default to null]
**id** | **String** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] [default to null]
**locationId** | **String** | id that refers to address | [optional] [default to null]
**address** | [**Address**](Address.md) | address of activity | [optional] [default to null]
**arrTime** | **int** | arrival time at this activity in seconds | [optional] [default to null]
**endTime** | **int** | end time of and thus departure time at this activity | [optional] [default to null]
**endDateTime** | **String** | end date time with offset like this 1970-01-01T01:00+01:00 | [optional] [default to null]
**arrDateTime** | **String** | arrival date time with offset like this 1970-01-01T01:00+01:00 | [optional] [default to null]
**waitingTime** | **int** | waiting time at this activity in seconds | [optional] [default to null]
**preparationTime** | **int** | preparation time at this activity in seconds | [optional] [default to null]
**distance** | **int** | cumulated distance from start to this activity in m | [optional] [default to null]
**drivingTime** | **int** | driving time of driver in seconds | [optional] [default to null]
**loadBefore** | **List&lt;int&gt;** | Array with size/capacity dimensions before this activity | [optional] [default to []]
**loadAfter** | **List&lt;int&gt;** | Array with size/capacity dimensions after this activity | [optional] [default to []]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


