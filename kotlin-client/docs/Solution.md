# Solution

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**costs** | [**kotlin.Int**](.md) |  |  [optional]
**distance** | [**kotlin.Int**](.md) | Overall distance travelled in meter, i.e. the sum of each route&#x27;s transport distance |  [optional]
**time** | [**kotlin.Long**](.md) | Use &#x60;transport_time&#x60; instead. |  [optional]
**transportTime** | [**kotlin.Long**](.md) | Overall time travelled in seconds, i.e. the sum of each route&#x27;s transport time. |  [optional]
**maxOperationTime** | [**kotlin.Long**](.md) | Operation time of longest route in seconds. |  [optional]
**waitingTime** | [**kotlin.Long**](.md) | Overall waiting time in seconds. |  [optional]
**serviceDuration** | [**kotlin.Long**](.md) | Overall service time in seconds. |  [optional]
**preparationTime** | [**kotlin.Long**](.md) | Overall preparation time in seconds. |  [optional]
**completionTime** | [**kotlin.Long**](.md) | Overall completion time in seconds, i.e. the sum of each routes/drivers operation time. |  [optional]
**noVehicles** | [**kotlin.Int**](.md) | Number of employed vehicles. |  [optional]
**noUnassigned** | [**kotlin.Int**](.md) | Number of jobs that could not be assigned to final solution. |  [optional]
**routes** | [**kotlin.Array&lt;Route&gt;**](Route.md) | An array of routes |  [optional]
**unassigned** | [**SolutionUnassigned**](SolutionUnassigned.md) |  |  [optional]
