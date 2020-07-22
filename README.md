
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

## Old Readme

See [old readme](oldreadme.md).
