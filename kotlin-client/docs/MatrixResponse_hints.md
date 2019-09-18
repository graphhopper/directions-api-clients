# MatrixResponseHints

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**message** | [**kotlin.String**](.md) | Short description of this hint |  [optional]
**details** | [**kotlin.String**](.md) | Details of this hint |  [optional]
**invalidFromPoints** | [**kotlin.Array&lt;java.math.BigDecimal&gt;**](java.math.BigDecimal.md) | Optional. An array of from_point indices of points that could not be found. Will only be added if &#x60;fail_fast&#x3D;false&#x60; and some &#x60;from_point&#x60;s were not found.&#x60; |  [optional]
**invalidToPoints** | [**kotlin.Array&lt;java.math.BigDecimal&gt;**](java.math.BigDecimal.md) | Optional. An array of to_point indices of points that could not be found. Will only be added if &#x60;fail_fast&#x3D;false&#x60; and some &#x60;to_point&#x60;s were not found.&#x60; |  [optional]
**pointPairs** | [**kotlin.Array&lt;kotlin.Array&lt;java.math.BigDecimal&gt;&gt;**](.md) | Optional. An array of two-element arrays representing the from/to_point indices of points for which no connection could be found. Will only be added if &#x60;fail_fast&#x3D;false&#x60; and some connections were not found. |  [optional]
