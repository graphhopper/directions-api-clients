# API clients for the GraphHopper Directions API

This project contains API clients that were created from [our swagger specification](https://graphhopper.com/api/1/swagger.json) for the different languages.

Please see the successfully created one in the subfolders.

language  |  tested?| alternative
:---------|:--------|:------------
clojure   |  no     |
cpprest   |  no     |
csharp    |  [partly](https://github.com/graphhopper/directions-api-clients/issues/14) |
dart      |  no     |
go        |  no     |
haskell   |  no     |
java      |  yes    | You can use the optimized [handcoded client](https://github.com/graphhopper/graphhopper/tree/master/client-hc)
javascript|  yes    | Use the [official client](https://github.com/graphhopper/directions-api-js-client)
kotlin	  |  no     |
objc      |  no     |
perl      |  no     |
php       |  [yes](https://github.com/graphhopper/directions-api-clients-route-optimization/issues/4)     |
python    |  no     |
qt5cpp    |  no     |
r         |  no     | Community contribution for the [Routing API](https://www.rdocumentation.org/packages/stplanr/versions/0.2.2/topics/route_graphhopper) (stplanr).
ruby      |  [yes](https://github.com/graphhopper/directions-api-clients-route-optimization/issues/3)   |
rust      |  no     |
scala     |  no     |
sinatra   |  no     |
swift     |  no     | Community contribution for the [Routing](https://github.com/rmnblm/GraphHopperRouting) and [Geocoding](https://github.com/rmnblm/GraphHopperGeocoder) API
symphony  |  -      | Community contribution for the [Geocoding API](https://github.com/Andreas-Schoenefeldt/GraphHopperConnectorBundle)
tizen     |  no     |


`tested=yes` means we or one of our customers have successfully used the
client for this programming language. 

The JavaScript client is handcrafted and can be found in the separate,
linked repository.

The Java client is also available [on maven](http://search.maven.org/#search%7Cga%7C1%7Ca%3A%22directions-api-client%22).


## Supported APIs

Currently the following APIs are supported

 * Routing API (with unencoded polylines only)
 * Geocoding API
 * Matrix API 
 * Isochrone API
 * Route Optimization API

## Build it yourself

Currently we use [swagger codegen](https://github.com/swagger-api/swagger-codegen/) from master
(we'll soon switch to stable 2.4.0) to create the clients. You can easily edit the create.sh script
to specify your own packaged version.

### Update all clients

./create.sh

### Update one client of your choice

./create.sh [yourlanguage]
