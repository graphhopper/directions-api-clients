# Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service | [optional] [default to null]
**_type** | **String** | type of service | [optional] [default to null]
**priority** | **i32** | priority of service | [optional] [default to null]
**name** | **String** | name of service | [optional] [default to null]
**address** | [***::models::Address**](Address.md) |  | [optional] [default to null]
**duration** | **i64** | duration of service, i.e. time in seconds the corresponding activity takes | [optional] [default to null]
**preparation_time** | **i64** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] [default to null]
**time_windows** | [**Vec<::models::TimeWindow>**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] [default to null]
**size** | **Vec<i32>** | array of capacity dimensions | [optional] [default to null]
**required_skills** | **Vec<String>** | array of required skills | [optional] [default to null]
**allowed_vehicles** | **Vec<String>** | array of allowed vehicle ids | [optional] [default to null]
**disallowed_vehicles** | **Vec<String>** | array of disallowed vehicle ids | [optional] [default to null]
**max_time_in_vehicle** | **i64** | max time service can stay in vehicle | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


