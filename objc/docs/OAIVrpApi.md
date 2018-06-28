# OAIVrpApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**postVrp**](OAIVrpApi.md#postvrp) | **POST** /vrp/optimize | Solves vehicle routing problems


# **postVrp**
```objc
-(NSURLSessionTask*) postVrpWithKey: (NSString*) key
    request: (OAIRequest*) request
        completionHandler: (void (^)(OAIJobId* output, NSError* error)) handler;
```

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.

### Example 
```objc

NSString* key = @"key_example"; // your API key
OAIRequest* request = [[OAIRequest alloc] init]; // Request object that contains the problem to be solved

OAIVrpApi*apiInstance = [[OAIVrpApi alloc] init];

// Solves vehicle routing problems
[apiInstance postVrpWithKey:key
              request:request
          completionHandler: ^(OAIJobId* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling OAIVrpApi->postVrp: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **NSString***| your API key | 
 **request** | [**OAIRequest***](OAIRequest.md)| Request object that contains the problem to be solved | 

### Return type

[**OAIJobId***](OAIJobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

