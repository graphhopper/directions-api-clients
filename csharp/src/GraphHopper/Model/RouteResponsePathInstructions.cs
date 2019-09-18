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
    /// RouteResponsePathInstructions
    /// </summary>
    [DataContract]
        public partial class RouteResponsePathInstructions :  IEquatable<RouteResponsePathInstructions>, IValidatableObject
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="RouteResponsePathInstructions" /> class.
        /// </summary>
        /// <param name="text">A description what the user has to do in order to follow the route. The language depends on the locale parameter. .</param>
        /// <param name="streetName">The name of the street to turn onto in order to follow the route. .</param>
        /// <param name="distance">The distance for this instruction, in meters. .</param>
        /// <param name="time">The duration for this instruction, in milliseconds. .</param>
        /// <param name="interval">Two indices into &#x60;points&#x60;, referring to the beginning and the end of the segment of the route this instruction refers to. .</param>
        /// <param name="sign">A number which specifies the sign to show:  |   |   | |- --|- --| |TURN_SHARP_LEFT |-3| |TURN_LEFT | -2| |TURN_SLIGHT_LEFT | -1| |CONTINUE_ON_STREET | 0| |TURN_SLIGHT_RIGHT |1| |TURN_RIGHT | 2| |TURN_SHARP_RIGHT | 3| |FINISH | 4| |VIA_REACHED | 5| |USE_ROUNDABOUT | 6| |KEEP_RIGHT | 7| .</param>
        /// <param name="exitNumber">Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout. .</param>
        /// <param name="turnAngle">Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout &#x60;0 &lt; r &lt; 2*PI&#x60; for clockwise and &#x60;-2*PI &lt; r &lt; 0&#x60; for counterclockwise turns. .</param>
        public RouteResponsePathInstructions(string text = default(string), string streetName = default(string), double? distance = default(double?), int? time = default(int?), List<int?> interval = default(List<int?>), int? sign = default(int?), int? exitNumber = default(int?), double? turnAngle = default(double?))
        {
            this.Text = text;
            this.StreetName = streetName;
            this.Distance = distance;
            this.Time = time;
            this.Interval = interval;
            this.Sign = sign;
            this.ExitNumber = exitNumber;
            this.TurnAngle = turnAngle;
        }
        
        /// <summary>
        /// A description what the user has to do in order to follow the route. The language depends on the locale parameter. 
        /// </summary>
        /// <value>A description what the user has to do in order to follow the route. The language depends on the locale parameter. </value>
        [DataMember(Name="text", EmitDefaultValue=false)]
        public string Text { get; set; }

        /// <summary>
        /// The name of the street to turn onto in order to follow the route. 
        /// </summary>
        /// <value>The name of the street to turn onto in order to follow the route. </value>
        [DataMember(Name="street_name", EmitDefaultValue=false)]
        public string StreetName { get; set; }

        /// <summary>
        /// The distance for this instruction, in meters. 
        /// </summary>
        /// <value>The distance for this instruction, in meters. </value>
        [DataMember(Name="distance", EmitDefaultValue=false)]
        public double? Distance { get; set; }

        /// <summary>
        /// The duration for this instruction, in milliseconds. 
        /// </summary>
        /// <value>The duration for this instruction, in milliseconds. </value>
        [DataMember(Name="time", EmitDefaultValue=false)]
        public int? Time { get; set; }

        /// <summary>
        /// Two indices into &#x60;points&#x60;, referring to the beginning and the end of the segment of the route this instruction refers to. 
        /// </summary>
        /// <value>Two indices into &#x60;points&#x60;, referring to the beginning and the end of the segment of the route this instruction refers to. </value>
        [DataMember(Name="interval", EmitDefaultValue=false)]
        public List<int?> Interval { get; set; }

        /// <summary>
        /// A number which specifies the sign to show:  |   |   | |- --|- --| |TURN_SHARP_LEFT |-3| |TURN_LEFT | -2| |TURN_SLIGHT_LEFT | -1| |CONTINUE_ON_STREET | 0| |TURN_SLIGHT_RIGHT |1| |TURN_RIGHT | 2| |TURN_SHARP_RIGHT | 3| |FINISH | 4| |VIA_REACHED | 5| |USE_ROUNDABOUT | 6| |KEEP_RIGHT | 7| 
        /// </summary>
        /// <value>A number which specifies the sign to show:  |   |   | |- --|- --| |TURN_SHARP_LEFT |-3| |TURN_LEFT | -2| |TURN_SLIGHT_LEFT | -1| |CONTINUE_ON_STREET | 0| |TURN_SLIGHT_RIGHT |1| |TURN_RIGHT | 2| |TURN_SHARP_RIGHT | 3| |FINISH | 4| |VIA_REACHED | 5| |USE_ROUNDABOUT | 6| |KEEP_RIGHT | 7| </value>
        [DataMember(Name="sign", EmitDefaultValue=false)]
        public int? Sign { get; set; }

        /// <summary>
        /// Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout. 
        /// </summary>
        /// <value>Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout. </value>
        [DataMember(Name="exit_number", EmitDefaultValue=false)]
        public int? ExitNumber { get; set; }

        /// <summary>
        /// Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout &#x60;0 &lt; r &lt; 2*PI&#x60; for clockwise and &#x60;-2*PI &lt; r &lt; 0&#x60; for counterclockwise turns. 
        /// </summary>
        /// <value>Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout &#x60;0 &lt; r &lt; 2*PI&#x60; for clockwise and &#x60;-2*PI &lt; r &lt; 0&#x60; for counterclockwise turns. </value>
        [DataMember(Name="turn_angle", EmitDefaultValue=false)]
        public double? TurnAngle { get; set; }

        /// <summary>
        /// Returns the string presentation of the object
        /// </summary>
        /// <returns>String presentation of the object</returns>
        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.Append("class RouteResponsePathInstructions {\n");
            sb.Append("  Text: ").Append(Text).Append("\n");
            sb.Append("  StreetName: ").Append(StreetName).Append("\n");
            sb.Append("  Distance: ").Append(Distance).Append("\n");
            sb.Append("  Time: ").Append(Time).Append("\n");
            sb.Append("  Interval: ").Append(Interval).Append("\n");
            sb.Append("  Sign: ").Append(Sign).Append("\n");
            sb.Append("  ExitNumber: ").Append(ExitNumber).Append("\n");
            sb.Append("  TurnAngle: ").Append(TurnAngle).Append("\n");
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
            return this.Equals(input as RouteResponsePathInstructions);
        }

        /// <summary>
        /// Returns true if RouteResponsePathInstructions instances are equal
        /// </summary>
        /// <param name="input">Instance of RouteResponsePathInstructions to be compared</param>
        /// <returns>Boolean</returns>
        public bool Equals(RouteResponsePathInstructions input)
        {
            if (input == null)
                return false;

            return 
                (
                    this.Text == input.Text ||
                    (this.Text != null &&
                    this.Text.Equals(input.Text))
                ) && 
                (
                    this.StreetName == input.StreetName ||
                    (this.StreetName != null &&
                    this.StreetName.Equals(input.StreetName))
                ) && 
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
                    this.Interval == input.Interval ||
                    this.Interval != null &&
                    input.Interval != null &&
                    this.Interval.SequenceEqual(input.Interval)
                ) && 
                (
                    this.Sign == input.Sign ||
                    (this.Sign != null &&
                    this.Sign.Equals(input.Sign))
                ) && 
                (
                    this.ExitNumber == input.ExitNumber ||
                    (this.ExitNumber != null &&
                    this.ExitNumber.Equals(input.ExitNumber))
                ) && 
                (
                    this.TurnAngle == input.TurnAngle ||
                    (this.TurnAngle != null &&
                    this.TurnAngle.Equals(input.TurnAngle))
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
                if (this.Text != null)
                    hashCode = hashCode * 59 + this.Text.GetHashCode();
                if (this.StreetName != null)
                    hashCode = hashCode * 59 + this.StreetName.GetHashCode();
                if (this.Distance != null)
                    hashCode = hashCode * 59 + this.Distance.GetHashCode();
                if (this.Time != null)
                    hashCode = hashCode * 59 + this.Time.GetHashCode();
                if (this.Interval != null)
                    hashCode = hashCode * 59 + this.Interval.GetHashCode();
                if (this.Sign != null)
                    hashCode = hashCode * 59 + this.Sign.GetHashCode();
                if (this.ExitNumber != null)
                    hashCode = hashCode * 59 + this.ExitNumber.GetHashCode();
                if (this.TurnAngle != null)
                    hashCode = hashCode * 59 + this.TurnAngle.GetHashCode();
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
