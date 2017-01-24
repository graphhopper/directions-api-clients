# WWW::SwaggerClient::RouteOptimizationApi

## Load the API package
```perl
use WWW::SwaggerClient::Object::RouteOptimizationApi;
```

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**get_solution**](RouteOptimizationApi.md#get_solution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId
[**post_vrp**](RouteOptimizationApi.md#post_vrp) | **POST** /vrp/optimize | Solves vehicle routing problems


# **get_solution**
> Response get_solution(key => $key, job_id => $job_id)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Example 
```perl
use Data::Dumper;
use WWW::SwaggerClient::Configuration;
use WWW::SwaggerClient::RouteOptimizationApi;

my $api_instance = WWW::SwaggerClient::RouteOptimizationApi->new();
my $key = 'key_example'; # string | your API key
my $job_id = 'job_id_example'; # string | Request solution with jobId

eval { 
    my $result = $api_instance->get_solution(key => $key, job_id => $job_id);
    print Dumper($result);
};
if ($@) {
    warn "Exception when calling RouteOptimizationApi->get_solution: $@\n";
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| your API key | 
 **job_id** | **string**| Request solution with jobId | 

### Return type

[**Response**](Response.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **post_vrp**
> JobId post_vrp(key => $key, body => $body)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution. 

### Example 
```perl
use Data::Dumper;
use WWW::SwaggerClient::Configuration;
use WWW::SwaggerClient::RouteOptimizationApi;

my $api_instance = WWW::SwaggerClient::RouteOptimizationApi->new();
my $key = 'key_example'; # string | your API key
my $body = WWW::SwaggerClient::Object::Request->new(); # Request | Request object that contains the problem to be solved

eval { 
    my $result = $api_instance->post_vrp(key => $key, body => $body);
    print Dumper($result);
};
if ($@) {
    warn "Exception when calling RouteOptimizationApi->post_vrp: $@\n";
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| your API key | 
 **body** | [**Request**](Request.md)| Request object that contains the problem to be solved | 

### Return type

[**JobId**](JobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

