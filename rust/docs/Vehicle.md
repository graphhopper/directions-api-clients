# Vehicle

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicle_id** | **String** | Unique identifier of vehicle | [optional] [default to null]
**type_id** | **String** | Unique identifier referring to the available vehicle types | [optional] [default to null]
**start_address** | [***::models::Address**](Address.md) |  | [optional] [default to null]
**end_address** | [***::models::Address**](Address.md) |  | [optional] [default to null]
**_break** | [***::models::ModelBreak**](Break.md) |  | [optional] [default to null]
**return_to_depot** | **bool** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. | [optional] [default to null]
**earliest_start** | **i64** | earliest start of vehicle at its start location | [optional] [default to null]
**latest_end** | **i64** | latest end of vehicle at its end location | [optional] [default to null]
**skills** | **Vec<String>** | array of skills | [optional] [default to null]
**max_distance** | **i64** | max distance of vehicle | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


