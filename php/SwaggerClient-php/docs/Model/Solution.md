# Solution

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**costs** | **int** |  | [optional] 
**distance** | **int** | Overall distance travelled in meter, i.e. the sum of each route&#x27;s transport distance | [optional] 
**time** | **int** | Use &#x60;transport_time&#x60; instead. | [optional] 
**transport_time** | **int** | Overall time travelled in seconds, i.e. the sum of each route&#x27;s transport time. | [optional] 
**max_operation_time** | **int** | Operation time of longest route in seconds. | [optional] 
**waiting_time** | **int** | Overall waiting time in seconds. | [optional] 
**service_duration** | **int** | Overall service time in seconds. | [optional] 
**preparation_time** | **int** | Overall preparation time in seconds. | [optional] 
**completion_time** | **int** | Overall completion time in seconds, i.e. the sum of each routes/drivers operation time. | [optional] 
**no_vehicles** | **int** | Number of employed vehicles. | [optional] 
**no_unassigned** | **int** | Number of jobs that could not be assigned to final solution. | [optional] 
**routes** | [**\Swagger\Client\Model\Route[]**](Route.md) | An array of routes | [optional] 
**unassigned** | [**\Swagger\Client\Model\SolutionUnassigned**](SolutionUnassigned.md) |  | [optional] 

[[Back to Model list]](../../README.md#documentation-for-models) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to README]](../../README.md)

