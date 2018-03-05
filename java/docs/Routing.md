
# Routing

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**calcPoints** | **Boolean** | indicates whether solution should come with route geometries |  [optional]
**considerTraffic** | **Boolean** | indicates whether historical traffic information should be considered |  [optional]
**networkDataProvider** | [**NetworkDataProviderEnum**](#NetworkDataProviderEnum) | specifies the data provider |  [optional]
**failFast** | **Boolean** | indicates whether matrix calculation should fail fast when points cannot be connected |  [optional]


<a name="NetworkDataProviderEnum"></a>
## Enum: NetworkDataProviderEnum
Name | Value
---- | -----
OPENSTREETMAP | &quot;openstreetmap&quot;
TOMTOM | &quot;tomtom&quot;



