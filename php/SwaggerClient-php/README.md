# SwaggerClient-php
With the [GraphHopper Directions API](https://www.graphhopper.com/products/) you can integrate A-to-B route planning, turn-by-turn navigation, route optimization, isochrone calculations and other tools in your application.  The GraphHopper Directions API consists of the following RESTful web services:   * [Routing](#tag/Routing-API),  * [Route Optimization](#tag/Route-Optimization-API),  * [Isochrone](#tag/Isochrone-API),  * [Map Matching](#tag/Map-Matching-API),  * [Matrix](#tag/Matrix-API) and  * [Geocoding](#tag/Geocoding-API).  # Explore our APIs  To play and see the Route Optimization in action try our [route editor](https://graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/)  which available in the [dashboard](https://graphhopper.com/dashboard/). See how the Routing and Geocoding is integrated in  our route planner website [GraphHopper Maps](https://graphhopper.com/maps) ([sources](https://github.com/graphhopper/graphhopper/tree/0.12/web/src/main/resources/assets)).  And [see below](#section/Explore-our-APIs/Insomnia) for a collection of requests for [Insomnia](https://insomnia.rest/) and [Postman](https://www.getpostman.com/). The request file contains all example requests from this documentation.  ## Get started  1. To use the GraphHopper Directions API you sign up [here](https://graphhopper.com/dashboard/#/register) and create an API key. 2. Read the documentation of the desired API part below. 3. Start using the GraphHopper Directions API. [Our API clients](#section/Explore-our-APIs/API-Clients) can speed up the integration.  To use the GraphHopper Directions API commercially, you can buy paid package [in the dashboard](https://graphhopper.com/dashboard/#/pricing).  ## Contact Us  If you have problems or questions see the following information:   * [FAQ](https://graphhopper.com/api/1/docs/FAQ/)  * [Public forum](https://discuss.graphhopper.com/c/directions-api)       * [Contact us](https://www.graphhopper.com/contact-form/)  To get informed about the newest features and development follow us at [twitter](https://twitter.com/graphhopper/) or [our blog](https://graphhopper.com/blog/).  Furthermore you can watch [this git repository](https://github.com/graphhopper/directions-api-doc) of this documentation, sign up at our [dashboard](https://graphhopper.com/dashboard/) to get the newsletter or sign up at [our forum](https://discuss.graphhopper.com/c/directions-api). Pick the channel you like most.  ## API Clients  To speed up development and make coding easier, we offer the following clients:   * [JavaScript client](https://github.com/graphhopper/directions-api-js-client) - try the [live examples](https://graphhopper.com/api/1/examples/)  * [Others](https://github.com/graphhopper/directions-api-clients) like C#, Ruby, PHP, Python, ... automatically created for the Route Optimization  ### Bandwidth reduction  If you create your own client, make sure it supports http/2 and gzipped responses for best speed.  If you use the Matrix or Route Optimization and want to solve large problems, we recommend you to reduce bandwidth by [compressing your POST request](https://gist.github.com/karussell/82851e303ea7b3459b2dea01f18949f4) and specifying the header as follows: `Content-Encoding: gzip`.  ## Insomnia  To explore our APIs with [Insomnia](https://insomnia.rest/), follow these steps:  1. Open Insomnia and Import [our workspace](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/GraphHopper-Direction-API-Insomnia.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your workspace: Manage Environments -> Base Environment -> `\"api_key\": your API key` 3. Start exploring  ![Insomnia](./img/insomnia.png)  ## Postman  To explore our APIs with [Postman](https://www.getpostman.com/), follow these steps:  1. Import our [request collections](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_collection.json) as well as our [environment file](https://raw.githubusercontent.com/graphhopper/directions-api-doc/master/web/restclients/graphhopper_directions_api.postman_environment.json). 2. Specify [your API key](https://graphhopper.com/dashboard/#/register) in your environment: `\"api_key\": your API key` 3. Start exploring  ![Postman](./img/postman.png)  # Map Data and Routing Profiles  Currently, our main data source is [OpenStreetMap](https://www.openstreetmap.org). We also integrated other network data providers. This chapter gives an overview about the options you have.  ## OpenStreetMap  #### Geographical Coverage  [OpenStreetMap](https://www.openstreetmap.org) covers the entire world. If you want to convince yourself whether we can offer appropriate data for your region, please visit [GraphHopper Maps](https://graphhopper.com/maps/). You can edit and modify OpenStreetMap data if you find that important information is missing, for example, a weight restriction for a bridge. [Here](https://wiki.openstreetmap.org/wiki/Beginners%27_guide) is a beginner's guide that shows how to add data.  If you edited data, we usually consider your data after 1 week at latest.  #### Supported Vehicle Profiles  The Routing, Matrix and Route Optimizations support the following vehicle profiles:  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png) truck      | Truck like a MAN or Mercedes-Benz Actros | height=3.7m, width=2.6+0.5m, length=12m, weight=13000 + 13000 kg, hgv=yes, 3 Axes | ![truck image](https://graphhopper.com/maps/img/truck.png) scooter    | Moped mode | Fast inner city, often used for food delivery, is able to ignore certain bollards, maximum speed of roughly 50km/h | ![scooter image](https://graphhopper.com/maps/img/scooter.png) foot       | Pedestrian or walking | foot access         | ![foot image](https://graphhopper.com/maps/img/foot.png) hike       | Pedestrian or walking with priority for more beautiful hiking tours and potentially a bit longer than `foot`  | foot access         | ![hike image](https://graphhopper.com/maps/img/hike.png) bike       | Trekking bike avoiding hills | bike access  | ![bike image](https://graphhopper.com/maps/img/bike.png) mtb        | Mountainbike          | bike access         | ![Mountainbike image](https://graphhopper.com/maps/img/mtb.png) racingbike| Bike preferring roads | bike access         | ![racingbike image](https://graphhopper.com/maps/img/racingbike.png)  **Please note, that turn restrictions for motor vehicles such as `car` or `truck` are only considered with `edge_based=true` for the Routing (other APIs will follow).** Or if you already use `ch.disable=true` no additional parameter is required to consider turn restrictions for motor vehicles.  For the free package you can only choose from `car`, `bike` or `foot`.  We also offer a sophisticated `motorcycle` profile powered by the [Kurviger](https://kurviger.de/en) Routing. Kurviger favors curves and slopes while avoiding cities and highways.  Also we offer custom vehicle profiles with different properties, different speed profiles or different access options. To find out more about custom profiles, please [contact us](https://www.graphhopper.com/contact-form/).  ## TomTom  If you need to consider traffic, you can purchase the TomTom add-on.  Please note:   * Currently we only offer this for our [Route Optimization](#tag/Route-Optimization-API).  * This add-on uses the TomTom road network and historical traffic information only. Live traffic is not yet considered. Read more about [how this works](https://www.graphhopper.com/blog/2017/11/06/time-dependent-optimization/).  * Additionally to our terms your end users need to accept the [TomTom Eula](https://www.graphhopper.com/tomtom-end-user-license-agreement/).  * We do *not* use the TomTom web services. We only use their data with our software.   [Contact us](https://www.graphhopper.com/contact-form/) for more details.  #### Geographical Coverage  We offer  - Europe including Russia - North, Central and South America - Saudi Arabia - United Arab Emirates - South Africa - Australia  #### Supported Vehicle Profiles  Name       | Description           | Restrictions              | Icon -----------|:----------------------|:--------------------------|:--------------------------------------------------------- car        | Car mode              | car access                | ![car image](https://graphhopper.com/maps/img/car.png) small_truck| Small truck like a Mercedes Sprinter, Ford Transit or Iveco Daily | height=2.7m, width=2+0.4m, length=5.5m, weight=2080+1400 kg | ![small truck image](https://graphhopper.com/maps/img/small_truck.png)

This PHP package is automatically generated by the [Swagger Codegen](https://github.com/swagger-api/swagger-codegen) project:

- API version: 1.0.0
- Package version: 0.13.0-pre1
- Build package: io.swagger.codegen.v3.generators.php.PhpClientCodegen
For more information, please visit [https://www.graphhopper.com/](https://www.graphhopper.com/)

## Requirements

PHP 5.5 and later

## Installation & Usage
### Composer

To install the bindings via [Composer](http://getcomposer.org/), add the following to `composer.json`:

```
{
  "repositories": [
    {
      "type": "git",
      "url": "https://github.com/graphhopper/directions-api-client.git"
    }
  ],
  "require": {
    "graphhopper/directions-api-client": "*@dev"
  }
}
```

Then run `composer install`

### Manual Installation

Download the files and include `autoload.php`:

```php
    require_once('/path/to/SwaggerClient-php/vendor/autoload.php');
```

## Tests

To run the unit tests:

```
composer install
./vendor/bin/phpunit
```

## Getting Started

Please follow the [installation procedure](#installation--usage) and then run the following:

```php
<?php
require_once(__DIR__ . '/vendor/autoload.php');

// Configure API key authorization: api_key
$config = Swagger\Client\Configuration::getDefaultConfiguration()->setApiKey('key', 'YOUR_API_KEY');
// Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
// $config = Swagger\Client\Configuration::getDefaultConfiguration()->setApiKeyPrefix('key', 'Bearer');

$apiInstance = new Swagger\Client\directions-api-client\GeocodingApi(
    // If you want use custom http client, pass your client which implements `GuzzleHttp\ClientInterface`.
    // This is optional, `GuzzleHttp\Client` will be used as default.
    new GuzzleHttp\Client(),
    $config
);
$q = "q_example"; // string | If you do forward geocoding, this is `required` and is a textual description of the address you are looking for.
$locale = "locale_example"; // string | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
$limit = 56; // int | Specify the maximum number of results to return
$reverse = true; // bool | It is `required` to be `true` if you want to do a reverse geocoding request. If it is `true`, `point` must be defined as well, and `q` must not be used.
$debug = true; // bool | If `true`, the output will be formatted.
$point = "point_example"; // string | _Forward geocoding_: The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803. _Reverse geocoding_: The location to find amenities, cities.
$provider = "provider_example"; // string | The provider parameter is currently under development and can fall back to `default` at any time. The intend is to provide alternatives to our default geocoder. Each provider has its own strenghts and might fit better for certain scenarios, so it's worth to compare the different providers. To try it append the `provider`parameter to the URL like `&provider=nominatim`, the result structure should be identical in all cases - if not, please report this back to us. Keep in mind that some providers do not support certain parameters or don't return some fields, for example `osm_id` and `osm_type` are not supported by every geocoding provider. If you would like to use additional parameters of one of the providers, but it's not available for the GraphHopper Geocoding, yet? Please contact us.  The credit costs can be different for all providers - see [here](https://support.graphhopper.com/support/solutions/articles/44000718211-what-is-one-credit-) for more information about it.  Currently, only the default provider and gisgraphy supports autocompletion of partial search strings.  All providers support normal \"forward\" geocoding and reverse geocoding via `reverse=true`.  #### Default (`provider=default`)  This provider returns results of our internal geocoding engine, as described above.  #### Nominatim (`provider=nominatim`)  The GraphHopper Directions API uses a commercially hosted Nominatim geocoder. You can try this provider [here](https://nominatim.openstreetmap.org/). The provider does **not** fall under the [restrictions](https://operations.osmfoundation.org/policies/nominatim/) of the Nominatim instance hosted by OpenStreetMap.  In addition to the above documented parameters Nominatim allows to use the following parameters, which can be used as documented [here](https://wiki.openstreetmap.org/wiki/Nominatim#Parameters):  * viewbox * viewboxlbrt * bounded  #### OpenCage Data (`provider=opencagedata`)  This provider returns results from the OpenCageData geocoder which you can try [here](https://geocoder.opencagedata.com/demo).  In addition to the above documented parameters OpenCage Data allows to use the following parameters, which can be used as documented [here](https://geocoder.opencagedata.com/api#forward-opt):  * countrycode * bounds  #### Gisgraphy (`provider=gisgraphy`)  This provider returns results from the Gisgraphy geocoder which you can try [here](https://services.gisgraphy.com/static/leaflet/index.html).  **Limitations:** Gisgraphy does not return tags from OSM nor an extent. The locale parameter is currently not supported for Gisgraphy.  Gisgraphy has a special autocomplete API, which you can use by adding `autocomplete=true` (does not work with `reverse=true`). The autocomplete API is optimized on predicting text input, but returns less information.  In addition to the above documented parameters Gisgraphy allows to use the following parameters, which can be used as documented [here](http://www.gisgraphy.com/documentation/user-guide.php):  * radius * country

try {
    $result = $apiInstance->getGeocode($q, $locale, $limit, $reverse, $debug, $point, $provider);
    print_r($result);
} catch (Exception $e) {
    echo 'Exception when calling GeocodingApi->getGeocode: ', $e->getMessage(), PHP_EOL;
}
?>
```

## Documentation for API Endpoints

All URIs are relative to *https://graphhopper.com/api/1*

Class | Method | HTTP request | Description
------------ | ------------- | ------------- | -------------
*GeocodingApi* | [**getGeocode**](docs/Api/GeocodingApi.md#getgeocode) | **GET** /geocode | Execute a geocoding request
*IsochroneApi* | [**getIsochrone**](docs/Api/IsochroneApi.md#getisochrone) | **GET** /isochrone | Isochrone Request
*MapMatchingApi* | [**postGPX**](docs/Api/MapMatchingApi.md#postgpx) | **POST** /match | Map-match a GPX file
*MatrixApi* | [**calculateMatrix**](docs/Api/MatrixApi.md#calculatematrix) | **POST** /matrix/calculate | Post a matrix request in batch mode
*MatrixApi* | [**getMatrix**](docs/Api/MatrixApi.md#getmatrix) | **GET** /matrix | Execute a matrix request
*MatrixApi* | [**getMatrixSolution**](docs/Api/MatrixApi.md#getmatrixsolution) | **GET** /matrix/solution/{jobId} | Retrieve matrix
*MatrixApi* | [**postMatrix**](docs/Api/MatrixApi.md#postmatrix) | **POST** /matrix | Execute a matrix request
*RouteOptimizationApi* | [**getSolution**](docs/Api/RouteOptimizationApi.md#getsolution) | **GET** /vrp/solution/{jobId} | Retrieve solution
*RouteOptimizationApi* | [**solveVRP**](docs/Api/RouteOptimizationApi.md#solvevrp) | **POST** /vrp/optimize | Solve vehicle routing problem
*RoutingApi* | [**getRoute**](docs/Api/RoutingApi.md#getroute) | **GET** /route | Execute a routing request
*RoutingApi* | [**routeInfoGet**](docs/Api/RoutingApi.md#routeinfoget) | **GET** /route/info | Coverage information

## Documentation For Models

 - [Activity](docs/Model/Activity.md)
 - [Address](docs/Model/Address.md)
 - [Algorithm](docs/Model/Algorithm.md)
 - [AnyOfVehicleModelBreak](docs/Model/AnyOfVehicleModelBreak.md)
 - [BadRequest](docs/Model/BadRequest.md)
 - [Configuration](docs/Model/Configuration.md)
 - [CostMatrix](docs/Model/CostMatrix.md)
 - [CostMatrixData](docs/Model/CostMatrixData.md)
 - [CostMatrixDataInfo](docs/Model/CostMatrixDataInfo.md)
 - [Detail](docs/Model/Detail.md)
 - [DriveTimeBreak](docs/Model/DriveTimeBreak.md)
 - [EncodedLineString](docs/Model/EncodedLineString.md)
 - [ErrorMessage](docs/Model/ErrorMessage.md)
 - [GHError](docs/Model/GHError.md)
 - [GHErrorHints](docs/Model/GHErrorHints.md)
 - [GeocodingLocation](docs/Model/GeocodingLocation.md)
 - [GeocodingPoint](docs/Model/GeocodingPoint.md)
 - [GeocodingResponse](docs/Model/GeocodingResponse.md)
 - [GroupRelation](docs/Model/GroupRelation.md)
 - [InfoResponse](docs/Model/InfoResponse.md)
 - [InlineResponse404](docs/Model/InlineResponse404.md)
 - [InternalErrorMessage](docs/Model/InternalErrorMessage.md)
 - [IsochroneResponse](docs/Model/IsochroneResponse.md)
 - [IsochroneResponsePolygon](docs/Model/IsochroneResponsePolygon.md)
 - [IsochroneResponsePolygonProperties](docs/Model/IsochroneResponsePolygonProperties.md)
 - [JobId](docs/Model/JobId.md)
 - [JobRelation](docs/Model/JobRelation.md)
 - [LineString](docs/Model/LineString.md)
 - [MatrixRequest](docs/Model/MatrixRequest.md)
 - [MatrixResponse](docs/Model/MatrixResponse.md)
 - [MatrixResponseHints](docs/Model/MatrixResponseHints.md)
 - [Objective](docs/Model/Objective.md)
 - [Pickup](docs/Model/Pickup.md)
 - [Polygon](docs/Model/Polygon.md)
 - [Request](docs/Model/Request.md)
 - [Response](docs/Model/Response.md)
 - [ResponseAddress](docs/Model/ResponseAddress.md)
 - [ResponseInfo](docs/Model/ResponseInfo.md)
 - [Route](docs/Model/Route.md)
 - [RoutePoint](docs/Model/RoutePoint.md)
 - [RouteResponse](docs/Model/RouteResponse.md)
 - [RouteResponsePath](docs/Model/RouteResponsePath.md)
 - [RouteResponsePathInstructions](docs/Model/RouteResponsePathInstructions.md)
 - [Routing](docs/Model/Routing.md)
 - [Service](docs/Model/Service.md)
 - [Shipment](docs/Model/Shipment.md)
 - [SnappedWaypoint](docs/Model/SnappedWaypoint.md)
 - [Solution](docs/Model/Solution.md)
 - [SolutionUnassigned](docs/Model/SolutionUnassigned.md)
 - [Stop](docs/Model/Stop.md)
 - [SymmetricalMatrixRequest](docs/Model/SymmetricalMatrixRequest.md)
 - [TimeWindow](docs/Model/TimeWindow.md)
 - [TimeWindowBreak](docs/Model/TimeWindowBreak.md)
 - [Vehicle](docs/Model/Vehicle.md)
 - [VehicleProfileId](docs/Model/VehicleProfileId.md)
 - [VehicleType](docs/Model/VehicleType.md)

## Documentation For Authorization


## api_key

- **Type**: API key
- **API key parameter name**: key
- **Location**: URL query string


## Author

support@graphhopper.com

