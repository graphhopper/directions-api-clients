# DirectionsApiClient::Solution

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**costs** | **Integer** | overall costs of solution | [optional] 
**distance** | **Integer** | overall travel distance in meters | [optional] 
**time** | **Integer** | overall transport time in ms | [optional] 
**transport_time** | **Integer** | overall transport time in ms | [optional] 
**max_operation_time** | **Integer** | operation time of the longest route in ms | [optional] 
**waiting_time** | **Integer** | total waiting time in ms | [optional] 
**no_vehicles** | **Integer** | number of employed vehicles | [optional] 
**no_unassigned** | **Integer** | number of jobs that could not be assigned to final solution | [optional] 
**routes** | [**Array&lt;Route&gt;**](Route.md) | An array of routes | [optional] 
**unassigned** | [**SolutionUnassigned**](SolutionUnassigned.md) |  | [optional] 


