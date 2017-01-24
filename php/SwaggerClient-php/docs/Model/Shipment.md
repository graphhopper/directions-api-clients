# Shipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **string** | Unique identifier of service | [optional] 
**name** | **string** | name of shipment | [optional] 
**priority** | **int** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**pickup** | [**\Swagger\Client\Model\Stop**](Stop.md) |  | [optional] 
**delivery** | [**\Swagger\Client\Model\Stop**](Stop.md) |  | [optional] 
**size** | **int[]** | array of capacity dimensions | [optional] 
**required_skills** | **string[]** | array of required skills | [optional] 
**allowed_vehicles** | **string[]** | array of allowed vehicle ids | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


