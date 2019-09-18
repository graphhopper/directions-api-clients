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
 * VehicleType
 */


public class VehicleType {
  @SerializedName("type_id")
  private String typeId = null;

  @SerializedName("profile")
  private Object profile = null;

  @SerializedName("capacity")
  private List<Integer> capacity = null;

  @SerializedName("speed_factor")
  private Double speedFactor = 1d;

  @SerializedName("service_time_factor")
  private Double serviceTimeFactor = 1d;

  @SerializedName("cost_per_meter")
  private Double costPerMeter = null;

  @SerializedName("cost_per_second")
  private Double costPerSecond = null;

  @SerializedName("cost_per_activation")
  private Double costPerActivation = null;

  @SerializedName("consider_traffic")
  private Boolean considerTraffic = false;

  /**
   * Specifies the network data provider. Either use [&#x60;openstreetmap&#x60;](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [&#x60;tomtom&#x60;](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).
   */
  @JsonAdapter(NetworkDataProviderEnum.Adapter.class)
  public enum NetworkDataProviderEnum {
    OPENSTREETMAP("openstreetmap"),
    TOMTOM("tomtom");

    private String value;

    NetworkDataProviderEnum(String value) {
      this.value = value;
    }
    public String getValue() {
      return value;
    }

    @Override
    public String toString() {
      return String.valueOf(value);
    }
    public static NetworkDataProviderEnum fromValue(String text) {
      for (NetworkDataProviderEnum b : NetworkDataProviderEnum.values()) {
        if (String.valueOf(b.value).equals(text)) {
          return b;
        }
      }
      return null;
    }
    public static class Adapter extends TypeAdapter<NetworkDataProviderEnum> {
      @Override
      public void write(final JsonWriter jsonWriter, final NetworkDataProviderEnum enumeration) throws IOException {
        jsonWriter.value(enumeration.getValue());
      }

      @Override
      public NetworkDataProviderEnum read(final JsonReader jsonReader) throws IOException {
        String value = jsonReader.nextString();
        return NetworkDataProviderEnum.fromValue(String.valueOf(value));
      }
    }
  }  @SerializedName("network_data_provider")
  private NetworkDataProviderEnum networkDataProvider = NetworkDataProviderEnum.OPENSTREETMAP;

  public VehicleType typeId(String typeId) {
    this.typeId = typeId;
    return this;
  }

   /**
   * Specifies the id of the vehicle type. If a vehicle needs to be of this type, it should refer to this with its type_id attribute.
   * @return typeId
  **/
  @Schema(example = "my-own-type", required = true, description = "Specifies the id of the vehicle type. If a vehicle needs to be of this type, it should refer to this with its type_id attribute.")
  public String getTypeId() {
    return typeId;
  }

  public void setTypeId(String typeId) {
    this.typeId = typeId;
  }

  public VehicleType profile(Object profile) {
    this.profile = profile;
    return this;
  }

   /**
   * Get profile
   * @return profile
  **/
  @Schema(description = "")
  public Object getProfile() {
    return profile;
  }

  public void setProfile(Object profile) {
    this.profile = profile;
  }

  public VehicleType capacity(List<Integer> capacity) {
    this.capacity = capacity;
    return this;
  }

  public VehicleType addCapacityItem(Integer capacityItem) {
    if (this.capacity == null) {
      this.capacity = new ArrayList<Integer>();
    }
    this.capacity.add(capacityItem);
    return this;
  }

   /**
   * Specifies an array of capacity dimension values which need to be int values. For example, if there are two dimensions such as volume and weight then it needs to be defined as [ 1000, 300 ] assuming a maximum volume of 1000 and a maximum weight of 300.
   * @return capacity
  **/
  @Schema(example = "[100,500]", description = "Specifies an array of capacity dimension values which need to be int values. For example, if there are two dimensions such as volume and weight then it needs to be defined as [ 1000, 300 ] assuming a maximum volume of 1000 and a maximum weight of 300.")
  public List<Integer> getCapacity() {
    return capacity;
  }

  public void setCapacity(List<Integer> capacity) {
    this.capacity = capacity;
  }

  public VehicleType speedFactor(Double speedFactor) {
    this.speedFactor = speedFactor;
    return this;
  }

   /**
   * Specifies a speed factor for this vehicle type. If the vehicle that uses this type needs to be only half as fast as what is actually calculated with our routing engine then set the speed factor to 0.5.
   * @return speedFactor
  **/
  @Schema(description = "Specifies a speed factor for this vehicle type. If the vehicle that uses this type needs to be only half as fast as what is actually calculated with our routing engine then set the speed factor to 0.5.")
  public Double getSpeedFactor() {
    return speedFactor;
  }

  public void setSpeedFactor(Double speedFactor) {
    this.speedFactor = speedFactor;
  }

  public VehicleType serviceTimeFactor(Double serviceTimeFactor) {
    this.serviceTimeFactor = serviceTimeFactor;
    return this;
  }

   /**
   * Specifies a service time factor for this vehicle type. If the vehicle/driver that uses this type is able to conduct the service as double as fast as it is determined in the corresponding service or shipment then set it to 0.5.
   * @return serviceTimeFactor
  **/
  @Schema(description = "Specifies a service time factor for this vehicle type. If the vehicle/driver that uses this type is able to conduct the service as double as fast as it is determined in the corresponding service or shipment then set it to 0.5.")
  public Double getServiceTimeFactor() {
    return serviceTimeFactor;
  }

  public void setServiceTimeFactor(Double serviceTimeFactor) {
    this.serviceTimeFactor = serviceTimeFactor;
  }

  public VehicleType costPerMeter(Double costPerMeter) {
    this.costPerMeter = costPerMeter;
    return this;
  }

   /**
   * **_BETA feature_**! Cost parameter per distance unit, here meter is used
   * @return costPerMeter
  **/
  @Schema(description = "**_BETA feature_**! Cost parameter per distance unit, here meter is used")
  public Double getCostPerMeter() {
    return costPerMeter;
  }

  public void setCostPerMeter(Double costPerMeter) {
    this.costPerMeter = costPerMeter;
  }

  public VehicleType costPerSecond(Double costPerSecond) {
    this.costPerSecond = costPerSecond;
    return this;
  }

   /**
   * **_BETA feature_**! Cost parameter per time unit, here second is used
   * @return costPerSecond
  **/
  @Schema(description = "**_BETA feature_**! Cost parameter per time unit, here second is used")
  public Double getCostPerSecond() {
    return costPerSecond;
  }

  public void setCostPerSecond(Double costPerSecond) {
    this.costPerSecond = costPerSecond;
  }

  public VehicleType costPerActivation(Double costPerActivation) {
    this.costPerActivation = costPerActivation;
    return this;
  }

   /**
   * **_BETA feature_**! Cost parameter vehicle activation, i.e. fixed costs per vehicle
   * @return costPerActivation
  **/
  @Schema(description = "**_BETA feature_**! Cost parameter vehicle activation, i.e. fixed costs per vehicle")
  public Double getCostPerActivation() {
    return costPerActivation;
  }

  public void setCostPerActivation(Double costPerActivation) {
    this.costPerActivation = costPerActivation;
  }

  public VehicleType considerTraffic(Boolean considerTraffic) {
    this.considerTraffic = considerTraffic;
    return this;
  }

   /**
   * Specifies whether traffic should be considered. if \&quot;tomtom\&quot; is used and this is false, free flow travel times from \&quot;tomtom\&quot; are calculated. If this is true, historical traffic info are used. We do not yet have traffic data for \&quot;openstreetmap\&quot;, thus, setting this true has no effect at all.
   * @return considerTraffic
  **/
  @Schema(description = "Specifies whether traffic should be considered. if \"tomtom\" is used and this is false, free flow travel times from \"tomtom\" are calculated. If this is true, historical traffic info are used. We do not yet have traffic data for \"openstreetmap\", thus, setting this true has no effect at all.")
  public Boolean isConsiderTraffic() {
    return considerTraffic;
  }

  public void setConsiderTraffic(Boolean considerTraffic) {
    this.considerTraffic = considerTraffic;
  }

  public VehicleType networkDataProvider(NetworkDataProviderEnum networkDataProvider) {
    this.networkDataProvider = networkDataProvider;
    return this;
  }

   /**
   * Specifies the network data provider. Either use [&#x60;openstreetmap&#x60;](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [&#x60;tomtom&#x60;](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).
   * @return networkDataProvider
  **/
  @Schema(description = "Specifies the network data provider. Either use [`openstreetmap`](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [`tomtom`](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).")
  public NetworkDataProviderEnum getNetworkDataProvider() {
    return networkDataProvider;
  }

  public void setNetworkDataProvider(NetworkDataProviderEnum networkDataProvider) {
    this.networkDataProvider = networkDataProvider;
  }


  @Override
  public boolean equals(java.lang.Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }
    VehicleType vehicleType = (VehicleType) o;
    return Objects.equals(this.typeId, vehicleType.typeId) &&
        Objects.equals(this.profile, vehicleType.profile) &&
        Objects.equals(this.capacity, vehicleType.capacity) &&
        Objects.equals(this.speedFactor, vehicleType.speedFactor) &&
        Objects.equals(this.serviceTimeFactor, vehicleType.serviceTimeFactor) &&
        Objects.equals(this.costPerMeter, vehicleType.costPerMeter) &&
        Objects.equals(this.costPerSecond, vehicleType.costPerSecond) &&
        Objects.equals(this.costPerActivation, vehicleType.costPerActivation) &&
        Objects.equals(this.considerTraffic, vehicleType.considerTraffic) &&
        Objects.equals(this.networkDataProvider, vehicleType.networkDataProvider);
  }

  @Override
  public int hashCode() {
    return Objects.hash(typeId, profile, capacity, speedFactor, serviceTimeFactor, costPerMeter, costPerSecond, costPerActivation, considerTraffic, networkDataProvider);
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class VehicleType {\n");
    
    sb.append("    typeId: ").append(toIndentedString(typeId)).append("\n");
    sb.append("    profile: ").append(toIndentedString(profile)).append("\n");
    sb.append("    capacity: ").append(toIndentedString(capacity)).append("\n");
    sb.append("    speedFactor: ").append(toIndentedString(speedFactor)).append("\n");
    sb.append("    serviceTimeFactor: ").append(toIndentedString(serviceTimeFactor)).append("\n");
    sb.append("    costPerMeter: ").append(toIndentedString(costPerMeter)).append("\n");
    sb.append("    costPerSecond: ").append(toIndentedString(costPerSecond)).append("\n");
    sb.append("    costPerActivation: ").append(toIndentedString(costPerActivation)).append("\n");
    sb.append("    considerTraffic: ").append(toIndentedString(considerTraffic)).append("\n");
    sb.append("    networkDataProvider: ").append(toIndentedString(networkDataProvider)).append("\n");
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
