# Shipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Id** | **string** | Unique identifier of service | [optional] 
**Name** | **string** | name of shipment | [optional] 
**Priority** | **int32** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**Pickup** | [**Stop**](Stop.md) |  | [optional] 
**Delivery** | [**Stop**](Stop.md) |  | [optional] 
**Size** | **[]int32** | array of capacity dimensions | [optional] 
**RequiredSkills** | **[]string** | array of required skills | [optional] 
**AllowedVehicles** | **[]string** | array of allowed vehicle ids | [optional] 
**DisallowedVehicles** | **[]string** | array of disallowed vehicle ids | [optional] 
**MaxTimeInVehicle** | **int64** | max time shipment can stay in vehicle | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


