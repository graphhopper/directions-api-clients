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
    /// Vehicle
    /// </summary>
    [DataContract]
        public partial class Vehicle :  IEquatable<Vehicle>, IValidatableObject
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="Vehicle" /> class.
        /// </summary>
        /// <param name="vehicleId">Specifies the id of the vehicle. Ids need to be unique, thus if there two vehicles with the same id, an exception is thrown. (required).</param>
        /// <param name="typeId">The type_id refers to specified vehicle type (see vehicle types). If it is omitted a default type will be used. (default to &quot;default-type&quot;).</param>
        /// <param name="startAddress">startAddress (required).</param>
        /// <param name="endAddress">endAddress.</param>
        /// <param name="_break">_break.</param>
        /// <param name="returnToDepot">If it is false, the algorithm decides where to end the vehicle route. It ends in one of your customers&#x27; locations. The end is chosen such that it contributes to the overall objective function, e.g. min transport_time. If it is true, you can either specify a specific end location (which is then regarded as end depot) or you can leave it and the driver returns to its start location. (default to true).</param>
        /// <param name="earliestStart">Earliest start of vehicle in seconds. It is recommended to use the unix timestamp. (default to 0F).</param>
        /// <param name="latestEnd">Latest end of vehicle in seconds, i.e. the time the vehicle needs to be at its end location at latest..</param>
        /// <param name="skills">Array of skills, i.e. array of string (not case sensitive)..</param>
        /// <param name="maxDistance">Specifies the maximum distance a vehicle can go..</param>
        /// <param name="maxDrivingTime">Specifies the maximum drive time a vehicle/driver can go, i.e. the maximum time on the road (service and waiting times are not included here).</param>
        /// <param name="maxJobs">Specifies the maximum number of jobs a vehicle can load..</param>
        /// <param name="maxActivities">Specifies the maximum number of activities a vehicle can conduct..</param>
        /// <param name="moveToEndAddress">Indicates whether a vehicle should be moved even though it has not been assigned any jobs..</param>
        public Vehicle(string vehicleId = default(string), string typeId = "default-type", Address startAddress = default(Address), Address endAddress = default(Address), AnyOfVehicleBreak _break = default(AnyOfVehicleBreak), bool? returnToDepot = true, long? earliestStart = 0F, long? latestEnd = default(long?), List<string> skills = default(List<string>), long? maxDistance = default(long?), long? maxDrivingTime = default(long?), int? maxJobs = default(int?), int? maxActivities = default(int?), bool? moveToEndAddress = default(bool?))
        {
            // to ensure "vehicleId" is required (not null)
            if (vehicleId == null)
            {
                throw new InvalidDataException("vehicleId is a required property for Vehicle and cannot be null");
            }
            else
            {
                this.VehicleId = vehicleId;
            }
            // to ensure "startAddress" is required (not null)
            if (startAddress == null)
            {
                throw new InvalidDataException("startAddress is a required property for Vehicle and cannot be null");
            }
            else
            {
                this.StartAddress = startAddress;
            }
            // use default value if no "typeId" provided
            if (typeId == null)
            {
                this.TypeId = "default-type";
            }
            else
            {
                this.TypeId = typeId;
            }
            this.EndAddress = endAddress;
            this.Break = _break;
            // use default value if no "returnToDepot" provided
            if (returnToDepot == null)
            {
                this.ReturnToDepot = true;
            }
            else
            {
                this.ReturnToDepot = returnToDepot;
            }
            // use default value if no "earliestStart" provided
            if (earliestStart == null)
            {
                this.EarliestStart = 0F;
            }
            else
            {
                this.EarliestStart = earliestStart;
            }
            this.LatestEnd = latestEnd;
            this.Skills = skills;
            this.MaxDistance = maxDistance;
            this.MaxDrivingTime = maxDrivingTime;
            this.MaxJobs = maxJobs;
            this.MaxActivities = maxActivities;
            this.MoveToEndAddress = moveToEndAddress;
        }
        
        /// <summary>
        /// Specifies the id of the vehicle. Ids need to be unique, thus if there two vehicles with the same id, an exception is thrown.
        /// </summary>
        /// <value>Specifies the id of the vehicle. Ids need to be unique, thus if there two vehicles with the same id, an exception is thrown.</value>
        [DataMember(Name="vehicle_id", EmitDefaultValue=false)]
        public string VehicleId { get; set; }

        /// <summary>
        /// The type_id refers to specified vehicle type (see vehicle types). If it is omitted a default type will be used.
        /// </summary>
        /// <value>The type_id refers to specified vehicle type (see vehicle types). If it is omitted a default type will be used.</value>
        [DataMember(Name="type_id", EmitDefaultValue=false)]
        public string TypeId { get; set; }

        /// <summary>
        /// Gets or Sets StartAddress
        /// </summary>
        [DataMember(Name="start_address", EmitDefaultValue=false)]
        public Address StartAddress { get; set; }

        /// <summary>
        /// Gets or Sets EndAddress
        /// </summary>
        [DataMember(Name="end_address", EmitDefaultValue=false)]
        public Address EndAddress { get; set; }

        /// <summary>
        /// Gets or Sets Break
        /// </summary>
        [DataMember(Name="break", EmitDefaultValue=false)]
        public AnyOfVehicleBreak Break { get; set; }

        /// <summary>
        /// If it is false, the algorithm decides where to end the vehicle route. It ends in one of your customers&#x27; locations. The end is chosen such that it contributes to the overall objective function, e.g. min transport_time. If it is true, you can either specify a specific end location (which is then regarded as end depot) or you can leave it and the driver returns to its start location.
        /// </summary>
        /// <value>If it is false, the algorithm decides where to end the vehicle route. It ends in one of your customers&#x27; locations. The end is chosen such that it contributes to the overall objective function, e.g. min transport_time. If it is true, you can either specify a specific end location (which is then regarded as end depot) or you can leave it and the driver returns to its start location.</value>
        [DataMember(Name="return_to_depot", EmitDefaultValue=false)]
        public bool? ReturnToDepot { get; set; }

        /// <summary>
        /// Earliest start of vehicle in seconds. It is recommended to use the unix timestamp.
        /// </summary>
        /// <value>Earliest start of vehicle in seconds. It is recommended to use the unix timestamp.</value>
        [DataMember(Name="earliest_start", EmitDefaultValue=false)]
        public long? EarliestStart { get; set; }

        /// <summary>
        /// Latest end of vehicle in seconds, i.e. the time the vehicle needs to be at its end location at latest.
        /// </summary>
        /// <value>Latest end of vehicle in seconds, i.e. the time the vehicle needs to be at its end location at latest.</value>
        [DataMember(Name="latest_end", EmitDefaultValue=false)]
        public long? LatestEnd { get; set; }

        /// <summary>
        /// Array of skills, i.e. array of string (not case sensitive).
        /// </summary>
        /// <value>Array of skills, i.e. array of string (not case sensitive).</value>
        [DataMember(Name="skills", EmitDefaultValue=false)]
        public List<string> Skills { get; set; }

        /// <summary>
        /// Specifies the maximum distance a vehicle can go.
        /// </summary>
        /// <value>Specifies the maximum distance a vehicle can go.</value>
        [DataMember(Name="max_distance", EmitDefaultValue=false)]
        public long? MaxDistance { get; set; }

        /// <summary>
        /// Specifies the maximum drive time a vehicle/driver can go, i.e. the maximum time on the road (service and waiting times are not included here)
        /// </summary>
        /// <value>Specifies the maximum drive time a vehicle/driver can go, i.e. the maximum time on the road (service and waiting times are not included here)</value>
        [DataMember(Name="max_driving_time", EmitDefaultValue=false)]
        public long? MaxDrivingTime { get; set; }

        /// <summary>
        /// Specifies the maximum number of jobs a vehicle can load.
        /// </summary>
        /// <value>Specifies the maximum number of jobs a vehicle can load.</value>
        [DataMember(Name="max_jobs", EmitDefaultValue=false)]
        public int? MaxJobs { get; set; }

        /// <summary>
        /// Specifies the maximum number of activities a vehicle can conduct.
        /// </summary>
        /// <value>Specifies the maximum number of activities a vehicle can conduct.</value>
        [DataMember(Name="max_activities", EmitDefaultValue=false)]
        public int? MaxActivities { get; set; }

        /// <summary>
        /// Indicates whether a vehicle should be moved even though it has not been assigned any jobs.
        /// </summary>
        /// <value>Indicates whether a vehicle should be moved even though it has not been assigned any jobs.</value>
        [DataMember(Name="move_to_end_address", EmitDefaultValue=false)]
        public bool? MoveToEndAddress { get; set; }

        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.Append("class Vehicle {\n");
            sb.Append("  VehicleId: ").Append(VehicleId).Append("\n");
            sb.Append("  TypeId: ").Append(TypeId).Append("\n");
            sb.Append("  StartAddress: ").Append(StartAddress).Append("\n");
            sb.Append("  EndAddress: ").Append(EndAddress).Append("\n");
            sb.Append("  Break: ").Append(Break).Append("\n");
            sb.Append("  ReturnToDepot: ").Append(ReturnToDepot).Append("\n");
            sb.Append("  EarliestStart: ").Append(EarliestStart).Append("\n");
            sb.Append("  LatestEnd: ").Append(LatestEnd).Append("\n");
            sb.Append("  Skills: ").Append(Skills).Append("\n");
            sb.Append("  MaxDistance: ").Append(MaxDistance).Append("\n");
            sb.Append("  MaxDrivingTime: ").Append(MaxDrivingTime).Append("\n");
            sb.Append("  MaxJobs: ").Append(MaxJobs).Append("\n");
            sb.Append("  MaxActivities: ").Append(MaxActivities).Append("\n");
            sb.Append("  MoveToEndAddress: ").Append(MoveToEndAddress).Append("\n");
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
            return this.Equals(input as Vehicle);
        }

        /// <summary>
        /// Returns true if Vehicle instances are equal
        /// </summary>
        /// <param name="input">Instance of Vehicle to be compared</param>
        /// <returns>Boolean</returns>
        public bool Equals(Vehicle input)
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
                    this.TypeId == input.TypeId ||
                    (this.TypeId != null &&
                    this.TypeId.Equals(input.TypeId))
                ) && 
                (
                    this.StartAddress == input.StartAddress ||
                    (this.StartAddress != null &&
                    this.StartAddress.Equals(input.StartAddress))
                ) && 
                (
                    this.EndAddress == input.EndAddress ||
                    (this.EndAddress != null &&
                    this.EndAddress.Equals(input.EndAddress))
                ) && 
                (
                    this.Break == input.Break ||
                    this.Break != null &&
                    input.Break != null &&
                    this.Break.SequenceEqual(input.Break)
                ) && 
                (
                    this.ReturnToDepot == input.ReturnToDepot ||
                    (this.ReturnToDepot != null &&
                    this.ReturnToDepot.Equals(input.ReturnToDepot))
                ) && 
                (
                    this.EarliestStart == input.EarliestStart ||
                    (this.EarliestStart != null &&
                    this.EarliestStart.Equals(input.EarliestStart))
                ) && 
                (
                    this.LatestEnd == input.LatestEnd ||
                    (this.LatestEnd != null &&
                    this.LatestEnd.Equals(input.LatestEnd))
                ) && 
                (
                    this.Skills == input.Skills ||
                    this.Skills != null &&
                    input.Skills != null &&
                    this.Skills.SequenceEqual(input.Skills)
                ) && 
                (
                    this.MaxDistance == input.MaxDistance ||
                    (this.MaxDistance != null &&
                    this.MaxDistance.Equals(input.MaxDistance))
                ) && 
                (
                    this.MaxDrivingTime == input.MaxDrivingTime ||
                    (this.MaxDrivingTime != null &&
                    this.MaxDrivingTime.Equals(input.MaxDrivingTime))
                ) && 
                (
                    this.MaxJobs == input.MaxJobs ||
                    (this.MaxJobs != null &&
                    this.MaxJobs.Equals(input.MaxJobs))
                ) && 
                (
                    this.MaxActivities == input.MaxActivities ||
                    (this.MaxActivities != null &&
                    this.MaxActivities.Equals(input.MaxActivities))
                ) && 
                (
                    this.MoveToEndAddress == input.MoveToEndAddress ||
                    (this.MoveToEndAddress != null &&
                    this.MoveToEndAddress.Equals(input.MoveToEndAddress))
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
                if (this.TypeId != null)
                    hashCode = hashCode * 59 + this.TypeId.GetHashCode();
                if (this.StartAddress != null)
                    hashCode = hashCode * 59 + this.StartAddress.GetHashCode();
                if (this.EndAddress != null)
                    hashCode = hashCode * 59 + this.EndAddress.GetHashCode();
                if (this.Break != null)
                    hashCode = hashCode * 59 + this.Break.GetHashCode();
                if (this.ReturnToDepot != null)
                    hashCode = hashCode * 59 + this.ReturnToDepot.GetHashCode();
                if (this.EarliestStart != null)
                    hashCode = hashCode * 59 + this.EarliestStart.GetHashCode();
                if (this.LatestEnd != null)
                    hashCode = hashCode * 59 + this.LatestEnd.GetHashCode();
                if (this.Skills != null)
                    hashCode = hashCode * 59 + this.Skills.GetHashCode();
                if (this.MaxDistance != null)
                    hashCode = hashCode * 59 + this.MaxDistance.GetHashCode();
                if (this.MaxDrivingTime != null)
                    hashCode = hashCode * 59 + this.MaxDrivingTime.GetHashCode();
                if (this.MaxJobs != null)
                    hashCode = hashCode * 59 + this.MaxJobs.GetHashCode();
                if (this.MaxActivities != null)
                    hashCode = hashCode * 59 + this.MaxActivities.GetHashCode();
                if (this.MoveToEndAddress != null)
                    hashCode = hashCode * 59 + this.MoveToEndAddress.GetHashCode();
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
