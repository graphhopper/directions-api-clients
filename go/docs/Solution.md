# Solution

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Costs** | **int32** | overall costs of solution | [optional] [default to null]
**Distance** | **int32** | overall travel distance in meters | [optional] [default to null]
**Time** | **int64** | overall transport time in ms | [optional] [default to null]
**TransportTime** | **int64** | overall transport time in ms | [optional] [default to null]
**MaxOperationTime** | **int64** | operation time of the longest route in ms | [optional] [default to null]
**WaitingTime** | **int64** | total waiting time in ms | [optional] [default to null]
**NoVehicles** | **int32** | number of employed vehicles | [optional] [default to null]
**NoUnassigned** | **int32** | number of jobs that could not be assigned to final solution | [optional] [default to null]
**Routes** | [**[]Route**](Route.md) | An array of routes | [optional] [default to null]
**Unassigned** | [**SolutionUnassigned**](Solution_unassigned.md) |  | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


