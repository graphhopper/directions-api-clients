# Shipment

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **String** | Specifies the id of the shipment. Ids need to be unique so there must not be two services/shipments with the same id. | 
**name** | **String** | Meaningful name for shipment, e.g. \&quot;pickup and deliver pizza to Peter\&quot;. |  [optional]
**priority** | **Integer** | Specifies the priority. Can be 1 &#x3D; high priority to 10 &#x3D; low priority. Often there are more services/shipments than the available vehicle fleet can handle. Then you could assign priorities to differentiate high priority tasks from those that can be served later or omitted at all. |  [optional]
**pickup** | [**Stop**](Stop.md) |  | 
**delivery** | [**Stop**](Stop.md) |  | 
**size** | **List&lt;Integer&gt;** | Size can have multiple dimensions and should be in line with the capacity dimension array of the vehicle type. For example, if the item that needs to be delivered has two size dimension, volume and weight, then specify it as follow [ 20, 5 ] assuming a volume of 20 and a weight of 5. |  [optional]
**requiredSkills** | **List&lt;String&gt;** | Specifies an array of required skills, i.e. array of string (not case sensitive). For example, if this shipment needs to be conducted by a technician having a &#x60;drilling_machine&#x60; and a &#x60;screw_driver&#x60; then specify the array as follows: &#x60;[\&quot;drilling_machine\&quot;,\&quot;screw_driver\&quot;]&#x60;. This means that the service can only be done by a vehicle (technician) that has the skills &#x60;drilling_machine&#x60; AND &#x60;screw_driver&#x60; in its skill array. Otherwise it remains unassigned. |  [optional]
**allowedVehicles** | **List&lt;String&gt;** | Specifies an array of allowed vehicles, i.e. array of vehicle ids. For example, if this shipment can only be conducted EITHER by \&quot;technician_peter\&quot; OR \&quot;technician_stefan\&quot; specify this as follows: [\&quot;technician_peter\&quot;,\&quot;technician_stefan\&quot;]. |  [optional]
**disallowedVehicles** | **List&lt;String&gt;** | Specifies an array of disallowed vehicles, i.e. array of vehicle ids. |  [optional]
**maxTimeInVehicle** | **Long** | Specifies the maximum time in seconds a shipment can stay in the vehicle. |  [optional]
