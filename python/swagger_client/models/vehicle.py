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
from swagger_client.models.address import Address  # noqa: F401,E501
from swagger_client.models.any_of_vehicle_break import AnyOfVehicleBreak  # noqa: F401,E501


class Vehicle(object):
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
        'vehicle_id': 'str',
        'type_id': 'str',
        'start_address': 'Address',
        'end_address': 'Address',
        '_break': 'AnyOfVehicleBreak',
        'return_to_depot': 'bool',
        'earliest_start': 'int',
        'latest_end': 'int',
        'skills': 'list[str]',
        'max_distance': 'int',
        'max_driving_time': 'int',
        'max_jobs': 'int',
        'max_activities': 'int',
        'move_to_end_address': 'bool'
    }

    attribute_map = {
        'vehicle_id': 'vehicle_id',
        'type_id': 'type_id',
        'start_address': 'start_address',
        'end_address': 'end_address',
        '_break': 'break',
        'return_to_depot': 'return_to_depot',
        'earliest_start': 'earliest_start',
        'latest_end': 'latest_end',
        'skills': 'skills',
        'max_distance': 'max_distance',
        'max_driving_time': 'max_driving_time',
        'max_jobs': 'max_jobs',
        'max_activities': 'max_activities',
        'move_to_end_address': 'move_to_end_address'
    }

    def __init__(self, vehicle_id=None, type_id='default-type', start_address=None, end_address=None, _break=None, return_to_depot=True, earliest_start=0, latest_end=None, skills=None, max_distance=None, max_driving_time=None, max_jobs=None, max_activities=None, move_to_end_address=None):  # noqa: E501
        """Vehicle - a model defined in Swagger"""  # noqa: E501
        self._vehicle_id = None
        self._type_id = None
        self._start_address = None
        self._end_address = None
        self.__break = None
        self._return_to_depot = None
        self._earliest_start = None
        self._latest_end = None
        self._skills = None
        self._max_distance = None
        self._max_driving_time = None
        self._max_jobs = None
        self._max_activities = None
        self._move_to_end_address = None
        self.discriminator = None
        self.vehicle_id = vehicle_id
        if type_id is not None:
            self.type_id = type_id
        self.start_address = start_address
        if end_address is not None:
            self.end_address = end_address
        if _break is not None:
            self._break = _break
        if return_to_depot is not None:
            self.return_to_depot = return_to_depot
        if earliest_start is not None:
            self.earliest_start = earliest_start
        if latest_end is not None:
            self.latest_end = latest_end
        if skills is not None:
            self.skills = skills
        if max_distance is not None:
            self.max_distance = max_distance
        if max_driving_time is not None:
            self.max_driving_time = max_driving_time
        if max_jobs is not None:
            self.max_jobs = max_jobs
        if max_activities is not None:
            self.max_activities = max_activities
        if move_to_end_address is not None:
            self.move_to_end_address = move_to_end_address

    @property
    def vehicle_id(self):
        """Gets the vehicle_id of this Vehicle.  # noqa: E501

        Specifies the id of the vehicle. Ids need to be unique, thus if there two vehicles with the same id, an exception is thrown.  # noqa: E501

        :return: The vehicle_id of this Vehicle.  # noqa: E501
        :rtype: str
        """
        return self._vehicle_id

    @vehicle_id.setter
    def vehicle_id(self, vehicle_id):
        """Sets the vehicle_id of this Vehicle.

        Specifies the id of the vehicle. Ids need to be unique, thus if there two vehicles with the same id, an exception is thrown.  # noqa: E501

        :param vehicle_id: The vehicle_id of this Vehicle.  # noqa: E501
        :type: str
        """
        if vehicle_id is None:
            raise ValueError("Invalid value for `vehicle_id`, must not be `None`")  # noqa: E501

        self._vehicle_id = vehicle_id

    @property
    def type_id(self):
        """Gets the type_id of this Vehicle.  # noqa: E501

        The type_id refers to specified vehicle type (see vehicle types). If it is omitted a default type will be used.  # noqa: E501

        :return: The type_id of this Vehicle.  # noqa: E501
        :rtype: str
        """
        return self._type_id

    @type_id.setter
    def type_id(self, type_id):
        """Sets the type_id of this Vehicle.

        The type_id refers to specified vehicle type (see vehicle types). If it is omitted a default type will be used.  # noqa: E501

        :param type_id: The type_id of this Vehicle.  # noqa: E501
        :type: str
        """

        self._type_id = type_id

    @property
    def start_address(self):
        """Gets the start_address of this Vehicle.  # noqa: E501


        :return: The start_address of this Vehicle.  # noqa: E501
        :rtype: Address
        """
        return self._start_address

    @start_address.setter
    def start_address(self, start_address):
        """Sets the start_address of this Vehicle.


        :param start_address: The start_address of this Vehicle.  # noqa: E501
        :type: Address
        """
        if start_address is None:
            raise ValueError("Invalid value for `start_address`, must not be `None`")  # noqa: E501

        self._start_address = start_address

    @property
    def end_address(self):
        """Gets the end_address of this Vehicle.  # noqa: E501


        :return: The end_address of this Vehicle.  # noqa: E501
        :rtype: Address
        """
        return self._end_address

    @end_address.setter
    def end_address(self, end_address):
        """Sets the end_address of this Vehicle.


        :param end_address: The end_address of this Vehicle.  # noqa: E501
        :type: Address
        """

        self._end_address = end_address

    @property
    def _break(self):
        """Gets the _break of this Vehicle.  # noqa: E501


        :return: The _break of this Vehicle.  # noqa: E501
        :rtype: AnyOfVehicleBreak
        """
        return self.__break

    @_break.setter
    def _break(self, _break):
        """Sets the _break of this Vehicle.


        :param _break: The _break of this Vehicle.  # noqa: E501
        :type: AnyOfVehicleBreak
        """

        self.__break = _break

    @property
    def return_to_depot(self):
        """Gets the return_to_depot of this Vehicle.  # noqa: E501

        If it is false, the algorithm decides where to end the vehicle route. It ends in one of your customers' locations. The end is chosen such that it contributes to the overall objective function, e.g. min transport_time. If it is true, you can either specify a specific end location (which is then regarded as end depot) or you can leave it and the driver returns to its start location.  # noqa: E501

        :return: The return_to_depot of this Vehicle.  # noqa: E501
        :rtype: bool
        """
        return self._return_to_depot

    @return_to_depot.setter
    def return_to_depot(self, return_to_depot):
        """Sets the return_to_depot of this Vehicle.

        If it is false, the algorithm decides where to end the vehicle route. It ends in one of your customers' locations. The end is chosen such that it contributes to the overall objective function, e.g. min transport_time. If it is true, you can either specify a specific end location (which is then regarded as end depot) or you can leave it and the driver returns to its start location.  # noqa: E501

        :param return_to_depot: The return_to_depot of this Vehicle.  # noqa: E501
        :type: bool
        """

        self._return_to_depot = return_to_depot

    @property
    def earliest_start(self):
        """Gets the earliest_start of this Vehicle.  # noqa: E501

        Earliest start of vehicle in seconds. It is recommended to use the unix timestamp.  # noqa: E501

        :return: The earliest_start of this Vehicle.  # noqa: E501
        :rtype: int
        """
        return self._earliest_start

    @earliest_start.setter
    def earliest_start(self, earliest_start):
        """Sets the earliest_start of this Vehicle.

        Earliest start of vehicle in seconds. It is recommended to use the unix timestamp.  # noqa: E501

        :param earliest_start: The earliest_start of this Vehicle.  # noqa: E501
        :type: int
        """

        self._earliest_start = earliest_start

    @property
    def latest_end(self):
        """Gets the latest_end of this Vehicle.  # noqa: E501

        Latest end of vehicle in seconds, i.e. the time the vehicle needs to be at its end location at latest.  # noqa: E501

        :return: The latest_end of this Vehicle.  # noqa: E501
        :rtype: int
        """
        return self._latest_end

    @latest_end.setter
    def latest_end(self, latest_end):
        """Sets the latest_end of this Vehicle.

        Latest end of vehicle in seconds, i.e. the time the vehicle needs to be at its end location at latest.  # noqa: E501

        :param latest_end: The latest_end of this Vehicle.  # noqa: E501
        :type: int
        """

        self._latest_end = latest_end

    @property
    def skills(self):
        """Gets the skills of this Vehicle.  # noqa: E501

        Array of skills, i.e. array of string (not case sensitive).  # noqa: E501

        :return: The skills of this Vehicle.  # noqa: E501
        :rtype: list[str]
        """
        return self._skills

    @skills.setter
    def skills(self, skills):
        """Sets the skills of this Vehicle.

        Array of skills, i.e. array of string (not case sensitive).  # noqa: E501

        :param skills: The skills of this Vehicle.  # noqa: E501
        :type: list[str]
        """

        self._skills = skills

    @property
    def max_distance(self):
        """Gets the max_distance of this Vehicle.  # noqa: E501

        Specifies the maximum distance a vehicle can go.  # noqa: E501

        :return: The max_distance of this Vehicle.  # noqa: E501
        :rtype: int
        """
        return self._max_distance

    @max_distance.setter
    def max_distance(self, max_distance):
        """Sets the max_distance of this Vehicle.

        Specifies the maximum distance a vehicle can go.  # noqa: E501

        :param max_distance: The max_distance of this Vehicle.  # noqa: E501
        :type: int
        """

        self._max_distance = max_distance

    @property
    def max_driving_time(self):
        """Gets the max_driving_time of this Vehicle.  # noqa: E501

        Specifies the maximum drive time a vehicle/driver can go, i.e. the maximum time on the road (service and waiting times are not included here)  # noqa: E501

        :return: The max_driving_time of this Vehicle.  # noqa: E501
        :rtype: int
        """
        return self._max_driving_time

    @max_driving_time.setter
    def max_driving_time(self, max_driving_time):
        """Sets the max_driving_time of this Vehicle.

        Specifies the maximum drive time a vehicle/driver can go, i.e. the maximum time on the road (service and waiting times are not included here)  # noqa: E501

        :param max_driving_time: The max_driving_time of this Vehicle.  # noqa: E501
        :type: int
        """

        self._max_driving_time = max_driving_time

    @property
    def max_jobs(self):
        """Gets the max_jobs of this Vehicle.  # noqa: E501

        Specifies the maximum number of jobs a vehicle can load.  # noqa: E501

        :return: The max_jobs of this Vehicle.  # noqa: E501
        :rtype: int
        """
        return self._max_jobs

    @max_jobs.setter
    def max_jobs(self, max_jobs):
        """Sets the max_jobs of this Vehicle.

        Specifies the maximum number of jobs a vehicle can load.  # noqa: E501

        :param max_jobs: The max_jobs of this Vehicle.  # noqa: E501
        :type: int
        """

        self._max_jobs = max_jobs

    @property
    def max_activities(self):
        """Gets the max_activities of this Vehicle.  # noqa: E501

        Specifies the maximum number of activities a vehicle can conduct.  # noqa: E501

        :return: The max_activities of this Vehicle.  # noqa: E501
        :rtype: int
        """
        return self._max_activities

    @max_activities.setter
    def max_activities(self, max_activities):
        """Sets the max_activities of this Vehicle.

        Specifies the maximum number of activities a vehicle can conduct.  # noqa: E501

        :param max_activities: The max_activities of this Vehicle.  # noqa: E501
        :type: int
        """

        self._max_activities = max_activities

    @property
    def move_to_end_address(self):
        """Gets the move_to_end_address of this Vehicle.  # noqa: E501

        Indicates whether a vehicle should be moved even though it has not been assigned any jobs.  # noqa: E501

        :return: The move_to_end_address of this Vehicle.  # noqa: E501
        :rtype: bool
        """
        return self._move_to_end_address

    @move_to_end_address.setter
    def move_to_end_address(self, move_to_end_address):
        """Sets the move_to_end_address of this Vehicle.

        Indicates whether a vehicle should be moved even though it has not been assigned any jobs.  # noqa: E501

        :param move_to_end_address: The move_to_end_address of this Vehicle.  # noqa: E501
        :type: bool
        """

        self._move_to_end_address = move_to_end_address

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
        if issubclass(Vehicle, dict):
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
        if not isinstance(other, Vehicle):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
