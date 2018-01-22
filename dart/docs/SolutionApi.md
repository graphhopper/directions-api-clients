# swagger.api.SolutionApi

## Load the API package
```dart
import 'package:swagger/api.dart';
```

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getSolution**](SolutionApi.md#getSolution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId


# **getSolution**
> Response getSolution(key, jobId)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Example 
```dart
import 'package:swagger/api.dart';

var api_instance = new SolutionApi();
var key = key_example; // String | your API key
var jobId = jobId_example; // String | Request solution with jobId

try { 
    var result = api_instance.getSolution(key, jobId);
    print(result);
} catch (e) {
    print("Exception when calling SolutionApi->getSolution: $e\n");
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| your API key | 
 **jobId** | **String**| Request solution with jobId | 

### Return type

[**Response**](Response.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

