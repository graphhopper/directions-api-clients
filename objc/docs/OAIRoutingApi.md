# OAIRoutingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**routeGet**](OAIRoutingApi.md#routeget) | **GET** /route | Routing Request


# **routeGet**
```objc
-(NSURLSessionTask*) routeGetWithPoint: (NSArray<NSString*>*) point
    pointsEncoded: (NSNumber*) pointsEncoded
    key: (NSString*) key
    locale: (NSString*) locale
    instructions: (NSNumber*) instructions
    vehicle: (NSString*) vehicle
    elevation: (NSNumber*) elevation
    calcPoints: (NSNumber*) calcPoints
    pointHint: (NSArray<NSString*>*) pointHint
    chDisable: (NSNumber*) chDisable
    weighting: (NSString*) weighting
    edgeTraversal: (NSNumber*) edgeTraversal
    algorithm: (NSString*) algorithm
    heading: (NSNumber*) heading
    headingPenalty: (NSNumber*) headingPenalty
    passThrough: (NSNumber*) passThrough
    details: (NSArray<NSString*>*) details
    roundTripDistance: (NSNumber*) roundTripDistance
    roundTripSeed: (NSNumber*) roundTripSeed
    alternativeRouteMaxPaths: (NSNumber*) alternativeRouteMaxPaths
    alternativeRouteMaxWeightFactor: (NSNumber*) alternativeRouteMaxWeightFactor
    alternativeRouteMaxShareFactor: (NSNumber*) alternativeRouteMaxShareFactor
    avoid: (NSString*) avoid
        completionHandler: (void (^)(OAIRouteResponse* output, NSError* error)) handler;
```

Routing Request

The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions

### Example 
```objc

NSArray<NSString*>* point = @[@"point_example"]; // Specify multiple points for which the route should be calculated. The order is important. Specify at least two points.
NSNumber* pointsEncoded = @56; // IMPORTANT- TODO - currently you have to pass false for the swagger client - Have not found a way to force add a parameter. If `false` the coordinates in `point` and `snapped_waypoints` are returned as array using the order [lon,lat,elevation] for every point. If `true` the coordinates will be encoded as string leading to less bandwith usage. You'll need a special handling for the decoding of this string on the client-side. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/java/com/graphhopper/http/WebHelper.java#L43) and [JavaScript](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/webapp/js/ghrequest.js#L139). It is especially important to use no 3rd party client if you set `elevation=true`!
NSString* key = @"key_example"; // Get your key at graphhopper.com
NSString* locale = @"locale_example"; // The locale of the resulting turn instructions. E.g. `pt_PT` for Portuguese or `de` for German (optional)
NSNumber* instructions = @56; // If instruction should be calculated and returned (optional)
NSString* vehicle = @"vehicle_example"; // The vehicle for which the route should be calculated. Other vehicles are foot, small_truck, ... (optional)
NSNumber* elevation = @56; // If `true` a third dimension - the elevation - is included in the polyline or in the GeoJson. If enabled you have to use a modified version of the decoding method or set points_encoded to `false`. See the points_encoded attribute for more details. Additionally a request can fail if the vehicle does not support elevation. See the features object for every vehicle. (optional)
NSNumber* calcPoints = @56; // If the points for the route should be calculated at all printing out only distance and time. (optional)
NSArray<NSString*>* pointHint = @[@"pointHint_example"]; // Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. (optional)
NSNumber* chDisable = @56; // Use this parameter in combination with one or more parameters of this table (optional)
NSString* weighting = @"weighting_example"; // Which kind of 'best' route calculation you need. Other option is `shortest` (e.g. for `vehicle=foot` or `bike`), `short_fastest` if time and distance is expensive e.g. for `vehicle=truck` (optional)
NSNumber* edgeTraversal = @56; // Use `true` if you want to consider turn restrictions for bike and motor vehicles. Keep in mind that the response time is roughly 2 times slower. (optional)
NSString* algorithm = @"algorithm_example"; // The algorithm to calculate the route. Other options are `dijkstra`, `astar`, `astarbi`, `alternative_route` and `round_trip` (optional)
NSNumber* heading = @56; // Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with `algorithm=round_trip` and force the initial direction. (optional)
NSNumber* headingPenalty = @56; // Penalty for omitting a specified heading. The penalty corresponds to the accepted time delay in seconds in comparison to the route without a heading. (optional)
NSNumber* passThrough = @56; // If `true` u-turns are avoided at via-points with regard to the `heading_penalty`. (optional)
NSArray<NSString*>* details = @[@"details_example"]; // List of additional trip attributes to be returned. Try some of the following: `average_speed`, `street_name`, `edge_id`, `time`, `distance`. (optional)
NSNumber* roundTripDistance = @56; // If `algorithm=round_trip` this parameter configures approximative length of the resulting round trip (optional)
NSNumber* roundTripSeed = @56; // If `algorithm=round_trip` this parameter introduces randomness if e.g. the first try wasn't good. (optional)
NSNumber* alternativeRouteMaxPaths = @56; // If `algorithm=alternative_route` this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. (optional)
NSNumber* alternativeRouteMaxWeightFactor = @56; // If `algorithm=alternative_route` this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. (optional)
NSNumber* alternativeRouteMaxShareFactor = @56; // If `algorithm=alternative_route` this parameter specifies how much alternatives routes can have maximum in common with the optimal route. Increasing can lead to worse alternatives. (optional)
NSString* avoid = @"avoid_example"; // comma separate list to avoid certain roads. You can avoid motorway, ferry, tunnel or track (optional)

OAIRoutingApi*apiInstance = [[OAIRoutingApi alloc] init];

// Routing Request
[apiInstance routeGetWithPoint:point
              pointsEncoded:pointsEncoded
              key:key
              locale:locale
              instructions:instructions
              vehicle:vehicle
              elevation:elevation
              calcPoints:calcPoints
              pointHint:pointHint
              chDisable:chDisable
              weighting:weighting
              edgeTraversal:edgeTraversal
              algorithm:algorithm
              heading:heading
              headingPenalty:headingPenalty
              passThrough:passThrough
              details:details
              roundTripDistance:roundTripDistance
              roundTripSeed:roundTripSeed
              alternativeRouteMaxPaths:alternativeRouteMaxPaths
              alternativeRouteMaxWeightFactor:alternativeRouteMaxWeightFactor
              alternativeRouteMaxShareFactor:alternativeRouteMaxShareFactor
              avoid:avoid
          completionHandler: ^(OAIRouteResponse* output, NSError* error) {
                        if (output) {
                            NSLog(@"%@", output);
                        }
                        if (error) {
                            NSLog(@"Error calling OAIRoutingApi->routeGet: %@", error);
                        }
                    }];
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| Specify multiple points for which the route should be calculated. The order is important. Specify at least two points. | 
 **pointsEncoded** | **NSNumber***| IMPORTANT- TODO - currently you have to pass false for the swagger client - Have not found a way to force add a parameter. If &#x60;false&#x60; the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as array using the order [lon,lat,elevation] for every point. If &#x60;true&#x60; the coordinates will be encoded as string leading to less bandwith usage. You&#39;ll need a special handling for the decoding of this string on the client-side. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/java/com/graphhopper/http/WebHelper.java#L43) and [JavaScript](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/webapp/js/ghrequest.js#L139). It is especially important to use no 3rd party client if you set &#x60;elevation&#x3D;true&#x60;! | 
 **key** | **NSString***| Get your key at graphhopper.com | 
 **locale** | **NSString***| The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German | [optional] 
 **instructions** | **NSNumber***| If instruction should be calculated and returned | [optional] 
 **vehicle** | **NSString***| The vehicle for which the route should be calculated. Other vehicles are foot, small_truck, ... | [optional] 
 **elevation** | **NSNumber***| If &#x60;true&#x60; a third dimension - the elevation - is included in the polyline or in the GeoJson. If enabled you have to use a modified version of the decoding method or set points_encoded to &#x60;false&#x60;. See the points_encoded attribute for more details. Additionally a request can fail if the vehicle does not support elevation. See the features object for every vehicle. | [optional] 
 **calcPoints** | **NSNumber***| If the points for the route should be calculated at all printing out only distance and time. | [optional] 
 **pointHint** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| Optional parameter. Specifies a hint for each &#x60;point&#x60; parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. | [optional] 
 **chDisable** | **NSNumber***| Use this parameter in combination with one or more parameters of this table | [optional] 
 **weighting** | **NSString***| Which kind of &#39;best&#39; route calculation you need. Other option is &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;), &#x60;short_fastest&#x60; if time and distance is expensive e.g. for &#x60;vehicle&#x3D;truck&#x60; | [optional] 
 **edgeTraversal** | **NSNumber***| Use &#x60;true&#x60; if you want to consider turn restrictions for bike and motor vehicles. Keep in mind that the response time is roughly 2 times slower. | [optional] 
 **algorithm** | **NSString***| The algorithm to calculate the route. Other options are &#x60;dijkstra&#x60;, &#x60;astar&#x60;, &#x60;astarbi&#x60;, &#x60;alternative_route&#x60; and &#x60;round_trip&#x60; | [optional] 
 **heading** | **NSNumber***| Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and force the initial direction. | [optional] 
 **headingPenalty** | **NSNumber***| Penalty for omitting a specified heading. The penalty corresponds to the accepted time delay in seconds in comparison to the route without a heading. | [optional] 
 **passThrough** | **NSNumber***| If &#x60;true&#x60; u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. | [optional] 
 **details** | [**NSArray&lt;NSString*&gt;***](NSString*.md)| List of additional trip attributes to be returned. Try some of the following: &#x60;average_speed&#x60;, &#x60;street_name&#x60;, &#x60;edge_id&#x60;, &#x60;time&#x60;, &#x60;distance&#x60;. | [optional] 
 **roundTripDistance** | **NSNumber***| If &#x60;algorithm&#x3D;round_trip&#x60; this parameter configures approximative length of the resulting round trip | [optional] 
 **roundTripSeed** | **NSNumber***| If &#x60;algorithm&#x3D;round_trip&#x60; this parameter introduces randomness if e.g. the first try wasn&#39;t good. | [optional] 
 **alternativeRouteMaxPaths** | **NSNumber***| If &#x60;algorithm&#x3D;alternative_route&#x60; this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. | [optional] 
 **alternativeRouteMaxWeightFactor** | **NSNumber***| If &#x60;algorithm&#x3D;alternative_route&#x60; this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. | [optional] 
 **alternativeRouteMaxShareFactor** | **NSNumber***| If &#x60;algorithm&#x3D;alternative_route&#x60; this parameter specifies how much alternatives routes can have maximum in common with the optimal route. Increasing can lead to worse alternatives. | [optional] 
 **avoid** | **NSString***| comma separate list to avoid certain roads. You can avoid motorway, ferry, tunnel or track | [optional] 

### Return type

[**OAIRouteResponse***](OAIRouteResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

