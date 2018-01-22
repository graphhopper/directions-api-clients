# Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_type** | **String** | type of activity | [optional] [default to null]
**id** | **String** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] [default to null]
**location_id** | **String** | id that refers to address | [optional] [default to null]
**arr_time** | **i64** | arrival time at this activity in ms | [optional] [default to null]
**end_time** | **i64** | end time of and thus departure time at this activity | [optional] [default to null]
**waiting_time** | **i64** | waiting time at this activity in ms | [optional] [default to null]
**distance** | **i64** | cumulated distance from start to this activity in m | [optional] [default to null]
**driving_time** | **i64** | driving time of driver in ms | [optional] [default to null]
**load_before** | **Vec<i32>** | Array with size/capacity dimensions before this activity | [optional] [default to null]
**load_after** | **Vec<i32>** | Array with size/capacity dimensions after this activity | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


