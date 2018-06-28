# SolutionApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getSolution**](SolutionApi.md#getSolution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId


<a name="getSolution"></a>
# **getSolution**
> Response getSolution(key, jobId)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Example
```kotlin
// Import classes:
//import org.openapitools.client.infrastructure.*
//import org.openapitools.client.models.*

val apiInstance = SolutionApi()
val key : kotlin.String = key_example // kotlin.String | your API key
val jobId : kotlin.String = jobId_example // kotlin.String | Request solution with jobId
try {
    val result : Response = apiInstance.getSolution(key, jobId)
    println(result)
} catch (e: ClientException) {
    println("4xx response calling SolutionApi#getSolution")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling SolutionApi#getSolution")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **kotlin.String**| your API key |
 **jobId** | **kotlin.String**| Request solution with jobId |

### Return type

[**Response**](Response.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

