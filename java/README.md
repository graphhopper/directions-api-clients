# directions-api-client

## Requirements

Building the API client library requires [Maven](https://maven.apache.org/) to be installed.

## Installation

To install the API client library to your local Maven repository, simply execute:

```shell
mvn install
```

To deploy it to a remote Maven repository instead, configure the settings of the repository and execute:

```shell
mvn deploy
```

Refer to the [official documentation](https://maven.apache.org/plugins/maven-deploy-plugin/usage.html) for more information.

### Maven users

Add this dependency to your project's POM:

```xml
<dependency>
    <groupId>com.graphhopper</groupId>
    <artifactId>directions-api-client</artifactId>
    <version>0.9-SNAPSHOT</version>
    <scope>compile</scope>
</dependency>
```

### Gradle users

Add this dependency to your project's build file:

```groovy
compile "com.graphhopper:directions-api-client:0.9-SNAPSHOT"
```

### Others

At first generate the JAR by executing:

    mvn package

Then manually install the following JARs:

* target/directions-api-client-0.9-SNAPSHOT.jar
* target/lib/*.jar

## Getting Started

Please follow the [installation](#installation) instruction and execute the following Java code:

```java

import com.graphhopper.directions.api.client.*;
import com.graphhopper.directions.api.client.auth.*;
import com.graphhopper.directions.api.client.model.*;
import com.graphhopper.directions.api.client.api.GeocodingApi;

import java.io.File;
import java.util.*;

public class GeocodingApiExample {

    public static void main(String[] args) {
        
        GeocodingApi apiInstance = new GeocodingApi();
        String key = "key_example"; // String | Get your key at graphhopper.com
        String q = "q_example"; // String | If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon.
        String locale = "locale_example"; // String | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
        Integer limit = 56; // Integer | Specify the maximum number of returned results
        Boolean reverse = true; // Boolean | Set to true to do a reverse Geocoding request
        String point = "point_example"; // String | The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803
        String provider = "provider_example"; // String | Can be either, default, nominatim, opencagedata
        try {
            GHGeocodingResponse result = apiInstance.geocodeGet(key, q, locale, limit, reverse, point, provider);
            System.out.println(result);
        } catch (ApiException e) {
            System.err.println("Exception when calling GeocodingApi#geocodeGet");
            e.printStackTrace();
        }
    }
}

```

## Documentation for API Endpoints

All URIs are relative to *https://graphhopper.com/api/1*

Class | Method | HTTP request | Description
------------ | ------------- | ------------- | -------------
*GeocodingApi* | [**geocodeGet**](docs/GeocodingApi.md#geocodeGet) | **GET** /geocode | Execute a Geocoding request
*IsochroneApi* | [**isochroneGet**](docs/IsochroneApi.md#isochroneGet) | **GET** /isochrone | Isochrone Request
*MatrixApi* | [**matrixGet**](docs/MatrixApi.md#matrixGet) | **GET** /matrix | Matrix API
*MatrixApi* | [**matrixPost**](docs/MatrixApi.md#matrixPost) | **POST** /matrix | Matrix API Post
*RouteOptimizationApi* | [**getSolution**](docs/RouteOptimizationApi.md#getSolution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId
*RouteOptimizationApi* | [**postVrp**](docs/RouteOptimizationApi.md#postVrp) | **POST** /vrp/optimize | Solves vehicle routing problems
*RoutingApi* | [**routeGet**](docs/RoutingApi.md#routeGet) | **GET** /route | Routing Request


## Documentation for Models

 - [Activity](docs/Activity.md)
 - [Address](docs/Address.md)
 - [Algorithm](docs/Algorithm.md)
 - [CostMatrix](docs/CostMatrix.md)
 - [GHError](docs/GHError.md)
 - [GHErrorHints](docs/GHErrorHints.md)
 - [GHGeocodingLocation](docs/GHGeocodingLocation.md)
 - [GHGeocodingPoint](docs/GHGeocodingPoint.md)
 - [GHGeocodingResponse](docs/GHGeocodingResponse.md)
 - [GHIsochroneResponse](docs/GHIsochroneResponse.md)
 - [GHIsochroneResponsePolygon](docs/GHIsochroneResponsePolygon.md)
 - [GHIsochroneResponsePolygonGeometry](docs/GHIsochroneResponsePolygonGeometry.md)
 - [GHIsochroneResponsePolygonProperties](docs/GHIsochroneResponsePolygonProperties.md)
 - [GHMatrixRequest](docs/GHMatrixRequest.md)
 - [GHMatrixResponse](docs/GHMatrixResponse.md)
 - [GHResponseCoordinates](docs/GHResponseCoordinates.md)
 - [GHResponseCoordinatesArray](docs/GHResponseCoordinatesArray.md)
 - [GHResponseInfo](docs/GHResponseInfo.md)
 - [GHResponseInstruction](docs/GHResponseInstruction.md)
 - [GHResponseInstructions](docs/GHResponseInstructions.md)
 - [GHRouteResponse](docs/GHRouteResponse.md)
 - [GHRouteResponsePath](docs/GHRouteResponsePath.md)
 - [JobId](docs/JobId.md)
 - [ModelBreak](docs/ModelBreak.md)
 - [Objective](docs/Objective.md)
 - [Relation](docs/Relation.md)
 - [Request](docs/Request.md)
 - [Response](docs/Response.md)
 - [Route](docs/Route.md)
 - [Service](docs/Service.md)
 - [Shipment](docs/Shipment.md)
 - [Solution](docs/Solution.md)
 - [SolutionUnassigned](docs/SolutionUnassigned.md)
 - [Stop](docs/Stop.md)
 - [TimeWindow](docs/TimeWindow.md)
 - [Vehicle](docs/Vehicle.md)
 - [VehicleType](docs/VehicleType.md)


## Documentation for Authorization

Authentication schemes defined for the API:
### api_key

- **Type**: API key
- **API key parameter name**: key
- **Location**: URL query string


## Recommendation

It's recommended to create an instance of `ApiClient` per thread in a multithreaded environment to avoid any potential issues.

## Author



