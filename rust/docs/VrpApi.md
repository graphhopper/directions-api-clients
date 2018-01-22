# \VrpApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**post_vrp**](VrpApi.md#post_vrp) | **Post** /vrp/optimize | Solves vehicle routing problems


# **post_vrp**
> ::models::JobId post_vrp(key, body)
Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
  **key** | **String**| your API key | 
  **body** | [**Request**](Request.md)| Request object that contains the problem to be solved | 

### Return type

[**::models::JobId**](JobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

