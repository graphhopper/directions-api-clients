# Request

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicles** | [**list[Vehicle]**](Vehicle.md) | Specifies the available vehicles. | [optional] 
**vehicle_types** | [**list[VehicleType]**](VehicleType.md) | Specifies the available vehicle types that are referred to by the specified vehicles. | [optional] 
**services** | [**list[Service]**](Service.md) | Specifies the available services, i.e. pickup, delivery or any other points to be visited by vehicles. Each service only involves exactly one location. | [optional] 
**shipments** | [**list[Shipment]**](Shipment.md) | Specifies the available shipments, i.e. pickup AND delivery points to be visited by vehicles subsequently. Each shipment involves exactly two locations, a pickup and a delivery location. | [optional] 
**relations** | [**list[Object]**](Object.md) | Specifies an arbitrary number of additional relations between and among services and shipments. | [optional] 
**algorithm** | [**Algorithm**](Algorithm.md) |  | [optional] 
**objectives** | [**list[Objective]**](Objective.md) | Specifies an array of objective functions. This tells the algorithm the objective of the optimization. | [optional] 
**cost_matrices** | [**list[CostMatrix]**](CostMatrix.md) | Specifies an array of cost matrix objects. This is used if you want to provide custom distance and/or time matrix values e.g. for time-dependent or indoor routing like for warehouses. | [optional] 
**configuration** | [**Configuration**](Configuration.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

