# VrpApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**postVrp**](VrpApi.md#postVrp) | **POST** /vrp/optimize | Solves vehicle routing problems


<a name="postVrp"></a>
# **postVrp**
> JobId postVrp(key, body)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.api.VrpApi;


VrpApi apiInstance = new VrpApi();
String key = "key_example"; // String | your API key
Request body = new Request(); // Request | Request object that contains the problem to be solved
try {
    JobId result = apiInstance.postVrp(key, body);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling VrpApi#postVrp");
    e.printStackTrace();
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

