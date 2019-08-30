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
    /// MatrixRequest
    /// </summary>
    [DataContract]
        public partial class MatrixRequest :  IEquatable<MatrixRequest>, IValidatableObject
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="MatrixRequest" /> class.
        /// </summary>
        /// <param name="fromPoints">The starting points for the routes in an array of &#x60;[longitude,latitude]&#x60;. For instance, if you want to calculate three routes from point A such as A-&gt;1, A-&gt;2, A-&gt;3 then you have one &#x60;from_point&#x60; parameter and three &#x60;to_point&#x60; parameters..</param>
        /// <param name="toPoints">The destination points for the routes in an array of &#x60;[longitude,latitude]&#x60;..</param>
        /// <param name="fromPointHints">See &#x60;point_hints&#x60;.</param>
        /// <param name="toPointHints">See &#x60;point_hints&#x60;.</param>
        /// <param name="outArrays">Specifies which matrices should be included in the response. Specify one or more of the following options &#x60;weights&#x60;, &#x60;times&#x60;, &#x60;distances&#x60;. The units of the entries of &#x60;distances&#x60; are meters, of &#x60;times&#x60; are seconds and of &#x60;weights&#x60; is arbitrary and it can differ for different vehicles or versions of this API..</param>
        /// <param name="vehicle">vehicle.</param>
        /// <param name="failFast">Specifies whether or not the matrix calculation should return with an error as soon as possible in case some points cannot be found or some points are not connected. If set to &#x60;false&#x60; the time/weight/distance matrix will be calculated for all valid points and contain the &#x60;null&#x60; value for all entries that could not be calculated. The &#x60;hint&#x60; field of the response will also contain additional information about what went wrong (see its documentation). (default to true).</param>
        public MatrixRequest(List<List<double?>> fromPoints = default(List<List<double?>>), List<List<double?>> toPoints = default(List<List<double?>>), List<string> fromPointHints = default(List<string>), List<string> toPointHints = default(List<string>), List<string> outArrays = default(List<string>),  vehicle = default(), bool? failFast = true)
        {
            this.FromPoints = fromPoints;
            this.ToPoints = toPoints;
            this.FromPointHints = fromPointHints;
            this.ToPointHints = toPointHints;
            this.OutArrays = outArrays;
            this.Vehicle = vehicle;
            // use default value if no "failFast" provided
            if (failFast == null)
            {
                this.FailFast = true;
            }
            else
            {
                this.FailFast = failFast;
            }
        }
        
        /// <summary>
        /// The starting points for the routes in an array of &#x60;[longitude,latitude]&#x60;. For instance, if you want to calculate three routes from point A such as A-&gt;1, A-&gt;2, A-&gt;3 then you have one &#x60;from_point&#x60; parameter and three &#x60;to_point&#x60; parameters.
        /// </summary>
        /// <value>The starting points for the routes in an array of &#x60;[longitude,latitude]&#x60;. For instance, if you want to calculate three routes from point A such as A-&gt;1, A-&gt;2, A-&gt;3 then you have one &#x60;from_point&#x60; parameter and three &#x60;to_point&#x60; parameters.</value>
        [DataMember(Name="from_points", EmitDefaultValue=false)]
        public List<List<double?>> FromPoints { get; set; }

        /// <summary>
        /// The destination points for the routes in an array of &#x60;[longitude,latitude]&#x60;.
        /// </summary>
        /// <value>The destination points for the routes in an array of &#x60;[longitude,latitude]&#x60;.</value>
        [DataMember(Name="to_points", EmitDefaultValue=false)]
        public List<List<double?>> ToPoints { get; set; }

        /// <summary>
        /// See &#x60;point_hints&#x60;
        /// </summary>
        /// <value>See &#x60;point_hints&#x60;</value>
        [DataMember(Name="from_point_hints", EmitDefaultValue=false)]
        public List<string> FromPointHints { get; set; }

        /// <summary>
        /// See &#x60;point_hints&#x60;
        /// </summary>
        /// <value>See &#x60;point_hints&#x60;</value>
        [DataMember(Name="to_point_hints", EmitDefaultValue=false)]
        public List<string> ToPointHints { get; set; }

        /// <summary>
        /// Specifies which matrices should be included in the response. Specify one or more of the following options &#x60;weights&#x60;, &#x60;times&#x60;, &#x60;distances&#x60;. The units of the entries of &#x60;distances&#x60; are meters, of &#x60;times&#x60; are seconds and of &#x60;weights&#x60; is arbitrary and it can differ for different vehicles or versions of this API.
        /// </summary>
        /// <value>Specifies which matrices should be included in the response. Specify one or more of the following options &#x60;weights&#x60;, &#x60;times&#x60;, &#x60;distances&#x60;. The units of the entries of &#x60;distances&#x60; are meters, of &#x60;times&#x60; are seconds and of &#x60;weights&#x60; is arbitrary and it can differ for different vehicles or versions of this API.</value>
        [DataMember(Name="out_arrays", EmitDefaultValue=false)]
        public List<string> OutArrays { get; set; }

        /// <summary>
        /// Gets or Sets Vehicle
        /// </summary>
        [DataMember(Name="vehicle", EmitDefaultValue=false)]
        public  Vehicle { get; set; }

        /// <summary>
        /// Specifies whether or not the matrix calculation should return with an error as soon as possible in case some points cannot be found or some points are not connected. If set to &#x60;false&#x60; the time/weight/distance matrix will be calculated for all valid points and contain the &#x60;null&#x60; value for all entries that could not be calculated. The &#x60;hint&#x60; field of the response will also contain additional information about what went wrong (see its documentation).
        /// </summary>
        /// <value>Specifies whether or not the matrix calculation should return with an error as soon as possible in case some points cannot be found or some points are not connected. If set to &#x60;false&#x60; the time/weight/distance matrix will be calculated for all valid points and contain the &#x60;null&#x60; value for all entries that could not be calculated. The &#x60;hint&#x60; field of the response will also contain additional information about what went wrong (see its documentation).</value>
        [DataMember(Name="fail_fast", EmitDefaultValue=false)]
        public bool? FailFast { get; set; }

        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.Append("class MatrixRequest {\n");
            sb.Append("  FromPoints: ").Append(FromPoints).Append("\n");
            sb.Append("  ToPoints: ").Append(ToPoints).Append("\n");
            sb.Append("  FromPointHints: ").Append(FromPointHints).Append("\n");
            sb.Append("  ToPointHints: ").Append(ToPointHints).Append("\n");
            sb.Append("  OutArrays: ").Append(OutArrays).Append("\n");
            sb.Append("  Vehicle: ").Append(Vehicle).Append("\n");
            sb.Append("  FailFast: ").Append(FailFast).Append("\n");
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
            return this.Equals(input as MatrixRequest);
        }

        /// <summary>
        /// Returns true if MatrixRequest instances are equal
        /// </summary>
        /// <param name="input">Instance of MatrixRequest to be compared</param>
        /// <returns>Boolean</returns>
        public bool Equals(MatrixRequest input)
        {
            if (input == null)
                return false;

            return 
                (
                    this.FromPoints == input.FromPoints ||
                    this.FromPoints != null &&
                    input.FromPoints != null &&
                    this.FromPoints.SequenceEqual(input.FromPoints)
                ) && 
                (
                    this.ToPoints == input.ToPoints ||
                    this.ToPoints != null &&
                    input.ToPoints != null &&
                    this.ToPoints.SequenceEqual(input.ToPoints)
                ) && 
                (
                    this.FromPointHints == input.FromPointHints ||
                    this.FromPointHints != null &&
                    input.FromPointHints != null &&
                    this.FromPointHints.SequenceEqual(input.FromPointHints)
                ) && 
                (
                    this.ToPointHints == input.ToPointHints ||
                    this.ToPointHints != null &&
                    input.ToPointHints != null &&
                    this.ToPointHints.SequenceEqual(input.ToPointHints)
                ) && 
                (
                    this.OutArrays == input.OutArrays ||
                    this.OutArrays != null &&
                    input.OutArrays != null &&
                    this.OutArrays.SequenceEqual(input.OutArrays)
                ) && 
                (
                    this.Vehicle == input.Vehicle ||
                    this.Vehicle != null &&
                    input.Vehicle != null &&
                    this.Vehicle.SequenceEqual(input.Vehicle)
                ) && 
                (
                    this.FailFast == input.FailFast ||
                    (this.FailFast != null &&
                    this.FailFast.Equals(input.FailFast))
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
                if (this.FromPoints != null)
                    hashCode = hashCode * 59 + this.FromPoints.GetHashCode();
                if (this.ToPoints != null)
                    hashCode = hashCode * 59 + this.ToPoints.GetHashCode();
                if (this.FromPointHints != null)
                    hashCode = hashCode * 59 + this.FromPointHints.GetHashCode();
                if (this.ToPointHints != null)
                    hashCode = hashCode * 59 + this.ToPointHints.GetHashCode();
                if (this.OutArrays != null)
                    hashCode = hashCode * 59 + this.OutArrays.GetHashCode();
                if (this.Vehicle != null)
                    hashCode = hashCode * 59 + this.Vehicle.GetHashCode();
                if (this.FailFast != null)
                    hashCode = hashCode * 59 + this.FailFast.GetHashCode();
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
