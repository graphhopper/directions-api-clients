# IsochroneApiApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getIsochrone**](IsochroneApiApi.md#getIsochrone) | **GET** /isochrone | Isochrone Request

<a name="getIsochrone"></a>
# **getIsochrone**
> IsochroneResponse getIsochrone(point, timeLimit, distanceLimit, vehicle, buckets, reverseFlow, weighting)

Isochrone Request

### Example You can get an example response via:  &#x60;&#x60;&#x60; curl \&quot;https://graphhopper.com/api/1/isochrone?point&#x3D;51.131108,12.414551&amp;key&#x3D;[YOUR_KEY]\&quot; &#x60;&#x60;&#x60;  Don&#x27;t forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is &#x27;&#x27;a line connecting points at which a vehicle arrives at the same time&#x27;&#x27;, see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit&#x60;.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiClient;
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.Configuration;
//import com.graphhopper.directions.api.client.auth.*;
//import com.graphhopper.directions.api.client.tmp.IsochroneApiApi;

ApiClient defaultClient = Configuration.getDefaultApiClient();

// Configure API key authorization: api_key
ApiKeyAuth api_key = (ApiKeyAuth) defaultClient.getAuthentication("api_key");
api_key.setApiKey("YOUR API KEY");
// Uncomment the following line to set a prefix for the API key, e.g. "Token" (defaults to null)
//api_key.setApiKeyPrefix("Token");

IsochroneApiApi apiInstance = new IsochroneApiApi();
String point = "point_example"; // String | Specify the start coordinate
Integer timeLimit = 56; // Integer | Specify which time the vehicle should travel. In seconds.
Integer distanceLimit = 56; // Integer | Specify which distance the vehicle should travel. In meters.
VehicleProfileId vehicle = new VehicleProfileId(); // VehicleProfileId | The vehicle profile for which the route should be calculated. 
Integer buckets = 56; // Integer | For how many subintervals an additional polygon should be calculated.
Boolean reverseFlow = true; // Boolean | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example use case for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.* 
String weighting = "weighting_example"; // String | Use `\"shortest\"` to get an isodistance line instead of an isochrone.
try {
    IsochroneResponse result = apiInstance.getIsochrone(point, timeLimit, distanceLimit, vehicle, buckets, reverseFlow, weighting);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling IsochroneApiApi#getIsochrone");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **String**| Specify the start coordinate |
 **timeLimit** | **Integer**| Specify which time the vehicle should travel. In seconds. | [optional]
 **distanceLimit** | **Integer**| Specify which distance the vehicle should travel. In meters. | [optional]
 **vehicle** | [**VehicleProfileId**](.md)| The vehicle profile for which the route should be calculated.  | [optional]
 **buckets** | **Integer**| For how many subintervals an additional polygon should be calculated. | [optional]
 **reverseFlow** | **Boolean**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  | [optional]
 **weighting** | **String**| Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. | [optional] [enum: fastest, shortest]

### Return type

[**IsochroneResponse**](IsochroneResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

