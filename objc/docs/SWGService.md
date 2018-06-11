# SWGService

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_id** | **NSString*** | Unique identifier of service | [optional] 
**type** | **NSString*** | type of service | [optional] 
**priority** | **NSNumber*** | priority of service | [optional] 
**name** | **NSString*** | name of service | [optional] 
**address** | [**SWGAddress***](SWGAddress.md) |  | [optional] 
**duration** | **NSNumber*** | duration of service, i.e. time in seconds the corresponding activity takes | [optional] 
**preparationTime** | **NSNumber*** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] 
**timeWindows** | [**NSArray&lt;SWGTimeWindow&gt;***](SWGTimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**size** | **NSArray&lt;NSNumber*&gt;*** | array of capacity dimensions | [optional] 
**requiredSkills** | **NSArray&lt;NSString*&gt;*** | array of required skills | [optional] 
**allowedVehicles** | **NSArray&lt;NSString*&gt;*** | array of allowed vehicle ids | [optional] 
**disallowedVehicles** | **NSArray&lt;NSString*&gt;*** | array of disallowed vehicle ids | [optional] 
**maxTimeInVehicle** | **NSNumber*** | max time service can stay in vehicle | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


