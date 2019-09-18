<?php
/**
 * VehicleType
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
 * With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Client Libraries  To speed up development and make coding easier, we offer the following client libraries:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions are considered only with `ch.disable=true`.**  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png)
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
 * VehicleType Class Doc Comment
 *
 * @category Class
 * @package  Swagger\Client
 * @author   Swagger Codegen team
 * @link     https://github.com/swagger-api/swagger-codegen
 */
class VehicleType implements ModelInterface, ArrayAccess
{
    const DISCRIMINATOR = null;

    /**
      * The original name of the model.
      *
      * @var string
      */
    protected static $swaggerModelName = 'VehicleType';

    /**
      * Array of property to type mappings. Used for (de)serialization
      *
      * @var string[]
      */
    protected static $swaggerTypes = [
        'type_id' => 'string',
'profile' => '',
'capacity' => 'int[]',
'speed_factor' => 'double',
'service_time_factor' => 'double',
'cost_per_meter' => 'double',
'cost_per_second' => 'double',
'cost_per_activation' => 'double',
'consider_traffic' => 'bool',
'network_data_provider' => 'string'    ];

    /**
      * Array of property to format mappings. Used for (de)serialization
      *
      * @var string[]
      */
    protected static $swaggerFormats = [
        'type_id' => null,
'profile' => null,
'capacity' => 'int32',
'speed_factor' => 'double',
'service_time_factor' => 'double',
'cost_per_meter' => 'double',
'cost_per_second' => 'double',
'cost_per_activation' => 'double',
'consider_traffic' => null,
'network_data_provider' => null    ];

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
        'type_id' => 'type_id',
'profile' => 'profile',
'capacity' => 'capacity',
'speed_factor' => 'speed_factor',
'service_time_factor' => 'service_time_factor',
'cost_per_meter' => 'cost_per_meter',
'cost_per_second' => 'cost_per_second',
'cost_per_activation' => 'cost_per_activation',
'consider_traffic' => 'consider_traffic',
'network_data_provider' => 'network_data_provider'    ];

    /**
     * Array of attributes to setter functions (for deserialization of responses)
     *
     * @var string[]
     */
    protected static $setters = [
        'type_id' => 'setTypeId',
'profile' => 'setProfile',
'capacity' => 'setCapacity',
'speed_factor' => 'setSpeedFactor',
'service_time_factor' => 'setServiceTimeFactor',
'cost_per_meter' => 'setCostPerMeter',
'cost_per_second' => 'setCostPerSecond',
'cost_per_activation' => 'setCostPerActivation',
'consider_traffic' => 'setConsiderTraffic',
'network_data_provider' => 'setNetworkDataProvider'    ];

    /**
     * Array of attributes to getter functions (for serialization of requests)
     *
     * @var string[]
     */
    protected static $getters = [
        'type_id' => 'getTypeId',
'profile' => 'getProfile',
'capacity' => 'getCapacity',
'speed_factor' => 'getSpeedFactor',
'service_time_factor' => 'getServiceTimeFactor',
'cost_per_meter' => 'getCostPerMeter',
'cost_per_second' => 'getCostPerSecond',
'cost_per_activation' => 'getCostPerActivation',
'consider_traffic' => 'getConsiderTraffic',
'network_data_provider' => 'getNetworkDataProvider'    ];

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

    const NETWORK_DATA_PROVIDER_OPENSTREETMAP = 'openstreetmap';
const NETWORK_DATA_PROVIDER_TOMTOM = 'tomtom';

    /**
     * Gets allowable values of the enum
     *
     * @return string[]
     */
    public function getNetworkDataProviderAllowableValues()
    {
        return [
            self::NETWORK_DATA_PROVIDER_OPENSTREETMAP,
self::NETWORK_DATA_PROVIDER_TOMTOM,        ];
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
        $this->container['type_id'] = isset($data['type_id']) ? $data['type_id'] : null;
        $this->container['profile'] = isset($data['profile']) ? $data['profile'] : null;
        $this->container['capacity'] = isset($data['capacity']) ? $data['capacity'] : null;
        $this->container['speed_factor'] = isset($data['speed_factor']) ? $data['speed_factor'] : 1;
        $this->container['service_time_factor'] = isset($data['service_time_factor']) ? $data['service_time_factor'] : 1;
        $this->container['cost_per_meter'] = isset($data['cost_per_meter']) ? $data['cost_per_meter'] : null;
        $this->container['cost_per_second'] = isset($data['cost_per_second']) ? $data['cost_per_second'] : null;
        $this->container['cost_per_activation'] = isset($data['cost_per_activation']) ? $data['cost_per_activation'] : null;
        $this->container['consider_traffic'] = isset($data['consider_traffic']) ? $data['consider_traffic'] : false;
        $this->container['network_data_provider'] = isset($data['network_data_provider']) ? $data['network_data_provider'] : 'openstreetmap';
    }

    /**
     * Show all the invalid properties with reasons.
     *
     * @return array invalid properties with reasons
     */
    public function listInvalidProperties()
    {
        $invalidProperties = [];

        if ($this->container['type_id'] === null) {
            $invalidProperties[] = "'type_id' can't be null";
        }
        $allowedValues = $this->getNetworkDataProviderAllowableValues();
        if (!is_null($this->container['network_data_provider']) && !in_array($this->container['network_data_provider'], $allowedValues, true)) {
            $invalidProperties[] = sprintf(
                "invalid value for 'network_data_provider', must be one of '%s'",
                implode("', '", $allowedValues)
            );
        }

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
     * Gets type_id
     *
     * @return string
     */
    public function getTypeId()
    {
        return $this->container['type_id'];
    }

    /**
     * Sets type_id
     *
     * @param string $type_id Specifies the id of the vehicle type. If a vehicle needs to be of this type, it should refer to this with its type_id attribute.
     *
     * @return $this
     */
    public function setTypeId($type_id)
    {
        $this->container['type_id'] = $type_id;

        return $this;
    }

    /**
     * Gets profile
     *
     * @return 
     */
    public function getProfile()
    {
        return $this->container['profile'];
    }

    /**
     * Sets profile
     *
     * @param  $profile profile
     *
     * @return $this
     */
    public function setProfile($profile)
    {
        $this->container['profile'] = $profile;

        return $this;
    }

    /**
     * Gets capacity
     *
     * @return int[]
     */
    public function getCapacity()
    {
        return $this->container['capacity'];
    }

    /**
     * Sets capacity
     *
     * @param int[] $capacity Specifies an array of capacity dimension values which need to be int values. For example, if there are two dimensions such as volume and weight then it needs to be defined as [ 1000, 300 ] assuming a maximum volume of 1000 and a maximum weight of 300.
     *
     * @return $this
     */
    public function setCapacity($capacity)
    {
        $this->container['capacity'] = $capacity;

        return $this;
    }

    /**
     * Gets speed_factor
     *
     * @return double
     */
    public function getSpeedFactor()
    {
        return $this->container['speed_factor'];
    }

    /**
     * Sets speed_factor
     *
     * @param double $speed_factor Specifies a speed factor for this vehicle type. If the vehicle that uses this type needs to be only half as fast as what is actually calculated with our routing engine then set the speed factor to 0.5.
     *
     * @return $this
     */
    public function setSpeedFactor($speed_factor)
    {
        $this->container['speed_factor'] = $speed_factor;

        return $this;
    }

    /**
     * Gets service_time_factor
     *
     * @return double
     */
    public function getServiceTimeFactor()
    {
        return $this->container['service_time_factor'];
    }

    /**
     * Sets service_time_factor
     *
     * @param double $service_time_factor Specifies a service time factor for this vehicle type. If the vehicle/driver that uses this type is able to conduct the service as double as fast as it is determined in the corresponding service or shipment then set it to 0.5.
     *
     * @return $this
     */
    public function setServiceTimeFactor($service_time_factor)
    {
        $this->container['service_time_factor'] = $service_time_factor;

        return $this;
    }

    /**
     * Gets cost_per_meter
     *
     * @return double
     */
    public function getCostPerMeter()
    {
        return $this->container['cost_per_meter'];
    }

    /**
     * Sets cost_per_meter
     *
     * @param double $cost_per_meter **_BETA feature_**! Cost parameter per distance unit, here meter is used
     *
     * @return $this
     */
    public function setCostPerMeter($cost_per_meter)
    {
        $this->container['cost_per_meter'] = $cost_per_meter;

        return $this;
    }

    /**
     * Gets cost_per_second
     *
     * @return double
     */
    public function getCostPerSecond()
    {
        return $this->container['cost_per_second'];
    }

    /**
     * Sets cost_per_second
     *
     * @param double $cost_per_second **_BETA feature_**! Cost parameter per time unit, here second is used
     *
     * @return $this
     */
    public function setCostPerSecond($cost_per_second)
    {
        $this->container['cost_per_second'] = $cost_per_second;

        return $this;
    }

    /**
     * Gets cost_per_activation
     *
     * @return double
     */
    public function getCostPerActivation()
    {
        return $this->container['cost_per_activation'];
    }

    /**
     * Sets cost_per_activation
     *
     * @param double $cost_per_activation **_BETA feature_**! Cost parameter vehicle activation, i.e. fixed costs per vehicle
     *
     * @return $this
     */
    public function setCostPerActivation($cost_per_activation)
    {
        $this->container['cost_per_activation'] = $cost_per_activation;

        return $this;
    }

    /**
     * Gets consider_traffic
     *
     * @return bool
     */
    public function getConsiderTraffic()
    {
        return $this->container['consider_traffic'];
    }

    /**
     * Sets consider_traffic
     *
     * @param bool $consider_traffic Specifies whether traffic should be considered. if \"tomtom\" is used and this is false, free flow travel times from \"tomtom\" are calculated. If this is true, historical traffic info are used. We do not yet have traffic data for \"openstreetmap\", thus, setting this true has no effect at all.
     *
     * @return $this
     */
    public function setConsiderTraffic($consider_traffic)
    {
        $this->container['consider_traffic'] = $consider_traffic;

        return $this;
    }

    /**
     * Gets network_data_provider
     *
     * @return string
     */
    public function getNetworkDataProvider()
    {
        return $this->container['network_data_provider'];
    }

    /**
     * Sets network_data_provider
     *
     * @param string $network_data_provider Specifies the network data provider. Either use [`openstreetmap`](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [`tomtom`](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).
     *
     * @return $this
     */
    public function setNetworkDataProvider($network_data_provider)
    {
        $allowedValues = $this->getNetworkDataProviderAllowableValues();
        if (!is_null($network_data_provider) && !in_array($network_data_provider, $allowedValues, true)) {
            throw new \InvalidArgumentException(
                sprintf(
                    "Invalid value for 'network_data_provider', must be one of '%s'",
                    implode("', '", $allowedValues)
                )
            );
        }
        $this->container['network_data_provider'] = $network_data_provider;

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
