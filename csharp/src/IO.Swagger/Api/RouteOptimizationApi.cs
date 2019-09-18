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
        public interface IRouteOptimizationApi : IApiAccessor
    {
        #region Synchronous Operations
        /// <summary>
        /// Retrieve solution
        /// </summary>
        /// <remarks>
        /// This endpoint returns the solution of posted vehicle routing or traveling salesman problems. You can fetch it with the job_id, you have been sent. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="jobId">Request solution with jobId</param>
        /// <returns>Response</returns>
        Response GetSolution (string jobId);

        /// <summary>
        /// Retrieve solution
        /// </summary>
        /// <remarks>
        /// This endpoint returns the solution of posted vehicle routing or traveling salesman problems. You can fetch it with the job_id, you have been sent. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="jobId">Request solution with jobId</param>
        /// <returns>ApiResponse of Response</returns>
        ApiResponse<Response> GetSolutionWithHttpInfo (string jobId);
        /// <summary>
        /// Solve vehicle routing problem
        /// </summary>
        /// <remarks>
        ///  ### Getting Started  This tutorial - [Getting Started with the Optimization API](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - illustrates the very basic steps and building blocks to model your vehicle routing problem.  This only shows you an excerpt of what is possible with our API. You can find the entire specification of the required request (Request Body Schema) as well as the response below. It is an interactive documentation of nested objects. By default, you only see the root objects such as \&quot;vehicles\&quot;, \&quot;vehicle_types\&quot;, \&quot;objectives\&quot; etc.. To unfold detailed information about each root object, you just need to click on it as shown here  ![Nested Doc](./img/nested-doc.gif)  To explore the specification, we can recommend you to extend the problem in the tutorial above and either use our [route editor](https://www.graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/) in the Directions API dashboard or the REST clients such as Insomnia or Postman as described [here](https://docs.graphhopper.com/#section/Explore-our-APIs). Additionally, you can find a ready-to-use example in the Request Samples Panel on the right (or below). You can easily unfold it by clicking the + or you can just copy it all and paste it to our route editor or your REST client.  Furthermore, we provide [a number of tutorials](https://www.graphhopper.com/tutorial/) illustrating how to use this API and how to model your vehicle routing problems. Here, you can find a list of tutorials that might help you to get started quickly:  - [Getting Start with the Optimization API - Traveling Salesman Problem](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - [How to solve a traveling salesman problem with a week-planning horizon?](https://www.graphhopper.com/blog/2016/05/30/how-to-solve-a-traveling-salesman-problem-with-a-week-planning-horizon/) - [How to schedule technicians with skills and multiple dependencies between tasks?](https://www.graphhopper.com/blog/2016/06/03/how-to-route-technicians-with-skills-and-multiple-dependencies-between-tasks/) - [What is the difference between the min. of completion time and min. transport time?](https://www.graphhopper.com/blog/2016/06/20/what-is-the-difference-between-the-minimization-of-completion-time-and-minimizing-transport-time/) - [How to model multiple delivery routes with a single vehicle?](https://www.graphhopper.com/blog/2016/07/21/how-to-model-multiple-delivery-routes-with-a-single-vehicle/) 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="body">Request object that contains the problem to be solved</param>
        /// <returns>JobId</returns>
        JobId SolveVRP (Request body);

        /// <summary>
        /// Solve vehicle routing problem
        /// </summary>
        /// <remarks>
        ///  ### Getting Started  This tutorial - [Getting Started with the Optimization API](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - illustrates the very basic steps and building blocks to model your vehicle routing problem.  This only shows you an excerpt of what is possible with our API. You can find the entire specification of the required request (Request Body Schema) as well as the response below. It is an interactive documentation of nested objects. By default, you only see the root objects such as \&quot;vehicles\&quot;, \&quot;vehicle_types\&quot;, \&quot;objectives\&quot; etc.. To unfold detailed information about each root object, you just need to click on it as shown here  ![Nested Doc](./img/nested-doc.gif)  To explore the specification, we can recommend you to extend the problem in the tutorial above and either use our [route editor](https://www.graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/) in the Directions API dashboard or the REST clients such as Insomnia or Postman as described [here](https://docs.graphhopper.com/#section/Explore-our-APIs). Additionally, you can find a ready-to-use example in the Request Samples Panel on the right (or below). You can easily unfold it by clicking the + or you can just copy it all and paste it to our route editor or your REST client.  Furthermore, we provide [a number of tutorials](https://www.graphhopper.com/tutorial/) illustrating how to use this API and how to model your vehicle routing problems. Here, you can find a list of tutorials that might help you to get started quickly:  - [Getting Start with the Optimization API - Traveling Salesman Problem](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - [How to solve a traveling salesman problem with a week-planning horizon?](https://www.graphhopper.com/blog/2016/05/30/how-to-solve-a-traveling-salesman-problem-with-a-week-planning-horizon/) - [How to schedule technicians with skills and multiple dependencies between tasks?](https://www.graphhopper.com/blog/2016/06/03/how-to-route-technicians-with-skills-and-multiple-dependencies-between-tasks/) - [What is the difference between the min. of completion time and min. transport time?](https://www.graphhopper.com/blog/2016/06/20/what-is-the-difference-between-the-minimization-of-completion-time-and-minimizing-transport-time/) - [How to model multiple delivery routes with a single vehicle?](https://www.graphhopper.com/blog/2016/07/21/how-to-model-multiple-delivery-routes-with-a-single-vehicle/) 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="body">Request object that contains the problem to be solved</param>
        /// <returns>ApiResponse of JobId</returns>
        ApiResponse<JobId> SolveVRPWithHttpInfo (Request body);
        #endregion Synchronous Operations
        #region Asynchronous Operations
        /// <summary>
        /// Retrieve solution
        /// </summary>
        /// <remarks>
        /// This endpoint returns the solution of posted vehicle routing or traveling salesman problems. You can fetch it with the job_id, you have been sent. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="jobId">Request solution with jobId</param>
        /// <returns>Task of Response</returns>
        System.Threading.Tasks.Task<Response> GetSolutionAsync (string jobId);

        /// <summary>
        /// Retrieve solution
        /// </summary>
        /// <remarks>
        /// This endpoint returns the solution of posted vehicle routing or traveling salesman problems. You can fetch it with the job_id, you have been sent. 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="jobId">Request solution with jobId</param>
        /// <returns>Task of ApiResponse (Response)</returns>
        System.Threading.Tasks.Task<ApiResponse<Response>> GetSolutionAsyncWithHttpInfo (string jobId);
        /// <summary>
        /// Solve vehicle routing problem
        /// </summary>
        /// <remarks>
        ///  ### Getting Started  This tutorial - [Getting Started with the Optimization API](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - illustrates the very basic steps and building blocks to model your vehicle routing problem.  This only shows you an excerpt of what is possible with our API. You can find the entire specification of the required request (Request Body Schema) as well as the response below. It is an interactive documentation of nested objects. By default, you only see the root objects such as \&quot;vehicles\&quot;, \&quot;vehicle_types\&quot;, \&quot;objectives\&quot; etc.. To unfold detailed information about each root object, you just need to click on it as shown here  ![Nested Doc](./img/nested-doc.gif)  To explore the specification, we can recommend you to extend the problem in the tutorial above and either use our [route editor](https://www.graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/) in the Directions API dashboard or the REST clients such as Insomnia or Postman as described [here](https://docs.graphhopper.com/#section/Explore-our-APIs). Additionally, you can find a ready-to-use example in the Request Samples Panel on the right (or below). You can easily unfold it by clicking the + or you can just copy it all and paste it to our route editor or your REST client.  Furthermore, we provide [a number of tutorials](https://www.graphhopper.com/tutorial/) illustrating how to use this API and how to model your vehicle routing problems. Here, you can find a list of tutorials that might help you to get started quickly:  - [Getting Start with the Optimization API - Traveling Salesman Problem](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - [How to solve a traveling salesman problem with a week-planning horizon?](https://www.graphhopper.com/blog/2016/05/30/how-to-solve-a-traveling-salesman-problem-with-a-week-planning-horizon/) - [How to schedule technicians with skills and multiple dependencies between tasks?](https://www.graphhopper.com/blog/2016/06/03/how-to-route-technicians-with-skills-and-multiple-dependencies-between-tasks/) - [What is the difference between the min. of completion time and min. transport time?](https://www.graphhopper.com/blog/2016/06/20/what-is-the-difference-between-the-minimization-of-completion-time-and-minimizing-transport-time/) - [How to model multiple delivery routes with a single vehicle?](https://www.graphhopper.com/blog/2016/07/21/how-to-model-multiple-delivery-routes-with-a-single-vehicle/) 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="body">Request object that contains the problem to be solved</param>
        /// <returns>Task of JobId</returns>
        System.Threading.Tasks.Task<JobId> SolveVRPAsync (Request body);

        /// <summary>
        /// Solve vehicle routing problem
        /// </summary>
        /// <remarks>
        ///  ### Getting Started  This tutorial - [Getting Started with the Optimization API](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - illustrates the very basic steps and building blocks to model your vehicle routing problem.  This only shows you an excerpt of what is possible with our API. You can find the entire specification of the required request (Request Body Schema) as well as the response below. It is an interactive documentation of nested objects. By default, you only see the root objects such as \&quot;vehicles\&quot;, \&quot;vehicle_types\&quot;, \&quot;objectives\&quot; etc.. To unfold detailed information about each root object, you just need to click on it as shown here  ![Nested Doc](./img/nested-doc.gif)  To explore the specification, we can recommend you to extend the problem in the tutorial above and either use our [route editor](https://www.graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/) in the Directions API dashboard or the REST clients such as Insomnia or Postman as described [here](https://docs.graphhopper.com/#section/Explore-our-APIs). Additionally, you can find a ready-to-use example in the Request Samples Panel on the right (or below). You can easily unfold it by clicking the + or you can just copy it all and paste it to our route editor or your REST client.  Furthermore, we provide [a number of tutorials](https://www.graphhopper.com/tutorial/) illustrating how to use this API and how to model your vehicle routing problems. Here, you can find a list of tutorials that might help you to get started quickly:  - [Getting Start with the Optimization API - Traveling Salesman Problem](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - [How to solve a traveling salesman problem with a week-planning horizon?](https://www.graphhopper.com/blog/2016/05/30/how-to-solve-a-traveling-salesman-problem-with-a-week-planning-horizon/) - [How to schedule technicians with skills and multiple dependencies between tasks?](https://www.graphhopper.com/blog/2016/06/03/how-to-route-technicians-with-skills-and-multiple-dependencies-between-tasks/) - [What is the difference between the min. of completion time and min. transport time?](https://www.graphhopper.com/blog/2016/06/20/what-is-the-difference-between-the-minimization-of-completion-time-and-minimizing-transport-time/) - [How to model multiple delivery routes with a single vehicle?](https://www.graphhopper.com/blog/2016/07/21/how-to-model-multiple-delivery-routes-with-a-single-vehicle/) 
        /// </remarks>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="body">Request object that contains the problem to be solved</param>
        /// <returns>Task of ApiResponse (JobId)</returns>
        System.Threading.Tasks.Task<ApiResponse<JobId>> SolveVRPAsyncWithHttpInfo (Request body);
        #endregion Asynchronous Operations
    }

    /// <summary>
    /// Represents a collection of functions to interact with the API endpoints
    /// </summary>
        public partial class RouteOptimizationApi : IRouteOptimizationApi
    {
        private IO.Swagger.Client.ExceptionFactory _exceptionFactory = (name, response) => null;

        /// <summary>
        /// Initializes a new instance of the <see cref="RouteOptimizationApi"/> class.
        /// </summary>
        /// <returns></returns>
        public RouteOptimizationApi(String basePath)
        {
            this.Configuration = new IO.Swagger.Client.Configuration { BasePath = basePath };

            ExceptionFactory = IO.Swagger.Client.Configuration.DefaultExceptionFactory;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="RouteOptimizationApi"/> class
        /// </summary>
        /// <returns></returns>
        public RouteOptimizationApi()
        {
            this.Configuration = IO.Swagger.Client.Configuration.Default;

            ExceptionFactory = IO.Swagger.Client.Configuration.DefaultExceptionFactory;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="RouteOptimizationApi"/> class
        /// using Configuration object
        /// </summary>
        /// <param name="configuration">An instance of Configuration</param>
        /// <returns></returns>
        public RouteOptimizationApi(IO.Swagger.Client.Configuration configuration = null)
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
        /// Retrieve solution This endpoint returns the solution of posted vehicle routing or traveling salesman problems. You can fetch it with the job_id, you have been sent. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="jobId">Request solution with jobId</param>
        /// <returns>Response</returns>
        public Response GetSolution (string jobId)
        {
             ApiResponse<Response> localVarResponse = GetSolutionWithHttpInfo(jobId);
             return localVarResponse.Data;
        }

        /// <summary>
        /// Retrieve solution This endpoint returns the solution of posted vehicle routing or traveling salesman problems. You can fetch it with the job_id, you have been sent. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="jobId">Request solution with jobId</param>
        /// <returns>ApiResponse of Response</returns>
        public ApiResponse< Response > GetSolutionWithHttpInfo (string jobId)
        {
            // verify the required parameter 'jobId' is set
            if (jobId == null)
                throw new ApiException(400, "Missing required parameter 'jobId' when calling RouteOptimizationApi->GetSolution");

            var localVarPath = "/vrp/solution/{jobId}";
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

            if (jobId != null) localVarPathParams.Add("jobId", this.Configuration.ApiClient.ParameterToString(jobId)); // path parameter
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
                Exception exception = ExceptionFactory("GetSolution", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<Response>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (Response) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(Response)));
        }

        /// <summary>
        /// Retrieve solution This endpoint returns the solution of posted vehicle routing or traveling salesman problems. You can fetch it with the job_id, you have been sent. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="jobId">Request solution with jobId</param>
        /// <returns>Task of Response</returns>
        public async System.Threading.Tasks.Task<Response> GetSolutionAsync (string jobId)
        {
             ApiResponse<Response> localVarResponse = await GetSolutionAsyncWithHttpInfo(jobId);
             return localVarResponse.Data;

        }

        /// <summary>
        /// Retrieve solution This endpoint returns the solution of posted vehicle routing or traveling salesman problems. You can fetch it with the job_id, you have been sent. 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="jobId">Request solution with jobId</param>
        /// <returns>Task of ApiResponse (Response)</returns>
        public async System.Threading.Tasks.Task<ApiResponse<Response>> GetSolutionAsyncWithHttpInfo (string jobId)
        {
            // verify the required parameter 'jobId' is set
            if (jobId == null)
                throw new ApiException(400, "Missing required parameter 'jobId' when calling RouteOptimizationApi->GetSolution");

            var localVarPath = "/vrp/solution/{jobId}";
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

            if (jobId != null) localVarPathParams.Add("jobId", this.Configuration.ApiClient.ParameterToString(jobId)); // path parameter
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
                Exception exception = ExceptionFactory("GetSolution", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<Response>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (Response) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(Response)));
        }

        /// <summary>
        /// Solve vehicle routing problem  ### Getting Started  This tutorial - [Getting Started with the Optimization API](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - illustrates the very basic steps and building blocks to model your vehicle routing problem.  This only shows you an excerpt of what is possible with our API. You can find the entire specification of the required request (Request Body Schema) as well as the response below. It is an interactive documentation of nested objects. By default, you only see the root objects such as \&quot;vehicles\&quot;, \&quot;vehicle_types\&quot;, \&quot;objectives\&quot; etc.. To unfold detailed information about each root object, you just need to click on it as shown here  ![Nested Doc](./img/nested-doc.gif)  To explore the specification, we can recommend you to extend the problem in the tutorial above and either use our [route editor](https://www.graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/) in the Directions API dashboard or the REST clients such as Insomnia or Postman as described [here](https://docs.graphhopper.com/#section/Explore-our-APIs). Additionally, you can find a ready-to-use example in the Request Samples Panel on the right (or below). You can easily unfold it by clicking the + or you can just copy it all and paste it to our route editor or your REST client.  Furthermore, we provide [a number of tutorials](https://www.graphhopper.com/tutorial/) illustrating how to use this API and how to model your vehicle routing problems. Here, you can find a list of tutorials that might help you to get started quickly:  - [Getting Start with the Optimization API - Traveling Salesman Problem](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - [How to solve a traveling salesman problem with a week-planning horizon?](https://www.graphhopper.com/blog/2016/05/30/how-to-solve-a-traveling-salesman-problem-with-a-week-planning-horizon/) - [How to schedule technicians with skills and multiple dependencies between tasks?](https://www.graphhopper.com/blog/2016/06/03/how-to-route-technicians-with-skills-and-multiple-dependencies-between-tasks/) - [What is the difference between the min. of completion time and min. transport time?](https://www.graphhopper.com/blog/2016/06/20/what-is-the-difference-between-the-minimization-of-completion-time-and-minimizing-transport-time/) - [How to model multiple delivery routes with a single vehicle?](https://www.graphhopper.com/blog/2016/07/21/how-to-model-multiple-delivery-routes-with-a-single-vehicle/) 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="body">Request object that contains the problem to be solved</param>
        /// <returns>JobId</returns>
        public JobId SolveVRP (Request body)
        {
             ApiResponse<JobId> localVarResponse = SolveVRPWithHttpInfo(body);
             return localVarResponse.Data;
        }

        /// <summary>
        /// Solve vehicle routing problem  ### Getting Started  This tutorial - [Getting Started with the Optimization API](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - illustrates the very basic steps and building blocks to model your vehicle routing problem.  This only shows you an excerpt of what is possible with our API. You can find the entire specification of the required request (Request Body Schema) as well as the response below. It is an interactive documentation of nested objects. By default, you only see the root objects such as \&quot;vehicles\&quot;, \&quot;vehicle_types\&quot;, \&quot;objectives\&quot; etc.. To unfold detailed information about each root object, you just need to click on it as shown here  ![Nested Doc](./img/nested-doc.gif)  To explore the specification, we can recommend you to extend the problem in the tutorial above and either use our [route editor](https://www.graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/) in the Directions API dashboard or the REST clients such as Insomnia or Postman as described [here](https://docs.graphhopper.com/#section/Explore-our-APIs). Additionally, you can find a ready-to-use example in the Request Samples Panel on the right (or below). You can easily unfold it by clicking the + or you can just copy it all and paste it to our route editor or your REST client.  Furthermore, we provide [a number of tutorials](https://www.graphhopper.com/tutorial/) illustrating how to use this API and how to model your vehicle routing problems. Here, you can find a list of tutorials that might help you to get started quickly:  - [Getting Start with the Optimization API - Traveling Salesman Problem](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - [How to solve a traveling salesman problem with a week-planning horizon?](https://www.graphhopper.com/blog/2016/05/30/how-to-solve-a-traveling-salesman-problem-with-a-week-planning-horizon/) - [How to schedule technicians with skills and multiple dependencies between tasks?](https://www.graphhopper.com/blog/2016/06/03/how-to-route-technicians-with-skills-and-multiple-dependencies-between-tasks/) - [What is the difference between the min. of completion time and min. transport time?](https://www.graphhopper.com/blog/2016/06/20/what-is-the-difference-between-the-minimization-of-completion-time-and-minimizing-transport-time/) - [How to model multiple delivery routes with a single vehicle?](https://www.graphhopper.com/blog/2016/07/21/how-to-model-multiple-delivery-routes-with-a-single-vehicle/) 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="body">Request object that contains the problem to be solved</param>
        /// <returns>ApiResponse of JobId</returns>
        public ApiResponse< JobId > SolveVRPWithHttpInfo (Request body)
        {
            // verify the required parameter 'body' is set
            if (body == null)
                throw new ApiException(400, "Missing required parameter 'body' when calling RouteOptimizationApi->SolveVRP");

            var localVarPath = "/vrp/optimize";
            var localVarPathParams = new Dictionary<String, String>();
            var localVarQueryParams = new List<KeyValuePair<String, String>>();
            var localVarHeaderParams = new Dictionary<String, String>(this.Configuration.DefaultHeader);
            var localVarFormParams = new Dictionary<String, String>();
            var localVarFileParams = new Dictionary<String, FileParameter>();
            Object localVarPostBody = null;

            // to determine the Content-Type header
            String[] localVarHttpContentTypes = new String[] {
                "application/json"
            };
            String localVarHttpContentType = this.Configuration.ApiClient.SelectHeaderContentType(localVarHttpContentTypes);

            // to determine the Accept header
            String[] localVarHttpHeaderAccepts = new String[] {
                "application/json"
            };
            String localVarHttpHeaderAccept = this.Configuration.ApiClient.SelectHeaderAccept(localVarHttpHeaderAccepts);
            if (localVarHttpHeaderAccept != null)
                localVarHeaderParams.Add("Accept", localVarHttpHeaderAccept);

            if (body != null && body.GetType() != typeof(byte[]))
            {
                localVarPostBody = this.Configuration.ApiClient.Serialize(body); // http body (model) parameter
            }
            else
            {
                localVarPostBody = body; // byte array
            }
            // authentication (api_key) required
            if (!String.IsNullOrEmpty(this.Configuration.GetApiKeyWithPrefix("key")))
            {
                localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "key", this.Configuration.GetApiKeyWithPrefix("key")));
            }

            // make the HTTP request
            IRestResponse localVarResponse = (IRestResponse) this.Configuration.ApiClient.CallApi(localVarPath,
                Method.POST, localVarQueryParams, localVarPostBody, localVarHeaderParams, localVarFormParams, localVarFileParams,
                localVarPathParams, localVarHttpContentType);

            int localVarStatusCode = (int) localVarResponse.StatusCode;

            if (ExceptionFactory != null)
            {
                Exception exception = ExceptionFactory("SolveVRP", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<JobId>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (JobId) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(JobId)));
        }

        /// <summary>
        /// Solve vehicle routing problem  ### Getting Started  This tutorial - [Getting Started with the Optimization API](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - illustrates the very basic steps and building blocks to model your vehicle routing problem.  This only shows you an excerpt of what is possible with our API. You can find the entire specification of the required request (Request Body Schema) as well as the response below. It is an interactive documentation of nested objects. By default, you only see the root objects such as \&quot;vehicles\&quot;, \&quot;vehicle_types\&quot;, \&quot;objectives\&quot; etc.. To unfold detailed information about each root object, you just need to click on it as shown here  ![Nested Doc](./img/nested-doc.gif)  To explore the specification, we can recommend you to extend the problem in the tutorial above and either use our [route editor](https://www.graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/) in the Directions API dashboard or the REST clients such as Insomnia or Postman as described [here](https://docs.graphhopper.com/#section/Explore-our-APIs). Additionally, you can find a ready-to-use example in the Request Samples Panel on the right (or below). You can easily unfold it by clicking the + or you can just copy it all and paste it to our route editor or your REST client.  Furthermore, we provide [a number of tutorials](https://www.graphhopper.com/tutorial/) illustrating how to use this API and how to model your vehicle routing problems. Here, you can find a list of tutorials that might help you to get started quickly:  - [Getting Start with the Optimization API - Traveling Salesman Problem](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - [How to solve a traveling salesman problem with a week-planning horizon?](https://www.graphhopper.com/blog/2016/05/30/how-to-solve-a-traveling-salesman-problem-with-a-week-planning-horizon/) - [How to schedule technicians with skills and multiple dependencies between tasks?](https://www.graphhopper.com/blog/2016/06/03/how-to-route-technicians-with-skills-and-multiple-dependencies-between-tasks/) - [What is the difference between the min. of completion time and min. transport time?](https://www.graphhopper.com/blog/2016/06/20/what-is-the-difference-between-the-minimization-of-completion-time-and-minimizing-transport-time/) - [How to model multiple delivery routes with a single vehicle?](https://www.graphhopper.com/blog/2016/07/21/how-to-model-multiple-delivery-routes-with-a-single-vehicle/) 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="body">Request object that contains the problem to be solved</param>
        /// <returns>Task of JobId</returns>
        public async System.Threading.Tasks.Task<JobId> SolveVRPAsync (Request body)
        {
             ApiResponse<JobId> localVarResponse = await SolveVRPAsyncWithHttpInfo(body);
             return localVarResponse.Data;

        }

        /// <summary>
        /// Solve vehicle routing problem  ### Getting Started  This tutorial - [Getting Started with the Optimization API](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - illustrates the very basic steps and building blocks to model your vehicle routing problem.  This only shows you an excerpt of what is possible with our API. You can find the entire specification of the required request (Request Body Schema) as well as the response below. It is an interactive documentation of nested objects. By default, you only see the root objects such as \&quot;vehicles\&quot;, \&quot;vehicle_types\&quot;, \&quot;objectives\&quot; etc.. To unfold detailed information about each root object, you just need to click on it as shown here  ![Nested Doc](./img/nested-doc.gif)  To explore the specification, we can recommend you to extend the problem in the tutorial above and either use our [route editor](https://www.graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/) in the Directions API dashboard or the REST clients such as Insomnia or Postman as described [here](https://docs.graphhopper.com/#section/Explore-our-APIs). Additionally, you can find a ready-to-use example in the Request Samples Panel on the right (or below). You can easily unfold it by clicking the + or you can just copy it all and paste it to our route editor or your REST client.  Furthermore, we provide [a number of tutorials](https://www.graphhopper.com/tutorial/) illustrating how to use this API and how to model your vehicle routing problems. Here, you can find a list of tutorials that might help you to get started quickly:  - [Getting Start with the Optimization API - Traveling Salesman Problem](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - [How to solve a traveling salesman problem with a week-planning horizon?](https://www.graphhopper.com/blog/2016/05/30/how-to-solve-a-traveling-salesman-problem-with-a-week-planning-horizon/) - [How to schedule technicians with skills and multiple dependencies between tasks?](https://www.graphhopper.com/blog/2016/06/03/how-to-route-technicians-with-skills-and-multiple-dependencies-between-tasks/) - [What is the difference between the min. of completion time and min. transport time?](https://www.graphhopper.com/blog/2016/06/20/what-is-the-difference-between-the-minimization-of-completion-time-and-minimizing-transport-time/) - [How to model multiple delivery routes with a single vehicle?](https://www.graphhopper.com/blog/2016/07/21/how-to-model-multiple-delivery-routes-with-a-single-vehicle/) 
        /// </summary>
        /// <exception cref="IO.Swagger.Client.ApiException">Thrown when fails to make API call</exception>
        /// <param name="body">Request object that contains the problem to be solved</param>
        /// <returns>Task of ApiResponse (JobId)</returns>
        public async System.Threading.Tasks.Task<ApiResponse<JobId>> SolveVRPAsyncWithHttpInfo (Request body)
        {
            // verify the required parameter 'body' is set
            if (body == null)
                throw new ApiException(400, "Missing required parameter 'body' when calling RouteOptimizationApi->SolveVRP");

            var localVarPath = "/vrp/optimize";
            var localVarPathParams = new Dictionary<String, String>();
            var localVarQueryParams = new List<KeyValuePair<String, String>>();
            var localVarHeaderParams = new Dictionary<String, String>(this.Configuration.DefaultHeader);
            var localVarFormParams = new Dictionary<String, String>();
            var localVarFileParams = new Dictionary<String, FileParameter>();
            Object localVarPostBody = null;

            // to determine the Content-Type header
            String[] localVarHttpContentTypes = new String[] {
                "application/json"
            };
            String localVarHttpContentType = this.Configuration.ApiClient.SelectHeaderContentType(localVarHttpContentTypes);

            // to determine the Accept header
            String[] localVarHttpHeaderAccepts = new String[] {
                "application/json"
            };
            String localVarHttpHeaderAccept = this.Configuration.ApiClient.SelectHeaderAccept(localVarHttpHeaderAccepts);
            if (localVarHttpHeaderAccept != null)
                localVarHeaderParams.Add("Accept", localVarHttpHeaderAccept);

            if (body != null && body.GetType() != typeof(byte[]))
            {
                localVarPostBody = this.Configuration.ApiClient.Serialize(body); // http body (model) parameter
            }
            else
            {
                localVarPostBody = body; // byte array
            }
            // authentication (api_key) required
            if (!String.IsNullOrEmpty(this.Configuration.GetApiKeyWithPrefix("key")))
            {
                localVarQueryParams.AddRange(this.Configuration.ApiClient.ParameterToKeyValuePairs("", "key", this.Configuration.GetApiKeyWithPrefix("key")));
            }

            // make the HTTP request
            IRestResponse localVarResponse = (IRestResponse) await this.Configuration.ApiClient.CallApiAsync(localVarPath,
                Method.POST, localVarQueryParams, localVarPostBody, localVarHeaderParams, localVarFormParams, localVarFileParams,
                localVarPathParams, localVarHttpContentType);

            int localVarStatusCode = (int) localVarResponse.StatusCode;

            if (ExceptionFactory != null)
            {
                Exception exception = ExceptionFactory("SolveVRP", localVarResponse);
                if (exception != null) throw exception;
            }

            return new ApiResponse<JobId>(localVarStatusCode,
                localVarResponse.Headers.ToDictionary(x => x.Name, x => string.Join(",", x.Value)),
                (JobId) this.Configuration.ApiClient.Deserialize(localVarResponse, typeof(JobId)));
        }

    }
}
