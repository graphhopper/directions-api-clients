# swagger.api.VrpApi

## Load the API package
```dart
import 'package:swagger/api.dart';
```

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**postVrp**](VrpApi.md#postVrp) | **POST** /vrp/optimize | Solves vehicle routing problems


# **postVrp**
> JobId postVrp(key, body)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.

### Example 
```dart
import 'package:swagger/api.dart';

var api_instance = new VrpApi();
var key = key_example; // String | your API key
var body = new Request(); // Request | Request object that contains the problem to be solved

try { 
    var result = api_instance.postVrp(key, body);
    print(result);
} catch (e) {
    print("Exception when calling VrpApi->postVrp: $e\n");
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| your API key | 
 **body** | [**Request**](Request.md)| Request object that contains the problem to be solved | 

### Return type

[**JobId**](JobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

