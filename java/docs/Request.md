# Request

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicles** | [**List&lt;Vehicle&gt;**](Vehicle.md) | Specifies the available vehicles. |  [optional]
**vehicleTypes** | [**List&lt;VehicleType&gt;**](VehicleType.md) | Specifies the available vehicle types that are referred to by the specified vehicles. |  [optional]
**services** | [**List&lt;Service&gt;**](Service.md) | Specifies the available services, i.e. pickup, delivery or any other points to be visited by vehicles. Each service only involves exactly one location. |  [optional]
**shipments** | [**List&lt;Shipment&gt;**](Shipment.md) | Specifies the available shipments, i.e. pickup AND delivery points to be visited by vehicles subsequently. Each shipment involves exactly two locations, a pickup and a delivery location. |  [optional]
**relations** | **List&lt;Object&gt;** | Specifies an arbitrary number of additional relations between and among services and shipments. |  [optional]
**algorithm** | [**Algorithm**](Algorithm.md) |  |  [optional]
**objectives** | [**List&lt;Objective&gt;**](Objective.md) | Specifies an array of objective functions. This tells the algorithm the objective of the optimization. |  [optional]
**costMatrices** | [**List&lt;CostMatrix&gt;**](CostMatrix.md) | Specifies an array of cost matrix objects. This is used if you want to provide custom distance and/or time matrix values e.g. for time-dependent or indoor routing like for warehouses. |  [optional]
**_configuration** | [**ModelConfiguration**](ModelConfiguration.md) |  |  [optional]
