# Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | **Vec<String>** |  | [optional] [default to null]
**job_id** | **String** | unique identify of job - which you get when posting your request to the large problem solver | [optional] [default to null]
**status** | **String** | indicates the current status of the job | [optional] [default to null]
**waiting_time_in_queue** | **i64** | waiting time in ms | [optional] [default to null]
**processing_time** | **i64** | processing time in ms. if job is still waiting in queue, processing_time is 0 | [optional] [default to null]
**solution** | [***::models::Solution**](Solution.md) | the solution. only available if status field indicates finished | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


