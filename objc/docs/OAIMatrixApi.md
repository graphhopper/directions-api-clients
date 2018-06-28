# OAIMatrixApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**matrixGet**](OAIMatrixApi.md#matrixget) | **GET** /matrix | Matrix API
[**matrixPost**](OAIMatrixApi.md#matrixpost) | **POST** /matrix | Matrix API Post


# **matrixGet**
```objc
-(NSURLSessionTask*) matrixGetWithKey: (NSString*) key
    point: (NSArray<NSString*>*) point
    fromPoint: (NSArray<NSString*>*) fromPoint
    toPoint: (NSArray<NSString*>*) toPoint
    pointHint: (NSArray<NSString*>*) pointHint
    fromPointHint: (NSArray<NSString*>*) fromPointHint
    toPointHint: (NSArray<NSString*>*) toPointHint
    outArray: (NSArray<NSString*>*) outArray
    vehicle: (NSString*) vehicle
        completionHandler: (void (^)(OAIMatrixResponse* output, NSError* error)) handler;
```

Matrix API

The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called 'via points', which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this. 

### Example 
```objc

NSString* key = @"key_example"; // Get your key at graphhopper.com
NSArray<NSString*>* point = @[@"point_example"]; // Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude. (optional)
NSArray<NSString*>* fromPoint = @[@"fromPoint_example"]; // The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude. (optional)
NSArray<NSString*>* toPoint = @[@"toPoint_example"]; // The destination points for the routes. Is a string with the format latitude,longitude. (optional)
NSArray<NSString*>* pointHint = @[@"pointHint_example"]; // Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. (optional)
NSArray<NSString*>* fromPointHint = @[@"fromPointHint_example"]; // For the from_point parameter. See point_hint (optional)
NSArray<NSString*>* toPointHint = @[@"toPointHint_example"]; // For the to_point parameter. See point_hint (optional)
NSArray<NSString*>* outArray = @[@"outArray_example"]; // Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. (optional)
NSString* vehicle = @"car"; // The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc (optional) (default to @"car")

OAIMatrixApi*apiInstance = [[OAIMatrixApi alloc] init];

// Matrix API
[apiInstance matrixGetWithKey:key
              point:point
              fromPoint:fromPoint
              toPoint:toPoint
              pointHint:pointHint
              fromPointHint:fromPointHint
              toPointHint:toPointHint
              outArray:outArray
              vehicle:vehicle
          completionHandler: ^(OAIMatrixResponse* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling OAIMatrixApi->matrixGet: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **NSString***| Get your key at graphhopper.com | 
 **point** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude. | [optional] 
 **fromPoint** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| The starting points for the routes. E.g. if you want to calculate the three routes A-&amp;gt;1, A-&amp;gt;2, A-&amp;gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude. | [optional] 
 **toPoint** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| The destination points for the routes. Is a string with the format latitude,longitude. | [optional] 
 **pointHint** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| Optional parameter. Specifies a hint for each &#x60;point&#x60; parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. | [optional] 
 **fromPointHint** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| For the from_point parameter. See point_hint | [optional] 
 **toPointHint** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| For the to_point parameter. See point_hint | [optional] 
 **outArray** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| Specifies which arrays should be included in the response. Specify one or more of the following options &#39;weights&#39;, &#39;times&#39;, &#39;distances&#39;. To specify more than one array use e.g. out_array&#x3D;times&amp;out_array&#x3D;distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. | [optional] 
 **vehicle** | **NSString***| The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc | [optional] [default to @&quot;car&quot;]

### Return type

[**OAIMatrixResponse***](OAIMatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **matrixPost**
```objc
-(NSURLSessionTask*) matrixPostWithKey: (NSString*) key
    matrixRequest: (OAIMatrixRequest*) matrixRequest
        completionHandler: (void (^)(OAIMatrixResponse* output, NSError* error)) handler;
```

Matrix API Post

The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request. 

### Example 
```objc

NSString* key = @"key_example"; // Get your key at graphhopper.com
OAIMatrixRequest* matrixRequest = [[OAIMatrixRequest alloc] init]; //  (optional)

OAIMatrixApi*apiInstance = [[OAIMatrixApi alloc] init];

// Matrix API Post
[apiInstance matrixPostWithKey:key
              matrixRequest:matrixRequest
          completionHandler: ^(OAIMatrixResponse* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling OAIMatrixApi->matrixPost: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **NSString***| Get your key at graphhopper.com | 
 **matrixRequest** | [**OAIMatrixRequest***](OAIMatrixRequest.md)|  | [optional] 

### Return type

[**OAIMatrixResponse***](OAIMatrixResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

