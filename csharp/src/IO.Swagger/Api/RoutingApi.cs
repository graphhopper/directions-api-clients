/* 
 * GraphHopper Directions API
 *
 *  With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Clients  To speed up development and make coding easier, we offer the following clients:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon - -- -- -- -- --|:- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions for motor vehicles such as `car` or `truck` are only considered with `edge_based=true` for the Routing (other APIs will follow).** Or if you already use `ch.disable=true` no additional parameter is required to consider turn restrictions for motor vehicles.  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon - -- -- -- -- --|:- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) 
 *
 * OpenAPI spec version: 1.0.0
 * Contact: support@graphhopper.com
 * Generated by: https://github.com/swagger-api/swagger-codegen.git
 */
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using RestSharp;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace IO.Swagger.Api
{
    /// <summary>
    /// Represents a collection of functions to interact with the API endpoints
    /// </summary>
        public interface IRoutingApi : IApiAccessor
    {
        #region Synchronous Operations
        /// <summary>
        /// Execute a routing request
        /// </summary>
        /// <remarks>
        /// ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#x27;&#x27;best&#x27;&#x27; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. </param>
        /// <param name="pointHint">The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)</param>
        /// <param name="snapPrevention">Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="locale">The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)</param>
        /// <param name="elevation">If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)</param>
        /// <param name="details">Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)</param>
        /// <param name="optimize">Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)</param>
        /// <param name="instructions">If instructions should be calculated and returned  (optional)</param>
        /// <param name="calcPoints">If the points for the route should be calculated at all.  (optional)</param>
        /// <param name="debug">If &#x60;true&#x60;, the output will be formatted.  (optional)</param>
        /// <param name="pointsEncoded">If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)</param>
        /// <param name="type">Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)</param>
        /// <param name="chDisable">Use this parameter in combination with one or more parameters from below.  (optional)</param>
        /// <param name="weighting">Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="heading">Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="headingPenalty">Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="passThrough">If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="blockArea">Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="avoid">Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="algorithm">Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripDistance">If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripSeed">If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)</param>
        /// <param name="alternativeRouteMaxPaths">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxWeightFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxShareFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <returns>RouteResponse</returns>
        RouteResponse GetRoute (List<string> point, List<string> pointHint = null, List<string> snapPrevention = null, VehicleProfileId vehicle = null, string locale = null, bool? elevation = null, List<string> details = null, bool? optimize = null, bool? instructions = null, bool? calcPoints = null, bool? debug = null, bool? pointsEncoded = null, string type = null, bool? chDisable = null, string weighting = null, List<int?> heading = null, int? headingPenalty = null, bool? passThrough = null, string blockArea = null, string avoid = null, string algorithm = null, int? roundTripDistance = null, long? roundTripSeed = null, int? alternativeRouteMaxPaths = null, decimal? alternativeRouteMaxWeightFactor = null, decimal? alternativeRouteMaxShareFactor = null);

        /// <summary>
        /// Execute a routing request
        /// </summary>
        /// <remarks>
        /// ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#x27;&#x27;best&#x27;&#x27; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. </param>
        /// <param name="pointHint">The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)</param>
        /// <param name="snapPrevention">Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="locale">The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)</param>
        /// <param name="elevation">If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)</param>
        /// <param name="details">Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)</param>
        /// <param name="optimize">Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)</param>
        /// <param name="instructions">If instructions should be calculated and returned  (optional)</param>
        /// <param name="calcPoints">If the points for the route should be calculated at all.  (optional)</param>
        /// <param name="debug">If &#x60;true&#x60;, the output will be formatted.  (optional)</param>
        /// <param name="pointsEncoded">If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)</param>
        /// <param name="type">Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)</param>
        /// <param name="chDisable">Use this parameter in combination with one or more parameters from below.  (optional)</param>
        /// <param name="weighting">Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="heading">Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="headingPenalty">Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="passThrough">If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="blockArea">Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="avoid">Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="algorithm">Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripDistance">If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripSeed">If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)</param>
        /// <param name="alternativeRouteMaxPaths">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxWeightFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxShareFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <returns>ApiResponse of RouteResponse</returns>
        ApiResponse<RouteResponse> GetRouteWithHttpInfo (List<string> point, List<string> pointHint = null, List<string> snapPrevention = null, VehicleProfileId vehicle = null, string locale = null, bool? elevation = null, List<string> details = null, bool? optimize = null, bool? instructions = null, bool? calcPoints = null, bool? debug = null, bool? pointsEncoded = null, string type = null, bool? chDisable = null, string weighting = null, List<int?> heading = null, int? headingPenalty = null, bool? passThrough = null, string blockArea = null, string avoid = null, string algorithm = null, int? roundTripDistance = null, long? roundTripSeed = null, int? alternativeRouteMaxPaths = null, decimal? alternativeRouteMaxWeightFactor = null, decimal? alternativeRouteMaxShareFactor = null);
        /// <summary>
        /// Coverage information
        /// </summary>
        /// <remarks>
        /// Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <returns>InfoResponse</returns>
        InfoResponse RouteInfoGet ();

        /// <summary>
        /// Coverage information
        /// </summary>
        /// <remarks>
        /// Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <returns>ApiResponse of InfoResponse</returns>
        ApiResponse<InfoResponse> RouteInfoGetWithHttpInfo ();
        #endregion Synchronous Operations
        #region Asynchronous Operations
        /// <summary>
        /// Execute a routing request
        /// </summary>
        /// <remarks>
        /// ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#x27;&#x27;best&#x27;&#x27; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. </param>
        /// <param name="pointHint">The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)</param>
        /// <param name="snapPrevention">Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="locale">The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)</param>
        /// <param name="elevation">If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)</param>
        /// <param name="details">Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)</param>
        /// <param name="optimize">Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)</param>
        /// <param name="instructions">If instructions should be calculated and returned  (optional)</param>
        /// <param name="calcPoints">If the points for the route should be calculated at all.  (optional)</param>
        /// <param name="debug">If &#x60;true&#x60;, the output will be formatted.  (optional)</param>
        /// <param name="pointsEncoded">If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)</param>
        /// <param name="type">Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)</param>
        /// <param name="chDisable">Use this parameter in combination with one or more parameters from below.  (optional)</param>
        /// <param name="weighting">Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="heading">Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="headingPenalty">Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="passThrough">If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="blockArea">Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="avoid">Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="algorithm">Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripDistance">If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripSeed">If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)</param>
        /// <param name="alternativeRouteMaxPaths">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxWeightFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxShareFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <returns>Task of RouteResponse</returns>
        System.Threading.Tasks.Task<RouteResponse> GetRouteAsync (List<string> point, List<string> pointHint = null, List<string> snapPrevention = null, VehicleProfileId vehicle = null, string locale = null, bool? elevation = null, List<string> details = null, bool? optimize = null, bool? instructions = null, bool? calcPoints = null, bool? debug = null, bool? pointsEncoded = null, string type = null, bool? chDisable = null, string weighting = null, List<int?> heading = null, int? headingPenalty = null, bool? passThrough = null, string blockArea = null, string avoid = null, string algorithm = null, int? roundTripDistance = null, long? roundTripSeed = null, int? alternativeRouteMaxPaths = null, decimal? alternativeRouteMaxWeightFactor = null, decimal? alternativeRouteMaxShareFactor = null);

        /// <summary>
        /// Execute a routing request
        /// </summary>
        /// <remarks>
        /// ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#x27;&#x27;best&#x27;&#x27; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. </param>
        /// <param name="pointHint">The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)</param>
        /// <param name="snapPrevention">Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="locale">The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)</param>
        /// <param name="elevation">If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)</param>
        /// <param name="details">Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)</param>
        /// <param name="optimize">Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)</param>
        /// <param name="instructions">If instructions should be calculated and returned  (optional)</param>
        /// <param name="calcPoints">If the points for the route should be calculated at all.  (optional)</param>
        /// <param name="debug">If &#x60;true&#x60;, the output will be formatted.  (optional)</param>
        /// <param name="pointsEncoded">If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)</param>
        /// <param name="type">Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)</param>
        /// <param name="chDisable">Use this parameter in combination with one or more parameters from below.  (optional)</param>
        /// <param name="weighting">Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="heading">Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="headingPenalty">Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="passThrough">If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="blockArea">Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="avoid">Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="algorithm">Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripDistance">If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripSeed">If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)</param>
        /// <param name="alternativeRouteMaxPaths">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxWeightFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxShareFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <returns>Task of ApiResponse (RouteResponse)</returns>
        System.Threading.Tasks.Task<ApiResponse<RouteResponse>> GetRouteAsyncWithHttpInfo (List<string> point, List<string> pointHint = null, List<string> snapPrevention = null, VehicleProfileId vehicle = null, string locale = null, bool? elevation = null, List<string> details = null, bool? optimize = null, bool? instructions = null, bool? calcPoints = null, bool? debug = null, bool? pointsEncoded = null, string type = null, bool? chDisable = null, string weighting = null, List<int?> heading = null, int? headingPenalty = null, bool? passThrough = null, string blockArea = null, string avoid = null, string algorithm = null, int? roundTripDistance = null, long? roundTripSeed = null, int? alternativeRouteMaxPaths = null, decimal? alternativeRouteMaxWeightFactor = null, decimal? alternativeRouteMaxShareFactor = null);
        /// <summary>
        /// Coverage information
        /// </summary>
        /// <remarks>
        /// Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <returns>Task of InfoResponse</returns>
        System.Threading.Tasks.Task<InfoResponse> RouteInfoGetAsync ();

        /// <summary>
        /// Coverage information
        /// </summary>
        /// <remarks>
        /// Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <returns>Task of ApiResponse (InfoResponse)</returns>
        System.Threading.Tasks.Task<ApiResponse<InfoResponse>> RouteInfoGetAsyncWithHttpInfo ();
        #endregion Asynchronous Operations
    }

    /// <summary>
    /// Represents a collection of functions to interact with the API endpoints
    /// </summary>
        public partial class RoutingApi : IRoutingApi
    {
        private IO.Swagger.Client.ExceptionFactory _exceptionFactory = (name, response) => null;

        /// <summary>
        /// Initializes a new instance of the <see cref="RoutingApi"/> class.
        /// </summary>
        /// <returns></returns>
        public RoutingApi(String basePath)
        {
            this.Configuration = new IO.Swagger.Client.Configuration { BasePath = basePath };

            ExceptionFactory = IO.Swagger.Client.Configuration.DefaultExceptionFactory;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="RoutingApi"/> class
        /// </summary>
        /// <returns></returns>
        public RoutingApi()
        {
            this.Configuration = IO.Swagger.Client.Configuration.Default;

            ExceptionFactory = IO.Swagger.Client.Configuration.DefaultExceptionFactory;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="RoutingApi"/> class
        /// using Configuration object
        /// </summary>
        /// <param name="configuration">An instance of Configuration</param>
        /// <returns></returns>
        public RoutingApi(IO.Swagger.Client.Configuration configuration = null)
        {
            if (configuration == null) // use the default one in Configuration
                this.Configuration = IO.Swagger.Client.Configuration.Default;
            else
                this.Configuration = configuration;

            ExceptionFactory = IO.Swagger.Client.Configuration.DefaultExceptionFactory;
        }

        /// <summary>
        /// Gets the base path of the API client.
        /// </summary>
        /// <value>The base path</value>
        public String GetBasePath()
        {
            return this.Configuration.ApiClient.RestClient.BaseUrl.ToString();
        }

        /// <summary>
        /// Sets the base path of the API client.
        /// </summary>
        /// <value>The base path</value>
        [Obsolete("SetBasePath is deprecated, please do 'Configuration.ApiClient = new ApiClient(\"http://new-path\")' instead.")]
        public void SetBasePath(String basePath)
        {
            // do nothing
        }

        /// <summary>
        /// Gets or sets the configuration object
        /// </summary>
        /// <value>An instance of the Configuration</value>
        public IO.Swagger.Client.Configuration Configuration {get; set;}

        /// <summary>
        /// Provides a factory method hook for the creation of exceptions.
        /// </summary>
        public IO.Swagger.Client.ExceptionFactory ExceptionFactory
        {
            get
            {
                if (_exceptionFactory != null && _exceptionFactory.GetInvocationList().Length > 1)
                {
                    throw new InvalidOperationException("Multicast delegate for ExceptionFactory is unsupported.");
                }
                return _exceptionFactory;
            }
            set { _exceptionFactory = value; }
        }

        /// <summary>
        /// Gets the default header.
        /// </summary>
        /// <returns>Dictionary of HTTP header</returns>
        [Obsolete("DefaultHeader is deprecated, please use Configuration.DefaultHeader instead.")]
        public IDictionary<String, String> DefaultHeader()
        {
            return new ReadOnlyDictionary<string, string>(this.Configuration.DefaultHeader);
        }

        /// <summary>
        /// Add default header.
        /// </summary>
        /// <param name="key">Header field name.</param>
        /// <param name="value">Header field value.</param>
        /// <returns></returns>
        [Obsolete("AddDefaultHeader is deprecated, please use Configuration.AddDefaultHeader instead.")]
        public void AddDefaultHeader(string key, string value)
        {
            this.Configuration.AddDefaultHeader(key, value);
        }

        /// <summary>
        /// Execute a routing request ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#x27;&#x27;best&#x27;&#x27; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. </param>
        /// <param name="pointHint">The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)</param>
        /// <param name="snapPrevention">Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="locale">The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)</param>
        /// <param name="elevation">If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)</param>
        /// <param name="details">Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)</param>
        /// <param name="optimize">Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)</param>
        /// <param name="instructions">If instructions should be calculated and returned  (optional)</param>
        /// <param name="calcPoints">If the points for the route should be calculated at all.  (optional)</param>
        /// <param name="debug">If &#x60;true&#x60;, the output will be formatted.  (optional)</param>
        /// <param name="pointsEncoded">If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)</param>
        /// <param name="type">Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)</param>
        /// <param name="chDisable">Use this parameter in combination with one or more parameters from below.  (optional)</param>
        /// <param name="weighting">Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="heading">Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="headingPenalty">Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="passThrough">If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="blockArea">Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="avoid">Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="algorithm">Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripDistance">If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripSeed">If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)</param>
        /// <param name="alternativeRouteMaxPaths">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxWeightFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxShareFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <returns>RouteResponse</returns>
        public RouteResponse GetRoute (List<string> point, List<string> pointHint = null, List<string> snapPrevention = null, VehicleProfileId vehicle = null, string locale = null, bool? elevation = null, List<string> details = null, bool? optimize = null, bool? instructions = null, bool? calcPoints = null, bool? debug = null, bool? pointsEncoded = null, string type = null, bool? chDisable = null, string weighting = null, List<int?> heading = null, int? headingPenalty = null, bool? passThrough = null, string blockArea = null, string avoid = null, string algorithm = null, int? roundTripDistance = null, long? roundTripSeed = null, int? alternativeRouteMaxPaths = null, decimal? alternativeRouteMaxWeightFactor = null, decimal? alternativeRouteMaxShareFactor = null)
        {
             ApiResponse<RouteResponse> localVarResponse = GetRouteWithHttpInfo(point, pointHint, snapPrevention, vehicle, locale, elevation, details, optimize, instructions, calcPoints, debug, pointsEncoded, type, chDisable, weighting, heading, headingPenalty, passThrough, blockArea, avoid, algorithm, roundTripDistance, roundTripSeed, alternativeRouteMaxPaths, alternativeRouteMaxWeightFactor, alternativeRouteMaxShareFactor);
             return localVarResponse.Data;
        }

        /// <summary>
        /// Execute a routing request ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#x27;&#x27;best&#x27;&#x27; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. </param>
        /// <param name="pointHint">The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)</param>
        /// <param name="snapPrevention">Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="locale">The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)</param>
        /// <param name="elevation">If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)</param>
        /// <param name="details">Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)</param>
        /// <param name="optimize">Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)</param>
        /// <param name="instructions">If instructions should be calculated and returned  (optional)</param>
        /// <param name="calcPoints">If the points for the route should be calculated at all.  (optional)</param>
        /// <param name="debug">If &#x60;true&#x60;, the output will be formatted.  (optional)</param>
        /// <param name="pointsEncoded">If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)</param>
        /// <param name="type">Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)</param>
        /// <param name="chDisable">Use this parameter in combination with one or more parameters from below.  (optional)</param>
        /// <param name="weighting">Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="heading">Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="headingPenalty">Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="passThrough">If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="blockArea">Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="avoid">Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="algorithm">Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripDistance">If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripSeed">If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)</param>
        /// <param name="alternativeRouteMaxPaths">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxWeightFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxShareFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <returns>ApiResponse of RouteResponse</returns>
        public ApiResponse< RouteResponse > GetRouteWithHttpInfo (List<string> point, List<string> pointHint = null, List<string> snapPrevention = null, VehicleProfileId vehicle = null, string locale = null, bool? elevation = null, List<string> details = null, bool? optimize = null, bool? instructions = null, bool? calcPoints = null, bool? debug = null, bool? pointsEncoded = null, string type = null, bool? chDisable = null, string weighting = null, List<int?> heading = null, int? headingPenalty = null, bool? passThrough = null, string blockArea = null, string avoid = null, string algorithm = null, int? roundTripDistance = null, long? roundTripSeed = null, int? alternativeRouteMaxPaths = null, decimal? alternativeRouteMaxWeightFactor = null, decimal? alternativeRouteMaxShareFactor = null)
        {
            // verify the required parameter 'point' is set
            if (point == null)
                throw new ApiException(400, "Missing required parameter 'point' when calling RoutingApi->GetRoute");

            var localVarPath = "/route";
            var localVarPathParams = new Dictionary<String, String>();
            var localVarQueryParams = new List<KeyValuePair<String, String>>();
            var localVarHeaderParams = new Dictionary<String, String>(this.Configuration.DefaultHeader);
            var localVarFormParams = new Dictionary<String, String>();
            var localVarFileParams = new Dictionary<String, FileParameter>();
            Object localVarPostBody = null;

            // to determine the Content-Type header
            String[] localVarHttpContentTypes = new String[] {
            };
            String localVarHttpContentType = this.Configuration.ApiClient.SelectHeaderContentType(localVarHttpContentTypes);

            // to determine the Accept header
            String[] localVarHttpHeaderAccepts = new String[] {
                "application/json"
            };
            String localVarHttpHeaderAccept = this.Configuration.ApiClient.SelectHeaderAccept(localVarHttpHeaderAccepts);
            if (localVarHttpHeaderAccept != null)
                localVarHeaderParams.Add("Accept", localVarHttpHeaderAccept);

            if (point != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "point", point)); // query parameter
            if (pointHint != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "point_hint", pointHint)); // query parameter
            if (snapPrevention != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "snap_prevention", snapPrevention)); // query parameter
            if (vehicle != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "vehicle", vehicle)); // query parameter
            if (locale != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "locale", locale)); // query parameter
            if (elevation != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "elevation", elevation)); // query parameter
            if (details != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "details", details)); // query parameter
            if (optimize != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "optimize", optimize)); // query parameter
            if (instructions != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "instructions", instructions)); // query parameter
            if (calcPoints != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "calc_points", calcPoints)); // query parameter
            if (debug != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "debug", debug)); // query parameter
            if (pointsEncoded != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "points_encoded", pointsEncoded)); // query parameter
            if (type != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "type", type)); // query parameter
            if (chDisable != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "ch.disable", chDisable)); // query parameter
            if (weighting != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "weighting", weighting)); // query parameter
            if (heading != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "heading", heading)); // query parameter
            if (headingPenalty != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "heading_penalty", headingPenalty)); // query parameter
            if (passThrough != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "pass_through", passThrough)); // query parameter
            if (blockArea != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "block_area", blockArea)); // query parameter
            if (avoid != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "avoid", avoid)); // query parameter
            if (algorithm != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "algorithm", algorithm)); // query parameter
            if (roundTripDistance != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "round_trip.distance", roundTripDistance)); // query parameter
            if (roundTripSeed != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "round_trip.seed", roundTripSeed)); // query parameter
            if (alternativeRouteMaxPaths != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "alternative_route.max_paths", alternativeRouteMaxPaths)); // query parameter
            if (alternativeRouteMaxWeightFactor != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "alternative_route.max_weight_factor", alternativeRouteMaxWeightFactor)); // query parameter
            if (alternativeRouteMaxShareFactor != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "alternative_route.max_share_factor", alternativeRouteMaxShareFactor)); // query parameter
            // authentication (api_key) required
            if (!String.IsNullOrEmpty(this.Configuration.GetApiKeyWithPrefix("key")))
            {
                localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "key", this.Configuration.GetApiKeyWithPrefix("key")));
            }

            // make the HTTP request
            IRestResponse localVarResponse = (IRestResponse) this.Configuration.ApiClient.CallApi(localVarPath,
                Method.GET, localVarQueryParams, localVarPostBody, localVarHeaderParams, localVarFormParams, localVarFileParams,
                localVarPathParams, localVarHttpContentType);

            int localVarStatusCode = (int) localVarResponse.StatusCode;

            if (ExceptionFactory != null)
            {
                Exception exception = ExceptionFactory("GetRoute", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<RouteResponse>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (RouteResponse) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(RouteResponse)));
        }

        /// <summary>
        /// Execute a routing request ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#x27;&#x27;best&#x27;&#x27; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. </param>
        /// <param name="pointHint">The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)</param>
        /// <param name="snapPrevention">Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="locale">The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)</param>
        /// <param name="elevation">If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)</param>
        /// <param name="details">Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)</param>
        /// <param name="optimize">Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)</param>
        /// <param name="instructions">If instructions should be calculated and returned  (optional)</param>
        /// <param name="calcPoints">If the points for the route should be calculated at all.  (optional)</param>
        /// <param name="debug">If &#x60;true&#x60;, the output will be formatted.  (optional)</param>
        /// <param name="pointsEncoded">If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)</param>
        /// <param name="type">Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)</param>
        /// <param name="chDisable">Use this parameter in combination with one or more parameters from below.  (optional)</param>
        /// <param name="weighting">Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="heading">Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="headingPenalty">Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="passThrough">If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="blockArea">Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="avoid">Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="algorithm">Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripDistance">If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripSeed">If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)</param>
        /// <param name="alternativeRouteMaxPaths">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxWeightFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxShareFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <returns>Task of RouteResponse</returns>
        public async System.Threading.Tasks.Task<RouteResponse> GetRouteAsync (List<string> point, List<string> pointHint = null, List<string> snapPrevention = null, VehicleProfileId vehicle = null, string locale = null, bool? elevation = null, List<string> details = null, bool? optimize = null, bool? instructions = null, bool? calcPoints = null, bool? debug = null, bool? pointsEncoded = null, string type = null, bool? chDisable = null, string weighting = null, List<int?> heading = null, int? headingPenalty = null, bool? passThrough = null, string blockArea = null, string avoid = null, string algorithm = null, int? roundTripDistance = null, long? roundTripSeed = null, int? alternativeRouteMaxPaths = null, decimal? alternativeRouteMaxWeightFactor = null, decimal? alternativeRouteMaxShareFactor = null)
        {
             ApiResponse<RouteResponse> localVarResponse = await GetRouteAsyncWithHttpInfo(point, pointHint, snapPrevention, vehicle, locale, elevation, details, optimize, instructions, calcPoints, debug, pointsEncoded, type, chDisable, weighting, heading, headingPenalty, passThrough, blockArea, avoid, algorithm, roundTripDistance, roundTripSeed, alternativeRouteMaxPaths, alternativeRouteMaxWeightFactor, alternativeRouteMaxShareFactor);
             return localVarResponse.Data;

        }

        /// <summary>
        /// Execute a routing request ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#x27;&#x27;best&#x27;&#x27; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. </param>
        /// <param name="pointHint">The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)</param>
        /// <param name="snapPrevention">Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="locale">The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)</param>
        /// <param name="elevation">If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)</param>
        /// <param name="details">Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)</param>
        /// <param name="optimize">Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)</param>
        /// <param name="instructions">If instructions should be calculated and returned  (optional)</param>
        /// <param name="calcPoints">If the points for the route should be calculated at all.  (optional)</param>
        /// <param name="debug">If &#x60;true&#x60;, the output will be formatted.  (optional)</param>
        /// <param name="pointsEncoded">If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)</param>
        /// <param name="type">Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)</param>
        /// <param name="chDisable">Use this parameter in combination with one or more parameters from below.  (optional)</param>
        /// <param name="weighting">Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="heading">Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="headingPenalty">Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="passThrough">If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="blockArea">Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="avoid">Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="algorithm">Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripDistance">If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)</param>
        /// <param name="roundTripSeed">If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)</param>
        /// <param name="alternativeRouteMaxPaths">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxWeightFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <param name="alternativeRouteMaxShareFactor">If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)</param>
        /// <returns>Task of ApiResponse (RouteResponse)</returns>
        public async System.Threading.Tasks.Task<ApiResponse<RouteResponse>> GetRouteAsyncWithHttpInfo (List<string> point, List<string> pointHint = null, List<string> snapPrevention = null, VehicleProfileId vehicle = null, string locale = null, bool? elevation = null, List<string> details = null, bool? optimize = null, bool? instructions = null, bool? calcPoints = null, bool? debug = null, bool? pointsEncoded = null, string type = null, bool? chDisable = null, string weighting = null, List<int?> heading = null, int? headingPenalty = null, bool? passThrough = null, string blockArea = null, string avoid = null, string algorithm = null, int? roundTripDistance = null, long? roundTripSeed = null, int? alternativeRouteMaxPaths = null, decimal? alternativeRouteMaxWeightFactor = null, decimal? alternativeRouteMaxShareFactor = null)
        {
            // verify the required parameter 'point' is set
            if (point == null)
                throw new ApiException(400, "Missing required parameter 'point' when calling RoutingApi->GetRoute");

            var localVarPath = "/route";
            var localVarPathParams = new Dictionary<String, String>();
            var localVarQueryParams = new List<KeyValuePair<String, String>>();
            var localVarHeaderParams = new Dictionary<String, String>(this.Configuration.DefaultHeader);
            var localVarFormParams = new Dictionary<String, String>();
            var localVarFileParams = new Dictionary<String, FileParameter>();
            Object localVarPostBody = null;

            // to determine the Content-Type header
            String[] localVarHttpContentTypes = new String[] {
            };
            String localVarHttpContentType = this.Configuration.ApiClient.SelectHeaderContentType(localVarHttpContentTypes);

            // to determine the Accept header
            String[] localVarHttpHeaderAccepts = new String[] {
                "application/json"
            };
            String localVarHttpHeaderAccept = this.Configuration.ApiClient.SelectHeaderAccept(localVarHttpHeaderAccepts);
            if (localVarHttpHeaderAccept != null)
                localVarHeaderParams.Add("Accept", localVarHttpHeaderAccept);

            if (point != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "point", point)); // query parameter
            if (pointHint != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "point_hint", pointHint)); // query parameter
            if (snapPrevention != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "snap_prevention", snapPrevention)); // query parameter
            if (vehicle != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "vehicle", vehicle)); // query parameter
            if (locale != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "locale", locale)); // query parameter
            if (elevation != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "elevation", elevation)); // query parameter
            if (details != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "details", details)); // query parameter
            if (optimize != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "optimize", optimize)); // query parameter
            if (instructions != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "instructions", instructions)); // query parameter
            if (calcPoints != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "calc_points", calcPoints)); // query parameter
            if (debug != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "debug", debug)); // query parameter
            if (pointsEncoded != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "points_encoded", pointsEncoded)); // query parameter
            if (type != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "type", type)); // query parameter
            if (chDisable != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "ch.disable", chDisable)); // query parameter
            if (weighting != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "weighting", weighting)); // query parameter
            if (heading != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("multi", "heading", heading)); // query parameter
            if (headingPenalty != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "heading_penalty", headingPenalty)); // query parameter
            if (passThrough != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "pass_through", passThrough)); // query parameter
            if (blockArea != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "block_area", blockArea)); // query parameter
            if (avoid != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "avoid", avoid)); // query parameter
            if (algorithm != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "algorithm", algorithm)); // query parameter
            if (roundTripDistance != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "round_trip.distance", roundTripDistance)); // query parameter
            if (roundTripSeed != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "round_trip.seed", roundTripSeed)); // query parameter
            if (alternativeRouteMaxPaths != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "alternative_route.max_paths", alternativeRouteMaxPaths)); // query parameter
            if (alternativeRouteMaxWeightFactor != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "alternative_route.max_weight_factor", alternativeRouteMaxWeightFactor)); // query parameter
            if (alternativeRouteMaxShareFactor != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "alternative_route.max_share_factor", alternativeRouteMaxShareFactor)); // query parameter
            // authentication (api_key) required
            if (!String.IsNullOrEmpty(this.Configuration.GetApiKeyWithPrefix("key")))
            {
                localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "key", this.Configuration.GetApiKeyWithPrefix("key")));
            }

            // make the HTTP request
            IRestResponse localVarResponse = (IRestResponse) await this.Configuration.ApiClient.CallApiAsync(localVarPath,
                Method.GET, localVarQueryParams, localVarPostBody, localVarHeaderParams, localVarFormParams, localVarFileParams,
                localVarPathParams, localVarHttpContentType);

            int localVarStatusCode = (int) localVarResponse.StatusCode;

            if (ExceptionFactory != null)
            {
                Exception exception = ExceptionFactory("GetRoute", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<RouteResponse>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (RouteResponse) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(RouteResponse)));
        }

        /// <summary>
        /// Coverage information Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <returns>InfoResponse</returns>
        public InfoResponse RouteInfoGet ()
        {
             ApiResponse<InfoResponse> localVarResponse = RouteInfoGetWithHttpInfo();
             return localVarResponse.Data;
        }

        /// <summary>
        /// Coverage information Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <returns>ApiResponse of InfoResponse</returns>
        public ApiResponse< InfoResponse > RouteInfoGetWithHttpInfo ()
        {

            var localVarPath = "/route/info";
            var localVarPathParams = new Dictionary<String, String>();
            var localVarQueryParams = new List<KeyValuePair<String, String>>();
            var localVarHeaderParams = new Dictionary<String, String>(this.Configuration.DefaultHeader);
            var localVarFormParams = new Dictionary<String, String>();
            var localVarFileParams = new Dictionary<String, FileParameter>();
            Object localVarPostBody = null;

            // to determine the Content-Type header
            String[] localVarHttpContentTypes = new String[] {
            };
            String localVarHttpContentType = this.Configuration.ApiClient.SelectHeaderContentType(localVarHttpContentTypes);

            // to determine the Accept header
            String[] localVarHttpHeaderAccepts = new String[] {
                "application/json"
            };
            String localVarHttpHeaderAccept = this.Configuration.ApiClient.SelectHeaderAccept(localVarHttpHeaderAccepts);
            if (localVarHttpHeaderAccept != null)
                localVarHeaderParams.Add("Accept", localVarHttpHeaderAccept);

            // authentication (api_key) required
            if (!String.IsNullOrEmpty(this.Configuration.GetApiKeyWithPrefix("key")))
            {
                localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "key", this.Configuration.GetApiKeyWithPrefix("key")));
            }

            // make the HTTP request
            IRestResponse localVarResponse = (IRestResponse) this.Configuration.ApiClient.CallApi(localVarPath,
                Method.GET, localVarQueryParams, localVarPostBody, localVarHeaderParams, localVarFormParams, localVarFileParams,
                localVarPathParams, localVarHttpContentType);

            int localVarStatusCode = (int) localVarResponse.StatusCode;

            if (ExceptionFactory != null)
            {
                Exception exception = ExceptionFactory("RouteInfoGet", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<InfoResponse>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (InfoResponse) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(InfoResponse)));
        }

        /// <summary>
        /// Coverage information Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <returns>Task of InfoResponse</returns>
        public async System.Threading.Tasks.Task<InfoResponse> RouteInfoGetAsync ()
        {
             ApiResponse<InfoResponse> localVarResponse = await RouteInfoGetAsyncWithHttpInfo();
             return localVarResponse.Data;

        }

        /// <summary>
        /// Coverage information Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <returns>Task of ApiResponse (InfoResponse)</returns>
        public async System.Threading.Tasks.Task<ApiResponse<InfoResponse>> RouteInfoGetAsyncWithHttpInfo ()
        {

            var localVarPath = "/route/info";
            var localVarPathParams = new Dictionary<String, String>();
            var localVarQueryParams = new List<KeyValuePair<String, String>>();
            var localVarHeaderParams = new Dictionary<String, String>(this.Configuration.DefaultHeader);
            var localVarFormParams = new Dictionary<String, String>();
            var localVarFileParams = new Dictionary<String, FileParameter>();
            Object localVarPostBody = null;

            // to determine the Content-Type header
            String[] localVarHttpContentTypes = new String[] {
            };
            String localVarHttpContentType = this.Configuration.ApiClient.SelectHeaderContentType(localVarHttpContentTypes);

            // to determine the Accept header
            String[] localVarHttpHeaderAccepts = new String[] {
                "application/json"
            };
            String localVarHttpHeaderAccept = this.Configuration.ApiClient.SelectHeaderAccept(localVarHttpHeaderAccepts);
            if (localVarHttpHeaderAccept != null)
                localVarHeaderParams.Add("Accept", localVarHttpHeaderAccept);

            // authentication (api_key) required
            if (!String.IsNullOrEmpty(this.Configuration.GetApiKeyWithPrefix("key")))
            {
                localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "key", this.Configuration.GetApiKeyWithPrefix("key")));
            }

            // make the HTTP request
            IRestResponse localVarResponse = (IRestResponse) await this.Configuration.ApiClient.CallApiAsync(localVarPath,
                Method.GET, localVarQueryParams, localVarPostBody, localVarHeaderParams, localVarFormParams, localVarFileParams,
                localVarPathParams, localVarHttpContentType);

            int localVarStatusCode = (int) localVarResponse.StatusCode;

            if (ExceptionFactory != null)
            {
                Exception exception = ExceptionFactory("RouteInfoGet", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<InfoResponse>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (InfoResponse) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(InfoResponse)));
        }

    }
}
