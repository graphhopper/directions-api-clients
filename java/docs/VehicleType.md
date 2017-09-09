
# VehicleType

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**typeId** | **String** | Unique identifier for the vehicle type |  [optional]
**profile** | [**ProfileEnum**](#ProfileEnum) | Profile of vehicle type |  [optional]
**capacity** | **List&lt;Integer&gt;** | array of capacity dimensions |  [optional]
**speedFactor** | **Double** | speed_factor of vehicle type |  [optional]
**serviceTimeFactor** | **Double** | service time factor of vehicle type |  [optional]
**costPerMeter** | **Double** | cost parameter per distance unit, here meter is used |  [optional]
**costPerSecond** | **Double** | cost parameter per time unit, here second is used |  [optional]
**costPerActivation** | **Double** | cost parameter vehicle activation, i.e. fixed costs per vehicle |  [optional]


<a name="ProfileEnum"></a>
## Enum: ProfileEnum
Name | Value
---- | -----
CAR | &quot;car&quot;
BIKE | &quot;bike&quot;
FOOT | &quot;foot&quot;
MTB | &quot;mtb&quot;
MOTORCYCLE | &quot;motorcycle&quot;
RACINGBIKE | &quot;racingbike&quot;
TRUCK | &quot;truck&quot;
SMALL_TRUCK | &quot;small_truck&quot;



