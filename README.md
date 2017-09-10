# API clients for the GraphHopper Directions API

This project contains API clients that were created from [our swagger specification](https://graphhopper.com/api/1/swagger.json) for the different languages.

Please see the successfully created one in the subfolders.

language  |  tested?| alternative
:---------|:--------|:------------
clojure   |  no     |
csharp    |  no     |
go        |  no     |
haskell   |  no     |
java      |  yes    | You can use the optimized [handcoded client](https://github.com/graphhopper/graphhopper/tree/master/client-hc) for some APIs.
javascript|  yes    | Use the [official client](https://github.com/graphhopper/directions-api-js-client)
objc      |  no     |
perl      |  no     |
php       |  [yes](https://github.com/graphhopper/directions-api-clients-route-optimization/issues/4)     |
python    |  no     |
qt5cpp    |  no     |
ruby      |  [yes](https://github.com/graphhopper/directions-api-clients-route-optimization/issues/3)   |
scala     |  no     |
swift     |  no     | Community contribution for the [Routing](https://github.com/rmnblm/GraphHopperRouting) and [Geocoding](https://github.com/rmnblm/GraphHopperGeocoder) API
tizen     |  no     |


tested=yes means we or one of our customers have successfully used the
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

Currently we use swagger codegen 2.2.2 to create the clients but you can
easily edit the create.sh script.

### Update all clients

./create.sh

### Update one client of your choice

./create.sh [yourlanguage]
