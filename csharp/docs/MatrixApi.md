# IO.Swagger.Api.MatrixApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**MatrixGet**](MatrixApi.md#matrixget) | **GET** /matrix | Matrix API
[**MatrixPost**](MatrixApi.md#matrixpost) | **POST** /matrix | Matrix API Post


<a name="matrixget"></a>
# **MatrixGet**
> MatrixResponse MatrixGet (string key, List<string> point = null, string fromPoint = null, string toPoint = null, List<string> outArray = null, string vehicle = null)

Matrix API

The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called 'via points', which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this. 

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class MatrixGetExample
    {
        public void main()
        {
            var apiInstance = new MatrixApi();
            var key = key_example;  // string | Get your key at graphhopper.com
            var point = new List<string>(); // List<string> | Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude. (optional) 
            var fromPoint = fromPoint_example;  // string | The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude. (optional) 
            var toPoint = toPoint_example;  // string | The destination points for the routes. Is a string with the format latitude,longitude. (optional) 
            var outArray = new List<string>(); // List<string> | Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. (optional) 
            var vehicle = vehicle_example;  // string | The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc, see here for the details. (optional)  (default to car)

            try
            {
                // Matrix API
                MatrixResponse result = apiInstance.MatrixGet(key, point, fromPoint, toPoint, outArray, vehicle);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling MatrixApi.MatrixGet: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| Get your key at graphhopper.com | 
 **point** | [**List&lt;string&gt;**](string.md)| Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude. | [optional] 
 **fromPoint** | **string**| The starting points for the routes. E.g. if you want to calculate the three routes A-&amp;gt;1, A-&amp;gt;2, A-&amp;gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude. | [optional] 
 **toPoint** | **string**| The destination points for the routes. Is a string with the format latitude,longitude. | [optional] 
 **outArray** | [**List&lt;string&gt;**](string.md)| Specifies which arrays should be included in the response. Specify one or more of the following options &#39;weights&#39;, &#39;times&#39;, &#39;distances&#39;. To specify more than one array use e.g. out_array&#x3D;times&amp;out_array&#x3D;distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. | [optional] 
 **vehicle** | **string**| The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc, see here for the details. | [optional] [default to car]

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="matrixpost"></a>
# **MatrixPost**
> MatrixResponse MatrixPost (string key, MatrixRequest body = null)

Matrix API Post

The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request. 

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class MatrixPostExample
    {
        public void main()
        {
            var apiInstance = new MatrixApi();
            var key = key_example;  // string | Get your key at graphhopper.com
            var body = new MatrixRequest(); // MatrixRequest |  (optional) 

            try
            {
                // Matrix API Post
                MatrixResponse result = apiInstance.MatrixPost(key, body);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling MatrixApi.MatrixPost: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| Get your key at graphhopper.com | 
 **body** | [**MatrixRequest**](MatrixRequest.md)|  | [optional] 

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

