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
import com.graphhopper.directions.api.client.model.Address;
import com.graphhopper.directions.api.client.model.TimeWindow;
import io.swagger.v3.oas.annotations.media.Schema;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
/**
 * Service
 */


public class Service {
  @SerializedName("id")
  private String id = null;

  /**
   * Specifies type of service. This makes a difference if items are loaded or unloaded, i.e. if one of the size dimensions &gt; 0. If it is specified as &#x60;service&#x60; or &#x60;pickup&#x60;, items are loaded and will stay in the vehicle for the rest of the route (and thus consumes capacity for the rest of the route). If it is a &#x60;delivery&#x60;, items are implicitly loaded at the beginning of the route and will stay in the route until delivery (and thus releases capacity for the rest of the route).
   */
  @JsonAdapter(TypeEnum.Adapter.class)
  public enum TypeEnum {
    SERVICE("service"),
    PICKUP("pickup"),
    DELIVERY("delivery");

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
  private TypeEnum type = TypeEnum.SERVICE;

  @SerializedName("priority")
  private Integer priority = 2;

  @SerializedName("name")
  private String name = null;

  @SerializedName("address")
  private Address address = null;

  @SerializedName("duration")
  private Long duration = 0l;

  @SerializedName("preparation_time")
  private Long preparationTime = 0l;

  @SerializedName("time_windows")
  private List<TimeWindow> timeWindows = null;

  @SerializedName("size")
  private List<Integer> size = null;

  @SerializedName("required_skills")
  private List<String> requiredSkills = null;

  @SerializedName("allowed_vehicles")
  private List<String> allowedVehicles = null;

  @SerializedName("disallowed_vehicles")
  private List<String> disallowedVehicles = null;

  @SerializedName("max_time_in_vehicle")
  private Long maxTimeInVehicle = null;

  @SerializedName("group")
  private String group = null;

  public Service id(String id) {
    this.id = id;
    return this;
  }

   /**
   * Specifies the id of the service. Ids need to be unique so there must not be two services/shipments with the same id.
   * @return id
  **/
  @Schema(example = "7fe77504-7df8-4497-843c-02d70b6490ce", required = true, description = "Specifies the id of the service. Ids need to be unique so there must not be two services/shipments with the same id.")
  public String getId() {
    return id;
  }

  public void setId(String id) {
    this.id = id;
  }

  public Service type(TypeEnum type) {
    this.type = type;
    return this;
  }

   /**
   * Specifies type of service. This makes a difference if items are loaded or unloaded, i.e. if one of the size dimensions &gt; 0. If it is specified as &#x60;service&#x60; or &#x60;pickup&#x60;, items are loaded and will stay in the vehicle for the rest of the route (and thus consumes capacity for the rest of the route). If it is a &#x60;delivery&#x60;, items are implicitly loaded at the beginning of the route and will stay in the route until delivery (and thus releases capacity for the rest of the route).
   * @return type
  **/
  @Schema(example = "delivery", description = "Specifies type of service. This makes a difference if items are loaded or unloaded, i.e. if one of the size dimensions > 0. If it is specified as `service` or `pickup`, items are loaded and will stay in the vehicle for the rest of the route (and thus consumes capacity for the rest of the route). If it is a `delivery`, items are implicitly loaded at the beginning of the route and will stay in the route until delivery (and thus releases capacity for the rest of the route).")
  public TypeEnum getType() {
    return type;
  }

  public void setType(TypeEnum type) {
    this.type = type;
  }

  public Service priority(Integer priority) {
    this.priority = priority;
    return this;
  }

   /**
   * Specifies the priority. Can be 1 &#x3D; high priority to 10 &#x3D; low priority. Often there are more services/shipments than the available vehicle fleet can handle. Then you could assign priorities to differentiate high priority tasks from those that can be served later or omitted at all.
   * @return priority
  **/
  @Schema(example = "1", description = "Specifies the priority. Can be 1 = high priority to 10 = low priority. Often there are more services/shipments than the available vehicle fleet can handle. Then you could assign priorities to differentiate high priority tasks from those that can be served later or omitted at all.")
  public Integer getPriority() {
    return priority;
  }

  public void setPriority(Integer priority) {
    this.priority = priority;
  }

  public Service name(String name) {
    this.name = name;
    return this;
  }

   /**
   * Meaningful name for service, e.g. &#x60;\&quot;deliver pizza\&quot;&#x60;.
   * @return name
  **/
  @Schema(example = "delivery pizza", description = "Meaningful name for service, e.g. `\"deliver pizza\"`.")
  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public Service address(Address address) {
    this.address = address;
    return this;
  }

   /**
   * Get address
   * @return address
  **/
  @Schema(required = true, description = "")
  public Address getAddress() {
    return address;
  }

  public void setAddress(Address address) {
    this.address = address;
  }

  public Service duration(Long duration) {
    this.duration = duration;
    return this;
  }

   /**
   * Specifies the duration of the service in seconds, i.e. how long it takes at the customer site.
   * minimum: 0
   * maximum: 604800
   * @return duration
  **/
  @Schema(example = "1800", description = "Specifies the duration of the service in seconds, i.e. how long it takes at the customer site.")
  public Long getDuration() {
    return duration;
  }

  public void setDuration(Long duration) {
    this.duration = duration;
  }

  public Service preparationTime(Long preparationTime) {
    this.preparationTime = preparationTime;
    return this;
  }

   /**
   * Specifies the preparation time in seconds. It can be used to model parking lot search time since if you have 3 identical locations in a row, it only falls due once.
   * minimum: 0
   * maximum: 604800
   * @return preparationTime
  **/
  @Schema(example = "300", description = "Specifies the preparation time in seconds. It can be used to model parking lot search time since if you have 3 identical locations in a row, it only falls due once.")
  public Long getPreparationTime() {
    return preparationTime;
  }

  public void setPreparationTime(Long preparationTime) {
    this.preparationTime = preparationTime;
  }

  public Service timeWindows(List<TimeWindow> timeWindows) {
    this.timeWindows = timeWindows;
    return this;
  }

  public Service addTimeWindowsItem(TimeWindow timeWindowsItem) {
    if (this.timeWindows == null) {
      this.timeWindows = new ArrayList<TimeWindow>();
    }
    this.timeWindows.add(timeWindowsItem);
    return this;
  }

   /**
   * Specifies an array of time window objects (see time_window object below). Specify the time either with the recommended Unix time stamp (the number of seconds since 1970-01-01) or you can also count the seconds relative to Monday morning 00:00 and define the whole week in seconds. For example, Monday 9am is then represented by 9hour * 3600sec/hour &#x3D; 32400. In turn, Wednesday 1pm corresponds to 2day * 24hour/day * 3600sec/hour + 1day * 13hour/day * 3600sec/hour &#x3D; 219600. See this tutorial for more information.
   * @return timeWindows
  **/
  @Schema(example = "[{\"earliest\":32400,\"latest\":36000},{\"earliest\":50400,\"latest\":54000}]", description = "Specifies an array of time window objects (see time_window object below). Specify the time either with the recommended Unix time stamp (the number of seconds since 1970-01-01) or you can also count the seconds relative to Monday morning 00:00 and define the whole week in seconds. For example, Monday 9am is then represented by 9hour * 3600sec/hour = 32400. In turn, Wednesday 1pm corresponds to 2day * 24hour/day * 3600sec/hour + 1day * 13hour/day * 3600sec/hour = 219600. See this tutorial for more information.")
  public List<TimeWindow> getTimeWindows() {
    return timeWindows;
  }

  public void setTimeWindows(List<TimeWindow> timeWindows) {
    this.timeWindows = timeWindows;
  }

  public Service size(List<Integer> size) {
    this.size = size;
    return this;
  }

  public Service addSizeItem(Integer sizeItem) {
    if (this.size == null) {
      this.size = new ArrayList<Integer>();
    }
    this.size.add(sizeItem);
    return this;
  }

   /**
   * Size can have multiple dimensions and should be in line with the capacity dimension array of the vehicle type. For example, if the item that needs to be delivered has two size dimension, volume and weight, then specify it as follow [ 20, 5 ] assuming a volume of 20 and a weight of 5.
   * @return size
  **/
  @Schema(example = "[30,5,1]", description = "Size can have multiple dimensions and should be in line with the capacity dimension array of the vehicle type. For example, if the item that needs to be delivered has two size dimension, volume and weight, then specify it as follow [ 20, 5 ] assuming a volume of 20 and a weight of 5.")
  public List<Integer> getSize() {
    return size;
  }

  public void setSize(List<Integer> size) {
    this.size = size;
  }

  public Service requiredSkills(List<String> requiredSkills) {
    this.requiredSkills = requiredSkills;
    return this;
  }

  public Service addRequiredSkillsItem(String requiredSkillsItem) {
    if (this.requiredSkills == null) {
      this.requiredSkills = new ArrayList<String>();
    }
    this.requiredSkills.add(requiredSkillsItem);
    return this;
  }

   /**
   * Specifies an array of required skills, i.e. array of string (not case sensitive). For example, if this service needs to be conducted by a technician having a &#x60;drilling_machine&#x60; and a &#x60;screw_driver&#x60; then specify the array as follows: &#x60;[\&quot;drilling_machine\&quot;,\&quot;screw_driver\&quot;]&#x60;. This means that the service can only be done by a vehicle (technician) that has the skills &#x60;drilling_machine&#x60; AND &#x60;screw_driver&#x60; in its skill array. Otherwise it remains unassigned.
   * @return requiredSkills
  **/
  @Schema(example = "[\"drilling_machine\",\"screw_driver\"]", description = "Specifies an array of required skills, i.e. array of string (not case sensitive). For example, if this service needs to be conducted by a technician having a `drilling_machine` and a `screw_driver` then specify the array as follows: `[\"drilling_machine\",\"screw_driver\"]`. This means that the service can only be done by a vehicle (technician) that has the skills `drilling_machine` AND `screw_driver` in its skill array. Otherwise it remains unassigned.")
  public List<String> getRequiredSkills() {
    return requiredSkills;
  }

  public void setRequiredSkills(List<String> requiredSkills) {
    this.requiredSkills = requiredSkills;
  }

  public Service allowedVehicles(List<String> allowedVehicles) {
    this.allowedVehicles = allowedVehicles;
    return this;
  }

  public Service addAllowedVehiclesItem(String allowedVehiclesItem) {
    if (this.allowedVehicles == null) {
      this.allowedVehicles = new ArrayList<String>();
    }
    this.allowedVehicles.add(allowedVehiclesItem);
    return this;
  }

   /**
   * Specifies an array of allowed vehicles, i.e. array of vehicle ids. For example, if this service can only be conducted EITHER by &#x60;technician_peter&#x60; OR &#x60;technician_stefan&#x60; specify this as follows: &#x60;[\&quot;technician_peter\&quot;,\&quot;technician_stefan\&quot;]&#x60;.
   * @return allowedVehicles
  **/
  @Schema(example = "[\"technician_peter\",\"technician_stefan\"]", description = "Specifies an array of allowed vehicles, i.e. array of vehicle ids. For example, if this service can only be conducted EITHER by `technician_peter` OR `technician_stefan` specify this as follows: `[\"technician_peter\",\"technician_stefan\"]`.")
  public List<String> getAllowedVehicles() {
    return allowedVehicles;
  }

  public void setAllowedVehicles(List<String> allowedVehicles) {
    this.allowedVehicles = allowedVehicles;
  }

  public Service disallowedVehicles(List<String> disallowedVehicles) {
    this.disallowedVehicles = disallowedVehicles;
    return this;
  }

  public Service addDisallowedVehiclesItem(String disallowedVehiclesItem) {
    if (this.disallowedVehicles == null) {
      this.disallowedVehicles = new ArrayList<String>();
    }
    this.disallowedVehicles.add(disallowedVehiclesItem);
    return this;
  }

   /**
   * Specifies an array of disallowed vehicles, i.e. array of vehicle ids.
   * @return disallowedVehicles
  **/
  @Schema(example = "[\"driver-A\",\"driver-B\"]", description = "Specifies an array of disallowed vehicles, i.e. array of vehicle ids.")
  public List<String> getDisallowedVehicles() {
    return disallowedVehicles;
  }

  public void setDisallowedVehicles(List<String> disallowedVehicles) {
    this.disallowedVehicles = disallowedVehicles;
  }

  public Service maxTimeInVehicle(Long maxTimeInVehicle) {
    this.maxTimeInVehicle = maxTimeInVehicle;
    return this;
  }

   /**
   * Specifies the maximum time in seconds a delivery can stay in the vehicle. Currently, it only works with services of \&quot;type\&quot;:\&quot;delivery\&quot;.
   * @return maxTimeInVehicle
  **/
  @Schema(example = "900", description = "Specifies the maximum time in seconds a delivery can stay in the vehicle. Currently, it only works with services of \"type\":\"delivery\".")
  public Long getMaxTimeInVehicle() {
    return maxTimeInVehicle;
  }

  public void setMaxTimeInVehicle(Long maxTimeInVehicle) {
    this.maxTimeInVehicle = maxTimeInVehicle;
  }

  public Service group(String group) {
    this.group = group;
    return this;
  }

   /**
   * Group this service belongs to.
   * @return group
  **/
  @Schema(example = "group-A", description = "Group this service belongs to.")
  public String getGroup() {
    return group;
  }

  public void setGroup(String group) {
    this.group = group;
  }


  @Override
  public boolean equals(java.lang.Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }
    Service service = (Service) o;
    return Objects.equals(this.id, service.id) &&
        Objects.equals(this.type, service.type) &&
        Objects.equals(this.priority, service.priority) &&
        Objects.equals(this.name, service.name) &&
        Objects.equals(this.address, service.address) &&
        Objects.equals(this.duration, service.duration) &&
        Objects.equals(this.preparationTime, service.preparationTime) &&
        Objects.equals(this.timeWindows, service.timeWindows) &&
        Objects.equals(this.size, service.size) &&
        Objects.equals(this.requiredSkills, service.requiredSkills) &&
        Objects.equals(this.allowedVehicles, service.allowedVehicles) &&
        Objects.equals(this.disallowedVehicles, service.disallowedVehicles) &&
        Objects.equals(this.maxTimeInVehicle, service.maxTimeInVehicle) &&
        Objects.equals(this.group, service.group);
  }

  @Override
  public int hashCode() {
    return Objects.hash(id, type, priority, name, address, duration, preparationTime, timeWindows, size, requiredSkills, allowedVehicles, disallowedVehicles, maxTimeInVehicle, group);
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class Service {\n");
    
    sb.append("    id: ").append(toIndentedString(id)).append("\n");
    sb.append("    type: ").append(toIndentedString(type)).append("\n");
    sb.append("    priority: ").append(toIndentedString(priority)).append("\n");
    sb.append("    name: ").append(toIndentedString(name)).append("\n");
    sb.append("    address: ").append(toIndentedString(address)).append("\n");
    sb.append("    duration: ").append(toIndentedString(duration)).append("\n");
    sb.append("    preparationTime: ").append(toIndentedString(preparationTime)).append("\n");
    sb.append("    timeWindows: ").append(toIndentedString(timeWindows)).append("\n");
    sb.append("    size: ").append(toIndentedString(size)).append("\n");
    sb.append("    requiredSkills: ").append(toIndentedString(requiredSkills)).append("\n");
    sb.append("    allowedVehicles: ").append(toIndentedString(allowedVehicles)).append("\n");
    sb.append("    disallowedVehicles: ").append(toIndentedString(disallowedVehicles)).append("\n");
    sb.append("    maxTimeInVehicle: ").append(toIndentedString(maxTimeInVehicle)).append("\n");
    sb.append("    group: ").append(toIndentedString(group)).append("\n");
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
