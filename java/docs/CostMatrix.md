# CostMatrix

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | [**TypeEnum**](#TypeEnum) | type of cost matrix, currently default or google are supported |  [optional]
**locationIds** | **List&lt;String&gt;** |  |  [optional]
**data** | [**CostMatrixData**](CostMatrixData.md) |  |  [optional]
**profile** | **String** | vehicle profile or empty if catch all fallback |  [optional]

<a name="TypeEnum"></a>
## Enum: TypeEnum
Name | Value
---- | -----
DEFAULT | &quot;default&quot;
GOOGLE | &quot;google&quot;
