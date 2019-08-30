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
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using RestSharp;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace IO.Swagger.Api
{
    /// <summary>
    /// Represents a collection of functions to interact with the API endpoints
    /// </summary>
        public interface IIsochroneApi : IApiAccessor
    {
        #region Synchronous Operations
        /// <summary>
        /// Isochrone Request
        /// </summary>
        /// <remarks>
        /// ### Example You can get an example response via:  &#x60;&#x60;&#x60; curl \&quot;https://graphhopper.com/api/1/isochrone?point&#x3D;51.131108,12.414551&amp;key&#x3D;[YOUR_KEY]\&quot; &#x60;&#x60;&#x60;  Don&#x27;t forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is &#x27;&#x27;a line connecting points at which a vehicle arrives at the same time&#x27;&#x27;, see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit&#x60;.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">Specify the start coordinate</param>
        /// <param name="timeLimit">Specify which time the vehicle should travel. In seconds. (optional)</param>
        /// <param name="distanceLimit">Specify which distance the vehicle should travel. In meters. (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="buckets">For how many subintervals an additional polygon should be calculated. (optional)</param>
        /// <param name="reverseFlow">If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  (optional)</param>
        /// <param name="weighting">Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. (optional)</param>
        /// <returns>IsochroneResponse</returns>
        IsochroneResponse GetIsochrone (string point, int? timeLimit = null, int? distanceLimit = null, VehicleProfileId vehicle = null, int? buckets = null, bool? reverseFlow = null, string weighting = null);

        /// <summary>
        /// Isochrone Request
        /// </summary>
        /// <remarks>
        /// ### Example You can get an example response via:  &#x60;&#x60;&#x60; curl \&quot;https://graphhopper.com/api/1/isochrone?point&#x3D;51.131108,12.414551&amp;key&#x3D;[YOUR_KEY]\&quot; &#x60;&#x60;&#x60;  Don&#x27;t forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is &#x27;&#x27;a line connecting points at which a vehicle arrives at the same time&#x27;&#x27;, see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit&#x60;.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">Specify the start coordinate</param>
        /// <param name="timeLimit">Specify which time the vehicle should travel. In seconds. (optional)</param>
        /// <param name="distanceLimit">Specify which distance the vehicle should travel. In meters. (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="buckets">For how many subintervals an additional polygon should be calculated. (optional)</param>
        /// <param name="reverseFlow">If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  (optional)</param>
        /// <param name="weighting">Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. (optional)</param>
        /// <returns>ApiResponse of IsochroneResponse</returns>
        ApiResponse<IsochroneResponse> GetIsochroneWithHttpInfo (string point, int? timeLimit = null, int? distanceLimit = null, VehicleProfileId vehicle = null, int? buckets = null, bool? reverseFlow = null, string weighting = null);
        #endregion Synchronous Operations
        #region Asynchronous Operations
        /// <summary>
        /// Isochrone Request
        /// </summary>
        /// <remarks>
        /// ### Example You can get an example response via:  &#x60;&#x60;&#x60; curl \&quot;https://graphhopper.com/api/1/isochrone?point&#x3D;51.131108,12.414551&amp;key&#x3D;[YOUR_KEY]\&quot; &#x60;&#x60;&#x60;  Don&#x27;t forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is &#x27;&#x27;a line connecting points at which a vehicle arrives at the same time&#x27;&#x27;, see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit&#x60;.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">Specify the start coordinate</param>
        /// <param name="timeLimit">Specify which time the vehicle should travel. In seconds. (optional)</param>
        /// <param name="distanceLimit">Specify which distance the vehicle should travel. In meters. (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="buckets">For how many subintervals an additional polygon should be calculated. (optional)</param>
        /// <param name="reverseFlow">If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  (optional)</param>
        /// <param name="weighting">Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. (optional)</param>
        /// <returns>Task of IsochroneResponse</returns>
        System.Threading.Tasks.Task<IsochroneResponse> GetIsochroneAsync (string point, int? timeLimit = null, int? distanceLimit = null, VehicleProfileId vehicle = null, int? buckets = null, bool? reverseFlow = null, string weighting = null);

        /// <summary>
        /// Isochrone Request
        /// </summary>
        /// <remarks>
        /// ### Example You can get an example response via:  &#x60;&#x60;&#x60; curl \&quot;https://graphhopper.com/api/1/isochrone?point&#x3D;51.131108,12.414551&amp;key&#x3D;[YOUR_KEY]\&quot; &#x60;&#x60;&#x60;  Don&#x27;t forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is &#x27;&#x27;a line connecting points at which a vehicle arrives at the same time&#x27;&#x27;, see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit&#x60;.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">Specify the start coordinate</param>
        /// <param name="timeLimit">Specify which time the vehicle should travel. In seconds. (optional)</param>
        /// <param name="distanceLimit">Specify which distance the vehicle should travel. In meters. (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="buckets">For how many subintervals an additional polygon should be calculated. (optional)</param>
        /// <param name="reverseFlow">If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  (optional)</param>
        /// <param name="weighting">Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. (optional)</param>
        /// <returns>Task of ApiResponse (IsochroneResponse)</returns>
        System.Threading.Tasks.Task<ApiResponse<IsochroneResponse>> GetIsochroneAsyncWithHttpInfo (string point, int? timeLimit = null, int? distanceLimit = null, VehicleProfileId vehicle = null, int? buckets = null, bool? reverseFlow = null, string weighting = null);
        #endregion Asynchronous Operations
    }

    /// <summary>
    /// Represents a collection of functions to interact with the API endpoints
    /// </summary>
        public partial class IsochroneApi : IIsochroneApi
    {
        private IO.Swagger.Client.ExceptionFactory _exceptionFactory = (name, response) => null;

        /// <summary>
        /// Initializes a new instance of the <see cref="IsochroneApi"/> class.
        /// </summary>
        /// <returns></returns>
        public IsochroneApi(String basePath)
        {
            this.Configuration = new IO.Swagger.Client.Configuration { BasePath = basePath };

            ExceptionFactory = IO.Swagger.Client.Configuration.DefaultExceptionFactory;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="IsochroneApi"/> class
        /// </summary>
        /// <returns></returns>
        public IsochroneApi()
        {
            this.Configuration = IO.Swagger.Client.Configuration.Default;

            ExceptionFactory = IO.Swagger.Client.Configuration.DefaultExceptionFactory;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="IsochroneApi"/> class
        /// using Configuration object
        /// </summary>
        /// <param name="configuration">An instance of Configuration</param>
        /// <returns></returns>
        public IsochroneApi(IO.Swagger.Client.Configuration configuration = null)
        {
            if (configuration == null) // use the default one in Configuration
                this.Configuration = IO.Swagger.Client.Configuration.Default;
            else
                this.Configuration = configuration;

            ExceptionFactory = IO.Swagger.Client.Configuration.DefaultExceptionFactory;
        }

        /// <summary>
        /// Gets the base path of the API client.
        /// </summary>
        /// <value>The base path</value>
        public String GetBasePath()
        {
            return this.Configuration.ApiClient.RestClient.BaseUrl.ToString();
        }

        /// <summary>
        /// Sets the base path of the API client.
        /// </summary>
        /// <value>The base path</value>
        [Obsolete("SetBasePath is deprecated, please do 'Configuration.ApiClient = new ApiClient(\"http://new-path\")' instead.")]
        public void SetBasePath(String basePath)
        {
            // do nothing
        }

        /// <summary>
        /// Gets or sets the configuration object
        /// </summary>
        /// <value>An instance of the Configuration</value>
        public IO.Swagger.Client.Configuration Configuration {get; set;}

        /// <summary>
        /// Provides a factory method hook for the creation of exceptions.
        /// </summary>
        public IO.Swagger.Client.ExceptionFactory ExceptionFactory
        {
            get
            {
                if (_exceptionFactory != null && _exceptionFactory.GetInvocationList().Length > 1)
                {
                    throw new InvalidOperationException("Multicast delegate for ExceptionFactory is unsupported.");
                }
                return _exceptionFactory;
            }
            set { _exceptionFactory = value; }
        }

        /// <summary>
        /// Gets the default header.
        /// </summary>
        /// <returns>Dictionary of HTTP header</returns>
        [Obsolete("DefaultHeader is deprecated, please use Configuration.DefaultHeader instead.")]
        public IDictionary<String, String> DefaultHeader()
        {
            return new ReadOnlyDictionary<string, string>(this.Configuration.DefaultHeader);
        }

        /// <summary>
        /// Add default header.
        /// </summary>
        /// <param name="key">Header field name.</param>
        /// <param name="value">Header field value.</param>
        /// <returns></returns>
        [Obsolete("AddDefaultHeader is deprecated, please use Configuration.AddDefaultHeader instead.")]
        public void AddDefaultHeader(string key, string value)
        {
            this.Configuration.AddDefaultHeader(key, value);
        }

        /// <summary>
        /// Isochrone Request ### Example You can get an example response via:  &#x60;&#x60;&#x60; curl \&quot;https://graphhopper.com/api/1/isochrone?point&#x3D;51.131108,12.414551&amp;key&#x3D;[YOUR_KEY]\&quot; &#x60;&#x60;&#x60;  Don&#x27;t forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is &#x27;&#x27;a line connecting points at which a vehicle arrives at the same time&#x27;&#x27;, see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit&#x60;.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">Specify the start coordinate</param>
        /// <param name="timeLimit">Specify which time the vehicle should travel. In seconds. (optional)</param>
        /// <param name="distanceLimit">Specify which distance the vehicle should travel. In meters. (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="buckets">For how many subintervals an additional polygon should be calculated. (optional)</param>
        /// <param name="reverseFlow">If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  (optional)</param>
        /// <param name="weighting">Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. (optional)</param>
        /// <returns>IsochroneResponse</returns>
        public IsochroneResponse GetIsochrone (string point, int? timeLimit = null, int? distanceLimit = null, VehicleProfileId vehicle = null, int? buckets = null, bool? reverseFlow = null, string weighting = null)
        {
             ApiResponse<IsochroneResponse> localVarResponse = GetIsochroneWithHttpInfo(point, timeLimit, distanceLimit, vehicle, buckets, reverseFlow, weighting);
             return localVarResponse.Data;
        }

        /// <summary>
        /// Isochrone Request ### Example You can get an example response via:  &#x60;&#x60;&#x60; curl \&quot;https://graphhopper.com/api/1/isochrone?point&#x3D;51.131108,12.414551&amp;key&#x3D;[YOUR_KEY]\&quot; &#x60;&#x60;&#x60;  Don&#x27;t forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is &#x27;&#x27;a line connecting points at which a vehicle arrives at the same time&#x27;&#x27;, see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit&#x60;.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">Specify the start coordinate</param>
        /// <param name="timeLimit">Specify which time the vehicle should travel. In seconds. (optional)</param>
        /// <param name="distanceLimit">Specify which distance the vehicle should travel. In meters. (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="buckets">For how many subintervals an additional polygon should be calculated. (optional)</param>
        /// <param name="reverseFlow">If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  (optional)</param>
        /// <param name="weighting">Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. (optional)</param>
        /// <returns>ApiResponse of IsochroneResponse</returns>
        public ApiResponse< IsochroneResponse > GetIsochroneWithHttpInfo (string point, int? timeLimit = null, int? distanceLimit = null, VehicleProfileId vehicle = null, int? buckets = null, bool? reverseFlow = null, string weighting = null)
        {
            // verify the required parameter 'point' is set
            if (point == null)
                throw new ApiException(400, "Missing required parameter 'point' when calling IsochroneApi->GetIsochrone");

            var localVarPath = "/isochrone";
            var localVarPathParams = new Dictionary<String, String>();
            var localVarQueryParams = new List<KeyValuePair<String, String>>();
            var localVarHeaderParams = new Dictionary<String, String>(this.Configuration.DefaultHeader);
            var localVarFormParams = new Dictionary<String, String>();
            var localVarFileParams = new Dictionary<String, FileParameter>();
            Object localVarPostBody = null;

            // to determine the Content-Type header
            String[] localVarHttpContentTypes = new String[] {
            };
            String localVarHttpContentType = this.Configuration.ApiClient.SelectHeaderContentType(localVarHttpContentTypes);

            // to determine the Accept header
            String[] localVarHttpHeaderAccepts = new String[] {
                "application/json"
            };
            String localVarHttpHeaderAccept = this.Configuration.ApiClient.SelectHeaderAccept(localVarHttpHeaderAccepts);
            if (localVarHttpHeaderAccept != null)
                localVarHeaderParams.Add("Accept", localVarHttpHeaderAccept);

            if (point != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "point", point)); // query parameter
            if (timeLimit != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "time_limit", timeLimit)); // query parameter
            if (distanceLimit != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "distance_limit", distanceLimit)); // query parameter
            if (vehicle != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "vehicle", vehicle)); // query parameter
            if (buckets != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "buckets", buckets)); // query parameter
            if (reverseFlow != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "reverse_flow", reverseFlow)); // query parameter
            if (weighting != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "weighting", weighting)); // query parameter
            // authentication (api_key) required
            if (!String.IsNullOrEmpty(this.Configuration.GetApiKeyWithPrefix("key")))
            {
                localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "key", this.Configuration.GetApiKeyWithPrefix("key")));
            }

            // make the HTTP request
            IRestResponse localVarResponse = (IRestResponse) this.Configuration.ApiClient.CallApi(localVarPath,
                Method.GET, localVarQueryParams, localVarPostBody, localVarHeaderParams, localVarFormParams, localVarFileParams,
                localVarPathParams, localVarHttpContentType);

            int localVarStatusCode = (int) localVarResponse.StatusCode;

            if (ExceptionFactory != null)
            {
                Exception exception = ExceptionFactory("GetIsochrone", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<IsochroneResponse>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (IsochroneResponse) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(IsochroneResponse)));
        }

        /// <summary>
        /// Isochrone Request ### Example You can get an example response via:  &#x60;&#x60;&#x60; curl \&quot;https://graphhopper.com/api/1/isochrone?point&#x3D;51.131108,12.414551&amp;key&#x3D;[YOUR_KEY]\&quot; &#x60;&#x60;&#x60;  Don&#x27;t forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is &#x27;&#x27;a line connecting points at which a vehicle arrives at the same time&#x27;&#x27;, see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit&#x60;.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">Specify the start coordinate</param>
        /// <param name="timeLimit">Specify which time the vehicle should travel. In seconds. (optional)</param>
        /// <param name="distanceLimit">Specify which distance the vehicle should travel. In meters. (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="buckets">For how many subintervals an additional polygon should be calculated. (optional)</param>
        /// <param name="reverseFlow">If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  (optional)</param>
        /// <param name="weighting">Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. (optional)</param>
        /// <returns>Task of IsochroneResponse</returns>
        public async System.Threading.Tasks.Task<IsochroneResponse> GetIsochroneAsync (string point, int? timeLimit = null, int? distanceLimit = null, VehicleProfileId vehicle = null, int? buckets = null, bool? reverseFlow = null, string weighting = null)
        {
             ApiResponse<IsochroneResponse> localVarResponse = await GetIsochroneAsyncWithHttpInfo(point, timeLimit, distanceLimit, vehicle, buckets, reverseFlow, weighting);
             return localVarResponse.Data;

        }

        /// <summary>
        /// Isochrone Request ### Example You can get an example response via:  &#x60;&#x60;&#x60; curl \&quot;https://graphhopper.com/api/1/isochrone?point&#x3D;51.131108,12.414551&amp;key&#x3D;[YOUR_KEY]\&quot; &#x60;&#x60;&#x60;  Don&#x27;t forget to replace the placeholder with your own key.  ### Introduction ![Isochrone screenshot](./img/isochrone-example.png)  An isochrone of a location is &#x27;&#x27;a line connecting points at which a vehicle arrives at the same time&#x27;&#x27;, see Wikipedia. With the same API you can also calculate isodistances, just use the parameter distance_limit instead of time_limit&#x60;.  ### Use Cases Some possible areas in which this API may be useful to you:  - real estate analysis - realtors - vehicle scheduling - geomarketing - reach of electric vehicles - transport planning - logistics (distribution and retail network planning)  ### API Clients and Examples See the [clients](#section/API-Clients) section in the main documentation, and [live examples](https://graphhopper.com/api/1/examples/#isochrone). 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="point">Specify the start coordinate</param>
        /// <param name="timeLimit">Specify which time the vehicle should travel. In seconds. (optional)</param>
        /// <param name="distanceLimit">Specify which distance the vehicle should travel. In meters. (optional)</param>
        /// <param name="vehicle">The vehicle profile for which the route should be calculated.  (optional)</param>
        /// <param name="buckets">For how many subintervals an additional polygon should be calculated. (optional)</param>
        /// <param name="reverseFlow">If &#x60;false&#x60; the flow goes from point to the polygon, if &#x60;true&#x60; the flow goes from the polygon \&quot;inside\&quot; to the point. Example use case for &#x60;false&#x60;&amp;#58; *How many potential customer can be reached within 30min travel time from your store* vs. &#x60;true&#x60;&amp;#58; *How many customers can reach your store within 30min travel time.*  (optional)</param>
        /// <param name="weighting">Use &#x60;\&quot;shortest\&quot;&#x60; to get an isodistance line instead of an isochrone. (optional)</param>
        /// <returns>Task of ApiResponse (IsochroneResponse)</returns>
        public async System.Threading.Tasks.Task<ApiResponse<IsochroneResponse>> GetIsochroneAsyncWithHttpInfo (string point, int? timeLimit = null, int? distanceLimit = null, VehicleProfileId vehicle = null, int? buckets = null, bool? reverseFlow = null, string weighting = null)
        {
            // verify the required parameter 'point' is set
            if (point == null)
                throw new ApiException(400, "Missing required parameter 'point' when calling IsochroneApi->GetIsochrone");

            var localVarPath = "/isochrone";
            var localVarPathParams = new Dictionary<String, String>();
            var localVarQueryParams = new List<KeyValuePair<String, String>>();
            var localVarHeaderParams = new Dictionary<String, String>(this.Configuration.DefaultHeader);
            var localVarFormParams = new Dictionary<String, String>();
            var localVarFileParams = new Dictionary<String, FileParameter>();
            Object localVarPostBody = null;

            // to determine the Content-Type header
            String[] localVarHttpContentTypes = new String[] {
            };
            String localVarHttpContentType = this.Configuration.ApiClient.SelectHeaderContentType(localVarHttpContentTypes);

            // to determine the Accept header
            String[] localVarHttpHeaderAccepts = new String[] {
                "application/json"
            };
            String localVarHttpHeaderAccept = this.Configuration.ApiClient.SelectHeaderAccept(localVarHttpHeaderAccepts);
            if (localVarHttpHeaderAccept != null)
                localVarHeaderParams.Add("Accept", localVarHttpHeaderAccept);

            if (point != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "point", point)); // query parameter
            if (timeLimit != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "time_limit", timeLimit)); // query parameter
            if (distanceLimit != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "distance_limit", distanceLimit)); // query parameter
            if (vehicle != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "vehicle", vehicle)); // query parameter
            if (buckets != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "buckets", buckets)); // query parameter
            if (reverseFlow != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "reverse_flow", reverseFlow)); // query parameter
            if (weighting != null) localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "weighting", weighting)); // query parameter
            // authentication (api_key) required
            if (!String.IsNullOrEmpty(this.Configuration.GetApiKeyWithPrefix("key")))
            {
                localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "key", this.Configuration.GetApiKeyWithPrefix("key")));
            }

            // make the HTTP request
            IRestResponse localVarResponse = (IRestResponse) await this.Configuration.ApiClient.CallApiAsync(localVarPath,
                Method.GET, localVarQueryParams, localVarPostBody, localVarHeaderParams, localVarFormParams, localVarFileParams,
                localVarPathParams, localVarHttpContentType);

            int localVarStatusCode = (int) localVarResponse.StatusCode;

            if (ExceptionFactory != null)
            {
                Exception exception = ExceptionFactory("GetIsochrone", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<IsochroneResponse>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (IsochroneResponse) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(IsochroneResponse)));
        }

    }
}
