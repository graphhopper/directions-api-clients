/*
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

package com.graphhopper.directions.api.client.model;

import java.util.Objects;
import java.util.Arrays;
import com.google.gson.TypeAdapter;
import com.google.gson.annotations.JsonAdapter;
import com.google.gson.annotations.SerializedName;
import com.google.gson.stream.JsonReader;
import com.google.gson.stream.JsonWriter;
import com.graphhopper.directions.api.client.model.RouteResponsePathInstructions;
import io.swagger.v3.oas.annotations.media.Schema;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
/**
 * RouteResponsePath
 */


public class RouteResponsePath {
  @SerializedName("distance")
  private Double distance = null;

  @SerializedName("time")
  private Long time = null;

  @SerializedName("ascend")
  private Double ascend = null;

  @SerializedName("descend")
  private Double descend = null;

  @SerializedName("points")
  private Object points = null;

  @SerializedName("snapped_waypoints")
  private Object snappedWaypoints = null;

  @SerializedName("points_encoded")
  private Boolean pointsEncoded = null;

  @SerializedName("bbox")
  private List<Double> bbox = null;

  @SerializedName("instructions")
  private List<RouteResponsePathInstructions> instructions = null;

  @SerializedName("details")
  private Object details = null;

  @SerializedName("points_order")
  private List<Integer> pointsOrder = null;

  public RouteResponsePath distance(Double distance) {
    this.distance = distance;
    return this;
  }

   /**
   * The total distance, in meters. 
   * @return distance
  **/
  @Schema(description = "The total distance, in meters. ")
  public Double getDistance() {
    return distance;
  }

  public void setDistance(Double distance) {
    this.distance = distance;
  }

  public RouteResponsePath time(Long time) {
    this.time = time;
    return this;
  }

   /**
   * The total travel time, in milliseconds. 
   * @return time
  **/
  @Schema(description = "The total travel time, in milliseconds. ")
  public Long getTime() {
    return time;
  }

  public void setTime(Long time) {
    this.time = time;
  }

  public RouteResponsePath ascend(Double ascend) {
    this.ascend = ascend;
    return this;
  }

   /**
   * The total ascent, in meters. 
   * @return ascend
  **/
  @Schema(description = "The total ascent, in meters. ")
  public Double getAscend() {
    return ascend;
  }

  public void setAscend(Double ascend) {
    this.ascend = ascend;
  }

  public RouteResponsePath descend(Double descend) {
    this.descend = descend;
    return this;
  }

   /**
   * The total descent, in meters. 
   * @return descend
  **/
  @Schema(description = "The total descent, in meters. ")
  public Double getDescend() {
    return descend;
  }

  public void setDescend(Double descend) {
    this.descend = descend;
  }

  public RouteResponsePath points(Object points) {
    this.points = points;
    return this;
  }

   /**
   * Get points
   * @return points
  **/
  @Schema(description = "")
  public Object getPoints() {
    return points;
  }

  public void setPoints(Object points) {
    this.points = points;
  }

  public RouteResponsePath snappedWaypoints(Object snappedWaypoints) {
    this.snappedWaypoints = snappedWaypoints;
    return this;
  }

   /**
   * Get snappedWaypoints
   * @return snappedWaypoints
  **/
  @Schema(description = "")
  public Object getSnappedWaypoints() {
    return snappedWaypoints;
  }

  public void setSnappedWaypoints(Object snappedWaypoints) {
    this.snappedWaypoints = snappedWaypoints;
  }

  public RouteResponsePath pointsEncoded(Boolean pointsEncoded) {
    this.pointsEncoded = pointsEncoded;
    return this;
  }

   /**
   * Whether the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields are encoded strings rather than GeoJSON LineStrings. 
   * @return pointsEncoded
  **/
  @Schema(description = "Whether the `points` and `snapped_waypoints` fields are encoded strings rather than GeoJSON LineStrings. ")
  public Boolean isPointsEncoded() {
    return pointsEncoded;
  }

  public void setPointsEncoded(Boolean pointsEncoded) {
    this.pointsEncoded = pointsEncoded;
  }

  public RouteResponsePath bbox(List<Double> bbox) {
    this.bbox = bbox;
    return this;
  }

  public RouteResponsePath addBboxItem(Double bboxItem) {
    if (this.bbox == null) {
      this.bbox = new ArrayList<Double>();
    }
    this.bbox.add(bboxItem);
    return this;
  }

   /**
   * The bounding box of the route geometry. Format: &#x60;[minLon, minLat, maxLon, maxLat]&#x60;. 
   * @return bbox
  **/
  @Schema(description = "The bounding box of the route geometry. Format: `[minLon, minLat, maxLon, maxLat]`. ")
  public List<Double> getBbox() {
    return bbox;
  }

  public void setBbox(List<Double> bbox) {
    this.bbox = bbox;
  }

  public RouteResponsePath instructions(List<RouteResponsePathInstructions> instructions) {
    this.instructions = instructions;
    return this;
  }

  public RouteResponsePath addInstructionsItem(RouteResponsePathInstructions instructionsItem) {
    if (this.instructions == null) {
      this.instructions = new ArrayList<RouteResponsePathInstructions>();
    }
    this.instructions.add(instructionsItem);
    return this;
  }

   /**
   * The instructions for this route. This feature is under active development, and our instructions can sometimes be misleading, so be mindful when using them for navigation. 
   * @return instructions
  **/
  @Schema(description = "The instructions for this route. This feature is under active development, and our instructions can sometimes be misleading, so be mindful when using them for navigation. ")
  public List<RouteResponsePathInstructions> getInstructions() {
    return instructions;
  }

  public void setInstructions(List<RouteResponsePathInstructions> instructions) {
    this.instructions = instructions;
  }

  public RouteResponsePath details(Object details) {
    this.details = details;
    return this;
  }

   /**
   * Details, as requested with the &#x60;details&#x60; parameter. Consider the value &#x60;{\&quot;street_name\&quot;: [[0,2,\&quot;Frankfurter Straße\&quot;],[2,6,\&quot;Zollweg\&quot;]]}&#x60;. In this example, the route uses two streets: The first, Frankfurter Straße, is used between &#x60;points[0]&#x60; and &#x60;points[2]&#x60;, and the second, Zollweg, between &#x60;points[2]&#x60; and &#x60;points[6]&#x60;. See [here](https://discuss.graphhopper.com/t/2539) for discussion. 
   * @return details
  **/
  @Schema(description = "Details, as requested with the `details` parameter. Consider the value `{\"street_name\": [[0,2,\"Frankfurter Straße\"],[2,6,\"Zollweg\"]]}`. In this example, the route uses two streets: The first, Frankfurter Straße, is used between `points[0]` and `points[2]`, and the second, Zollweg, between `points[2]` and `points[6]`. See [here](https://discuss.graphhopper.com/t/2539) for discussion. ")
  public Object getDetails() {
    return details;
  }

  public void setDetails(Object details) {
    this.details = details;
  }

  public RouteResponsePath pointsOrder(List<Integer> pointsOrder) {
    this.pointsOrder = pointsOrder;
    return this;
  }

  public RouteResponsePath addPointsOrderItem(Integer pointsOrderItem) {
    if (this.pointsOrder == null) {
      this.pointsOrder = new ArrayList<Integer>();
    }
    this.pointsOrder.add(pointsOrderItem);
    return this;
  }

   /**
   * An array of indices (zero-based), specifiying the order in which the input points are visited. Only present if the &#x60;optimize&#x60; parameter was used. 
   * @return pointsOrder
  **/
  @Schema(description = "An array of indices (zero-based), specifiying the order in which the input points are visited. Only present if the `optimize` parameter was used. ")
  public List<Integer> getPointsOrder() {
    return pointsOrder;
  }

  public void setPointsOrder(List<Integer> pointsOrder) {
    this.pointsOrder = pointsOrder;
  }


  @Override
  public boolean equals(java.lang.Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }
    RouteResponsePath routeResponsePath = (RouteResponsePath) o;
    return Objects.equals(this.distance, routeResponsePath.distance) &&
        Objects.equals(this.time, routeResponsePath.time) &&
        Objects.equals(this.ascend, routeResponsePath.ascend) &&
        Objects.equals(this.descend, routeResponsePath.descend) &&
        Objects.equals(this.points, routeResponsePath.points) &&
        Objects.equals(this.snappedWaypoints, routeResponsePath.snappedWaypoints) &&
        Objects.equals(this.pointsEncoded, routeResponsePath.pointsEncoded) &&
        Objects.equals(this.bbox, routeResponsePath.bbox) &&
        Objects.equals(this.instructions, routeResponsePath.instructions) &&
        Objects.equals(this.details, routeResponsePath.details) &&
        Objects.equals(this.pointsOrder, routeResponsePath.pointsOrder);
  }

  @Override
  public int hashCode() {
    return Objects.hash(distance, time, ascend, descend, points, snappedWaypoints, pointsEncoded, bbox, instructions, details, pointsOrder);
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class RouteResponsePath {\n");
    
    sb.append("    distance: ").append(toIndentedString(distance)).append("\n");
    sb.append("    time: ").append(toIndentedString(time)).append("\n");
    sb.append("    ascend: ").append(toIndentedString(ascend)).append("\n");
    sb.append("    descend: ").append(toIndentedString(descend)).append("\n");
    sb.append("    points: ").append(toIndentedString(points)).append("\n");
    sb.append("    snappedWaypoints: ").append(toIndentedString(snappedWaypoints)).append("\n");
    sb.append("    pointsEncoded: ").append(toIndentedString(pointsEncoded)).append("\n");
    sb.append("    bbox: ").append(toIndentedString(bbox)).append("\n");
    sb.append("    instructions: ").append(toIndentedString(instructions)).append("\n");
    sb.append("    details: ").append(toIndentedString(details)).append("\n");
    sb.append("    pointsOrder: ").append(toIndentedString(pointsOrder)).append("\n");
    sb.append("}");
    return sb.toString();
  }

  /**
   * Convert the given object to string with each line indented by 4 spaces
   * (except the first line).
   */
  private String toIndentedString(java.lang.Object o) {
    if (o == null) {
      return "null";
    }
    return o.toString().replace("\n", "\n    ");
  }

}
