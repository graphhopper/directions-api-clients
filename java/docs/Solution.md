# Solution

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**costs** | **Integer** |  |  [optional]
**distance** | **Integer** | Overall distance travelled in meter, i.e. the sum of each route&#x27;s transport distance |  [optional]
**time** | **Long** | Use &#x60;transport_time&#x60; instead. |  [optional]
**transportTime** | **Long** | Overall time travelled in seconds, i.e. the sum of each route&#x27;s transport time. |  [optional]
**maxOperationTime** | **Long** | Operation time of longest route in seconds. |  [optional]
**waitingTime** | **Long** | Overall waiting time in seconds. |  [optional]
**serviceDuration** | **Long** | Overall service time in seconds. |  [optional]
**preparationTime** | **Long** | Overall preparation time in seconds. |  [optional]
**completionTime** | **Long** | Overall completion time in seconds, i.e. the sum of each routes/drivers operation time. |  [optional]
**noVehicles** | **Integer** | Number of employed vehicles. |  [optional]
**noUnassigned** | **Integer** | Number of jobs that could not be assigned to final solution. |  [optional]
**routes** | [**List&lt;Route&gt;**](Route.md) | An array of routes |  [optional]
**unassigned** | [**SolutionUnassigned**](SolutionUnassigned.md) |  |  [optional]
