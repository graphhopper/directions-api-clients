# \SolutionApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**get_solution**](SolutionApi.md#get_solution) | **Get** /vrp/solution/{jobId} | Return the solution associated to the jobId


# **get_solution**
> ::models::Response get_solution(key, job_id)
Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
  **key** | **String**| your API key | 
  **job_id** | **String**| Request solution with jobId | 

### Return type

[**::models::Response**](Response.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

