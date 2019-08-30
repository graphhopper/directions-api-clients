# Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | **List&lt;String&gt;** |  |  [optional]
**jobId** | [**UUID**](UUID.md) | UUID. Unique identifier of job - which you get when posting your request to the large problem solver |  [optional]
**status** | [**StatusEnum**](#StatusEnum) | Indicates the current status of the job |  [optional]
**waitingTimeInQueue** | **Long** | Waiting time in ms |  [optional]
**processingTime** | **Long** | Processing time in ms. If job is still waiting in queue, processing_time is 0 |  [optional]
**solution** | [**Solution**](Solution.md) |  |  [optional]

<a name="StatusEnum"></a>
## Enum: StatusEnum
Name | Value
---- | -----
WAITING_IN_QUEUE | &quot;waiting_in_queue&quot;
PROCESSING | &quot;processing&quot;
FINISHED | &quot;finished&quot;
