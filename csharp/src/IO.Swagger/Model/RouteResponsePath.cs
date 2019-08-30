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
    /// RouteResponsePath
    /// </summary>
    [DataContract]
        public partial class RouteResponsePath :  IEquatable<RouteResponsePath>, IValidatableObject
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="RouteResponsePath" /> class.
        /// </summary>
        /// <param name="distance">The total distance, in meters. .</param>
        /// <param name="time">The total travel time, in milliseconds. .</param>
        /// <param name="ascend">The total ascent, in meters. .</param>
        /// <param name="descend">The total descent, in meters. .</param>
        /// <param name="points">points.</param>
        /// <param name="snappedWaypoints">snappedWaypoints.</param>
        /// <param name="pointsEncoded">Whether the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields are encoded strings rather than GeoJSON LineStrings. .</param>
        /// <param name="bbox">The bounding box of the route geometry. Format: &#x60;[minLon, minLat, maxLon, maxLat]&#x60;. .</param>
        /// <param name="instructions">The instructions for this route. This feature is under active development, and our instructions can sometimes be misleading, so be mindful when using them for navigation. .</param>
        /// <param name="details">Details, as requested with the &#x60;details&#x60; parameter. Consider the value &#x60;{\&quot;street_name\&quot;: [[0,2,\&quot;Frankfurter Straße\&quot;],[2,6,\&quot;Zollweg\&quot;]]}&#x60;. In this example, the route uses two streets: The first, Frankfurter Straße, is used between &#x60;points[0]&#x60; and &#x60;points[2]&#x60;, and the second, Zollweg, between &#x60;points[2]&#x60; and &#x60;points[6]&#x60;. See [here](https://discuss.graphhopper.com/t/2539) for discussion. .</param>
        /// <param name="pointsOrder">An array of indices (zero-based), specifiying the order in which the input points are visited. Only present if the &#x60;optimize&#x60; parameter was used. .</param>
        public RouteResponsePath(double? distance = default(double?), long? time = default(long?), double? ascend = default(double?), double? descend = default(double?),  points = default(),  snappedWaypoints = default(), bool? pointsEncoded = default(bool?), List<double?> bbox = default(List<double?>), List<RouteResponsePathInstructions> instructions = default(List<RouteResponsePathInstructions>), Object details = default(Object), List<int?> pointsOrder = default(List<int?>))
        {
            this.Distance = distance;
            this.Time = time;
            this.Ascend = ascend;
            this.Descend = descend;
            this.Points = points;
            this.SnappedWaypoints = snappedWaypoints;
            this.PointsEncoded = pointsEncoded;
            this.Bbox = bbox;
            this.Instructions = instructions;
            this.Details = details;
            this.PointsOrder = pointsOrder;
        }
        
        /// <summary>
        /// The total distance, in meters. 
        /// </summary>
        /// <value>The total distance, in meters. </value>
        [DataMember(Name="distance", EmitDefaultValue=false)]
        public double? Distance { get; set; }

        /// <summary>
        /// The total travel time, in milliseconds. 
        /// </summary>
        /// <value>The total travel time, in milliseconds. </value>
        [DataMember(Name="time", EmitDefaultValue=false)]
        public long? Time { get; set; }

        /// <summary>
        /// The total ascent, in meters. 
        /// </summary>
        /// <value>The total ascent, in meters. </value>
        [DataMember(Name="ascend", EmitDefaultValue=false)]
        public double? Ascend { get; set; }

        /// <summary>
        /// The total descent, in meters. 
        /// </summary>
        /// <value>The total descent, in meters. </value>
        [DataMember(Name="descend", EmitDefaultValue=false)]
        public double? Descend { get; set; }

        /// <summary>
        /// Gets or Sets Points
        /// </summary>
        [DataMember(Name="points", EmitDefaultValue=false)]
        public  Points { get; set; }

        /// <summary>
        /// Gets or Sets SnappedWaypoints
        /// </summary>
        [DataMember(Name="snapped_waypoints", EmitDefaultValue=false)]
        public  SnappedWaypoints { get; set; }

        /// <summary>
        /// Whether the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields are encoded strings rather than GeoJSON LineStrings. 
        /// </summary>
        /// <value>Whether the &#x60;points&#x60; and &#x60;snapped_waypoints&#x60; fields are encoded strings rather than GeoJSON LineStrings. </value>
        [DataMember(Name="points_encoded", EmitDefaultValue=false)]
        public bool? PointsEncoded { get; set; }

        /// <summary>
        /// The bounding box of the route geometry. Format: &#x60;[minLon, minLat, maxLon, maxLat]&#x60;. 
        /// </summary>
        /// <value>The bounding box of the route geometry. Format: &#x60;[minLon, minLat, maxLon, maxLat]&#x60;. </value>
        [DataMember(Name="bbox", EmitDefaultValue=false)]
        public List<double?> Bbox { get; set; }

        /// <summary>
        /// The instructions for this route. This feature is under active development, and our instructions can sometimes be misleading, so be mindful when using them for navigation. 
        /// </summary>
        /// <value>The instructions for this route. This feature is under active development, and our instructions can sometimes be misleading, so be mindful when using them for navigation. </value>
        [DataMember(Name="instructions", EmitDefaultValue=false)]
        public List<RouteResponsePathInstructions> Instructions { get; set; }

        /// <summary>
        /// Details, as requested with the &#x60;details&#x60; parameter. Consider the value &#x60;{\&quot;street_name\&quot;: [[0,2,\&quot;Frankfurter Straße\&quot;],[2,6,\&quot;Zollweg\&quot;]]}&#x60;. In this example, the route uses two streets: The first, Frankfurter Straße, is used between &#x60;points[0]&#x60; and &#x60;points[2]&#x60;, and the second, Zollweg, between &#x60;points[2]&#x60; and &#x60;points[6]&#x60;. See [here](https://discuss.graphhopper.com/t/2539) for discussion. 
        /// </summary>
        /// <value>Details, as requested with the &#x60;details&#x60; parameter. Consider the value &#x60;{\&quot;street_name\&quot;: [[0,2,\&quot;Frankfurter Straße\&quot;],[2,6,\&quot;Zollweg\&quot;]]}&#x60;. In this example, the route uses two streets: The first, Frankfurter Straße, is used between &#x60;points[0]&#x60; and &#x60;points[2]&#x60;, and the second, Zollweg, between &#x60;points[2]&#x60; and &#x60;points[6]&#x60;. See [here](https://discuss.graphhopper.com/t/2539) for discussion. </value>
        [DataMember(Name="details", EmitDefaultValue=false)]
        public Object Details { get; set; }

        /// <summary>
        /// An array of indices (zero-based), specifiying the order in which the input points are visited. Only present if the &#x60;optimize&#x60; parameter was used. 
        /// </summary>
        /// <value>An array of indices (zero-based), specifiying the order in which the input points are visited. Only present if the &#x60;optimize&#x60; parameter was used. </value>
        [DataMember(Name="points_order", EmitDefaultValue=false)]
        public List<int?> PointsOrder { get; set; }

        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.Append("class RouteResponsePath {\n");
            sb.Append("  Distance: ").Append(Distance).Append("\n");
            sb.Append("  Time: ").Append(Time).Append("\n");
            sb.Append("  Ascend: ").Append(Ascend).Append("\n");
            sb.Append("  Descend: ").Append(Descend).Append("\n");
            sb.Append("  Points: ").Append(Points).Append("\n");
            sb.Append("  SnappedWaypoints: ").Append(SnappedWaypoints).Append("\n");
            sb.Append("  PointsEncoded: ").Append(PointsEncoded).Append("\n");
            sb.Append("  Bbox: ").Append(Bbox).Append("\n");
            sb.Append("  Instructions: ").Append(Instructions).Append("\n");
            sb.Append("  Details: ").Append(Details).Append("\n");
            sb.Append("  PointsOrder: ").Append(PointsOrder).Append("\n");
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
            return this.Equals(input as RouteResponsePath);
        }

        /// <summary>
        /// Returns true if RouteResponsePath instances are equal
        /// </summary>
        /// <param name="input">Instance of RouteResponsePath to be compared</param>
        /// <returns>Boolean</returns>
        public bool Equals(RouteResponsePath input)
        {
            if (input == null)
                return false;

            return 
                (
                    this.Distance == input.Distance ||
                    (this.Distance != null &&
                    this.Distance.Equals(input.Distance))
                ) && 
                (
                    this.Time == input.Time ||
                    (this.Time != null &&
                    this.Time.Equals(input.Time))
                ) && 
                (
                    this.Ascend == input.Ascend ||
                    (this.Ascend != null &&
                    this.Ascend.Equals(input.Ascend))
                ) && 
                (
                    this.Descend == input.Descend ||
                    (this.Descend != null &&
                    this.Descend.Equals(input.Descend))
                ) && 
                (
                    this.Points == input.Points ||
                    this.Points != null &&
                    input.Points != null &&
                    this.Points.SequenceEqual(input.Points)
                ) && 
                (
                    this.SnappedWaypoints == input.SnappedWaypoints ||
                    this.SnappedWaypoints != null &&
                    input.SnappedWaypoints != null &&
                    this.SnappedWaypoints.SequenceEqual(input.SnappedWaypoints)
                ) && 
                (
                    this.PointsEncoded == input.PointsEncoded ||
                    (this.PointsEncoded != null &&
                    this.PointsEncoded.Equals(input.PointsEncoded))
                ) && 
                (
                    this.Bbox == input.Bbox ||
                    this.Bbox != null &&
                    input.Bbox != null &&
                    this.Bbox.SequenceEqual(input.Bbox)
                ) && 
                (
                    this.Instructions == input.Instructions ||
                    this.Instructions != null &&
                    input.Instructions != null &&
                    this.Instructions.SequenceEqual(input.Instructions)
                ) && 
                (
                    this.Details == input.Details ||
                    (this.Details != null &&
                    this.Details.Equals(input.Details))
                ) && 
                (
                    this.PointsOrder == input.PointsOrder ||
                    this.PointsOrder != null &&
                    input.PointsOrder != null &&
                    this.PointsOrder.SequenceEqual(input.PointsOrder)
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
                if (this.Distance != null)
                    hashCode = hashCode * 59 + this.Distance.GetHashCode();
                if (this.Time != null)
                    hashCode = hashCode * 59 + this.Time.GetHashCode();
                if (this.Ascend != null)
                    hashCode = hashCode * 59 + this.Ascend.GetHashCode();
                if (this.Descend != null)
                    hashCode = hashCode * 59 + this.Descend.GetHashCode();
                if (this.Points != null)
                    hashCode = hashCode * 59 + this.Points.GetHashCode();
                if (this.SnappedWaypoints != null)
                    hashCode = hashCode * 59 + this.SnappedWaypoints.GetHashCode();
                if (this.PointsEncoded != null)
                    hashCode = hashCode * 59 + this.PointsEncoded.GetHashCode();
                if (this.Bbox != null)
                    hashCode = hashCode * 59 + this.Bbox.GetHashCode();
                if (this.Instructions != null)
                    hashCode = hashCode * 59 + this.Instructions.GetHashCode();
                if (this.Details != null)
                    hashCode = hashCode * 59 + this.Details.GetHashCode();
                if (this.PointsOrder != null)
                    hashCode = hashCode * 59 + this.PointsOrder.GetHashCode();
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
