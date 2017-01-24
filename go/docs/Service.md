# Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Id** | **string** | Unique identifier of service | [optional] [default to null]
**Type_** | **string** | type of service | [optional] [default to null]
**Priority** | **int32** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] [default to null]
**Name** | **string** | name of service | [optional] [default to null]
**Address** | [**Address**](Address.md) |  | [optional] [default to null]
**Duration** | **int64** | duration of service, i.e. time in ms the corresponding activity takes | [optional] [default to null]
**TimeWindows** | [**[]TimeWindow**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] [default to null]
**Size** | **[]int32** | array of capacity dimensions | [optional] [default to null]
**RequiredSkills** | **[]string** | array of required skills | [optional] [default to null]
**AllowedVehicles** | **[]string** | array of allowed vehicle ids | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


