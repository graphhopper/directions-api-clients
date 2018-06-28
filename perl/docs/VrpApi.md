# WWW::OpenAPIClient::VrpApi

## Load the API package
```perl
use WWW::OpenAPIClient::Object::VrpApi;
```

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**post_vrp**](VrpApi.md#post_vrp) | **POST** /vrp/optimize | Solves vehicle routing problems


# **post_vrp**
> JobId post_vrp(key => $key, request => $request)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.

### Example 
```perl
use Data::Dumper;
use WWW::OpenAPIClient::VrpApi;
my $api_instance = WWW::OpenAPIClient::VrpApi->new(
);

my $key = "key_example"; # string | your API key
my $request = WWW::OpenAPIClient::Object::Request->new(); # Request | Request object that contains the problem to be solved

eval { 
    my $result = $api_instance->post_vrp(key => $key, request => $request);
    print Dumper($result);
};
if ($@) {
    warn "Exception when calling VrpApi->post_vrp: $@\n";
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| your API key | 
 **request** | [**Request**](Request.md)| Request object that contains the problem to be solved | 

### Return type

[**JobId**](JobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

