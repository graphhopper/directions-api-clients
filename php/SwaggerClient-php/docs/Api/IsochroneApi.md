# Swagger\Client\IsochroneApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**isochroneGet**](IsochroneApi.md#isochroneGet) | **GET** /isochrone | Isochrone Request


# **isochroneGet**
> \Swagger\Client\Model\IsochroneResponse isochroneGet($point, $key, $time_limit, $distance_limit, $vehicle, $buckets, $reverse_flow)

Isochrone Request

The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**.

### Example
```php
<?php
require_once(__DIR__ . '/vendor/autoload.php');

$api_instance = new Swagger\Client\Api\IsochroneApi();
$point = "point_example"; // string | Specify the start coordinate
$key = "key_example"; // string | Get your key at graphhopper.com
$time_limit = 600; // int | Specify which time the vehicle should travel. In seconds.
$distance_limit = -1; // int | Specify which distance the vehicle should travel. In meter.
$vehicle = "car"; // string | Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/)
$buckets = 1; // int | For how many sub intervals an additional polygon should be calculated.
$reverse_flow = false; // bool | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*

try {
    $result = $api_instance->isochroneGet($point, $key, $time_limit, $distance_limit, $vehicle, $buckets, $reverse_flow);
    print_r($result);
} catch (Exception $e) {
    echo 'Exception when calling IsochroneApi->isochroneGet: ', $e->getMessage(), PHP_EOL;
}
?>
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **string**| Specify the start coordinate |
 **key** | **string**| Get your key at graphhopper.com |
 **time_limit** | **int**| Specify which time the vehicle should travel. In seconds. | [optional] [default to 600]
 **distance_limit** | **int**| Specify which distance the vehicle should travel. In meter. | [optional] [default to -1]
 **vehicle** | **string**| Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) | [optional] [default to car]
 **buckets** | **int**| For how many sub intervals an additional polygon should be calculated. | [optional] [default to 1]
 **reverse_flow** | **bool**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example usage for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.* | [optional] [default to false]

### Return type

[**\Swagger\Client\Model\IsochroneResponse**](../Model/IsochroneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to Model list]](../../README.md#documentation-for-models) [[Back to README]](../../README.md)

