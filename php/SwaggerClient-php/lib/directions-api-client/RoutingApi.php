<?php
/**
 * RoutingApi
 * PHP version 5
 *
 * @category Class
 * @package  Swagger\Client
 * @author   Swagger Codegen team
 * @link     https://github.com/swagger-api/swagger-codegen
 */

/**
 * GraphHopper Directions API
 *
 * With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Clients  To speed up development and make coding easier, we offer the following clients:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions for motor vehicles such as `car` or `truck` are only considered with `edge_based=true` for the Routing (other APIs will follow).** Or if you already use `ch.disable=true` no additional parameter is required to consider turn restrictions for motor vehicles.  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png)
 *
 * OpenAPI spec version: 1.0.0
 * Contact: support@graphhopper.com
 * Generated by: https://github.com/swagger-api/swagger-codegen.git
 * Swagger Codegen version: 3.0.11
 */
/**
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen
 * Do not edit the class manually.
 */

namespace Swagger\Client\directions-api-client;

use GuzzleHttp\Client;
use GuzzleHttp\ClientInterface;
use GuzzleHttp\Exception\RequestException;
use GuzzleHttp\Psr7\MultipartStream;
use GuzzleHttp\Psr7\Request;
use GuzzleHttp\RequestOptions;
use Swagger\Client\ApiException;
use Swagger\Client\Configuration;
use Swagger\Client\HeaderSelector;
use Swagger\Client\ObjectSerializer;

/**
 * RoutingApi Class Doc Comment
 *
 * @category Class
 * @package  Swagger\Client
 * @author   Swagger Codegen team
 * @link     https://github.com/swagger-api/swagger-codegen
 */
class RoutingApi
{
    /**
     * @var ClientInterface
     */
    protected $client;

    /**
     * @var Configuration
     */
    protected $config;

    /**
     * @var HeaderSelector
     */
    protected $headerSelector;

    /**
     * @param ClientInterface $client
     * @param Configuration   $config
     * @param HeaderSelector  $selector
     */
    public function __construct(
        ClientInterface $client = null,
        Configuration $config = null,
        HeaderSelector $selector = null
    ) {
        $this->client = $client ?: new Client();
        $this->config = $config ?: new Configuration();
        $this->headerSelector = $selector ?: new HeaderSelector();
    }

    /**
     * @return Configuration
     */
    public function getConfig()
    {
        return $this->config;
    }

    /**
     * Operation getRoute
     *
     * Execute a routing request
     *
     * @param  string[] $point The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. (required)
     * @param  string[] $point_hint The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters. (optional)
     * @param  string[] $snap_prevention Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60; (optional)
     * @param  \Swagger\Client\Model\VehicleProfileId $vehicle The vehicle profile for which the route should be calculated. (optional)
     * @param  string $locale The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German. (optional)
     * @param  bool $elevation If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile. (optional)
     * @param  string[] $details Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;. (optional)
     * @param  bool $optimize Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive. (optional)
     * @param  bool $instructions If instructions should be calculated and returned (optional)
     * @param  bool $calc_points If the points for the route should be calculated at all. (optional)
     * @param  bool $debug If &#x60;true&#x60;, the output will be formatted. (optional)
     * @param  bool $points_encoded If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27). (optional)
     * @param  string $type Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;. (optional)
     * @param  bool $ch_disable Use this parameter in combination with one or more parameters from below. (optional)
     * @param  string $weighting Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int[] $heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $heading_penalty Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  bool $pass_through If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $block_area Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $avoid Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $algorithm Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_distance If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_seed If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value. (optional)
     * @param  int $alternative_route_max_paths If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_weight_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_share_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives. (optional)
     *
     * @throws \Swagger\Client\ApiException on non-2xx response
     * @throws \InvalidArgumentException
     * @return \Swagger\Client\Model\RouteResponse
     */
    public function getRoute($point, $point_hint = null, $snap_prevention = null, $vehicle = null, $locale = null, $elevation = null, $details = null, $optimize = null, $instructions = null, $calc_points = null, $debug = null, $points_encoded = null, $type = null, $ch_disable = null, $weighting = null, $heading = null, $heading_penalty = null, $pass_through = null, $block_area = null, $avoid = null, $algorithm = null, $round_trip_distance = null, $round_trip_seed = null, $alternative_route_max_paths = null, $alternative_route_max_weight_factor = null, $alternative_route_max_share_factor = null)
    {
        list($response) = $this->getRouteWithHttpInfo($point, $point_hint, $snap_prevention, $vehicle, $locale, $elevation, $details, $optimize, $instructions, $calc_points, $debug, $points_encoded, $type, $ch_disable, $weighting, $heading, $heading_penalty, $pass_through, $block_area, $avoid, $algorithm, $round_trip_distance, $round_trip_seed, $alternative_route_max_paths, $alternative_route_max_weight_factor, $alternative_route_max_share_factor);
        return $response;
    }

    /**
     * Operation getRouteWithHttpInfo
     *
     * Execute a routing request
     *
     * @param  string[] $point The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. (required)
     * @param  string[] $point_hint The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters. (optional)
     * @param  string[] $snap_prevention Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60; (optional)
     * @param  \Swagger\Client\Model\VehicleProfileId $vehicle The vehicle profile for which the route should be calculated. (optional)
     * @param  string $locale The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German. (optional)
     * @param  bool $elevation If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile. (optional)
     * @param  string[] $details Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;. (optional)
     * @param  bool $optimize Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive. (optional)
     * @param  bool $instructions If instructions should be calculated and returned (optional)
     * @param  bool $calc_points If the points for the route should be calculated at all. (optional)
     * @param  bool $debug If &#x60;true&#x60;, the output will be formatted. (optional)
     * @param  bool $points_encoded If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27). (optional)
     * @param  string $type Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;. (optional)
     * @param  bool $ch_disable Use this parameter in combination with one or more parameters from below. (optional)
     * @param  string $weighting Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int[] $heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $heading_penalty Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  bool $pass_through If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $block_area Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $avoid Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $algorithm Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_distance If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_seed If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value. (optional)
     * @param  int $alternative_route_max_paths If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_weight_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_share_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives. (optional)
     *
     * @throws \Swagger\Client\ApiException on non-2xx response
     * @throws \InvalidArgumentException
     * @return array of \Swagger\Client\Model\RouteResponse, HTTP status code, HTTP response headers (array of strings)
     */
    public function getRouteWithHttpInfo($point, $point_hint = null, $snap_prevention = null, $vehicle = null, $locale = null, $elevation = null, $details = null, $optimize = null, $instructions = null, $calc_points = null, $debug = null, $points_encoded = null, $type = null, $ch_disable = null, $weighting = null, $heading = null, $heading_penalty = null, $pass_through = null, $block_area = null, $avoid = null, $algorithm = null, $round_trip_distance = null, $round_trip_seed = null, $alternative_route_max_paths = null, $alternative_route_max_weight_factor = null, $alternative_route_max_share_factor = null)
    {
        $returnType = '\Swagger\Client\Model\RouteResponse';
        $request = $this->getRouteRequest($point, $point_hint, $snap_prevention, $vehicle, $locale, $elevation, $details, $optimize, $instructions, $calc_points, $debug, $points_encoded, $type, $ch_disable, $weighting, $heading, $heading_penalty, $pass_through, $block_area, $avoid, $algorithm, $round_trip_distance, $round_trip_seed, $alternative_route_max_paths, $alternative_route_max_weight_factor, $alternative_route_max_share_factor);

        try {
            $options = $this->createHttpClientOption();
            try {
                $response = $this->client->send($request, $options);
            } catch (RequestException $e) {
                throw new ApiException(
                    "[{$e->getCode()}] {$e->getMessage()}",
                    $e->getCode(),
                    $e->getResponse() ? $e->getResponse()->getHeaders() : null,
                    $e->getResponse() ? $e->getResponse()->getBody()->getContents() : null
                );
            }

            $statusCode = $response->getStatusCode();

            if ($statusCode < 200 || $statusCode > 299) {
                throw new ApiException(
                    sprintf(
                        '[%d] Error connecting to the API (%s)',
                        $statusCode,
                        $request->getUri()
                    ),
                    $statusCode,
                    $response->getHeaders(),
                    $response->getBody()
                );
            }

            $responseBody = $response->getBody();
            if ($returnType === '\SplFileObject') {
                $content = $responseBody; //stream goes to serializer
            } else {
                $content = $responseBody->getContents();
                if (!in_array($returnType, ['string','integer','bool'])) {
                    $content = json_decode($content);
                }
            }

            return [
                ObjectSerializer::deserialize($content, $returnType, []),
                $response->getStatusCode(),
                $response->getHeaders()
            ];

        } catch (ApiException $e) {
            switch ($e->getCode()) {
                case 200:
                    $data = ObjectSerializer::deserialize(
                        $e->getResponseBody(),
                        '\Swagger\Client\Model\RouteResponse',
                        $e->getResponseHeaders()
                    );
                    $e->setResponseObject($data);
                    break;
                case 400:
                    $data = ObjectSerializer::deserialize(
                        $e->getResponseBody(),
                        '\Swagger\Client\Model\GHError',
                        $e->getResponseHeaders()
                    );
                    $e->setResponseObject($data);
                    break;
                case 401:
                    $data = ObjectSerializer::deserialize(
                        $e->getResponseBody(),
                        '\Swagger\Client\Model\GHError',
                        $e->getResponseHeaders()
                    );
                    $e->setResponseObject($data);
                    break;
                case 429:
                    $data = ObjectSerializer::deserialize(
                        $e->getResponseBody(),
                        '\Swagger\Client\Model\GHError',
                        $e->getResponseHeaders()
                    );
                    $e->setResponseObject($data);
                    break;
                case 500:
                    $data = ObjectSerializer::deserialize(
                        $e->getResponseBody(),
                        '\Swagger\Client\Model\GHError',
                        $e->getResponseHeaders()
                    );
                    $e->setResponseObject($data);
                    break;
                case 501:
                    $data = ObjectSerializer::deserialize(
                        $e->getResponseBody(),
                        '\Swagger\Client\Model\GHError',
                        $e->getResponseHeaders()
                    );
                    $e->setResponseObject($data);
                    break;
            }
            throw $e;
        }
    }

    /**
     * Operation getRouteAsync
     *
     * Execute a routing request
     *
     * @param  string[] $point The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. (required)
     * @param  string[] $point_hint The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters. (optional)
     * @param  string[] $snap_prevention Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60; (optional)
     * @param  \Swagger\Client\Model\VehicleProfileId $vehicle The vehicle profile for which the route should be calculated. (optional)
     * @param  string $locale The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German. (optional)
     * @param  bool $elevation If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile. (optional)
     * @param  string[] $details Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;. (optional)
     * @param  bool $optimize Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive. (optional)
     * @param  bool $instructions If instructions should be calculated and returned (optional)
     * @param  bool $calc_points If the points for the route should be calculated at all. (optional)
     * @param  bool $debug If &#x60;true&#x60;, the output will be formatted. (optional)
     * @param  bool $points_encoded If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27). (optional)
     * @param  string $type Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;. (optional)
     * @param  bool $ch_disable Use this parameter in combination with one or more parameters from below. (optional)
     * @param  string $weighting Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int[] $heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $heading_penalty Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  bool $pass_through If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $block_area Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $avoid Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $algorithm Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_distance If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_seed If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value. (optional)
     * @param  int $alternative_route_max_paths If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_weight_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_share_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives. (optional)
     *
     * @throws \InvalidArgumentException
     * @return \GuzzleHttp\Promise\PromiseInterface
     */
    public function getRouteAsync($point, $point_hint = null, $snap_prevention = null, $vehicle = null, $locale = null, $elevation = null, $details = null, $optimize = null, $instructions = null, $calc_points = null, $debug = null, $points_encoded = null, $type = null, $ch_disable = null, $weighting = null, $heading = null, $heading_penalty = null, $pass_through = null, $block_area = null, $avoid = null, $algorithm = null, $round_trip_distance = null, $round_trip_seed = null, $alternative_route_max_paths = null, $alternative_route_max_weight_factor = null, $alternative_route_max_share_factor = null)
    {
        return $this->getRouteAsyncWithHttpInfo($point, $point_hint, $snap_prevention, $vehicle, $locale, $elevation, $details, $optimize, $instructions, $calc_points, $debug, $points_encoded, $type, $ch_disable, $weighting, $heading, $heading_penalty, $pass_through, $block_area, $avoid, $algorithm, $round_trip_distance, $round_trip_seed, $alternative_route_max_paths, $alternative_route_max_weight_factor, $alternative_route_max_share_factor)
            ->then(
                function ($response) {
                    return $response[0];
                }
            );
    }

    /**
     * Operation getRouteAsyncWithHttpInfo
     *
     * Execute a routing request
     *
     * @param  string[] $point The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. (required)
     * @param  string[] $point_hint The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters. (optional)
     * @param  string[] $snap_prevention Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60; (optional)
     * @param  \Swagger\Client\Model\VehicleProfileId $vehicle The vehicle profile for which the route should be calculated. (optional)
     * @param  string $locale The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German. (optional)
     * @param  bool $elevation If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile. (optional)
     * @param  string[] $details Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;. (optional)
     * @param  bool $optimize Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive. (optional)
     * @param  bool $instructions If instructions should be calculated and returned (optional)
     * @param  bool $calc_points If the points for the route should be calculated at all. (optional)
     * @param  bool $debug If &#x60;true&#x60;, the output will be formatted. (optional)
     * @param  bool $points_encoded If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27). (optional)
     * @param  string $type Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;. (optional)
     * @param  bool $ch_disable Use this parameter in combination with one or more parameters from below. (optional)
     * @param  string $weighting Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int[] $heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $heading_penalty Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  bool $pass_through If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $block_area Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $avoid Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $algorithm Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_distance If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_seed If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value. (optional)
     * @param  int $alternative_route_max_paths If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_weight_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_share_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives. (optional)
     *
     * @throws \InvalidArgumentException
     * @return \GuzzleHttp\Promise\PromiseInterface
     */
    public function getRouteAsyncWithHttpInfo($point, $point_hint = null, $snap_prevention = null, $vehicle = null, $locale = null, $elevation = null, $details = null, $optimize = null, $instructions = null, $calc_points = null, $debug = null, $points_encoded = null, $type = null, $ch_disable = null, $weighting = null, $heading = null, $heading_penalty = null, $pass_through = null, $block_area = null, $avoid = null, $algorithm = null, $round_trip_distance = null, $round_trip_seed = null, $alternative_route_max_paths = null, $alternative_route_max_weight_factor = null, $alternative_route_max_share_factor = null)
    {
        $returnType = '\Swagger\Client\Model\RouteResponse';
        $request = $this->getRouteRequest($point, $point_hint, $snap_prevention, $vehicle, $locale, $elevation, $details, $optimize, $instructions, $calc_points, $debug, $points_encoded, $type, $ch_disable, $weighting, $heading, $heading_penalty, $pass_through, $block_area, $avoid, $algorithm, $round_trip_distance, $round_trip_seed, $alternative_route_max_paths, $alternative_route_max_weight_factor, $alternative_route_max_share_factor);

        return $this->client
            ->sendAsync($request, $this->createHttpClientOption())
            ->then(
                function ($response) use ($returnType) {
                    $responseBody = $response->getBody();
                    if ($returnType === '\SplFileObject') {
                        $content = $responseBody; //stream goes to serializer
                    } else {
                        $content = $responseBody->getContents();
                        if ($returnType !== 'string') {
                            $content = json_decode($content);
                        }
                    }

                    return [
                        ObjectSerializer::deserialize($content, $returnType, []),
                        $response->getStatusCode(),
                        $response->getHeaders()
                    ];
                },
                function ($exception) {
                    $response = $exception->getResponse();
                    $statusCode = $response->getStatusCode();
                    throw new ApiException(
                        sprintf(
                            '[%d] Error connecting to the API (%s)',
                            $statusCode,
                            $exception->getRequest()->getUri()
                        ),
                        $statusCode,
                        $response->getHeaders(),
                        $response->getBody()
                    );
                }
            );
    }

    /**
     * Create request for operation 'getRoute'
     *
     * @param  string[] $point The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan. (required)
     * @param  string[] $point_hint The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters. (optional)
     * @param  string[] $snap_prevention Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60; (optional)
     * @param  \Swagger\Client\Model\VehicleProfileId $vehicle The vehicle profile for which the route should be calculated. (optional)
     * @param  string $locale The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German. (optional)
     * @param  bool $elevation If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile. (optional)
     * @param  string[] $details Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;. (optional)
     * @param  bool $optimize Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive. (optional)
     * @param  bool $instructions If instructions should be calculated and returned (optional)
     * @param  bool $calc_points If the points for the route should be calculated at all. (optional)
     * @param  bool $debug If &#x60;true&#x60;, the output will be formatted. (optional)
     * @param  bool $points_encoded If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#x27;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27). (optional)
     * @param  string $type Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;. (optional)
     * @param  bool $ch_disable Use this parameter in combination with one or more parameters from below. (optional)
     * @param  string $weighting Determines the way the &#x27;&#x27;best&#x27;&#x27; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int[] $heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $heading_penalty Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  bool $pass_through If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $block_area Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $avoid Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  string $algorithm Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_distance If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;. (optional)
     * @param  int $round_trip_seed If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value. (optional)
     * @param  int $alternative_route_max_paths If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_weight_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. (optional)
     * @param  float $alternative_route_max_share_factor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives. (optional)
     *
     * @throws \InvalidArgumentException
     * @return \GuzzleHttp\Psr7\Request
     */
    protected function getRouteRequest($point, $point_hint = null, $snap_prevention = null, $vehicle = null, $locale = null, $elevation = null, $details = null, $optimize = null, $instructions = null, $calc_points = null, $debug = null, $points_encoded = null, $type = null, $ch_disable = null, $weighting = null, $heading = null, $heading_penalty = null, $pass_through = null, $block_area = null, $avoid = null, $algorithm = null, $round_trip_distance = null, $round_trip_seed = null, $alternative_route_max_paths = null, $alternative_route_max_weight_factor = null, $alternative_route_max_share_factor = null)
    {
        // verify the required parameter 'point' is set
        if ($point === null || (is_array($point) && count($point) === 0)) {
            throw new \InvalidArgumentException(
                'Missing the required parameter $point when calling getRoute'
            );
        }

        $resourcePath = '/route';
        $formParams = [];
        $queryParams = [];
        $headerParams = [];
        $httpBody = '';
        $multipart = false;

        // query params
        if (is_array($point)) {
            $point = ObjectSerializer::serializeCollection($point, 'multi', true);
        }
        if ($point !== null) {
            $queryParams['point'] = ObjectSerializer::toQueryValue($point);
        }
        // query params
        if (is_array($point_hint)) {
            $point_hint = ObjectSerializer::serializeCollection($point_hint, 'multi', true);
        }
        if ($point_hint !== null) {
            $queryParams['point_hint'] = ObjectSerializer::toQueryValue($point_hint);
        }
        // query params
        if (is_array($snap_prevention)) {
            $snap_prevention = ObjectSerializer::serializeCollection($snap_prevention, 'multi', true);
        }
        if ($snap_prevention !== null) {
            $queryParams['snap_prevention'] = ObjectSerializer::toQueryValue($snap_prevention);
        }
        // query params
        if ($vehicle !== null) {
            $queryParams['vehicle'] = ObjectSerializer::toQueryValue($vehicle);
        }
        // query params
        if ($locale !== null) {
            $queryParams['locale'] = ObjectSerializer::toQueryValue($locale);
        }
        // query params
        if ($elevation !== null) {
            $queryParams['elevation'] = ObjectSerializer::toQueryValue($elevation);
        }
        // query params
        if (is_array($details)) {
            $details = ObjectSerializer::serializeCollection($details, 'multi', true);
        }
        if ($details !== null) {
            $queryParams['details'] = ObjectSerializer::toQueryValue($details);
        }
        // query params
        if ($optimize !== null) {
            $queryParams['optimize'] = ObjectSerializer::toQueryValue($optimize);
        }
        // query params
        if ($instructions !== null) {
            $queryParams['instructions'] = ObjectSerializer::toQueryValue($instructions);
        }
        // query params
        if ($calc_points !== null) {
            $queryParams['calc_points'] = ObjectSerializer::toQueryValue($calc_points);
        }
        // query params
        if ($debug !== null) {
            $queryParams['debug'] = ObjectSerializer::toQueryValue($debug);
        }
        // query params
        if ($points_encoded !== null) {
            $queryParams['points_encoded'] = ObjectSerializer::toQueryValue($points_encoded);
        }
        // query params
        if ($type !== null) {
            $queryParams['type'] = ObjectSerializer::toQueryValue($type);
        }
        // query params
        if ($ch_disable !== null) {
            $queryParams['ch.disable'] = ObjectSerializer::toQueryValue($ch_disable);
        }
        // query params
        if ($weighting !== null) {
            $queryParams['weighting'] = ObjectSerializer::toQueryValue($weighting);
        }
        // query params
        if (is_array($heading)) {
            $heading = ObjectSerializer::serializeCollection($heading, 'multi', true);
        }
        if ($heading !== null) {
            $queryParams['heading'] = ObjectSerializer::toQueryValue($heading);
        }
        // query params
        if ($heading_penalty !== null) {
            $queryParams['heading_penalty'] = ObjectSerializer::toQueryValue($heading_penalty);
        }
        // query params
        if ($pass_through !== null) {
            $queryParams['pass_through'] = ObjectSerializer::toQueryValue($pass_through);
        }
        // query params
        if ($block_area !== null) {
            $queryParams['block_area'] = ObjectSerializer::toQueryValue($block_area);
        }
        // query params
        if ($avoid !== null) {
            $queryParams['avoid'] = ObjectSerializer::toQueryValue($avoid);
        }
        // query params
        if ($algorithm !== null) {
            $queryParams['algorithm'] = ObjectSerializer::toQueryValue($algorithm);
        }
        // query params
        if ($round_trip_distance !== null) {
            $queryParams['round_trip.distance'] = ObjectSerializer::toQueryValue($round_trip_distance);
        }
        // query params
        if ($round_trip_seed !== null) {
            $queryParams['round_trip.seed'] = ObjectSerializer::toQueryValue($round_trip_seed);
        }
        // query params
        if ($alternative_route_max_paths !== null) {
            $queryParams['alternative_route.max_paths'] = ObjectSerializer::toQueryValue($alternative_route_max_paths);
        }
        // query params
        if ($alternative_route_max_weight_factor !== null) {
            $queryParams['alternative_route.max_weight_factor'] = ObjectSerializer::toQueryValue($alternative_route_max_weight_factor);
        }
        // query params
        if ($alternative_route_max_share_factor !== null) {
            $queryParams['alternative_route.max_share_factor'] = ObjectSerializer::toQueryValue($alternative_route_max_share_factor);
        }


        // body params
        $_tempBody = null;

        if ($multipart) {
            $headers = $this->headerSelector->selectHeadersForMultipart(
                ['application/json']
            );
        } else {
            $headers = $this->headerSelector->selectHeaders(
                ['application/json'],
                []
            );
        }

        // for model (json/xml)
        if (isset($_tempBody)) {
            // $_tempBody is the method argument, if present
            $httpBody = $_tempBody;
            // \stdClass has no __toString(), so we should encode it manually
            if ($httpBody instanceof \stdClass && $headers['Content-Type'] === 'application/json') {
                $httpBody = \GuzzleHttp\json_encode($httpBody);
            }
        } elseif (count($formParams) > 0) {
            if ($multipart) {
                $multipartContents = [];
                foreach ($formParams as $formParamName => $formParamValue) {
                    $multipartContents[] = [
                        'name' => $formParamName,
                        'contents' => $formParamValue
                    ];
                }
                // for HTTP post (form)
                $httpBody = new MultipartStream($multipartContents);

            } elseif ($headers['Content-Type'] === 'application/json') {
                $httpBody = \GuzzleHttp\json_encode($formParams);

            } else {
                // for HTTP post (form)
                $httpBody = \GuzzleHttp\Psr7\build_query($formParams);
            }
        }

        // this endpoint requires API key authentication
        $apiKey = $this->config->getApiKeyWithPrefix('key');
        if ($apiKey !== null) {
            $queryParams['key'] = $apiKey;
        }

        $defaultHeaders = [];
        if ($this->config->getUserAgent()) {
            $defaultHeaders['User-Agent'] = $this->config->getUserAgent();
        }

        $headers = array_merge(
            $defaultHeaders,
            $headerParams,
            $headers
        );

        $query = \GuzzleHttp\Psr7\build_query($queryParams);
        return new Request(
            'GET',
            $this->config->getHost() . $resourcePath . ($query ? "?{$query}" : ''),
            $headers,
            $httpBody
        );
    }

    /**
     * Operation routeInfoGet
     *
     * Coverage information
     *
     *
     * @throws \Swagger\Client\ApiException on non-2xx response
     * @throws \InvalidArgumentException
     * @return \Swagger\Client\Model\InfoResponse
     */
    public function routeInfoGet()
    {
        list($response) = $this->routeInfoGetWithHttpInfo();
        return $response;
    }

    /**
     * Operation routeInfoGetWithHttpInfo
     *
     * Coverage information
     *
     *
     * @throws \Swagger\Client\ApiException on non-2xx response
     * @throws \InvalidArgumentException
     * @return array of \Swagger\Client\Model\InfoResponse, HTTP status code, HTTP response headers (array of strings)
     */
    public function routeInfoGetWithHttpInfo()
    {
        $returnType = '\Swagger\Client\Model\InfoResponse';
        $request = $this->routeInfoGetRequest();

        try {
            $options = $this->createHttpClientOption();
            try {
                $response = $this->client->send($request, $options);
            } catch (RequestException $e) {
                throw new ApiException(
                    "[{$e->getCode()}] {$e->getMessage()}",
                    $e->getCode(),
                    $e->getResponse() ? $e->getResponse()->getHeaders() : null,
                    $e->getResponse() ? $e->getResponse()->getBody()->getContents() : null
                );
            }

            $statusCode = $response->getStatusCode();

            if ($statusCode < 200 || $statusCode > 299) {
                throw new ApiException(
                    sprintf(
                        '[%d] Error connecting to the API (%s)',
                        $statusCode,
                        $request->getUri()
                    ),
                    $statusCode,
                    $response->getHeaders(),
                    $response->getBody()
                );
            }

            $responseBody = $response->getBody();
            if ($returnType === '\SplFileObject') {
                $content = $responseBody; //stream goes to serializer
            } else {
                $content = $responseBody->getContents();
                if (!in_array($returnType, ['string','integer','bool'])) {
                    $content = json_decode($content);
                }
            }

            return [
                ObjectSerializer::deserialize($content, $returnType, []),
                $response->getStatusCode(),
                $response->getHeaders()
            ];

        } catch (ApiException $e) {
            switch ($e->getCode()) {
                case 200:
                    $data = ObjectSerializer::deserialize(
                        $e->getResponseBody(),
                        '\Swagger\Client\Model\InfoResponse',
                        $e->getResponseHeaders()
                    );
                    $e->setResponseObject($data);
                    break;
            }
            throw $e;
        }
    }

    /**
     * Operation routeInfoGetAsync
     *
     * Coverage information
     *
     *
     * @throws \InvalidArgumentException
     * @return \GuzzleHttp\Promise\PromiseInterface
     */
    public function routeInfoGetAsync()
    {
        return $this->routeInfoGetAsyncWithHttpInfo()
            ->then(
                function ($response) {
                    return $response[0];
                }
            );
    }

    /**
     * Operation routeInfoGetAsyncWithHttpInfo
     *
     * Coverage information
     *
     *
     * @throws \InvalidArgumentException
     * @return \GuzzleHttp\Promise\PromiseInterface
     */
    public function routeInfoGetAsyncWithHttpInfo()
    {
        $returnType = '\Swagger\Client\Model\InfoResponse';
        $request = $this->routeInfoGetRequest();

        return $this->client
            ->sendAsync($request, $this->createHttpClientOption())
            ->then(
                function ($response) use ($returnType) {
                    $responseBody = $response->getBody();
                    if ($returnType === '\SplFileObject') {
                        $content = $responseBody; //stream goes to serializer
                    } else {
                        $content = $responseBody->getContents();
                        if ($returnType !== 'string') {
                            $content = json_decode($content);
                        }
                    }

                    return [
                        ObjectSerializer::deserialize($content, $returnType, []),
                        $response->getStatusCode(),
                        $response->getHeaders()
                    ];
                },
                function ($exception) {
                    $response = $exception->getResponse();
                    $statusCode = $response->getStatusCode();
                    throw new ApiException(
                        sprintf(
                            '[%d] Error connecting to the API (%s)',
                            $statusCode,
                            $exception->getRequest()->getUri()
                        ),
                        $statusCode,
                        $response->getHeaders(),
                        $response->getBody()
                    );
                }
            );
    }

    /**
     * Create request for operation 'routeInfoGet'
     *
     *
     * @throws \InvalidArgumentException
     * @return \GuzzleHttp\Psr7\Request
     */
    protected function routeInfoGetRequest()
    {

        $resourcePath = '/route/info';
        $formParams = [];
        $queryParams = [];
        $headerParams = [];
        $httpBody = '';
        $multipart = false;



        // body params
        $_tempBody = null;

        if ($multipart) {
            $headers = $this->headerSelector->selectHeadersForMultipart(
                ['application/json']
            );
        } else {
            $headers = $this->headerSelector->selectHeaders(
                ['application/json'],
                []
            );
        }

        // for model (json/xml)
        if (isset($_tempBody)) {
            // $_tempBody is the method argument, if present
            $httpBody = $_tempBody;
            // \stdClass has no __toString(), so we should encode it manually
            if ($httpBody instanceof \stdClass && $headers['Content-Type'] === 'application/json') {
                $httpBody = \GuzzleHttp\json_encode($httpBody);
            }
        } elseif (count($formParams) > 0) {
            if ($multipart) {
                $multipartContents = [];
                foreach ($formParams as $formParamName => $formParamValue) {
                    $multipartContents[] = [
                        'name' => $formParamName,
                        'contents' => $formParamValue
                    ];
                }
                // for HTTP post (form)
                $httpBody = new MultipartStream($multipartContents);

            } elseif ($headers['Content-Type'] === 'application/json') {
                $httpBody = \GuzzleHttp\json_encode($formParams);

            } else {
                // for HTTP post (form)
                $httpBody = \GuzzleHttp\Psr7\build_query($formParams);
            }
        }

        // this endpoint requires API key authentication
        $apiKey = $this->config->getApiKeyWithPrefix('key');
        if ($apiKey !== null) {
            $queryParams['key'] = $apiKey;
        }

        $defaultHeaders = [];
        if ($this->config->getUserAgent()) {
            $defaultHeaders['User-Agent'] = $this->config->getUserAgent();
        }

        $headers = array_merge(
            $defaultHeaders,
            $headerParams,
            $headers
        );

        $query = \GuzzleHttp\Psr7\build_query($queryParams);
        return new Request(
            'GET',
            $this->config->getHost() . $resourcePath . ($query ? "?{$query}" : ''),
            $headers,
            $httpBody
        );
    }

    /**
     * Create http client option
     *
     * @throws \RuntimeException on file opening failure
     * @return array of http client options
     */
    protected function createHttpClientOption()
    {
        $options = [];
        if ($this->config->getDebug()) {
            $options[RequestOptions::DEBUG] = fopen($this->config->getDebugFile(), 'a');
            if (!$options[RequestOptions::DEBUG]) {
                throw new \RuntimeException('Failed to open the debug file: ' . $this->config->getDebugFile());
            }
        }

        return $options;
    }
}
