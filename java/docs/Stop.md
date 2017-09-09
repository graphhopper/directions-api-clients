
# Stop

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**address** | [**Address**](Address.md) |  |  [optional]
**duration** | **Long** | duration of stop, i.e. time in ms the corresponding activity takes |  [optional]
**preparationTime** | **Long** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location |  [optional]
**timeWindows** | [**List&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed |  [optional]



