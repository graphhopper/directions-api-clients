# Shipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service | [optional] [default to null]
**name** | **String** | name of shipment | [optional] [default to null]
**priority** | **i32** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] [default to null]
**pickup** | [***::models::Stop**](Stop.md) |  | [optional] [default to null]
**delivery** | [***::models::Stop**](Stop.md) |  | [optional] [default to null]
**size** | **Vec<i32>** | array of capacity dimensions | [optional] [default to null]
**required_skills** | **Vec<String>** | array of required skills | [optional] [default to null]
**allowed_vehicles** | **Vec<String>** | array of allowed vehicle ids | [optional] [default to null]
**disallowed_vehicles** | **Vec<String>** | array of disallowed vehicle ids | [optional] [default to null]
**max_time_in_vehicle** | **i64** | max time shipment can stay in vehicle | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


