part of openapi.api;



class IsochroneApi {
  final ApiClient apiClient;

  IsochroneApi([ApiClient apiClient]) : apiClient = apiClient ?? defaultApiClient;

  /// Isochrone Request
  ///
  /// The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate &#39;a line connecting points at which a vehicle arrives at the same time,&#39; see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 
  Future<IsochroneResponse> isochroneGet(String point, String key, { int timeLimit, int distanceLimit, String vehicle, int buckets, bool reverseFlow, String weighting }) async {
    Object postBody = null;

    // verify required params are set
    if(point == null) {
     throw new ApiException(400, "Missing required param: point");
    }
    if(key == null) {
     throw new ApiException(400, "Missing required param: key");
    }

    // create path and map variables
    String path = "/isochrone".replaceAll("{format}","json");

    // query params
    List<QueryParam> queryParams = [];
    Map<String, String> headerParams = {};
    Map<String, String> formParams = {};
      queryParams.addAll(_convertParametersForCollectionFormat("", "point", point));
    if(timeLimit != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "time_limit", timeLimit));
    }
    if(distanceLimit != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "distance_limit", distanceLimit));
    }
    if(vehicle != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "vehicle", vehicle));
    }
    if(buckets != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "buckets", buckets));
    }
    if(reverseFlow != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "reverse_flow", reverseFlow));
    }
    if(weighting != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "weighting", weighting));
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
      return apiClient.deserialize(response.body, 'IsochroneResponse') as IsochroneResponse;
    } else {
      return null;
    }
  }
}
