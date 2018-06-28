# Vehicle

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicle_id** | **String** | Unique identifier of vehicle | [optional] 
**type_id** | **String** | Unique identifier referring to the available vehicle types | [optional] 
**start_address** | [***::models::Address**](Address.md) |  | [optional] 
**end_address** | [***::models::Address**](Address.md) |  | [optional] 
**_break** | [***::models::ModelBreak**](Break.md) |  | [optional] 
**return_to_depot** | **bool** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. | [optional] 
**earliest_start** | **i64** | earliest start of vehicle at its start location | [optional] 
**latest_end** | **i64** | latest end of vehicle at its end location | [optional] 
**skills** | **Vec<String>** | array of skills | [optional] 
**max_distance** | **i64** | max distance of vehicle | [optional] 
**max_driving_time** | **i64** | max drive time of vehicle | [optional] 
**max_jobs** | **i32** | max number of jobs the vehicle can load | [optional] 
**max_activities** | **i32** | max number of activities the vehicle can conduct | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


