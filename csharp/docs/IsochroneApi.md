# IO.Swagger.Api.IsochroneApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**IsochroneGet**](IsochroneApi.md#isochroneget) | **GET** /isochrone | Isochrone Request


<a name="isochroneget"></a>
# **IsochroneGet**
> IsochroneResponse IsochroneGet (string point, string key, int? timeLimit = null, int? distanceLimit = null, string vehicle = null, int? buckets = null, bool? reverseFlow = null)

Isochrone Request

The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class IsochroneGetExample
    {
        public void main()
        {
            var apiInstance = new IsochroneApi();
            var point = point_example;  // string | Specify the start coordinate
            var key = key_example;  // string | Get your key at graphhopper.com
            var timeLimit = 56;  // int? | Specify which time the vehicle should travel. In seconds. (optional)  (default to 600)
            var distanceLimit = 56;  // int? | Specify which distance the vehicle should travel. In meter. (optional)  (default to -1)
            var vehicle = vehicle_example;  // string | Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) (optional)  (default to car)
            var buckets = 56;  // int? | For how many sub intervals an additional polygon should be calculated. (optional)  (default to 1)
            var reverseFlow = true;  // bool? | If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.* (optional)  (default to false)

            try
            {
                // Isochrone Request
                IsochroneResponse result = apiInstance.IsochroneGet(point, key, timeLimit, distanceLimit, vehicle, buckets, reverseFlow);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling IsochroneApi.IsochroneGet: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | **string**| Specify the start coordinate | 
 **key** | **string**| Get your key at graphhopper.com | 
 **timeLimit** | **int?**| Specify which time the vehicle should travel. In seconds. | [optional] [default to 600]
 **distanceLimit** | **int?**| Specify which distance the vehicle should travel. In meter. | [optional] [default to -1]
 **vehicle** | **string**| Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) | [optional] [default to car]
 **buckets** | **int?**| For how many sub intervals an additional polygon should be calculated. | [optional] [default to 1]
 **reverseFlow** | **bool?**| If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example usage for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.* | [optional] [default to false]

### Return type

[**IsochroneResponse**](IsochroneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

