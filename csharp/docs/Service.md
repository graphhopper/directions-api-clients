# IO.Swagger.Model.Service
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Id** | **string** | Unique identifier of service | [optional] 
**Type** | **string** | type of service | [optional] 
**Priority** | **int?** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**Name** | **string** | name of service | [optional] 
**Address** | [**Address**](Address.md) |  | [optional] 
**Duration** | **long?** | duration of service, i.e. time in ms the corresponding activity takes | [optional] 
**TimeWindows** | [**List&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**Size** | **List&lt;int?&gt;** | array of capacity dimensions | [optional] 
**RequiredSkills** | **List&lt;string&gt;** | array of required skills | [optional] 
**AllowedVehicles** | **List&lt;string&gt;** | array of allowed vehicle ids | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

