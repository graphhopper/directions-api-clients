# OAIResponse

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**varCopyrights** | **NSArray&lt;NSString*&gt;*** |  | [optional] 
**jobId** | **NSString*** | unique identify of job - which you get when posting your request to the large problem solver | [optional] 
**status** | **NSString*** | indicates the current status of the job | [optional] 
**waitingInQueue** | **NSNumber*** | waiting time in ms | [optional] 
**processingTime** | **NSNumber*** | processing time in ms. if job is still waiting in queue, processing_time is 0 | [optional] 
**solution** | [**OAISolution***](OAISolution.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


