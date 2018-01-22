
# Shipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **kotlin.String** | Unique identifier of service |  [optional]
**name** | **kotlin.String** | name of shipment |  [optional]
**priority** | **kotlin.Int** | priority of service, i.e. 1 &#x3D; high, 2 &#x3D; normal, 3 &#x3D; low. default is 2. |  [optional]
**pickup** | [**Stop**](Stop.md) |  |  [optional]
**delivery** | [**Stop**](Stop.md) |  |  [optional]
**size** | **kotlin.Array&lt;kotlin.Int&gt;** | array of capacity dimensions |  [optional]
**required_skills** | **kotlin.Array&lt;kotlin.String&gt;** | array of required skills |  [optional]
**allowed_vehicles** | **kotlin.Array&lt;kotlin.String&gt;** | array of allowed vehicle ids |  [optional]



