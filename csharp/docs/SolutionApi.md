# IO.Swagger.Api.SolutionApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GetSolution**](SolutionApi.md#getsolution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId


<a name="getsolution"></a>
# **GetSolution**
> Response GetSolution (string key, string jobId)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class GetSolutionExample
    {
        public void main()
        {
            var apiInstance = new SolutionApi();
            var key = key_example;  // string | your API key
            var jobId = jobId_example;  // string | Request solution with jobId

            try
            {
                // Return the solution associated to the jobId
                Response result = apiInstance.GetSolution(key, jobId);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling SolutionApi.GetSolution: " + e.Message );
            }
        }
    }
}
```

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

