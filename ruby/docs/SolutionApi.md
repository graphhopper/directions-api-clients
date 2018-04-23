# GraphHopperClient::SolutionApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**get_solution**](SolutionApi.md#get_solution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId


# **get_solution**
> Response get_solution(key, job_id)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 

### Example
```ruby
# load the gem
require 'directions-api-client'

api_instance = GraphHopperClient::SolutionApi.new

key = "key_example" # String | your API key

job_id = "job_id_example" # String | Request solution with jobId


begin
  #Return the solution associated to the jobId
  result = api_instance.get_solution(key, job_id)
  p result
rescue GraphHopperClient::ApiError => e
  puts "Exception when calling SolutionApi->get_solution: #{e}"
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



