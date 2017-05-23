# swagger_client.IsochroneApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**isochrone_get**](IsochroneApi.md#isochrone_get) | **GET** /isochrone | Isochrone Request


# **isochrone_get**
> IsochroneResponse isochrone_get(point, key, time_limit=time_limit, distance_limit=distance_limit, vehicle=vehicle, buckets=buckets, reverse_flow=reverse_flow)

Isochrone Request

The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 

### Example 
```python
from __future__ import print_statement
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.IsochroneApi()
point = 'point_example' # str | Specify the start coordinate
key = 'key_example' # str | Get your key at graphhopper.com
time_limit = 600 # int | Specify which time the vehicle should travel. In seconds. (optional) (default to 600)
distance_limit = -1 # int | Specify which distance the vehicle should travel. In meter. (optional) (default to -1)
vehicle = 'car' # str | Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) (optional) (default to car)
buckets = 1 # int | For how many sub intervals an additional polygon should be calculated. (optional) (default to 1)
reverse_flow = false # bool | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.* (optional) (default to false)

try: 
    # Isochrone Request
    api_response = api_instance.isochrone_get(point, key, time_limit=time_limit, distance_limit=distance_limit, vehicle=vehicle, buckets=buckets, reverse_flow=reverse_flow)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling IsochroneApi->isochrone_get: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **str**| Specify the start coordinate | 
 **key** | **str**| Get your key at graphhopper.com | 
 **time_limit** | **int**| Specify which time the vehicle should travel. In seconds. | [optional] [default to 600]
 **distance_limit** | **int**| Specify which distance the vehicle should travel. In meter. | [optional] [default to -1]
 **vehicle** | **str**| Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) | [optional] [default to car]
 **buckets** | **int**| For how many sub intervals an additional polygon should be calculated. | [optional] [default to 1]
 **reverse_flow** | **bool**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example usage for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.* | [optional] [default to false]

### Return type

[**IsochroneResponse**](IsochroneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

