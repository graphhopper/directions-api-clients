# openapi.api.IsochroneApi

## Load the API package
```dart
import 'package:openapi/api.dart';
```

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**isochroneGet**](IsochroneApi.md#isochroneGet) | **GET** /isochrone | Isochrone Request


# **isochroneGet**
> IsochroneResponse isochroneGet(point, key, timeLimit, distanceLimit, vehicle, buckets, reverseFlow, weighting)

Isochrone Request

The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 

### Example 
```dart
import 'package:openapi/api.dart';

var api_instance = new IsochroneApi();
var point = point_example; // String | Specify the start coordinate
var key = key_example; // String | Get your key at graphhopper.com
var timeLimit = 56; // int | Specify which time the vehicle should travel. In seconds.
var distanceLimit = 56; // int | Specify which distance the vehicle should travel. In meter.
var vehicle = vehicle_example; // String | Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/)
var buckets = 56; // int | For how many sub intervals an additional polygon should be calculated.
var reverseFlow = true; // bool | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*
var weighting = weighting_example; // String | Can be fastest or shortest

try { 
    var result = api_instance.isochroneGet(point, key, timeLimit, distanceLimit, vehicle, buckets, reverseFlow, weighting);
    print(result);
} catch (e) {
    print("Exception when calling IsochroneApi->isochroneGet: $e\n");
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **String**| Specify the start coordinate | 
 **key** | **String**| Get your key at graphhopper.com | 
 **timeLimit** | **int**| Specify which time the vehicle should travel. In seconds. | [optional] [default to 600]
 **distanceLimit** | **int**| Specify which distance the vehicle should travel. In meter. | [optional] [default to -1]
 **vehicle** | **String**| Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) | [optional] [default to car]
 **buckets** | **int**| For how many sub intervals an additional polygon should be calculated. | [optional] [default to 1]
 **reverseFlow** | **bool**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example usage for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.* | [optional] [default to false]
 **weighting** | **String**| Can be fastest or shortest | [optional] [default to fastest]

### Return type

[**IsochroneResponse**](IsochroneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

