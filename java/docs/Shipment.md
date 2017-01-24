
# Shipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Unique identifier of service |  [optional]
**name** | **String** | name of shipment |  [optional]
**priority** | **Integer** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. |  [optional]
**pickup** | [**Stop**](Stop.md) |  |  [optional]
**delivery** | [**Stop**](Stop.md) |  |  [optional]
**size** | **List&lt;Integer&gt;** | array of capacity dimensions |  [optional]
**requiredSkills** | **List&lt;String&gt;** | array of required skills |  [optional]
**allowedVehicles** | **List&lt;String&gt;** | array of allowed vehicle ids |  [optional]



