# Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **string** | Unique identifier of service | [optional] 
**type** | **string** | type of service | [optional] 
**priority** | **int** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**name** | **string** | name of service | [optional] 
**address** | [**\Swagger\Client\Model\Address**](Address.md) |  | [optional] 
**duration** | **int** | duration of service, i.e. time in ms the corresponding activity takes | [optional] 
**time_windows** | [**\Swagger\Client\Model\TimeWindow[]**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**size** | **int[]** | array of capacity dimensions | [optional] 
**required_skills** | **string[]** | array of required skills | [optional] 
**allowed_vehicles** | **string[]** | array of allowed vehicle ids | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


