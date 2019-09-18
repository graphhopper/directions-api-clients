# MapMatchingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**postGPX**](MapMatchingApi.md#postGPX) | **POST** /match | Map-match a GPX file

<a name="postGPX"></a>
# **postGPX**
> RouteResponse postGPX()

Map-match a GPX file

### Example You get an example response for a GPX via:  &#x60;&#x60;&#x60; curl -XPOST -H \&quot;Content-Type: application/gpx+xml\&quot; \&quot;https://graphhopper.com/api/1/match?vehicle&#x3D;car&amp;key&#x3D;[YOUR_KEY]\&quot; --data @/path/to/some.gpx &#x60;&#x60;&#x60;  ### Introduction ![Map Matching screenshot](./img/map-matching-example.gif)  The Map Matching is part of the GraphHopper Directions API and with this API you can snap measured GPS points typically as GPX files to a digital road network to e.g. clean data or attach certain data like elevation or turn instructions to it. Read more at Wikipedia.  In the example screenshot above and demo you see the Map Matching in action where the black line is the GPS track and the green one is matched result.  Most of the times, you can simply POST a GPX file, but some of the request parameters of the [Routing](#tag/Routing-API) apply here, too.  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#map-matching).  ### Limits and Counts The cost for one request depends on the number of GPS location and is documented [here](https://graphhopper.com/api/1/docs/FAQ/).  One request should not exceed the Map Matching location limit depending on the package, see the pricing in our dashboard. 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiClient;
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.Configuration;
//import com.graphhopper.directions.api.client.auth.*;
//import com.graphhopper.directions.api.client.api.MapMatchingApi;

ApiClient defaultClient = Configuration.getDefaultApiClient();

// Configure API key authorization: api_key
ApiKeyAuth api_key = (ApiKeyAuth) defaultClient.getAuthentication("api_key");
api_key.setApiKey("YOUR API KEY");
// Uncomment the following line to set a prefix for the API key, e.g. "Token" (defaults to null)
//api_key.setApiKeyPrefix("Token");

MapMatchingApi apiInstance = new MapMatchingApi();
try {
    RouteResponse result = apiInstance.postGPX();
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling MapMatchingApi#postGPX");
    e.printStackTrace();
}
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**RouteResponse**](RouteResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

