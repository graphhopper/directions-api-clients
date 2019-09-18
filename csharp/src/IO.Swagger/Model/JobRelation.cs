/* 
 * GraphHopper Directions API
 *
 *  With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Clients  To speed up development and make coding easier, we offer the following clients:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon - -- -- -- -- --|:- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions for motor vehicles such as `car` or `truck` are only considered with `edge_based=true` for the Routing (other APIs will follow).** Or if you already use `ch.disable=true` no additional parameter is required to consider turn restrictions for motor vehicles.  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon - -- -- -- -- --|:- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) 
 *
 * OpenAPI spec version: 1.0.0
 * Contact: support@graphhopper.com
 * Generated by: https://github.com/swagger-api/swagger-codegen.git
 */
using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Runtime.Serialization;
using Newtonsoft.Json;
using Newtonsoft.Json.Converters;
using System.ComponentModel.DataAnnotations;
using SwaggerDateConverter = IO.Swagger.Client.SwaggerDateConverter;

namespace IO.Swagger.Model
{
    /// <summary>
    /// JobRelation
    /// </summary>
    [DataContract]
        public partial class JobRelation :  IEquatable<JobRelation>, IValidatableObject
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="JobRelation" /> class.
        /// </summary>
        /// <param name="type">Specifies the type of relation. It must be either of type &#x60;in_same_route&#x60;, &#x60;in_sequence&#x60; or &#x60;in_direct_sequence&#x60;.  &#x60;in_same_route&#x60;: As the name suggest, it enforces the specified services or shipments to be in the same route. It can be specified as follows:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_same_route\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;] } &#x60;&#x60;&#x60;  This enforces service i to be in the same route as service j no matter which vehicle will be employed. If a specific vehicle (driver) is required to conduct this, just add a &#x60;vehicle_id&#x60; like this:  &#x60;&#x60;&#x60; {    \&quot;type\&quot;: \&quot;in_same_route\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;],    \&quot;vehicle_id\&quot;: \&quot;vehicle1\&quot; } &#x60;&#x60;&#x60;  This not only enforce service i and j to be in the same route, but also makes sure that both services are in the route of &#x60;vehicle1&#x60;.  *Tip*: This way initial loads and vehicle routes can be modelled. For example, if your vehicles are already on the road and new orders come in, then vehicles can still be rescheduled subject to the orders that have already been assigned to these vehicles.    &#x60;in_sequence&#x60;: This relation type enforces n jobs to be in sequence. It can be specified as  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;] } &#x60;&#x60;&#x60;  which means that service j need to be in the same route as service i AND it needs to occur somewhere after service i. As described above if a specific vehicle needs to conduct this, just add &#x60;vehicle_id&#x60;.   &#x60;in_direct_sequence&#x60;: This enforces n services or shipments to be in direct sequence. It can be specified as  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;,\&quot;serv_k_id\&quot;] } &#x60;&#x60;&#x60;  yielding service j to occur directly after service i, and service k to occur directly after service j i.e. in strong order. Again, a vehicle can be assigned a priority by adding a &#x60;vehicle_id&#x60; to the relation.   *Special IDs*: If you look at the previous example and you want service i to be the first in the route, use the special ID &#x60;start&#x60; as follows:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;start\&quot;,\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;,\&quot;serv_k_id\&quot;] } &#x60;&#x60;&#x60;  Latter enforces the direct sequence of i, j and k at the beginning of the route. If this sequence should be bound to the end of the route, use the special ID &#x60;end&#x60; like this:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;service_j_id\&quot;,\&quot;serv_k_id\&quot;,\&quot;end\&quot;] } &#x60;&#x60;&#x60;  If you deal with services then you need to use the &#x27;id&#x27; of your services in the field &#x27;ids&#x27;. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use the shipment id plus the keyword &#x60;_pickup&#x60; or &#x60;_delivery&#x60;. For example, to ensure that the pickup and delivery of the shipment with the id &#x27;my_shipment&#x27; are direct neighbors, you need the following specification:  &#x60;&#x60;&#x60; {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;my_ship_pickup\&quot;,\&quot;my_ship_delivery\&quot;] } &#x60;&#x60;&#x60;   (required).</param>
        /// <param name="ids">Specifies an array of shipment and/or service ids that are in relation. If you deal with services then you need to use the id of your services in ids. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use your shipment id plus the keyword &#x60;_pickup&#x60; or &#x60;_delivery&#x60;. If you want to place a service or shipment activity at the beginning of your route, use the special ID &#x60;start&#x60;. In turn, use &#x60;end&#x60; to place it at the end of the route. (required).</param>
        /// <param name="vehicleId">Id of pre-assigned vehicle, i.e. the vehicle id that is determined to conduct the services and shipments in this relation..</param>
        public JobRelation(string type = default(string), List<string> ids = default(List<string>), string vehicleId = default(string))
        {
            // to ensure "type" is required (not null)
            if (type == null)
            {
                throw new InvalidDataException("type is a required property for JobRelation and cannot be null");
            }
            else
            {
                this.Type = type;
            }
            // to ensure "ids" is required (not null)
            if (ids == null)
            {
                throw new InvalidDataException("ids is a required property for JobRelation and cannot be null");
            }
            else
            {
                this.Ids = ids;
            }
            this.VehicleId = vehicleId;
        }
        
        /// <summary>
        /// Specifies the type of relation. It must be either of type &#x60;in_same_route&#x60;, &#x60;in_sequence&#x60; or &#x60;in_direct_sequence&#x60;.  &#x60;in_same_route&#x60;: As the name suggest, it enforces the specified services or shipments to be in the same route. It can be specified as follows:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_same_route\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;] } &#x60;&#x60;&#x60;  This enforces service i to be in the same route as service j no matter which vehicle will be employed. If a specific vehicle (driver) is required to conduct this, just add a &#x60;vehicle_id&#x60; like this:  &#x60;&#x60;&#x60; {    \&quot;type\&quot;: \&quot;in_same_route\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;],    \&quot;vehicle_id\&quot;: \&quot;vehicle1\&quot; } &#x60;&#x60;&#x60;  This not only enforce service i and j to be in the same route, but also makes sure that both services are in the route of &#x60;vehicle1&#x60;.  *Tip*: This way initial loads and vehicle routes can be modelled. For example, if your vehicles are already on the road and new orders come in, then vehicles can still be rescheduled subject to the orders that have already been assigned to these vehicles.    &#x60;in_sequence&#x60;: This relation type enforces n jobs to be in sequence. It can be specified as  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;] } &#x60;&#x60;&#x60;  which means that service j need to be in the same route as service i AND it needs to occur somewhere after service i. As described above if a specific vehicle needs to conduct this, just add &#x60;vehicle_id&#x60;.   &#x60;in_direct_sequence&#x60;: This enforces n services or shipments to be in direct sequence. It can be specified as  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;,\&quot;serv_k_id\&quot;] } &#x60;&#x60;&#x60;  yielding service j to occur directly after service i, and service k to occur directly after service j i.e. in strong order. Again, a vehicle can be assigned a priority by adding a &#x60;vehicle_id&#x60; to the relation.   *Special IDs*: If you look at the previous example and you want service i to be the first in the route, use the special ID &#x60;start&#x60; as follows:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;start\&quot;,\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;,\&quot;serv_k_id\&quot;] } &#x60;&#x60;&#x60;  Latter enforces the direct sequence of i, j and k at the beginning of the route. If this sequence should be bound to the end of the route, use the special ID &#x60;end&#x60; like this:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;service_j_id\&quot;,\&quot;serv_k_id\&quot;,\&quot;end\&quot;] } &#x60;&#x60;&#x60;  If you deal with services then you need to use the &#x27;id&#x27; of your services in the field &#x27;ids&#x27;. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use the shipment id plus the keyword &#x60;_pickup&#x60; or &#x60;_delivery&#x60;. For example, to ensure that the pickup and delivery of the shipment with the id &#x27;my_shipment&#x27; are direct neighbors, you need the following specification:  &#x60;&#x60;&#x60; {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;my_ship_pickup\&quot;,\&quot;my_ship_delivery\&quot;] } &#x60;&#x60;&#x60;  
        /// </summary>
        /// <value>Specifies the type of relation. It must be either of type &#x60;in_same_route&#x60;, &#x60;in_sequence&#x60; or &#x60;in_direct_sequence&#x60;.  &#x60;in_same_route&#x60;: As the name suggest, it enforces the specified services or shipments to be in the same route. It can be specified as follows:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_same_route\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;] } &#x60;&#x60;&#x60;  This enforces service i to be in the same route as service j no matter which vehicle will be employed. If a specific vehicle (driver) is required to conduct this, just add a &#x60;vehicle_id&#x60; like this:  &#x60;&#x60;&#x60; {    \&quot;type\&quot;: \&quot;in_same_route\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;],    \&quot;vehicle_id\&quot;: \&quot;vehicle1\&quot; } &#x60;&#x60;&#x60;  This not only enforce service i and j to be in the same route, but also makes sure that both services are in the route of &#x60;vehicle1&#x60;.  *Tip*: This way initial loads and vehicle routes can be modelled. For example, if your vehicles are already on the road and new orders come in, then vehicles can still be rescheduled subject to the orders that have already been assigned to these vehicles.    &#x60;in_sequence&#x60;: This relation type enforces n jobs to be in sequence. It can be specified as  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;] } &#x60;&#x60;&#x60;  which means that service j need to be in the same route as service i AND it needs to occur somewhere after service i. As described above if a specific vehicle needs to conduct this, just add &#x60;vehicle_id&#x60;.   &#x60;in_direct_sequence&#x60;: This enforces n services or shipments to be in direct sequence. It can be specified as  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;,\&quot;serv_k_id\&quot;] } &#x60;&#x60;&#x60;  yielding service j to occur directly after service i, and service k to occur directly after service j i.e. in strong order. Again, a vehicle can be assigned a priority by adding a &#x60;vehicle_id&#x60; to the relation.   *Special IDs*: If you look at the previous example and you want service i to be the first in the route, use the special ID &#x60;start&#x60; as follows:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;start\&quot;,\&quot;serv_i_id\&quot;,\&quot;serv_j_id\&quot;,\&quot;serv_k_id\&quot;] } &#x60;&#x60;&#x60;  Latter enforces the direct sequence of i, j and k at the beginning of the route. If this sequence should be bound to the end of the route, use the special ID &#x60;end&#x60; like this:  &#x60;&#x60;&#x60;json {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;serv_i_id\&quot;,\&quot;service_j_id\&quot;,\&quot;serv_k_id\&quot;,\&quot;end\&quot;] } &#x60;&#x60;&#x60;  If you deal with services then you need to use the &#x27;id&#x27; of your services in the field &#x27;ids&#x27;. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use the shipment id plus the keyword &#x60;_pickup&#x60; or &#x60;_delivery&#x60;. For example, to ensure that the pickup and delivery of the shipment with the id &#x27;my_shipment&#x27; are direct neighbors, you need the following specification:  &#x60;&#x60;&#x60; {    \&quot;type\&quot;: \&quot;in_direct_sequence\&quot;,    \&quot;ids\&quot;: [\&quot;my_ship_pickup\&quot;,\&quot;my_ship_delivery\&quot;] } &#x60;&#x60;&#x60;  </value>
        [DataMember(Name="type", EmitDefaultValue=false)]
        public string Type { get; set; }

        /// <summary>
        /// Specifies an array of shipment and/or service ids that are in relation. If you deal with services then you need to use the id of your services in ids. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use your shipment id plus the keyword &#x60;_pickup&#x60; or &#x60;_delivery&#x60;. If you want to place a service or shipment activity at the beginning of your route, use the special ID &#x60;start&#x60;. In turn, use &#x60;end&#x60; to place it at the end of the route.
        /// </summary>
        /// <value>Specifies an array of shipment and/or service ids that are in relation. If you deal with services then you need to use the id of your services in ids. To also consider sequences of the pickups and deliveries of your shipments, you need to use a special ID, i.e. use your shipment id plus the keyword &#x60;_pickup&#x60; or &#x60;_delivery&#x60;. If you want to place a service or shipment activity at the beginning of your route, use the special ID &#x60;start&#x60;. In turn, use &#x60;end&#x60; to place it at the end of the route.</value>
        [DataMember(Name="ids", EmitDefaultValue=false)]
        public List<string> Ids { get; set; }

        /// <summary>
        /// Id of pre-assigned vehicle, i.e. the vehicle id that is determined to conduct the services and shipments in this relation.
        /// </summary>
        /// <value>Id of pre-assigned vehicle, i.e. the vehicle id that is determined to conduct the services and shipments in this relation.</value>
        [DataMember(Name="vehicle_id", EmitDefaultValue=false)]
        public string VehicleId { get; set; }

        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.Append("class JobRelation {\n");
            sb.Append("  Type: ").Append(Type).Append("\n");
            sb.Append("  Ids: ").Append(Ids).Append("\n");
            sb.Append("  VehicleId: ").Append(VehicleId).Append("\n");
            sb.Append("}\n");
            return sb.ToString();
        }
  
        /// <summary>
        /// Returns the JSON string presentation of the object
        /// </summary>
        /// <returns>JSON string presentation of the object</returns>
        public virtual string ToJson()
        {
            return JsonConvert.SerializeObject(this, Formatting.Indented);
        }

        /// <summary>
        /// Returns true if objects are equal
        /// </summary>
        /// <param name="input">Object to be compared</param>
        /// <returns>Boolean</returns>
        public override bool Equals(object input)
        {
            return this.Equals(input as JobRelation);
        }

        /// <summary>
        /// Returns true if JobRelation instances are equal
        /// </summary>
        /// <param name="input">Instance of JobRelation to be compared</param>
        /// <returns>Boolean</returns>
        public bool Equals(JobRelation input)
        {
            if (input == null)
                return false;

            return 
                (
                    this.Type == input.Type ||
                    (this.Type != null &&
                    this.Type.Equals(input.Type))
                ) && 
                (
                    this.Ids == input.Ids ||
                    this.Ids != null &&
                    input.Ids != null &&
                    this.Ids.SequenceEqual(input.Ids)
                ) && 
                (
                    this.VehicleId == input.VehicleId ||
                    (this.VehicleId != null &&
                    this.VehicleId.Equals(input.VehicleId))
                );
        }

        /// <summary>
        /// Gets the hash code
        /// </summary>
        /// <returns>Hash code</returns>
        public override int GetHashCode()
        {
            unchecked // Overflow is fine, just wrap
            {
                int hashCode = 41;
                if (this.Type != null)
                    hashCode = hashCode * 59 + this.Type.GetHashCode();
                if (this.Ids != null)
                    hashCode = hashCode * 59 + this.Ids.GetHashCode();
                if (this.VehicleId != null)
                    hashCode = hashCode * 59 + this.VehicleId.GetHashCode();
                return hashCode;
            }
        }

        /// <summary>
        /// To validate all properties of the instance
        /// </summary>
        /// <param name="validationContext">Validation context</param>
        /// <returns>Validation Result</returns>
        IEnumerable<System.ComponentModel.DataAnnotations.ValidationResult> IValidatableObject.Validate(ValidationContext validationContext)
        {
            yield break;
        }
    }
}
