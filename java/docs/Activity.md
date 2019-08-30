# Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | [**TypeEnum**](#TypeEnum) | type of activity |  [optional]
**id** | **String** | Id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to |  [optional]
**locationId** | **String** | Id that refers to address |  [optional]
**address** | [**ResponseAddress**](ResponseAddress.md) |  |  [optional]
**arrTime** | **Long** | Arrival time at this activity in seconds. If type is &#x60;start&#x60;, this is not available (since it makes no sense to have &#x60;arr_time&#x60; at start). However, &#x60;end_time&#x60; is available and actually means \\\&quot;departure time\\\&quot; at start location. It is important to note that &#x60;arr_time&#x60; does not necessarily mean \\\&quot;start of underlying activity\\\&quot;, it solely means arrival time at activity location. If this activity has no time windows and if there are no further preparation times, &#x60;arr_time&#x60; is equal to activity start time. |  [optional]
**endTime** | **Long** | End time of and thus departure time at this activity. If type is &#x60;end&#x60;, this is not available (since it makes no sense to have an &#x60;end_time&#x60; at end) &#x60;end_time&#x60; at each activity is equal to the departure time at the activity location. |  [optional]
**endDateTime** | [**OffsetDateTime**](OffsetDateTime.md) | End date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is &#x60;null&#x60;. |  [optional]
**arrDateTime** | [**OffsetDateTime**](OffsetDateTime.md) | Arrival date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is &#x60;null&#x60;. |  [optional]
**waitingTime** | **Long** | Waiting time at this activity in seconds. A waiting time can occur if the activity has at least one time window. If &#x60;arr_time&#x60; &lt; &#x60;time_window.earliest&#x60; a waiting time of &#x60;time_window_earliest&#x60; - &#x60;arr_time&#x60; occurs. |  [optional]
**preparationTime** | **Long** | preparation time at this activity in seconds |  [optional]
**distance** | **Long** | cumulated distance from start to this activity in m |  [optional]
**drivingTime** | **Long** | driving time of driver in seconds |  [optional]
**loadBefore** | **List&lt;Integer&gt;** | Array with size/capacity dimensions before this activity |  [optional]
**loadAfter** | **List&lt;Integer&gt;** | Array with size/capacity dimensions after this activity |  [optional]

<a name="TypeEnum"></a>
## Enum: TypeEnum
Name | Value
---- | -----
START | &quot;start&quot;
END | &quot;end&quot;
SERVICE | &quot;service&quot;
PICKUPSHIPMENT | &quot;pickupShipment&quot;
DELIVERSHIPMENT | &quot;deliverShipment&quot;
PICKUP | &quot;pickup&quot;
DELIVERY | &quot;delivery&quot;
BREAK | &quot;break&quot;
