# MatrixResponse

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distances** | [**float[][]**](array.md) | The distance matrix for the specified points in the same order as the time matrix. The distances are in meters. If &#x60;fail_fast&#x3D;false&#x60; the matrix will contain &#x60;null&#x60; for connections that could not be found. | [optional] 
**times** | [**float[][]**](array.md) | The time matrix for the specified points in the order [[from1-&gt;to1, from1-&gt;to2, ...], [from2-&gt;to1, from2-&gt;to2, ...], ...]. The times are in seconds. If &#x60;fail_fast&#x3D;false&#x60; the matrix will contain &#x60;null&#x60; for connections that could not be found. | [optional] 
**weights** | [**double[][]**](array.md) | The weight matrix for the specified points in the same order as the time matrix. The weights for different vehicles can have a different unit but the weights array is perfectly suited as input for Vehicle Routing Problems as it is currently faster to calculate. If &#x60;fail_fast&#x3D;false&#x60; the matrix will contain &#x60;null&#x60; for connections that could not be found. | [optional] 
**info** | [**\Swagger\Client\Model\ResponseInfo**](ResponseInfo.md) |  | [optional] 
**hints** | [**\Swagger\Client\Model\MatrixResponseHints[]**](MatrixResponseHints.md) | Optional. Additional response data | [optional] 

[[Back to Model list]](../../README.md#documentation-for-models) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to README]](../../README.md)

