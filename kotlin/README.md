# io.swagger.client - Kotlin client library for GraphHopper Directions API

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
* Some Kotlin and Java types are fully qualified to avoid conflicts with types defined in Swagger definitions.
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

 - [io.swagger.client.models.Activity](docs/Activity.md)
 - [io.swagger.client.models.Address](docs/Address.md)
 - [io.swagger.client.models.Algorithm](docs/Algorithm.md)
 - [io.swagger.client.models.Break](docs/Break.md)
 - [io.swagger.client.models.Configuration](docs/Configuration.md)
 - [io.swagger.client.models.CostMatrix](docs/CostMatrix.md)
 - [io.swagger.client.models.CostMatrix_data](docs/CostMatrix_data.md)
 - [io.swagger.client.models.CostMatrix_data_info](docs/CostMatrix_data_info.md)
 - [io.swagger.client.models.Detail](docs/Detail.md)
 - [io.swagger.client.models.GHError](docs/GHError.md)
 - [io.swagger.client.models.GHError_hints](docs/GHError_hints.md)
 - [io.swagger.client.models.GeocodingLocation](docs/GeocodingLocation.md)
 - [io.swagger.client.models.GeocodingPoint](docs/GeocodingPoint.md)
 - [io.swagger.client.models.GeocodingResponse](docs/GeocodingResponse.md)
 - [io.swagger.client.models.IsochroneResponse](docs/IsochroneResponse.md)
 - [io.swagger.client.models.IsochroneResponsePolygon](docs/IsochroneResponsePolygon.md)
 - [io.swagger.client.models.IsochroneResponsePolygon_geometry](docs/IsochroneResponsePolygon_geometry.md)
 - [io.swagger.client.models.IsochroneResponsePolygon_properties](docs/IsochroneResponsePolygon_properties.md)
 - [io.swagger.client.models.JobId](docs/JobId.md)
 - [io.swagger.client.models.Location](docs/Location.md)
 - [io.swagger.client.models.MatrixRequest](docs/MatrixRequest.md)
 - [io.swagger.client.models.MatrixResponse](docs/MatrixResponse.md)
 - [io.swagger.client.models.Objective](docs/Objective.md)
 - [io.swagger.client.models.Relation](docs/Relation.md)
 - [io.swagger.client.models.Request](docs/Request.md)
 - [io.swagger.client.models.Response](docs/Response.md)
 - [io.swagger.client.models.ResponseCoordinates](docs/ResponseCoordinates.md)
 - [io.swagger.client.models.ResponseCoordinatesArray](docs/ResponseCoordinatesArray.md)
 - [io.swagger.client.models.ResponseInfo](docs/ResponseInfo.md)
 - [io.swagger.client.models.ResponseInstruction](docs/ResponseInstruction.md)
 - [io.swagger.client.models.ResponseInstructions](docs/ResponseInstructions.md)
 - [io.swagger.client.models.Route](docs/Route.md)
 - [io.swagger.client.models.RoutePoint](docs/RoutePoint.md)
 - [io.swagger.client.models.RouteResponse](docs/RouteResponse.md)
 - [io.swagger.client.models.RouteResponsePath](docs/RouteResponsePath.md)
 - [io.swagger.client.models.Routing](docs/Routing.md)
 - [io.swagger.client.models.Service](docs/Service.md)
 - [io.swagger.client.models.Shipment](docs/Shipment.md)
 - [io.swagger.client.models.Solution](docs/Solution.md)
 - [io.swagger.client.models.Solution_unassigned](docs/Solution_unassigned.md)
 - [io.swagger.client.models.Stop](docs/Stop.md)
 - [io.swagger.client.models.TimeWindow](docs/TimeWindow.md)
 - [io.swagger.client.models.Vehicle](docs/Vehicle.md)
 - [io.swagger.client.models.VehicleType](docs/VehicleType.md)


<a name="documentation-for-authorization"></a>
## Documentation for Authorization

<a name="api_key"></a>
### api_key

- **Type**: API key
- **API key parameter name**: key
- **Location**: URL query string

