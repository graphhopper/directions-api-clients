# Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **str** | Unique identifier of service | [optional] 
**type** | **str** | type of service | [optional] 
**priority** | **int** | priority of service | [optional] 
**name** | **str** | name of service | [optional] 
**address** | [**Address**](Address.md) |  | [optional] 
**duration** | **int** | duration of service, i.e. time in ms the corresponding activity takes | [optional] 
**preparation_time** | **int** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] 
**time_windows** | [**list[TimeWindow]**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**size** | **list[int]** | array of capacity dimensions | [optional] 
**required_skills** | **list[str]** | array of required skills | [optional] 
**allowed_vehicles** | **list[str]** | array of allowed vehicle ids | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


