# GraphHopperClient::Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | **Array&lt;String&gt;** |  | [optional] 
**job_id** | **String** | unique identify of job - which you get when posting your request to the large problem solver | [optional] 
**status** | **String** | indicates the current status of the job | [optional] 
**waiting_time_in_queue** | **Integer** | waiting time in ms | [optional] 
**processing_time** | **Integer** | processing time in ms. if job is still waiting in queue, processing_time is 0 | [optional] 
**solution** | [**Solution**](Solution.md) | the solution. only available if status field indicates finished | [optional] 


