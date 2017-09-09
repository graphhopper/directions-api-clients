# IsochroneApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**isochroneGet**](IsochroneApi.md#isochroneGet) | **GET** /isochrone | Isochrone Request


<a name="isochroneGet"></a>
# **isochroneGet**
> IsochroneResponse isochroneGet(point, key, timeLimit, distanceLimit, vehicle, buckets, reverseFlow)

Isochrone Request

The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate &#39;a line connecting points at which a vehicle arrives at the same time,&#39; see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.api.IsochroneApi;


IsochroneApi apiInstance = new IsochroneApi();
String point = "point_example"; // String | Specify the start coordinate
String key = "key_example"; // String | Get your key at graphhopper.com
Integer timeLimit = 600; // Integer | Specify which time the vehicle should travel. In seconds.
Integer distanceLimit = -1; // Integer | Specify which distance the vehicle should travel. In meter.
String vehicle = "car"; // String | Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/)
Integer buckets = 1; // Integer | For how many sub intervals an additional polygon should be calculated.
Boolean reverseFlow = false; // Boolean | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*
try {
    IsochroneResponse result = apiInstance.isochroneGet(point, key, timeLimit, distanceLimit, vehicle, buckets, reverseFlow);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling IsochroneApi#isochroneGet");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **String**| Specify the start coordinate |
 **key** | **String**| Get your key at graphhopper.com |
 **timeLimit** | **Integer**| Specify which time the vehicle should travel. In seconds. | [optional] [default to 600]
 **distanceLimit** | **Integer**| Specify which distance the vehicle should travel. In meter. | [optional] [default to -1]
 **vehicle** | **String**| Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) | [optional] [default to car]
 **buckets** | **Integer**| For how many sub intervals an additional polygon should be calculated. | [optional] [default to 1]
 **reverseFlow** | **Boolean**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example usage for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.* | [optional] [default to false]

### Return type

[**IsochroneResponse**](IsochroneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

