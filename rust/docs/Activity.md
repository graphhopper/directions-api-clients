# Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_type** | **String** | type of activity | [optional] 
**id** | **String** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] 
**location_id** | **String** | id that refers to address | [optional] 
**arr_time** | **i64** | arrival time at this activity in seconds | [optional] 
**end_time** | **i64** | end time of and thus departure time at this activity | [optional] 
**waiting_time** | **i64** | waiting time at this activity in seconds | [optional] 
**distance** | **i64** | cumulated distance from start to this activity in m | [optional] 
**driving_time** | **i64** | driving time of driver in seconds | [optional] 
**load_before** | **Vec<i32>** | Array with size/capacity dimensions before this activity | [optional] 
**load_after** | **Vec<i32>** | Array with size/capacity dimensions after this activity | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


