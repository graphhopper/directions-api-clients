# Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **string** | type of activity | [optional] 
**id** | **string** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] 
**location_id** | **string** | id that refers to address | [optional] 
**arr_time** | **int** | arrival time at this activity in seconds | [optional] 
**end_time** | **int** | end time of and thus departure time at this activity | [optional] 
**waiting_time** | **int** | waiting time at this activity in seconds | [optional] 
**distance** | **int** | cumulated distance from start to this activity in m | [optional] 
**driving_time** | **int** | driving time of driver in seconds | [optional] 
**load_before** | **int[]** | Array with size/capacity dimensions before this activity | [optional] 
**load_after** | **int[]** | Array with size/capacity dimensions after this activity | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


