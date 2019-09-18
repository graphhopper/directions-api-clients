/* 
 * GraphHopper Directions API
 *
 *  With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Client Libraries  To speed up development and make coding easier, we offer the following client libraries:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon - -- -- -- -- --|:- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions are considered only with `ch.disable=true`.**  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon - -- -- -- -- --|:- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -|:- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) 
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
using SwaggerDateConverter = GraphHopper.Client.SwaggerDateConverter;

namespace GraphHopper.Model
{
    /// <summary>
    /// VehicleType
    /// </summary>
    [DataContract]
        public partial class VehicleType :  IEquatable<VehicleType>, IValidatableObject
    {
        /// <summary>
        /// Specifies the network data provider. Either use [&#x60;openstreetmap&#x60;](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [&#x60;tomtom&#x60;](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).
        /// </summary>
        /// <value>Specifies the network data provider. Either use [&#x60;openstreetmap&#x60;](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [&#x60;tomtom&#x60;](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).</value>
        [JsonConverter(typeof(StringEnumConverter))]
                public enum NetworkDataProviderEnum
        {
            /// <summary>
            /// Enum Openstreetmap for value: openstreetmap
            /// </summary>
            [EnumMember(Value = "openstreetmap")]
            Openstreetmap = 0,
            /// <summary>
            /// Enum Tomtom for value: tomtom
            /// </summary>
            [EnumMember(Value = "tomtom")]
            Tomtom = 1        }
        /// <summary>
        /// Specifies the network data provider. Either use [&#x60;openstreetmap&#x60;](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [&#x60;tomtom&#x60;](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).
        /// </summary>
        /// <value>Specifies the network data provider. Either use [&#x60;openstreetmap&#x60;](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [&#x60;tomtom&#x60;](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).</value>
        [DataMember(Name="network_data_provider", EmitDefaultValue=false)]
        public NetworkDataProviderEnum? NetworkDataProvider { get; set; }
        /// <summary>
        /// Initializes a new instance of the <see cref="VehicleType" /> class.
        /// </summary>
        /// <param name="typeId">Specifies the id of the vehicle type. If a vehicle needs to be of this type, it should refer to this with its type_id attribute. (required).</param>
        /// <param name="profile">profile.</param>
        /// <param name="capacity">Specifies an array of capacity dimension values which need to be int values. For example, if there are two dimensions such as volume and weight then it needs to be defined as [ 1000, 300 ] assuming a maximum volume of 1000 and a maximum weight of 300. (default to [0]).</param>
        /// <param name="speedFactor">Specifies a speed factor for this vehicle type. If the vehicle that uses this type needs to be only half as fast as what is actually calculated with our routing engine then set the speed factor to 0.5. (default to 1).</param>
        /// <param name="serviceTimeFactor">Specifies a service time factor for this vehicle type. If the vehicle/driver that uses this type is able to conduct the service as double as fast as it is determined in the corresponding service or shipment then set it to 0.5. (default to 1).</param>
        /// <param name="costPerMeter">**_BETA feature_**! Cost parameter per distance unit, here meter is used.</param>
        /// <param name="costPerSecond">**_BETA feature_**! Cost parameter per time unit, here second is used.</param>
        /// <param name="costPerActivation">**_BETA feature_**! Cost parameter vehicle activation, i.e. fixed costs per vehicle.</param>
        /// <param name="considerTraffic">Specifies whether traffic should be considered. if \&quot;tomtom\&quot; is used and this is false, free flow travel times from \&quot;tomtom\&quot; are calculated. If this is true, historical traffic info are used. We do not yet have traffic data for \&quot;openstreetmap\&quot;, thus, setting this true has no effect at all. (default to false).</param>
        /// <param name="networkDataProvider">Specifies the network data provider. Either use [&#x60;openstreetmap&#x60;](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [&#x60;tomtom&#x60;](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required). (default to NetworkDataProviderEnum.Openstreetmap).</param>
        public VehicleType(string typeId = default(string),  profile = default(), List<int?> capacity = [0], double? speedFactor = 1, double? serviceTimeFactor = 1, double? costPerMeter = default(double?), double? costPerSecond = default(double?), double? costPerActivation = default(double?), bool? considerTraffic = false, NetworkDataProviderEnum? networkDataProvider = NetworkDataProviderEnum.Openstreetmap)
        {
            // to ensure "typeId" is required (not null)
            if (typeId == null)
            {
                throw new InvalidDataException("typeId is a required property for VehicleType and cannot be null");
            }
            else
            {
                this.TypeId = typeId;
            }
            this.Profile = profile;
            // use default value if no "capacity" provided
            if (capacity == null)
            {
                this.Capacity = [0];
            }
            else
            {
                this.Capacity = capacity;
            }
            // use default value if no "speedFactor" provided
            if (speedFactor == null)
            {
                this.SpeedFactor = 1;
            }
            else
            {
                this.SpeedFactor = speedFactor;
            }
            // use default value if no "serviceTimeFactor" provided
            if (serviceTimeFactor == null)
            {
                this.ServiceTimeFactor = 1;
            }
            else
            {
                this.ServiceTimeFactor = serviceTimeFactor;
            }
            this.CostPerMeter = costPerMeter;
            this.CostPerSecond = costPerSecond;
            this.CostPerActivation = costPerActivation;
            // use default value if no "considerTraffic" provided
            if (considerTraffic == null)
            {
                this.ConsiderTraffic = false;
            }
            else
            {
                this.ConsiderTraffic = considerTraffic;
            }
            // use default value if no "networkDataProvider" provided
            if (networkDataProvider == null)
            {
                this.NetworkDataProvider = NetworkDataProviderEnum.Openstreetmap;
            }
            else
            {
                this.NetworkDataProvider = networkDataProvider;
            }
        }
        
        /// <summary>
        /// Specifies the id of the vehicle type. If a vehicle needs to be of this type, it should refer to this with its type_id attribute.
        /// </summary>
        /// <value>Specifies the id of the vehicle type. If a vehicle needs to be of this type, it should refer to this with its type_id attribute.</value>
        [DataMember(Name="type_id", EmitDefaultValue=false)]
        public string TypeId { get; set; }

        /// <summary>
        /// Gets or Sets Profile
        /// </summary>
        [DataMember(Name="profile", EmitDefaultValue=false)]
        public  Profile { get; set; }

        /// <summary>
        /// Specifies an array of capacity dimension values which need to be int values. For example, if there are two dimensions such as volume and weight then it needs to be defined as [ 1000, 300 ] assuming a maximum volume of 1000 and a maximum weight of 300.
        /// </summary>
        /// <value>Specifies an array of capacity dimension values which need to be int values. For example, if there are two dimensions such as volume and weight then it needs to be defined as [ 1000, 300 ] assuming a maximum volume of 1000 and a maximum weight of 300.</value>
        [DataMember(Name="capacity", EmitDefaultValue=false)]
        public List<int?> Capacity { get; set; }

        /// <summary>
        /// Specifies a speed factor for this vehicle type. If the vehicle that uses this type needs to be only half as fast as what is actually calculated with our routing engine then set the speed factor to 0.5.
        /// </summary>
        /// <value>Specifies a speed factor for this vehicle type. If the vehicle that uses this type needs to be only half as fast as what is actually calculated with our routing engine then set the speed factor to 0.5.</value>
        [DataMember(Name="speed_factor", EmitDefaultValue=false)]
        public double? SpeedFactor { get; set; }

        /// <summary>
        /// Specifies a service time factor for this vehicle type. If the vehicle/driver that uses this type is able to conduct the service as double as fast as it is determined in the corresponding service or shipment then set it to 0.5.
        /// </summary>
        /// <value>Specifies a service time factor for this vehicle type. If the vehicle/driver that uses this type is able to conduct the service as double as fast as it is determined in the corresponding service or shipment then set it to 0.5.</value>
        [DataMember(Name="service_time_factor", EmitDefaultValue=false)]
        public double? ServiceTimeFactor { get; set; }

        /// <summary>
        /// **_BETA feature_**! Cost parameter per distance unit, here meter is used
        /// </summary>
        /// <value>**_BETA feature_**! Cost parameter per distance unit, here meter is used</value>
        [DataMember(Name="cost_per_meter", EmitDefaultValue=false)]
        public double? CostPerMeter { get; set; }

        /// <summary>
        /// **_BETA feature_**! Cost parameter per time unit, here second is used
        /// </summary>
        /// <value>**_BETA feature_**! Cost parameter per time unit, here second is used</value>
        [DataMember(Name="cost_per_second", EmitDefaultValue=false)]
        public double? CostPerSecond { get; set; }

        /// <summary>
        /// **_BETA feature_**! Cost parameter vehicle activation, i.e. fixed costs per vehicle
        /// </summary>
        /// <value>**_BETA feature_**! Cost parameter vehicle activation, i.e. fixed costs per vehicle</value>
        [DataMember(Name="cost_per_activation", EmitDefaultValue=false)]
        public double? CostPerActivation { get; set; }

        /// <summary>
        /// Specifies whether traffic should be considered. if \&quot;tomtom\&quot; is used and this is false, free flow travel times from \&quot;tomtom\&quot; are calculated. If this is true, historical traffic info are used. We do not yet have traffic data for \&quot;openstreetmap\&quot;, thus, setting this true has no effect at all.
        /// </summary>
        /// <value>Specifies whether traffic should be considered. if \&quot;tomtom\&quot; is used and this is false, free flow travel times from \&quot;tomtom\&quot; are calculated. If this is true, historical traffic info are used. We do not yet have traffic data for \&quot;openstreetmap\&quot;, thus, setting this true has no effect at all.</value>
        [DataMember(Name="consider_traffic", EmitDefaultValue=false)]
        public bool? ConsiderTraffic { get; set; }


        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.Append("class VehicleType {\n");
            sb.Append("  TypeId: ").Append(TypeId).Append("\n");
            sb.Append("  Profile: ").Append(Profile).Append("\n");
            sb.Append("  Capacity: ").Append(Capacity).Append("\n");
            sb.Append("  SpeedFactor: ").Append(SpeedFactor).Append("\n");
            sb.Append("  ServiceTimeFactor: ").Append(ServiceTimeFactor).Append("\n");
            sb.Append("  CostPerMeter: ").Append(CostPerMeter).Append("\n");
            sb.Append("  CostPerSecond: ").Append(CostPerSecond).Append("\n");
            sb.Append("  CostPerActivation: ").Append(CostPerActivation).Append("\n");
            sb.Append("  ConsiderTraffic: ").Append(ConsiderTraffic).Append("\n");
            sb.Append("  NetworkDataProvider: ").Append(NetworkDataProvider).Append("\n");
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
            return this.Equals(input as VehicleType);
        }

        /// <summary>
        /// Returns true if VehicleType instances are equal
        /// </summary>
        /// <param name="input">Instance of VehicleType to be compared</param>
        /// <returns>Boolean</returns>
        public bool Equals(VehicleType input)
        {
            if (input == null)
                return false;

            return 
                (
                    this.TypeId == input.TypeId ||
                    (this.TypeId != null &&
                    this.TypeId.Equals(input.TypeId))
                ) && 
                (
                    this.Profile == input.Profile ||
                    this.Profile != null &&
                    input.Profile != null &&
                    this.Profile.SequenceEqual(input.Profile)
                ) && 
                (
                    this.Capacity == input.Capacity ||
                    this.Capacity != null &&
                    input.Capacity != null &&
                    this.Capacity.SequenceEqual(input.Capacity)
                ) && 
                (
                    this.SpeedFactor == input.SpeedFactor ||
                    (this.SpeedFactor != null &&
                    this.SpeedFactor.Equals(input.SpeedFactor))
                ) && 
                (
                    this.ServiceTimeFactor == input.ServiceTimeFactor ||
                    (this.ServiceTimeFactor != null &&
                    this.ServiceTimeFactor.Equals(input.ServiceTimeFactor))
                ) && 
                (
                    this.CostPerMeter == input.CostPerMeter ||
                    (this.CostPerMeter != null &&
                    this.CostPerMeter.Equals(input.CostPerMeter))
                ) && 
                (
                    this.CostPerSecond == input.CostPerSecond ||
                    (this.CostPerSecond != null &&
                    this.CostPerSecond.Equals(input.CostPerSecond))
                ) && 
                (
                    this.CostPerActivation == input.CostPerActivation ||
                    (this.CostPerActivation != null &&
                    this.CostPerActivation.Equals(input.CostPerActivation))
                ) && 
                (
                    this.ConsiderTraffic == input.ConsiderTraffic ||
                    (this.ConsiderTraffic != null &&
                    this.ConsiderTraffic.Equals(input.ConsiderTraffic))
                ) && 
                (
                    this.NetworkDataProvider == input.NetworkDataProvider ||
                    (this.NetworkDataProvider != null &&
                    this.NetworkDataProvider.Equals(input.NetworkDataProvider))
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
                if (this.TypeId != null)
                    hashCode = hashCode * 59 + this.TypeId.GetHashCode();
                if (this.Profile != null)
                    hashCode = hashCode * 59 + this.Profile.GetHashCode();
                if (this.Capacity != null)
                    hashCode = hashCode * 59 + this.Capacity.GetHashCode();
                if (this.SpeedFactor != null)
                    hashCode = hashCode * 59 + this.SpeedFactor.GetHashCode();
                if (this.ServiceTimeFactor != null)
                    hashCode = hashCode * 59 + this.ServiceTimeFactor.GetHashCode();
                if (this.CostPerMeter != null)
                    hashCode = hashCode * 59 + this.CostPerMeter.GetHashCode();
                if (this.CostPerSecond != null)
                    hashCode = hashCode * 59 + this.CostPerSecond.GetHashCode();
                if (this.CostPerActivation != null)
                    hashCode = hashCode * 59 + this.CostPerActivation.GetHashCode();
                if (this.ConsiderTraffic != null)
                    hashCode = hashCode * 59 + this.ConsiderTraffic.GetHashCode();
                if (this.NetworkDataProvider != null)
                    hashCode = hashCode * 59 + this.NetworkDataProvider.GetHashCode();
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
