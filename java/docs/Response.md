
# Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | **List&lt;String&gt;** |  |  [optional]
**jobId** | **String** | unique identify of job - which you get when posting your request to the large problem solver |  [optional]
**status** | [**StatusEnum**](#StatusEnum) | indicates the current status of the job |  [optional]
**waitingInQueue** | **Long** | waiting time in ms |  [optional]
**processingTime** | **Long** | processing time in ms. if job is still waiting in queue, processing_time is 0 |  [optional]
**solution** | [**Solution**](Solution.md) | the solution. only available if status field indicates finished |  [optional]


<a name="StatusEnum"></a>
## Enum: StatusEnum
Name | Value
---- | -----
WAITING_IN_QUEUE | &quot;waiting_in_queue&quot;
PROCESSING | &quot;processing&quot;
FINISHED | &quot;finished&quot;



