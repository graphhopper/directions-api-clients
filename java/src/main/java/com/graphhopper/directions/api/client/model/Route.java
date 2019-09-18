/*
 * GraphHopper Directions API
 *  With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Client Libraries  To speed up development and make coding easier, we offer the following client libraries:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions are considered only with `ch.disable=true`.**  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) 
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
import com.graphhopper.directions.api.client.model.Activity;
import com.graphhopper.directions.api.client.model.RoutePoint;
import io.swagger.v3.oas.annotations.media.Schema;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
/**
 * Route
 */


public class Route {
  @SerializedName("vehicle_id")
  private String vehicleId = null;

  @SerializedName("distance")
  private Long distance = null;

  @SerializedName("transport_time")
  private Long transportTime = null;

  @SerializedName("completion_time")
  private Long completionTime = null;

  @SerializedName("waiting_time")
  private Long waitingTime = null;

  @SerializedName("service_duration")
  private Long serviceDuration = null;

  @SerializedName("preparation_time")
  private Long preparationTime = null;

  @SerializedName("activities")
  private List<Activity> activities = null;

  @SerializedName("points")
  private List<RoutePoint> points = null;

  public Route vehicleId(String vehicleId) {
    this.vehicleId = vehicleId;
    return this;
  }

   /**
   * Id of vehicle that operates route
   * @return vehicleId
  **/
  @Schema(example = "driver-stefan", description = "Id of vehicle that operates route")
  public String getVehicleId() {
    return vehicleId;
  }

  public void setVehicleId(String vehicleId) {
    this.vehicleId = vehicleId;
  }

  public Route distance(Long distance) {
    this.distance = distance;
    return this;
  }

   /**
   * Distance of route in meter
   * @return distance
  **/
  @Schema(example = "10000", description = "Distance of route in meter")
  public Long getDistance() {
    return distance;
  }

  public void setDistance(Long distance) {
    this.distance = distance;
  }

  public Route transportTime(Long transportTime) {
    this.transportTime = transportTime;
    return this;
  }

   /**
   * Transport time of route in seconds
   * @return transportTime
  **/
  @Schema(example = "1800", description = "Transport time of route in seconds")
  public Long getTransportTime() {
    return transportTime;
  }

  public void setTransportTime(Long transportTime) {
    this.transportTime = transportTime;
  }

  public Route completionTime(Long completionTime) {
    this.completionTime = completionTime;
    return this;
  }

   /**
   * Completion time of route in seconds
   * @return completionTime
  **/
  @Schema(example = "1800", description = "Completion time of route in seconds")
  public Long getCompletionTime() {
    return completionTime;
  }

  public void setCompletionTime(Long completionTime) {
    this.completionTime = completionTime;
  }

  public Route waitingTime(Long waitingTime) {
    this.waitingTime = waitingTime;
    return this;
  }

   /**
   * Waiting time of route in seconds
   * @return waitingTime
  **/
  @Schema(description = "Waiting time of route in seconds")
  public Long getWaitingTime() {
    return waitingTime;
  }

  public void setWaitingTime(Long waitingTime) {
    this.waitingTime = waitingTime;
  }

  public Route serviceDuration(Long serviceDuration) {
    this.serviceDuration = serviceDuration;
    return this;
  }

   /**
   * Service duration of route in seconds
   * @return serviceDuration
  **/
  @Schema(description = "Service duration of route in seconds")
  public Long getServiceDuration() {
    return serviceDuration;
  }

  public void setServiceDuration(Long serviceDuration) {
    this.serviceDuration = serviceDuration;
  }

  public Route preparationTime(Long preparationTime) {
    this.preparationTime = preparationTime;
    return this;
  }

   /**
   * Preparation time of route in seconds
   * @return preparationTime
  **/
  @Schema(description = "Preparation time of route in seconds")
  public Long getPreparationTime() {
    return preparationTime;
  }

  public void setPreparationTime(Long preparationTime) {
    this.preparationTime = preparationTime;
  }

  public Route activities(List<Activity> activities) {
    this.activities = activities;
    return this;
  }

  public Route addActivitiesItem(Activity activitiesItem) {
    if (this.activities == null) {
      this.activities = new ArrayList<Activity>();
    }
    this.activities.add(activitiesItem);
    return this;
  }

   /**
   * Array of activities
   * @return activities
  **/
  @Schema(example = "[{\"type\":\"start\",\"location_id\":\"berlin\",\"address\":{\"location_id\":\"berlin\",\"lat\":52.537,\"lon\":13.406},\"end_time\":1551122400,\"end_date_time\":\"2019-02-25T20:20+01:00\",\"distance\":0,\"driving_time\":0,\"preparation_time\":0,\"waiting_time\":0,\"load_after\":[0]},{\"type\":\"service\",\"id\":\"berlin-2\",\"location_id\":\"13.408642_52.527094\",\"address\":{\"location_id\":\"13.408642_52.527094\",\"lat\":52.527094,\"lon\":13.408642},\"arr_time\":1551122713,\"arr_date_time\":\"2019-02-25T20:25:13+01:00\",\"end_time\":1551122713,\"end_date_time\":\"2019-02-25T20:25:13+01:00\",\"waiting_time\":0,\"distance\":1777,\"driving_time\":313,\"preparation_time\":0,\"load_before\":[0],\"load_after\":[0]},{\"type\":\"service\",\"id\":\"berlin-1\",\"location_id\":\"13.398170_52.527303\",\"address\":{\"location_id\":\"13.398170_52.527303\",\"lat\":52.527303,\"lon\":13.39817},\"arr_time\":1551122864,\"arr_date_time\":\"2019-02-25T20:27:44+01:00\",\"end_time\":1551122864,\"end_date_time\":\"2019-02-25T20:27:44+01:00\",\"waiting_time\":0,\"distance\":2562,\"driving_time\":464,\"preparation_time\":0,\"load_before\":[0],\"load_after\":[0]},{\"type\":\"end\",\"location_id\":\"berlin\",\"address\":{\"location_id\":\"berlin\",\"lat\":52.537,\"lon\":13.406},\"arr_time\":1551123189,\"arr_date_time\":\"2019-02-25T20:33:09+01:00\",\"distance\":4334,\"driving_time\":789,\"preparation_time\":0,\"waiting_time\":0,\"load_before\":[0]}]", description = "Array of activities")
  public List<Activity> getActivities() {
    return activities;
  }

  public void setActivities(List<Activity> activities) {
    this.activities = activities;
  }

  public Route points(List<RoutePoint> points) {
    this.points = points;
    return this;
  }

  public Route addPointsItem(RoutePoint pointsItem) {
    if (this.points == null) {
      this.points = new ArrayList<RoutePoint>();
    }
    this.points.add(pointsItem);
    return this;
  }

   /**
   * Array of route planning points
   * @return points
  **/
  @Schema(example = "[{\"coordinates\":[[13.4061,52.53701],[13.40643,52.53634],[13.4067,52.53573],[13.40722,52.53479],[13.40729,52.53468],[13.40735,52.53463],[13.41205,52.53275],[13.41245,52.53264],[13.41218,52.53166],[13.41205,52.53139],[13.41177,52.53112],[13.41072,52.53033],[13.41049,52.53014],[13.4098,52.52928],[13.40937,52.5287],[13.40994,52.52858],[13.41032,52.52782],[13.41054,52.52745],[13.41097,52.52656],[13.41107,52.5265],[13.41119,52.52614],[13.41119,52.52604],[13.41109,52.52587],[13.40971,52.52631],[13.40981,52.52659],[13.40891,52.52683],[13.40852,52.52695]],\"type\":\"LineString\"},{\"coordinates\":[[13.40852,52.52695],[13.4081,52.52706],[13.40802,52.52696],[13.40469,52.52758],[13.4033,52.52781],[13.40331,52.52767],[13.40298,52.52763],[13.40261,52.52807],[13.39818,52.52726]],\"type\":\"LineString\"},{\"coordinates\":[[13.39818,52.52726],[13.39808,52.52725],[13.39785,52.52768],[13.39727,52.52866],[13.39762,52.52876],[13.3976,52.52914],[13.39756,52.52943],[13.39597,52.53243],[13.39777,52.5325],[13.39843,52.53254],[13.39891,52.53259],[13.40288,52.53354],[13.40297,52.53359],[13.40338,52.534],[13.40466,52.53419],[13.40433,52.53503],[13.40443,52.53511],[13.40541,52.53611],[13.40547,52.53615],[13.40643,52.53634],[13.4061,52.53701]],\"type\":\"LineString\"}]", description = "Array of route planning points")
  public List<RoutePoint> getPoints() {
    return points;
  }

  public void setPoints(List<RoutePoint> points) {
    this.points = points;
  }


  @Override
  public boolean equals(java.lang.Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }
    Route route = (Route) o;
    return Objects.equals(this.vehicleId, route.vehicleId) &&
        Objects.equals(this.distance, route.distance) &&
        Objects.equals(this.transportTime, route.transportTime) &&
        Objects.equals(this.completionTime, route.completionTime) &&
        Objects.equals(this.waitingTime, route.waitingTime) &&
        Objects.equals(this.serviceDuration, route.serviceDuration) &&
        Objects.equals(this.preparationTime, route.preparationTime) &&
        Objects.equals(this.activities, route.activities) &&
        Objects.equals(this.points, route.points);
  }

  @Override
  public int hashCode() {
    return Objects.hash(vehicleId, distance, transportTime, completionTime, waitingTime, serviceDuration, preparationTime, activities, points);
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class Route {\n");
    
    sb.append("    vehicleId: ").append(toIndentedString(vehicleId)).append("\n");
    sb.append("    distance: ").append(toIndentedString(distance)).append("\n");
    sb.append("    transportTime: ").append(toIndentedString(transportTime)).append("\n");
    sb.append("    completionTime: ").append(toIndentedString(completionTime)).append("\n");
    sb.append("    waitingTime: ").append(toIndentedString(waitingTime)).append("\n");
    sb.append("    serviceDuration: ").append(toIndentedString(serviceDuration)).append("\n");
    sb.append("    preparationTime: ").append(toIndentedString(preparationTime)).append("\n");
    sb.append("    activities: ").append(toIndentedString(activities)).append("\n");
    sb.append("    points: ").append(toIndentedString(points)).append("\n");
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
