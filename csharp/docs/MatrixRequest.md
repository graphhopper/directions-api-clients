# GraphHopper.Model.MatrixRequest
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**FromPoints** | **List&lt;List&lt;double?&gt;&gt;** | The starting points for the routes in an array of &#x60;[longitude,latitude]&#x60;. For instance, if you want to calculate three routes from point A such as A-&gt;1, A-&gt;2, A-&gt;3 then you have one &#x60;from_point&#x60; parameter and three &#x60;to_point&#x60; parameters. | [optional] 
**ToPoints** | **List&lt;List&lt;double?&gt;&gt;** | The destination points for the routes in an array of &#x60;[longitude,latitude]&#x60;. | [optional] 
**FromPointHints** | **List&lt;string&gt;** | See &#x60;point_hints&#x60; | [optional] 
**ToPointHints** | **List&lt;string&gt;** | See &#x60;point_hints&#x60; | [optional] 
**OutArrays** | **List&lt;string&gt;** | Specifies which matrices should be included in the response. Specify one or more of the following options &#x60;weights&#x60;, &#x60;times&#x60;, &#x60;distances&#x60;. The units of the entries of &#x60;distances&#x60; are meters, of &#x60;times&#x60; are seconds and of &#x60;weights&#x60; is arbitrary and it can differ for different vehicles or versions of this API. | [optional] 
**Vehicle** | [****](.md) |  | [optional] 
**FailFast** | **bool?** | Specifies whether or not the matrix calculation should return with an error as soon as possible in case some points cannot be found or some points are not connected. If set to &#x60;false&#x60; the time/weight/distance matrix will be calculated for all valid points and contain the &#x60;null&#x60; value for all entries that could not be calculated. The &#x60;hint&#x60; field of the response will also contain additional information about what went wrong (see its documentation). | [optional] [default to true]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

