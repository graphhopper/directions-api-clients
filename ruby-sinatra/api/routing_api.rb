require 'json'


MyApp.add_route('GET', '/api/1/route', {
  "resourcePath" => "/Routing",
  "summary" => "Routing Request",
  "nickname" => "route_get", 
  "responseClass" => "RouteResponse", 
  "endpoint" => "/route", 
  "notes" => "The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions",
  "parameters" => [
    {
      "name" => "point",
      "description" => "Specify multiple points for which the route should be calculated. The order is important. Specify at least two points.",
      "dataType" => "array[string]",
      "collectionFormat" => "multi",
      "paramType" => "query",
    },
    {
      "name" => "locale",
      "description" => "The locale of the resulting turn instructions. E.g. &#x60;pt_PT&#x60; for Portuguese or &#x60;de&#x60; for German",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "instructions",
      "description" => "If instruction should be calculated and returned",
      "dataType" => "boolean",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "vehicle",
      "description" => "The vehicle for which the route should be calculated. Other vehicles are foot, small_truck, ...",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "elevation",
      "description" => "If &#x60;true&#x60; a third dimension - the elevation - is included in the polyline or in the GeoJson. If enabled you have to use a modified version of the decoding method or set points_encoded to &#x60;false&#x60;. See the points_encoded attribute for more details. Additionally a request can fail if the vehicle does not support elevation. See the features object for every vehicle.",
      "dataType" => "boolean",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "points_encoded",
      "description" => "IMPORTANT- TODO - currently you have to pass false for the swagger client - Have not found a way to force add a parameter. If &#x60;false&#x60; the coordinates in &#x60;point&#x60; and &#x60;snapped_waypoints&#x60; are returned as array using the order [lon,lat,elevation] for every point. If &#x60;true&#x60; the coordinates will be encoded as string leading to less bandwith usage. You&#39;ll need a special handling for the decoding of this string on the client-side. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/java/com/graphhopper/http/WebHelper.java#L43) and [JavaScript](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/webapp/js/ghrequest.js#L139). It is especially important to use no 3rd party client if you set &#x60;elevation&#x3D;true&#x60;!",
      "dataType" => "boolean",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "calc_points",
      "description" => "If the points for the route should be calculated at all printing out only distance and time.",
      "dataType" => "boolean",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "point_hint",
      "description" => "Optional parameter. Specifies a hint for each &#x60;point&#x60; parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up.",
      "dataType" => "array[string]",
      "collectionFormat" => "multi",
      "paramType" => "query",
    },
    {
      "name" => "ch/disable",
      "description" => "Use this parameter in combination with one or more parameters of this table",
      "dataType" => "boolean",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "weighting",
      "description" => "Which kind of &#39;best&#39; route calculation you need. Other option is &#x60;shortest&#x60; (e.g. for &#x60;vehicle&#x3D;foot&#x60; or &#x60;bike&#x60;), &#x60;short_fastest&#x60; if time and distance is expensive e.g. for &#x60;vehicle&#x3D;truck&#x60;",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "edge_traversal",
      "description" => "Use &#x60;true&#x60; if you want to consider turn restrictions for bike and motor vehicles. Keep in mind that the response time is roughly 2 times slower.",
      "dataType" => "boolean",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "algorithm",
      "description" => "The algorithm to calculate the route. Other options are &#x60;dijkstra&#x60;, &#x60;astar&#x60;, &#x60;astarbi&#x60;, &#x60;alternative_route&#x60; and &#x60;round_trip&#x60;",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "heading",
      "description" => "Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with &#x60;algorithm&#x3D;round_trip&#x60; and force the initial direction.",
      "dataType" => "int",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "heading_penalty",
      "description" => "Penalty for omitting a specified heading. The penalty corresponds to the accepted time delay in seconds in comparison to the route without a heading.",
      "dataType" => "int",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "pass_through",
      "description" => "If &#x60;true&#x60; u-turns are avoided at via-points with regard to the &#x60;heading_penalty&#x60;.",
      "dataType" => "boolean",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "details",
      "description" => "List of additional trip attributes to be returned. Try some of the following: &#x60;average_speed&#x60;, &#x60;street_name&#x60;, &#x60;edge_id&#x60;, &#x60;time&#x60;, &#x60;distance&#x60;.",
      "dataType" => "array[string]",
      "collectionFormat" => "multi",
      "paramType" => "query",
    },
    {
      "name" => "round_trip/distance",
      "description" => "If &#x60;algorithm&#x3D;round_trip&#x60; this parameter configures approximative length of the resulting round trip",
      "dataType" => "int",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "round_trip/seed",
      "description" => "If &#x60;algorithm&#x3D;round_trip&#x60; this parameter introduces randomness if e.g. the first try wasn&#39;t good.",
      "dataType" => "int",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "alternative_route/max_paths",
      "description" => "If &#x60;algorithm&#x3D;alternative_route&#x60; this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.",
      "dataType" => "int",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "alternative_route/max_weight_factor",
      "description" => "If &#x60;algorithm&#x3D;alternative_route&#x60; this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.",
      "dataType" => "int",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "alternative_route/max_share_factor",
      "description" => "If &#x60;algorithm&#x3D;alternative_route&#x60; this parameter specifies how much alternatives routes can have maximum in common with the optimal route. Increasing can lead to worse alternatives.",
      "dataType" => "int",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "avoid",
      "description" => "comma separate list to avoid certain roads. You can avoid motorway, ferry, tunnel or track",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "key",
      "description" => "Get your key at graphhopper.com",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    ]}) do
  cross_origin
  # the guts live here

  {"message" => "yes, it worked"}.to_json
end

