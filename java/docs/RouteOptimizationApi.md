# RouteOptimizationApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getSolution**](RouteOptimizationApi.md#getSolution) | **GET** /vrp/solution/{jobId} | Retrieve solution
[**solveVRP**](RouteOptimizationApi.md#solveVRP) | **POST** /vrp/optimize | Solve vehicle routing problem

<a name="getSolution"></a>
# **getSolution**
> Response getSolution(jobId)

Retrieve solution

This endpoint returns the solution of posted vehicle routing or traveling salesman problems. You can fetch it with the job_id, you have been sent. 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiClient;
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.Configuration;
//import com.graphhopper.directions.api.client.auth.*;
//import com.graphhopper.directions.api.client.api.RouteOptimizationApi;

ApiClient defaultClient = Configuration.getDefaultApiClient();

// Configure API key authorization: api_key
ApiKeyAuth api_key = (ApiKeyAuth) defaultClient.getAuthentication("api_key");
api_key.setApiKey("YOUR API KEY");
// Uncomment the following line to set a prefix for the API key, e.g. "Token" (defaults to null)
//api_key.setApiKeyPrefix("Token");

RouteOptimizationApi apiInstance = new RouteOptimizationApi();
String jobId = "jobId_example"; // String | Request solution with jobId
try {
    Response result = apiInstance.getSolution(jobId);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling RouteOptimizationApi#getSolution");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **jobId** | **String**| Request solution with jobId |

### Return type

[**Response**](Response.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

<a name="solveVRP"></a>
# **solveVRP**
> JobId solveVRP(body)

Solve vehicle routing problem

 ### Getting Started  This tutorial - [Getting Started with the Optimization API](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - illustrates the very basic steps and building blocks to model your vehicle routing problem.  This only shows you an excerpt of what is possible with our API. You can find the entire specification of the required request (Request Body Schema) as well as the response below. It is an interactive documentation of nested objects. By default, you only see the root objects such as \&quot;vehicles\&quot;, \&quot;vehicle_types\&quot;, \&quot;objectives\&quot; etc.. To unfold detailed information about each root object, you just need to click on it as shown here  ![Nested Doc](./img/nested-doc.gif)  To explore the specification, we can recommend you to extend the problem in the tutorial above and either use our [route editor](https://www.graphhopper.com/blog/2015/07/21/graphhoppers-new-route-optimization-editor/) in the Directions API dashboard or the REST clients such as Insomnia or Postman as described [here](https://docs.graphhopper.com/#section/Explore-our-APIs). Additionally, you can find a ready-to-use example in the Request Samples Panel on the right (or below). You can easily unfold it by clicking the + or you can just copy it all and paste it to our route editor or your REST client.  Furthermore, we provide [a number of tutorials](https://www.graphhopper.com/tutorial/) illustrating how to use this API and how to model your vehicle routing problems. Here, you can find a list of tutorials that might help you to get started quickly:  - [Getting Start with the Optimization API - Traveling Salesman Problem](https://www.graphhopper.com/blog/2019/05/17/getting-started-with-the-optimization-api-traveling-salesman-problem/) - [How to solve a traveling salesman problem with a week-planning horizon?](https://www.graphhopper.com/blog/2016/05/30/how-to-solve-a-traveling-salesman-problem-with-a-week-planning-horizon/) - [How to schedule technicians with skills and multiple dependencies between tasks?](https://www.graphhopper.com/blog/2016/06/03/how-to-route-technicians-with-skills-and-multiple-dependencies-between-tasks/) - [What is the difference between the min. of completion time and min. transport time?](https://www.graphhopper.com/blog/2016/06/20/what-is-the-difference-between-the-minimization-of-completion-time-and-minimizing-transport-time/) - [How to model multiple delivery routes with a single vehicle?](https://www.graphhopper.com/blog/2016/07/21/how-to-model-multiple-delivery-routes-with-a-single-vehicle/) 

### Example
```java
// Import classes:
//import com.graphhopper.directions.api.client.ApiClient;
//import com.graphhopper.directions.api.client.ApiException;
//import com.graphhopper.directions.api.client.Configuration;
//import com.graphhopper.directions.api.client.auth.*;
//import com.graphhopper.directions.api.client.api.RouteOptimizationApi;

ApiClient defaultClient = Configuration.getDefaultApiClient();

// Configure API key authorization: api_key
ApiKeyAuth api_key = (ApiKeyAuth) defaultClient.getAuthentication("api_key");
api_key.setApiKey("YOUR API KEY");
// Uncomment the following line to set a prefix for the API key, e.g. "Token" (defaults to null)
//api_key.setApiKeyPrefix("Token");

RouteOptimizationApi apiInstance = new RouteOptimizationApi();
Request body = new Request(); // Request | Request object that contains the problem to be solved
try {
    JobId result = apiInstance.solveVRP(body);
    System.out.println(result);
} catch (ApiException e) {
    System.err.println("Exception when calling RouteOptimizationApi#solveVRP");
    e.printStackTrace();
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**Request**](Request.md)| Request object that contains the problem to be solved |

### Return type

[**JobId**](JobId.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

