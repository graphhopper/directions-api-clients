# IO.Swagger.Model.Response
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Copyrights** | **List&lt;string&gt;** |  | [optional] 
**JobId** | **Guid?** | UUID. Unique identifier of job - which you get when posting your request to the large problem solver | [optional] 
**Status** | **string** | Indicates the current status of the job | [optional] 
**WaitingTimeInQueue** | **long?** | Waiting time in ms | [optional] 
**ProcessingTime** | **long?** | Processing time in ms. If job is still waiting in queue, processing_time is 0 | [optional] 
**Solution** | [**Solution**](Solution.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

