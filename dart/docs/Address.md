# openapi.model.Address

## Load the model package
```dart
import 'package:openapi/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**locationId** | **String** | Unique identifier of location | [optional] [default to null]
**name** | **String** | name of location, e.g. street name plus house number | [optional] [default to null]
**lon** | **double** | longitude | [optional] [default to null]
**lat** | **double** | latitude | [optional] [default to null]
**streetHint** | **String** | Optional parameter. Specifies a hint for each address to better snap the coordinates (lon,lat) to road network. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


