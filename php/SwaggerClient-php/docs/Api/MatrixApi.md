# Swagger\Client\MatrixApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**matrixGet**](MatrixApi.md#matrixGet) | **GET** /matrix | Matrix API
[**matrixPost**](MatrixApi.md#matrixPost) | **POST** /matrix | Matrix API Post


# **matrixGet**
> \Swagger\Client\Model\MatrixResponse matrixGet($key, $point, $from_point, $to_point, $point_hint, $from_point_hint, $to_point_hint, $out_array, $vehicle)

Matrix API

The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called 'via points', which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this.

### Example
```php
<?php
require_once(__DIR__ . '/vendor/autoload.php');

$apiInstance = new Swagger\Client\Api\MatrixApi(
    // If you want use custom http client, pass your client which implements `GuzzleHttp\ClientInterface`.
    // This is optional, `GuzzleHttp\Client` will be used as default.
    new GuzzleHttp\Client()
);
$key = "key_example"; // string | Get your key at graphhopper.com
$point = array("point_example"); // string[] | Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude.
$from_point = array("from_point_example"); // string[] | The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude.
$to_point = array("to_point_example"); // string[] | The destination points for the routes. Is a string with the format latitude,longitude.
$point_hint = array("point_hint_example"); // string[] | Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up.
$from_point_hint = array("from_point_hint_example"); // string[] | For the from_point parameter. See point_hint
$to_point_hint = array("to_point_hint_example"); // string[] | For the to_point parameter. See point_hint
$out_array = array("out_array_example"); // string[] | Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
$vehicle = "car"; // string | The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc

try {
    $result = $apiInstance->matrixGet($key, $point, $from_point, $to_point, $point_hint, $from_point_hint, $to_point_hint, $out_array, $vehicle);
    print_r($result);
} catch (Exception $e) {
    echo 'Exception when calling MatrixApi->matrixGet: ', $e->getMessage(), PHP_EOL;
}
?>
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| Get your key at graphhopper.com |
 **point** | [**string[]**](../Model/string.md)| Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude. | [optional]
 **from_point** | [**string[]**](../Model/string.md)| The starting points for the routes. E.g. if you want to calculate the three routes A-&amp;gt;1, A-&amp;gt;2, A-&amp;gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude. | [optional]
 **to_point** | [**string[]**](../Model/string.md)| The destination points for the routes. Is a string with the format latitude,longitude. | [optional]
 **point_hint** | [**string[]**](../Model/string.md)| Optional parameter. Specifies a hint for each &#x60;point&#x60; parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. | [optional]
 **from_point_hint** | [**string[]**](../Model/string.md)| For the from_point parameter. See point_hint | [optional]
 **to_point_hint** | [**string[]**](../Model/string.md)| For the to_point parameter. See point_hint | [optional]
 **out_array** | [**string[]**](../Model/string.md)| Specifies which arrays should be included in the response. Specify one or more of the following options &#39;weights&#39;, &#39;times&#39;, &#39;distances&#39;. To specify more than one array use e.g. out_array&#x3D;times&amp;out_array&#x3D;distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. | [optional]
 **vehicle** | **string**| The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc | [optional] [default to car]

### Return type

[**\Swagger\Client\Model\MatrixResponse**](../Model/MatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to Model list]](../../README.md#documentation-for-models) [[Back to README]](../../README.md)

# **matrixPost**
> \Swagger\Client\Model\MatrixResponse matrixPost($key, $body)

Matrix API Post

The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request.

### Example
```php
<?php
require_once(__DIR__ . '/vendor/autoload.php');

$apiInstance = new Swagger\Client\Api\MatrixApi(
    // If you want use custom http client, pass your client which implements `GuzzleHttp\ClientInterface`.
    // This is optional, `GuzzleHttp\Client` will be used as default.
    new GuzzleHttp\Client()
);
$key = "key_example"; // string | Get your key at graphhopper.com
$body = new \Swagger\Client\Model\MatrixRequest(); // \Swagger\Client\Model\MatrixRequest | 

try {
    $result = $apiInstance->matrixPost($key, $body);
    print_r($result);
} catch (Exception $e) {
    echo 'Exception when calling MatrixApi->matrixPost: ', $e->getMessage(), PHP_EOL;
}
?>
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| Get your key at graphhopper.com |
 **body** | [**\Swagger\Client\Model\MatrixRequest**](../Model/MatrixRequest.md)|  | [optional]

### Return type

[**\Swagger\Client\Model\MatrixResponse**](../Model/MatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to Model list]](../../README.md#documentation-for-models) [[Back to README]](../../README.md)

