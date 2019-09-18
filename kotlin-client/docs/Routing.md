# Routing

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**calcPoints** | [**kotlin.Boolean**](.md) | It lets you specify whether the API should provide you with route geometries for vehicle routes or not. Thus, you do not need to do extra routing to get the polyline for each route. |  [optional]
**considerTraffic** | [**kotlin.Boolean**](.md) | indicates whether historical traffic information should be considered |  [optional]
**networkDataProvider** | [**inline**](#NetworkDataProviderEnum) | specifies the data provider, read more about it [here](#section/Map-Data-and-Routing-Profiles). |  [optional]
**failFast** | [**kotlin.Boolean**](.md) | indicates whether matrix calculation should fail fast when points cannot be connected |  [optional]
**returnSnappedWaypoints** | [**kotlin.Boolean**](.md) | Indicates whether a solution includes snapped waypoints. In contrary to the address coordinate a snapped waypoint is the access point to the (road) network. |  [optional]

<a name="NetworkDataProviderEnum"></a>
## Enum: network_data_provider
Name | Value
---- | -----
networkDataProvider | openstreetmap, tomtom
