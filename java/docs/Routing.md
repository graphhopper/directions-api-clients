# Routing

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**calcPoints** | **Boolean** | It lets you specify whether the API should provide you with route geometries for vehicle routes or not. Thus, you do not need to do extra routing to get the polyline for each route. |  [optional]
**considerTraffic** | **Boolean** | indicates whether historical traffic information should be considered |  [optional]
**networkDataProvider** | [**NetworkDataProviderEnum**](#NetworkDataProviderEnum) | specifies the data provider, read more about it [here](#section/Map-Data-and-Routing-Profiles). |  [optional]
**failFast** | **Boolean** | indicates whether matrix calculation should fail fast when points cannot be connected |  [optional]
**returnSnappedWaypoints** | **Boolean** | Indicates whether a solution includes snapped waypoints. In contrary to the address coordinate a snapped waypoint is the access point to the (road) network. |  [optional]

<a name="NetworkDataProviderEnum"></a>
## Enum: NetworkDataProviderEnum
Name | Value
---- | -----
OPENSTREETMAP | &quot;openstreetmap&quot;
TOMTOM | &quot;tomtom&quot;
