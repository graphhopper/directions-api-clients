# SWGActivity

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **NSString*** | type of activity | [optional] 
**_id** | **NSString*** | id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to | [optional] 
**locationId** | **NSString*** | id that refers to address | [optional] 
**address** | [**SWGAddress***](SWGAddress.md) | address of activity | [optional] 
**arrTime** | **NSNumber*** | arrival time at this activity in seconds | [optional] 
**endTime** | **NSNumber*** | end time of and thus departure time at this activity | [optional] 
**endDateTime** | **NSString*** | end date time with offset like this 1970-01-01T01:00+01:00 | [optional] 
**arrDateTime** | **NSString*** | arrival date time with offset like this 1970-01-01T01:00+01:00 | [optional] 
**waitingTime** | **NSNumber*** | waiting time at this activity in seconds | [optional] 
**preparationTime** | **NSNumber*** | preparation time at this activity in seconds | [optional] 
**distance** | **NSNumber*** | cumulated distance from start to this activity in m | [optional] 
**drivingTime** | **NSNumber*** | driving time of driver in seconds | [optional] 
**loadBefore** | **NSArray&lt;NSNumber*&gt;*** | Array with size/capacity dimensions before this activity | [optional] 
**loadAfter** | **NSArray&lt;NSNumber*&gt;*** | Array with size/capacity dimensions after this activity | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


