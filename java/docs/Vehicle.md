
# Vehicle

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**vehicleId** | **String** | Unique identifier of vehicle |  [optional]
**typeId** | **String** | Unique identifier referring to the available vehicle types |  [optional]
**startAddress** | [**Address**](Address.md) |  |  [optional]
**endAddress** | [**Address**](Address.md) |  |  [optional]
**_break** | [**ModelBreak**](ModelBreak.md) |  |  [optional]
**returnToDepot** | **Boolean** | Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. |  [optional]
**earliestStart** | **Long** | earliest start of vehicle at its start location |  [optional]
**latestEnd** | **Long** | latest end of vehicle at its end location |  [optional]
**skills** | **List&lt;String&gt;** | array of skills |  [optional]
**maxDistance** | **Long** | max distance of vehicle |  [optional]



