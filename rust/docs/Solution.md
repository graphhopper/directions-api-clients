# Solution

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**costs** | **i32** | overall costs of solution | [optional] [default to null]
**distance** | **i32** | overall travel distance in meters | [optional] [default to null]
**time** | **i64** | overall transport time in seconds | [optional] [default to null]
**transport_time** | **i64** | overall transport time in seconds | [optional] [default to null]
**max_operation_time** | **i64** | operation time of the longest route in seconds | [optional] [default to null]
**waiting_time** | **i64** | total waiting time in seconds | [optional] [default to null]
**service_duration** | **i64** | total service time in seconds | [optional] [default to null]
**preparation_time** | **i64** | total preparation time in seconds | [optional] [default to null]
**completion_time** | **i64** | total completion time in seconds | [optional] [default to null]
**no_vehicles** | **i32** | number of employed vehicles | [optional] [default to null]
**no_unassigned** | **i32** | number of jobs that could not be assigned to final solution | [optional] [default to null]
**routes** | [**Vec<::models::Route>**](Route.md) | An array of routes | [optional] [default to null]
**unassigned** | [***::models::SolutionUnassigned**](Solution_unassigned.md) |  | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


