# org.openapitools.client - Kotlin client library for GraphHopper Directions API

## Requires

* Kotlin 1.1.2
* Gradle 3.3

## Build

First, create the gradle wrapper script:

```
gradle wrapper
```

Then, run:

```
./gradlew check assemble
```

This runs all tests and packages the library.

## Features/Implementation Notes

* Supports JSON inputs/outputs, File inputs, and Form inputs.
* Supports collection formats for query parameters: csv, tsv, ssv, pipes.
* Some Kotlin and Java types are fully qualified to avoid conflicts with types defined in OpenAPI definitions.
* Implementation of ApiClient is intended to reduce method counts, specifically to benefit Android targets.

<a name="documentation-for-api-endpoints"></a>
## Documentation for API Endpoints

All URIs are relative to *https://graphhopper.com/api/1*

Class | Method | HTTP request | Description
------------ | ------------- | ------------- | -------------
*GeocodingApi* | [**geocodeGet**](docs/GeocodingApi.md#geocodeget) | **GET** /geocode | Execute a Geocoding request
*IsochroneApi* | [**isochroneGet**](docs/IsochroneApi.md#isochroneget) | **GET** /isochrone | Isochrone Request
*MatrixApi* | [**matrixGet**](docs/MatrixApi.md#matrixget) | **GET** /matrix | Matrix API
*MatrixApi* | [**matrixPost**](docs/MatrixApi.md#matrixpost) | **POST** /matrix | Matrix API Post
*RoutingApi* | [**routeGet**](docs/RoutingApi.md#routeget) | **GET** /route | Routing Request
*SolutionApi* | [**getSolution**](docs/SolutionApi.md#getsolution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId
*VrpApi* | [**postVrp**](docs/VrpApi.md#postvrp) | **POST** /vrp/optimize | Solves vehicle routing problems


<a name="documentation-for-models"></a>
## Documentation for Models

 - [org.openapitools.client.models.Activity](docs/Activity.md)
 - [org.openapitools.client.models.Address](docs/Address.md)
 - [org.openapitools.client.models.Algorithm](docs/Algorithm.md)
 - [org.openapitools.client.models.Break](docs/Break.md)
 - [org.openapitools.client.models.Configuration](docs/Configuration.md)
 - [org.openapitools.client.models.CostMatrix](docs/CostMatrix.md)
 - [org.openapitools.client.models.Detail](docs/Detail.md)
 - [org.openapitools.client.models.GHError](docs/GHError.md)
 - [org.openapitools.client.models.GeocodingLocation](docs/GeocodingLocation.md)
 - [org.openapitools.client.models.GeocodingPoint](docs/GeocodingPoint.md)
 - [org.openapitools.client.models.GeocodingResponse](docs/GeocodingResponse.md)
 - [org.openapitools.client.models.IsochroneResponse](docs/IsochroneResponse.md)
 - [org.openapitools.client.models.IsochroneResponsePolygon](docs/IsochroneResponsePolygon.md)
 - [org.openapitools.client.models.JobId](docs/JobId.md)
 - [org.openapitools.client.models.Location](docs/Location.md)
 - [org.openapitools.client.models.MatrixRequest](docs/MatrixRequest.md)
 - [org.openapitools.client.models.MatrixResponse](docs/MatrixResponse.md)
 - [org.openapitools.client.models.Objective](docs/Objective.md)
 - [org.openapitools.client.models.Relation](docs/Relation.md)
 - [org.openapitools.client.models.Request](docs/Request.md)
 - [org.openapitools.client.models.Response](docs/Response.md)
 - [org.openapitools.client.models.ResponseCoordinates](docs/ResponseCoordinates.md)
 - [org.openapitools.client.models.ResponseCoordinatesArray](docs/ResponseCoordinatesArray.md)
 - [org.openapitools.client.models.ResponseInfo](docs/ResponseInfo.md)
 - [org.openapitools.client.models.ResponseInstruction](docs/ResponseInstruction.md)
 - [org.openapitools.client.models.ResponseInstructions](docs/ResponseInstructions.md)
 - [org.openapitools.client.models.Route](docs/Route.md)
 - [org.openapitools.client.models.RoutePoint](docs/RoutePoint.md)
 - [org.openapitools.client.models.RouteResponse](docs/RouteResponse.md)
 - [org.openapitools.client.models.RouteResponsePath](docs/RouteResponsePath.md)
 - [org.openapitools.client.models.Routing](docs/Routing.md)
 - [org.openapitools.client.models.Service](docs/Service.md)
 - [org.openapitools.client.models.Shipment](docs/Shipment.md)
 - [org.openapitools.client.models.Solution](docs/Solution.md)
 - [org.openapitools.client.models.Stop](docs/Stop.md)
 - [org.openapitools.client.models.TimeWindow](docs/TimeWindow.md)
 - [org.openapitools.client.models.Vehicle](docs/Vehicle.md)
 - [org.openapitools.client.models.VehicleType](docs/VehicleType.md)


<a name="documentation-for-authorization"></a>
## Documentation for Authorization

<a name="api_key"></a>
### api_key

- **Type**: API key
- **API key parameter name**: key
- **Location**: URL query string

