# Vehicle

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**VehicleId** | **string** | Unique identifier of vehicle | [optional] [default to null]
**TypeId** | **string** | Unique identifier referring to the available vehicle types | [optional] [default to null]
**StartAddress** | [**Address**](Address.md) |  | [optional] [default to null]
**EndAddress** | [**Address**](Address.md) |  | [optional] [default to null]
**Break_** | [**ModelBreak**](Break.md) |  | [optional] [default to null]
**ReturnToDepot** | **bool** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. | [optional] [default to null]
**EarliestStart** | **int64** | earliest start of vehicle at its start location | [optional] [default to null]
**LatestEnd** | **int64** | latest end of vehicle at its end location | [optional] [default to null]
**Skills** | **[]string** | array of skills | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


