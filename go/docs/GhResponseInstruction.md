# GhResponseInstruction

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Text** | **string** | A description what the user has to do in order to follow the route. The language depends on the locale parameter. | [optional] [default to null]
**Distance** | **float64** | The distance for this instruction, in meter | [optional] [default to null]
**Time** | **int32** | The duration for this instruction, in ms | [optional] [default to null]
**Interval** | **[]int32** | An array containing the first and the last index (relative to paths[0].points) of the points for this instruction. This is useful to know for which part of the route the instructions are valid. | [optional] [default to null]
**Sign** | **int32** | A number which specifies the sign to show e.g. for right turn etc &lt;br&gt;TURN_SHARP_LEFT &#x3D; -3&lt;br&gt;TURN_LEFT &#x3D; -2&lt;br&gt;TURN_SLIGHT_LEFT &#x3D; -1&lt;br&gt;CONTINUE_ON_STREET &#x3D; 0&lt;br&gt;TURN_SLIGHT_RIGHT &#x3D; 1&lt;br&gt;TURN_RIGHT &#x3D; 2&lt;br&gt;TURN_SHARP_RIGHT &#x3D; 3&lt;br&gt;FINISH &#x3D; 4&lt;br&gt;VIA_REACHED &#x3D; 5&lt;br&gt;USE_ROUNDABOUT &#x3D; 6 | [optional] [default to null]
**AnnotationText** | **string** | optional - A text describing the instruction in more detail, e.g. like surface of the way, warnings or involved costs. | [optional] [default to null]
**AnnotationImportance** | **int32** | optional - 0 stands for INFO, 1 for warning, 2 for costs, 3 for costs and warning | [optional] [default to null]
**ExitNumber** | **int32** | optional - Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout. | [optional] [default to null]
**TurnAngle** | **float64** | optional - Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout - 0&amp;lt;r&amp;lt;2*PI for clockwise and -2PI&amp;lt;r&amp;lt;0 for counterclockwise transit. Null if the direction of rotation is undefined. | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


