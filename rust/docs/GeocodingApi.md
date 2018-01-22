# \GeocodingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**geocode_get**](GeocodingApi.md#geocode_get) | **Get** /geocode | Execute a Geocoding request


# **geocode_get**
> ::models::GeocodingResponse geocode_get(key, optional)
Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
  **key** | **String**| Get your key at graphhopper.com | 
 **optional** | **map[string]interface{}** | optional parameters | nil if no parameters

### Optional Parameters
Optional parameters are passed through a map[string]interface{}.

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| Get your key at graphhopper.com | 
 **q** | **String**| If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon. | 
 **locale** | **String**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | 
 **limit** | **i32**| Specify the maximum number of returned results | 
 **reverse** | **bool**| Set to true to do a reverse Geocoding request | 
 **point** | **String**| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | 
 **provider** | **String**| Can be either, default, nominatim, opencagedata | 

### Return type

[**::models::GeocodingResponse**](GeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

