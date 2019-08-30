# Vehicle

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicleId** | **String** | Specifies the id of the vehicle. Ids need to be unique, thus if there two vehicles with the same id, an exception is thrown. | 
**typeId** | **String** | The type_id refers to specified vehicle type (see vehicle types). If it is omitted a default type will be used. |  [optional]
**startAddress** | [**Address**](Address.md) |  | 
**endAddress** | [**Address**](Address.md) |  |  [optional]
**_break** | [**AnyOfVehicleModelBreak**](AnyOfVehicleModelBreak.md) |  |  [optional]
**returnToDepot** | **Boolean** | If it is false, the algorithm decides where to end the vehicle route. It ends in one of your customers&#x27; locations. The end is chosen such that it contributes to the overall objective function, e.g. min transport_time. If it is true, you can either specify a specific end location (which is then regarded as end depot) or you can leave it and the driver returns to its start location. |  [optional]
**earliestStart** | **Long** | Earliest start of vehicle in seconds. It is recommended to use the unix timestamp. |  [optional]
**latestEnd** | **Long** | Latest end of vehicle in seconds, i.e. the time the vehicle needs to be at its end location at latest. |  [optional]
**skills** | **List&lt;String&gt;** | Array of skills, i.e. array of string (not case sensitive). |  [optional]
**maxDistance** | **Long** | Specifies the maximum distance a vehicle can go. |  [optional]
**maxDrivingTime** | **Long** | Specifies the maximum drive time a vehicle/driver can go, i.e. the maximum time on the road (service and waiting times are not included here) |  [optional]
**maxJobs** | **Integer** | Specifies the maximum number of jobs a vehicle can load. |  [optional]
**maxActivities** | **Integer** | Specifies the maximum number of activities a vehicle can conduct. |  [optional]
**moveToEndAddress** | **Boolean** | Indicates whether a vehicle should be moved even though it has not been assigned any jobs. |  [optional]
