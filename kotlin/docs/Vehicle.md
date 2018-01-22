
# Vehicle

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicle_id** | **kotlin.String** | Unique identifier of vehicle |  [optional]
**type_id** | **kotlin.String** | Unique identifier referring to the available vehicle types |  [optional]
**start_address** | [**Address**](Address.md) |  |  [optional]
**end_address** | [**Address**](Address.md) |  |  [optional]
**&#x60;break&#x60;** | [**Break**](Break.md) |  |  [optional]
**return_to_depot** | **kotlin.Boolean** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. |  [optional]
**earliest_start** | **kotlin.Long** | earliest start of vehicle at its start location |  [optional]
**latest_end** | **kotlin.Long** | latest end of vehicle at its end location |  [optional]
**skills** | **kotlin.Array&lt;kotlin.String&gt;** | array of skills |  [optional]
**max_distance** | **kotlin.Long** | max distance of vehicle |  [optional]



