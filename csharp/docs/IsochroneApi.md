# IO.Swagger.Api.IsochroneApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GetIsochrone**](IsochroneApi.md#getisochrone) | **GET** /isochrone | Isochrone Request

<a name="getisochrone"></a>
# **GetIsochrone**
> IsochroneResponse GetIsochrone (string point, int? timeLimit = null, int? distanceLimit = null, VehicleProfileId vehicle = null, int? buckets = null, bool? reverseFlow = null, string weighting = null)

Isochrone Request

### Example You can get an example response via:  ``` curl \"https://graphhopper.com/api/1/isochrone?point=51.131108,12.414551&key=[YOUR_KEY]\" ```  Don't forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is ''a line connecting points at which a vehicle arrives at the same time'', see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit`.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class GetIsochroneExample
    {
        public void main()
        {
            // Configure API key authorization: api_key
            Configuration.Default.AddApiKey("key", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("key", "Bearer");

            var apiInstance = new IsochroneApi();
            var point = point_example;  // string | Specify the start coordinate
            var timeLimit = 56;  // int? | Specify which time the vehicle should travel. In seconds. (optional) 
            var distanceLimit = 56;  // int? | Specify which distance the vehicle should travel. In meters. (optional) 
            var vehicle = new VehicleProfileId(); // VehicleProfileId | The vehicle profile for which the route should be calculated.  (optional) 
            var buckets = 56;  // int? | For how many subintervals an additional polygon should be calculated. (optional) 
            var reverseFlow = true;  // bool? | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example use case for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*  (optional) 
            var weighting = weighting_example;  // string | Use `\"shortest\"` to get an isodistance line instead of an isochrone. (optional) 

            try
            {
                // Isochrone Request
                IsochroneResponse result = apiInstance.GetIsochrone(point, timeLimit, distanceLimit, vehicle, buckets, reverseFlow, weighting);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling IsochroneApi.GetIsochrone: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **string**| Specify the start coordinate | 
 **timeLimit** | **int?**| Specify which time the vehicle should travel. In seconds. | [optional] 
 **distanceLimit** | **int?**| Specify which distance the vehicle should travel. In meters. | [optional] 
 **vehicle** | [**VehicleProfileId**](VehicleProfileId.md)| The vehicle profile for which the route should be calculated.  | [optional] 
 **buckets** | **int?**| For how many subintervals an additional polygon should be calculated. | [optional] 
 **reverseFlow** | **bool?**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  | [optional] 
 **weighting** | **string**| Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. | [optional] 

### Return type

[**IsochroneResponse**](IsochroneResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)
