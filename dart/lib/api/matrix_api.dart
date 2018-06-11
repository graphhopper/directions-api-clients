part of swagger.api;



class MatrixApi {
  final ApiClient apiClient;

  MatrixApi([ApiClient apiClient]) : apiClient = apiClient ?? defaultApiClient;

  /// Matrix API
  ///
  /// The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called &#39;via points&#39;, which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this. 
  Future<MatrixResponse> matrixGet(String key, { List<String> point, List<String> fromPoint, List<String> toPoint, List<String> outArray, String vehicle }) async {
    Object postBody = null;

    // verify required params are set
    if(key == null) {
     throw new ApiException(400, "Missing required param: key");
    }

    // create path and map variables
    String path = "/matrix".replaceAll("{format}","json");

    // query params
    List<QueryParam> queryParams = [];
    Map<String, String> headerParams = {};
    Map<String, String> formParams = {};
    if(point != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("multi", "point", point));
    }
    if(fromPoint != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("multi", "from_point", fromPoint));
    }
    if(toPoint != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("multi", "to_point", toPoint));
    }
    if(outArray != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("multi", "out_array", outArray));
    }
    if(vehicle != null) {
      queryParams.addAll(_convertParametersForCollectionFormat("", "vehicle", vehicle));
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
      return apiClient.deserialize(response.body, 'MatrixResponse') as MatrixResponse ;
    } else {
      return null;
    }
  }
  /// Matrix API Post
  ///
  /// The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request. 
  Future<MatrixResponse> matrixPost(String key, { MatrixRequest body }) async {
    Object postBody = body;

    // verify required params are set
    if(key == null) {
     throw new ApiException(400, "Missing required param: key");
    }

    // create path and map variables
    String path = "/matrix".replaceAll("{format}","json");

    // query params
    List<QueryParam> queryParams = [];
    Map<String, String> headerParams = {};
    Map<String, String> formParams = {};
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
                                             'POST',
                                             queryParams,
                                             postBody,
                                             headerParams,
                                             formParams,
                                             contentType,
                                             authNames);

    if(response.statusCode >= 400) {
      throw new ApiException(response.statusCode, response.body);
    } else if(response.body != null) {
      return apiClient.deserialize(response.body, 'MatrixResponse') as MatrixResponse ;
    } else {
      return null;
    }
  }
}
