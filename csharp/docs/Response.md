# IO.Swagger.Model.Response
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Copyrights** | **List&lt;string&gt;** |  | [optional] 
**JobId** | **string** | unique identify of job - which you get when posting your request to the large problem solver | [optional] 
**Status** | **string** | indicates the current status of the job | [optional] 
**WaitingInQueue** | **long?** | waiting time in ms | [optional] 
**ProcessingTime** | **long?** | processing time in ms. if job is still waiting in queue, processing_time is 0 | [optional] 
**Solution** | [**Solution**](Solution.md) | the solution. only available if status field indicates finished | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

