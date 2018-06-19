# MatrixApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**matrixGet**](MatrixApi.md#matrixGet) | **GET** /matrix | Matrix API
[**matrixPost**](MatrixApi.md#matrixPost) | **POST** /matrix | Matrix API Post


<a name="matrixGet"></a>
# **matrixGet**
> MatrixResponse matrixGet(key, point, fromPoint, toPoint, pointHint, fromPointHint, toPointHint, outArray, vehicle)

Matrix API

The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called &#39;via points&#39;, which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this. 

### Example
```kotlin
// Import classes:
//import io.swagger.client.infrastructure.*
//import io.swagger.client.models.*

val apiInstance = MatrixApi()
val key : kotlin.String = key_example // kotlin.String | Get your key at graphhopper.com
val point : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude.
val fromPoint : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude.
val toPoint : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | The destination points for the routes. Is a string with the format latitude,longitude.
val pointHint : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up.
val fromPointHint : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | For the from_point parameter. See point_hint
val toPointHint : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | For the to_point parameter. See point_hint
val outArray : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
val vehicle : kotlin.String = vehicle_example // kotlin.String | The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc
try {
    val result : MatrixResponse = apiInstance.matrixGet(key, point, fromPoint, toPoint, pointHint, fromPointHint, toPointHint, outArray, vehicle)
    println(result)
} catch (e: ClientException) {
    println("4xx response calling MatrixApi#matrixGet")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling MatrixApi#matrixGet")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **kotlin.String**| Get your key at graphhopper.com |
 **point** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude. | [optional]
 **fromPoint** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| The starting points for the routes. E.g. if you want to calculate the three routes A-&amp;gt;1, A-&amp;gt;2, A-&amp;gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude. | [optional]
 **toPoint** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| The destination points for the routes. Is a string with the format latitude,longitude. | [optional]
 **pointHint** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| Optional parameter. Specifies a hint for each &#x60;point&#x60; parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. | [optional]
 **fromPointHint** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| For the from_point parameter. See point_hint | [optional]
 **toPointHint** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| For the to_point parameter. See point_hint | [optional]
 **outArray** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| Specifies which arrays should be included in the response. Specify one or more of the following options &#39;weights&#39;, &#39;times&#39;, &#39;distances&#39;. To specify more than one array use e.g. out_array&#x3D;times&amp;out_array&#x3D;distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. | [optional]
 **vehicle** | **kotlin.String**| The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc | [optional] [default to car]

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
```kotlin
// Import classes:
//import io.swagger.client.infrastructure.*
//import io.swagger.client.models.*

val apiInstance = MatrixApi()
val key : kotlin.String = key_example // kotlin.String | Get your key at graphhopper.com
val body : MatrixRequest =  // MatrixRequest | 
try {
    val result : MatrixResponse = apiInstance.matrixPost(key, body)
    println(result)
} catch (e: ClientException) {
    println("4xx response calling MatrixApi#matrixPost")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling MatrixApi#matrixPost")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **kotlin.String**| Get your key at graphhopper.com |
 **body** | [**MatrixRequest**](MatrixRequest.md)|  | [optional]

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

