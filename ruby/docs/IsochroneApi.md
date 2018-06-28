# GraphHopperClient::IsochroneApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**isochrone_get**](IsochroneApi.md#isochrone_get) | **GET** /isochrone | Isochrone Request


# **isochrone_get**
> IsochroneResponse isochrone_get(point, key, opts)

Isochrone Request

The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 

### Example
```ruby
# load the gem
require 'directions-api-client'

api_instance = GraphHopperClient::IsochroneApi.new

point = "point_example" # String | Specify the start coordinate

key = "key_example" # String | Get your key at graphhopper.com

opts = { 
  time_limit: 600, # Integer | Specify which time the vehicle should travel. In seconds.
  distance_limit: -1, # Integer | Specify which distance the vehicle should travel. In meter.
  vehicle: "car", # String | Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/)
  buckets: 1, # Integer | For how many sub intervals an additional polygon should be calculated.
  reverse_flow: false, # BOOLEAN | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*
  weighting: "fastest" # String | Can be fastest or shortest
}

begin
  #Isochrone Request
  result = api_instance.isochrone_get(point, key, opts)
  p result
rescue GraphHopperClient::ApiError => e
  puts "Exception when calling IsochroneApi->isochrone_get: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **String**| Specify the start coordinate | 
 **key** | **String**| Get your key at graphhopper.com | 
 **time_limit** | **Integer**| Specify which time the vehicle should travel. In seconds. | [optional] [default to 600]
 **distance_limit** | **Integer**| Specify which distance the vehicle should travel. In meter. | [optional] [default to -1]
 **vehicle** | **String**| Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) | [optional] [default to car]
 **buckets** | **Integer**| For how many sub intervals an additional polygon should be calculated. | [optional] [default to 1]
 **reverse_flow** | **BOOLEAN**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example usage for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.* | [optional] [default to false]
 **weighting** | **String**| Can be fastest or shortest | [optional] [default to fastest]

### Return type

[**IsochroneResponse**](IsochroneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json



