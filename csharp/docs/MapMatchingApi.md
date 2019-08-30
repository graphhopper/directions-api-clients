# IO.Swagger.Api.MapMatchingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PostGPX**](MapMatchingApi.md#postgpx) | **POST** /match | Map-match a GPX file

<a name="postgpx"></a>
# **PostGPX**
> RouteResponse PostGPX ()

Map-match a GPX file

### Example You get an example response for a GPX via:  ``` curl -XPOST -H \"Content-Type: application/gpx+xml\" \"https://graphhopper.com/api/1/match?vehicle=car&key=[YOUR_KEY]\" - -data @/path/to/some.gpx ```  ### Introduction ![Map Matching screenshot](./img/map-matching-example.gif)  The Map Matching is part of the GraphHopper Directions API and with this API you can snap measured GPS points typically as GPX files to a digital road network to e.g. clean data or attach certain data like elevation or turn instructions to it. Read more at Wikipedia.  In the example screenshot above and demo you see the Map Matching in action where the black line is the GPS track and the green one is matched result.  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#map-matching).  ### Limits and Counts The cost for one request depends on the number of GPS location and is documented [here](https://graphhopper.com/api/1/docs/FAQ/).  One request should not exceed the Map Matching location limit depending on the package, see the pricing in our dashboard. 

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class PostGPXExample
    {
        public void main()
        {
            // Configure API key authorization: api_key
            Configuration.Default.AddApiKey("key", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("key", "Bearer");

            var apiInstance = new MapMatchingApi();

            try
            {
                // Map-match a GPX file
                RouteResponse result = apiInstance.PostGPX();
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling MapMatchingApi.PostGPX: " + e.Message );
            }
        }
    }
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

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)
