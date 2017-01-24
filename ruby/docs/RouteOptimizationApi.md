# SwaggerClient::RouteOptimizationApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**get_solution**](RouteOptimizationApi.md#get_solution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId
[**post_vrp**](RouteOptimizationApi.md#post_vrp) | **POST** /vrp/optimize | Solves vehicle routing problems


# **get_solution**
> Response get_solution(key, job_id)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::RouteOptimizationApi.new

key = "key_example" # String | your API key

job_id = "job_id_example" # String | Request solution with jobId


begin
  #Return the solution associated to the jobId
  result = api_instance.get_solution(key, job_id)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling RouteOptimizationApi->get_solution: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **String**| your API key | 
 **job_id** | **String**| Request solution with jobId | 

### Return type

[**Response**](Response.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json



# **post_vrp**
> JobId post_vrp(key, body)

Solves vehicle routing problems

This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution. 

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::RouteOptimizationApi.new

key = "key_example" # String | your API key

body = SwaggerClient::Request.new # Request | Request object that contains the problem to be solved


begin
  #Solves vehicle routing problems
  result = api_instance.post_vrp(key, body)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling RouteOptimizationApi->post_vrp: #{e}"
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



