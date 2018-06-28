# Shipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service | [optional] 
**name** | **String** | name of shipment | [optional] 
**priority** | **i32** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**pickup** | [***::models::Stop**](Stop.md) |  | [optional] 
**delivery** | [***::models::Stop**](Stop.md) |  | [optional] 
**size** | **Vec<i32>** | array of capacity dimensions | [optional] 
**required_skills** | **Vec<String>** | array of required skills | [optional] 
**allowed_vehicles** | **Vec<String>** | array of allowed vehicle ids | [optional] 
**disallowed_vehicles** | **Vec<String>** | array of disallowed vehicle ids | [optional] 
**max_time_in_vehicle** | **i64** | max time shipment can stay in vehicle | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


