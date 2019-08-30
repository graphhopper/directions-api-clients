<?php
/**
 * Solution
 *
 * PHP version 5
 *
 * @category Class
 * @package  Swagger\Client
 * @author   Swagger Codegen team
 * @link     https://github.com/swagger-api/swagger-codegen
 */

/**
 * GraphHopper Directions API
 *
 * With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Clients  To speed up development and make coding easier, we offer the following clients:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions for motor vehicles such as `car` or `truck` are only considered with `edge_based=true` for the Routing (other APIs will follow).** Or if you already use `ch.disable=true` no additional parameter is required to consider turn restrictions for motor vehicles.  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png)
 *
 * OpenAPI spec version: 1.0.0
 * Contact: support@graphhopper.com
 * Generated by: https://github.com/swagger-api/swagger-codegen.git
 * Swagger Codegen version: 3.0.11
 */
/**
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen
 * Do not edit the class manually.
 */

namespace Swagger\Client\Model;

use \ArrayAccess;
use \Swagger\Client\ObjectSerializer;

/**
 * Solution Class Doc Comment
 *
 * @category Class
 * @description Only available if status field indicates &#x60;finished&#x60;.
 * @package  Swagger\Client
 * @author   Swagger Codegen team
 * @link     https://github.com/swagger-api/swagger-codegen
 */
class Solution implements ModelInterface, ArrayAccess
{
    const DISCRIMINATOR = null;

    /**
      * The original name of the model.
      *
      * @var string
      */
    protected static $swaggerModelName = 'Solution';

    /**
      * Array of property to type mappings. Used for (de)serialization
      *
      * @var string[]
      */
    protected static $swaggerTypes = [
        'costs' => 'int',
'distance' => 'int',
'time' => 'int',
'transport_time' => 'int',
'max_operation_time' => 'int',
'waiting_time' => 'int',
'service_duration' => 'int',
'preparation_time' => 'int',
'completion_time' => 'int',
'no_vehicles' => 'int',
'no_unassigned' => 'int',
'routes' => '\Swagger\Client\Model\Route[]',
'unassigned' => '\Swagger\Client\Model\SolutionUnassigned'    ];

    /**
      * Array of property to format mappings. Used for (de)serialization
      *
      * @var string[]
      */
    protected static $swaggerFormats = [
        'costs' => 'int32',
'distance' => 'int32',
'time' => 'int64',
'transport_time' => 'int64',
'max_operation_time' => 'int64',
'waiting_time' => 'int64',
'service_duration' => 'int64',
'preparation_time' => 'int64',
'completion_time' => 'int64',
'no_vehicles' => 'int32',
'no_unassigned' => 'int32',
'routes' => null,
'unassigned' => null    ];

    /**
     * Array of property to type mappings. Used for (de)serialization
     *
     * @return array
     */
    public static function swaggerTypes()
    {
        return self::$swaggerTypes;
    }

    /**
     * Array of property to format mappings. Used for (de)serialization
     *
     * @return array
     */
    public static function swaggerFormats()
    {
        return self::$swaggerFormats;
    }

    /**
     * Array of attributes where the key is the local name,
     * and the value is the original name
     *
     * @var string[]
     */
    protected static $attributeMap = [
        'costs' => 'costs',
'distance' => 'distance',
'time' => 'time',
'transport_time' => 'transport_time',
'max_operation_time' => 'max_operation_time',
'waiting_time' => 'waiting_time',
'service_duration' => 'service_duration',
'preparation_time' => 'preparation_time',
'completion_time' => 'completion_time',
'no_vehicles' => 'no_vehicles',
'no_unassigned' => 'no_unassigned',
'routes' => 'routes',
'unassigned' => 'unassigned'    ];

    /**
     * Array of attributes to setter functions (for deserialization of responses)
     *
     * @var string[]
     */
    protected static $setters = [
        'costs' => 'setCosts',
'distance' => 'setDistance',
'time' => 'setTime',
'transport_time' => 'setTransportTime',
'max_operation_time' => 'setMaxOperationTime',
'waiting_time' => 'setWaitingTime',
'service_duration' => 'setServiceDuration',
'preparation_time' => 'setPreparationTime',
'completion_time' => 'setCompletionTime',
'no_vehicles' => 'setNoVehicles',
'no_unassigned' => 'setNoUnassigned',
'routes' => 'setRoutes',
'unassigned' => 'setUnassigned'    ];

    /**
     * Array of attributes to getter functions (for serialization of requests)
     *
     * @var string[]
     */
    protected static $getters = [
        'costs' => 'getCosts',
'distance' => 'getDistance',
'time' => 'getTime',
'transport_time' => 'getTransportTime',
'max_operation_time' => 'getMaxOperationTime',
'waiting_time' => 'getWaitingTime',
'service_duration' => 'getServiceDuration',
'preparation_time' => 'getPreparationTime',
'completion_time' => 'getCompletionTime',
'no_vehicles' => 'getNoVehicles',
'no_unassigned' => 'getNoUnassigned',
'routes' => 'getRoutes',
'unassigned' => 'getUnassigned'    ];

    /**
     * Array of attributes where the key is the local name,
     * and the value is the original name
     *
     * @return array
     */
    public static function attributeMap()
    {
        return self::$attributeMap;
    }

    /**
     * Array of attributes to setter functions (for deserialization of responses)
     *
     * @return array
     */
    public static function setters()
    {
        return self::$setters;
    }

    /**
     * Array of attributes to getter functions (for serialization of requests)
     *
     * @return array
     */
    public static function getters()
    {
        return self::$getters;
    }

    /**
     * The original name of the model.
     *
     * @return string
     */
    public function getModelName()
    {
        return self::$swaggerModelName;
    }

    

    /**
     * Associative array for storing property values
     *
     * @var mixed[]
     */
    protected $container = [];

    /**
     * Constructor
     *
     * @param mixed[] $data Associated array of property values
     *                      initializing the model
     */
    public function __construct(array $data = null)
    {
        $this->container['costs'] = isset($data['costs']) ? $data['costs'] : null;
        $this->container['distance'] = isset($data['distance']) ? $data['distance'] : null;
        $this->container['time'] = isset($data['time']) ? $data['time'] : null;
        $this->container['transport_time'] = isset($data['transport_time']) ? $data['transport_time'] : null;
        $this->container['max_operation_time'] = isset($data['max_operation_time']) ? $data['max_operation_time'] : null;
        $this->container['waiting_time'] = isset($data['waiting_time']) ? $data['waiting_time'] : null;
        $this->container['service_duration'] = isset($data['service_duration']) ? $data['service_duration'] : null;
        $this->container['preparation_time'] = isset($data['preparation_time']) ? $data['preparation_time'] : null;
        $this->container['completion_time'] = isset($data['completion_time']) ? $data['completion_time'] : null;
        $this->container['no_vehicles'] = isset($data['no_vehicles']) ? $data['no_vehicles'] : null;
        $this->container['no_unassigned'] = isset($data['no_unassigned']) ? $data['no_unassigned'] : null;
        $this->container['routes'] = isset($data['routes']) ? $data['routes'] : null;
        $this->container['unassigned'] = isset($data['unassigned']) ? $data['unassigned'] : null;
    }

    /**
     * Show all the invalid properties with reasons.
     *
     * @return array invalid properties with reasons
     */
    public function listInvalidProperties()
    {
        $invalidProperties = [];

        return $invalidProperties;
    }

    /**
     * Validate all the properties in the model
     * return true if all passed
     *
     * @return bool True if all properties are valid
     */
    public function valid()
    {
        return count($this->listInvalidProperties()) === 0;
    }


    /**
     * Gets costs
     *
     * @return int
     */
    public function getCosts()
    {
        return $this->container['costs'];
    }

    /**
     * Sets costs
     *
     * @param int $costs costs
     *
     * @return $this
     */
    public function setCosts($costs)
    {
        $this->container['costs'] = $costs;

        return $this;
    }

    /**
     * Gets distance
     *
     * @return int
     */
    public function getDistance()
    {
        return $this->container['distance'];
    }

    /**
     * Sets distance
     *
     * @param int $distance Overall distance travelled in meter, i.e. the sum of each route's transport distance
     *
     * @return $this
     */
    public function setDistance($distance)
    {
        $this->container['distance'] = $distance;

        return $this;
    }

    /**
     * Gets time
     *
     * @return int
     */
    public function getTime()
    {
        return $this->container['time'];
    }

    /**
     * Sets time
     *
     * @param int $time Use `transport_time` instead.
     *
     * @return $this
     */
    public function setTime($time)
    {
        $this->container['time'] = $time;

        return $this;
    }

    /**
     * Gets transport_time
     *
     * @return int
     */
    public function getTransportTime()
    {
        return $this->container['transport_time'];
    }

    /**
     * Sets transport_time
     *
     * @param int $transport_time Overall time travelled in seconds, i.e. the sum of each route's transport time.
     *
     * @return $this
     */
    public function setTransportTime($transport_time)
    {
        $this->container['transport_time'] = $transport_time;

        return $this;
    }

    /**
     * Gets max_operation_time
     *
     * @return int
     */
    public function getMaxOperationTime()
    {
        return $this->container['max_operation_time'];
    }

    /**
     * Sets max_operation_time
     *
     * @param int $max_operation_time Operation time of longest route in seconds.
     *
     * @return $this
     */
    public function setMaxOperationTime($max_operation_time)
    {
        $this->container['max_operation_time'] = $max_operation_time;

        return $this;
    }

    /**
     * Gets waiting_time
     *
     * @return int
     */
    public function getWaitingTime()
    {
        return $this->container['waiting_time'];
    }

    /**
     * Sets waiting_time
     *
     * @param int $waiting_time Overall waiting time in seconds.
     *
     * @return $this
     */
    public function setWaitingTime($waiting_time)
    {
        $this->container['waiting_time'] = $waiting_time;

        return $this;
    }

    /**
     * Gets service_duration
     *
     * @return int
     */
    public function getServiceDuration()
    {
        return $this->container['service_duration'];
    }

    /**
     * Sets service_duration
     *
     * @param int $service_duration Overall service time in seconds.
     *
     * @return $this
     */
    public function setServiceDuration($service_duration)
    {
        $this->container['service_duration'] = $service_duration;

        return $this;
    }

    /**
     * Gets preparation_time
     *
     * @return int
     */
    public function getPreparationTime()
    {
        return $this->container['preparation_time'];
    }

    /**
     * Sets preparation_time
     *
     * @param int $preparation_time Overall preparation time in seconds.
     *
     * @return $this
     */
    public function setPreparationTime($preparation_time)
    {
        $this->container['preparation_time'] = $preparation_time;

        return $this;
    }

    /**
     * Gets completion_time
     *
     * @return int
     */
    public function getCompletionTime()
    {
        return $this->container['completion_time'];
    }

    /**
     * Sets completion_time
     *
     * @param int $completion_time Overall completion time in seconds, i.e. the sum of each routes/drivers operation time.
     *
     * @return $this
     */
    public function setCompletionTime($completion_time)
    {
        $this->container['completion_time'] = $completion_time;

        return $this;
    }

    /**
     * Gets no_vehicles
     *
     * @return int
     */
    public function getNoVehicles()
    {
        return $this->container['no_vehicles'];
    }

    /**
     * Sets no_vehicles
     *
     * @param int $no_vehicles Number of employed vehicles.
     *
     * @return $this
     */
    public function setNoVehicles($no_vehicles)
    {
        $this->container['no_vehicles'] = $no_vehicles;

        return $this;
    }

    /**
     * Gets no_unassigned
     *
     * @return int
     */
    public function getNoUnassigned()
    {
        return $this->container['no_unassigned'];
    }

    /**
     * Sets no_unassigned
     *
     * @param int $no_unassigned Number of jobs that could not be assigned to final solution.
     *
     * @return $this
     */
    public function setNoUnassigned($no_unassigned)
    {
        $this->container['no_unassigned'] = $no_unassigned;

        return $this;
    }

    /**
     * Gets routes
     *
     * @return \Swagger\Client\Model\Route[]
     */
    public function getRoutes()
    {
        return $this->container['routes'];
    }

    /**
     * Sets routes
     *
     * @param \Swagger\Client\Model\Route[] $routes An array of routes
     *
     * @return $this
     */
    public function setRoutes($routes)
    {
        $this->container['routes'] = $routes;

        return $this;
    }

    /**
     * Gets unassigned
     *
     * @return \Swagger\Client\Model\SolutionUnassigned
     */
    public function getUnassigned()
    {
        return $this->container['unassigned'];
    }

    /**
     * Sets unassigned
     *
     * @param \Swagger\Client\Model\SolutionUnassigned $unassigned unassigned
     *
     * @return $this
     */
    public function setUnassigned($unassigned)
    {
        $this->container['unassigned'] = $unassigned;

        return $this;
    }
    /**
     * Returns true if offset exists. False otherwise.
     *
     * @param integer $offset Offset
     *
     * @return boolean
     */
    public function offsetExists($offset)
    {
        return isset($this->container[$offset]);
    }

    /**
     * Gets offset.
     *
     * @param integer $offset Offset
     *
     * @return mixed
     */
    public function offsetGet($offset)
    {
        return isset($this->container[$offset]) ? $this->container[$offset] : null;
    }

    /**
     * Sets value based on offset.
     *
     * @param integer $offset Offset
     * @param mixed   $value  Value to be set
     *
     * @return void
     */
    public function offsetSet($offset, $value)
    {
        if (is_null($offset)) {
            $this->container[] = $value;
        } else {
            $this->container[$offset] = $value;
        }
    }

    /**
     * Unsets offset.
     *
     * @param integer $offset Offset
     *
     * @return void
     */
    public function offsetUnset($offset)
    {
        unset($this->container[$offset]);
    }

    /**
     * Gets the string presentation of the object
     *
     * @return string
     */
    public function __toString()
    {
        if (defined('JSON_PRETTY_PRINT')) { // use JSON pretty print
            return json_encode(
                ObjectSerializer::sanitizeForSerialization($this),
                JSON_PRETTY_PRINT
            );
        }

        return json_encode(ObjectSerializer::sanitizeForSerialization($this));
    }
}
