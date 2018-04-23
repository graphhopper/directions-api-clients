# GraphHopperClient::Stop

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**address** | [**Address**](Address.md) |  | [optional] 
**duration** | **Integer** | duration of stop, i.e. time in seconds the corresponding activity takes | [optional] 
**preparation_time** | **Integer** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] 
**time_windows** | [**Array&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 


