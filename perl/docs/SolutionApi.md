# WWW::OpenAPIClient::SolutionApi

## Load the API package
```perl
use WWW::OpenAPIClient::Object::SolutionApi;
```

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**get_solution**](SolutionApi.md#get_solution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId


# **get_solution**
> Response get_solution(key => $key, job_id => $job_id)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Example 
```perl
use Data::Dumper;
use WWW::OpenAPIClient::SolutionApi;
my $api_instance = WWW::OpenAPIClient::SolutionApi->new(
);

my $key = "key_example"; # string | your API key
my $job_id = "job_id_example"; # string | Request solution with jobId

eval { 
    my $result = $api_instance->get_solution(key => $key, job_id => $job_id);
    print Dumper($result);
};
if ($@) {
    warn "Exception when calling SolutionApi->get_solution: $@\n";
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

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

