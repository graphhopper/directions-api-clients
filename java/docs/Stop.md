# Stop

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**address** | [**Address**](Address.md) |  |  [optional]
**duration** | **Long** | Specifies the duration of the pickup or delivery in seconds, e.g. how long it takes unload items at the customer site. |  [optional]
**preparationTime** | **Long** | Specifies the preparation time in seconds. It can be used to model parking lot search time since if you have 3 identical locations in a row, it only falls due once. |  [optional]
**timeWindows** | [**List&lt;TimeWindow&gt;**](TimeWindow.md) | Specifies an array of time window objects (see time window object below). For example, if an item needs to be delivered between 7am and 10am then specify the array as follows: [ { \&quot;earliest\&quot;: 25200, \&quot;latest\&quot; : 32400 } ] (starting the day from 0 in seconds). |  [optional]
**group** | **String** | Group this stop belongs to |  [optional]
