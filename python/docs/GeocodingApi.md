# swagger_client.GeocodingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**geocode_get**](GeocodingApi.md#geocode_get) | **GET** /geocode | Execute a Geocoding request


# **geocode_get**
> GeocodingResponse geocode_get(key, q=q, locale=locale, limit=limit, reverse=reverse, point=point, provider=provider)

Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 

### Example 
```python
from __future__ import print_statement
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.GeocodingApi()
key = 'key_example' # str | Get your key at graphhopper.com
q = 'q_example' # str | If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon. (optional)
locale = 'locale_example' # str | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used. (optional)
limit = 56 # int | Specify the maximum number of returned results (optional)
reverse = true # bool | Set to true to do a reverse Geocoding request (optional)
point = 'point_example' # str | The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803 (optional)
provider = 'provider_example' # str | Can be either, default, nominatim, opencagedata (optional)

try: 
    # Execute a Geocoding request
    api_response = api_instance.geocode_get(key, q=q, locale=locale, limit=limit, reverse=reverse, point=point, provider=provider)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling GeocodingApi->geocode_get: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **str**| Get your key at graphhopper.com | 
 **q** | **str**| If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon. | [optional] 
 **locale** | **str**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | [optional] 
 **limit** | **int**| Specify the maximum number of returned results | [optional] 
 **reverse** | **bool**| Set to true to do a reverse Geocoding request | [optional] 
 **point** | **str**| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | [optional] 
 **provider** | **str**| Can be either, default, nominatim, opencagedata | [optional] 

### Return type

[**GeocodingResponse**](GeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

