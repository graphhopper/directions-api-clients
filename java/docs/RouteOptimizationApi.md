# RouteOptimizationApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getSolution**](RouteOptimizationApi.md#getSolution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId
[**postVrp**](RouteOptimizationApi.md#postVrp) | **POST** /vrp/optimize | Solves vehicle routing problems


<a name="getSolution"></a>
# **getSolution**
> Response getSolution(key, jobId)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.api.RouteOptimizationApi;


RouteOptimizationApi apiInstance = new RouteOptimizationApi();
String key = "key_example"; // String | your API key
String jobId = "jobId_example"; // String | Request solution with jobId
try {
    Response result = apiInstance.getSolution(key, jobId);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling RouteOptimizationApi#getSolution");
    e.printStackTrace();
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

<a name="postVrp"></a>
# **postVrp**
> JobId postVrp(key, body)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution. 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.api.RouteOptimizationApi;


RouteOptimizationApi apiInstance = new RouteOptimizationApi();
String key = "key_example"; // String | your API key
Request body = new Request(); // Request | Request object that contains the problem to be solved
try {
    JobId result = apiInstance.postVrp(key, body);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling RouteOptimizationApi#postVrp");
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

