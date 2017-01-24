# WWW::SwaggerClient::Object::Vehicle

## Load the model package
```perl
use WWW::SwaggerClient::Object::Vehicle;
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicle_id** | **string** | Unique identifier of vehicle | [optional] 
**type_id** | **string** | Unique identifier referring to the available vehicle types | [optional] 
**start_address** | [**Address**](Address.md) |  | [optional] 
**end_address** | [**Address**](Address.md) |  | [optional] 
**break** | [**Break**](Break.md) |  | [optional] 
**return_to_depot** | **boolean** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. | [optional] 
**earliest_start** | **int** | earliest start of vehicle at its start location | [optional] 
**latest_end** | **int** | latest end of vehicle at its end location | [optional] 
**skills** | **ARRAY[string]** | array of skills | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


