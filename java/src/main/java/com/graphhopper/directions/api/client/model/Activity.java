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
import com.graphhopper.directions.api.client.model.ResponseAddress;
import io.swagger.v3.oas.annotations.media.Schema;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import org.threeten.bp.OffsetDateTime;
/**
 * Activity
 */


public class Activity {
  /**
   * type of activity
   */
  @JsonAdapter(TypeEnum.Adapter.class)
  public enum TypeEnum {
    START("start"),
    END("end"),
    SERVICE("service"),
    PICKUPSHIPMENT("pickupShipment"),
    DELIVERSHIPMENT("deliverShipment"),
    PICKUP("pickup"),
    DELIVERY("delivery"),
    BREAK("break");

    private String value;

    TypeEnum(String value) {
      this.value = value;
    }
    public String getValue() {
      return value;
    }

    @Override
    public String toString() {
      return String.valueOf(value);
    }
    public static TypeEnum fromValue(String text) {
      for (TypeEnum b : TypeEnum.values()) {
        if (String.valueOf(b.value).equals(text)) {
          return b;
        }
      }
      return null;
    }
    public static class Adapter extends TypeAdapter<TypeEnum> {
      @Override
      public void write(final JsonWriter jsonWriter, final TypeEnum enumeration) throws IOException {
        jsonWriter.value(enumeration.getValue());
      }

      @Override
      public TypeEnum read(final JsonReader jsonReader) throws IOException {
        String value = jsonReader.nextString();
        return TypeEnum.fromValue(String.valueOf(value));
      }
    }
  }  @SerializedName("type")
  private TypeEnum type = null;

  @SerializedName("id")
  private String id = null;

  @SerializedName("location_id")
  private String locationId = null;

  @SerializedName("address")
  private ResponseAddress address = null;

  @SerializedName("arr_time")
  private Long arrTime = null;

  @SerializedName("end_time")
  private Long endTime = null;

  @SerializedName("end_date_time")
  private OffsetDateTime endDateTime = null;

  @SerializedName("arr_date_time")
  private OffsetDateTime arrDateTime = null;

  @SerializedName("waiting_time")
  private Long waitingTime = null;

  @SerializedName("preparation_time")
  private Long preparationTime = null;

  @SerializedName("distance")
  private Long distance = null;

  @SerializedName("driving_time")
  private Long drivingTime = null;

  @SerializedName("load_before")
  private List<Integer> loadBefore = null;

  @SerializedName("load_after")
  private List<Integer> loadAfter = null;

  public Activity type(TypeEnum type) {
    this.type = type;
    return this;
  }

   /**
   * type of activity
   * @return type
  **/
  @Schema(description = "type of activity")
  public TypeEnum getType() {
    return type;
  }

  public void setType(TypeEnum type) {
    this.type = type;
  }

  public Activity id(String id) {
    this.id = id;
    return this;
  }

   /**
   * Id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to
   * @return id
  **/
  @Schema(description = "Id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to")
  public String getId() {
    return id;
  }

  public void setId(String id) {
    this.id = id;
  }

  public Activity locationId(String locationId) {
    this.locationId = locationId;
    return this;
  }

   /**
   * Id that refers to address
   * @return locationId
  **/
  @Schema(description = "Id that refers to address")
  public String getLocationId() {
    return locationId;
  }

  public void setLocationId(String locationId) {
    this.locationId = locationId;
  }

  public Activity address(ResponseAddress address) {
    this.address = address;
    return this;
  }

   /**
   * Get address
   * @return address
  **/
  @Schema(description = "")
  public ResponseAddress getAddress() {
    return address;
  }

  public void setAddress(ResponseAddress address) {
    this.address = address;
  }

  public Activity arrTime(Long arrTime) {
    this.arrTime = arrTime;
    return this;
  }

   /**
   * Arrival time at this activity in seconds. If type is &#x60;start&#x60;, this is not available (since it makes no sense to have &#x60;arr_time&#x60; at start). However, &#x60;end_time&#x60; is available and actually means \\\&quot;departure time\\\&quot; at start location. It is important to note that &#x60;arr_time&#x60; does not necessarily mean \\\&quot;start of underlying activity\\\&quot;, it solely means arrival time at activity location. If this activity has no time windows and if there are no further preparation times, &#x60;arr_time&#x60; is equal to activity start time.
   * @return arrTime
  **/
  @Schema(description = "Arrival time at this activity in seconds. If type is `start`, this is not available (since it makes no sense to have `arr_time` at start). However, `end_time` is available and actually means \\\"departure time\\\" at start location. It is important to note that `arr_time` does not necessarily mean \\\"start of underlying activity\\\", it solely means arrival time at activity location. If this activity has no time windows and if there are no further preparation times, `arr_time` is equal to activity start time.")
  public Long getArrTime() {
    return arrTime;
  }

  public void setArrTime(Long arrTime) {
    this.arrTime = arrTime;
  }

  public Activity endTime(Long endTime) {
    this.endTime = endTime;
    return this;
  }

   /**
   * End time of and thus departure time at this activity. If type is &#x60;end&#x60;, this is not available (since it makes no sense to have an &#x60;end_time&#x60; at end) &#x60;end_time&#x60; at each activity is equal to the departure time at the activity location.
   * @return endTime
  **/
  @Schema(description = "End time of and thus departure time at this activity. If type is `end`, this is not available (since it makes no sense to have an `end_time` at end) `end_time` at each activity is equal to the departure time at the activity location.")
  public Long getEndTime() {
    return endTime;
  }

  public void setEndTime(Long endTime) {
    this.endTime = endTime;
  }

  public Activity endDateTime(OffsetDateTime endDateTime) {
    this.endDateTime = endDateTime;
    return this;
  }

   /**
   * End date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is &#x60;null&#x60;.
   * @return endDateTime
  **/
  @Schema(description = "End date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is `null`.")
  public OffsetDateTime getEndDateTime() {
    return endDateTime;
  }

  public void setEndDateTime(OffsetDateTime endDateTime) {
    this.endDateTime = endDateTime;
  }

  public Activity arrDateTime(OffsetDateTime arrDateTime) {
    this.arrDateTime = arrDateTime;
    return this;
  }

   /**
   * Arrival date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is &#x60;null&#x60;.
   * @return arrDateTime
  **/
  @Schema(description = "Arrival date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is `null`.")
  public OffsetDateTime getArrDateTime() {
    return arrDateTime;
  }

  public void setArrDateTime(OffsetDateTime arrDateTime) {
    this.arrDateTime = arrDateTime;
  }

  public Activity waitingTime(Long waitingTime) {
    this.waitingTime = waitingTime;
    return this;
  }

   /**
   * Waiting time at this activity in seconds. A waiting time can occur if the activity has at least one time window. If &#x60;arr_time&#x60; &lt; &#x60;time_window.earliest&#x60; a waiting time of &#x60;time_window_earliest&#x60; - &#x60;arr_time&#x60; occurs.
   * @return waitingTime
  **/
  @Schema(description = "Waiting time at this activity in seconds. A waiting time can occur if the activity has at least one time window. If `arr_time` < `time_window.earliest` a waiting time of `time_window_earliest` - `arr_time` occurs.")
  public Long getWaitingTime() {
    return waitingTime;
  }

  public void setWaitingTime(Long waitingTime) {
    this.waitingTime = waitingTime;
  }

  public Activity preparationTime(Long preparationTime) {
    this.preparationTime = preparationTime;
    return this;
  }

   /**
   * preparation time at this activity in seconds
   * @return preparationTime
  **/
  @Schema(description = "preparation time at this activity in seconds")
  public Long getPreparationTime() {
    return preparationTime;
  }

  public void setPreparationTime(Long preparationTime) {
    this.preparationTime = preparationTime;
  }

  public Activity distance(Long distance) {
    this.distance = distance;
    return this;
  }

   /**
   * cumulated distance from start to this activity in m
   * @return distance
  **/
  @Schema(description = "cumulated distance from start to this activity in m")
  public Long getDistance() {
    return distance;
  }

  public void setDistance(Long distance) {
    this.distance = distance;
  }

  public Activity drivingTime(Long drivingTime) {
    this.drivingTime = drivingTime;
    return this;
  }

   /**
   * driving time of driver in seconds
   * @return drivingTime
  **/
  @Schema(description = "driving time of driver in seconds")
  public Long getDrivingTime() {
    return drivingTime;
  }

  public void setDrivingTime(Long drivingTime) {
    this.drivingTime = drivingTime;
  }

  public Activity loadBefore(List<Integer> loadBefore) {
    this.loadBefore = loadBefore;
    return this;
  }

  public Activity addLoadBeforeItem(Integer loadBeforeItem) {
    if (this.loadBefore == null) {
      this.loadBefore = new ArrayList<Integer>();
    }
    this.loadBefore.add(loadBeforeItem);
    return this;
  }

   /**
   * Array with size/capacity dimensions before this activity
   * @return loadBefore
  **/
  @Schema(description = "Array with size/capacity dimensions before this activity")
  public List<Integer> getLoadBefore() {
    return loadBefore;
  }

  public void setLoadBefore(List<Integer> loadBefore) {
    this.loadBefore = loadBefore;
  }

  public Activity loadAfter(List<Integer> loadAfter) {
    this.loadAfter = loadAfter;
    return this;
  }

  public Activity addLoadAfterItem(Integer loadAfterItem) {
    if (this.loadAfter == null) {
      this.loadAfter = new ArrayList<Integer>();
    }
    this.loadAfter.add(loadAfterItem);
    return this;
  }

   /**
   * Array with size/capacity dimensions after this activity
   * @return loadAfter
  **/
  @Schema(description = "Array with size/capacity dimensions after this activity")
  public List<Integer> getLoadAfter() {
    return loadAfter;
  }

  public void setLoadAfter(List<Integer> loadAfter) {
    this.loadAfter = loadAfter;
  }


  @Override
  public boolean equals(java.lang.Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }
    Activity activity = (Activity) o;
    return Objects.equals(this.type, activity.type) &&
        Objects.equals(this.id, activity.id) &&
        Objects.equals(this.locationId, activity.locationId) &&
        Objects.equals(this.address, activity.address) &&
        Objects.equals(this.arrTime, activity.arrTime) &&
        Objects.equals(this.endTime, activity.endTime) &&
        Objects.equals(this.endDateTime, activity.endDateTime) &&
        Objects.equals(this.arrDateTime, activity.arrDateTime) &&
        Objects.equals(this.waitingTime, activity.waitingTime) &&
        Objects.equals(this.preparationTime, activity.preparationTime) &&
        Objects.equals(this.distance, activity.distance) &&
        Objects.equals(this.drivingTime, activity.drivingTime) &&
        Objects.equals(this.loadBefore, activity.loadBefore) &&
        Objects.equals(this.loadAfter, activity.loadAfter);
  }

  @Override
  public int hashCode() {
    return Objects.hash(type, id, locationId, address, arrTime, endTime, endDateTime, arrDateTime, waitingTime, preparationTime, distance, drivingTime, loadBefore, loadAfter);
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class Activity {\n");
    
    sb.append("    type: ").append(toIndentedString(type)).append("\n");
    sb.append("    id: ").append(toIndentedString(id)).append("\n");
    sb.append("    locationId: ").append(toIndentedString(locationId)).append("\n");
    sb.append("    address: ").append(toIndentedString(address)).append("\n");
    sb.append("    arrTime: ").append(toIndentedString(arrTime)).append("\n");
    sb.append("    endTime: ").append(toIndentedString(endTime)).append("\n");
    sb.append("    endDateTime: ").append(toIndentedString(endDateTime)).append("\n");
    sb.append("    arrDateTime: ").append(toIndentedString(arrDateTime)).append("\n");
    sb.append("    waitingTime: ").append(toIndentedString(waitingTime)).append("\n");
    sb.append("    preparationTime: ").append(toIndentedString(preparationTime)).append("\n");
    sb.append("    distance: ").append(toIndentedString(distance)).append("\n");
    sb.append("    drivingTime: ").append(toIndentedString(drivingTime)).append("\n");
    sb.append("    loadBefore: ").append(toIndentedString(loadBefore)).append("\n");
    sb.append("    loadAfter: ").append(toIndentedString(loadAfter)).append("\n");
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
