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
/**
 * Objective
 */


public class Objective {
  /**
   * Type of objective function, i.e. &#x60;min&#x60; or &#x60;min-max&#x60;.   * &#x60;min&#x60;: Minimizes the objective value.  * &#x60;min-max&#x60;: Minimizes the maximum objective value.  For instance, &#x60;min&#x60; -&gt; &#x60;vehicles&#x60; minimizes the number of employed vehicles. &#x60;min&#x60; -&gt; &#x60;completion_time&#x60; minimizes the sum of your vehicle routes&#x27; completion time.  If you use, for example, &#x60;min-max&#x60; -&gt; &#x60;completion_time&#x60;, it minimizes the maximum of your vehicle routes&#x27; completion time, i.e. it minimizes the overall makespan. This only makes sense if you have more than one vehicle. In case of one vehicle, switching from &#x60;min&#x60; to &#x60;min-max&#x60; should not have any impact. If you have more than one vehicle, then the algorithm tries to constantly move stops from one vehicle to another such that the completion time of longest vehicle route can be further reduced. For example, if you have one vehicle that takes 8 hours to serve all customers, adding another vehicle (and using &#x60;min-max&#x60;) might halve the time to serve all customers to 4 hours. However, this usually comes with higher transport costs.  If you want to minimize &#x60;vehicles&#x60; first and, second, &#x60;completion_time&#x60;, you can also combine different objectives like this:  &#x60;&#x60;&#x60;json \&quot;objectives\&quot; : [    {       \&quot;type\&quot;: \&quot;min\&quot;,       \&quot;value\&quot;: \&quot;vehicles\&quot;    },    {       \&quot;type\&quot;: \&quot;min\&quot;,       \&quot;value\&quot;: \&quot;completion_time\&quot;    } ] &#x60;&#x60;&#x60;  If you want to balance activities or the number of stops among all employed drivers, you need to specify it as follows:  &#x60;&#x60;&#x60;json \&quot;objectives\&quot; : [    {       \&quot;type\&quot;: \&quot;min-max\&quot;,       \&quot;value\&quot;: \&quot;completion_time\&quot;    },    {       \&quot;type\&quot;: \&quot;min-max\&quot;,       \&quot;value\&quot;: \&quot;activities\&quot;    } ] &#x60;&#x60;&#x60; 
   */
  @JsonAdapter(TypeEnum.Adapter.class)
  public enum TypeEnum {
    MIN("min"),
    MIN_MAX("min-max");

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
  private TypeEnum type = TypeEnum.MIN;

  /**
   * The value of the objective function. The objective value &#x60;transport_time&#x60; solely considers the time your drivers spend on the road, i.e. transport time. In contrary to &#x60;transport_time&#x60;, &#x60;completion_time&#x60; also takes waiting times at customer sites into account. The &#x60;completion_time&#x60; of a route is defined as the time from starting to ending the route, i.e. the route&#x27;s transport time, the sum of waiting times plus the sum of activity durations. Note that choosing &#x60;transport_time&#x60; or &#x60;completion_time&#x60; only makes a difference if you specified time windows for your services/shipments since only in scenarios with time windows waiting times can occur. The objective value &#x60;vehicles&#x60; can only be used along with &#x60;min&#x60; and minimizes vehicles. 
   */
  @JsonAdapter(ValueEnum.Adapter.class)
  public enum ValueEnum {
    COMPLETION_TIME("completion_time"),
    TRANSPORT_TIME("transport_time"),
    VEHICLES("vehicles"),
    ACTIVITIES("activities");

    private String value;

    ValueEnum(String value) {
      this.value = value;
    }
    public String getValue() {
      return value;
    }

    @Override
    public String toString() {
      return String.valueOf(value);
    }
    public static ValueEnum fromValue(String text) {
      for (ValueEnum b : ValueEnum.values()) {
        if (String.valueOf(b.value).equals(text)) {
          return b;
        }
      }
      return null;
    }
    public static class Adapter extends TypeAdapter<ValueEnum> {
      @Override
      public void write(final JsonWriter jsonWriter, final ValueEnum enumeration) throws IOException {
        jsonWriter.value(enumeration.getValue());
      }

      @Override
      public ValueEnum read(final JsonReader jsonReader) throws IOException {
        String value = jsonReader.nextString();
        return ValueEnum.fromValue(String.valueOf(value));
      }
    }
  }  @SerializedName("value")
  private ValueEnum value = ValueEnum.TRANSPORT_TIME;

  public Objective type(TypeEnum type) {
    this.type = type;
    return this;
  }

   /**
   * Type of objective function, i.e. &#x60;min&#x60; or &#x60;min-max&#x60;.   * &#x60;min&#x60;: Minimizes the objective value.  * &#x60;min-max&#x60;: Minimizes the maximum objective value.  For instance, &#x60;min&#x60; -&gt; &#x60;vehicles&#x60; minimizes the number of employed vehicles. &#x60;min&#x60; -&gt; &#x60;completion_time&#x60; minimizes the sum of your vehicle routes&#x27; completion time.  If you use, for example, &#x60;min-max&#x60; -&gt; &#x60;completion_time&#x60;, it minimizes the maximum of your vehicle routes&#x27; completion time, i.e. it minimizes the overall makespan. This only makes sense if you have more than one vehicle. In case of one vehicle, switching from &#x60;min&#x60; to &#x60;min-max&#x60; should not have any impact. If you have more than one vehicle, then the algorithm tries to constantly move stops from one vehicle to another such that the completion time of longest vehicle route can be further reduced. For example, if you have one vehicle that takes 8 hours to serve all customers, adding another vehicle (and using &#x60;min-max&#x60;) might halve the time to serve all customers to 4 hours. However, this usually comes with higher transport costs.  If you want to minimize &#x60;vehicles&#x60; first and, second, &#x60;completion_time&#x60;, you can also combine different objectives like this:  &#x60;&#x60;&#x60;json \&quot;objectives\&quot; : [    {       \&quot;type\&quot;: \&quot;min\&quot;,       \&quot;value\&quot;: \&quot;vehicles\&quot;    },    {       \&quot;type\&quot;: \&quot;min\&quot;,       \&quot;value\&quot;: \&quot;completion_time\&quot;    } ] &#x60;&#x60;&#x60;  If you want to balance activities or the number of stops among all employed drivers, you need to specify it as follows:  &#x60;&#x60;&#x60;json \&quot;objectives\&quot; : [    {       \&quot;type\&quot;: \&quot;min-max\&quot;,       \&quot;value\&quot;: \&quot;completion_time\&quot;    },    {       \&quot;type\&quot;: \&quot;min-max\&quot;,       \&quot;value\&quot;: \&quot;activities\&quot;    } ] &#x60;&#x60;&#x60; 
   * @return type
  **/
  @Schema(required = true, description = "Type of objective function, i.e. `min` or `min-max`.   * `min`: Minimizes the objective value.  * `min-max`: Minimizes the maximum objective value.  For instance, `min` -> `vehicles` minimizes the number of employed vehicles. `min` -> `completion_time` minimizes the sum of your vehicle routes' completion time.  If you use, for example, `min-max` -> `completion_time`, it minimizes the maximum of your vehicle routes' completion time, i.e. it minimizes the overall makespan. This only makes sense if you have more than one vehicle. In case of one vehicle, switching from `min` to `min-max` should not have any impact. If you have more than one vehicle, then the algorithm tries to constantly move stops from one vehicle to another such that the completion time of longest vehicle route can be further reduced. For example, if you have one vehicle that takes 8 hours to serve all customers, adding another vehicle (and using `min-max`) might halve the time to serve all customers to 4 hours. However, this usually comes with higher transport costs.  If you want to minimize `vehicles` first and, second, `completion_time`, you can also combine different objectives like this:  ```json \"objectives\" : [    {       \"type\": \"min\",       \"value\": \"vehicles\"    },    {       \"type\": \"min\",       \"value\": \"completion_time\"    } ] ```  If you want to balance activities or the number of stops among all employed drivers, you need to specify it as follows:  ```json \"objectives\" : [    {       \"type\": \"min-max\",       \"value\": \"completion_time\"    },    {       \"type\": \"min-max\",       \"value\": \"activities\"    } ] ``` ")
  public TypeEnum getType() {
    return type;
  }

  public void setType(TypeEnum type) {
    this.type = type;
  }

  public Objective value(ValueEnum value) {
    this.value = value;
    return this;
  }

   /**
   * The value of the objective function. The objective value &#x60;transport_time&#x60; solely considers the time your drivers spend on the road, i.e. transport time. In contrary to &#x60;transport_time&#x60;, &#x60;completion_time&#x60; also takes waiting times at customer sites into account. The &#x60;completion_time&#x60; of a route is defined as the time from starting to ending the route, i.e. the route&#x27;s transport time, the sum of waiting times plus the sum of activity durations. Note that choosing &#x60;transport_time&#x60; or &#x60;completion_time&#x60; only makes a difference if you specified time windows for your services/shipments since only in scenarios with time windows waiting times can occur. The objective value &#x60;vehicles&#x60; can only be used along with &#x60;min&#x60; and minimizes vehicles. 
   * @return value
  **/
  @Schema(required = true, description = "The value of the objective function. The objective value `transport_time` solely considers the time your drivers spend on the road, i.e. transport time. In contrary to `transport_time`, `completion_time` also takes waiting times at customer sites into account. The `completion_time` of a route is defined as the time from starting to ending the route, i.e. the route's transport time, the sum of waiting times plus the sum of activity durations. Note that choosing `transport_time` or `completion_time` only makes a difference if you specified time windows for your services/shipments since only in scenarios with time windows waiting times can occur. The objective value `vehicles` can only be used along with `min` and minimizes vehicles. ")
  public ValueEnum getValue() {
    return value;
  }

  public void setValue(ValueEnum value) {
    this.value = value;
  }


  @Override
  public boolean equals(java.lang.Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }
    Objective objective = (Objective) o;
    return Objects.equals(this.type, objective.type) &&
        Objects.equals(this.value, objective.value);
  }

  @Override
  public int hashCode() {
    return Objects.hash(type, value);
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class Objective {\n");
    
    sb.append("    type: ").append(toIndentedString(type)).append("\n");
    sb.append("    value: ").append(toIndentedString(value)).append("\n");
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
