# IO.Swagger.Model.Solution
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Costs** | **int?** |  | [optional] 
**Distance** | **int?** | Overall distance travelled in meter, i.e. the sum of each route&#x27;s transport distance | [optional] 
**Time** | **long?** | Use &#x60;transport_time&#x60; instead. | [optional] 
**TransportTime** | **long?** | Overall time travelled in seconds, i.e. the sum of each route&#x27;s transport time. | [optional] 
**MaxOperationTime** | **long?** | Operation time of longest route in seconds. | [optional] 
**WaitingTime** | **long?** | Overall waiting time in seconds. | [optional] 
**ServiceDuration** | **long?** | Overall service time in seconds. | [optional] 
**PreparationTime** | **long?** | Overall preparation time in seconds. | [optional] 
**CompletionTime** | **long?** | Overall completion time in seconds, i.e. the sum of each routes/drivers operation time. | [optional] 
**NoVehicles** | **int?** | Number of employed vehicles. | [optional] 
**NoUnassigned** | **int?** | Number of jobs that could not be assigned to final solution. | [optional] 
**Routes** | [**List&lt;Route&gt;**](Route.md) | An array of routes | [optional] 
**Unassigned** | [**SolutionUnassigned**](SolutionUnassigned.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

