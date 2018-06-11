# WWW::SwaggerClient::Object::Service

## Load the model package
```perl
use WWW::SwaggerClient::Object::Service;
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **string** | Unique identifier of service | [optional] 
**type** | **string** | type of service | [optional] 
**priority** | **int** | priority of service | [optional] 
**name** | **string** | name of service | [optional] 
**address** | [**Address**](Address.md) |  | [optional] 
**duration** | **int** | duration of service, i.e. time in seconds the corresponding activity takes | [optional] 
**preparation_time** | **int** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] 
**time_windows** | [**ARRAY[TimeWindow]**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**size** | **ARRAY[int]** | array of capacity dimensions | [optional] 
**required_skills** | **ARRAY[string]** | array of required skills | [optional] 
**allowed_vehicles** | **ARRAY[string]** | array of allowed vehicle ids | [optional] 
**disallowed_vehicles** | **ARRAY[string]** | array of disallowed vehicle ids | [optional] 
**max_time_in_vehicle** | **int** | max time service can stay in vehicle | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


