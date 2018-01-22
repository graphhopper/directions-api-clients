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
```kotlin
// Import classes:
//import io.swagger.client.infrastructure.*
//import io.swagger.client.models.*

val apiInstance = IsochroneApi()
val point : kotlin.String = point_example // kotlin.String | Specify the start coordinate
val key : kotlin.String = key_example // kotlin.String | Get your key at graphhopper.com
val timeLimit : kotlin.Int = 56 // kotlin.Int | Specify which time the vehicle should travel. In seconds.
val distanceLimit : kotlin.Int = 56 // kotlin.Int | Specify which distance the vehicle should travel. In meter.
val vehicle : kotlin.String = vehicle_example // kotlin.String | Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/)
val buckets : kotlin.Int = 56 // kotlin.Int | For how many sub intervals an additional polygon should be calculated.
val reverseFlow : kotlin.Boolean = true // kotlin.Boolean | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*
try {
    val result : IsochroneResponse = apiInstance.isochroneGet(point, key, timeLimit, distanceLimit, vehicle, buckets, reverseFlow)
    println(result)
} catch (e: ClientException) {
    println("4xx response calling IsochroneApi#isochroneGet")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling IsochroneApi#isochroneGet")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **kotlin.String**| Specify the start coordinate |
 **key** | **kotlin.String**| Get your key at graphhopper.com |
 **timeLimit** | **kotlin.Int**| Specify which time the vehicle should travel. In seconds. | [optional] [default to 600]
 **distanceLimit** | **kotlin.Int**| Specify which distance the vehicle should travel. In meter. | [optional] [default to -1]
 **vehicle** | **kotlin.String**| Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) | [optional] [default to car]
 **buckets** | **kotlin.Int**| For how many sub intervals an additional polygon should be calculated. | [optional] [default to 1]
 **reverseFlow** | **kotlin.Boolean**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example usage for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.* | [optional] [default to false]

### Return type

[**IsochroneResponse**](IsochroneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

