# Swagger\Client\SolutionApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getSolution**](SolutionApi.md#getSolution) | **GET** /vrp/solution/{jobId} | Return the solution associated to the jobId


# **getSolution**
> \Swagger\Client\Model\Response getSolution($key, $job_id)

Return the solution associated to the jobId

This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent.

### Example
```php
<?php
require_once(__DIR__ . '/vendor/autoload.php');

$api_instance = new Swagger\Client\Api\SolutionApi();
$key = "key_example"; // string | your API key
$job_id = "job_id_example"; // string | Request solution with jobId

try {
    $result = $api_instance->getSolution($key, $job_id);
    print_r($result);
} catch (Exception $e) {
    echo 'Exception when calling SolutionApi->getSolution: ', $e->getMessage(), PHP_EOL;
}
?>
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **key** | **string**| your API key |
 **job_id** | **string**| Request solution with jobId |

### Return type

[**\Swagger\Client\Model\Response**](../Model/Response.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to Model list]](../../README.md#documentation-for-models) [[Back to README]](../../README.md)

