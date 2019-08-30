# IO.Swagger.Model.VehicleType
## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**TypeId** | **string** | Specifies the id of the vehicle type. If a vehicle needs to be of this type, it should refer to this with its type_id attribute. | 
**Profile** | [****](.md) |  | [optional] 
**Capacity** | **List&lt;int?&gt;** | Specifies an array of capacity dimension values which need to be int values. For example, if there are two dimensions such as volume and weight then it needs to be defined as [ 1000, 300 ] assuming a maximum volume of 1000 and a maximum weight of 300. | [optional] [default to [0]]
**SpeedFactor** | **double?** | Specifies a speed factor for this vehicle type. If the vehicle that uses this type needs to be only half as fast as what is actually calculated with our routing engine then set the speed factor to 0.5. | [optional] [default to 1]
**ServiceTimeFactor** | **double?** | Specifies a service time factor for this vehicle type. If the vehicle/driver that uses this type is able to conduct the service as double as fast as it is determined in the corresponding service or shipment then set it to 0.5. | [optional] [default to 1]
**CostPerMeter** | **double?** | **_BETA feature_**! Cost parameter per distance unit, here meter is used | [optional] 
**CostPerSecond** | **double?** | **_BETA feature_**! Cost parameter per time unit, here second is used | [optional] 
**CostPerActivation** | **double?** | **_BETA feature_**! Cost parameter vehicle activation, i.e. fixed costs per vehicle | [optional] 
**ConsiderTraffic** | **bool?** | Specifies whether traffic should be considered. if \&quot;tomtom\&quot; is used and this is false, free flow travel times from \&quot;tomtom\&quot; are calculated. If this is true, historical traffic info are used. We do not yet have traffic data for \&quot;openstreetmap\&quot;, thus, setting this true has no effect at all. | [optional] [default to false]
**NetworkDataProvider** | **string** | Specifies the network data provider. Either use [&#x60;openstreetmap&#x60;](#section/Map-Data-and-Routing-Profiles/OpenStreetMap) (default) or [&#x60;tomtom&#x60;](#section/Map-Data-and-Routing-Profiles/TomTom) (add-on required). | [optional] [default to NetworkDataProviderEnum.Openstreetmap]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)

