# Vehicle

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicle_id** | **str** | Unique identifier of vehicle | [optional] 
**type_id** | **str** | Unique identifier referring to the available vehicle types | [optional] 
**start_address** | [**Address**](Address.md) |  | [optional] 
**end_address** | [**Address**](Address.md) |  | [optional] 
**_break** | [**ModelBreak**](ModelBreak.md) |  | [optional] 
**return_to_depot** | **bool** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. | [optional] 
**earliest_start** | **int** | earliest start of vehicle at its start location | [optional] 
**latest_end** | **int** | latest end of vehicle at its end location | [optional] 
**skills** | **list[str]** | array of skills | [optional] 
**max_distance** | **int** | max distance of vehicle | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


