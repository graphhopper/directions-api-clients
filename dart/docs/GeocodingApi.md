# swagger.api.GeocodingApi

## Load the API package
```dart
import 'package:swagger/api.dart';
```

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**geocodeGet**](GeocodingApi.md#geocodeGet) | **GET** /geocode | Execute a Geocoding request


# **geocodeGet**
> GeocodingResponse geocodeGet(key, q, locale, limit, reverse, point, provider)

Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 

### Example 
```dart
import 'package:swagger/api.dart';

var api_instance = new GeocodingApi();
var key = key_example; // String | Get your key at graphhopper.com
var q = q_example; // String | If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon.
var locale = locale_example; // String | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
var limit = 56; // int | Specify the maximum number of returned results
var reverse = true; // bool | Set to true to do a reverse Geocoding request
var point = point_example; // String | The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803
var provider = provider_example; // String | Can be either, default, nominatim, opencagedata

try { 
    var result = api_instance.geocodeGet(key, q, locale, limit, reverse, point, provider);
    print(result);
} catch (e) {
    print("Exception when calling GeocodingApi->geocodeGet: $e\n");
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| Get your key at graphhopper.com | 
 **q** | **String**| If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon. | [optional] 
 **locale** | **String**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | [optional] 
 **limit** | **int**| Specify the maximum number of returned results | [optional] 
 **reverse** | **bool**| Set to true to do a reverse Geocoding request | [optional] 
 **point** | **String**| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | [optional] 
 **provider** | **String**| Can be either, default, nominatim, opencagedata | [optional] 

### Return type

[**GeocodingResponse**](GeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

