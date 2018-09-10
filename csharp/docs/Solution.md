# IO.Swagger.Model.Solution
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Costs** | **int?** | overall costs of solution | [optional] 
**Distance** | **int?** | overall travel distance in meters | [optional] 
**Time** | **long?** | overall transport time in seconds | [optional] 
**TransportTime** | **long?** | overall transport time in seconds | [optional] 
**MaxOperationTime** | **long?** | operation time of the longest route in seconds | [optional] 
**WaitingTime** | **long?** | total waiting time in seconds | [optional] 
**ServiceDuration** | **long?** | total service time in seconds | [optional] 
**PreparationTime** | **long?** | total preparation time in seconds | [optional] 
**CompletionTime** | **long?** | total completion time in seconds | [optional] 
**NoVehicles** | **int?** | number of employed vehicles | [optional] 
**NoUnassigned** | **int?** | number of jobs that could not be assigned to final solution | [optional] 
**Routes** | [**List&lt;Route&gt;**](Route.md) | An array of routes | [optional] 
**Unassigned** | [**SolutionUnassigned**](SolutionUnassigned.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

