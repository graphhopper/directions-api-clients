# VrpApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**postVrp**](VrpApi.md#postVrp) | **POST** /vrp/optimize | Solves vehicle routing problems


<a name="postVrp"></a>
# **postVrp**
> JobId postVrp(key, request)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.

### Example
```kotlin
// Import classes:
//import org.openapitools.client.infrastructure.*
//import org.openapitools.client.models.*

val apiInstance = VrpApi()
val key : kotlin.String = key_example // kotlin.String | your API key
val request : Request =  // Request | Request object that contains the problem to be solved
try {
    val result : JobId = apiInstance.postVrp(key, request)
    println(result)
} catch (e: ClientException) {
    println("4xx response calling VrpApi#postVrp")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling VrpApi#postVrp")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **kotlin.String**| your API key |
 **request** | [**Request**](Request.md)| Request object that contains the problem to be solved |

### Return type

[**JobId**](JobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

