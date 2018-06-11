
# Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **kotlin.String** | Unique identifier of service |  [optional]
**type** | [**inline**](#TypeEnum) | type of service |  [optional]
**priority** | **kotlin.Int** | priority of service |  [optional]
**name** | **kotlin.String** | name of service |  [optional]
**address** | [**Address**](Address.md) |  |  [optional]
**duration** | **kotlin.Long** | duration of service, i.e. time in seconds the corresponding activity takes |  [optional]
**preparation_time** | **kotlin.Long** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location |  [optional]
**time_windows** | [**kotlin.Array&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed |  [optional]
**size** | **kotlin.Array&lt;kotlin.Int&gt;** | array of capacity dimensions |  [optional]
**required_skills** | **kotlin.Array&lt;kotlin.String&gt;** | array of required skills |  [optional]
**allowed_vehicles** | **kotlin.Array&lt;kotlin.String&gt;** | array of allowed vehicle ids |  [optional]
**disallowed_vehicles** | **kotlin.Array&lt;kotlin.String&gt;** | array of disallowed vehicle ids |  [optional]
**max_time_in_vehicle** | **kotlin.Long** | max time service can stay in vehicle |  [optional]


<a name="TypeEnum"></a>
## Enum: type
Name | Value
---- | -----
type | service, pickup, delivery



