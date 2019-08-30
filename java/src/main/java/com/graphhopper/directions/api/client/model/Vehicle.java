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
import com.graphhopper.directions.api.client.model.Address;
import com.graphhopper.directions.api.client.model.AnyOfVehicleModelBreak;
import io.swagger.v3.oas.annotations.media.Schema;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
/**
 * Vehicle
 */


public class Vehicle {
  @SerializedName("vehicle_id")
  private String vehicleId = null;

  @SerializedName("type_id")
  private String typeId = "default-type";

  @SerializedName("start_address")
  private Address startAddress = null;

  @SerializedName("end_address")
  private Address endAddress = null;

  @SerializedName("break")
  private AnyOfVehicleModelBreak _break = null;

  @SerializedName("return_to_depot")
  private Boolean returnToDepot = true;

  @SerializedName("earliest_start")
  private Long earliestStart = 0l;

  @SerializedName("latest_end")
  private Long latestEnd = null;

  @SerializedName("skills")
  private List<String> skills = null;

  @SerializedName("max_distance")
  private Long maxDistance = null;

  @SerializedName("max_driving_time")
  private Long maxDrivingTime = null;

  @SerializedName("max_jobs")
  private Integer maxJobs = null;

  @SerializedName("max_activities")
  private Integer maxActivities = null;

  @SerializedName("move_to_end_address")
  private Boolean moveToEndAddress = null;

  public Vehicle vehicleId(String vehicleId) {
    this.vehicleId = vehicleId;
    return this;
  }

   /**
   * Specifies the id of the vehicle. Ids need to be unique, thus if there two vehicles with the same id, an exception is thrown.
   * @return vehicleId
  **/
  @Schema(example = "vehicle-1", required = true, description = "Specifies the id of the vehicle. Ids need to be unique, thus if there two vehicles with the same id, an exception is thrown.")
  public String getVehicleId() {
    return vehicleId;
  }

  public void setVehicleId(String vehicleId) {
    this.vehicleId = vehicleId;
  }

  public Vehicle typeId(String typeId) {
    this.typeId = typeId;
    return this;
  }

   /**
   * The type_id refers to specified vehicle type (see vehicle types). If it is omitted a default type will be used.
   * @return typeId
  **/
  @Schema(example = "my-own-type", description = "The type_id refers to specified vehicle type (see vehicle types). If it is omitted a default type will be used.")
  public String getTypeId() {
    return typeId;
  }

  public void setTypeId(String typeId) {
    this.typeId = typeId;
  }

  public Vehicle startAddress(Address startAddress) {
    this.startAddress = startAddress;
    return this;
  }

   /**
   * Get startAddress
   * @return startAddress
  **/
  @Schema(required = true, description = "")
  public Address getStartAddress() {
    return startAddress;
  }

  public void setStartAddress(Address startAddress) {
    this.startAddress = startAddress;
  }

  public Vehicle endAddress(Address endAddress) {
    this.endAddress = endAddress;
    return this;
  }

   /**
   * Get endAddress
   * @return endAddress
  **/
  @Schema(description = "")
  public Address getEndAddress() {
    return endAddress;
  }

  public void setEndAddress(Address endAddress) {
    this.endAddress = endAddress;
  }

  public Vehicle _break(AnyOfVehicleModelBreak _break) {
    this._break = _break;
    return this;
  }

   /**
   * Get _break
   * @return _break
  **/
  @Schema(description = "")
  public AnyOfVehicleModelBreak getBreak() {
    return _break;
  }

  public void setBreak(AnyOfVehicleModelBreak _break) {
    this._break = _break;
  }

  public Vehicle returnToDepot(Boolean returnToDepot) {
    this.returnToDepot = returnToDepot;
    return this;
  }

   /**
   * If it is false, the algorithm decides where to end the vehicle route. It ends in one of your customers&#x27; locations. The end is chosen such that it contributes to the overall objective function, e.g. min transport_time. If it is true, you can either specify a specific end location (which is then regarded as end depot) or you can leave it and the driver returns to its start location.
   * @return returnToDepot
  **/
  @Schema(description = "If it is false, the algorithm decides where to end the vehicle route. It ends in one of your customers' locations. The end is chosen such that it contributes to the overall objective function, e.g. min transport_time. If it is true, you can either specify a specific end location (which is then regarded as end depot) or you can leave it and the driver returns to its start location.")
  public Boolean isReturnToDepot() {
    return returnToDepot;
  }

  public void setReturnToDepot(Boolean returnToDepot) {
    this.returnToDepot = returnToDepot;
  }

  public Vehicle earliestStart(Long earliestStart) {
    this.earliestStart = earliestStart;
    return this;
  }

   /**
   * Earliest start of vehicle in seconds. It is recommended to use the unix timestamp.
   * @return earliestStart
  **/
  @Schema(description = "Earliest start of vehicle in seconds. It is recommended to use the unix timestamp.")
  public Long getEarliestStart() {
    return earliestStart;
  }

  public void setEarliestStart(Long earliestStart) {
    this.earliestStart = earliestStart;
  }

  public Vehicle latestEnd(Long latestEnd) {
    this.latestEnd = latestEnd;
    return this;
  }

   /**
   * Latest end of vehicle in seconds, i.e. the time the vehicle needs to be at its end location at latest.
   * @return latestEnd
  **/
  @Schema(description = "Latest end of vehicle in seconds, i.e. the time the vehicle needs to be at its end location at latest.")
  public Long getLatestEnd() {
    return latestEnd;
  }

  public void setLatestEnd(Long latestEnd) {
    this.latestEnd = latestEnd;
  }

  public Vehicle skills(List<String> skills) {
    this.skills = skills;
    return this;
  }

  public Vehicle addSkillsItem(String skillsItem) {
    if (this.skills == null) {
      this.skills = new ArrayList<String>();
    }
    this.skills.add(skillsItem);
    return this;
  }

   /**
   * Array of skills, i.e. array of string (not case sensitive).
   * @return skills
  **/
  @Schema(example = "[\"drilling_maschine\",\"screw_driver\"]", description = "Array of skills, i.e. array of string (not case sensitive).")
  public List<String> getSkills() {
    return skills;
  }

  public void setSkills(List<String> skills) {
    this.skills = skills;
  }

  public Vehicle maxDistance(Long maxDistance) {
    this.maxDistance = maxDistance;
    return this;
  }

   /**
   * Specifies the maximum distance a vehicle can go.
   * @return maxDistance
  **/
  @Schema(example = "400000", description = "Specifies the maximum distance a vehicle can go.")
  public Long getMaxDistance() {
    return maxDistance;
  }

  public void setMaxDistance(Long maxDistance) {
    this.maxDistance = maxDistance;
  }

  public Vehicle maxDrivingTime(Long maxDrivingTime) {
    this.maxDrivingTime = maxDrivingTime;
    return this;
  }

   /**
   * Specifies the maximum drive time a vehicle/driver can go, i.e. the maximum time on the road (service and waiting times are not included here)
   * @return maxDrivingTime
  **/
  @Schema(example = "28800", description = "Specifies the maximum drive time a vehicle/driver can go, i.e. the maximum time on the road (service and waiting times are not included here)")
  public Long getMaxDrivingTime() {
    return maxDrivingTime;
  }

  public void setMaxDrivingTime(Long maxDrivingTime) {
    this.maxDrivingTime = maxDrivingTime;
  }

  public Vehicle maxJobs(Integer maxJobs) {
    this.maxJobs = maxJobs;
    return this;
  }

   /**
   * Specifies the maximum number of jobs a vehicle can load.
   * @return maxJobs
  **/
  @Schema(example = "12", description = "Specifies the maximum number of jobs a vehicle can load.")
  public Integer getMaxJobs() {
    return maxJobs;
  }

  public void setMaxJobs(Integer maxJobs) {
    this.maxJobs = maxJobs;
  }

  public Vehicle maxActivities(Integer maxActivities) {
    this.maxActivities = maxActivities;
    return this;
  }

   /**
   * Specifies the maximum number of activities a vehicle can conduct.
   * @return maxActivities
  **/
  @Schema(example = "24", description = "Specifies the maximum number of activities a vehicle can conduct.")
  public Integer getMaxActivities() {
    return maxActivities;
  }

  public void setMaxActivities(Integer maxActivities) {
    this.maxActivities = maxActivities;
  }

  public Vehicle moveToEndAddress(Boolean moveToEndAddress) {
    this.moveToEndAddress = moveToEndAddress;
    return this;
  }

   /**
   * Indicates whether a vehicle should be moved even though it has not been assigned any jobs.
   * @return moveToEndAddress
  **/
  @Schema(description = "Indicates whether a vehicle should be moved even though it has not been assigned any jobs.")
  public Boolean isMoveToEndAddress() {
    return moveToEndAddress;
  }

  public void setMoveToEndAddress(Boolean moveToEndAddress) {
    this.moveToEndAddress = moveToEndAddress;
  }


  @Override
  public boolean equals(java.lang.Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }
    Vehicle vehicle = (Vehicle) o;
    return Objects.equals(this.vehicleId, vehicle.vehicleId) &&
        Objects.equals(this.typeId, vehicle.typeId) &&
        Objects.equals(this.startAddress, vehicle.startAddress) &&
        Objects.equals(this.endAddress, vehicle.endAddress) &&
        Objects.equals(this._break, vehicle._break) &&
        Objects.equals(this.returnToDepot, vehicle.returnToDepot) &&
        Objects.equals(this.earliestStart, vehicle.earliestStart) &&
        Objects.equals(this.latestEnd, vehicle.latestEnd) &&
        Objects.equals(this.skills, vehicle.skills) &&
        Objects.equals(this.maxDistance, vehicle.maxDistance) &&
        Objects.equals(this.maxDrivingTime, vehicle.maxDrivingTime) &&
        Objects.equals(this.maxJobs, vehicle.maxJobs) &&
        Objects.equals(this.maxActivities, vehicle.maxActivities) &&
        Objects.equals(this.moveToEndAddress, vehicle.moveToEndAddress);
  }

  @Override
  public int hashCode() {
    return Objects.hash(vehicleId, typeId, startAddress, endAddress, _break, returnToDepot, earliestStart, latestEnd, skills, maxDistance, maxDrivingTime, maxJobs, maxActivities, moveToEndAddress);
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class Vehicle {\n");
    
    sb.append("    vehicleId: ").append(toIndentedString(vehicleId)).append("\n");
    sb.append("    typeId: ").append(toIndentedString(typeId)).append("\n");
    sb.append("    startAddress: ").append(toIndentedString(startAddress)).append("\n");
    sb.append("    endAddress: ").append(toIndentedString(endAddress)).append("\n");
    sb.append("    _break: ").append(toIndentedString(_break)).append("\n");
    sb.append("    returnToDepot: ").append(toIndentedString(returnToDepot)).append("\n");
    sb.append("    earliestStart: ").append(toIndentedString(earliestStart)).append("\n");
    sb.append("    latestEnd: ").append(toIndentedString(latestEnd)).append("\n");
    sb.append("    skills: ").append(toIndentedString(skills)).append("\n");
    sb.append("    maxDistance: ").append(toIndentedString(maxDistance)).append("\n");
    sb.append("    maxDrivingTime: ").append(toIndentedString(maxDrivingTime)).append("\n");
    sb.append("    maxJobs: ").append(toIndentedString(maxJobs)).append("\n");
    sb.append("    maxActivities: ").append(toIndentedString(maxActivities)).append("\n");
    sb.append("    moveToEndAddress: ").append(toIndentedString(moveToEndAddress)).append("\n");
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
