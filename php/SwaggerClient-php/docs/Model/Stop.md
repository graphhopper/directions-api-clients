# Stop

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**address** | [**\Swagger\Client\Model\Address**](Address.md) |  | [optional] 
**duration** | **int** | Specifies the duration of the pickup or delivery in seconds, e.g. how long it takes unload items at the customer site. | [optional] [default to 0]
**preparation_time** | **int** | Specifies the preparation time in seconds. It can be used to model parking lot search time since if you have 3 identical locations in a row, it only falls due once. | [optional] [default to 0]
**time_windows** | [**\Swagger\Client\Model\TimeWindow[]**](TimeWindow.md) | Specifies an array of time window objects (see time window object below). For example, if an item needs to be delivered between 7am and 10am then specify the array as follows: [ { \&quot;earliest\&quot;: 25200, \&quot;latest\&quot; : 32400 } ] (starting the day from 0 in seconds). | [optional] 
**group** | **string** | Group this stop belongs to | [optional] 

[[Back to Model list]](../../README.md#documentation-for-models) [[Back to API list]](../../README.md#documentation-for-api-endpoints) [[Back to README]](../../README.md)

