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
from swagger_client.models.route import Route  # noqa: F401,E501
from swagger_client.models.solution_unassigned import SolutionUnassigned  # noqa: F401,E501


class Solution(object):
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
        'costs': 'int',
        'distance': 'int',
        'time': 'int',
        'transport_time': 'int',
        'max_operation_time': 'int',
        'waiting_time': 'int',
        'service_duration': 'int',
        'preparation_time': 'int',
        'completion_time': 'int',
        'no_vehicles': 'int',
        'no_unassigned': 'int',
        'routes': 'list[Route]',
        'unassigned': 'SolutionUnassigned'
    }

    attribute_map = {
        'costs': 'costs',
        'distance': 'distance',
        'time': 'time',
        'transport_time': 'transport_time',
        'max_operation_time': 'max_operation_time',
        'waiting_time': 'waiting_time',
        'service_duration': 'service_duration',
        'preparation_time': 'preparation_time',
        'completion_time': 'completion_time',
        'no_vehicles': 'no_vehicles',
        'no_unassigned': 'no_unassigned',
        'routes': 'routes',
        'unassigned': 'unassigned'
    }

    def __init__(self, costs=None, distance=None, time=None, transport_time=None, max_operation_time=None, waiting_time=None, service_duration=None, preparation_time=None, completion_time=None, no_vehicles=None, no_unassigned=None, routes=None, unassigned=None):  # noqa: E501
        """Solution - a model defined in Swagger"""  # noqa: E501
        self._costs = None
        self._distance = None
        self._time = None
        self._transport_time = None
        self._max_operation_time = None
        self._waiting_time = None
        self._service_duration = None
        self._preparation_time = None
        self._completion_time = None
        self._no_vehicles = None
        self._no_unassigned = None
        self._routes = None
        self._unassigned = None
        self.discriminator = None
        if costs is not None:
            self.costs = costs
        if distance is not None:
            self.distance = distance
        if time is not None:
            self.time = time
        if transport_time is not None:
            self.transport_time = transport_time
        if max_operation_time is not None:
            self.max_operation_time = max_operation_time
        if waiting_time is not None:
            self.waiting_time = waiting_time
        if service_duration is not None:
            self.service_duration = service_duration
        if preparation_time is not None:
            self.preparation_time = preparation_time
        if completion_time is not None:
            self.completion_time = completion_time
        if no_vehicles is not None:
            self.no_vehicles = no_vehicles
        if no_unassigned is not None:
            self.no_unassigned = no_unassigned
        if routes is not None:
            self.routes = routes
        if unassigned is not None:
            self.unassigned = unassigned

    @property
    def costs(self):
        """Gets the costs of this Solution.  # noqa: E501


        :return: The costs of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._costs

    @costs.setter
    def costs(self, costs):
        """Sets the costs of this Solution.


        :param costs: The costs of this Solution.  # noqa: E501
        :type: int
        """

        self._costs = costs

    @property
    def distance(self):
        """Gets the distance of this Solution.  # noqa: E501

        Overall distance travelled in meter, i.e. the sum of each route's transport distance  # noqa: E501

        :return: The distance of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._distance

    @distance.setter
    def distance(self, distance):
        """Sets the distance of this Solution.

        Overall distance travelled in meter, i.e. the sum of each route's transport distance  # noqa: E501

        :param distance: The distance of this Solution.  # noqa: E501
        :type: int
        """

        self._distance = distance

    @property
    def time(self):
        """Gets the time of this Solution.  # noqa: E501

        Use `transport_time` instead.  # noqa: E501

        :return: The time of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._time

    @time.setter
    def time(self, time):
        """Sets the time of this Solution.

        Use `transport_time` instead.  # noqa: E501

        :param time: The time of this Solution.  # noqa: E501
        :type: int
        """

        self._time = time

    @property
    def transport_time(self):
        """Gets the transport_time of this Solution.  # noqa: E501

        Overall time travelled in seconds, i.e. the sum of each route's transport time.  # noqa: E501

        :return: The transport_time of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._transport_time

    @transport_time.setter
    def transport_time(self, transport_time):
        """Sets the transport_time of this Solution.

        Overall time travelled in seconds, i.e. the sum of each route's transport time.  # noqa: E501

        :param transport_time: The transport_time of this Solution.  # noqa: E501
        :type: int
        """

        self._transport_time = transport_time

    @property
    def max_operation_time(self):
        """Gets the max_operation_time of this Solution.  # noqa: E501

        Operation time of longest route in seconds.  # noqa: E501

        :return: The max_operation_time of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._max_operation_time

    @max_operation_time.setter
    def max_operation_time(self, max_operation_time):
        """Sets the max_operation_time of this Solution.

        Operation time of longest route in seconds.  # noqa: E501

        :param max_operation_time: The max_operation_time of this Solution.  # noqa: E501
        :type: int
        """

        self._max_operation_time = max_operation_time

    @property
    def waiting_time(self):
        """Gets the waiting_time of this Solution.  # noqa: E501

        Overall waiting time in seconds.  # noqa: E501

        :return: The waiting_time of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._waiting_time

    @waiting_time.setter
    def waiting_time(self, waiting_time):
        """Sets the waiting_time of this Solution.

        Overall waiting time in seconds.  # noqa: E501

        :param waiting_time: The waiting_time of this Solution.  # noqa: E501
        :type: int
        """

        self._waiting_time = waiting_time

    @property
    def service_duration(self):
        """Gets the service_duration of this Solution.  # noqa: E501

        Overall service time in seconds.  # noqa: E501

        :return: The service_duration of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._service_duration

    @service_duration.setter
    def service_duration(self, service_duration):
        """Sets the service_duration of this Solution.

        Overall service time in seconds.  # noqa: E501

        :param service_duration: The service_duration of this Solution.  # noqa: E501
        :type: int
        """

        self._service_duration = service_duration

    @property
    def preparation_time(self):
        """Gets the preparation_time of this Solution.  # noqa: E501

        Overall preparation time in seconds.  # noqa: E501

        :return: The preparation_time of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._preparation_time

    @preparation_time.setter
    def preparation_time(self, preparation_time):
        """Sets the preparation_time of this Solution.

        Overall preparation time in seconds.  # noqa: E501

        :param preparation_time: The preparation_time of this Solution.  # noqa: E501
        :type: int
        """

        self._preparation_time = preparation_time

    @property
    def completion_time(self):
        """Gets the completion_time of this Solution.  # noqa: E501

        Overall completion time in seconds, i.e. the sum of each routes/drivers operation time.  # noqa: E501

        :return: The completion_time of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._completion_time

    @completion_time.setter
    def completion_time(self, completion_time):
        """Sets the completion_time of this Solution.

        Overall completion time in seconds, i.e. the sum of each routes/drivers operation time.  # noqa: E501

        :param completion_time: The completion_time of this Solution.  # noqa: E501
        :type: int
        """

        self._completion_time = completion_time

    @property
    def no_vehicles(self):
        """Gets the no_vehicles of this Solution.  # noqa: E501

        Number of employed vehicles.  # noqa: E501

        :return: The no_vehicles of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._no_vehicles

    @no_vehicles.setter
    def no_vehicles(self, no_vehicles):
        """Sets the no_vehicles of this Solution.

        Number of employed vehicles.  # noqa: E501

        :param no_vehicles: The no_vehicles of this Solution.  # noqa: E501
        :type: int
        """

        self._no_vehicles = no_vehicles

    @property
    def no_unassigned(self):
        """Gets the no_unassigned of this Solution.  # noqa: E501

        Number of jobs that could not be assigned to final solution.  # noqa: E501

        :return: The no_unassigned of this Solution.  # noqa: E501
        :rtype: int
        """
        return self._no_unassigned

    @no_unassigned.setter
    def no_unassigned(self, no_unassigned):
        """Sets the no_unassigned of this Solution.

        Number of jobs that could not be assigned to final solution.  # noqa: E501

        :param no_unassigned: The no_unassigned of this Solution.  # noqa: E501
        :type: int
        """

        self._no_unassigned = no_unassigned

    @property
    def routes(self):
        """Gets the routes of this Solution.  # noqa: E501

        An array of routes  # noqa: E501

        :return: The routes of this Solution.  # noqa: E501
        :rtype: list[Route]
        """
        return self._routes

    @routes.setter
    def routes(self, routes):
        """Sets the routes of this Solution.

        An array of routes  # noqa: E501

        :param routes: The routes of this Solution.  # noqa: E501
        :type: list[Route]
        """

        self._routes = routes

    @property
    def unassigned(self):
        """Gets the unassigned of this Solution.  # noqa: E501


        :return: The unassigned of this Solution.  # noqa: E501
        :rtype: SolutionUnassigned
        """
        return self._unassigned

    @unassigned.setter
    def unassigned(self, unassigned):
        """Sets the unassigned of this Solution.


        :param unassigned: The unassigned of this Solution.  # noqa: E501
        :type: SolutionUnassigned
        """

        self._unassigned = unassigned

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
        if issubclass(Solution, dict):
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
        if not isinstance(other, Solution):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
