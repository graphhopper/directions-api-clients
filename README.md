# API clients for the GraphHopper Directions API

This project contains API clients that were created from [our swagger specification](https://graphhopper.com/api/1/swagger.json) for the different languages.

Please see the successfully created one in the subfolders.

language  |  tested?| alternative
:---------|:--------|:------------
java      |  yes    | Use the [official client](https://github.com/graphhopper/directions-api-java-client)
javascript|  yes    | Use the [official client](https://github.com/graphhopper/directions-api-js-client)
python    |  no     |
csharp    |  no     |
ruby      |  [yes](https://github.com/graphhopper/directions-api-clients-route-optimization/issues/3)   |
sinatra (ruby)| no     |
php       |  [yes](https://github.com/graphhopper/directions-api-clients-route-optimization/issues/4)     |
perl      |  no     |
scala     |  no     |
swift     |  no     | Community contribution for the [Routing](https://github.com/rmnblm/GraphHopperRouting) and [Geocoding](https://github.com/rmnblm/GraphHopperGeocoder) API
objc      |  no     |
tizen     |  no     |
dart      |  no     |
go        |  no     |
clojure   |  no     |
qt5cpp    |  no     |
haskell   |  no     |

tested=yes means we or one of our customers have successfully used the
client for this programming language. 

The Java and JavaScript clients are either handcrafted or the
created versions were further optimized and can be found in the separate,
linked repository.


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
