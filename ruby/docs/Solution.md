# GraphHopperClient::Solution

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**costs** | **Integer** | overall costs of solution | [optional] 
**distance** | **Integer** | overall travel distance in meters | [optional] 
**time** | **Integer** | overall transport time in seconds | [optional] 
**transport_time** | **Integer** | overall transport time in seconds | [optional] 
**max_operation_time** | **Integer** | operation time of the longest route in seconds | [optional] 
**waiting_time** | **Integer** | total waiting time in seconds | [optional] 
**service_duration** | **Integer** | total service time in seconds | [optional] 
**preparation_time** | **Integer** | total preparation time in seconds | [optional] 
**completion_time** | **Integer** | total completion time in seconds | [optional] 
**no_vehicles** | **Integer** | number of employed vehicles | [optional] 
**no_unassigned** | **Integer** | number of jobs that could not be assigned to final solution | [optional] 
**routes** | [**Array&lt;Route&gt;**](Route.md) | An array of routes | [optional] 
**unassigned** | [**SolutionUnassigned**](SolutionUnassigned.md) |  | [optional] 


