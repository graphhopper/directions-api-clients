# coding: utf-8

"""
    GraphHopper Directions API

     With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Client Libraries  To speed up development and make coding easier, we offer the following client libraries:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions are considered only with `ch.disable=true`.**  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png)   # noqa: E501

    OpenAPI spec version: 1.0.0
    Contact: support@graphhopper.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""

import pprint
import re  # noqa: F401

import six
from swagger_client.models.object import Object  # noqa: F401,E501


class VehicleType(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """
    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'type_id': 'str',
        'profile': 'Object',
        'capacity': 'list[int]',
        'speed_factor': 'float',
        'service_time_factor': 'float',
        'cost_per_meter': 'float',
        'cost_per_second': 'float',
        'cost_per_activation': 'float',
        'consider_traffic': 'bool',
        'network_data_provider': 'str'
    }

    attribute_map = {
        'type_id': 'type_id',
        'profile': 'profile',
        'capacity': 'capacity',
        'speed_factor': 'speed_factor',
        'service_time_factor': 'service_time_factor',
        'cost_per_meter': 'cost_per_meter',
        'cost_per_second': 'cost_per_second',
        'cost_per_activation': 'cost_per_activation',
        'consider_traffic': 'consider_traffic',
        'network_data_provider': 'network_data_provider'
    }

    def __init__(self, type_id=None, profile=None, capacity=None, speed_factor=1, service_time_factor=1, cost_per_meter=None, cost_per_second=None, cost_per_activation=None, consider_traffic=False, network_data_provider='openstreetmap'):  # noqa: E501
        """VehicleType - a model defined in Swagger"""  # noqa: E501
        self._type_id = None
        self._profile = None
        self._capacity = None
        self._speed_factor = None
        self._service_time_factor = None
        self._cost_per_meter = None
        self._cost_per_second = None
        self._cost_per_activation = None
        self._consider_traffic = None
        self._network_data_provider = None
        self.discriminator = None
        self.type_id = type_id
        if profile is not None:
            self.profile = profile
        if capacity is not None:
            self.capacity = capacity
        if speed_factor is not None:
            self.speed_factor = speed_factor
        if service_time_factor is not None:
            self.service_time_factor = service_time_factor
        if cost_per_meter is not None:
            self.cost_per_meter = cost_per_meter
        if cost_per_second is not None:
            self.cost_per_second = cost_per_second
        if cost_per_activation is not None:
            self.cost_per_activation = cost_per_activation
        if consider_traffic is not None:
            self.consider_traffic = consider_traffic
        if network_data_provider is not None:
            self.network_data_provider = network_data_provider

    @property
    def type_id(self):
        """Gets the type_id of this VehicleType.  # noqa: E501

        Specifies the id of the vehicle type. If a vehicle needs to be of this type, it should refer to this with its type_id attribute.  # noqa: E501

        :return: The type_id of this VehicleType.  # noqa: E501
        :rtype: str
        """
        return self._type_id

    @type_id.setter
    def type_id(self, type_id):
        """Sets the type_id of this VehicleType.

        Specifies the id of the vehicle type. If a vehicle needs to be of this type, it should refer to this with its type_id attribute.  # noqa: E501

        :param type_id: The type_id of this VehicleType.  # noqa: E501
        :type: str
        """
        if type_id is None:
            raise ValueError("Invalid value for `type_id`, must not be `None`")  # noqa: E501

        self._type_id = type_id

    @property
    def profile(self):
        """Gets the profile of this VehicleType.  # noqa: E501


        :return: The profile of this VehicleType.  # noqa: E501
        :rtype: Object
        """
        return self._profile

    @profile.setter
    def profile(self, profile):
        """Sets the profile of this VehicleType.


        :param profile: The profile of this VehicleType.  # noqa: E501
        :type: Object
        """

        self._profile = profile

    @property
    def capacity(self):
        """Gets the capacity of this VehicleType.  # noqa: E501

        Specifies an array of capacity dimension values which need to be int values. For example, if there are two dimensions such as volume and weight then it needs to be defined as [ 1000, 300 ] assuming a maximum volume of 1000 and a maximum weight of 300.  # noqa: E501

        :return: The capacity of this VehicleType.  # noqa: E501
        :rtype: list[int]
        """
        return self._capacity

    @capacity.setter
    def capacity(self, capacity):
        """Sets the capacity of this VehicleType.

        Specifies an array of capacity dimension values which need to be int values. For example, if there are two dimensions such as volume and weight then it needs to be defined as [ 1000, 300 ] assuming a maximum volume of 1000 and a maximum weight of 300.  # noqa: E501

        :param capacity: The capacity of this VehicleType.  # noqa: E501
        :type: list[int]
        """

        self._capacity = capacity

    @property
    def speed_factor(self):
        """Gets the speed_factor of this VehicleType.  # noqa: E501

        Specifies a speed factor for this vehicle type. If the vehicle that uses this type needs to be only half as fast as what is actually calculated with our routing engine then set the speed factor to 0.5.  # noqa: E501

        :return: The speed_factor of this VehicleType.  # noqa: E501
        :rtype: float
        """
        return self._speed_factor

    @speed_factor.setter
    def speed_factor(self, speed_factor):
        """Sets the speed_factor of this VehicleType.

        Specifies a speed factor for this vehicle type. If the vehicle that uses this type needs to be only half as fast as what is actually calculated with our routing engine then set the speed factor to 0.5.  # noqa: E501

        :param speed_factor: The speed_factor of this VehicleType.  # noqa: E501
        :type: float
        """

        self._speed_factor = speed_factor

    @property
    def service_time_factor(self):
        """Gets the service_time_factor of this VehicleType.  # noqa: E501

        Specifies a service time factor for this vehicle type. If the vehicle/driver that uses this type is able to conduct the service as double as fast as it is determined in the corresponding service or shipment then set it to 0.5.  # noqa: E501

        :return: The service_time_factor of this VehicleType.  # noqa: E501
        :rtype: float
        """
        return self._service_time_factor

    @service_time_factor.setter
    def service_time_factor(self, service_time_factor):
        """Sets the service_time_factor of this VehicleType.

        Specifies a service time factor for this vehicle type. If the vehicle/driver that uses this type is able to conduct the service as double as fast as it is determined in the corresponding service or shipment then set it to 0.5.  # noqa: E501

        :param service_time_factor: The service_time_factor of this VehicleType.  # noqa: E501
        :type: float
        """

        self._service_time_factor = service_time_factor

    @property
    def cost_per_meter(self):
        """Gets the cost_per_meter of this VehicleType.  # noqa: E501

        **_BETA feature_**! Cost parameter per distance unit, here meter is used  # noqa: E501

        :return: The cost_per_meter of this VehicleType.  # noqa: E501
        :rtype: float
        """
        return self._cost_per_meter

    @cost_per_meter.setter
    def cost_per_meter(self, cost_per_meter):
        """Sets the cost_per_meter of this VehicleType.

        **_BETA feature_**! Cost parameter per distance unit, here meter is used  # noqa: E501

        :param cost_per_meter: The cost_per_meter of this VehicleType.  # noqa: E501
        :type: float
        """

        self._cost_per_meter = cost_per_meter

    @property
    def cost_per_second(self):
        """Gets the cost_per_second of this VehicleType.  # noqa: E501

        **_BETA feature_**! Cost parameter per time unit, here second is used  # noqa: E501

        :return: The cost_per_second of this VehicleType.  # noqa: E501
        :rtype: float
        """
        return self._cost_per_second

    @cost_per_second.setter
    def cost_per_second(self, cost_per_second):
        """Sets the cost_per_second of this VehicleType.

        **_BETA feature_**! Cost parameter per time unit, here second is used  # noqa: E501

        :param cost_per_second: The cost_per_second of this VehicleType.  # noqa: E501
        :type: float
        """

        self._cost_per_second = cost_per_second

    @property
    def cost_per_activation(self):
        """Gets the cost_per_activation of this VehicleType.  # noqa: E501

        **_BETA feature_**! Cost parameter vehicle activation, i.e. fixed costs per vehicle  # noqa: E501

        :return: The cost_per_activation of this VehicleType.  # noqa: E501
        :rtype: float
        """
        return self._cost_per_activation

    @cost_per_activation.setter
    def cost_per_activation(self, cost_per_activation):
        """Sets the cost_per_activation of this VehicleType.

        **_BETA feature_**! Cost parameter vehicle activation, i.e. fixed costs per vehicle  # noqa: E501

        :param cost_per_activation: The cost_per_activation of this VehicleType.  # noqa: E501
        :type: float
        """

        self._cost_per_activation = cost_per_activation

    @property
    def consider_traffic(self):
        """Gets the consider_traffic of this VehicleType.  # noqa: E501

        Specifies whether traffic should be considered. if \"tomtom\" is used and this is false, free flow travel times from \"tomtom\" are calculated. If this is true, historical traffic info are used. We do not yet have traffic data for \"openstreetmap\", thus, setting this true has no effect at all.  # noqa: E501

        :return: The consider_traffic of this VehicleType.  # noqa: E501
        :rtype: bool
        """
        return self._consider_traffic

    @consider_traffic.setter
    def consider_traffic(self, consider_traffic):
        """Sets the consider_traffic of this VehicleType.

        Specifies whether traffic should be considered. if \"tomtom\" is used and this is false, free flow travel times from \"tomtom\" are calculated. If this is true, historical traffic info are used. We do not yet have traffic data for \"openstreetmap\", thus, setting this true has no effect at all.  # noqa: E501

        :param consider_traffic: The consider_traffic of this VehicleType.  # noqa: E501
        :type: bool
        """

        self._consider_traffic = consider_traffic

    @property
    def network_data_provider(self):
        """Gets the network_data_provider of this VehicleType.  # noqa: E501

        Specifies the network data provider. Either use [`openstreetmap`](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [`tomtom`](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).  # noqa: E501

        :return: The network_data_provider of this VehicleType.  # noqa: E501
        :rtype: str
        """
        return self._network_data_provider

    @network_data_provider.setter
    def network_data_provider(self, network_data_provider):
        """Sets the network_data_provider of this VehicleType.

        Specifies the network data provider. Either use [`openstreetmap`](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [`tomtom`](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required).  # noqa: E501

        :param network_data_provider: The network_data_provider of this VehicleType.  # noqa: E501
        :type: str
        """
        allowed_values = ["openstreetmap", "tomtom"]  # noqa: E501
        if network_data_provider not in allowed_values:
            raise ValueError(
                "Invalid value for `network_data_provider` ({0}), must be one of {1}"  # noqa: E501
                .format(network_data_provider, allowed_values)
            )

        self._network_data_provider = network_data_provider

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(VehicleType, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, VehicleType):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
