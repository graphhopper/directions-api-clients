
## Deprecated Notice

The sources in this repository are outdated. Instead create fresh sources from [within the browser](https://editor.swagger.io/?url=https://docs.graphhopper.com/openapi.json) (click on 'Generate Client') or via docker:

```
docker run --rm -v "${PWD}:/local" openapitools/openapi-generator-cli generate \
    -i https://docs.graphhopper.com/openapi.json
    -g go \
    -o /local/out/go
```

To improve the naming of the classes you can do the following:

```bash
curl https://docs.graphhopper.com/openapi.yaml | sed -e 's/Matrix API/Matrix/g' | sed -e 's/Routing API/Routing/g' | sed -e 's/Geocoding API/Geocoding/g' | sed -e 's/Route Optimization API/Route Optimization/g' | sed -e 's/Map Matching API/Map Matching/g' | sed -e 's/Isochrone API/Isochrone/g' > openapi.yaml
```

----

## API clients for the GraphHopper Directions API

This project contains API clients that were created from [our OpenAPI specification](https://docs.graphhopper.com/openapi.yaml) for the different languages.

Please see the successfully created clients in the subfolders.

language  |  tested?| alternative
:---------|:--------|:------------
csharp    |  no     |
java      |  no     | You can use the optimized [handcoded client](https://github.com/graphhopper/graphhopper/tree/master/client-hc)
javascript|  no     | Use the [official client](https://github.com/graphhopper/directions-api-js-client)
kotlin	  |  no     |
php       |  no     |
python    |  no     |
r lang    |  no     | See https://github.com/crazycapivara/graphhopper-r
scala     |  no     |
swift4    |  no     | Community contribution for the [Routing](https://github.com/rmnblm/GraphHopperRouting) and [Geocoding](https://github.com/rmnblm/GraphHopperGeocoder) API
symphony  |  -      | Community contribution for the [Geocoding API](https://github.com/Andreas-Schoenefeldt/GraphHopperConnectorBundle)


`tested=yes` means we or one of our customers have successfully used the
client for this programming language. 

The JavaScript client is handcrafted and can be found in the separate, linked repository.

The Java client is also available [on maven](http://search.maven.org/#search%7Cga%7C1%7Ca%3A%22directions-api-client%22).


## Supported APIs

Currently the following APIs are supported

 * Routing API (with unencoded polylines only)
 * Geocoding API
 * Matrix API 
 * Isochrone API
 * Route Optimization API

## Build it yourself

Currently we use [swagger codegen](https://github.com/swagger-api/swagger-codegen/)
3.0.11 to create the clients. You can easily edit the create.sh script
to specify your own packaged version.

### Update all clients

./create.sh

### Update one client of your choice

./create.sh [yourlanguage]
