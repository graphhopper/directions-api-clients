# IO.Swagger.Model.Shipment
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Id** | **string** | Unique identifier of service | [optional] 
**Name** | **string** | name of shipment | [optional] 
**Priority** | **int?** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**Pickup** | [**Stop**](Stop.md) |  | [optional] 
**Delivery** | [**Stop**](Stop.md) |  | [optional] 
**Size** | **List&lt;int?&gt;** | array of capacity dimensions | [optional] 
**RequiredSkills** | **List&lt;string&gt;** | array of required skills | [optional] 
**AllowedVehicles** | **List&lt;string&gt;** | array of allowed vehicle ids | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

