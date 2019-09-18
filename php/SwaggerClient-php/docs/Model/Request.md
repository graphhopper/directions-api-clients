# Request

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicles** | [**\Swagger\Client\Model\Vehicle[]**](Vehicle.md) | Specifies the available vehicles. | [optional] 
**vehicle_types** | [**\Swagger\Client\Model\VehicleType[]**](VehicleType.md) | Specifies the available vehicle types that are referred to by the specified vehicles. | [optional] 
**services** | [**\Swagger\Client\Model\Service[]**](Service.md) | Specifies the available services, i.e. pickup, delivery or any other points to be visited by vehicles. Each service only involves exactly one location. | [optional] 
**shipments** | [**\Swagger\Client\Model\Shipment[]**](Shipment.md) | Specifies the available shipments, i.e. pickup AND delivery points to be visited by vehicles subsequently. Each shipment involves exactly two locations, a pickup and a delivery location. | [optional] 
**relations** | [**null[]**](.md) | Specifies an arbitrary number of additional relations between and among services and shipments. | [optional] 
**algorithm** | [**\Swagger\Client\Model\Algorithm**](Algorithm.md) |  | [optional] 
**objectives** | [**\Swagger\Client\Model\Objective[]**](Objective.md) | Specifies an array of objective functions. This tells the algorithm the objective of the optimization. | [optional] 
**cost_matrices** | [**\Swagger\Client\Model\CostMatrix[]**](CostMatrix.md) | Specifies an array of cost matrix objects. This is used if you want to provide custom distance and/or time matrix values e.g. for time-dependent or indoor routing like for warehouses. | [optional] 
**configuration** | [**\Swagger\Client\Model\Configuration**](Configuration.md) |  | [optional] 

[[Back to Model list]](../../README.md#documentation-for-models) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to README]](../../README.md)

