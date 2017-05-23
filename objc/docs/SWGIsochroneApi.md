# SWGIsochroneApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**isochroneGet**](SWGIsochroneApi.md#isochroneget) | **GET** /isochrone | Isochrone Request


# **isochroneGet**
```objc
-(NSURLSessionTask*) isochroneGetWithPoint: (NSString*) point
    key: (NSString*) key
    timeLimit: (NSNumber*) timeLimit
    distanceLimit: (NSNumber*) distanceLimit
    vehicle: (NSString*) vehicle
    buckets: (NSNumber*) buckets
    reverseFlow: (NSNumber*) reverseFlow
        completionHandler: (void (^)(SWGIsochroneResponse* output, NSError* error)) handler;
```

Isochrone Request

The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 

### Example 
```objc

NSString* point = @"point_example"; // Specify the start coordinate
NSString* key = @"key_example"; // Get your key at graphhopper.com
NSNumber* timeLimit = @600; // Specify which time the vehicle should travel. In seconds. (optional) (default to 600)
NSNumber* distanceLimit = @-1; // Specify which distance the vehicle should travel. In meter. (optional) (default to -1)
NSString* vehicle = @"car"; // Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) (optional) (default to car)
NSNumber* buckets = @1; // For how many sub intervals an additional polygon should be calculated. (optional) (default to 1)
NSNumber* reverseFlow = @false; // If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.* (optional) (default to false)

SWGIsochroneApi*apiInstance = [[SWGIsochroneApi alloc] init];

// Isochrone Request
[apiInstance isochroneGetWithPoint:point
              key:key
              timeLimit:timeLimit
              distanceLimit:distanceLimit
              vehicle:vehicle
              buckets:buckets
              reverseFlow:reverseFlow
          completionHandler: ^(SWGIsochroneResponse* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling SWGIsochroneApi->isochroneGet: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **NSString***| Specify the start coordinate | 
 **key** | **NSString***| Get your key at graphhopper.com | 
 **timeLimit** | **NSNumber***| Specify which time the vehicle should travel. In seconds. | [optional] [default to 600]
 **distanceLimit** | **NSNumber***| Specify which distance the vehicle should travel. In meter. | [optional] [default to -1]
 **vehicle** | **NSString***| Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) | [optional] [default to car]
 **buckets** | **NSNumber***| For how many sub intervals an additional polygon should be calculated. | [optional] [default to 1]
 **reverseFlow** | **NSNumber***| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example usage for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.* | [optional] [default to false]

### Return type

[**SWGIsochroneResponse***](SWGIsochroneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

