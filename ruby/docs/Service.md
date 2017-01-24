# SwaggerClient::Service

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service | [optional] 
**type** | **String** | type of service | [optional] 
**priority** | **Integer** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. | [optional] 
**name** | **String** | name of service | [optional] 
**address** | [**Address**](Address.md) |  | [optional] 
**duration** | **Integer** | duration of service, i.e. time in ms the corresponding activity takes | [optional] 
**time_windows** | [**Array&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] 
**size** | **Array&lt;Integer&gt;** | array of capacity dimensions | [optional] 
**required_skills** | **Array&lt;String&gt;** | array of required skills | [optional] 
**allowed_vehicles** | **Array&lt;String&gt;** | array of allowed vehicle ids | [optional] 


