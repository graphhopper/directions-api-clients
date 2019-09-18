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
import io.swagger.v3.oas.annotations.media.Schema;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
/**
 * JobRelation
 */


public class JobRelation {
  @SerializedName("type")
  private String type = null;

  @SerializedName("ids")
  private List<String> ids = new ArrayList<String>();

  @SerializedName("vehicle_id")
  private String vehicleId = null;

  public JobRelation type(String type) {
    this.type = type;
    return this;
  }

   /**
   * Specifies the type of relation. It must be either of type &#x60;in_same_route&#x60;, &#x60;in_sequence&#x60; or &#x60;in_direct_sequence&#x60;.  &#x60;in_same_route&#x60;: As the name suggest, it enforces the specified services or shipments to be in the same route. It can be specified as follows:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_same_route\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;] } &#x60;&#x60;&#x60;  This enforces service i to be in the same route as service j no matter which vehicle will be employed. If a specific vehicle (driver) is required to conduct this, just add a &#x60;vehicle_id&#x60; like this:  &#x60;&#x60;&#x60; {    \&quot;type\&quot;: \&quot;in_same_route\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;],    \&quot;vehicle_id\&quot;: \&quot;vehicle1\&quot; } &#x60;&#x60;&#x60;  This not only enforce service i and j to be in the same route, but also makes sure that both services are in the route of &#x60;vehicle1&#x60;.  *Tip*: This way initial loads and vehicle routes can be modelled. For example, if your vehicles are already on the road and new orders come in, then vehicles can still be rescheduled subject to the orders that have already been assigned to these vehicles.    &#x60;in_sequence&#x60;: This relation type enforces n jobs to be in sequence. It can be specified as  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;] } &#x60;&#x60;&#x60;  which means that service j need to be in the same route as service i AND it needs to occur somewhere after service i. As described above if a specific vehicle needs to conduct this, just add &#x60;vehicle_id&#x60;.   &#x60;in_direct_sequence&#x60;: This enforces n services or shipments to be in direct sequence. It can be specified as  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;,\&quot;serv_k_id\&quot;] } &#x60;&#x60;&#x60;  yielding service j to occur directly after service i, and service k to occur directly after service j i.e. in strong order. Again, a vehicle can be assigned a priority by adding a &#x60;vehicle_id&#x60; to the relation.   *Special IDs*: If you look at the previous example and you want service i to be the first in the route, use the special ID &#x60;start&#x60; as follows:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;start\&quot;,\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;,\&quot;serv_k_id\&quot;] } &#x60;&#x60;&#x60;  Latter enforces the direct sequence of i, j and k at the beginning of the route. If this sequence should be bound to the end of the route, use the special ID &#x60;end&#x60; like this:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;service_j_id\&quot;,\&quot;serv_k_id\&quot;,\&quot;end\&quot;] } &#x60;&#x60;&#x60;  If you deal with services then you need to use the &#x27;id&#x27; of your services in the field &#x27;ids&#x27;. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use the shipment id plus the keyword &#x60;_pickup&#x60; or &#x60;_delivery&#x60;. For example, to ensure that the pickup and delivery of the shipment with the id &#x27;my_shipment&#x27; are direct neighbors, you need the following specification:  &#x60;&#x60;&#x60; {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;my_ship_pickup\&quot;,\&quot;my_ship_delivery\&quot;] } &#x60;&#x60;&#x60;  
   * @return type
  **/
  @Schema(example = "in_direct_sequence", required = true, description = "Specifies the type of relation. It must be either of type `in_same_route`, `in_sequence` or `in_direct_sequence`.  `in_same_route`: As the name suggest, it enforces the specified services or shipments to be in the same route. It can be specified as follows:  ```json {    \"type\": \"in_same_route\",    \"ids\": [\"serv_i_id\",\"serv_j_id\"] } ```  This enforces service i to be in the same route as service j no matter which vehicle will be employed. If a specific vehicle (driver) is required to conduct this, just add a `vehicle_id` like this:  ``` {    \"type\": \"in_same_route\",    \"ids\": [\"serv_i_id\",\"serv_j_id\"],    \"vehicle_id\": \"vehicle1\" } ```  This not only enforce service i and j to be in the same route, but also makes sure that both services are in the route of `vehicle1`.  *Tip*: This way initial loads and vehicle routes can be modelled. For example, if your vehicles are already on the road and new orders come in, then vehicles can still be rescheduled subject to the orders that have already been assigned to these vehicles.    `in_sequence`: This relation type enforces n jobs to be in sequence. It can be specified as  ```json {    \"type\": \"in_sequence\",    \"ids\": [\"serv_i_id\",\"serv_j_id\"] } ```  which means that service j need to be in the same route as service i AND it needs to occur somewhere after service i. As described above if a specific vehicle needs to conduct this, just add `vehicle_id`.   `in_direct_sequence`: This enforces n services or shipments to be in direct sequence. It can be specified as  ```json {    \"type\": \"in_direct_sequence\",    \"ids\": [\"serv_i_id\",\"serv_j_id\",\"serv_k_id\"] } ```  yielding service j to occur directly after service i, and service k to occur directly after service j i.e. in strong order. Again, a vehicle can be assigned a priority by adding a `vehicle_id` to the relation.   *Special IDs*: If you look at the previous example and you want service i to be the first in the route, use the special ID `start` as follows:  ```json {    \"type\": \"in_direct_sequence\",    \"ids\": [\"start\",\"serv_i_id\",\"serv_j_id\",\"serv_k_id\"] } ```  Latter enforces the direct sequence of i, j and k at the beginning of the route. If this sequence should be bound to the end of the route, use the special ID `end` like this:  ```json {    \"type\": \"in_direct_sequence\",    \"ids\": [\"serv_i_id\",\"service_j_id\",\"serv_k_id\",\"end\"] } ```  If you deal with services then you need to use the 'id' of your services in the field 'ids'. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use the shipment id plus the keyword `_pickup` or `_delivery`. For example, to ensure that the pickup and delivery of the shipment with the id 'my_shipment' are direct neighbors, you need the following specification:  ``` {    \"type\": \"in_direct_sequence\",    \"ids\": [\"my_ship_pickup\",\"my_ship_delivery\"] } ```  ")
  public String getType() {
    return type;
  }

  public void setType(String type) {
    this.type = type;
  }

  public JobRelation ids(List<String> ids) {
    this.ids = ids;
    return this;
  }

  public JobRelation addIdsItem(String idsItem) {
    this.ids.add(idsItem);
    return this;
  }

   /**
   * Specifies an array of shipment and/or service ids that are in relation. If you deal with services then you need to use the id of your services in ids. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use your shipment id plus the keyword &#x60;_pickup&#x60; or &#x60;_delivery&#x60;. If you want to place a service or shipment activity at the beginning of your route, use the special ID &#x60;start&#x60;. In turn, use &#x60;end&#x60; to place it at the end of the route.
   * @return ids
  **/
  @Schema(example = "[\"pickup-1\",\"pickup-2\"]", required = true, description = "Specifies an array of shipment and/or service ids that are in relation. If you deal with services then you need to use the id of your services in ids. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use your shipment id plus the keyword `_pickup` or `_delivery`. If you want to place a service or shipment activity at the beginning of your route, use the special ID `start`. In turn, use `end` to place it at the end of the route.")
  public List<String> getIds() {
    return ids;
  }

  public void setIds(List<String> ids) {
    this.ids = ids;
  }

  public JobRelation vehicleId(String vehicleId) {
    this.vehicleId = vehicleId;
    return this;
  }

   /**
   * Id of pre-assigned vehicle, i.e. the vehicle id that is determined to conduct the services and shipments in this relation.
   * @return vehicleId
  **/
  @Schema(example = "driver-Peter", description = "Id of pre-assigned vehicle, i.e. the vehicle id that is determined to conduct the services and shipments in this relation.")
  public String getVehicleId() {
    return vehicleId;
  }

  public void setVehicleId(String vehicleId) {
    this.vehicleId = vehicleId;
  }


  @Override
  public boolean equals(java.lang.Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }
    JobRelation jobRelation = (JobRelation) o;
    return Objects.equals(this.type, jobRelation.type) &&
        Objects.equals(this.ids, jobRelation.ids) &&
        Objects.equals(this.vehicleId, jobRelation.vehicleId);
  }

  @Override
  public int hashCode() {
    return Objects.hash(type, ids, vehicleId);
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class JobRelation {\n");
    
    sb.append("    type: ").append(toIndentedString(type)).append("\n");
    sb.append("    ids: ").append(toIndentedString(ids)).append("\n");
    sb.append("    vehicleId: ").append(toIndentedString(vehicleId)).append("\n");
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
