# Swagger\Client\MatrixApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**matrixGet**](MatrixApi.md#matrixGet) | **GET** /matrix | Matrix API
[**matrixPost**](MatrixApi.md#matrixPost) | **POST** /matrix | Matrix API Post


# **matrixGet**
> \Swagger\Client\Model\GHMatrixResponse matrixGet($key, $point, $from_point, $to_point, $out_array, $vehicle)

Matrix API

The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called 'via points', which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this.

### Example
```php
<?php
require_once(__DIR__ . '/vendor/autoload.php');

$api_instance = new Swagger\Client\Api\MatrixApi();
$key = "key_example"; // string | Get your key at graphhopper.com
$point = array("point_example"); // string[] | Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude.
$from_point = "from_point_example"; // string | The starting points for the routes. E.g. if you want to calculate the three routes A->1, A->2, A->3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude.
$to_point = "to_point_example"; // string | The destination points for the routes. Is a string with the format latitude,longitude.
$out_array = array("out_array_example"); // string[] | pecifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
$vehicle = "car"; // string | The vehicle for which the route should be calculated. Other vehicles are foot, bike, mtb, racingbike, motorcycle, small_truck, bus and truck. See here for the details.

try {
    $result = $api_instance->matrixGet($key, $point, $from_point, $to_point, $out_array, $vehicle);
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
 **from_point** | **string**| The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude. | [optional]
 **to_point** | **string**| The destination points for the routes. Is a string with the format latitude,longitude. | [optional]
 **out_array** | [**string[]**](../Model/string.md)| pecifies which arrays should be included in the response. Specify one or more of the following options &#39;weights&#39;, &#39;times&#39;, &#39;distances&#39;. To specify more than one array use e.g. out_array&#x3D;times&amp;out_array&#x3D;distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. | [optional]
 **vehicle** | **string**| The vehicle for which the route should be calculated. Other vehicles are foot, bike, mtb, racingbike, motorcycle, small_truck, bus and truck. See here for the details. | [optional] [default to car]

### Return type

[**\Swagger\Client\Model\GHMatrixResponse**](../Model/GHMatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to Model list]](../../README.md#documentation-for-models) [[Back to README]](../../README.md)

# **matrixPost**
> \Swagger\Client\Model\GHMatrixResponse matrixPost($key, $body)

Matrix API Post

The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request.

### Example
```php
<?php
require_once(__DIR__ . '/vendor/autoload.php');

$api_instance = new Swagger\Client\Api\MatrixApi();
$key = "key_example"; // string | Get your key at graphhopper.com
$body = new \Swagger\Client\Model\GHMatrixRequest(); // \Swagger\Client\Model\GHMatrixRequest | 

try {
    $result = $api_instance->matrixPost($key, $body);
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
 **body** | [**\Swagger\Client\Model\GHMatrixRequest**](../Model/\Swagger\Client\Model\GHMatrixRequest.md)|  | [optional]

### Return type

[**\Swagger\Client\Model\GHMatrixResponse**](../Model/GHMatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to Model list]](../../README.md#documentation-for-models) [[Back to README]](../../README.md)

