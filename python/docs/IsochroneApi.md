# swagger_client.IsochroneApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**get_isochrone**](IsochroneApi.md#get_isochrone) | **GET** /isochrone | Isochrone Request

# **get_isochrone**
> IsochroneResponse get_isochrone(point, time_limit=time_limit, distance_limit=distance_limit, vehicle=vehicle, buckets=buckets, reverse_flow=reverse_flow, weighting=weighting)

Isochrone Request

### Example You can get an example response via:  ``` curl \"https://graphhopper.com/api/1/isochrone?point=51.131108,12.414551&key=[YOUR_KEY]\" ```  Don't forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is ''a line connecting points at which a vehicle arrives at the same time'', see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit`.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: api_key
configuration = swagger_client.Configuration()
configuration.api_key['key'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['key'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.IsochroneApi(swagger_client.ApiClient(configuration))
point = 'point_example' # str | Specify the start coordinate
time_limit = 56 # int | Specify which time the vehicle should travel. In seconds. (optional)
distance_limit = 56 # int | Specify which distance the vehicle should travel. In meters. (optional)
vehicle = swagger_client.VehicleProfileId() # VehicleProfileId | The vehicle profile for which the route should be calculated.  (optional)
buckets = 56 # int | For how many subintervals an additional polygon should be calculated. (optional)
reverse_flow = true # bool | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example use case for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*  (optional)
weighting = 'weighting_example' # str | Use `\"shortest\"` to get an isodistance line instead of an isochrone. (optional)

try:
    # Isochrone Request
    api_response = api_instance.get_isochrone(point, time_limit=time_limit, distance_limit=distance_limit, vehicle=vehicle, buckets=buckets, reverse_flow=reverse_flow, weighting=weighting)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling IsochroneApi->get_isochrone: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **str**| Specify the start coordinate | 
 **time_limit** | **int**| Specify which time the vehicle should travel. In seconds. | [optional] 
 **distance_limit** | **int**| Specify which distance the vehicle should travel. In meters. | [optional] 
 **vehicle** | [**VehicleProfileId**](.md)| The vehicle profile for which the route should be calculated.  | [optional] 
 **buckets** | **int**| For how many subintervals an additional polygon should be calculated. | [optional] 
 **reverse_flow** | **bool**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  | [optional] 
 **weighting** | **str**| Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. | [optional] 

### Return type

[**IsochroneResponse**](IsochroneResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

