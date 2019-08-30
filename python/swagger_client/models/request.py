# coding: utf-8

"""
    GraphHopper Directions API

     With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Clients  To speed up development and make coding easier, we offer the following clients:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions for motor vehicles such as `car` or `truck` are only considered with `edge_based=true` for the Routing (other APIs will follow).** Or if you already use `ch.disable=true` no additional parameter is required to consider turn restrictions for motor vehicles.  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png)   # noqa: E501

    OpenAPI spec version: 1.0.0
    Contact: support@graphhopper.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""

import pprint
import re  # noqa: F401

import six
from swagger_client.models.algorithm import Algorithm  # noqa: F401,E501
from swagger_client.models.configuration import Configuration  # noqa: F401,E501
from swagger_client.models.cost_matrix import CostMatrix  # noqa: F401,E501
from swagger_client.models.object import Object  # noqa: F401,E501
from swagger_client.models.objective import Objective  # noqa: F401,E501
from swagger_client.models.service import Service  # noqa: F401,E501
from swagger_client.models.shipment import Shipment  # noqa: F401,E501
from swagger_client.models.vehicle import Vehicle  # noqa: F401,E501
from swagger_client.models.vehicle_type import VehicleType  # noqa: F401,E501


class Request(object):
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
        'vehicles': 'list[Vehicle]',
        'vehicle_types': 'list[VehicleType]',
        'services': 'list[Service]',
        'shipments': 'list[Shipment]',
        'relations': 'list[Object]',
        'algorithm': 'Algorithm',
        'objectives': 'list[Objective]',
        'cost_matrices': 'list[CostMatrix]',
        'configuration': 'Configuration'
    }

    attribute_map = {
        'vehicles': 'vehicles',
        'vehicle_types': 'vehicle_types',
        'services': 'services',
        'shipments': 'shipments',
        'relations': 'relations',
        'algorithm': 'algorithm',
        'objectives': 'objectives',
        'cost_matrices': 'cost_matrices',
        'configuration': 'configuration'
    }

    def __init__(self, vehicles=None, vehicle_types=None, services=None, shipments=None, relations=None, algorithm=None, objectives=None, cost_matrices=None, configuration=None):  # noqa: E501
        """Request - a model defined in Swagger"""  # noqa: E501
        self._vehicles = None
        self._vehicle_types = None
        self._services = None
        self._shipments = None
        self._relations = None
        self._algorithm = None
        self._objectives = None
        self._cost_matrices = None
        self._configuration = None
        self.discriminator = None
        if vehicles is not None:
            self.vehicles = vehicles
        if vehicle_types is not None:
            self.vehicle_types = vehicle_types
        if services is not None:
            self.services = services
        if shipments is not None:
            self.shipments = shipments
        if relations is not None:
            self.relations = relations
        if algorithm is not None:
            self.algorithm = algorithm
        if objectives is not None:
            self.objectives = objectives
        if cost_matrices is not None:
            self.cost_matrices = cost_matrices
        if configuration is not None:
            self.configuration = configuration

    @property
    def vehicles(self):
        """Gets the vehicles of this Request.  # noqa: E501

        Specifies the available vehicles.  # noqa: E501

        :return: The vehicles of this Request.  # noqa: E501
        :rtype: list[Vehicle]
        """
        return self._vehicles

    @vehicles.setter
    def vehicles(self, vehicles):
        """Sets the vehicles of this Request.

        Specifies the available vehicles.  # noqa: E501

        :param vehicles: The vehicles of this Request.  # noqa: E501
        :type: list[Vehicle]
        """

        self._vehicles = vehicles

    @property
    def vehicle_types(self):
        """Gets the vehicle_types of this Request.  # noqa: E501

        Specifies the available vehicle types that are referred to by the specified vehicles.  # noqa: E501

        :return: The vehicle_types of this Request.  # noqa: E501
        :rtype: list[VehicleType]
        """
        return self._vehicle_types

    @vehicle_types.setter
    def vehicle_types(self, vehicle_types):
        """Sets the vehicle_types of this Request.

        Specifies the available vehicle types that are referred to by the specified vehicles.  # noqa: E501

        :param vehicle_types: The vehicle_types of this Request.  # noqa: E501
        :type: list[VehicleType]
        """

        self._vehicle_types = vehicle_types

    @property
    def services(self):
        """Gets the services of this Request.  # noqa: E501

        Specifies the available services, i.e. pickup, delivery or any other points to be visited by vehicles. Each service only involves exactly one location.  # noqa: E501

        :return: The services of this Request.  # noqa: E501
        :rtype: list[Service]
        """
        return self._services

    @services.setter
    def services(self, services):
        """Sets the services of this Request.

        Specifies the available services, i.e. pickup, delivery or any other points to be visited by vehicles. Each service only involves exactly one location.  # noqa: E501

        :param services: The services of this Request.  # noqa: E501
        :type: list[Service]
        """

        self._services = services

    @property
    def shipments(self):
        """Gets the shipments of this Request.  # noqa: E501

        Specifies the available shipments, i.e. pickup AND delivery points to be visited by vehicles subsequently. Each shipment involves exactly two locations, a pickup and a delivery location.  # noqa: E501

        :return: The shipments of this Request.  # noqa: E501
        :rtype: list[Shipment]
        """
        return self._shipments

    @shipments.setter
    def shipments(self, shipments):
        """Sets the shipments of this Request.

        Specifies the available shipments, i.e. pickup AND delivery points to be visited by vehicles subsequently. Each shipment involves exactly two locations, a pickup and a delivery location.  # noqa: E501

        :param shipments: The shipments of this Request.  # noqa: E501
        :type: list[Shipment]
        """

        self._shipments = shipments

    @property
    def relations(self):
        """Gets the relations of this Request.  # noqa: E501

        Specifies an arbitrary number of additional relations between and among services and shipments.  # noqa: E501

        :return: The relations of this Request.  # noqa: E501
        :rtype: list[Object]
        """
        return self._relations

    @relations.setter
    def relations(self, relations):
        """Sets the relations of this Request.

        Specifies an arbitrary number of additional relations between and among services and shipments.  # noqa: E501

        :param relations: The relations of this Request.  # noqa: E501
        :type: list[Object]
        """

        self._relations = relations

    @property
    def algorithm(self):
        """Gets the algorithm of this Request.  # noqa: E501


        :return: The algorithm of this Request.  # noqa: E501
        :rtype: Algorithm
        """
        return self._algorithm

    @algorithm.setter
    def algorithm(self, algorithm):
        """Sets the algorithm of this Request.


        :param algorithm: The algorithm of this Request.  # noqa: E501
        :type: Algorithm
        """

        self._algorithm = algorithm

    @property
    def objectives(self):
        """Gets the objectives of this Request.  # noqa: E501

        Specifies an array of objective functions. This tells the algorithm the objective of the optimization.  # noqa: E501

        :return: The objectives of this Request.  # noqa: E501
        :rtype: list[Objective]
        """
        return self._objectives

    @objectives.setter
    def objectives(self, objectives):
        """Sets the objectives of this Request.

        Specifies an array of objective functions. This tells the algorithm the objective of the optimization.  # noqa: E501

        :param objectives: The objectives of this Request.  # noqa: E501
        :type: list[Objective]
        """

        self._objectives = objectives

    @property
    def cost_matrices(self):
        """Gets the cost_matrices of this Request.  # noqa: E501

        Specifies an array of cost matrix objects. This is used if you want to provide custom distance and/or time matrix values e.g. for time-dependent or indoor routing like for warehouses.  # noqa: E501

        :return: The cost_matrices of this Request.  # noqa: E501
        :rtype: list[CostMatrix]
        """
        return self._cost_matrices

    @cost_matrices.setter
    def cost_matrices(self, cost_matrices):
        """Sets the cost_matrices of this Request.

        Specifies an array of cost matrix objects. This is used if you want to provide custom distance and/or time matrix values e.g. for time-dependent or indoor routing like for warehouses.  # noqa: E501

        :param cost_matrices: The cost_matrices of this Request.  # noqa: E501
        :type: list[CostMatrix]
        """

        self._cost_matrices = cost_matrices

    @property
    def configuration(self):
        """Gets the configuration of this Request.  # noqa: E501


        :return: The configuration of this Request.  # noqa: E501
        :rtype: Configuration
        """
        return self._configuration

    @configuration.setter
    def configuration(self, configuration):
        """Sets the configuration of this Request.


        :param configuration: The configuration of this Request.  # noqa: E501
        :type: Configuration
        """

        self._configuration = configuration

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
        if issubclass(Request, dict):
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
        if not isinstance(other, Request):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
