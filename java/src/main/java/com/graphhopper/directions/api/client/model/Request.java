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
import com.graphhopper.directions.api.client.model.Algorithm;
import com.graphhopper.directions.api.client.model.CostMatrix;
import com.graphhopper.directions.api.client.model.ModelConfiguration;
import com.graphhopper.directions.api.client.model.Objective;
import com.graphhopper.directions.api.client.model.Service;
import com.graphhopper.directions.api.client.model.Shipment;
import com.graphhopper.directions.api.client.model.Vehicle;
import com.graphhopper.directions.api.client.model.VehicleType;
import io.swagger.v3.oas.annotations.media.Schema;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
/**
 * Request
 */


public class Request {
  @SerializedName("vehicles")
  private List<Vehicle> vehicles = null;

  @SerializedName("vehicle_types")
  private List<VehicleType> vehicleTypes = null;

  @SerializedName("services")
  private List<Service> services = null;

  @SerializedName("shipments")
  private List<Shipment> shipments = null;

  @SerializedName("relations")
  private List<Object> relations = null;

  @SerializedName("algorithm")
  private Algorithm algorithm = null;

  @SerializedName("objectives")
  private List<Objective> objectives = null;

  @SerializedName("cost_matrices")
  private List<CostMatrix> costMatrices = null;

  @SerializedName("configuration")
  private ModelConfiguration _configuration = null;

  public Request vehicles(List<Vehicle> vehicles) {
    this.vehicles = vehicles;
    return this;
  }

  public Request addVehiclesItem(Vehicle vehiclesItem) {
    if (this.vehicles == null) {
      this.vehicles = new ArrayList<Vehicle>();
    }
    this.vehicles.add(vehiclesItem);
    return this;
  }

   /**
   * Specifies the available vehicles.
   * @return vehicles
  **/
  @Schema(description = "Specifies the available vehicles.")
  public List<Vehicle> getVehicles() {
    return vehicles;
  }

  public void setVehicles(List<Vehicle> vehicles) {
    this.vehicles = vehicles;
  }

  public Request vehicleTypes(List<VehicleType> vehicleTypes) {
    this.vehicleTypes = vehicleTypes;
    return this;
  }

  public Request addVehicleTypesItem(VehicleType vehicleTypesItem) {
    if (this.vehicleTypes == null) {
      this.vehicleTypes = new ArrayList<VehicleType>();
    }
    this.vehicleTypes.add(vehicleTypesItem);
    return this;
  }

   /**
   * Specifies the available vehicle types that are referred to by the specified vehicles.
   * @return vehicleTypes
  **/
  @Schema(description = "Specifies the available vehicle types that are referred to by the specified vehicles.")
  public List<VehicleType> getVehicleTypes() {
    return vehicleTypes;
  }

  public void setVehicleTypes(List<VehicleType> vehicleTypes) {
    this.vehicleTypes = vehicleTypes;
  }

  public Request services(List<Service> services) {
    this.services = services;
    return this;
  }

  public Request addServicesItem(Service servicesItem) {
    if (this.services == null) {
      this.services = new ArrayList<Service>();
    }
    this.services.add(servicesItem);
    return this;
  }

   /**
   * Specifies the available services, i.e. pickup, delivery or any other points to be visited by vehicles. Each service only involves exactly one location.
   * @return services
  **/
  @Schema(description = "Specifies the available services, i.e. pickup, delivery or any other points to be visited by vehicles. Each service only involves exactly one location.")
  public List<Service> getServices() {
    return services;
  }

  public void setServices(List<Service> services) {
    this.services = services;
  }

  public Request shipments(List<Shipment> shipments) {
    this.shipments = shipments;
    return this;
  }

  public Request addShipmentsItem(Shipment shipmentsItem) {
    if (this.shipments == null) {
      this.shipments = new ArrayList<Shipment>();
    }
    this.shipments.add(shipmentsItem);
    return this;
  }

   /**
   * Specifies the available shipments, i.e. pickup AND delivery points to be visited by vehicles subsequently. Each shipment involves exactly two locations, a pickup and a delivery location.
   * @return shipments
  **/
  @Schema(description = "Specifies the available shipments, i.e. pickup AND delivery points to be visited by vehicles subsequently. Each shipment involves exactly two locations, a pickup and a delivery location.")
  public List<Shipment> getShipments() {
    return shipments;
  }

  public void setShipments(List<Shipment> shipments) {
    this.shipments = shipments;
  }

  public Request relations(List<Object> relations) {
    this.relations = relations;
    return this;
  }

  public Request addRelationsItem(Object relationsItem) {
    if (this.relations == null) {
      this.relations = new ArrayList<Object>();
    }
    this.relations.add(relationsItem);
    return this;
  }

   /**
   * Specifies an arbitrary number of additional relations between and among services and shipments.
   * @return relations
  **/
  @Schema(description = "Specifies an arbitrary number of additional relations between and among services and shipments.")
  public List<Object> getRelations() {
    return relations;
  }

  public void setRelations(List<Object> relations) {
    this.relations = relations;
  }

  public Request algorithm(Algorithm algorithm) {
    this.algorithm = algorithm;
    return this;
  }

   /**
   * Get algorithm
   * @return algorithm
  **/
  @Schema(description = "")
  public Algorithm getAlgorithm() {
    return algorithm;
  }

  public void setAlgorithm(Algorithm algorithm) {
    this.algorithm = algorithm;
  }

  public Request objectives(List<Objective> objectives) {
    this.objectives = objectives;
    return this;
  }

  public Request addObjectivesItem(Objective objectivesItem) {
    if (this.objectives == null) {
      this.objectives = new ArrayList<Objective>();
    }
    this.objectives.add(objectivesItem);
    return this;
  }

   /**
   * Specifies an array of objective functions. This tells the algorithm the objective of the optimization.
   * @return objectives
  **/
  @Schema(example = "[{\"type\":\"min\",\"value\":\"vehicles\"},{\"type\":\"min\",\"value\":\"completion_time\"}]", description = "Specifies an array of objective functions. This tells the algorithm the objective of the optimization.")
  public List<Objective> getObjectives() {
    return objectives;
  }

  public void setObjectives(List<Objective> objectives) {
    this.objectives = objectives;
  }

  public Request costMatrices(List<CostMatrix> costMatrices) {
    this.costMatrices = costMatrices;
    return this;
  }

  public Request addCostMatricesItem(CostMatrix costMatricesItem) {
    if (this.costMatrices == null) {
      this.costMatrices = new ArrayList<CostMatrix>();
    }
    this.costMatrices.add(costMatricesItem);
    return this;
  }

   /**
   * Specifies an array of cost matrix objects. This is used if you want to provide custom distance and/or time matrix values e.g. for time-dependent or indoor routing like for warehouses.
   * @return costMatrices
  **/
  @Schema(example = "[{\"profile\":\"car\",\"location_ids\":[\"start\",\"Dammstrasse\",\"Bergstrasse\",\"Koppstrasse\",\"start2\",\"nirvana\"],\"data\":{\"times\":[[0,1000,1400,2000,0,4000],[1000,0,1000,2100,1000,4000],[1400,1000,0,1100,1100,4000],[2000,2100,1100,0,1200,4000],[0,1000,1400,2000,0,4000],[4000,4000,4000,4000,4000,4000]],\"distances\":[[0,1000,1400,2000,0,4000],[1000,0,1000,2100,1000,4000],[1400,1000,0,1100,1100,4000],[2000,2100,1100,0,1200,4000],[0,1000,1400,2000,0,4000],[4000,4000,4000,4000,4000,4000]]}}]", description = "Specifies an array of cost matrix objects. This is used if you want to provide custom distance and/or time matrix values e.g. for time-dependent or indoor routing like for warehouses.")
  public List<CostMatrix> getCostMatrices() {
    return costMatrices;
  }

  public void setCostMatrices(List<CostMatrix> costMatrices) {
    this.costMatrices = costMatrices;
  }

  public Request _configuration(ModelConfiguration _configuration) {
    this._configuration = _configuration;
    return this;
  }

   /**
   * Get _configuration
   * @return _configuration
  **/
  @Schema(description = "")
  public ModelConfiguration getConfiguration() {
    return _configuration;
  }

  public void setConfiguration(ModelConfiguration _configuration) {
    this._configuration = _configuration;
  }


  @Override
  public boolean equals(java.lang.Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }
    Request request = (Request) o;
    return Objects.equals(this.vehicles, request.vehicles) &&
        Objects.equals(this.vehicleTypes, request.vehicleTypes) &&
        Objects.equals(this.services, request.services) &&
        Objects.equals(this.shipments, request.shipments) &&
        Objects.equals(this.relations, request.relations) &&
        Objects.equals(this.algorithm, request.algorithm) &&
        Objects.equals(this.objectives, request.objectives) &&
        Objects.equals(this.costMatrices, request.costMatrices) &&
        Objects.equals(this._configuration, request._configuration);
  }

  @Override
  public int hashCode() {
    return Objects.hash(vehicles, vehicleTypes, services, shipments, relations, algorithm, objectives, costMatrices, _configuration);
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class Request {\n");
    
    sb.append("    vehicles: ").append(toIndentedString(vehicles)).append("\n");
    sb.append("    vehicleTypes: ").append(toIndentedString(vehicleTypes)).append("\n");
    sb.append("    services: ").append(toIndentedString(services)).append("\n");
    sb.append("    shipments: ").append(toIndentedString(shipments)).append("\n");
    sb.append("    relations: ").append(toIndentedString(relations)).append("\n");
    sb.append("    algorithm: ").append(toIndentedString(algorithm)).append("\n");
    sb.append("    objectives: ").append(toIndentedString(objectives)).append("\n");
    sb.append("    costMatrices: ").append(toIndentedString(costMatrices)).append("\n");
    sb.append("    _configuration: ").append(toIndentedString(_configuration)).append("\n");
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
