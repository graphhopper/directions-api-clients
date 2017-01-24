# IO.Swagger.Model.Vehicle
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**VehicleId** | **string** | Unique identifier of vehicle | [optional] 
**TypeId** | **string** | Unique identifier referring to the available vehicle types | [optional] 
**StartAddress** | [**Address**](Address.md) |  | [optional] 
**EndAddress** | [**Address**](Address.md) |  | [optional] 
**_Break** | [**ModelBreak**](ModelBreak.md) |  | [optional] 
**ReturnToDepot** | **bool?** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. | [optional] 
**EarliestStart** | **long?** | earliest start of vehicle at its start location | [optional] 
**LatestEnd** | **long?** | latest end of vehicle at its end location | [optional] 
**Skills** | **List&lt;string&gt;** | array of skills | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

