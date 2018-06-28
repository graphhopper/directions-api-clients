part of openapi.api;



class SolutionApi {
  final ApiClient apiClient;

  SolutionApi([ApiClient apiClient]) : apiClient = apiClient ?? defaultApiClient;

  /// Return the solution associated to the jobId
  ///
  /// This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 
  Future<Response> getSolution(String key, String jobId) async {
    Object postBody = null;

    // verify required params are set
    if(key == null) {
     throw new ApiException(400, "Missing required param: key");
    }
    if(jobId == null) {
     throw new ApiException(400, "Missing required param: jobId");
    }

    // create path and map variables
    String path = "/vrp/solution/{jobId}".replaceAll("{format}","json").replaceAll("{" + "jobId" + "}", jobId.toString());

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
      return apiClient.deserialize(response.body, 'Response') as Response;
    } else {
      return null;
    }
  }
}
