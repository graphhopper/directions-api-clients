
# Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | [**TypeEnum**](#TypeEnum) | type of activity |  [optional]
**id** | **String** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to |  [optional]
**locationId** | **String** | id that refers to address |  [optional]
**arrTime** | **Long** | arrival time at this activity in ms |  [optional]
**endTime** | **Long** | end time of and thus departure time at this activity |  [optional]
**waitingTime** | **Long** | waiting time at this activity in ms |  [optional]
**distance** | **Long** | cumulated distance from start to this activity in m |  [optional]
**drivingTime** | **Long** | driving time of driver in ms |  [optional]
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



