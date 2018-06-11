# GraphHopperClient::VrpApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**post_vrp**](VrpApi.md#post_vrp) | **POST** /vrp/optimize | Solves vehicle routing problems


# **post_vrp**
> JobId post_vrp(key, body)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.

### Example
```ruby
# load the gem
require 'directions-api-client'

api_instance = GraphHopperClient::VrpApi.new

key = "key_example" # String | your API key

body = GraphHopperClient::Request.new # Request | Request object that contains the problem to be solved


begin
  #Solves vehicle routing problems
  result = api_instance.post_vrp(key, body)
  p result
rescue GraphHopperClient::ApiError => e
  puts "Exception when calling VrpApi->post_vrp: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| your API key | 
 **body** | [**Request**](Request.md)| Request object that contains the problem to be solved | 

### Return type

[**JobId**](JobId.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json



