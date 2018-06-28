# Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service | [optional] 
**_type** | **String** | type of service | [optional] 
**priority** | **i32** | priority of service | [optional] 
**name** | **String** | name of service | [optional] 
**address** | [***::models::Address**](Address.md) |  | [optional] 
**duration** | **i64** | duration of service, i.e. time in seconds the corresponding activity takes | [optional] 
**preparation_time** | **i64** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] 
**time_windows** | [**Vec<::models::TimeWindow>**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**size** | **Vec<i32>** | array of capacity dimensions | [optional] 
**required_skills** | **Vec<String>** | array of required skills | [optional] 
**allowed_vehicles** | **Vec<String>** | array of allowed vehicle ids | [optional] 
**disallowed_vehicles** | **Vec<String>** | array of disallowed vehicle ids | [optional] 
**max_time_in_vehicle** | **i64** | max time service can stay in vehicle | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


