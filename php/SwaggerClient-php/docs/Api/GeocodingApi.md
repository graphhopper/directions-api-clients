# Swagger\Client\GeocodingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**geocodeGet**](GeocodingApi.md#geocodeGet) | **GET** /geocode | Execute a Geocoding request


# **geocodeGet**
> \Swagger\Client\Model\GeocodingResponse geocodeGet($key, $q, $locale, $limit, $reverse, $point, $provider)

Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/

### Example
```php
<?php
require_once(__DIR__ . '/vendor/autoload.php');

$apiInstance = new Swagger\Client\Api\GeocodingApi(
    // If you want use custom http client, pass your client which implements `GuzzleHttp\ClientInterface`.
    // This is optional, `GuzzleHttp\Client` will be used as default.
    new GuzzleHttp\Client()
);
$key = "key_example"; // string | Get your key at graphhopper.com
$q = "q_example"; // string | If you do forward geocoding, then this would be a textual description of the address you are looking for
$locale = "locale_example"; // string | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
$limit = 56; // int | Specify the maximum number of returned results
$reverse = true; // bool | Set to true to do a reverse Geocoding request, see point parameter
$point = "point_example"; // string | The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803
$provider = "provider_example"; // string | Can be either, default, nominatim, opencagedata

try {
    $result = $apiInstance->geocodeGet($key, $q, $locale, $limit, $reverse, $point, $provider);
    print_r($result);
} catch (Exception $e) {
    echo 'Exception when calling GeocodingApi->geocodeGet: ', $e->getMessage(), PHP_EOL;
}
?>
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| Get your key at graphhopper.com |
 **q** | **string**| If you do forward geocoding, then this would be a textual description of the address you are looking for | [optional]
 **locale** | **string**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | [optional]
 **limit** | **int**| Specify the maximum number of returned results | [optional]
 **reverse** | **bool**| Set to true to do a reverse Geocoding request, see point parameter | [optional]
 **point** | **string**| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | [optional]
 **provider** | **string**| Can be either, default, nominatim, opencagedata | [optional]

### Return type

[**\Swagger\Client\Model\GeocodingResponse**](../Model/GeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to Model list]](../../README.md#documentation-for-models) [[Back to README]](../../README.md)

