# IO.Swagger.Api.VrpApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PostVrp**](VrpApi.md#postvrp) | **POST** /vrp/optimize | Solves vehicle routing problems


<a name="postvrp"></a>
# **PostVrp**
> JobId PostVrp (string key, Request body)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class PostVrpExample
    {
        public void main()
        {
            var apiInstance = new VrpApi();
            var key = key_example;  // string | your API key
            var body = new Request(); // Request | Request object that contains the problem to be solved

            try
            {
                // Solves vehicle routing problems
                JobId result = apiInstance.PostVrp(key, body);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling VrpApi.PostVrp: " + e.Message );
            }
        }
    }
}
```

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

