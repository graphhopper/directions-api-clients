# Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | **list[str]** |  | [optional] 
**job_id** | **str** | unique identify of job - which you get when posting your request to the large problem solver | [optional] 
**status** | **str** | indicates the current status of the job | [optional] 
**waiting_in_queue** | **int** | waiting time in ms | [optional] 
**processing_time** | **int** | processing time in ms. if job is still waiting in queue, processing_time is 0 | [optional] 
**solution** | [**Solution**](Solution.md) | the solution. only available if status field indicates finished | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


