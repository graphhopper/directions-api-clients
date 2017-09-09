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
    <version>0.10-SNAPSHOT</version>
    <scope>compile</scope>
</dependency>
```

### Gradle users

Add this dependency to your project's build file:

```groovy
compile "com.graphhopper:directions-api-client:0.10-SNAPSHOT"
```

### Others

At first generate the JAR by executing:

    mvn package

Then manually install the following JARs:

* target/directions-api-client-0.10-SNAPSHOT.jar
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
            GeocodingResponse result = apiInstance.geocodeGet(key, q, locale, limit, reverse, point, provider);
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
*RoutingApi* | [**routeGet**](docs/RoutingApi.md#routeGet) | **GET** /route | Routing Request
*SolutionApi* | [**getSolution**](docs/SolutionApi.md#getSolution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId
*VrpApi* | [**postVrp**](docs/VrpApi.md#postVrp) | **POST** /vrp/optimize | Solves vehicle routing problems


## Documentation for Models

 - [Activity](docs/Activity.md)
 - [Address](docs/Address.md)
 - [Algorithm](docs/Algorithm.md)
 - [CostMatrix](docs/CostMatrix.md)
 - [CostMatrixData](docs/CostMatrixData.md)
 - [CostMatrixDataInfo](docs/CostMatrixDataInfo.md)
 - [GHError](docs/GHError.md)
 - [GHErrorHints](docs/GHErrorHints.md)
 - [GeocodingLocation](docs/GeocodingLocation.md)
 - [GeocodingPoint](docs/GeocodingPoint.md)
 - [GeocodingResponse](docs/GeocodingResponse.md)
 - [IsochroneResponse](docs/IsochroneResponse.md)
 - [IsochroneResponsePolygon](docs/IsochroneResponsePolygon.md)
 - [IsochroneResponsePolygonGeometry](docs/IsochroneResponsePolygonGeometry.md)
 - [IsochroneResponsePolygonProperties](docs/IsochroneResponsePolygonProperties.md)
 - [JobId](docs/JobId.md)
 - [Location](docs/Location.md)
 - [MatrixRequest](docs/MatrixRequest.md)
 - [MatrixResponse](docs/MatrixResponse.md)
 - [ModelBreak](docs/ModelBreak.md)
 - [ModelConfiguration](docs/ModelConfiguration.md)
 - [Objective](docs/Objective.md)
 - [Relation](docs/Relation.md)
 - [Request](docs/Request.md)
 - [Response](docs/Response.md)
 - [ResponseCoordinates](docs/ResponseCoordinates.md)
 - [ResponseCoordinatesArray](docs/ResponseCoordinatesArray.md)
 - [ResponseInfo](docs/ResponseInfo.md)
 - [ResponseInstruction](docs/ResponseInstruction.md)
 - [ResponseInstructions](docs/ResponseInstructions.md)
 - [Route](docs/Route.md)
 - [RoutePoint](docs/RoutePoint.md)
 - [RouteResponse](docs/RouteResponse.md)
 - [RouteResponsePath](docs/RouteResponsePath.md)
 - [Routing](docs/Routing.md)
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



