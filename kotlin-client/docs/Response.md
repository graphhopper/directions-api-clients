# Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | [**kotlin.Array&lt;kotlin.String&gt;**](.md) |  |  [optional]
**jobId** | [**java.util.UUID**](java.util.UUID.md) | UUID. Unique identifier of job - which you get when posting your request to the large problem solver |  [optional]
**status** | [**inline**](#StatusEnum) | Indicates the current status of the job |  [optional]
**waitingTimeInQueue** | [**kotlin.Long**](.md) | Waiting time in ms |  [optional]
**processingTime** | [**kotlin.Long**](.md) | Processing time in ms. If job is still waiting in queue, processing_time is 0 |  [optional]
**solution** | [**Solution**](Solution.md) |  |  [optional]

<a name="StatusEnum"></a>
## Enum: status
Name | Value
---- | -----
status | waiting_in_queue, processing, finished
