# GraphHopperClient::Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service | [optional] 
**type** | **String** | type of service | [optional] 
**priority** | **Integer** | priority of service | [optional] 
**name** | **String** | name of service | [optional] 
**address** | [**Address**](Address.md) |  | [optional] 
**duration** | **Integer** | duration of service, i.e. time in seconds the corresponding activity takes | [optional] 
**preparation_time** | **Integer** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] 
**time_windows** | [**Array&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**size** | **Array&lt;Integer&gt;** | array of capacity dimensions | [optional] 
**required_skills** | **Array&lt;String&gt;** | array of required skills | [optional] 
**allowed_vehicles** | **Array&lt;String&gt;** | array of allowed vehicle ids | [optional] 
**disallowed_vehicles** | **Array&lt;String&gt;** | array of disallowed vehicle ids | [optional] 
**max_time_in_vehicle** | **Integer** | max time service can stay in vehicle | [optional] 


