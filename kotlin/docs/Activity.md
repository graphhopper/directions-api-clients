
# Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | [**inline**](#TypeEnum) | type of activity |  [optional]
**id** | **kotlin.String** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to |  [optional]
**location_id** | **kotlin.String** | id that refers to address |  [optional]
**arr_time** | **kotlin.Long** | arrival time at this activity in seconds |  [optional]
**end_time** | **kotlin.Long** | end time of and thus departure time at this activity |  [optional]
**waiting_time** | **kotlin.Long** | waiting time at this activity in seconds |  [optional]
**distance** | **kotlin.Long** | cumulated distance from start to this activity in m |  [optional]
**driving_time** | **kotlin.Long** | driving time of driver in seconds |  [optional]
**load_before** | **kotlin.Array&lt;kotlin.Int&gt;** | Array with size/capacity dimensions before this activity |  [optional]
**load_after** | **kotlin.Array&lt;kotlin.Int&gt;** | Array with size/capacity dimensions after this activity |  [optional]


<a name="TypeEnum"></a>
## Enum: type
Name | Value
---- | -----
type | start, end, service, pickupShipment, deliverShipment, pickup, delivery, break



