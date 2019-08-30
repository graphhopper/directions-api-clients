# GeocodingApi

All URIs are relative to *https://graphhopper.com/api/1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getGeocode**](GeocodingApi.md#getGeocode) | **GET** /geocode | Execute a geocoding request

<a name="getGeocode"></a>
# **getGeocode**
> GeocodingResponse getGeocode(q, locale, limit, reverse, debug, point, provider)

Execute a geocoding request

 ### Introduction  ![Geocoding Example](./img/geocoding-example.png)  _Geocoding_ describes the process of transforming an textual address representation to a coordinate (&#x60;latitude,longitude&#x60;). For example the conversion from &#x60;Berlin&#x60; to &#x60;52.5170365,13.3888599&#x60;.  _Reverse geocoding_ converts a coordinate to a textual address representation or place name. Find out more about Geocoding itself on [Wikipedia](http://en.wikipedia.org/wiki/Geocoding). 

### Example
```kotlin
// Import classes:
//import io.swagger.client.infrastructure.*
//import io.swagger.client.models.*;

val apiInstance = GeocodingApi()
val q : kotlin.String = q_example // kotlin.String | If you do forward geocoding, this is `required` and is a textual description of the address you are looking for.
val locale : kotlin.String = locale_example // kotlin.String | Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
val limit : kotlin.Int = 56 // kotlin.Int | Specify the maximum number of results to return
val reverse : kotlin.Boolean = true // kotlin.Boolean | It is `required` to be `true` if you want to do a reverse geocoding request. If it is `true`, `point` must be defined as well, and `q` must not be used.
val debug : kotlin.Boolean = true // kotlin.Boolean | If `true`, the output will be formatted.
val point : kotlin.String = point_example // kotlin.String | _Forward geocoding_: The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803. _Reverse geocoding_: The location to find amenities, cities.
val provider : kotlin.String = provider_example // kotlin.String | The provider parameter is currently under development and can fall back to `default` at any time. The intend is to provide alternatives to our default geocoder. Each provider has its own strenghts and might fit better for certain scenarios, so it's worth to compare the different providers. To try it append the `provider`parameter to the URL like `&provider=nominatim`, the result structure should be identical in all cases - if not, please report this back to us. Keep in mind that some providers do not support certain parameters or don't return some fields, for example `osm_id` and `osm_type` are not supported by every geocoding provider. If you would like to use additional parameters of one of the providers, but it's not available for the GraphHopper Geocoding, yet? Please contact us.  The credit costs can be different for all providers - see [here](https://support.graphhopper.com/support/solutions/articles/44000718211-what-is-one-credit-) for more information about it.  Currently, only the default provider and gisgraphy supports autocompletion of partial search strings.  All providers support normal \"forward\" geocoding and reverse geocoding via `reverse=true`.  #### Default (`provider=default`)  This provider returns results of our internal geocoding engine, as described above.  #### Nominatim (`provider=nominatim`)  The GraphHopper Directions API uses a commercially hosted Nominatim geocoder. You can try this provider [here](https://nominatim.openstreetmap.org/). The provider does **not** fall under the [restrictions](https://operations.osmfoundation.org/policies/nominatim/) of the Nominatim instance hosted by OpenStreetMap.  In addition to the above documented parameters Nominatim allows to use the following parameters, which can be used as documented [here](https://wiki.openstreetmap.org/wiki/Nominatim#Parameters):  * viewbox * viewboxlbrt * bounded  #### OpenCage Data (`provider=opencagedata`)  This provider returns results from the OpenCageData geocoder which you can try [here](https://geocoder.opencagedata.com/demo).  In addition to the above documented parameters OpenCage Data allows to use the following parameters, which can be used as documented [here](https://geocoder.opencagedata.com/api#forward-opt):  * countrycode * bounds  #### Gisgraphy (`provider=gisgraphy`)  This provider returns results from the Gisgraphy geocoder which you can try [here](https://services.gisgraphy.com/static/leaflet/index.html).  **Limitations:** Gisgraphy does not return tags from OSM nor an extent. The locale parameter is currently not supported for Gisgraphy.  Gisgraphy has a special autocomplete API, which you can use by adding `autocomplete=true` (does not work with `reverse=true`). The autocomplete API is optimized on predicting text input, but returns less information.  In addition to the above documented parameters Gisgraphy allows to use the following parameters, which can be used as documented [here](http://www.gisgraphy.com/documentation/user-guide.php):  * radius * country 
try {
    val result : GeocodingResponse = apiInstance.getGeocode(q, locale, limit, reverse, debug, point, provider)
    println(result)
} catch (e: ClientException) {
    println("4xx response calling GeocodingApi#getGeocode")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling GeocodingApi#getGeocode")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **q** | **kotlin.String**| If you do forward geocoding, this is &#x60;required&#x60; and is a textual description of the address you are looking for. | [optional]
 **locale** | **kotlin.String**| Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#x27;t found the default (en) is used. | [optional]
 **limit** | **kotlin.Int**| Specify the maximum number of results to return | [optional]
 **reverse** | **kotlin.Boolean**| It is &#x60;required&#x60; to be &#x60;true&#x60; if you want to do a reverse geocoding request. If it is &#x60;true&#x60;, &#x60;point&#x60; must be defined as well, and &#x60;q&#x60; must not be used. | [optional]
 **debug** | **kotlin.Boolean**| If &#x60;true&#x60;, the output will be formatted. | [optional]
 **point** | **kotlin.String**| _Forward geocoding_: The location bias in the format &#x27;latitude,longitude&#x27; e.g. point&#x3D;45.93272,11.58803. _Reverse geocoding_: The location to find amenities, cities. | [optional]
 **provider** | **kotlin.String**| The provider parameter is currently under development and can fall back to &#x60;default&#x60; at any time. The intend is to provide alternatives to our default geocoder. Each provider has its own strenghts and might fit better for certain scenarios, so it&#x27;s worth to compare the different providers. To try it append the &#x60;provider&#x60;parameter to the URL like &#x60;&amp;provider&#x3D;nominatim&#x60;, the result structure should be identical in all cases - if not, please report this back to us. Keep in mind that some providers do not support certain parameters or don&#x27;t return some fields, for example &#x60;osm_id&#x60; and &#x60;osm_type&#x60; are not supported by every geocoding provider. If you would like to use additional parameters of one of the providers, but it&#x27;s not available for the GraphHopper Geocoding, yet? Please contact us.  The credit costs can be different for all providers - see [here](https://support.graphhopper.com/support/solutions/articles/44000718211-what-is-one-credit-) for more information about it.  Currently, only the default provider and gisgraphy supports autocompletion of partial search strings.  All providers support normal \&quot;forward\&quot; geocoding and reverse geocoding via &#x60;reverse&#x3D;true&#x60;.  #### Default (&#x60;provider&#x3D;default&#x60;)  This provider returns results of our internal geocoding engine, as described above.  #### Nominatim (&#x60;provider&#x3D;nominatim&#x60;)  The GraphHopper Directions API uses a commercially hosted Nominatim geocoder. You can try this provider [here](https://nominatim.openstreetmap.org/). The provider does **not** fall under the [restrictions](https://operations.osmfoundation.org/policies/nominatim/) of the Nominatim instance hosted by OpenStreetMap.  In addition to the above documented parameters Nominatim allows to use the following parameters, which can be used as documented [here](https://wiki.openstreetmap.org/wiki/Nominatim#Parameters):  * viewbox * viewboxlbrt * bounded  #### OpenCage Data (&#x60;provider&#x3D;opencagedata&#x60;)  This provider returns results from the OpenCageData geocoder which you can try [here](https://geocoder.opencagedata.com/demo).  In addition to the above documented parameters OpenCage Data allows to use the following parameters, which can be used as documented [here](https://geocoder.opencagedata.com/api#forward-opt):  * countrycode * bounds  #### Gisgraphy (&#x60;provider&#x3D;gisgraphy&#x60;)  This provider returns results from the Gisgraphy geocoder which you can try [here](https://services.gisgraphy.com/static/leaflet/index.html).  **Limitations:** Gisgraphy does not return tags from OSM nor an extent. The locale parameter is currently not supported for Gisgraphy.  Gisgraphy has a special autocomplete API, which you can use by adding &#x60;autocomplete&#x3D;true&#x60; (does not work with &#x60;reverse&#x3D;true&#x60;). The autocomplete API is optimized on predicting text input, but returns less information.  In addition to the above documented parameters Gisgraphy allows to use the following parameters, which can be used as documented [here](http://www.gisgraphy.com/documentation/user-guide.php):  * radius * country  | [optional]

### Return type

[**GeocodingResponse**](GeocodingResponse.md)

### Authorization

[api_key](../README.md#api_key)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

