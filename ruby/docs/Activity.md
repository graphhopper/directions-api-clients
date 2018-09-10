# GraphHopperClient::Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **String** | type of activity | [optional] 
**id** | **String** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] 
**location_id** | **String** | id that refers to address | [optional] 
**address** | [**Address**](Address.md) | address of activity | [optional] 
**arr_time** | **Integer** | arrival time at this activity in seconds | [optional] 
**end_time** | **Integer** | end time of and thus departure time at this activity | [optional] 
**end_date_time** | **String** | end date time with offset like this 1970-01-01T01:00+01:00 | [optional] 
**arr_date_time** | **String** | arrival date time with offset like this 1970-01-01T01:00+01:00 | [optional] 
**waiting_time** | **Integer** | waiting time at this activity in seconds | [optional] 
**preparation_time** | **Integer** | preparation time at this activity in seconds | [optional] 
**distance** | **Integer** | cumulated distance from start to this activity in m | [optional] 
**driving_time** | **Integer** | driving time of driver in seconds | [optional] 
**load_before** | **Array&lt;Integer&gt;** | Array with size/capacity dimensions before this activity | [optional] 
**load_after** | **Array&lt;Integer&gt;** | Array with size/capacity dimensions after this activity | [optional] 


