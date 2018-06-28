
# Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | **kotlin.Array&lt;kotlin.String&gt;** |  |  [optional]
**job_id** | **kotlin.String** | unique identify of job - which you get when posting your request to the large problem solver |  [optional]
**status** | [**inline**](#StatusEnum) | indicates the current status of the job |  [optional]
**waiting_in_queue** | **kotlin.Long** | waiting time in ms |  [optional]
**processing_time** | **kotlin.Long** | processing time in ms. if job is still waiting in queue, processing_time is 0 |  [optional]
**solution** | [**Solution**](Solution.md) |  |  [optional]


<a name="StatusEnum"></a>
## Enum: status
Name | Value
---- | -----
status | waiting_in_queue, processing, finished



