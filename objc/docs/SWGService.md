# SWGService

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_id** | **NSString*** | Unique identifier of service | [optional] 
**type** | **NSString*** | type of service | [optional] 
**priority** | **NSNumber*** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**name** | **NSString*** | name of service | [optional] 
**address** | [**SWGAddress***](SWGAddress.md) |  | [optional] 
**duration** | **NSNumber*** | duration of service, i.e. time in ms the corresponding activity takes | [optional] 
**timeWindows** | [**NSArray&lt;SWGTimeWindow&gt;***](SWGTimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**size** | **NSArray&lt;NSNumber*&gt;*** | array of capacity dimensions | [optional] 
**requiredSkills** | **NSArray&lt;NSString*&gt;*** | array of required skills | [optional] 
**allowedVehicles** | **NSArray&lt;NSString*&gt;*** | array of allowed vehicle ids | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


