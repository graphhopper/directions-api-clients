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
*GeocodingApi* | [**getGeocode**](docs/GeocodingApi.md#getgeocode) | **GET** /geocode | Execute a geocoding request
*IsochroneApi* | [**getIsochrone**](docs/IsochroneApi.md#getisochrone) | **GET** /isochrone | Isochrone Request
*MapMatchingApi* | [**postGPX**](docs/MapMatchingApi.md#postgpx) | **POST** /match | Map-match a GPX file
*MatrixApi* | [**calculateMatrix**](docs/MatrixApi.md#calculatematrix) | **POST** /matrix/calculate | Post a matrix request in batch mode
*MatrixApi* | [**getMatrix**](docs/MatrixApi.md#getmatrix) | **GET** /matrix | Execute a matrix request
*MatrixApi* | [**getMatrixSolution**](docs/MatrixApi.md#getmatrixsolution) | **GET** /matrix/solution/{jobId} | Retrieve matrix
*MatrixApi* | [**postMatrix**](docs/MatrixApi.md#postmatrix) | **POST** /matrix | Execute a matrix request
*RouteOptimizationApi* | [**getSolution**](docs/RouteOptimizationApi.md#getsolution) | **GET** /vrp/solution/{jobId} | Retrieve solution
*RouteOptimizationApi* | [**solveVRP**](docs/RouteOptimizationApi.md#solvevrp) | **POST** /vrp/optimize | Solve vehicle routing problem
*RoutingApi* | [**getRoute**](docs/RoutingApi.md#getroute) | **GET** /route | Execute a routing request
*RoutingApi* | [**routeInfoGet**](docs/RoutingApi.md#routeinfoget) | **GET** /route/info | Coverage information

<a name="documentation-for-models"></a>
## Documentation for Models

 - [io.swagger.client.models.Activity](docs/Activity.md)
 - [io.swagger.client.models.Address](docs/Address.md)
 - [io.swagger.client.models.Algorithm](docs/Algorithm.md)
 - [io.swagger.client.models.AnyOfVehicleBacktickbreakBacktick](docs/AnyOfVehicleBacktickbreakBacktick.md)
 - [io.swagger.client.models.BadRequest](docs/BadRequest.md)
 - [io.swagger.client.models.Configuration](docs/Configuration.md)
 - [io.swagger.client.models.CostMatrix](docs/CostMatrix.md)
 - [io.swagger.client.models.CostMatrixData](docs/CostMatrixData.md)
 - [io.swagger.client.models.CostMatrixDataInfo](docs/CostMatrixDataInfo.md)
 - [io.swagger.client.models.Detail](docs/Detail.md)
 - [io.swagger.client.models.DriveTimeBreak](docs/DriveTimeBreak.md)
 - [io.swagger.client.models.EncodedLineString](docs/EncodedLineString.md)
 - [io.swagger.client.models.ErrorMessage](docs/ErrorMessage.md)
 - [io.swagger.client.models.GHError](docs/GHError.md)
 - [io.swagger.client.models.GHErrorHints](docs/GHErrorHints.md)
 - [io.swagger.client.models.GeocodingLocation](docs/GeocodingLocation.md)
 - [io.swagger.client.models.GeocodingPoint](docs/GeocodingPoint.md)
 - [io.swagger.client.models.GeocodingResponse](docs/GeocodingResponse.md)
 - [io.swagger.client.models.GroupRelation](docs/GroupRelation.md)
 - [io.swagger.client.models.InfoResponse](docs/InfoResponse.md)
 - [io.swagger.client.models.InlineResponse404](docs/InlineResponse404.md)
 - [io.swagger.client.models.InternalErrorMessage](docs/InternalErrorMessage.md)
 - [io.swagger.client.models.IsochroneResponse](docs/IsochroneResponse.md)
 - [io.swagger.client.models.IsochroneResponsePolygon](docs/IsochroneResponsePolygon.md)
 - [io.swagger.client.models.IsochroneResponsePolygonProperties](docs/IsochroneResponsePolygonProperties.md)
 - [io.swagger.client.models.JobId](docs/JobId.md)
 - [io.swagger.client.models.JobRelation](docs/JobRelation.md)
 - [io.swagger.client.models.LineString](docs/LineString.md)
 - [io.swagger.client.models.MatrixRequest](docs/MatrixRequest.md)
 - [io.swagger.client.models.MatrixResponse](docs/MatrixResponse.md)
 - [io.swagger.client.models.MatrixResponseHints](docs/MatrixResponseHints.md)
 - [io.swagger.client.models.Objective](docs/Objective.md)
 - [io.swagger.client.models.Pickup](docs/Pickup.md)
 - [io.swagger.client.models.Polygon](docs/Polygon.md)
 - [io.swagger.client.models.Request](docs/Request.md)
 - [io.swagger.client.models.Response](docs/Response.md)
 - [io.swagger.client.models.ResponseAddress](docs/ResponseAddress.md)
 - [io.swagger.client.models.ResponseInfo](docs/ResponseInfo.md)
 - [io.swagger.client.models.Route](docs/Route.md)
 - [io.swagger.client.models.RoutePoint](docs/RoutePoint.md)
 - [io.swagger.client.models.RouteResponse](docs/RouteResponse.md)
 - [io.swagger.client.models.RouteResponsePath](docs/RouteResponsePath.md)
 - [io.swagger.client.models.RouteResponsePathInstructions](docs/RouteResponsePathInstructions.md)
 - [io.swagger.client.models.Routing](docs/Routing.md)
 - [io.swagger.client.models.Service](docs/Service.md)
 - [io.swagger.client.models.Shipment](docs/Shipment.md)
 - [io.swagger.client.models.SnappedWaypoint](docs/SnappedWaypoint.md)
 - [io.swagger.client.models.Solution](docs/Solution.md)
 - [io.swagger.client.models.SolutionUnassigned](docs/SolutionUnassigned.md)
 - [io.swagger.client.models.Stop](docs/Stop.md)
 - [io.swagger.client.models.SymmetricalMatrixRequest](docs/SymmetricalMatrixRequest.md)
 - [io.swagger.client.models.TimeWindow](docs/TimeWindow.md)
 - [io.swagger.client.models.TimeWindowBreak](docs/TimeWindowBreak.md)
 - [io.swagger.client.models.Vehicle](docs/Vehicle.md)
 - [io.swagger.client.models.VehicleProfileId](docs/VehicleProfileId.md)
 - [io.swagger.client.models.VehicleType](docs/VehicleType.md)

<a name="documentation-for-authorization"></a>
## Documentation for Authorization

<a name="api_key"></a>
### api_key


