# SWGVrpApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**postVrp**](SWGVrpApi.md#postvrp) | **POST** /vrp/optimize | Solves vehicle routing problems


# **postVrp**
```objc
-(NSURLSessionTask*) postVrpWithKey: (NSString*) key
    body: (SWGRequest*) body
        completionHandler: (void (^)(SWGJobId* output, NSError* error)) handler;
```

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.

### Example 
```objc

NSString* key = @"key_example"; // your API key
SWGRequest* body = [[SWGRequest alloc] init]; // Request object that contains the problem to be solved

SWGVrpApi*apiInstance = [[SWGVrpApi alloc] init];

// Solves vehicle routing problems
[apiInstance postVrpWithKey:key
              body:body
          completionHandler: ^(SWGJobId* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling SWGVrpApi->postVrp: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **NSString***| your API key | 
 **body** | [**SWGRequest***](SWGRequest.md)| Request object that contains the problem to be solved | 

### Return type

[**SWGJobId***](SWGJobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

