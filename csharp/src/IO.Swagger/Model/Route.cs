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
    /// Route
    /// </summary>
    [DataContract]
        public partial class Route :  IEquatable<Route>, IValidatableObject
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="Route" /> class.
        /// </summary>
        /// <param name="vehicleId">Id of vehicle that operates route.</param>
        /// <param name="distance">Distance of route in meter.</param>
        /// <param name="transportTime">Transport time of route in seconds.</param>
        /// <param name="completionTime">Completion time of route in seconds.</param>
        /// <param name="waitingTime">Waiting time of route in seconds.</param>
        /// <param name="serviceDuration">Service duration of route in seconds.</param>
        /// <param name="preparationTime">Preparation time of route in seconds.</param>
        /// <param name="activities">Array of activities.</param>
        /// <param name="points">Array of route planning points.</param>
        public Route(string vehicleId = default(string), long? distance = default(long?), long? transportTime = default(long?), long? completionTime = default(long?), long? waitingTime = default(long?), long? serviceDuration = default(long?), long? preparationTime = default(long?), List<Activity> activities = default(List<Activity>), List<RoutePoint> points = default(List<RoutePoint>))
        {
            this.VehicleId = vehicleId;
            this.Distance = distance;
            this.TransportTime = transportTime;
            this.CompletionTime = completionTime;
            this.WaitingTime = waitingTime;
            this.ServiceDuration = serviceDuration;
            this.PreparationTime = preparationTime;
            this.Activities = activities;
            this.Points = points;
        }
        
        /// <summary>
        /// Id of vehicle that operates route
        /// </summary>
        /// <value>Id of vehicle that operates route</value>
        [DataMember(Name="vehicle_id", EmitDefaultValue=false)]
        public string VehicleId { get; set; }

        /// <summary>
        /// Distance of route in meter
        /// </summary>
        /// <value>Distance of route in meter</value>
        [DataMember(Name="distance", EmitDefaultValue=false)]
        public long? Distance { get; set; }

        /// <summary>
        /// Transport time of route in seconds
        /// </summary>
        /// <value>Transport time of route in seconds</value>
        [DataMember(Name="transport_time", EmitDefaultValue=false)]
        public long? TransportTime { get; set; }

        /// <summary>
        /// Completion time of route in seconds
        /// </summary>
        /// <value>Completion time of route in seconds</value>
        [DataMember(Name="completion_time", EmitDefaultValue=false)]
        public long? CompletionTime { get; set; }

        /// <summary>
        /// Waiting time of route in seconds
        /// </summary>
        /// <value>Waiting time of route in seconds</value>
        [DataMember(Name="waiting_time", EmitDefaultValue=false)]
        public long? WaitingTime { get; set; }

        /// <summary>
        /// Service duration of route in seconds
        /// </summary>
        /// <value>Service duration of route in seconds</value>
        [DataMember(Name="service_duration", EmitDefaultValue=false)]
        public long? ServiceDuration { get; set; }

        /// <summary>
        /// Preparation time of route in seconds
        /// </summary>
        /// <value>Preparation time of route in seconds</value>
        [DataMember(Name="preparation_time", EmitDefaultValue=false)]
        public long? PreparationTime { get; set; }

        /// <summary>
        /// Array of activities
        /// </summary>
        /// <value>Array of activities</value>
        [DataMember(Name="activities", EmitDefaultValue=false)]
        public List<Activity> Activities { get; set; }

        /// <summary>
        /// Array of route planning points
        /// </summary>
        /// <value>Array of route planning points</value>
        [DataMember(Name="points", EmitDefaultValue=false)]
        public List<RoutePoint> Points { get; set; }

        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.Append("class Route {\n");
            sb.Append("  VehicleId: ").Append(VehicleId).Append("\n");
            sb.Append("  Distance: ").Append(Distance).Append("\n");
            sb.Append("  TransportTime: ").Append(TransportTime).Append("\n");
            sb.Append("  CompletionTime: ").Append(CompletionTime).Append("\n");
            sb.Append("  WaitingTime: ").Append(WaitingTime).Append("\n");
            sb.Append("  ServiceDuration: ").Append(ServiceDuration).Append("\n");
            sb.Append("  PreparationTime: ").Append(PreparationTime).Append("\n");
            sb.Append("  Activities: ").Append(Activities).Append("\n");
            sb.Append("  Points: ").Append(Points).Append("\n");
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
            return this.Equals(input as Route);
        }

        /// <summary>
        /// Returns true if Route instances are equal
        /// </summary>
        /// <param name="input">Instance of Route to be compared</param>
        /// <returns>Boolean</returns>
        public bool Equals(Route input)
        {
            if (input == null)
                return false;

            return 
                (
                    this.VehicleId == input.VehicleId ||
                    (this.VehicleId != null &&
                    this.VehicleId.Equals(input.VehicleId))
                ) && 
                (
                    this.Distance == input.Distance ||
                    (this.Distance != null &&
                    this.Distance.Equals(input.Distance))
                ) && 
                (
                    this.TransportTime == input.TransportTime ||
                    (this.TransportTime != null &&
                    this.TransportTime.Equals(input.TransportTime))
                ) && 
                (
                    this.CompletionTime == input.CompletionTime ||
                    (this.CompletionTime != null &&
                    this.CompletionTime.Equals(input.CompletionTime))
                ) && 
                (
                    this.WaitingTime == input.WaitingTime ||
                    (this.WaitingTime != null &&
                    this.WaitingTime.Equals(input.WaitingTime))
                ) && 
                (
                    this.ServiceDuration == input.ServiceDuration ||
                    (this.ServiceDuration != null &&
                    this.ServiceDuration.Equals(input.ServiceDuration))
                ) && 
                (
                    this.PreparationTime == input.PreparationTime ||
                    (this.PreparationTime != null &&
                    this.PreparationTime.Equals(input.PreparationTime))
                ) && 
                (
                    this.Activities == input.Activities ||
                    this.Activities != null &&
                    input.Activities != null &&
                    this.Activities.SequenceEqual(input.Activities)
                ) && 
                (
                    this.Points == input.Points ||
                    this.Points != null &&
                    input.Points != null &&
                    this.Points.SequenceEqual(input.Points)
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
                if (this.VehicleId != null)
                    hashCode = hashCode * 59 + this.VehicleId.GetHashCode();
                if (this.Distance != null)
                    hashCode = hashCode * 59 + this.Distance.GetHashCode();
                if (this.TransportTime != null)
                    hashCode = hashCode * 59 + this.TransportTime.GetHashCode();
                if (this.CompletionTime != null)
                    hashCode = hashCode * 59 + this.CompletionTime.GetHashCode();
                if (this.WaitingTime != null)
                    hashCode = hashCode * 59 + this.WaitingTime.GetHashCode();
                if (this.ServiceDuration != null)
                    hashCode = hashCode * 59 + this.ServiceDuration.GetHashCode();
                if (this.PreparationTime != null)
                    hashCode = hashCode * 59 + this.PreparationTime.GetHashCode();
                if (this.Activities != null)
                    hashCode = hashCode * 59 + this.Activities.GetHashCode();
                if (this.Points != null)
                    hashCode = hashCode * 59 + this.Points.GetHashCode();
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
