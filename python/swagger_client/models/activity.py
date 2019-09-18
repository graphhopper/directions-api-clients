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
from swagger_client.models.response_address import ResponseAddress  # noqa: F401,E501


class Activity(object):
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
        'type': 'str',
        'id': 'str',
        'location_id': 'str',
        'address': 'ResponseAddress',
        'arr_time': 'int',
        'end_time': 'int',
        'end_date_time': 'datetime',
        'arr_date_time': 'datetime',
        'waiting_time': 'int',
        'preparation_time': 'int',
        'distance': 'int',
        'driving_time': 'int',
        'load_before': 'list[int]',
        'load_after': 'list[int]'
    }

    attribute_map = {
        'type': 'type',
        'id': 'id',
        'location_id': 'location_id',
        'address': 'address',
        'arr_time': 'arr_time',
        'end_time': 'end_time',
        'end_date_time': 'end_date_time',
        'arr_date_time': 'arr_date_time',
        'waiting_time': 'waiting_time',
        'preparation_time': 'preparation_time',
        'distance': 'distance',
        'driving_time': 'driving_time',
        'load_before': 'load_before',
        'load_after': 'load_after'
    }

    def __init__(self, type=None, id=None, location_id=None, address=None, arr_time=None, end_time=None, end_date_time=None, arr_date_time=None, waiting_time=None, preparation_time=None, distance=None, driving_time=None, load_before=None, load_after=None):  # noqa: E501
        """Activity - a model defined in Swagger"""  # noqa: E501
        self._type = None
        self._id = None
        self._location_id = None
        self._address = None
        self._arr_time = None
        self._end_time = None
        self._end_date_time = None
        self._arr_date_time = None
        self._waiting_time = None
        self._preparation_time = None
        self._distance = None
        self._driving_time = None
        self._load_before = None
        self._load_after = None
        self.discriminator = None
        if type is not None:
            self.type = type
        if id is not None:
            self.id = id
        if location_id is not None:
            self.location_id = location_id
        if address is not None:
            self.address = address
        if arr_time is not None:
            self.arr_time = arr_time
        if end_time is not None:
            self.end_time = end_time
        if end_date_time is not None:
            self.end_date_time = end_date_time
        if arr_date_time is not None:
            self.arr_date_time = arr_date_time
        if waiting_time is not None:
            self.waiting_time = waiting_time
        if preparation_time is not None:
            self.preparation_time = preparation_time
        if distance is not None:
            self.distance = distance
        if driving_time is not None:
            self.driving_time = driving_time
        if load_before is not None:
            self.load_before = load_before
        if load_after is not None:
            self.load_after = load_after

    @property
    def type(self):
        """Gets the type of this Activity.  # noqa: E501

        type of activity  # noqa: E501

        :return: The type of this Activity.  # noqa: E501
        :rtype: str
        """
        return self._type

    @type.setter
    def type(self, type):
        """Sets the type of this Activity.

        type of activity  # noqa: E501

        :param type: The type of this Activity.  # noqa: E501
        :type: str
        """
        allowed_values = ["start", "end", "service", "pickupShipment", "deliverShipment", "pickup", "delivery", "break"]  # noqa: E501
        if type not in allowed_values:
            raise ValueError(
                "Invalid value for `type` ({0}), must be one of {1}"  # noqa: E501
                .format(type, allowed_values)
            )

        self._type = type

    @property
    def id(self):
        """Gets the id of this Activity.  # noqa: E501

        Id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to  # noqa: E501

        :return: The id of this Activity.  # noqa: E501
        :rtype: str
        """
        return self._id

    @id.setter
    def id(self, id):
        """Sets the id of this Activity.

        Id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to  # noqa: E501

        :param id: The id of this Activity.  # noqa: E501
        :type: str
        """

        self._id = id

    @property
    def location_id(self):
        """Gets the location_id of this Activity.  # noqa: E501

        Id that refers to address  # noqa: E501

        :return: The location_id of this Activity.  # noqa: E501
        :rtype: str
        """
        return self._location_id

    @location_id.setter
    def location_id(self, location_id):
        """Sets the location_id of this Activity.

        Id that refers to address  # noqa: E501

        :param location_id: The location_id of this Activity.  # noqa: E501
        :type: str
        """

        self._location_id = location_id

    @property
    def address(self):
        """Gets the address of this Activity.  # noqa: E501


        :return: The address of this Activity.  # noqa: E501
        :rtype: ResponseAddress
        """
        return self._address

    @address.setter
    def address(self, address):
        """Sets the address of this Activity.


        :param address: The address of this Activity.  # noqa: E501
        :type: ResponseAddress
        """

        self._address = address

    @property
    def arr_time(self):
        """Gets the arr_time of this Activity.  # noqa: E501

        Arrival time at this activity in seconds. If type is `start`, this is not available (since it makes no sense to have `arr_time` at start). However, `end_time` is available and actually means \\\"departure time\\\" at start location. It is important to note that `arr_time` does not necessarily mean \\\"start of underlying activity\\\", it solely means arrival time at activity location. If this activity has no time windows and if there are no further preparation times, `arr_time` is equal to activity start time.  # noqa: E501

        :return: The arr_time of this Activity.  # noqa: E501
        :rtype: int
        """
        return self._arr_time

    @arr_time.setter
    def arr_time(self, arr_time):
        """Sets the arr_time of this Activity.

        Arrival time at this activity in seconds. If type is `start`, this is not available (since it makes no sense to have `arr_time` at start). However, `end_time` is available and actually means \\\"departure time\\\" at start location. It is important to note that `arr_time` does not necessarily mean \\\"start of underlying activity\\\", it solely means arrival time at activity location. If this activity has no time windows and if there are no further preparation times, `arr_time` is equal to activity start time.  # noqa: E501

        :param arr_time: The arr_time of this Activity.  # noqa: E501
        :type: int
        """

        self._arr_time = arr_time

    @property
    def end_time(self):
        """Gets the end_time of this Activity.  # noqa: E501

        End time of and thus departure time at this activity. If type is `end`, this is not available (since it makes no sense to have an `end_time` at end) `end_time` at each activity is equal to the departure time at the activity location.  # noqa: E501

        :return: The end_time of this Activity.  # noqa: E501
        :rtype: int
        """
        return self._end_time

    @end_time.setter
    def end_time(self, end_time):
        """Sets the end_time of this Activity.

        End time of and thus departure time at this activity. If type is `end`, this is not available (since it makes no sense to have an `end_time` at end) `end_time` at each activity is equal to the departure time at the activity location.  # noqa: E501

        :param end_time: The end_time of this Activity.  # noqa: E501
        :type: int
        """

        self._end_time = end_time

    @property
    def end_date_time(self):
        """Gets the end_date_time of this Activity.  # noqa: E501

        End date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is `null`.  # noqa: E501

        :return: The end_date_time of this Activity.  # noqa: E501
        :rtype: datetime
        """
        return self._end_date_time

    @end_date_time.setter
    def end_date_time(self, end_date_time):
        """Sets the end_date_time of this Activity.

        End date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is `null`.  # noqa: E501

        :param end_date_time: The end_date_time of this Activity.  # noqa: E501
        :type: datetime
        """

        self._end_date_time = end_date_time

    @property
    def arr_date_time(self):
        """Gets the arr_date_time of this Activity.  # noqa: E501

        Arrival date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is `null`.  # noqa: E501

        :return: The arr_date_time of this Activity.  # noqa: E501
        :rtype: datetime
        """
        return self._arr_date_time

    @arr_date_time.setter
    def arr_date_time(self, arr_date_time):
        """Sets the arr_date_time of this Activity.

        Arrival date time with offset like this 1970-01-01T01:00+01:00. If you do not use time-dependent optimization, this is `null`.  # noqa: E501

        :param arr_date_time: The arr_date_time of this Activity.  # noqa: E501
        :type: datetime
        """

        self._arr_date_time = arr_date_time

    @property
    def waiting_time(self):
        """Gets the waiting_time of this Activity.  # noqa: E501

        Waiting time at this activity in seconds. A waiting time can occur if the activity has at least one time window. If `arr_time` < `time_window.earliest` a waiting time of `time_window_earliest` - `arr_time` occurs.  # noqa: E501

        :return: The waiting_time of this Activity.  # noqa: E501
        :rtype: int
        """
        return self._waiting_time

    @waiting_time.setter
    def waiting_time(self, waiting_time):
        """Sets the waiting_time of this Activity.

        Waiting time at this activity in seconds. A waiting time can occur if the activity has at least one time window. If `arr_time` < `time_window.earliest` a waiting time of `time_window_earliest` - `arr_time` occurs.  # noqa: E501

        :param waiting_time: The waiting_time of this Activity.  # noqa: E501
        :type: int
        """

        self._waiting_time = waiting_time

    @property
    def preparation_time(self):
        """Gets the preparation_time of this Activity.  # noqa: E501

        preparation time at this activity in seconds  # noqa: E501

        :return: The preparation_time of this Activity.  # noqa: E501
        :rtype: int
        """
        return self._preparation_time

    @preparation_time.setter
    def preparation_time(self, preparation_time):
        """Sets the preparation_time of this Activity.

        preparation time at this activity in seconds  # noqa: E501

        :param preparation_time: The preparation_time of this Activity.  # noqa: E501
        :type: int
        """

        self._preparation_time = preparation_time

    @property
    def distance(self):
        """Gets the distance of this Activity.  # noqa: E501

        cumulated distance from start to this activity in m  # noqa: E501

        :return: The distance of this Activity.  # noqa: E501
        :rtype: int
        """
        return self._distance

    @distance.setter
    def distance(self, distance):
        """Sets the distance of this Activity.

        cumulated distance from start to this activity in m  # noqa: E501

        :param distance: The distance of this Activity.  # noqa: E501
        :type: int
        """

        self._distance = distance

    @property
    def driving_time(self):
        """Gets the driving_time of this Activity.  # noqa: E501

        driving time of driver in seconds  # noqa: E501

        :return: The driving_time of this Activity.  # noqa: E501
        :rtype: int
        """
        return self._driving_time

    @driving_time.setter
    def driving_time(self, driving_time):
        """Sets the driving_time of this Activity.

        driving time of driver in seconds  # noqa: E501

        :param driving_time: The driving_time of this Activity.  # noqa: E501
        :type: int
        """

        self._driving_time = driving_time

    @property
    def load_before(self):
        """Gets the load_before of this Activity.  # noqa: E501

        Array with size/capacity dimensions before this activity  # noqa: E501

        :return: The load_before of this Activity.  # noqa: E501
        :rtype: list[int]
        """
        return self._load_before

    @load_before.setter
    def load_before(self, load_before):
        """Sets the load_before of this Activity.

        Array with size/capacity dimensions before this activity  # noqa: E501

        :param load_before: The load_before of this Activity.  # noqa: E501
        :type: list[int]
        """

        self._load_before = load_before

    @property
    def load_after(self):
        """Gets the load_after of this Activity.  # noqa: E501

        Array with size/capacity dimensions after this activity  # noqa: E501

        :return: The load_after of this Activity.  # noqa: E501
        :rtype: list[int]
        """
        return self._load_after

    @load_after.setter
    def load_after(self, load_after):
        """Sets the load_after of this Activity.

        Array with size/capacity dimensions after this activity  # noqa: E501

        :param load_after: The load_after of this Activity.  # noqa: E501
        :type: list[int]
        """

        self._load_after = load_after

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
        if issubclass(Activity, dict):
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
        if not isinstance(other, Activity):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
