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
    /// Service
    /// </summary>
    [DataContract]
        public partial class Service :  IEquatable<Service>, IValidatableObject
    {
        /// <summary>
        /// Specifies type of service. This makes a difference if items are loaded or unloaded, i.e. if one of the size dimensions &gt; 0. If it is specified as &#x60;service&#x60; or &#x60;pickup&#x60;, items are loaded and will stay in the vehicle for the rest of the route (and thus consumes capacity for the rest of the route). If it is a &#x60;delivery&#x60;, items are implicitly loaded at the beginning of the route and will stay in the route until delivery (and thus releases capacity for the rest of the route).
        /// </summary>
        /// <value>Specifies type of service. This makes a difference if items are loaded or unloaded, i.e. if one of the size dimensions &gt; 0. If it is specified as &#x60;service&#x60; or &#x60;pickup&#x60;, items are loaded and will stay in the vehicle for the rest of the route (and thus consumes capacity for the rest of the route). If it is a &#x60;delivery&#x60;, items are implicitly loaded at the beginning of the route and will stay in the route until delivery (and thus releases capacity for the rest of the route).</value>
        [JsonConverter(typeof(StringEnumConverter))]
                public enum TypeEnum
        {
            /// <summary>
            /// Enum Service for value: service
            /// </summary>
            [EnumMember(Value = "service")]
            Service = 0,
            /// <summary>
            /// Enum Pickup for value: pickup
            /// </summary>
            [EnumMember(Value = "pickup")]
            Pickup = 1,
            /// <summary>
            /// Enum Delivery for value: delivery
            /// </summary>
            [EnumMember(Value = "delivery")]
            Delivery = 2        }
        /// <summary>
        /// Specifies type of service. This makes a difference if items are loaded or unloaded, i.e. if one of the size dimensions &gt; 0. If it is specified as &#x60;service&#x60; or &#x60;pickup&#x60;, items are loaded and will stay in the vehicle for the rest of the route (and thus consumes capacity for the rest of the route). If it is a &#x60;delivery&#x60;, items are implicitly loaded at the beginning of the route and will stay in the route until delivery (and thus releases capacity for the rest of the route).
        /// </summary>
        /// <value>Specifies type of service. This makes a difference if items are loaded or unloaded, i.e. if one of the size dimensions &gt; 0. If it is specified as &#x60;service&#x60; or &#x60;pickup&#x60;, items are loaded and will stay in the vehicle for the rest of the route (and thus consumes capacity for the rest of the route). If it is a &#x60;delivery&#x60;, items are implicitly loaded at the beginning of the route and will stay in the route until delivery (and thus releases capacity for the rest of the route).</value>
        [DataMember(Name="type", EmitDefaultValue=false)]
        public TypeEnum? Type { get; set; }
        /// <summary>
        /// Initializes a new instance of the <see cref="Service" /> class.
        /// </summary>
        /// <param name="id">Specifies the id of the service. Ids need to be unique so there must not be two services/shipments with the same id. (required).</param>
        /// <param name="type">Specifies type of service. This makes a difference if items are loaded or unloaded, i.e. if one of the size dimensions &gt; 0. If it is specified as &#x60;service&#x60; or &#x60;pickup&#x60;, items are loaded and will stay in the vehicle for the rest of the route (and thus consumes capacity for the rest of the route). If it is a &#x60;delivery&#x60;, items are implicitly loaded at the beginning of the route and will stay in the route until delivery (and thus releases capacity for the rest of the route). (default to TypeEnum.Service).</param>
        /// <param name="priority">Specifies the priority. Can be 1 &#x3D; high priority to 10 &#x3D; low priority. Often there are more services/shipments than the available vehicle fleet can handle. Then you could assign priorities to differentiate high priority tasks from those that can be served later or omitted at all. (default to 2).</param>
        /// <param name="name">Meaningful name for service, e.g. &#x60;\&quot;deliver pizza\&quot;&#x60;..</param>
        /// <param name="address">address (required).</param>
        /// <param name="duration">Specifies the duration of the service in seconds, i.e. how long it takes at the customer site. (default to 0F).</param>
        /// <param name="preparationTime">Specifies the preparation time in seconds. It can be used to model parking lot search time since if you have 3 identical locations in a row, it only falls due once. (default to 0F).</param>
        /// <param name="timeWindows">Specifies an array of time window objects (see time_window object below). Specify the time either with the recommended Unix time stamp (the number of seconds since 1970-01-01) or you can also count the seconds relative to Monday morning 00:00 and define the whole week in seconds. For example, Monday 9am is then represented by 9hour * 3600sec/hour &#x3D; 32400. In turn, Wednesday 1pm corresponds to 2day * 24hour/day * 3600sec/hour + 1day * 13hour/day * 3600sec/hour &#x3D; 219600. See this tutorial for more information..</param>
        /// <param name="size">Size can have multiple dimensions and should be in line with the capacity dimension array of the vehicle type. For example, if the item that needs to be delivered has two size dimension, volume and weight, then specify it as follow [ 20, 5 ] assuming a volume of 20 and a weight of 5. (default to [0]).</param>
        /// <param name="requiredSkills">Specifies an array of required skills, i.e. array of string (not case sensitive). For example, if this service needs to be conducted by a technician having a &#x60;drilling_machine&#x60; and a &#x60;screw_driver&#x60; then specify the array as follows: &#x60;[\&quot;drilling_machine\&quot;,\&quot;screw_driver\&quot;]&#x60;. This means that the service can only be done by a vehicle (technician) that has the skills &#x60;drilling_machine&#x60; AND &#x60;screw_driver&#x60; in its skill array. Otherwise it remains unassigned..</param>
        /// <param name="allowedVehicles">Specifies an array of allowed vehicles, i.e. array of vehicle ids. For example, if this service can only be conducted EITHER by &#x60;technician_peter&#x60; OR &#x60;technician_stefan&#x60; specify this as follows: &#x60;[\&quot;technician_peter\&quot;,\&quot;technician_stefan\&quot;]&#x60;..</param>
        /// <param name="disallowedVehicles">Specifies an array of disallowed vehicles, i.e. array of vehicle ids..</param>
        /// <param name="maxTimeInVehicle">Specifies the maximum time in seconds a delivery can stay in the vehicle. Currently, it only works with services of \&quot;type\&quot;:\&quot;delivery\&quot;..</param>
        /// <param name="group">Group this service belongs to..</param>
        public Service(string id = default(string), TypeEnum? type = TypeEnum.Service, int? priority = 2, string name = default(string), Address address = default(Address), long? duration = 0F, long? preparationTime = 0F, List<TimeWindow> timeWindows = default(List<TimeWindow>), List<int?> size = [0], List<string> requiredSkills = default(List<string>), List<string> allowedVehicles = default(List<string>), List<string> disallowedVehicles = default(List<string>), long? maxTimeInVehicle = default(long?), string group = default(string))
        {
            // to ensure "id" is required (not null)
            if (id == null)
            {
                throw new InvalidDataException("id is a required property for Service and cannot be null");
            }
            else
            {
                this.Id = id;
            }
            // to ensure "address" is required (not null)
            if (address == null)
            {
                throw new InvalidDataException("address is a required property for Service and cannot be null");
            }
            else
            {
                this.Address = address;
            }
            // use default value if no "type" provided
            if (type == null)
            {
                this.Type = TypeEnum.Service;
            }
            else
            {
                this.Type = type;
            }
            // use default value if no "priority" provided
            if (priority == null)
            {
                this.Priority = 2;
            }
            else
            {
                this.Priority = priority;
            }
            this.Name = name;
            // use default value if no "duration" provided
            if (duration == null)
            {
                this.Duration = 0F;
            }
            else
            {
                this.Duration = duration;
            }
            // use default value if no "preparationTime" provided
            if (preparationTime == null)
            {
                this.PreparationTime = 0F;
            }
            else
            {
                this.PreparationTime = preparationTime;
            }
            this.TimeWindows = timeWindows;
            // use default value if no "size" provided
            if (size == null)
            {
                this.Size = [0];
            }
            else
            {
                this.Size = size;
            }
            this.RequiredSkills = requiredSkills;
            this.AllowedVehicles = allowedVehicles;
            this.DisallowedVehicles = disallowedVehicles;
            this.MaxTimeInVehicle = maxTimeInVehicle;
            this.Group = group;
        }
        
        /// <summary>
        /// Specifies the id of the service. Ids need to be unique so there must not be two services/shipments with the same id.
        /// </summary>
        /// <value>Specifies the id of the service. Ids need to be unique so there must not be two services/shipments with the same id.</value>
        [DataMember(Name="id", EmitDefaultValue=false)]
        public string Id { get; set; }


        /// <summary>
        /// Specifies the priority. Can be 1 &#x3D; high priority to 10 &#x3D; low priority. Often there are more services/shipments than the available vehicle fleet can handle. Then you could assign priorities to differentiate high priority tasks from those that can be served later or omitted at all.
        /// </summary>
        /// <value>Specifies the priority. Can be 1 &#x3D; high priority to 10 &#x3D; low priority. Often there are more services/shipments than the available vehicle fleet can handle. Then you could assign priorities to differentiate high priority tasks from those that can be served later or omitted at all.</value>
        [DataMember(Name="priority", EmitDefaultValue=false)]
        public int? Priority { get; set; }

        /// <summary>
        /// Meaningful name for service, e.g. &#x60;\&quot;deliver pizza\&quot;&#x60;.
        /// </summary>
        /// <value>Meaningful name for service, e.g. &#x60;\&quot;deliver pizza\&quot;&#x60;.</value>
        [DataMember(Name="name", EmitDefaultValue=false)]
        public string Name { get; set; }

        /// <summary>
        /// Gets or Sets Address
        /// </summary>
        [DataMember(Name="address", EmitDefaultValue=false)]
        public Address Address { get; set; }

        /// <summary>
        /// Specifies the duration of the service in seconds, i.e. how long it takes at the customer site.
        /// </summary>
        /// <value>Specifies the duration of the service in seconds, i.e. how long it takes at the customer site.</value>
        [DataMember(Name="duration", EmitDefaultValue=false)]
        public long? Duration { get; set; }

        /// <summary>
        /// Specifies the preparation time in seconds. It can be used to model parking lot search time since if you have 3 identical locations in a row, it only falls due once.
        /// </summary>
        /// <value>Specifies the preparation time in seconds. It can be used to model parking lot search time since if you have 3 identical locations in a row, it only falls due once.</value>
        [DataMember(Name="preparation_time", EmitDefaultValue=false)]
        public long? PreparationTime { get; set; }

        /// <summary>
        /// Specifies an array of time window objects (see time_window object below). Specify the time either with the recommended Unix time stamp (the number of seconds since 1970-01-01) or you can also count the seconds relative to Monday morning 00:00 and define the whole week in seconds. For example, Monday 9am is then represented by 9hour * 3600sec/hour &#x3D; 32400. In turn, Wednesday 1pm corresponds to 2day * 24hour/day * 3600sec/hour + 1day * 13hour/day * 3600sec/hour &#x3D; 219600. See this tutorial for more information.
        /// </summary>
        /// <value>Specifies an array of time window objects (see time_window object below). Specify the time either with the recommended Unix time stamp (the number of seconds since 1970-01-01) or you can also count the seconds relative to Monday morning 00:00 and define the whole week in seconds. For example, Monday 9am is then represented by 9hour * 3600sec/hour &#x3D; 32400. In turn, Wednesday 1pm corresponds to 2day * 24hour/day * 3600sec/hour + 1day * 13hour/day * 3600sec/hour &#x3D; 219600. See this tutorial for more information.</value>
        [DataMember(Name="time_windows", EmitDefaultValue=false)]
        public List<TimeWindow> TimeWindows { get; set; }

        /// <summary>
        /// Size can have multiple dimensions and should be in line with the capacity dimension array of the vehicle type. For example, if the item that needs to be delivered has two size dimension, volume and weight, then specify it as follow [ 20, 5 ] assuming a volume of 20 and a weight of 5.
        /// </summary>
        /// <value>Size can have multiple dimensions and should be in line with the capacity dimension array of the vehicle type. For example, if the item that needs to be delivered has two size dimension, volume and weight, then specify it as follow [ 20, 5 ] assuming a volume of 20 and a weight of 5.</value>
        [DataMember(Name="size", EmitDefaultValue=false)]
        public List<int?> Size { get; set; }

        /// <summary>
        /// Specifies an array of required skills, i.e. array of string (not case sensitive). For example, if this service needs to be conducted by a technician having a &#x60;drilling_machine&#x60; and a &#x60;screw_driver&#x60; then specify the array as follows: &#x60;[\&quot;drilling_machine\&quot;,\&quot;screw_driver\&quot;]&#x60;. This means that the service can only be done by a vehicle (technician) that has the skills &#x60;drilling_machine&#x60; AND &#x60;screw_driver&#x60; in its skill array. Otherwise it remains unassigned.
        /// </summary>
        /// <value>Specifies an array of required skills, i.e. array of string (not case sensitive). For example, if this service needs to be conducted by a technician having a &#x60;drilling_machine&#x60; and a &#x60;screw_driver&#x60; then specify the array as follows: &#x60;[\&quot;drilling_machine\&quot;,\&quot;screw_driver\&quot;]&#x60;. This means that the service can only be done by a vehicle (technician) that has the skills &#x60;drilling_machine&#x60; AND &#x60;screw_driver&#x60; in its skill array. Otherwise it remains unassigned.</value>
        [DataMember(Name="required_skills", EmitDefaultValue=false)]
        public List<string> RequiredSkills { get; set; }

        /// <summary>
        /// Specifies an array of allowed vehicles, i.e. array of vehicle ids. For example, if this service can only be conducted EITHER by &#x60;technician_peter&#x60; OR &#x60;technician_stefan&#x60; specify this as follows: &#x60;[\&quot;technician_peter\&quot;,\&quot;technician_stefan\&quot;]&#x60;.
        /// </summary>
        /// <value>Specifies an array of allowed vehicles, i.e. array of vehicle ids. For example, if this service can only be conducted EITHER by &#x60;technician_peter&#x60; OR &#x60;technician_stefan&#x60; specify this as follows: &#x60;[\&quot;technician_peter\&quot;,\&quot;technician_stefan\&quot;]&#x60;.</value>
        [DataMember(Name="allowed_vehicles", EmitDefaultValue=false)]
        public List<string> AllowedVehicles { get; set; }

        /// <summary>
        /// Specifies an array of disallowed vehicles, i.e. array of vehicle ids.
        /// </summary>
        /// <value>Specifies an array of disallowed vehicles, i.e. array of vehicle ids.</value>
        [DataMember(Name="disallowed_vehicles", EmitDefaultValue=false)]
        public List<string> DisallowedVehicles { get; set; }

        /// <summary>
        /// Specifies the maximum time in seconds a delivery can stay in the vehicle. Currently, it only works with services of \&quot;type\&quot;:\&quot;delivery\&quot;.
        /// </summary>
        /// <value>Specifies the maximum time in seconds a delivery can stay in the vehicle. Currently, it only works with services of \&quot;type\&quot;:\&quot;delivery\&quot;.</value>
        [DataMember(Name="max_time_in_vehicle", EmitDefaultValue=false)]
        public long? MaxTimeInVehicle { get; set; }

        /// <summary>
        /// Group this service belongs to.
        /// </summary>
        /// <value>Group this service belongs to.</value>
        [DataMember(Name="group", EmitDefaultValue=false)]
        public string Group { get; set; }

        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.Append("class Service {\n");
            sb.Append("  Id: ").Append(Id).Append("\n");
            sb.Append("  Type: ").Append(Type).Append("\n");
            sb.Append("  Priority: ").Append(Priority).Append("\n");
            sb.Append("  Name: ").Append(Name).Append("\n");
            sb.Append("  Address: ").Append(Address).Append("\n");
            sb.Append("  Duration: ").Append(Duration).Append("\n");
            sb.Append("  PreparationTime: ").Append(PreparationTime).Append("\n");
            sb.Append("  TimeWindows: ").Append(TimeWindows).Append("\n");
            sb.Append("  Size: ").Append(Size).Append("\n");
            sb.Append("  RequiredSkills: ").Append(RequiredSkills).Append("\n");
            sb.Append("  AllowedVehicles: ").Append(AllowedVehicles).Append("\n");
            sb.Append("  DisallowedVehicles: ").Append(DisallowedVehicles).Append("\n");
            sb.Append("  MaxTimeInVehicle: ").Append(MaxTimeInVehicle).Append("\n");
            sb.Append("  Group: ").Append(Group).Append("\n");
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
            return this.Equals(input as Service);
        }

        /// <summary>
        /// Returns true if Service instances are equal
        /// </summary>
        /// <param name="input">Instance of Service to be compared</param>
        /// <returns>Boolean</returns>
        public bool Equals(Service input)
        {
            if (input == null)
                return false;

            return 
                (
                    this.Id == input.Id ||
                    (this.Id != null &&
                    this.Id.Equals(input.Id))
                ) && 
                (
                    this.Type == input.Type ||
                    (this.Type != null &&
                    this.Type.Equals(input.Type))
                ) && 
                (
                    this.Priority == input.Priority ||
                    (this.Priority != null &&
                    this.Priority.Equals(input.Priority))
                ) && 
                (
                    this.Name == input.Name ||
                    (this.Name != null &&
                    this.Name.Equals(input.Name))
                ) && 
                (
                    this.Address == input.Address ||
                    (this.Address != null &&
                    this.Address.Equals(input.Address))
                ) && 
                (
                    this.Duration == input.Duration ||
                    (this.Duration != null &&
                    this.Duration.Equals(input.Duration))
                ) && 
                (
                    this.PreparationTime == input.PreparationTime ||
                    (this.PreparationTime != null &&
                    this.PreparationTime.Equals(input.PreparationTime))
                ) && 
                (
                    this.TimeWindows == input.TimeWindows ||
                    this.TimeWindows != null &&
                    input.TimeWindows != null &&
                    this.TimeWindows.SequenceEqual(input.TimeWindows)
                ) && 
                (
                    this.Size == input.Size ||
                    this.Size != null &&
                    input.Size != null &&
                    this.Size.SequenceEqual(input.Size)
                ) && 
                (
                    this.RequiredSkills == input.RequiredSkills ||
                    this.RequiredSkills != null &&
                    input.RequiredSkills != null &&
                    this.RequiredSkills.SequenceEqual(input.RequiredSkills)
                ) && 
                (
                    this.AllowedVehicles == input.AllowedVehicles ||
                    this.AllowedVehicles != null &&
                    input.AllowedVehicles != null &&
                    this.AllowedVehicles.SequenceEqual(input.AllowedVehicles)
                ) && 
                (
                    this.DisallowedVehicles == input.DisallowedVehicles ||
                    this.DisallowedVehicles != null &&
                    input.DisallowedVehicles != null &&
                    this.DisallowedVehicles.SequenceEqual(input.DisallowedVehicles)
                ) && 
                (
                    this.MaxTimeInVehicle == input.MaxTimeInVehicle ||
                    (this.MaxTimeInVehicle != null &&
                    this.MaxTimeInVehicle.Equals(input.MaxTimeInVehicle))
                ) && 
                (
                    this.Group == input.Group ||
                    (this.Group != null &&
                    this.Group.Equals(input.Group))
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
                if (this.Id != null)
                    hashCode = hashCode * 59 + this.Id.GetHashCode();
                if (this.Type != null)
                    hashCode = hashCode * 59 + this.Type.GetHashCode();
                if (this.Priority != null)
                    hashCode = hashCode * 59 + this.Priority.GetHashCode();
                if (this.Name != null)
                    hashCode = hashCode * 59 + this.Name.GetHashCode();
                if (this.Address != null)
                    hashCode = hashCode * 59 + this.Address.GetHashCode();
                if (this.Duration != null)
                    hashCode = hashCode * 59 + this.Duration.GetHashCode();
                if (this.PreparationTime != null)
                    hashCode = hashCode * 59 + this.PreparationTime.GetHashCode();
                if (this.TimeWindows != null)
                    hashCode = hashCode * 59 + this.TimeWindows.GetHashCode();
                if (this.Size != null)
                    hashCode = hashCode * 59 + this.Size.GetHashCode();
                if (this.RequiredSkills != null)
                    hashCode = hashCode * 59 + this.RequiredSkills.GetHashCode();
                if (this.AllowedVehicles != null)
                    hashCode = hashCode * 59 + this.AllowedVehicles.GetHashCode();
                if (this.DisallowedVehicles != null)
                    hashCode = hashCode * 59 + this.DisallowedVehicles.GetHashCode();
                if (this.MaxTimeInVehicle != null)
                    hashCode = hashCode * 59 + this.MaxTimeInVehicle.GetHashCode();
                if (this.Group != null)
                    hashCode = hashCode * 59 + this.Group.GetHashCode();
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
