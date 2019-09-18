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


class RouteResponsePathInstructions(object):
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
        'text': 'str',
        'street_name': 'str',
        'distance': 'float',
        'time': 'int',
        'interval': 'list[int]',
        'sign': 'int',
        'exit_number': 'int',
        'turn_angle': 'float'
    }

    attribute_map = {
        'text': 'text',
        'street_name': 'street_name',
        'distance': 'distance',
        'time': 'time',
        'interval': 'interval',
        'sign': 'sign',
        'exit_number': 'exit_number',
        'turn_angle': 'turn_angle'
    }

    def __init__(self, text=None, street_name=None, distance=None, time=None, interval=None, sign=None, exit_number=None, turn_angle=None):  # noqa: E501
        """RouteResponsePathInstructions - a model defined in Swagger"""  # noqa: E501
        self._text = None
        self._street_name = None
        self._distance = None
        self._time = None
        self._interval = None
        self._sign = None
        self._exit_number = None
        self._turn_angle = None
        self.discriminator = None
        if text is not None:
            self.text = text
        if street_name is not None:
            self.street_name = street_name
        if distance is not None:
            self.distance = distance
        if time is not None:
            self.time = time
        if interval is not None:
            self.interval = interval
        if sign is not None:
            self.sign = sign
        if exit_number is not None:
            self.exit_number = exit_number
        if turn_angle is not None:
            self.turn_angle = turn_angle

    @property
    def text(self):
        """Gets the text of this RouteResponsePathInstructions.  # noqa: E501

        A description what the user has to do in order to follow the route. The language depends on the locale parameter.   # noqa: E501

        :return: The text of this RouteResponsePathInstructions.  # noqa: E501
        :rtype: str
        """
        return self._text

    @text.setter
    def text(self, text):
        """Sets the text of this RouteResponsePathInstructions.

        A description what the user has to do in order to follow the route. The language depends on the locale parameter.   # noqa: E501

        :param text: The text of this RouteResponsePathInstructions.  # noqa: E501
        :type: str
        """

        self._text = text

    @property
    def street_name(self):
        """Gets the street_name of this RouteResponsePathInstructions.  # noqa: E501

        The name of the street to turn onto in order to follow the route.   # noqa: E501

        :return: The street_name of this RouteResponsePathInstructions.  # noqa: E501
        :rtype: str
        """
        return self._street_name

    @street_name.setter
    def street_name(self, street_name):
        """Sets the street_name of this RouteResponsePathInstructions.

        The name of the street to turn onto in order to follow the route.   # noqa: E501

        :param street_name: The street_name of this RouteResponsePathInstructions.  # noqa: E501
        :type: str
        """

        self._street_name = street_name

    @property
    def distance(self):
        """Gets the distance of this RouteResponsePathInstructions.  # noqa: E501

        The distance for this instruction, in meters.   # noqa: E501

        :return: The distance of this RouteResponsePathInstructions.  # noqa: E501
        :rtype: float
        """
        return self._distance

    @distance.setter
    def distance(self, distance):
        """Sets the distance of this RouteResponsePathInstructions.

        The distance for this instruction, in meters.   # noqa: E501

        :param distance: The distance of this RouteResponsePathInstructions.  # noqa: E501
        :type: float
        """

        self._distance = distance

    @property
    def time(self):
        """Gets the time of this RouteResponsePathInstructions.  # noqa: E501

        The duration for this instruction, in milliseconds.   # noqa: E501

        :return: The time of this RouteResponsePathInstructions.  # noqa: E501
        :rtype: int
        """
        return self._time

    @time.setter
    def time(self, time):
        """Sets the time of this RouteResponsePathInstructions.

        The duration for this instruction, in milliseconds.   # noqa: E501

        :param time: The time of this RouteResponsePathInstructions.  # noqa: E501
        :type: int
        """

        self._time = time

    @property
    def interval(self):
        """Gets the interval of this RouteResponsePathInstructions.  # noqa: E501

        Two indices into `points`, referring to the beginning and the end of the segment of the route this instruction refers to.   # noqa: E501

        :return: The interval of this RouteResponsePathInstructions.  # noqa: E501
        :rtype: list[int]
        """
        return self._interval

    @interval.setter
    def interval(self, interval):
        """Sets the interval of this RouteResponsePathInstructions.

        Two indices into `points`, referring to the beginning and the end of the segment of the route this instruction refers to.   # noqa: E501

        :param interval: The interval of this RouteResponsePathInstructions.  # noqa: E501
        :type: list[int]
        """

        self._interval = interval

    @property
    def sign(self):
        """Gets the sign of this RouteResponsePathInstructions.  # noqa: E501

        A number which specifies the sign to show:  |   |   | |---|---| |TURN_SHARP_LEFT |-3| |TURN_LEFT | -2| |TURN_SLIGHT_LEFT | -1| |CONTINUE_ON_STREET | 0| |TURN_SLIGHT_RIGHT |1| |TURN_RIGHT | 2| |TURN_SHARP_RIGHT | 3| |FINISH | 4| |VIA_REACHED | 5| |USE_ROUNDABOUT | 6| |KEEP_RIGHT | 7|   # noqa: E501

        :return: The sign of this RouteResponsePathInstructions.  # noqa: E501
        :rtype: int
        """
        return self._sign

    @sign.setter
    def sign(self, sign):
        """Sets the sign of this RouteResponsePathInstructions.

        A number which specifies the sign to show:  |   |   | |---|---| |TURN_SHARP_LEFT |-3| |TURN_LEFT | -2| |TURN_SLIGHT_LEFT | -1| |CONTINUE_ON_STREET | 0| |TURN_SLIGHT_RIGHT |1| |TURN_RIGHT | 2| |TURN_SHARP_RIGHT | 3| |FINISH | 4| |VIA_REACHED | 5| |USE_ROUNDABOUT | 6| |KEEP_RIGHT | 7|   # noqa: E501

        :param sign: The sign of this RouteResponsePathInstructions.  # noqa: E501
        :type: int
        """

        self._sign = sign

    @property
    def exit_number(self):
        """Gets the exit_number of this RouteResponsePathInstructions.  # noqa: E501

        Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout.   # noqa: E501

        :return: The exit_number of this RouteResponsePathInstructions.  # noqa: E501
        :rtype: int
        """
        return self._exit_number

    @exit_number.setter
    def exit_number(self, exit_number):
        """Sets the exit_number of this RouteResponsePathInstructions.

        Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout.   # noqa: E501

        :param exit_number: The exit_number of this RouteResponsePathInstructions.  # noqa: E501
        :type: int
        """

        self._exit_number = exit_number

    @property
    def turn_angle(self):
        """Gets the turn_angle of this RouteResponsePathInstructions.  # noqa: E501

        Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout `0 < r < 2*PI` for clockwise and `-2*PI < r < 0` for counterclockwise turns.   # noqa: E501

        :return: The turn_angle of this RouteResponsePathInstructions.  # noqa: E501
        :rtype: float
        """
        return self._turn_angle

    @turn_angle.setter
    def turn_angle(self, turn_angle):
        """Sets the turn_angle of this RouteResponsePathInstructions.

        Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout `0 < r < 2*PI` for clockwise and `-2*PI < r < 0` for counterclockwise turns.   # noqa: E501

        :param turn_angle: The turn_angle of this RouteResponsePathInstructions.  # noqa: E501
        :type: float
        """

        self._turn_angle = turn_angle

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
        if issubclass(RouteResponsePathInstructions, dict):
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
        if not isinstance(other, RouteResponsePathInstructions):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
