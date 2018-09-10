# Route

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicle_id** | **String** | id of vehicle that operates route | [optional] [default to null]
**distance** | **i64** | distance of route in meter | [optional] [default to null]
**transport_time** | **i64** | transport time of route in seconds | [optional] [default to null]
**completion_time** | **i64** | completion time of route in seconds | [optional] [default to null]
**waiting_time** | **i64** | waiting time of route in seconds | [optional] [default to null]
**service_duration** | **i64** | service duration of route in seconds | [optional] [default to null]
**preparation_time** | **i64** | preparation time of route in seconds | [optional] [default to null]
**activities** | [**Vec<::models::Activity>**](Activity.md) | array of activities | [optional] [default to null]
**points** | [**Vec<::models::RoutePoint>**](RoutePoint.md) | array of route planning points | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


