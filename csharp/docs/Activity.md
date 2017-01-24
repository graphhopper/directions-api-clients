# IO.Swagger.Model.Activity
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Type** | **string** | type of activity | [optional] 
**Id** | **string** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] 
**LocationId** | **string** | id that refers to address | [optional] 
**ArrTime** | **long?** | arrival time at this activity in ms | [optional] 
**EndTime** | **long?** | end time of and thus departure time at this activity | [optional] 
**WaitingTime** | **long?** | waiting time at this activity in ms | [optional] 
**Distance** | **long?** | cumulated distance from start to this activity in m | [optional] 
**DrivingTime** | **long?** | driving time of driver in ms | [optional] 
**LoadBefore** | **List&lt;int?&gt;** | Array with size/capacity dimensions before this activity | [optional] 
**LoadAfter** | **List&lt;int?&gt;** | Array with size/capacity dimensions after this activity | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

