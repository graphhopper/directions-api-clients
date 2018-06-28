# Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | **Vec<String>** |  | [optional] 
**job_id** | **String** | unique identify of job - which you get when posting your request to the large problem solver | [optional] 
**status** | **String** | indicates the current status of the job | [optional] 
**waiting_in_queue** | **i64** | waiting time in ms | [optional] 
**processing_time** | **i64** | processing time in ms. if job is still waiting in queue, processing_time is 0 | [optional] 
**solution** | [***::models::Solution**](Solution.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


