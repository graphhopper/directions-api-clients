# WWW::SwaggerClient::GeocodingApi

## Load the API package
```perl
use WWW::SwaggerClient::Object::GeocodingApi;
```

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**geocode_get**](GeocodingApi.md#geocode_get) | **GET** /geocode | Execute a Geocoding request


# **geocode_get**
> GeocodingResponse geocode_get(key => $key, q => $q, locale => $locale, limit => $limit, reverse => $reverse, point => $point, provider => $provider)

Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 

### Example 
```perl
use Data::Dumper;
use WWW::SwaggerClient::GeocodingApi;
my $api_instance = WWW::SwaggerClient::GeocodingApi->new(
);

my $key = 'key_example'; # string | Get your key at graphhopper.com
my $q = 'q_example'; # string | If you do forward geocoding, then this would be a textual description of the address you are looking for
my $locale = 'locale_example'; # string | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
my $limit = 56; # int | Specify the maximum number of returned results
my $reverse = 1; # boolean | Set to true to do a reverse Geocoding request, see point parameter
my $point = 'point_example'; # string | The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803
my $provider = 'provider_example'; # string | Can be either, default, nominatim, opencagedata

eval { 
    my $result = $api_instance->geocode_get(key => $key, q => $q, locale => $locale, limit => $limit, reverse => $reverse, point => $point, provider => $provider);
    print Dumper($result);
};
if ($@) {
    warn "Exception when calling GeocodingApi->geocode_get: $@\n";
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| Get your key at graphhopper.com | 
 **q** | **string**| If you do forward geocoding, then this would be a textual description of the address you are looking for | [optional] 
 **locale** | **string**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | [optional] 
 **limit** | **int**| Specify the maximum number of returned results | [optional] 
 **reverse** | **boolean**| Set to true to do a reverse Geocoding request, see point parameter | [optional] 
 **point** | **string**| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | [optional] 
 **provider** | **string**| Can be either, default, nominatim, opencagedata | [optional] 

### Return type

[**GeocodingResponse**](GeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

