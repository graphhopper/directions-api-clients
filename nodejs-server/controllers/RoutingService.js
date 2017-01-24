'use strict';

exports.routeGET = function(args, res, next) {
  /**
   * Routing Request
   * The GraphHopper Routing API allows to calculate routes. 
   *
   * point List Specify multiple points for which the route should be calculated. The order is important. Specify at least two points.
   * points_encoded Boolean IMPORTANT- TODO - currently you have to pass false for the swagger client - Have not found a way to force add a parameter. If `false` the coordinates in `point` and `snapped_waypoints` are returned as array using the order [lon,lat,elevation] for every point. If `true` the coordinates will be encoded as string leading to less bandwith usage. You'll need a special handling for the decoding of this string on the client-side. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/java/com/graphhopper/http/WebHelper.java#L43) and [JavaScript](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/webapp/js/ghrequest.js#L139). It is especially important to use no 3rd party client if you set `elevation=true`!
   * key String Get your key at graphhopper.com
   * locale String The locale of the resulting turn instructions. E.g. `pt_PT` for Portuguese or `de` for German (optional)
   * instructions Boolean If instruction should be calculated and returned (optional)
   * vehicle String The vehicle for which the route should be calculated. Other vehicles are foot, bike, motorcycle, hike, ... (optional)
   * elevation Boolean If `true` a third dimension - the elevation - is included in the polyline or in the GeoJson. If enabled you have to use a modified version of the decoding method or set points_encoded to `false`. See the points_encoded attribute for more details. Additionally a request can fail if the vehicle does not support elevation. See the features object for every vehicle. (optional)
   * calc_points Boolean If the points for the route should be calculated at all printing out only distance and time. (optional)
   * point_hint List Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. (optional)
   * ch.disable Boolean Use this parameter in combination with one or more parameters of this table (optional)
   * weighting String Which kind of 'best' route calculation you need. Other option is `shortest` (e.g. for `vehicle=foot` or `bike`), `short_fastest` if time and distance is expensive (e.g. for `vehicle=truck`) and `curvature` (only for `vehicle=motorcycle`) (optional)
   * edge_traversal Boolean Use `true` if you want to consider turn restrictions for bike and motor vehicles. Keep in mind that the response time is roughly 2 times slower. (optional)
   * algorithm String The algorithm to calculate the route. Other options are `dijkstra`, `astar`, `astarbi`, `alternative_route` and `round_trip` (optional)
   * heading Integer Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with `algorithm=round_trip` and force the initial direction. (optional)
   * heading_penalty Integer Penalty for omitting a specified heading. The penalty corresponds to the accepted time delay in seconds in comparison to the route without a heading. (optional)
   * pass_through Boolean If `true` u-turns are avoided at via-points with regard to the `heading_penalty`. (optional)
   * round_trip.distance Integer If `algorithm=round_trip` this parameter configures approximative length of the resulting round trip (optional)
   * round_trip.seed Long If `algorithm=round_trip` this parameter introduces randomness if e.g. the first try wasn't good. (optional)
   * alternative_route.max_paths Integer If `algorithm=alternative_route` this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. (optional)
   * alternative_route.max_weight_factor Integer If `algorithm=alternative_route` this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. (optional)
   * alternative_route.max_share_factor Integer If `algorithm=alternative_route` this parameter specifies how much alternatives routes can have maximum in common with the optimal route. Increasing can lead to worse alternatives. (optional)
   * returns GHRouteResponse
   **/
  var examples = {};
  examples['application/json'] = {
  "paths" : [ {
    "descend" : 1.3579000000000001069366817318950779736042022705078125,
    "instructions" : "",
    "ascend" : 1.3579000000000001069366817318950779736042022705078125,
    "distance" : 1.3579000000000001069366817318950779736042022705078125,
    "bbox" : [ 1.3579000000000001069366817318950779736042022705078125 ],
    "time" : 123456789,
    "points_encoded" : true,
    "points" : {
      "coordinates" : ""
    },
    "snapped_waypoints" : ""
  } ],
  "info" : {
    "took" : 123,
    "copyrights" : [ "aeiou" ]
  }
};
  if (Object.keys(examples).length > 0) {
    res.setHeader('Content-Type', 'application/json');
    res.end(JSON.stringify(examples[Object.keys(examples)[0]] || {}, null, 2));
  } else {
    res.end();
  }
}

