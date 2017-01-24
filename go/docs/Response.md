# Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Copyrights** | **[]string** |  | [optional] [default to null]
**JobId** | **string** | unique identify of job - which you get when posting your request to the large problem solver | [optional] [default to null]
**Status** | **string** | indicates the current status of the job | [optional] [default to null]
**WaitingInQueue** | **int64** | waiting time in ms | [optional] [default to null]
**ProcessingTime** | **int64** | processing time in ms. if job is still waiting in queue, processing_time is 0 | [optional] [default to null]
**Solution** | [**Solution**](Solution.md) | the solution. only available if status field indicates finished | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


