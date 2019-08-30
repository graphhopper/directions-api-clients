# swagger_client.MatrixApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**calculate_matrix**](MatrixApi.md#calculate_matrix) | **POST** /matrix/calculate | Post a matrix request in batch mode
[**get_matrix**](MatrixApi.md#get_matrix) | **GET** /matrix | Execute a matrix request
[**get_matrix_solution**](MatrixApi.md#get_matrix_solution) | **GET** /matrix/solution/{jobId} | Retrieve matrix
[**post_matrix**](MatrixApi.md#post_matrix) | **POST** /matrix | Execute a matrix request

# **calculate_matrix**
> JobId calculate_matrix(body=body)

Post a matrix request in batch mode

The Batch Matrix allows using matrices with more locations and works asynchronously - similar to our Route Optimization:  * Create a HTTP POST request against `/matrix/calculate` and add the key in the URL: `/matrix/calculate?key=[YOUR_KEY]`. This will give you the `job_id` from the response json like `{ \"job_id\": \"7ac65787-fb99-4e02-a832-2c3010c70097\" }`  * Poll via HTTP GET requests every second against `/matrix/solution/[job_id]`  Here are some full examples via curl: ```bash $ curl -X POST -H \"Content-Type: application/json\" \"https://graphhopper.com/api/1/matrix/calculate?key=[YOUR_KEY]\" -d '{\"points\":[[13.29895,52.48696],[13.370876,52.489575],[13.439026,52.511206]]}' {\"job_id\":\"7ac65787-fb99-4e02-a832-2c3010c70097\"} ```  Pick the returned `job_id` and use it in the next GET requests: ```bash $ curl -X GET \"https://graphhopper.com/api/1/matrix/solution/7ac65787-fb99-4e02-a832-2c3010c70097?key=[YOUR_KEY]\" {\"status\":\"waiting\"} ```  When the calculation is finished (`status:finished`) the JSON response will contain the full matrix JSON under `solution`: ```bash $ curl -X GET \"https://graphhopper.com/api/1/matrix/solution/7ac65787-fb99-4e02-a832-2c3010c70097?key=[YOUR_KEY]\" {\"solution\":{\"weights\":[[0.0,470.453,945.414],[503.793,0.0,580.871],[970.49,569.511,0.0]],\"info\":{\"copyrights\":[\"GraphHopper\",\"OpenStreetMap contributors\"]}},\"status\":\"finished\"} ```  Please note that if an error occured while calculation the JSON will not have a status but contain directly the error message e.g.: ```json {\"message\":\"Cannot find from_points: 1\",\"hints\":[{...}]} ``` 

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: api_key
configuration = swagger_client.Configuration()
configuration.api_key['key'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['key'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.MatrixApi(swagger_client.ApiClient(configuration))
body = swagger_client.Object() # Object |  (optional)

try:
    # Post a matrix request in batch mode
    api_response = api_instance.calculate_matrix(body=body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling MatrixApi->calculate_matrix: %s\n" % e)
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

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **get_matrix**
> MatrixResponse get_matrix(point=point, from_point=from_point, to_point=to_point, point_hint=point_hint, from_point_hint=from_point_hint, to_point_hint=to_point_hint, snap_prevention=snap_prevention, out_array=out_array, vehicle=vehicle, fail_fast=fail_fast)

Execute a matrix request

### Introduction  ![Matrix Example](./img/matrix-example.png)  The Matrix is part of the [GraphHopper Directions API](https://graphhopper.com/#directions-api) and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing multiple times.  In the [Routing](#tag/Routing-API) we support multiple points, so called 'via points', which results in one route being calculated. The Matrix results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the [GraphHopper Route Optimization](#tag/Route-Optimization-API) uses the Matrix under the hood to achieve this.  Some other use case scenarios for the Matrix:   * Logistic problems often pick up many items from and deliver them to many locations.  * Calculating detours with many possible points in-between and selecting the best e.g. interesting for ridesharing or taxi applications. For this 1-to-many requests are necessary.  * Finding the best tour for a tourist in the need to visit as many points of interests as possible.  * ...  ### API Clients and Examples  See the [clients](#section/API-Clients) section in the main document and [live examples](https://graphhopper.com/api/1/examples/#matrix).  ### Description  The Matrix calculates the well known distance-matrix for a set of points, i.e. it calculates all the distances between every point combination. But we do not stop there, we also offer a time-, weight- and route-matrix. The weight-matrix can be used as raw input for e.g. a vehicle routing problem ([VRP](http://en.wikipedia.org/wiki/Vehicle_routing_problem)) and is more precise than a time- or distance-matrix. E.g. for bike routes the actual weight of a route (e.g. the \"beauty\") is what you want to decide if a route is 'better' and not always the taken time or distance.  A simple illustration for a 3x3 matrix with identical from and to points:   -          |to_point1|to_point2|to_point3 :-----------|:--------|:--------|:-------- from_point1 |0        |1->2     | 1->3 from_point2 |2->1     |0        | 2->3 from_point3 |3->1     |3->2     | 0  A simple illustration for a 1x3 matrix with different start- and end-points:   -          | to_point1  | to_point2 | t_point3 :-----------|:-----------|:----------|:-------- from_pointA |A->1        |A->2       |A->3   For every route 1->2, 1-3, ... or A->1,A->2,A->3 you can return only the weight, the time and the distance. To calculate full routes you can use the [Routing](#tag/Routing-API) which also has a lot of different parameters.  ### Limits and Counts  The cost for one request depends on the number of locations and is documented [here](https://graphhopper.com/api/1/docs/FAQ/#what-is-one-credit).  One request should not exceed the Matrix location limit depending on the package, see the pricing in our dashboard. 

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: api_key
configuration = swagger_client.Configuration()
configuration.api_key['key'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['key'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.MatrixApi(swagger_client.ApiClient(configuration))
point = ['point_example'] # list[str] | Specify multiple points in `latitude,longitude` for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. (optional)
from_point = ['from_point_example'] # list[str] | The starting points for the routes in `latitude,longitude`. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. (optional)
to_point = ['to_point_example'] # list[str] | The destination points for the routes in `latitude,longitude`. (optional)
point_hint = ['point_hint_example'] # list[str] | Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. (optional)
from_point_hint = ['from_point_hint_example'] # list[str] | For the from_point parameter. See point_hint (optional)
to_point_hint = ['to_point_hint_example'] # list[str] | For the to_point parameter. See point_hint (optional)
snap_prevention = ['snap_prevention_example'] # list[str] | Optional parameter to avoid snapping to a certain road class or road environment. Current supported values `motorway`, `trunk`, `ferry`, `tunnel`, `bridge` and `ford`. Multiple values are specified like `snap_prevention=ferry&snap_prevention=motorway`  (optional)
out_array = ['out_array_example'] # list[str] | Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. (optional)
vehicle = swagger_client.VehicleProfileId() # VehicleProfileId | The vehicle profile for which the matrix should be calculated. (optional)
fail_fast = true # bool | Specifies whether or not the matrix calculation should return with an error as soon as possible in case some points cannot be found or some points are not connected. If set to `false` the time/weight/distance matrix will be calculated for all valid points and contain the `null` value for all entries that could not be calculated. The `hint` field of the response will also contain additional information about what went wrong (see its documentation). (optional)

try:
    # Execute a matrix request
    api_response = api_instance.get_matrix(point=point, from_point=from_point, to_point=to_point, point_hint=point_hint, from_point_hint=from_point_hint, to_point_hint=to_point_hint, snap_prevention=snap_prevention, out_array=out_array, vehicle=vehicle, fail_fast=fail_fast)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling MatrixApi->get_matrix: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **point** | [**list[str]**](str.md)| Specify multiple points in &#x60;latitude,longitude&#x60; for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. | [optional] 
 **from_point** | [**list[str]**](str.md)| The starting points for the routes in &#x60;latitude,longitude&#x60;. E.g. if you want to calculate the three routes A-&amp;gt;1, A-&amp;gt;2, A-&amp;gt;3 then you have one from_point parameter and three to_point parameters. | [optional] 
 **to_point** | [**list[str]**](str.md)| The destination points for the routes in &#x60;latitude,longitude&#x60;. | [optional] 
 **point_hint** | [**list[str]**](str.md)| Optional parameter. Specifies a hint for each &#x60;point&#x60; parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. | [optional] 
 **from_point_hint** | [**list[str]**](str.md)| For the from_point parameter. See point_hint | [optional] 
 **to_point_hint** | [**list[str]**](str.md)| For the to_point parameter. See point_hint | [optional] 
 **snap_prevention** | [**list[str]**](str.md)| Optional parameter to avoid snapping to a certain road class or road environment. Current supported values &#x60;motorway&#x60;, &#x60;trunk&#x60;, &#x60;ferry&#x60;, &#x60;tunnel&#x60;, &#x60;bridge&#x60; and &#x60;ford&#x60;. Multiple values are specified like &#x60;snap_prevention&#x3D;ferry&amp;snap_prevention&#x3D;motorway&#x60;  | [optional] 
 **out_array** | [**list[str]**](str.md)| Specifies which arrays should be included in the response. Specify one or more of the following options &#x27;weights&#x27;, &#x27;times&#x27;, &#x27;distances&#x27;. To specify more than one array use e.g. out_array&#x3D;times&amp;out_array&#x3D;distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. | [optional] 
 **vehicle** | [**VehicleProfileId**](.md)| The vehicle profile for which the matrix should be calculated. | [optional] 
 **fail_fast** | **bool**| Specifies whether or not the matrix calculation should return with an error as soon as possible in case some points cannot be found or some points are not connected. If set to &#x60;false&#x60; the time/weight/distance matrix will be calculated for all valid points and contain the &#x60;null&#x60; value for all entries that could not be calculated. The &#x60;hint&#x60; field of the response will also contain additional information about what went wrong (see its documentation). | [optional] 

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **get_matrix_solution**
> MatrixResponse get_matrix_solution(job_id)

Retrieve matrix

This endpoint returns the solution of posted matrix request. You can fetch it with the job_id, you have been sent. 

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: api_key
configuration = swagger_client.Configuration()
configuration.api_key['key'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['key'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.MatrixApi(swagger_client.ApiClient(configuration))
job_id = 'job_id_example' # str | Request solution with jobId

try:
    # Retrieve matrix
    api_response = api_instance.get_matrix_solution(job_id)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling MatrixApi->get_matrix_solution: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **job_id** | **str**| Request solution with jobId | 

### Return type

[**MatrixResponse**](MatrixResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **post_matrix**
> MatrixResponse post_matrix(body=body)

Execute a matrix request

The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key. Both request scenarios are identical except that all singular parameter names are named as their plural for a POST request. All effected parameters are: `points`, `from_points`, `to_points`, and `out_array`.  *Please note that in opposite to the GET endpoint, points are specified in `longitude, latitude`*.  For example `point=10,11&point=20,22` will be converted to the following JSON `points` array: ```json { \"points\": [[11,10], [22,20]] } ``` Note that also the order changes to `[longitude,latitude]` similar to [GeoJson](http://geojson.org/geojson-spec.html#examples).  Example: ```bash curl -X POST -H \"Content-Type: application/json\" \"https://graphhopper.com/api/1/matrix?key=[YOUR_KEY]\" -d '{\"elevation\":false,\"out_arrays\":[\"weights\"],\"from_points\":[[-0.087891,51.534377],[-0.090637,51.467697],[-0.171833,51.521241],[-0.211487,51.473685]],\"to_points\":[[-0.087891,51.534377],[-0.090637,51.467697],[-0.171833,51.521241],[-0.211487,51.473685]],\"vehicle\":\"car\"}' ``` 

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: api_key
configuration = swagger_client.Configuration()
configuration.api_key['key'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['key'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.MatrixApi(swagger_client.ApiClient(configuration))
body = swagger_client.Object() # Object |  (optional)

try:
    # Execute a matrix request
    api_response = api_instance.post_matrix(body=body)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling MatrixApi->post_matrix: %s\n" % e)
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

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

