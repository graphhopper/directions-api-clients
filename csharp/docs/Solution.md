# IO.Swagger.Model.Solution
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Costs** | **int?** | overall costs of solution | [optional] 
**Distance** | **int?** | overall travel distance in meters | [optional] 
**Time** | **long?** | overall transport time in ms | [optional] 
**TransportTime** | **long?** | overall transport time in ms | [optional] 
**MaxOperationTime** | **long?** | operation time of the longest route in ms | [optional] 
**WaitingTime** | **long?** | total waiting time in ms | [optional] 
**NoVehicles** | **int?** | number of employed vehicles | [optional] 
**NoUnassigned** | **int?** | number of jobs that could not be assigned to final solution | [optional] 
**Routes** | [**List&lt;Route&gt;**](Route.md) | An array of routes | [optional] 
**Unassigned** | [**SolutionUnassigned**](SolutionUnassigned.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

