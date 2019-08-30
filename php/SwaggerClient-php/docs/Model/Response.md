# Response

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | **string[]** |  | [optional] 
**job_id** | **string** | UUID. Unique identifier of job - which you get when posting your request to the large problem solver | [optional] 
**status** | **string** | Indicates the current status of the job | [optional] 
**waiting_time_in_queue** | **int** | Waiting time in ms | [optional] 
**processing_time** | **int** | Processing time in ms. If job is still waiting in queue, processing_time is 0 | [optional] 
**solution** | [**\Swagger\Client\Model\Solution**](Solution.md) |  | [optional] 

[[Back to Model list]](../../README.md#documentation-for-models) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to README]](../../README.md)

