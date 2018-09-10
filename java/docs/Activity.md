
# Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | [**TypeEnum**](#TypeEnum) | type of activity |  [optional]
**id** | **String** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to |  [optional]
**locationId** | **String** | id that refers to address |  [optional]
**address** | [**Address**](Address.md) | address of activity |  [optional]
**arrTime** | **Long** | arrival time at this activity in seconds |  [optional]
**endTime** | **Long** | end time of and thus departure time at this activity |  [optional]
**endDateTime** | **String** | end date time with offset like this 1970-01-01T01:00+01:00 |  [optional]
**arrDateTime** | **String** | arrival date time with offset like this 1970-01-01T01:00+01:00 |  [optional]
**waitingTime** | **Long** | waiting time at this activity in seconds |  [optional]
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



