# GeocodingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**geocodeGet**](GeocodingApi.md#geocodeGet) | **GET** /geocode | Execute a Geocoding request


<a name="geocodeGet"></a>
# **geocodeGet**
> GHGeocodingResponse geocodeGet(key, q, locale, limit, reverse, point, provider)

Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.api.GeocodingApi;


GeocodingApi apiInstance = new GeocodingApi();
String key = "key_example"; // String | Get your key at graphhopper.com
String q = "q_example"; // String | If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon.
String locale = "locale_example"; // String | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
Integer limit = 56; // Integer | Specify the maximum number of returned results
Boolean reverse = true; // Boolean | Set to true to do a reverse Geocoding request
String point = "point_example"; // String | The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803
String provider = "provider_example"; // String | Can be either, default, nominatim, opencagedata
try {
    GHGeocodingResponse result = apiInstance.geocodeGet(key, q, locale, limit, reverse, point, provider);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling GeocodingApi#geocodeGet");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| Get your key at graphhopper.com |
 **q** | **String**| If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon. | [optional]
 **locale** | **String**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | [optional]
 **limit** | **Integer**| Specify the maximum number of returned results | [optional]
 **reverse** | **Boolean**| Set to true to do a reverse Geocoding request | [optional]
 **point** | **String**| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | [optional]
 **provider** | **String**| Can be either, default, nominatim, opencagedata | [optional]

### Return type

[**GHGeocodingResponse**](GHGeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

