# GraphHopperClient::MatrixRequest

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**points** | **Array&lt;Array&lt;Float&gt;&gt;** | Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format longitude,latitude. | [optional] 
**from_points** | **Array&lt;Array&lt;Float&gt;&gt;** | The starting points for the routes. E.g. if you want to calculate the three routes A-&amp;gt;1, A-&amp;gt;2, A-&amp;gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format longitude,latitude. | [optional] 
**to_points** | **Array&lt;Array&lt;Float&gt;&gt;** | The destination points for the routes. Is a string with the format longitude,latitude. | [optional] 
**point_hints** | **Array&lt;String&gt;** | Optional parameter. Specifies a hint for each point in the &#x60;points&#x60; array to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. | [optional] 
**from_point_hints** | **Array&lt;String&gt;** | More information for the &#x60;from_points&#x60; array. See &#x60;point_hints&#x60; | [optional] 
**to_point_hints** | **Array&lt;String&gt;** | More information for the &#x60;to_points&#x60; array. See &#x60;point_hints&#x60; | [optional] 
**out_arrays** | **Array&lt;String&gt;** | Specifies which arrays should be included in the response. Specify one or more of the following options &#39;weights&#39;, &#39;times&#39;, &#39;distances&#39;. To specify more than one array use e.g. out_array&#x3D;times&amp;amp;out_array&#x3D;distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API. | [optional] 
**vehicle** | **String** | The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc, see here for the details. | [optional] 


