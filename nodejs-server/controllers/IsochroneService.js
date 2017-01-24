'use strict';

exports.isochroneGET = function(args, res, next) {
  /**
   * Isochrone Request
   * The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 
   *
   * point String Specify the start coordinate
   * key String Get your key at graphhopper.com
   * time_limit Integer Specify which time the vehicle should travel. In seconds. The maximum depends on the subscribed package. (optional)
   * vehicle String Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) (optional)
   * buckets Integer For how many sub intervals an additional polygon should be calculated. (optional)
   * reverse_flow Boolean If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.* (optional)
   * returns GHIsochroneResponse
   **/
  var examples = {};
  examples['application/json'] = {
  "polygons" : [ {
    "geometry" : {
      "coordinates" : "",
      "type" : "aeiou"
    },
    "type" : "aeiou",
    "properties" : {
      "bucket" : 123
    }
  } ],
  "copyrights" : [ "aeiou" ]
};
  if (Object.keys(examples).length > 0) {
    res.setHeader('Content-Type', 'application/json');
    res.end(JSON.stringify(examples[Object.keys(examples)[0]] || {}, null, 2));
  } else {
    res.end();
  }
}

