# Stop

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Address** | [***Address**](Address.md) |  | [optional] [default to null]
**Duration** | **int64** | duration of stop, i.e. time in seconds the corresponding activity takes | [optional] [default to null]
**PreparationTime** | **int64** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] [default to null]
**TimeWindows** | [**[]TimeWindow**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


