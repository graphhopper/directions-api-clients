part of swagger.api;



class RoutingApi {
  final ApiClient apiClient;

  RoutingApi([ApiClient apiClient]) : apiClient = apiClient ?? defaultApiClient;

  /// Routing Request
  ///
  /// The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions
  Future<RouteResponse> routeGet(List<String> point, bool pointsEncoded, String key, { String locale, bool instructions, String vehicle, bool elevation, bool calcPoints, List<String> pointHint, bool chDisable, String weighting, bool edgeTraversal, String algorithm, int heading, int headingPenalty, bool passThrough, int roundTripDistance, int roundTripSeed, int alternativeRouteMaxPaths, int alternativeRouteMaxWeightFactor, int alternativeRouteMaxShareFactor }) async {
    Object postBody = null;

    // verify required params are set
    if(point == null) {
     throw new ApiException(400, "Missing required param: point");
    }
    if(pointsEncoded == null) {
     throw new ApiException(400, "Missing required param: pointsEncoded");
    }
    if(key == null) {
     throw new ApiException(400, "Missing required param: key");
    }

    // create path and map variables
    String path = "/route".replaceAll("{format}","json");

    // query params
    List<QueryParam> queryParams = [];
    Map<String, String> headerParams = {};
    Map<String, String> formParams = {};
      queryParams.addAll(_convertParametersForCollectionFormat("multi", "point", point));
    if(locale != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "locale", locale));
    }
    if(instructions != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "instructions", instructions));
    }
    if(vehicle != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "vehicle", vehicle));
    }
    if(elevation != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "elevation", elevation));
    }
      queryParams.addAll(_convertParametersForCollectionFormat("", "points_encoded", pointsEncoded));
    if(calcPoints != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "calc_points", calcPoints));
    }
    if(pointHint != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("multi", "point_hint", pointHint));
    }
    if(chDisable != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "ch.disable", chDisable));
    }
    if(weighting != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "weighting", weighting));
    }
    if(edgeTraversal != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "edge_traversal", edgeTraversal));
    }
    if(algorithm != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "algorithm", algorithm));
    }
    if(heading != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "heading", heading));
    }
    if(headingPenalty != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "heading_penalty", headingPenalty));
    }
    if(passThrough != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "pass_through", passThrough));
    }
    if(roundTripDistance != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "round_trip.distance", roundTripDistance));
    }
    if(roundTripSeed != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "round_trip.seed", roundTripSeed));
    }
    if(alternativeRouteMaxPaths != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "alternative_route.max_paths", alternativeRouteMaxPaths));
    }
    if(alternativeRouteMaxWeightFactor != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "alternative_route.max_weight_factor", alternativeRouteMaxWeightFactor));
    }
    if(alternativeRouteMaxShareFactor != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "alternative_route.max_share_factor", alternativeRouteMaxShareFactor));
    }
      queryParams.addAll(_convertParametersForCollectionFormat("", "key", key));
    
    List<String> contentTypes = [];

    String contentType = contentTypes.length > 0 ? contentTypes[0] : "application/json";
    List<String> authNames = [];

    if(contentType.startsWith("multipart/form-data")) {
      bool hasFields = false;
      MultipartRequest mp = new MultipartRequest(null, null);
      
      if(hasFields)
        postBody = mp;
    }
    else {
          }

    var response = await apiClient.invokeAPI(path,
                                             'GET',
                                             queryParams,
                                             postBody,
                                             headerParams,
                                             formParams,
                                             contentType,
                                             authNames);

    if(response.statusCode >= 400) {
      throw new ApiException(response.statusCode, response.body);
    } else if(response.body != null) {
      return apiClient.deserialize(response.body, 'RouteResponse') as RouteResponse ;
    } else {
      return null;
    }
  }
}
