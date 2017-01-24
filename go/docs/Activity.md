# Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Type_** | **string** | type of activity | [optional] [default to null]
**Id** | **string** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] [default to null]
**LocationId** | **string** | id that refers to address | [optional] [default to null]
**ArrTime** | **int64** | arrival time at this activity in ms | [optional] [default to null]
**EndTime** | **int64** | end time of and thus departure time at this activity | [optional] [default to null]
**WaitingTime** | **int64** | waiting time at this activity in ms | [optional] [default to null]
**Distance** | **int64** | cumulated distance from start to this activity in m | [optional] [default to null]
**DrivingTime** | **int64** | driving time of driver in ms | [optional] [default to null]
**LoadBefore** | **[]int32** | Array with size/capacity dimensions before this activity | [optional] [default to null]
**LoadAfter** | **[]int32** | Array with size/capacity dimensions after this activity | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


