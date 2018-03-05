# GeocodingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**geocodeGet**](GeocodingApi.md#geocodeGet) | **GET** /geocode | Execute a Geocoding request


<a name="geocodeGet"></a>
# **geocodeGet**
> GeocodingResponse geocodeGet(key, q, locale, limit, reverse, point, provider)

Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 

### Example
```kotlin
// Import classes:
//import io.swagger.client.infrastructure.*
//import io.swagger.client.models.*

val apiInstance = GeocodingApi()
val key : kotlin.String = key_example // kotlin.String | Get your key at graphhopper.com
val q : kotlin.String = q_example // kotlin.String | If you do forward geocoding, then this would be a textual description of the address you are looking for
val locale : kotlin.String = locale_example // kotlin.String | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
val limit : kotlin.Int = 56 // kotlin.Int | Specify the maximum number of returned results
val reverse : kotlin.Boolean = true // kotlin.Boolean | Set to true to do a reverse Geocoding request, see point parameter
val point : kotlin.String = point_example // kotlin.String | The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803
val provider : kotlin.String = provider_example // kotlin.String | Can be either, default, nominatim, opencagedata
try {
    val result : GeocodingResponse = apiInstance.geocodeGet(key, q, locale, limit, reverse, point, provider)
    println(result)
} catch (e: ClientException) {
    println("4xx response calling GeocodingApi#geocodeGet")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling GeocodingApi#geocodeGet")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **kotlin.String**| Get your key at graphhopper.com |
 **q** | **kotlin.String**| If you do forward geocoding, then this would be a textual description of the address you are looking for | [optional]
 **locale** | **kotlin.String**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | [optional]
 **limit** | **kotlin.Int**| Specify the maximum number of returned results | [optional]
 **reverse** | **kotlin.Boolean**| Set to true to do a reverse Geocoding request, see point parameter | [optional]
 **point** | **kotlin.String**| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | [optional]
 **provider** | **kotlin.String**| Can be either, default, nominatim, opencagedata | [optional]

### Return type

[**GeocodingResponse**](GeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

