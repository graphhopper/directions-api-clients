
# Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service |  [optional]
**type** | [**TypeEnum**](#TypeEnum) | type of service |  [optional]
**priority** | **Integer** | priority of service |  [optional]
**name** | **String** | name of service |  [optional]
**address** | [**Address**](Address.md) |  |  [optional]
**duration** | **Long** | duration of service, i.e. time in ms the corresponding activity takes |  [optional]
**preparationTime** | **Long** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location |  [optional]
**timeWindows** | [**List&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed |  [optional]
**size** | **List&lt;Integer&gt;** | array of capacity dimensions |  [optional]
**requiredSkills** | **List&lt;String&gt;** | array of required skills |  [optional]
**allowedVehicles** | **List&lt;String&gt;** | array of allowed vehicle ids |  [optional]


<a name="TypeEnum"></a>
## Enum: TypeEnum
Name | Value
---- | -----
SERVICE | &quot;service&quot;
PICKUP | &quot;pickup&quot;
DELIVERY | &quot;delivery&quot;



