# Route

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicle_id** | **String** | id of vehicle that operates route | [optional] 
**distance** | **i64** | distance of route in meter | [optional] 
**transport_time** | **i64** | transport time of route in seconds | [optional] 
**completion_time** | **i64** | completion time of route in seconds | [optional] 
**waiting_time** | **i64** | waiting time of route in seconds | [optional] 
**activities** | [**Vec<::models::Activity>**](Activity.md) | array of activities | [optional] 
**points** | [**Vec<::models::RoutePoint>**](RoutePoint.md) | array of route planning points | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


