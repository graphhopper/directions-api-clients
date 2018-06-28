# Org.OpenAPITools.Model.Service
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Id** | **string** | Unique identifier of service | [optional] 
**Type** | **string** | type of service | [optional] 
**Priority** | **int?** | priority of service | [optional] 
**Name** | **string** | name of service | [optional] 
**Address** | [**Address**](Address.md) |  | [optional] 
**Duration** | **long?** | duration of service, i.e. time in seconds the corresponding activity takes | [optional] 
**PreparationTime** | **long?** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] 
**TimeWindows** | [**List&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**Size** | **List&lt;int?&gt;** | array of capacity dimensions | [optional] 
**RequiredSkills** | **List&lt;string&gt;** | array of required skills | [optional] 
**AllowedVehicles** | **List&lt;string&gt;** | array of allowed vehicle ids | [optional] 
**DisallowedVehicles** | **List&lt;string&gt;** | array of disallowed vehicle ids | [optional] 
**MaxTimeInVehicle** | **long?** | max time service can stay in vehicle | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

