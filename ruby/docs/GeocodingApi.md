# GraphHopperClient::GeocodingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**geocode_get**](GeocodingApi.md#geocode_get) | **GET** /geocode | Execute a Geocoding request


# **geocode_get**
> GeocodingResponse geocode_get(key, opts)

Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 

### Example
```ruby
# load the gem
require 'directions-api-client'

api_instance = GraphHopperClient::GeocodingApi.new

key = "key_example" # String | Get your key at graphhopper.com

opts = { 
  q: "q_example", # String | If you do forward geocoding, then this would be a textual description of the address you are looking for
  locale: "locale_example", # String | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
  limit: 56, # Integer | Specify the maximum number of returned results
  reverse: true, # BOOLEAN | Set to true to do a reverse Geocoding request, see point parameter
  point: "point_example", # String | The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803
  provider: "provider_example" # String | Can be either, default, nominatim, opencagedata
}

begin
  #Execute a Geocoding request
  result = api_instance.geocode_get(key, opts)
  p result
rescue GraphHopperClient::ApiError => e
  puts "Exception when calling GeocodingApi->geocode_get: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| Get your key at graphhopper.com | 
 **q** | **String**| If you do forward geocoding, then this would be a textual description of the address you are looking for | [optional] 
 **locale** | **String**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | [optional] 
 **limit** | **Integer**| Specify the maximum number of returned results | [optional] 
 **reverse** | **BOOLEAN**| Set to true to do a reverse Geocoding request, see point parameter | [optional] 
 **point** | **String**| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | [optional] 
 **provider** | **String**| Can be either, default, nominatim, opencagedata | [optional] 

### Return type

[**GeocodingResponse**](GeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json



