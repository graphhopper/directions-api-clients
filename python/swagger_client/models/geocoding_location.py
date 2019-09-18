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
from swagger_client.models.geocoding_point import GeocodingPoint  # noqa: F401,E501


class GeocodingLocation(object):
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
        'point': 'GeocodingPoint',
        'osm_id': 'str',
        'osm_type': 'str',
        'osm_key': 'str',
        'name': 'str',
        'country': 'str',
        'city': 'str',
        'state': 'str',
        'street': 'str',
        'housenumber': 'str',
        'postcode': 'str'
    }

    attribute_map = {
        'point': 'point',
        'osm_id': 'osm_id',
        'osm_type': 'osm_type',
        'osm_key': 'osm_key',
        'name': 'name',
        'country': 'country',
        'city': 'city',
        'state': 'state',
        'street': 'street',
        'housenumber': 'housenumber',
        'postcode': 'postcode'
    }

    def __init__(self, point=None, osm_id=None, osm_type=None, osm_key=None, name=None, country=None, city=None, state=None, street=None, housenumber=None, postcode=None):  # noqa: E501
        """GeocodingLocation - a model defined in Swagger"""  # noqa: E501
        self._point = None
        self._osm_id = None
        self._osm_type = None
        self._osm_key = None
        self._name = None
        self._country = None
        self._city = None
        self._state = None
        self._street = None
        self._housenumber = None
        self._postcode = None
        self.discriminator = None
        if point is not None:
            self.point = point
        if osm_id is not None:
            self.osm_id = osm_id
        if osm_type is not None:
            self.osm_type = osm_type
        if osm_key is not None:
            self.osm_key = osm_key
        if name is not None:
            self.name = name
        if country is not None:
            self.country = country
        if city is not None:
            self.city = city
        if state is not None:
            self.state = state
        if street is not None:
            self.street = street
        if housenumber is not None:
            self.housenumber = housenumber
        if postcode is not None:
            self.postcode = postcode

    @property
    def point(self):
        """Gets the point of this GeocodingLocation.  # noqa: E501


        :return: The point of this GeocodingLocation.  # noqa: E501
        :rtype: GeocodingPoint
        """
        return self._point

    @point.setter
    def point(self, point):
        """Sets the point of this GeocodingLocation.


        :param point: The point of this GeocodingLocation.  # noqa: E501
        :type: GeocodingPoint
        """

        self._point = point

    @property
    def osm_id(self):
        """Gets the osm_id of this GeocodingLocation.  # noqa: E501

        The OSM ID of the entity  # noqa: E501

        :return: The osm_id of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._osm_id

    @osm_id.setter
    def osm_id(self, osm_id):
        """Sets the osm_id of this GeocodingLocation.

        The OSM ID of the entity  # noqa: E501

        :param osm_id: The osm_id of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._osm_id = osm_id

    @property
    def osm_type(self):
        """Gets the osm_type of this GeocodingLocation.  # noqa: E501

        N = node, R = relation, W = way  # noqa: E501

        :return: The osm_type of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._osm_type

    @osm_type.setter
    def osm_type(self, osm_type):
        """Sets the osm_type of this GeocodingLocation.

        N = node, R = relation, W = way  # noqa: E501

        :param osm_type: The osm_type of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._osm_type = osm_type

    @property
    def osm_key(self):
        """Gets the osm_key of this GeocodingLocation.  # noqa: E501

        The OSM key of the entity  # noqa: E501

        :return: The osm_key of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._osm_key

    @osm_key.setter
    def osm_key(self, osm_key):
        """Sets the osm_key of this GeocodingLocation.

        The OSM key of the entity  # noqa: E501

        :param osm_key: The osm_key of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._osm_key = osm_key

    @property
    def name(self):
        """Gets the name of this GeocodingLocation.  # noqa: E501

        The name of the entity. Can be a boundary, POI, address, etc  # noqa: E501

        :return: The name of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._name

    @name.setter
    def name(self, name):
        """Sets the name of this GeocodingLocation.

        The name of the entity. Can be a boundary, POI, address, etc  # noqa: E501

        :param name: The name of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._name = name

    @property
    def country(self):
        """Gets the country of this GeocodingLocation.  # noqa: E501

        The country of the address  # noqa: E501

        :return: The country of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._country

    @country.setter
    def country(self, country):
        """Sets the country of this GeocodingLocation.

        The country of the address  # noqa: E501

        :param country: The country of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._country = country

    @property
    def city(self):
        """Gets the city of this GeocodingLocation.  # noqa: E501

        The city of the address  # noqa: E501

        :return: The city of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._city

    @city.setter
    def city(self, city):
        """Sets the city of this GeocodingLocation.

        The city of the address  # noqa: E501

        :param city: The city of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._city = city

    @property
    def state(self):
        """Gets the state of this GeocodingLocation.  # noqa: E501

        The state of the address  # noqa: E501

        :return: The state of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._state

    @state.setter
    def state(self, state):
        """Sets the state of this GeocodingLocation.

        The state of the address  # noqa: E501

        :param state: The state of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._state = state

    @property
    def street(self):
        """Gets the street of this GeocodingLocation.  # noqa: E501

        The street of the address  # noqa: E501

        :return: The street of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._street

    @street.setter
    def street(self, street):
        """Sets the street of this GeocodingLocation.

        The street of the address  # noqa: E501

        :param street: The street of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._street = street

    @property
    def housenumber(self):
        """Gets the housenumber of this GeocodingLocation.  # noqa: E501

        The housenumber of the address  # noqa: E501

        :return: The housenumber of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._housenumber

    @housenumber.setter
    def housenumber(self, housenumber):
        """Sets the housenumber of this GeocodingLocation.

        The housenumber of the address  # noqa: E501

        :param housenumber: The housenumber of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._housenumber = housenumber

    @property
    def postcode(self):
        """Gets the postcode of this GeocodingLocation.  # noqa: E501

        The postcode of the address  # noqa: E501

        :return: The postcode of this GeocodingLocation.  # noqa: E501
        :rtype: str
        """
        return self._postcode

    @postcode.setter
    def postcode(self, postcode):
        """Sets the postcode of this GeocodingLocation.

        The postcode of the address  # noqa: E501

        :param postcode: The postcode of this GeocodingLocation.  # noqa: E501
        :type: str
        """

        self._postcode = postcode

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
        if issubclass(GeocodingLocation, dict):
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
        if not isinstance(other, GeocodingLocation):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
