# OAIShipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_id** | **NSString*** | Unique identifier of service | [optional] 
**name** | **NSString*** | name of shipment | [optional] 
**priority** | **NSNumber*** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**pickup** | [**OAIStop***](OAIStop.md) |  | [optional] 
**delivery** | [**OAIStop***](OAIStop.md) |  | [optional] 
**size** | **NSArray&lt;NSNumber*&gt;*** | array of capacity dimensions | [optional] 
**requiredSkills** | **NSArray&lt;NSString*&gt;*** | array of required skills | [optional] 
**allowedVehicles** | **NSArray&lt;NSString*&gt;*** | array of allowed vehicle ids | [optional] 
**disallowedVehicles** | **NSArray&lt;NSString*&gt;*** | array of disallowed vehicle ids | [optional] 
**maxTimeInVehicle** | **NSNumber*** | max time shipment can stay in vehicle | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


