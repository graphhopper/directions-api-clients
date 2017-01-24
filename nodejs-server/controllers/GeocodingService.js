'use strict';

exports.geocodeGET = function(args, res, next) {
  /**
   * Execute a Geocoding request
   * This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 
   *
   * key String Get your key at graphhopper.com
   * q String If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon. (optional)
   * locale String Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used. (optional)
   * limit Integer Specify the maximum number of returned results (optional)
   * reverse Boolean Set to true to do a reverse Geocoding request (optional)
   * point String The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803 (optional)
   * provider String Can be either, default, nominatim, opencagedata (optional)
   * returns GHGeocodingResponse
   **/
  var examples = {};
  examples['application/json'] = {
  "hits" : [ {
    "osm_id" : "aeiou",
    "osm_type" : "aeiou",
    "country" : "aeiou",
    "city" : "aeiou",
    "housenumber" : "aeiou",
    "street" : "aeiou",
    "name" : "aeiou",
    "postcode" : "aeiou",
    "state" : "aeiou",
    "point" : {
      "lng" : 1.3579000000000001069366817318950779736042022705078125,
      "lat" : 1.3579000000000001069366817318950779736042022705078125
    }
  } ],
  "locale" : "aeiou"
};
  if (Object.keys(examples).length > 0) {
    res.setHeader('Content-Type', 'application/json');
    res.end(JSON.stringify(examples[Object.keys(examples)[0]] || {}, null, 2));
  } else {
    res.end();
  }
}

