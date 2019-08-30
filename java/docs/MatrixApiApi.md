# MatrixApiApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**calculateMatrix**](MatrixApiApi.md#calculateMatrix) | **POST** /matrix/calculate | Post a matrix request in batch mode
[**getMatrix**](MatrixApiApi.md#getMatrix) | **GET** /matrix | Execute a matrix request
[**getMatrixSolution**](MatrixApiApi.md#getMatrixSolution) | **GET** /matrix/solution/{jobId} | Retrieve matrix
[**postMatrix**](MatrixApiApi.md#postMatrix) | **POST** /matrix | Execute a matrix request

<a name="calculateMatrix"></a>
# **calculateMatrix**
> JobId calculateMatrix(body)

Post a matrix request in batch mode

The Batch Matrix API allows using matrices with more locations and works asynchronously - similar to our Route Optimization API:  * Create a HTTP POST request against &#x60;/matrix/calculate&#x60; and add the key in the URL: &#x60;/matrix/calculate?key&#x3D;[YOUR_KEY]&#x60;. This will give you the &#x60;job_id&#x60; from the response json like &#x60;{ \&quot;job_id\&quot;: \&quot;7ac65787-fb99-4e02-a832-2c3010c70097\&quot; }&#x60;  * Poll via HTTP GET requests every second against &#x60;/matrix/solution/[job_id]&#x60;  Here are some full examples via curl: &#x60;&#x60;&#x60;bash $ curl -X POST -H \&quot;Content-Type: application/json\&quot; \&quot;https://graphhopper.com/api/1/matrix/calculate?key&#x3D;[YOUR_KEY]\&quot; -d &#x27;{\&quot;points\&quot;:[[13.29895,52.48696],[13.370876,52.489575],[13.439026,52.511206]]}&#x27; {\&quot;job_id\&quot;:\&quot;7ac65787-fb99-4e02-a832-2c3010c70097\&quot;} &#x60;&#x60;&#x60;  Pick the returned &#x60;job_id&#x60; and use it in the next GET requests: &#x60;&#x60;&#x60;bash $ curl -X GET \&quot;https://graphhopper.com/api/1/matrix/solution/7ac65787-fb99-4e02-a832-2c3010c70097?key&#x3D;[YOUR_KEY]\&quot; {\&quot;status\&quot;:\&quot;waiting\&quot;} &#x60;&#x60;&#x60;  When the calculation is finished (&#x60;status:finished&#x60;) the JSON response will contain the full matrix JSON under &#x60;solution&#x60;: &#x60;&#x60;&#x60;bash $ curl -X GET \&quot;https://graphhopper.com/api/1/matrix/solution/7ac65787-fb99-4e02-a832-2c3010c70097?key&#x3D;[YOUR_KEY]\&quot; {\&quot;solution\&quot;:{\&quot;weights\&quot;:[[0.0,470.453,945.414],[503.793,0.0,580.871],[970.49,569.511,0.0]],\&quot;info\&quot;:{\&quot;copyrights\&quot;:[\&quot;GraphHopper\&quot;,\&quot;OpenStreetMap contributors\&quot;]}},\&quot;status\&quot;:\&quot;finished\&quot;} &#x60;&#x60;&#x60;  Please note that if an error occured while calculation the JSON will not have a status but contain directly the error message e.g.: &#x60;&#x60;&#x60;json {\&quot;message\&quot;:\&quot;Cannot find from_points: 1\&quot;,\&quot;hints\&quot;:[{...}]} &#x60;&#x60;&#x60; 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiClient;
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.Configuration;
//import com.graphhopper.directions.api.client.auth.*;
//import com.graphhopper.directions.api.client.tmp.MatrixApiApi;

ApiClient defaultClient = Configuration.getDefaultApiClient();

// Configure API key authorization: api_key
ApiKeyAuth api_key = (ApiKeyAuth) defaultClient.getAuthentication("api_key");
api_key.setApiKey("YOUR API KEY");
// Uncomment the following line to set a prefix for the API key, e.g. "Token" (defaults to null)
//api_key.setApiKeyPrefix("Token");

MatrixApiApi apiInstance = new MatrixApiApi();
Object body = null; // Object | 
try {
    JobId result = apiInstance.calculateMatrix(body);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling MatrixApiApi#calculateMatrix");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**Object**](Object.md)|  | [optional]

### Return type

[**JobId**](JobId.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

<a name="getMatrix"></a>
# **getMatrix**
> MatrixResponse getMatrix(point, fromPoint, toPoint, pointHint, fromPointHint, toPointHint, snapPrevention, outArray, vehicle, failFast)

Execute a matrix request

### Introduction  ![Matrix Example](./img/matrix-example.png)  The Matrix API is part of the [GraphHopper Directions API](https://graphhopper.com/#directions-api) and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times.  In the [Routing API](#tag/Routing-API) we support multiple points, so called &#x27;via points&#x27;, which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the [GraphHopper Route Optimization API](#tag/Route-Optimization-API) uses the Matrix API under the hood to achieve this.  Some other use case scenarios for the Matrix API:   * Logistic problems often pick up many items from and deliver them to many locations.  * Calculating detours with many possible points in-between and selecting the best e.g. interesting for ridesharing or taxi applications. For this 1-to-many requests are necessary.  * Finding the best tour for a tourist in the need to visit as many points of interests as possible.  * ...  ### API Clients and Examples  See the [clients](#section/API-Clients) section in the main document and [live examples](https://graphhopper.com/api/1/examples/#matrix).  ### Description  The Matrix API calculates the well known distance-matrix for a set of points, i.e. it calculates all the distances between every point combination. But we do not stop there, we also offer a time-, weight- and route-matrix. The weight-matrix can be used as raw input for e.g. a vehicle routing problem ([VRP](http://en.wikipedia.org/wiki/Vehicle_routing_problem)) and is more precise than a time- or distance-matrix. E.g. for bike routes the actual weight of a route (e.g. the \&quot;beauty\&quot;) is what you want to decide if a route is &#x27;better&#x27; and not always the taken time or distance.  A simple illustration for a 3x3 matrix with identical from and to points:   -          |to_point1|to_point2|to_point3 :-----------|:--------|:--------|:-------- from_point1 |0        |1-&gt;2     | 1-&gt;3 from_point2 |2-&gt;1     |0        | 2-&gt;3 from_point3 |3-&gt;1     |3-&gt;2     | 0  A simple illustration for a 1x3 matrix with different start- and end-points:   -          | to_point1  | to_point2 | t_point3 :-----------|:-----------|:----------|:-------- from_pointA |A-&gt;1        |A-&gt;2       |A-&gt;3   For every route 1-&gt;2, 1-3, ... or A-&gt;1,A-&gt;2,A-&gt;3 you can return only the weight, the time and the distance. To calculate full routes you can use the [Routing API](#tag/Routing-API) which also has a lot of different parameters.  ### Limits and Counts  The cost for one request depends on the number of locations and is documented [here](https://graphhopper.com/api/1/docs/FAQ/#what-is-one-credit).  One request should not exceed the Matrix API location limit depending on the package, see the pricing in our dashboard. 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiClient;
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.Configuration;
//import com.graphhopper.directions.api.client.auth.*;
//import com.graphhopper.directions.api.client.tmp.MatrixApiApi;

ApiClient defaultClient = Configuration.getDefaultApiClient();

// Configure API key authorization: api_key
ApiKeyAuth api_key = (ApiKeyAuth) defaultClient.getAuthentication("api_key");
api_key.setApiKey("YOUR API KEY");
// Uncomment the following line to set a prefix for the API key, e.g. "Token" (defaults to null)
//api_key.setApiKeyPrefix("Token");

MatrixApiApi apiInstance = new MatrixApiApi();
List<String> point = Arrays.asList("point_example"); // List<String> | Specify multiple points in `latitude,longitude` for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point.
List<String> fromPoint = Arrays.asList("fromPoint_example"); // List<String> | The starting points for the routes in `latitude,longitude`. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters.
List<String> toPoint = Arrays.asList("toPoint_example"); // List<String> | The destination points for the routes in `latitude,longitude`.
List<String> pointHint = Arrays.asList("pointHint_example"); // List<String> | Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up.
List<String> fromPointHint = Arrays.asList("fromPointHint_example"); // List<String> | For the from_point parameter. See point_hint
List<String> toPointHint = Arrays.asList("toPointHint_example"); // List<String> | For the to_point parameter. See point_hint
List<String> snapPrevention = Arrays.asList("snapPrevention_example"); // List<String> | Optional parameter to avoid snapping to a certain road class or road environment. Current supported values `motorway`, `trunk`, `ferry`, `tunnel`, `bridge` and `ford`. Multiple values are specified like `snap_prevention=ferry&snap_prevention=motorway` 
List<String> outArray = Arrays.asList("outArray_example"); // List<String> | Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
VehicleProfileId vehicle = new VehicleProfileId(); // VehicleProfileId | The vehicle profile for which the matrix should be calculated.
Boolean failFast = true; // Boolean | Specifies whether or not the matrix calculation should return with an error as soon as possible in case some points cannot be found or some points are not connected. If set to `false` the time/weight/distance matrix will be calculated for all valid points and contain the `null` value for all entries that could not be calculated. The `hint` field of the response will also contain additional information about what went wrong (see its documentation).
try {
    MatrixResponse result = apiInstance.getMatrix(point, fromPoint, toPoint, pointHint, fromPointHint, toPointHint, snapPrevention, outArray, vehicle, failFast);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling MatrixApiApi#getMatrix");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | [**List&lt;String&gt;**](String.md)| Specify multiple points in &#x60;latitude,longitude&#x60; for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. | [optional]
 **fromPoint** | [**List&lt;String&gt;**](String.md)| The starting points for the routes in &#x60;latitude,longitude&#x60;. E.g. if you want to calculate the three routes A-&amp;gt;1, A-&amp;gt;2, A-&amp;gt;3 then you have one from_point parameter and three to_point parameters. | [optional]
 **toPoint** | [**List&lt;String&gt;**](String.md)| The destination points for the routes in &#x60;latitude,longitude&#x60;. | [optional]
 **pointHint** | [**List&lt;String&gt;**](String.md)| Optional parameter. Specifies a hint for each &#x60;point&#x60; parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. | [optional]
 **fromPointHint** | [**List&lt;String&gt;**](String.md)| For the from_point parameter. See point_hint | [optional]
 **toPointHint** | [**List&lt;String&gt;**](String.md)| For the to_point parameter. See point_hint | [optional]
 **snapPrevention** | [**List&lt;String&gt;**](String.md)| Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  | [optional]
 **outArray** | [**List&lt;String&gt;**](String.md)| Specifies which arrays should be included in the response. Specify one or more of the following options &#x27;weights&#x27;, &#x27;times&#x27;, &#x27;distances&#x27;. To specify more than one array use e.g. out_array&#x3D;times&amp;out_array&#x3D;distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. | [optional]
 **vehicle** | [**VehicleProfileId**](.md)| The vehicle profile for which the matrix should be calculated. | [optional]
 **failFast** | **Boolean**| Specifies whether or not the matrix calculation should return with an error as soon as possible in case some points cannot be found or some points are not connected. If set to &#x60;false&#x60; the time/weight/distance matrix will be calculated for all valid points and contain the &#x60;null&#x60; value for all entries that could not be calculated. The &#x60;hint&#x60; field of the response will also contain additional information about what went wrong (see its documentation). | [optional]

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

<a name="getMatrixSolution"></a>
# **getMatrixSolution**
> MatrixResponse getMatrixSolution(jobId)

Retrieve matrix

This endpoint returns the solution of posted matrix request. You can fetch it with the job_id, you have been sent. 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiClient;
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.Configuration;
//import com.graphhopper.directions.api.client.auth.*;
//import com.graphhopper.directions.api.client.tmp.MatrixApiApi;

ApiClient defaultClient = Configuration.getDefaultApiClient();

// Configure API key authorization: api_key
ApiKeyAuth api_key = (ApiKeyAuth) defaultClient.getAuthentication("api_key");
api_key.setApiKey("YOUR API KEY");
// Uncomment the following line to set a prefix for the API key, e.g. "Token" (defaults to null)
//api_key.setApiKeyPrefix("Token");

MatrixApiApi apiInstance = new MatrixApiApi();
String jobId = "jobId_example"; // String | Request solution with jobId
try {
    MatrixResponse result = apiInstance.getMatrixSolution(jobId);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling MatrixApiApi#getMatrixSolution");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **jobId** | **String**| Request solution with jobId |

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

<a name="postMatrix"></a>
# **postMatrix**
> MatrixResponse postMatrix(body)

Execute a matrix request

The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key. Both request scenarios are identical except that all singular parameter names are named as their plural for a POST request. All effected parameters are: &#x60;points&#x60;, &#x60;from_points&#x60;, &#x60;to_points&#x60;, and &#x60;out_array&#x60;.  *Please note that in opposite to the GET endpoint, points are specified in &#x60;longitude, latitude&#x60;*.  For example &#x60;point&#x3D;10,11&amp;point&#x3D;20,22&#x60; will be converted to the following JSON &#x60;points&#x60; array: &#x60;&#x60;&#x60;json { \&quot;points\&quot;: [[11,10], [22,20]] } &#x60;&#x60;&#x60; Note that also the order changes to &#x60;[longitude,latitude]&#x60; similar to [GeoJson](http://geojson.org/geojson-spec.html#examples).  Example: &#x60;&#x60;&#x60;bash curl -X POST -H \&quot;Content-Type: application/json\&quot; \&quot;https://graphhopper.com/api/1/matrix?key&#x3D;[YOUR_KEY]\&quot; -d &#x27;{\&quot;elevation\&quot;:false,\&quot;out_arrays\&quot;:[\&quot;weights\&quot;],\&quot;from_points\&quot;:[[-0.087891,51.534377],[-0.090637,51.467697],[-0.171833,51.521241],[-0.211487,51.473685]],\&quot;to_points\&quot;:[[-0.087891,51.534377],[-0.090637,51.467697],[-0.171833,51.521241],[-0.211487,51.473685]],\&quot;vehicle\&quot;:\&quot;car\&quot;}&#x27; &#x60;&#x60;&#x60; 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiClient;
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.Configuration;
//import com.graphhopper.directions.api.client.auth.*;
//import com.graphhopper.directions.api.client.tmp.MatrixApiApi;

ApiClient defaultClient = Configuration.getDefaultApiClient();

// Configure API key authorization: api_key
ApiKeyAuth api_key = (ApiKeyAuth) defaultClient.getAuthentication("api_key");
api_key.setApiKey("YOUR API KEY");
// Uncomment the following line to set a prefix for the API key, e.g. "Token" (defaults to null)
//api_key.setApiKeyPrefix("Token");

MatrixApiApi apiInstance = new MatrixApiApi();
Object body = null; // Object | 
try {
    MatrixResponse result = apiInstance.postMatrix(body);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling MatrixApiApi#postMatrix");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**Object**](Object.md)|  | [optional]

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

