# \RouteOptimizationApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GetSolution**](RouteOptimizationApi.md#GetSolution) | **Get** /vrp/solution/{jobId} | Return the solution associated to the jobId
[**PostVrp**](RouteOptimizationApi.md#PostVrp) | **Post** /vrp/optimize | Solves vehicle routing problems


# **GetSolution**
> Response GetSolution($key, $jobId)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 


### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| your API key | 
 **jobId** | **string**| Request solution with jobId | 

### Return type

[**Response**](Response.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PostVrp**
> JobId PostVrp($key, $body)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution. 


### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| your API key | 
 **body** | [**Request**](Request.md)| Request object that contains the problem to be solved | 

### Return type

[**JobId**](JobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

