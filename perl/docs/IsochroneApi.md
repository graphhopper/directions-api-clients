# WWW::SwaggerClient::IsochroneApi

## Load the API package
```perl
use WWW::SwaggerClient::Object::IsochroneApi;
```

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**isochrone_get**](IsochroneApi.md#isochrone_get) | **GET** /isochrone | Isochrone Request


# **isochrone_get**
> GHIsochroneResponse isochrone_get(point => $point, key => $key, time_limit => $time_limit, vehicle => $vehicle, buckets => $buckets, reverse_flow => $reverse_flow)

Isochrone Request

The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 

### Example 
```perl
use Data::Dumper;
use WWW::SwaggerClient::Configuration;
use WWW::SwaggerClient::IsochroneApi;

my $api_instance = WWW::SwaggerClient::IsochroneApi->new();
my $point = 'point_example'; # string | Specify the start coordinate
my $key = 'key_example'; # string | Get your key at graphhopper.com
my $time_limit = 56; # int | Specify which time the vehicle should travel. In seconds. The maximum depends on the subscribed package.
my $vehicle = 'vehicle_example'; # string | Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/)
my $buckets = 56; # int | For how many sub intervals an additional polygon should be calculated.
my $reverse_flow = 1; # boolean | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*

eval { 
    my $result = $api_instance->isochrone_get(point => $point, key => $key, time_limit => $time_limit, vehicle => $vehicle, buckets => $buckets, reverse_flow => $reverse_flow);
    print Dumper($result);
};
if ($@) {
    warn "Exception when calling IsochroneApi->isochrone_get: $@\n";
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **string**| Specify the start coordinate | 
 **key** | **string**| Get your key at graphhopper.com | 
 **time_limit** | **int**| Specify which time the vehicle should travel. In seconds. The maximum depends on the subscribed package. | [optional] [default to 600]
 **vehicle** | **string**| Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) | [optional] [default to car]
 **buckets** | **int**| For how many sub intervals an additional polygon should be calculated. | [optional] [default to 1]
 **reverse_flow** | **boolean**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example usage for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.* | [optional] [default to false]

### Return type

[**GHIsochroneResponse**](GHIsochroneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

