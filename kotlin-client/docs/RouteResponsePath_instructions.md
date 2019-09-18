# RouteResponsePathInstructions

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**text** | [**kotlin.String**](.md) | A description what the user has to do in order to follow the route. The language depends on the locale parameter.  |  [optional]
**streetName** | [**kotlin.String**](.md) | The name of the street to turn onto in order to follow the route.  |  [optional]
**distance** | [**kotlin.Double**](.md) | The distance for this instruction, in meters.  |  [optional]
**time** | [**kotlin.Int**](.md) | The duration for this instruction, in milliseconds.  |  [optional]
**interval** | [**kotlin.Array&lt;kotlin.Int&gt;**](.md) | Two indices into &#x60;points&#x60;, referring to the beginning and the end of the segment of the route this instruction refers to.  |  [optional]
**sign** | [**kotlin.Int**](.md) | A number which specifies the sign to show:  |   |   | |---|---| |TURN_SHARP_LEFT |-3| |TURN_LEFT | -2| |TURN_SLIGHT_LEFT | -1| |CONTINUE_ON_STREET | 0| |TURN_SLIGHT_RIGHT |1| |TURN_RIGHT | 2| |TURN_SHARP_RIGHT | 3| |FINISH | 4| |VIA_REACHED | 5| |USE_ROUNDABOUT | 6| |KEEP_RIGHT | 7|  |  [optional]
**exitNumber** | [**kotlin.Int**](.md) | Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout.  |  [optional]
**turnAngle** | [**kotlin.Double**](.md) | Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout &#x60;0 &lt; r &lt; 2*PI&#x60; for clockwise and &#x60;-2*PI &lt; r &lt; 0&#x60; for counterclockwise turns.  |  [optional]
