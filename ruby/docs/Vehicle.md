# GraphHopperClient::Vehicle

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicle_id** | **String** | Unique identifier of vehicle | [optional] 
**type_id** | **String** | Unique identifier referring to the available vehicle types | [optional] 
**start_address** | [**Address**](Address.md) |  | [optional] 
**end_address** | [**Address**](Address.md) |  | [optional] 
**_break** | [**ModelBreak**](ModelBreak.md) |  | [optional] 
**return_to_depot** | **BOOLEAN** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. | [optional] 
**earliest_start** | **Integer** | earliest start of vehicle at its start location | [optional] 
**latest_end** | **Integer** | latest end of vehicle at its end location | [optional] 
**skills** | **Array&lt;String&gt;** | array of skills | [optional] 
**max_distance** | **Integer** | max distance of vehicle | [optional] 
**max_driving_time** | **Integer** | max drive time of vehicle | [optional] 
**max_jobs** | **Integer** | max number of jobs the vehicle can load | [optional] 
**max_activities** | **Integer** | max number of activities the vehicle can conduct | [optional] 


