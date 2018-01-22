# Stop

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**address** | [***::models::Address**](Address.md) |  | [optional] [default to null]
**duration** | **i64** | duration of stop, i.e. time in ms the corresponding activity takes | [optional] [default to null]
**preparation_time** | **i64** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] [default to null]
**time_windows** | [**Vec<::models::TimeWindow>**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


