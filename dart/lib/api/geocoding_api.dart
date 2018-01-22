part of swagger.api;



class GeocodingApi {
  final ApiClient apiClient;

  GeocodingApi([ApiClient apiClient]) : apiClient = apiClient ?? defaultApiClient;

  /// Execute a Geocoding request
  ///
  /// This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 
  Future<GeocodingResponse> geocodeGet(String key, { String q, String locale, int limit, bool reverse, String point, String provider }) async {
    Object postBody = null;

    // verify required params are set
    if(key == null) {
     throw new ApiException(400, "Missing required param: key");
    }

    // create path and map variables
    String path = "/geocode".replaceAll("{format}","json");

    // query params
    List<QueryParam> queryParams = [];
    Map<String, String> headerParams = {};
    Map<String, String> formParams = {};
    if(q != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "q", q));
    }
    if(locale != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "locale", locale));
    }
    if(limit != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "limit", limit));
    }
    if(reverse != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "reverse", reverse));
    }
    if(point != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "point", point));
    }
    if(provider != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "provider", provider));
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
      return apiClient.deserialize(response.body, 'GeocodingResponse') as GeocodingResponse ;
    } else {
      return null;
    }
  }
}
