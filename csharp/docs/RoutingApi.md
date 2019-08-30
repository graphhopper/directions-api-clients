# IO.Swagger.Api.RoutingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GetRoute**](RoutingApi.md#getroute) | **GET** /route | Execute a routing request
[**RouteInfoGet**](RoutingApi.md#routeinfoget) | **GET** /route/info | Coverage information

<a name="getroute"></a>
# **GetRoute**
> RouteResponse GetRoute (List<string> point, List<string> pointHint = null, List<string> snapPrevention = null, VehicleProfileId vehicle = null, string locale = null, bool? elevation = null, List<string> details = null, bool? optimize = null, bool? instructions = null, bool? calcPoints = null, bool? debug = null, bool? pointsEncoded = null, string type = null, bool? chDisable = null, string weighting = null, List<int?> heading = null, int? headingPenalty = null, bool? passThrough = null, string blockArea = null, string avoid = null, string algorithm = null, int? roundTripDistance = null, long? roundTripSeed = null, int? alternativeRouteMaxPaths = null, decimal? alternativeRouteMaxWeightFactor = null, decimal? alternativeRouteMaxShareFactor = null)

Execute a routing request

### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of ''best'' depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via `ch.disable=true`. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class GetRouteExample
    {
        public void main()
        {
            // Configure API key authorization: api_key
            Configuration.Default.AddApiKey("key", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("key", "Bearer");

            var apiInstance = new RoutingApi();
            var point = new List<string>(); // List<string> | The points for which the route should be calculated. Format: `[latitude,longitude]`. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. 
            var pointHint = new List<string>(); // List<string> | The point_hint is typically a road name to which the associated `point` parameter should be snapped to. Specify no `point_hint` parameter or the same number as you have `point` parameters.  (optional) 
            var snapPrevention = new List<string>(); // List<string> | Optional parameter to avoid snapping to a certain road class or road environment. Current supported values `motorway`, `trunk`, `ferry`, `tunnel`, `bridge` and `ford`. Multiple values are specified like `snap_prevention=ferry&snap_prevention=motorway`  (optional) 
            var vehicle = new VehicleProfileId(); // VehicleProfileId | The vehicle profile for which the route should be calculated.  (optional) 
            var locale = locale_example;  // string | The locale of the resulting turn instructions. E.g. `pt_PT` for Portuguese or `de` for German.  (optional) 
            var elevation = true;  // bool? | If `true`, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the `points` and `snapped_waypoints` fields of the response, in both their encodings. Unless you switch off the `points_encoded` parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional) 
            var details = new List<string>(); // List<string> | Optional parameter to retrieve path details. You can request additional details for the route: `street_name` and `time`. For all motor vehicle profiles, we additionally support `max_speed`, `toll`, `road_class`, `road_environment`, and `surface`.  (optional) 
            var optimize = true;  // bool? | Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to `true` and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional) 
            var instructions = true;  // bool? | If instructions should be calculated and returned  (optional) 
            var calcPoints = true;  // bool? | If the points for the route should be calculated at all.  (optional) 
            var debug = true;  // bool? | If `true`, the output will be formatted.  (optional) 
            var pointsEncoded = true;  // bool? | If `false`, the coordinates in `point` and `snapped_waypoints` are returned as lists of positions using the order `[lon,lat,elevation]`. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If `true`, the coordinates will be encoded as a string. You'll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional) 
            var type = type_example;  // string | Specifies the media type for the response. For `json`, it will be `application/json`. For `gpx`, it will be `application/gpx+xml`.  (optional) 
            var chDisable = true;  // bool? | Use this parameter in combination with one or more parameters from below.  (optional) 
            var weighting = weighting_example;  // string | Determines the way the ''best'' route is calculated. Default is `fastest`. Other options are `shortest` (e.g. for `vehicle=foot` or `bike`) and `short_fastest` which finds a reasonable balance between `shortest` and `fastest`. Requires `ch.disable=true`.  (optional) 
            var heading = new List<int?>(); // List<int?> | Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with `algorithm=round_trip` and forces the initial direction.  Requires `ch.disable=true`.  (optional) 
            var headingPenalty = 56;  // int? | Time penalty in seconds for not obeying a specified heading. Requires `ch.disable=true`.  (optional) 
            var passThrough = true;  // bool? | If `true`, u-turns are avoided at via-points with regard to the `heading_penalty`. Requires `ch.disable=true`.  (optional) 
            var blockArea = blockArea_example;  // string | Block road access via a point with the format `latitude,longitude` or an area defined by a circle `lat,lon,radius` or a rectangle `lat1,lon1,lat2,lon2`. Separate several values with `;`. Requires `ch.disable=true`.  (optional) 
            var avoid = avoid_example;  // string | Specify which road classes and environments you would like to avoid.  Possible values are `motorway`, `primary`, `secondary`, `tertiary`, `trunk`, `residential`, `steps`, `living_street`, `track`, `toll`, `ferry`, `tunnel`, `bridge` and `ford`. Separate several values with `;`. Obviously not all the values make sense for all vehicle profiles e.g. `bike` is already forbidden on a `motorway`. Requires `ch.disable=true`.  (optional) 
            var algorithm = algorithm_example;  // string | Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With `round_trip`, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With `alternative_route`, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires `ch.disable=true`.  (optional) 
            var roundTripDistance = 56;  // int? | If `algorithm=round_trip`, this parameter configures approximative length of the resulting round trip. Requires `ch.disable=true`.  (optional) 
            var roundTripSeed = 789;  // long? | If `algorithm=round_trip`, this sets the random seed. Change this to get a different tour for each value.  (optional) 
            var alternativeRouteMaxPaths = 56;  // int? | If `algorithm=alternative_route`, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional) 
            var alternativeRouteMaxWeightFactor = 1.2;  // decimal? | If `algorithm=alternative_route`, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional) 
            var alternativeRouteMaxShareFactor = 1.2;  // decimal? | If `algorithm=alternative_route`, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional) 

            try
            {
                // Execute a routing request
                RouteResponse result = apiInstance.GetRoute(point, pointHint, snapPrevention, vehicle, locale, elevation, details, optimize, instructions, calcPoints, debug, pointsEncoded, type, chDisable, weighting, heading, headingPenalty, passThrough, blockArea, avoid, algorithm, roundTripDistance, roundTripSeed, alternativeRouteMaxPaths, alternativeRouteMaxWeightFactor, alternativeRouteMaxShareFactor);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling RoutingApi.GetRoute: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | [**List&lt;string&gt;**](string.md)| The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan.  | 
 **pointHint** | [**List&lt;string&gt;**](string.md)| The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  | [optional] 
 **snapPrevention** | [**List&lt;string&gt;**](string.md)| Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  | [optional] 
 **vehicle** | [**VehicleProfileId**](VehicleProfileId.md)| The vehicle profile for which the route should be calculated.  | [optional] 
 **locale** | **string**| The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  | [optional] 
 **elevation** | **bool?**| If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  | [optional] 
 **details** | [**List&lt;string&gt;**](string.md)| Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  | [optional] 
 **optimize** | **bool?**| Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  | [optional] 
 **instructions** | **bool?**| If instructions should be calculated and returned  | [optional] 
 **calcPoints** | **bool?**| If the points for the route should be calculated at all.  | [optional] 
 **debug** | **bool?**| If &#x60;true&#x60;, the output will be formatted.  | [optional] 
 **pointsEncoded** | **bool?**| If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  | [optional] 
 **type** | **string**| Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  | [optional] 
 **chDisable** | **bool?**| Use this parameter in combination with one or more parameters from below.  | [optional] 
 **weighting** | **string**| Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  | [optional] 
 **heading** | [**List&lt;int?&gt;**](int?.md)| Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  | [optional] 
 **headingPenalty** | **int?**| Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  | [optional] 
 **passThrough** | **bool?**| If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  | [optional] 
 **blockArea** | **string**| Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  | [optional] 
 **avoid** | **string**| Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  | [optional] 
 **algorithm** | **string**| Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  | [optional] 
 **roundTripDistance** | **int?**| If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  | [optional] 
 **roundTripSeed** | **long?**| If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  | [optional] 
 **alternativeRouteMaxPaths** | **int?**| If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  | [optional] 
 **alternativeRouteMaxWeightFactor** | **decimal?**| If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  | [optional] 
 **alternativeRouteMaxShareFactor** | **decimal?**| If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  | [optional] 

### Return type

[**RouteResponse**](RouteResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)
<a name="routeinfoget"></a>
# **RouteInfoGet**
> InfoResponse RouteInfoGet ()

Coverage information

Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class RouteInfoGetExample
    {
        public void main()
        {
            // Configure API key authorization: api_key
            Configuration.Default.AddApiKey("key", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("key", "Bearer");

            var apiInstance = new RoutingApi();

            try
            {
                // Coverage information
                InfoResponse result = apiInstance.RouteInfoGet();
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling RoutingApi.RouteInfoGet: " + e.Message );
            }
        }
    }
}
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**InfoResponse**](InfoResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)
