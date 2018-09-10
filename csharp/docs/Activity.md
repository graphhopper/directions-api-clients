# IO.Swagger.Model.Activity
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Type** | **string** | type of activity | [optional] 
**Id** | **string** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] 
**LocationId** | **string** | id that refers to address | [optional] 
**Address** | [**Address**](Address.md) | address of activity | [optional] 
**ArrTime** | **long?** | arrival time at this activity in seconds | [optional] 
**EndTime** | **long?** | end time of and thus departure time at this activity | [optional] 
**EndDateTime** | **string** | end date time with offset like this 1970-01-01T01:00+01:00 | [optional] 
**ArrDateTime** | **string** | arrival date time with offset like this 1970-01-01T01:00+01:00 | [optional] 
**WaitingTime** | **long?** | waiting time at this activity in seconds | [optional] 
**PreparationTime** | **long?** | preparation time at this activity in seconds | [optional] 
**Distance** | **long?** | cumulated distance from start to this activity in m | [optional] 
**DrivingTime** | **long?** | driving time of driver in seconds | [optional] 
**LoadBefore** | **List&lt;int?&gt;** | Array with size/capacity dimensions before this activity | [optional] 
**LoadAfter** | **List&lt;int?&gt;** | Array with size/capacity dimensions after this activity | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

