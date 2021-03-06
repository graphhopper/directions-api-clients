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
from swagger_client.models.stop import Stop  # noqa: F401,E501


class Shipment(object):
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
        'id': 'str',
        'name': 'str',
        'priority': 'int',
        'pickup': 'Stop',
        'delivery': 'Stop',
        'size': 'list[int]',
        'required_skills': 'list[str]',
        'allowed_vehicles': 'list[str]',
        'disallowed_vehicles': 'list[str]',
        'max_time_in_vehicle': 'int'
    }

    attribute_map = {
        'id': 'id',
        'name': 'name',
        'priority': 'priority',
        'pickup': 'pickup',
        'delivery': 'delivery',
        'size': 'size',
        'required_skills': 'required_skills',
        'allowed_vehicles': 'allowed_vehicles',
        'disallowed_vehicles': 'disallowed_vehicles',
        'max_time_in_vehicle': 'max_time_in_vehicle'
    }

    def __init__(self, id=None, name=None, priority=2, pickup=None, delivery=None, size=None, required_skills=None, allowed_vehicles=None, disallowed_vehicles=None, max_time_in_vehicle=None):  # noqa: E501
        """Shipment - a model defined in Swagger"""  # noqa: E501
        self._id = None
        self._name = None
        self._priority = None
        self._pickup = None
        self._delivery = None
        self._size = None
        self._required_skills = None
        self._allowed_vehicles = None
        self._disallowed_vehicles = None
        self._max_time_in_vehicle = None
        self.discriminator = None
        self.id = id
        if name is not None:
            self.name = name
        if priority is not None:
            self.priority = priority
        self.pickup = pickup
        self.delivery = delivery
        if size is not None:
            self.size = size
        if required_skills is not None:
            self.required_skills = required_skills
        if allowed_vehicles is not None:
            self.allowed_vehicles = allowed_vehicles
        if disallowed_vehicles is not None:
            self.disallowed_vehicles = disallowed_vehicles
        if max_time_in_vehicle is not None:
            self.max_time_in_vehicle = max_time_in_vehicle

    @property
    def id(self):
        """Gets the id of this Shipment.  # noqa: E501

        Specifies the id of the shipment. Ids need to be unique so there must not be two services/shipments with the same id.  # noqa: E501

        :return: The id of this Shipment.  # noqa: E501
        :rtype: str
        """
        return self._id

    @id.setter
    def id(self, id):
        """Sets the id of this Shipment.

        Specifies the id of the shipment. Ids need to be unique so there must not be two services/shipments with the same id.  # noqa: E501

        :param id: The id of this Shipment.  # noqa: E501
        :type: str
        """
        if id is None:
            raise ValueError("Invalid value for `id`, must not be `None`")  # noqa: E501

        self._id = id

    @property
    def name(self):
        """Gets the name of this Shipment.  # noqa: E501

        Meaningful name for shipment, e.g. \"pickup and deliver pizza to Peter\".  # noqa: E501

        :return: The name of this Shipment.  # noqa: E501
        :rtype: str
        """
        return self._name

    @name.setter
    def name(self, name):
        """Sets the name of this Shipment.

        Meaningful name for shipment, e.g. \"pickup and deliver pizza to Peter\".  # noqa: E501

        :param name: The name of this Shipment.  # noqa: E501
        :type: str
        """

        self._name = name

    @property
    def priority(self):
        """Gets the priority of this Shipment.  # noqa: E501

        Specifies the priority. Can be 1 = high priority to 10 = low priority. Often there are more services/shipments than the available vehicle fleet can handle. Then you could assign priorities to differentiate high priority tasks from those that can be served later or omitted at all.  # noqa: E501

        :return: The priority of this Shipment.  # noqa: E501
        :rtype: int
        """
        return self._priority

    @priority.setter
    def priority(self, priority):
        """Sets the priority of this Shipment.

        Specifies the priority. Can be 1 = high priority to 10 = low priority. Often there are more services/shipments than the available vehicle fleet can handle. Then you could assign priorities to differentiate high priority tasks from those that can be served later or omitted at all.  # noqa: E501

        :param priority: The priority of this Shipment.  # noqa: E501
        :type: int
        """

        self._priority = priority

    @property
    def pickup(self):
        """Gets the pickup of this Shipment.  # noqa: E501


        :return: The pickup of this Shipment.  # noqa: E501
        :rtype: Stop
        """
        return self._pickup

    @pickup.setter
    def pickup(self, pickup):
        """Sets the pickup of this Shipment.


        :param pickup: The pickup of this Shipment.  # noqa: E501
        :type: Stop
        """
        if pickup is None:
            raise ValueError("Invalid value for `pickup`, must not be `None`")  # noqa: E501

        self._pickup = pickup

    @property
    def delivery(self):
        """Gets the delivery of this Shipment.  # noqa: E501


        :return: The delivery of this Shipment.  # noqa: E501
        :rtype: Stop
        """
        return self._delivery

    @delivery.setter
    def delivery(self, delivery):
        """Sets the delivery of this Shipment.


        :param delivery: The delivery of this Shipment.  # noqa: E501
        :type: Stop
        """
        if delivery is None:
            raise ValueError("Invalid value for `delivery`, must not be `None`")  # noqa: E501

        self._delivery = delivery

    @property
    def size(self):
        """Gets the size of this Shipment.  # noqa: E501

        Size can have multiple dimensions and should be in line with the capacity dimension array of the vehicle type. For example, if the item that needs to be delivered has two size dimension, volume and weight, then specify it as follow [ 20, 5 ] assuming a volume of 20 and a weight of 5.  # noqa: E501

        :return: The size of this Shipment.  # noqa: E501
        :rtype: list[int]
        """
        return self._size

    @size.setter
    def size(self, size):
        """Sets the size of this Shipment.

        Size can have multiple dimensions and should be in line with the capacity dimension array of the vehicle type. For example, if the item that needs to be delivered has two size dimension, volume and weight, then specify it as follow [ 20, 5 ] assuming a volume of 20 and a weight of 5.  # noqa: E501

        :param size: The size of this Shipment.  # noqa: E501
        :type: list[int]
        """

        self._size = size

    @property
    def required_skills(self):
        """Gets the required_skills of this Shipment.  # noqa: E501

        Specifies an array of required skills, i.e. array of string (not case sensitive). For example, if this shipment needs to be conducted by a technician having a `drilling_machine` and a `screw_driver` then specify the array as follows: `[\"drilling_machine\",\"screw_driver\"]`. This means that the service can only be done by a vehicle (technician) that has the skills `drilling_machine` AND `screw_driver` in its skill array. Otherwise it remains unassigned.  # noqa: E501

        :return: The required_skills of this Shipment.  # noqa: E501
        :rtype: list[str]
        """
        return self._required_skills

    @required_skills.setter
    def required_skills(self, required_skills):
        """Sets the required_skills of this Shipment.

        Specifies an array of required skills, i.e. array of string (not case sensitive). For example, if this shipment needs to be conducted by a technician having a `drilling_machine` and a `screw_driver` then specify the array as follows: `[\"drilling_machine\",\"screw_driver\"]`. This means that the service can only be done by a vehicle (technician) that has the skills `drilling_machine` AND `screw_driver` in its skill array. Otherwise it remains unassigned.  # noqa: E501

        :param required_skills: The required_skills of this Shipment.  # noqa: E501
        :type: list[str]
        """

        self._required_skills = required_skills

    @property
    def allowed_vehicles(self):
        """Gets the allowed_vehicles of this Shipment.  # noqa: E501

        Specifies an array of allowed vehicles, i.e. array of vehicle ids. For example, if this shipment can only be conducted EITHER by \"technician_peter\" OR \"technician_stefan\" specify this as follows: [\"technician_peter\",\"technician_stefan\"].  # noqa: E501

        :return: The allowed_vehicles of this Shipment.  # noqa: E501
        :rtype: list[str]
        """
        return self._allowed_vehicles

    @allowed_vehicles.setter
    def allowed_vehicles(self, allowed_vehicles):
        """Sets the allowed_vehicles of this Shipment.

        Specifies an array of allowed vehicles, i.e. array of vehicle ids. For example, if this shipment can only be conducted EITHER by \"technician_peter\" OR \"technician_stefan\" specify this as follows: [\"technician_peter\",\"technician_stefan\"].  # noqa: E501

        :param allowed_vehicles: The allowed_vehicles of this Shipment.  # noqa: E501
        :type: list[str]
        """

        self._allowed_vehicles = allowed_vehicles

    @property
    def disallowed_vehicles(self):
        """Gets the disallowed_vehicles of this Shipment.  # noqa: E501

        Specifies an array of disallowed vehicles, i.e. array of vehicle ids.  # noqa: E501

        :return: The disallowed_vehicles of this Shipment.  # noqa: E501
        :rtype: list[str]
        """
        return self._disallowed_vehicles

    @disallowed_vehicles.setter
    def disallowed_vehicles(self, disallowed_vehicles):
        """Sets the disallowed_vehicles of this Shipment.

        Specifies an array of disallowed vehicles, i.e. array of vehicle ids.  # noqa: E501

        :param disallowed_vehicles: The disallowed_vehicles of this Shipment.  # noqa: E501
        :type: list[str]
        """

        self._disallowed_vehicles = disallowed_vehicles

    @property
    def max_time_in_vehicle(self):
        """Gets the max_time_in_vehicle of this Shipment.  # noqa: E501

        Specifies the maximum time in seconds a shipment can stay in the vehicle.  # noqa: E501

        :return: The max_time_in_vehicle of this Shipment.  # noqa: E501
        :rtype: int
        """
        return self._max_time_in_vehicle

    @max_time_in_vehicle.setter
    def max_time_in_vehicle(self, max_time_in_vehicle):
        """Sets the max_time_in_vehicle of this Shipment.

        Specifies the maximum time in seconds a shipment can stay in the vehicle.  # noqa: E501

        :param max_time_in_vehicle: The max_time_in_vehicle of this Shipment.  # noqa: E501
        :type: int
        """

        self._max_time_in_vehicle = max_time_in_vehicle

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
        if issubclass(Shipment, dict):
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
        if not isinstance(other, Shipment):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
