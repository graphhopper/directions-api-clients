# Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Type** | **string** | type of activity | [optional] 
**Id** | **string** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] 
**LocationId** | **string** | id that refers to address | [optional] 
**ArrTime** | **int64** | arrival time at this activity in seconds | [optional] 
**EndTime** | **int64** | end time of and thus departure time at this activity | [optional] 
**WaitingTime** | **int64** | waiting time at this activity in seconds | [optional] 
**Distance** | **int64** | cumulated distance from start to this activity in m | [optional] 
**DrivingTime** | **int64** | driving time of driver in seconds | [optional] 
**LoadBefore** | **[]int32** | Array with size/capacity dimensions before this activity | [optional] 
**LoadAfter** | **[]int32** | Array with size/capacity dimensions after this activity | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


