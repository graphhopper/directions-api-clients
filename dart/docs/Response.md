# swagger.model.Response

## Load the model package
```dart
import 'package:swagger/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**copyrights** | **List&lt;String&gt;** |  | [optional] [default to []]
**jobId** | **String** | unique identify of job - which you get when posting your request to the large problem solver | [optional] [default to null]
**status** | **String** | indicates the current status of the job | [optional] [default to null]
**waitingInQueue** | **int** | waiting time in ms | [optional] [default to null]
**processingTime** | **int** | processing time in ms. if job is still waiting in queue, processing_time is 0 | [optional] [default to null]
**solution** | [**Solution**](Solution.md) | the solution. only available if status field indicates finished | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


