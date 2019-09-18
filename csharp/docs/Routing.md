# GraphHopper.Model.Routing
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**CalcPoints** | **bool?** | It lets you specify whether the API should provide you with route geometries for vehicle routes or not. Thus, you do not need to do extra routing to get the polyline for each route. | [optional] [default to false]
**ConsiderTraffic** | **bool?** | indicates whether historical traffic information should be considered | [optional] [default to false]
**NetworkDataProvider** | **string** | specifies the data provider, read more about it [here](#section/Map-Data-and-Routing-Profiles). | [optional] [default to NetworkDataProviderEnum.Openstreetmap]
**FailFast** | **bool?** | indicates whether matrix calculation should fail fast when points cannot be connected | [optional] [default to true]
**ReturnSnappedWaypoints** | **bool?** | Indicates whether a solution includes snapped waypoints. In contrary to the address coordinate a snapped waypoint is the access point to the (road) network. | [optional] [default to false]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

