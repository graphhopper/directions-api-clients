# SWGShipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_id** | **NSString*** | Unique identifier of service | [optional] 
**name** | **NSString*** | name of shipment | [optional] 
**priority** | **NSNumber*** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**pickup** | [**SWGStop***](SWGStop.md) |  | [optional] 
**delivery** | [**SWGStop***](SWGStop.md) |  | [optional] 
**size** | **NSArray&lt;NSNumber*&gt;*** | array of capacity dimensions | [optional] 
**requiredSkills** | **NSArray&lt;NSString*&gt;*** | array of required skills | [optional] 
**allowedVehicles** | **NSArray&lt;NSString*&gt;*** | array of allowed vehicle ids | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


