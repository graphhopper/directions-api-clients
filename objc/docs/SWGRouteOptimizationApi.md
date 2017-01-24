# SWGRouteOptimizationApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getSolution**](SWGRouteOptimizationApi.md#getsolution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId
[**postVrp**](SWGRouteOptimizationApi.md#postvrp) | **POST** /vrp/optimize | Solves vehicle routing problems


# **getSolution**
```objc
-(NSNumber*) getSolutionWithKey: (NSString*) key
    jobId: (NSString*) jobId
        completionHandler: (void (^)(SWGResponse* output, NSError* error)) handler;
```

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Example 
```objc

NSString* key = @"key_example"; // your API key
NSString* jobId = @"jobId_example"; // Request solution with jobId

SWGRouteOptimizationApi*apiInstance = [[SWGRouteOptimizationApi alloc] init];

// Return the solution associated to the jobId
[apiInstance getSolutionWithKey:key
              jobId:jobId
          completionHandler: ^(SWGResponse* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling SWGRouteOptimizationApi->getSolution: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **NSString***| your API key | 
 **jobId** | **NSString***| Request solution with jobId | 

### Return type

[**SWGResponse***](SWGResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **postVrp**
```objc
-(NSNumber*) postVrpWithKey: (NSString*) key
    body: (SWGRequest*) body
        completionHandler: (void (^)(SWGJobId* output, NSError* error)) handler;
```

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution. 

### Example 
```objc

NSString* key = @"key_example"; // your API key
SWGRequest* body = [[SWGRequest alloc] init]; // Request object that contains the problem to be solved

SWGRouteOptimizationApi*apiInstance = [[SWGRouteOptimizationApi alloc] init];

// Solves vehicle routing problems
[apiInstance postVrpWithKey:key
              body:body
          completionHandler: ^(SWGJobId* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling SWGRouteOptimizationApi->postVrp: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **NSString***| your API key | 
 **body** | [**SWGRequest***](SWGRequest*.md)| Request object that contains the problem to be solved | 

### Return type

[**SWGJobId***](SWGJobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

