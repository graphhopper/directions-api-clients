# SWGGeocodingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**geocodeGet**](SWGGeocodingApi.md#geocodeget) | **GET** /geocode | Execute a Geocoding request


# **geocodeGet**
```objc
-(NSURLSessionTask*) geocodeGetWithKey: (NSString*) key
    q: (NSString*) q
    locale: (NSString*) locale
    limit: (NSNumber*) limit
    reverse: (NSNumber*) reverse
    point: (NSString*) point
    provider: (NSString*) provider
        completionHandler: (void (^)(SWGGeocodingResponse* output, NSError* error)) handler;
```

Execute a Geocoding request

This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 

### Example 
```objc

NSString* key = @"key_example"; // Get your key at graphhopper.com
NSString* q = @"q_example"; // If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon. (optional)
NSString* locale = @"locale_example"; // Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used. (optional)
NSNumber* limit = @56; // Specify the maximum number of returned results (optional)
NSNumber* reverse = @true; // Set to true to do a reverse Geocoding request (optional)
NSString* point = @"point_example"; // The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803 (optional)
NSString* provider = @"provider_example"; // Can be either, default, nominatim, opencagedata (optional)

SWGGeocodingApi*apiInstance = [[SWGGeocodingApi alloc] init];

// Execute a Geocoding request
[apiInstance geocodeGetWithKey:key
              q:q
              locale:locale
              limit:limit
              reverse:reverse
              point:point
              provider:provider
          completionHandler: ^(SWGGeocodingResponse* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling SWGGeocodingApi->geocodeGet: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **NSString***| Get your key at graphhopper.com | 
 **q** | **NSString***| If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon. | [optional] 
 **locale** | **NSString***| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used. | [optional] 
 **limit** | **NSNumber***| Specify the maximum number of returned results | [optional] 
 **reverse** | **NSNumber***| Set to true to do a reverse Geocoding request | [optional] 
 **point** | **NSString***| The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803 | [optional] 
 **provider** | **NSString***| Can be either, default, nominatim, opencagedata | [optional] 

### Return type

[**SWGGeocodingResponse***](SWGGeocodingResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

