# DirectionsApiClient::Activity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **String** | type of activity | [optional] 
**id** | **String** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] 
**location_id** | **String** | id that refers to address | [optional] 
**arr_time** | **Integer** | arrival time at this activity in ms | [optional] 
**end_time** | **Integer** | end time of and thus departure time at this activity | [optional] 
**waiting_time** | **Integer** | waiting time at this activity in ms | [optional] 
**distance** | **Integer** | cumulated distance from start to this activity in m | [optional] 
**driving_time** | **Integer** | driving time of driver in ms | [optional] 
**load_before** | **Array&lt;Integer&gt;** | Array with size/capacity dimensions before this activity | [optional] 
**load_after** | **Array&lt;Integer&gt;** | Array with size/capacity dimensions after this activity | [optional] 


