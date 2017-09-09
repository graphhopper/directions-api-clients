# MatrixApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**matrixGet**](MatrixApi.md#matrixGet) | **GET** /matrix | Matrix API
[**matrixPost**](MatrixApi.md#matrixPost) | **POST** /matrix | Matrix API Post


<a name="matrixGet"></a>
# **matrixGet**
> MatrixResponse matrixGet(key, point, fromPoint, toPoint, outArray, vehicle)

Matrix API

The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called &#39;via points&#39;, which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this. 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.api.MatrixApi;


MatrixApi apiInstance = new MatrixApi();
String key = "key_example"; // String | Get your key at graphhopper.com
List<String> point = Arrays.asList("point_example"); // List<String> | Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude.
String fromPoint = "fromPoint_example"; // String | The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude.
String toPoint = "toPoint_example"; // String | The destination points for the routes. Is a string with the format latitude,longitude.
List<String> outArray = Arrays.asList("outArray_example"); // List<String> | Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
String vehicle = "car"; // String | The vehicle for which the route should be calculated. Other vehicles are foot, bike, mtb, racingbike, motorcycle, small_truck, bus and truck. See here for the details.
try {
    MatrixResponse result = apiInstance.matrixGet(key, point, fromPoint, toPoint, outArray, vehicle);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling MatrixApi#matrixGet");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| Get your key at graphhopper.com |
 **point** | [**List&lt;String&gt;**](String.md)| Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude. | [optional]
 **fromPoint** | **String**| The starting points for the routes. E.g. if you want to calculate the three routes A-&amp;gt;1, A-&amp;gt;2, A-&amp;gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude. | [optional]
 **toPoint** | **String**| The destination points for the routes. Is a string with the format latitude,longitude. | [optional]
 **outArray** | [**List&lt;String&gt;**](String.md)| Specifies which arrays should be included in the response. Specify one or more of the following options &#39;weights&#39;, &#39;times&#39;, &#39;distances&#39;. To specify more than one array use e.g. out_array&#x3D;times&amp;out_array&#x3D;distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. | [optional]
 **vehicle** | **String**| The vehicle for which the route should be calculated. Other vehicles are foot, bike, mtb, racingbike, motorcycle, small_truck, bus and truck. See here for the details. | [optional] [default to car]

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

<a name="matrixPost"></a>
# **matrixPost**
> MatrixResponse matrixPost(key, body)

Matrix API Post

The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request. 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.api.MatrixApi;


MatrixApi apiInstance = new MatrixApi();
String key = "key_example"; // String | Get your key at graphhopper.com
MatrixRequest body = new MatrixRequest(); // MatrixRequest | 
try {
    MatrixResponse result = apiInstance.matrixPost(key, body);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling MatrixApi#matrixPost");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| Get your key at graphhopper.com |
 **body** | [**MatrixRequest**](MatrixRequest.md)|  | [optional]

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

