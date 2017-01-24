# Shipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **str** | Unique identifier of service | [optional] 
**name** | **str** | name of shipment | [optional] 
**priority** | **int** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**pickup** | [**Stop**](Stop.md) |  | [optional] 
**delivery** | [**Stop**](Stop.md) |  | [optional] 
**size** | **list[int]** | array of capacity dimensions | [optional] 
**required_skills** | **list[str]** | array of required skills | [optional] 
**allowed_vehicles** | **list[str]** | array of allowed vehicle ids | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


