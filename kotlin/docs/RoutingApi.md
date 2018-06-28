# RoutingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**routeGet**](RoutingApi.md#routeGet) | **GET** /route | Routing Request


<a name="routeGet"></a>
# **routeGet**
> RouteResponse routeGet(point, pointsEncoded, key, locale, instructions, vehicle, elevation, calcPoints, pointHint, ch.disable, weighting, edgeTraversal, algorithm, heading, headingPenalty, passThrough, details, roundTrip.distance, roundTrip.seed, alternativeRoute.maxPaths, alternativeRoute.maxWeightFactor, alternativeRoute.maxShareFactor, avoid)

Routing Request

The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions

### Example
```kotlin
// Import classes:
//import org.openapitools.client.infrastructure.*
//import org.openapitools.client.models.*

val apiInstance = RoutingApi()
val point : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | Specify multiple points for which the route should be calculated. The order is important. Specify at least two points.
val pointsEncoded : kotlin.Boolean = true // kotlin.Boolean | IMPORTANT- TODO - currently you have to pass false for the swagger client - Have not found a way to force add a parameter. If `false` the coordinates in `point` and `snapped_waypoints` are returned as array using the order [lon,lat,elevation] for every point. If `true` the coordinates will be encoded as string leading to less bandwith usage. You'll need a special handling for the decoding of this string on the client-side. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/java/com/graphhopper/http/WebHelper.java#L43) and [JavaScript](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/webapp/js/ghrequest.js#L139). It is especially important to use no 3rd party client if you set `elevation=true`!
val key : kotlin.String = key_example // kotlin.String | Get your key at graphhopper.com
val locale : kotlin.String = locale_example // kotlin.String | The locale of the resulting turn instructions. E.g. `pt_PT` for Portuguese or `de` for German
val instructions : kotlin.Boolean = true // kotlin.Boolean | If instruction should be calculated and returned
val vehicle : kotlin.String = vehicle_example // kotlin.String | The vehicle for which the route should be calculated. Other vehicles are foot, small_truck, ...
val elevation : kotlin.Boolean = true // kotlin.Boolean | If `true` a third dimension - the elevation - is included in the polyline or in the GeoJson. If enabled you have to use a modified version of the decoding method or set points_encoded to `false`. See the points_encoded attribute for more details. Additionally a request can fail if the vehicle does not support elevation. See the features object for every vehicle.
val calcPoints : kotlin.Boolean = true // kotlin.Boolean | If the points for the route should be calculated at all printing out only distance and time.
val pointHint : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up.
val ch.disable : kotlin.Boolean = true // kotlin.Boolean | Use this parameter in combination with one or more parameters of this table
val weighting : kotlin.String = weighting_example // kotlin.String | Which kind of 'best' route calculation you need. Other option is `shortest` (e.g. for `vehicle=foot` or `bike`), `short_fastest` if time and distance is expensive e.g. for `vehicle=truck`
val edgeTraversal : kotlin.Boolean = true // kotlin.Boolean | Use `true` if you want to consider turn restrictions for bike and motor vehicles. Keep in mind that the response time is roughly 2 times slower.
val algorithm : kotlin.String = algorithm_example // kotlin.String | The algorithm to calculate the route. Other options are `dijkstra`, `astar`, `astarbi`, `alternative_route` and `round_trip`
val heading : kotlin.Int = 56 // kotlin.Int | Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with `algorithm=round_trip` and force the initial direction.
val headingPenalty : kotlin.Int = 56 // kotlin.Int | Penalty for omitting a specified heading. The penalty corresponds to the accepted time delay in seconds in comparison to the route without a heading.
val passThrough : kotlin.Boolean = true // kotlin.Boolean | If `true` u-turns are avoided at via-points with regard to the `heading_penalty`.
val details : kotlin.Array<kotlin.String> =  // kotlin.Array<kotlin.String> | List of additional trip attributes to be returned. Try some of the following: `average_speed`, `street_name`, `edge_id`, `time`, `distance`.
val roundTrip.distance : kotlin.Int = 56 // kotlin.Int | If `algorithm=round_trip` this parameter configures approximative length of the resulting round trip
val roundTrip.seed : kotlin.Long = 789 // kotlin.Long | If `algorithm=round_trip` this parameter introduces randomness if e.g. the first try wasn't good.
val alternativeRoute.maxPaths : kotlin.Int = 56 // kotlin.Int | If `algorithm=alternative_route` this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.
val alternativeRoute.maxWeightFactor : kotlin.Int = 56 // kotlin.Int | If `algorithm=alternative_route` this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.
val alternativeRoute.maxShareFactor : kotlin.Int = 56 // kotlin.Int | If `algorithm=alternative_route` this parameter specifies how much alternatives routes can have maximum in common with the optimal route. Increasing can lead to worse alternatives.
val avoid : kotlin.String = avoid_example // kotlin.String | comma separate list to avoid certain roads. You can avoid motorway, ferry, tunnel or track
try {
    val result : RouteResponse = apiInstance.routeGet(point, pointsEncoded, key, locale, instructions, vehicle, elevation, calcPoints, pointHint, ch.disable, weighting, edgeTraversal, algorithm, heading, headingPenalty, passThrough, details, roundTrip.distance, roundTrip.seed, alternativeRoute.maxPaths, alternativeRoute.maxWeightFactor, alternativeRoute.maxShareFactor, avoid)
    println(result)
} catch (e: ClientException) {
    println("4xx response calling RoutingApi#routeGet")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling RoutingApi#routeGet")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| Specify multiple points for which the route should be calculated. The order is important. Specify at least two points. |
 **pointsEncoded** | **kotlin.Boolean**| IMPORTANT- TODO - currently you have to pass false for the swagger client - Have not found a way to force add a parameter. If &#x60;false&#x60; the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as array using the order [lon,lat,elevation] for every point. If &#x60;true&#x60; the coordinates will be encoded as string leading to less bandwith usage. You&#39;ll need a special handling for the decoding of this string on the client-side. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/java/com/graphhopper/http/WebHelper.java#L43) and [JavaScript](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/webapp/js/ghrequest.js#L139). It is especially important to use no 3rd party client if you set &#x60;elevation&#x3D;true&#x60;! |
 **key** | **kotlin.String**| Get your key at graphhopper.com |
 **locale** | **kotlin.String**| The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German | [optional]
 **instructions** | **kotlin.Boolean**| If instruction should be calculated and returned | [optional]
 **vehicle** | **kotlin.String**| The vehicle for which the route should be calculated. Other vehicles are foot, small_truck, ... | [optional]
 **elevation** | **kotlin.Boolean**| If &#x60;true&#x60; a third dimension - the elevation - is included in the polyline or in the GeoJson. If enabled you have to use a modified version of the decoding method or set points_encoded to &#x60;false&#x60;. See the points_encoded attribute for more details. Additionally a request can fail if the vehicle does not support elevation. See the features object for every vehicle. | [optional]
 **calcPoints** | **kotlin.Boolean**| If the points for the route should be calculated at all printing out only distance and time. | [optional]
 **pointHint** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| Optional parameter. Specifies a hint for each &#x60;point&#x60; parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. | [optional]
 **ch.disable** | **kotlin.Boolean**| Use this parameter in combination with one or more parameters of this table | [optional]
 **weighting** | **kotlin.String**| Which kind of &#39;best&#39; route calculation you need. Other option is &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;), &#x60;short_fastest&#x60; if time and distance is expensive e.g. for &#x60;vehicle&#x3D;truck&#x60; | [optional]
 **edgeTraversal** | **kotlin.Boolean**| Use &#x60;true&#x60; if you want to consider turn restrictions for bike and motor vehicles. Keep in mind that the response time is roughly 2 times slower. | [optional]
 **algorithm** | **kotlin.String**| The algorithm to calculate the route. Other options are &#x60;dijkstra&#x60;, &#x60;astar&#x60;, &#x60;astarbi&#x60;, &#x60;alternative_route&#x60; and &#x60;round_trip&#x60; | [optional]
 **heading** | **kotlin.Int**| Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and force the initial direction. | [optional]
 **headingPenalty** | **kotlin.Int**| Penalty for omitting a specified heading. The penalty corresponds to the accepted time delay in seconds in comparison to the route without a heading. | [optional]
 **passThrough** | **kotlin.Boolean**| If &#x60;true&#x60; u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. | [optional]
 **details** | [**kotlin.Array&lt;kotlin.String&gt;**](kotlin.String.md)| List of additional trip attributes to be returned. Try some of the following: &#x60;average_speed&#x60;, &#x60;street_name&#x60;, &#x60;edge_id&#x60;, &#x60;time&#x60;, &#x60;distance&#x60;. | [optional]
 **roundTrip.distance** | **kotlin.Int**| If &#x60;algorithm&#x3D;round_trip&#x60; this parameter configures approximative length of the resulting round trip | [optional]
 **roundTrip.seed** | **kotlin.Long**| If &#x60;algorithm&#x3D;round_trip&#x60; this parameter introduces randomness if e.g. the first try wasn&#39;t good. | [optional]
 **alternativeRoute.maxPaths** | **kotlin.Int**| If &#x60;algorithm&#x3D;alternative_route&#x60; this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. | [optional]
 **alternativeRoute.maxWeightFactor** | **kotlin.Int**| If &#x60;algorithm&#x3D;alternative_route&#x60; this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. | [optional]
 **alternativeRoute.maxShareFactor** | **kotlin.Int**| If &#x60;algorithm&#x3D;alternative_route&#x60; this parameter specifies how much alternatives routes can have maximum in common with the optimal route. Increasing can lead to worse alternatives. | [optional]
 **avoid** | **kotlin.String**| comma separate list to avoid certain roads. You can avoid motorway, ferry, tunnel or track | [optional]

### Return type

[**RouteResponse**](RouteResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

