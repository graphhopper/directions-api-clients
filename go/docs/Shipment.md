# Shipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Id** | **string** | Unique identifier of service | [optional] [default to null]
**Name** | **string** | name of shipment | [optional] [default to null]
**Priority** | **int32** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] [default to null]
**Pickup** | [**Stop**](Stop.md) |  | [optional] [default to null]
**Delivery** | [**Stop**](Stop.md) |  | [optional] [default to null]
**Size** | **[]int32** | array of capacity dimensions | [optional] [default to null]
**RequiredSkills** | **[]string** | array of required skills | [optional] [default to null]
**AllowedVehicles** | **[]string** | array of allowed vehicle ids | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


