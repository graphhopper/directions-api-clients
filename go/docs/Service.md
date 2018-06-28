# Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Id** | **string** | Unique identifier of service | [optional] 
**Type** | **string** | type of service | [optional] 
**Priority** | **int32** | priority of service | [optional] 
**Name** | **string** | name of service | [optional] 
**Address** | [**Address**](Address.md) |  | [optional] 
**Duration** | **int64** | duration of service, i.e. time in seconds the corresponding activity takes | [optional] 
**PreparationTime** | **int64** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] 
**TimeWindows** | [**[]TimeWindow**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**Size** | **[]int32** | array of capacity dimensions | [optional] 
**RequiredSkills** | **[]string** | array of required skills | [optional] 
**AllowedVehicles** | **[]string** | array of allowed vehicle ids | [optional] 
**DisallowedVehicles** | **[]string** | array of disallowed vehicle ids | [optional] 
**MaxTimeInVehicle** | **int64** | max time service can stay in vehicle | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


