/**
 * GraphHopper Directions API
 *  With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Clients  To speed up development and make coding easier, we offer the following clients:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions for motor vehicles such as `car` or `truck` are only considered with `edge_based=true` for the Routing (other APIs will follow).** Or if you already use `ch.disable=true` no additional parameter is required to consider turn restrictions for motor vehicles.  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) 
 *
 * OpenAPI spec version: 1.0.0
 * Contact: support@graphhopper.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

package io.swagger.client.api

import java.text.SimpleDateFormat

import java.math.BigDecimal
import io.swagger.client.model.GHError
import io.swagger.client.model.InfoResponse
import io.swagger.client.model.RouteResponse
import io.swagger.client.model.VehicleProfileId
import io.swagger.client.{ApiInvoker, ApiException}

import com.sun.jersey.multipart.FormDataMultiPart
import com.sun.jersey.multipart.file.FileDataBodyPart

import javax.ws.rs.core.MediaType

import java.io.File
import java.util.Date
import java.util.TimeZone

import scala.collection.mutable.HashMap

import com.wordnik.swagger.client._
import scala.concurrent.Future
import collection.mutable

import java.net.URI

import com.wordnik.swagger.client.ClientResponseReaders.Json4sFormatsReader._
import com.wordnik.swagger.client.RequestWriters.Json4sFormatsWriter._

import scala.concurrent.ExecutionContext.Implicits.global
import scala.concurrent._
import scala.concurrent.duration._
import scala.util.{Failure, Success, Try}

import org.json4s._

class RoutingApi(
  val defBasePath: String = "https://graphhopper.com/api/1",
  defApiInvoker: ApiInvoker = ApiInvoker
) {
  private lazy val dateTimeFormatter = {
    val formatter = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSSZ")
    formatter.setTimeZone(TimeZone.getTimeZone("UTC"))
    formatter
  }
  private val dateFormatter = {
    val formatter = new SimpleDateFormat("yyyy-MM-dd")
    formatter.setTimeZone(TimeZone.getTimeZone("UTC"))
    formatter
  }
  implicit val formats = new org.json4s.DefaultFormats {
    override def dateFormatter = dateTimeFormatter
  }
  implicit val stringReader: ClientResponseReader[String] = ClientResponseReaders.StringReader
  implicit val unitReader: ClientResponseReader[Unit] = ClientResponseReaders.UnitReader
  implicit val jvalueReader: ClientResponseReader[JValue] = ClientResponseReaders.JValueReader
  implicit val jsonReader: ClientResponseReader[Nothing] = JsonFormatsReader
  implicit val stringWriter: RequestWriter[String] = RequestWriters.StringWriter
  implicit val jsonWriter: RequestWriter[Nothing] = JsonFormatsWriter

  var basePath: String = defBasePath
  var apiInvoker: ApiInvoker = defApiInvoker

  def addHeader(key: String, value: String): mutable.HashMap[String, String] = {
    apiInvoker.defaultHeaders += key -> value
  }

  val config: SwaggerConfig = SwaggerConfig.forUrl(new URI(defBasePath))
  val client = new RestClient(config)
  val helper = new RoutingApiAsyncHelper(client, config)

  /**
   * Execute a routing request
   * ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#39;&#39;best&#39;&#39; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
   *
   * @param point The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan.  
   * @param pointHint The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)
   * @param snapPrevention Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)
   * @param vehicle The vehicle profile for which the route should be calculated.  (optional)
   * @param locale The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)
   * @param elevation If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)
   * @param details Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)
   * @param optimize Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)
   * @param instructions If instructions should be calculated and returned  (optional)
   * @param calcPoints If the points for the route should be calculated at all.  (optional)
   * @param debug If &#x60;true&#x60;, the output will be formatted.  (optional)
   * @param pointsEncoded If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#39;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)
   * @param `type` Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)
   * @param chDisable Use this parameter in combination with one or more parameters from below.  (optional)
   * @param weighting Determines the way the &#39;&#39;best&#39;&#39; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param headingPenalty Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param passThrough If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param blockArea Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param avoid Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param algorithm Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param roundTripDistance If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param roundTripSeed If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)
   * @param alternativeRouteMaxPaths If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)
   * @param alternativeRouteMaxWeightFactor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)
   * @param alternativeRouteMaxShareFactor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)
   * @return RouteResponse
   */
  def getRoute(point: List[String], pointHint: Option[List[String]] = None, snapPrevention: Option[List[String]] = None, vehicle: Option[VehicleProfileId] = None, locale: Option[String] = None, elevation: Option[Boolean] = None, details: Option[List[String]] = None, optimize: Option[Boolean] = None, instructions: Option[Boolean] = None, calcPoints: Option[Boolean] = None, debug: Option[Boolean] = None, pointsEncoded: Option[Boolean] = None, `type`: Option[String] = None, chDisable: Option[Boolean] = None, weighting: Option[String] = None, heading: Option[List[Integer]] = None, headingPenalty: Option[Integer] = None, passThrough: Option[Boolean] = None, blockArea: Option[String] = None, avoid: Option[String] = None, algorithm: Option[String] = None, roundTripDistance: Option[Integer] = None, roundTripSeed: Option[Long] = None, alternativeRouteMaxPaths: Option[Integer] = None, alternativeRouteMaxWeightFactor: Option[BigDecimal] = None, alternativeRouteMaxShareFactor: Option[BigDecimal] = None): Option[RouteResponse] = {
    val await = Try(Await.result(getRouteAsync(point, pointHint, snapPrevention, vehicle, locale, elevation, details, optimize, instructions, calcPoints, debug, pointsEncoded, `type`, chDisable, weighting, heading, headingPenalty, passThrough, blockArea, avoid, algorithm, roundTripDistance, roundTripSeed, alternativeRouteMaxPaths, alternativeRouteMaxWeightFactor, alternativeRouteMaxShareFactor), Duration.Inf))
    await match {
      case Success(i) => Some(await.get)
      case Failure(t) => None
    }
  }

  /**
   * Execute a routing request asynchronously
   * ### Introduction  ![Routing screenshot](./img/routing-example.png)  The Routing is part of the GraphHopper Directions API. Routing is the process of finding the best path connecting two or more points, where the meaning of &#39;&#39;best&#39;&#39; depends on the vehicle and use case.  ### Navigation If you plan to use the Routing for navigation, have a look at our [open source demo navigation application](https://github.com/graphhopper/graphhopper-navigation-example) and adapt it to your needs.  ### Fast To get started using this API, just provide two or more points and retrieve the fastest route through the road network that connects them. This type of request is heavily optimized for query performance, so it does not take turn restrictions into account, and it does not allow for some advanced features. ### Flexible Enable turn restrictions and unlock further flexible features via &#x60;ch.disable&#x3D;true&#x60;. Please note that some options make the request more expensive, see the [FAQ](https://graphhopper.com/api/1/docs/FAQ/) for more details. 
   *
   * @param point The points for which the route should be calculated. Format: &#x60;[latitude,longitude]&#x60;. Specify at least an origin and a destination. Via points are possible. The maximum number depends on your plan.  
   * @param pointHint The point_hint is typically a road name to which the associated &#x60;point&#x60; parameter should be snapped to. Specify no &#x60;point_hint&#x60; parameter or the same number as you have &#x60;point&#x60; parameters.  (optional)
   * @param snapPrevention Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  (optional)
   * @param vehicle The vehicle profile for which the route should be calculated.  (optional)
   * @param locale The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German.  (optional)
   * @param elevation If &#x60;true&#x60;, a third coordinate, the altitude, is included to all positions in the response. This changes the format of the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields of the response, in both their encodings. Unless you switch off the &#x60;points_encoded&#x60; parameter, you need special code on the client side that can handle triple coordinates. A request can fail if the vehicle profile does not support elevation. See the features object for every vehicle profile.  (optional)
   * @param details Optional parameter to retrieve path details. You can request additional details for the route: &#x60;street_name&#x60; and &#x60;time&#x60;. For all motor vehicle profiles, we additionally support &#x60;max_speed&#x60;, &#x60;toll&#x60;, &#x60;road_class&#x60;, &#x60;road_environment&#x60;, and &#x60;surface&#x60;.  (optional)
   * @param optimize Normally, the calculated route will visit the points in the order you specified them. If you have more than two points, you can set this parameter to &#x60;true&#x60; and the points may be re-ordered to minimize the total travel time. Keep in mind that the limits on the number of locations of the Route Optimization applies, and the request is more expensive.  (optional)
   * @param instructions If instructions should be calculated and returned  (optional)
   * @param calcPoints If the points for the route should be calculated at all.  (optional)
   * @param debug If &#x60;true&#x60;, the output will be formatted.  (optional)
   * @param pointsEncoded If &#x60;false&#x60;, the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as lists of positions using the order &#x60;[lon,lat,elevation]&#x60;. This format may be easier to handle, but can consume a lot of bandwidth for long routes. If &#x60;true&#x60;, the coordinates will be encoded as a string. You&#39;ll need to decode this string in client code. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/e649aaed8d3f4378bf2d8889bbbc2318261eabb2/web-api/src/main/java/com/graphhopper/http/WebHelper.java#L54) and [JavaScript](https://github.com/graphhopper/directions-api-js-client/blob/cf43d1a5bc93a3e8007a44fcfc551117e4fa49bc/src/GHUtil.js#L27).  (optional)
   * @param `type` Specifies the media type for the response. For &#x60;json&#x60;, it will be &#x60;application/json&#x60;. For &#x60;gpx&#x60;, it will be &#x60;application/gpx+xml&#x60;.  (optional)
   * @param chDisable Use this parameter in combination with one or more parameters from below.  (optional)
   * @param weighting Determines the way the &#39;&#39;best&#39;&#39; route is calculated. Default is &#x60;fastest&#x60;. Other options are &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;) and &#x60;short_fastest&#x60; which finds a reasonable balance between &#x60;shortest&#x60; and &#x60;fastest&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and forces the initial direction.  Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param headingPenalty Time penalty in seconds for not obeying a specified heading. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param passThrough If &#x60;true&#x60;, u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param blockArea Block road access via a point with the format &#x60;latitude,longitude&#x60; or an area defined by a circle &#x60;lat,lon,radius&#x60; or a rectangle &#x60;lat1,lon1,lat2,lon2&#x60;. Separate several values with &#x60;;&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param avoid Specify which road classes and environments you would like to avoid.  Possible values are &#x60;motorway&#x60;, &#x60;primary&#x60;, &#x60;secondary&#x60;, &#x60;tertiary&#x60;, &#x60;trunk&#x60;, &#x60;residential&#x60;, &#x60;steps&#x60;, &#x60;living_street&#x60;, &#x60;track&#x60;, &#x60;toll&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Separate several values with &#x60;;&#x60;. Obviously not all the values make sense for all vehicle profiles e.g. &#x60;bike&#x60; is already forbidden on a &#x60;motorway&#x60;. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param algorithm Rather than looking for the shortest or fastest path, this lets you solve two different problems related to routing: With &#x60;round_trip&#x60;, the route will get you back to where you started. This is meant for fun (think of a bike trip), so we will add some randomness. With &#x60;alternative_route&#x60;, we give you not one but several routes that are close to optimal, but not too similar to each other. You can control both of these features with additional parameters, see below. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param roundTripDistance If &#x60;algorithm&#x3D;round_trip&#x60;, this parameter configures approximative length of the resulting round trip. Requires &#x60;ch.disable&#x3D;true&#x60;.  (optional)
   * @param roundTripSeed If &#x60;algorithm&#x3D;round_trip&#x60;, this sets the random seed. Change this to get a different tour for each value.  (optional)
   * @param alternativeRouteMaxPaths If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.  (optional)
   * @param alternativeRouteMaxWeightFactor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.  (optional)
   * @param alternativeRouteMaxShareFactor If &#x60;algorithm&#x3D;alternative_route&#x60;, this parameter specifies how similar an alternative route can be to the optimal route. Increasing can lead to worse alternatives.  (optional)
   * @return Future(RouteResponse)
   */
  def getRouteAsync(point: List[String], pointHint: Option[List[String]] = None, snapPrevention: Option[List[String]] = None, vehicle: Option[VehicleProfileId] = None, locale: Option[String] = None, elevation: Option[Boolean] = None, details: Option[List[String]] = None, optimize: Option[Boolean] = None, instructions: Option[Boolean] = None, calcPoints: Option[Boolean] = None, debug: Option[Boolean] = None, pointsEncoded: Option[Boolean] = None, `type`: Option[String] = None, chDisable: Option[Boolean] = None, weighting: Option[String] = None, heading: Option[List[Integer]] = None, headingPenalty: Option[Integer] = None, passThrough: Option[Boolean] = None, blockArea: Option[String] = None, avoid: Option[String] = None, algorithm: Option[String] = None, roundTripDistance: Option[Integer] = None, roundTripSeed: Option[Long] = None, alternativeRouteMaxPaths: Option[Integer] = None, alternativeRouteMaxWeightFactor: Option[BigDecimal] = None, alternativeRouteMaxShareFactor: Option[BigDecimal] = None): Future[RouteResponse] = {
      helper.getRoute(point, pointHint, snapPrevention, vehicle, locale, elevation, details, optimize, instructions, calcPoints, debug, pointsEncoded, `type`, chDisable, weighting, heading, headingPenalty, passThrough, blockArea, avoid, algorithm, roundTripDistance, roundTripSeed, alternativeRouteMaxPaths, alternativeRouteMaxWeightFactor, alternativeRouteMaxShareFactor)
  }

  /**
   * Coverage information
   * Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
   *
   * @return InfoResponse
   */
  def routeInfoGet(): Option[InfoResponse] = {
    val await = Try(Await.result(routeInfoGetAsync(), Duration.Inf))
    await match {
      case Success(i) => Some(await.get)
      case Failure(t) => None
    }
  }

  /**
   * Coverage information asynchronously
   * Use this to find out details about the supported vehicle profiles and features, or if you just need to ping the server. 
   *
   * @return Future(InfoResponse)
   */
  def routeInfoGetAsync(): Future[InfoResponse] = {
      helper.routeInfoGet()
  }

}

class RoutingApiAsyncHelper(client: TransportClient, config: SwaggerConfig) extends ApiClient(client, config) {

  def getRoute(point: List[String],
    pointHint: Option[List[String]] = None,
    snapPrevention: Option[List[String]] = None,
    vehicle: Option[VehicleProfileId] = None,
    locale: Option[String] = None,
    elevation: Option[Boolean] = None,
    details: Option[List[String]] = None,
    optimize: Option[Boolean] = None,
    instructions: Option[Boolean] = None,
    calcPoints: Option[Boolean] = None,
    debug: Option[Boolean] = None,
    pointsEncoded: Option[Boolean] = None,
    `type`: Option[String] = None,
    chDisable: Option[Boolean] = None,
    weighting: Option[String] = None,
    heading: Option[List[Integer]] = None,
    headingPenalty: Option[Integer] = None,
    passThrough: Option[Boolean] = None,
    blockArea: Option[String] = None,
    avoid: Option[String] = None,
    algorithm: Option[String] = None,
    roundTripDistance: Option[Integer] = None,
    roundTripSeed: Option[Long] = None,
    alternativeRouteMaxPaths: Option[Integer] = None,
    alternativeRouteMaxWeightFactor: Option[BigDecimal] = None,
    alternativeRouteMaxShareFactor: Option[BigDecimal] = None
    )(implicit reader: ClientResponseReader[RouteResponse]): Future[RouteResponse] = {
    // create path and map variables
    val path = (addFmt("/route"))

    // query params
    val queryParams = new mutable.HashMap[String, String]
    val headerParams = new mutable.HashMap[String, String]

    if (point == null) throw new Exception("Missing required parameter 'point' when calling RoutingApi->getRoute")
    queryParams += "point" -> point.toString
    pointHint match {
      case Some(param) => queryParams += "point_hint" -> param.toString
      case _ => queryParams
    }
    snapPrevention match {
      case Some(param) => queryParams += "snap_prevention" -> param.toString
      case _ => queryParams
    }
    vehicle match {
      case Some(param) => queryParams += "vehicle" -> param.toString
      case _ => queryParams
    }
    locale match {
      case Some(param) => queryParams += "locale" -> param.toString
      case _ => queryParams
    }
    elevation match {
      case Some(param) => queryParams += "elevation" -> param.toString
      case _ => queryParams
    }
    details match {
      case Some(param) => queryParams += "details" -> param.toString
      case _ => queryParams
    }
    optimize match {
      case Some(param) => queryParams += "optimize" -> param.toString
      case _ => queryParams
    }
    instructions match {
      case Some(param) => queryParams += "instructions" -> param.toString
      case _ => queryParams
    }
    calcPoints match {
      case Some(param) => queryParams += "calc_points" -> param.toString
      case _ => queryParams
    }
    debug match {
      case Some(param) => queryParams += "debug" -> param.toString
      case _ => queryParams
    }
    pointsEncoded match {
      case Some(param) => queryParams += "points_encoded" -> param.toString
      case _ => queryParams
    }
    `type` match {
      case Some(param) => queryParams += "type" -> param.toString
      case _ => queryParams
    }
    chDisable match {
      case Some(param) => queryParams += "ch.disable" -> param.toString
      case _ => queryParams
    }
    weighting match {
      case Some(param) => queryParams += "weighting" -> param.toString
      case _ => queryParams
    }
    heading match {
      case Some(param) => queryParams += "heading" -> param.toString
      case _ => queryParams
    }
    headingPenalty match {
      case Some(param) => queryParams += "heading_penalty" -> param.toString
      case _ => queryParams
    }
    passThrough match {
      case Some(param) => queryParams += "pass_through" -> param.toString
      case _ => queryParams
    }
    blockArea match {
      case Some(param) => queryParams += "block_area" -> param.toString
      case _ => queryParams
    }
    avoid match {
      case Some(param) => queryParams += "avoid" -> param.toString
      case _ => queryParams
    }
    algorithm match {
      case Some(param) => queryParams += "algorithm" -> param.toString
      case _ => queryParams
    }
    roundTripDistance match {
      case Some(param) => queryParams += "round_trip.distance" -> param.toString
      case _ => queryParams
    }
    roundTripSeed match {
      case Some(param) => queryParams += "round_trip.seed" -> param.toString
      case _ => queryParams
    }
    alternativeRouteMaxPaths match {
      case Some(param) => queryParams += "alternative_route.max_paths" -> param.toString
      case _ => queryParams
    }
    alternativeRouteMaxWeightFactor match {
      case Some(param) => queryParams += "alternative_route.max_weight_factor" -> param.toString
      case _ => queryParams
    }
    alternativeRouteMaxShareFactor match {
      case Some(param) => queryParams += "alternative_route.max_share_factor" -> param.toString
      case _ => queryParams
    }

    val resFuture = client.submit("GET", path, queryParams.toMap, headerParams.toMap, "")
    resFuture flatMap { resp =>
      process(reader.read(resp))
    }
  }

  def routeInfoGet()(implicit reader: ClientResponseReader[InfoResponse]): Future[InfoResponse] = {
    // create path and map variables
    val path = (addFmt("/route/info"))

    // query params
    val queryParams = new mutable.HashMap[String, String]
    val headerParams = new mutable.HashMap[String, String]


    val resFuture = client.submit("GET", path, queryParams.toMap, headerParams.toMap, "")
    resFuture flatMap { resp =>
      process(reader.read(resp))
    }
  }


}
