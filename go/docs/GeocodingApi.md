# \GeocodingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GeocodeGet**](GeocodingApi.md#GeocodeGet) | **Get** /geocode | Execute a Geocoding request


# **GeocodeGet**
> GeocodingResponse GeocodeGet(ctx, key, optional)
Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **key** | **string**| Get your key at graphhopper.com | 
 **optional** | ***GeocodeGetOpts** | optional parameters | nil if no parameters

### Optional Parameters
Optional parameters are passed through a pointer to a GeocodeGetOpts struct

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------

 **q** | **optional.String**| If you do forward geocoding, then this would be a textual description of the address you are looking for | 
 **locale** | **optional.String**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | 
 **limit** | **optional.Int32**| Specify the maximum number of returned results | 
 **reverse** | **optional.Bool**| Set to true to do a reverse Geocoding request, see point parameter | 
 **point** | **optional.String**| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | 
 **provider** | **optional.String**| Can be either, default, nominatim, opencagedata | 

### Return type

[**GeocodingResponse**](GeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

