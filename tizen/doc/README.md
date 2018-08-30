# Documentation for GraphHopper Directions API 1.0.0 Tizen Client SDK

## How do I get the doc files?
First generate source code by running `swagger-codegen`
Then run `doc/generateDocumentation.sh` from the output folder. It will generate all the doc files and put them in the `doc/SDK` directory.
To successfully generate documentation it needs `Doxygen` installed in the path.
*Note* - Before generating the documentation, put the logo of the project as the file `doc/logo.png` before running `doxygen`.


## How do I use this?
This is the structure of the doc folder:

```
.
├── logo.png                  \\Logo of the project
├── Doxyfile                  \\Doxygen config files
├── generateDocumentation.sh  \\Script to run to generate documentation
├── README.md                 \\This file
├── SDK                       \\Documentation for all classes in GraphHopper Directions API Tizen Client SDK. See ./html/index.html
│   └── html

```

## *tl;dr* run this:

```
doc/generateDocumentation.sh
```

The above SDK folder will be generated. See the index.html inside the SDK folder.


## What's Doxygen?
Doxygen is the de facto standard tool for generating/extracting documentation from annotated/unannotated C++ sources, but it also supports other popular programming languages such as C, Objective-C, C#, PHP, Java, Python, IDL (Corba, Microsoft, and UNO/OpenOffice flavors), Fortran, VHDL, Tcl, and to some extent D.

Check out [Doxygen](https://www.doxygen.org/) for additional information about the Doxygen project.

## I Don't want to run Doxygen. What are the API files for accessing the REST endpoints?
All URIs are relative to https://graphhopper.comhttps://graphhopper.com/api/1

### GeocodingManager
Method | HTTP request | Description
------------- | ------------- | -------------
*geocodeGetSync* | *GET* /geocode | Execute a Geocoding request.
*geocodeGetASync* | *GET* /geocode | Execute a Geocoding request.

### IsochroneManager
Method | HTTP request | Description
------------- | ------------- | -------------
*isochroneGetSync* | *GET* /isochrone | Isochrone Request.
*isochroneGetASync* | *GET* /isochrone | Isochrone Request.

### MatrixManager
Method | HTTP request | Description
------------- | ------------- | -------------
*matrixGetSync* | *GET* /matrix | Matrix API.
*matrixGetASync* | *GET* /matrix | Matrix API.
*matrixPostSync* | *POST* /matrix | Matrix API Post.
*matrixPostASync* | *POST* /matrix | Matrix API Post.

### RoutingManager
Method | HTTP request | Description
------------- | ------------- | -------------
*routeGetSync* | *GET* /route | Routing Request.
*routeGetASync* | *GET* /route | Routing Request.

### SolutionManager
Method | HTTP request | Description
------------- | ------------- | -------------
*getSolutionSync* | *GET* /vrp/solution/{jobId} | Return the solution associated to the jobId.
*getSolutionASync* | *GET* /vrp/solution/{jobId} | Return the solution associated to the jobId.

### VrpManager
Method | HTTP request | Description
------------- | ------------- | -------------
*postVrpSync* | *POST* /vrp/optimize | Solves vehicle routing problems.
*postVrpASync* | *POST* /vrp/optimize | Solves vehicle routing problems.


## What are the Model files for the data structures/objects?
Class | Description
------------- | -------------
 *Activity* | 
 *Address* | 
 *Break* | 
 *Configuration* | 
 *CostMatrix* | 
 *CostMatrix_data* | JSON data of matrix response
 *CostMatrix_data_info* | Additional information for your request
 *Detail* | 
 *GHError* | 
 *GHError_hints* | 
 *GeocodingLocation* | 
 *GeocodingPoint* | 
 *GeocodingResponse* | 
 *IsochroneResponse* | 
 *IsochroneResponsePolygon* | A found path
 *IsochroneResponsePolygon_geometry* | 
 *IsochroneResponsePolygon_properties* | 
 *JobId* | 
 *Location* | 
 *MatrixRequest* | 
 *MatrixResponse* | 
 *Objective* | 
 *Relation* | 
 *Request* | 
 *Response* | 
 *ResponseCoordinates* | 
 *ResponseCoordinatesArray* | An array containing coordinates
 *ResponseInfo* | Additional information for your request
 *ResponseInstruction* | 
 *ResponseInstructions* | Contains information about the instructions for this route. The last instruction is always the Finish instruction and takes 0ms and 0meter. Keep in mind that instructions are currently under active development and can sometimes contain misleading information, so, make sure you always show an image of the map at the same time when navigating your users!
 *Route* | 
 *RoutePoint* | 
 *RouteResponse* | 
 *RouteResponsePath* | A found path
 *Routing* | 
 *Service* | 
 *Shipment* | 
 *Solution* | 
 *Solution_unassigned* | 
 *Stop* | 
 *TimeWindow* | 
 *Vehicle* | 
 *VehicleType* | 

