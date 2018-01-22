# swagger.model.Stop

## Load the model package
```dart
import 'package:swagger/api.dart';
```

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**address** | [**Address**](Address.md) |  | [optional] [default to null]
**duration** | **int** | duration of stop, i.e. time in ms the corresponding activity takes | [optional] [default to null]
**preparationTime** | **int** | preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location | [optional] [default to null]
**timeWindows** | [**List&lt;TimeWindow&gt;**](TimeWindow.md) | array of time windows. currently, only a single time window is allowed | [optional] [default to []]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


