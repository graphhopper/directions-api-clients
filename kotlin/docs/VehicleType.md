
# VehicleType

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type_id** | **kotlin.String** | Unique identifier for the vehicle type |  [optional]
**profile** | [**inline**](#ProfileEnum) | Profile of vehicle type |  [optional]
**capacity** | **kotlin.Array&lt;kotlin.Int&gt;** | array of capacity dimensions |  [optional]
**speed_factor** | **kotlin.Double** | speed_factor of vehicle type |  [optional]
**service_time_factor** | **kotlin.Double** | service time factor of vehicle type |  [optional]
**cost_per_meter** | **kotlin.Double** | cost parameter per distance unit, here meter is used |  [optional]
**cost_per_second** | **kotlin.Double** | cost parameter per time unit, here second is used |  [optional]
**cost_per_activation** | **kotlin.Double** | cost parameter vehicle activation, i.e. fixed costs per vehicle |  [optional]


<a name="ProfileEnum"></a>
## Enum: profile
Name | Value
---- | -----
profile | car, bike, foot, mtb, racingbike, truck, small_truck



