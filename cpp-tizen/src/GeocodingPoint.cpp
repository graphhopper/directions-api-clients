#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "GeocodingPoint.h"

using namespace std;
using namespace Tizen::ArtikCloud;

GeocodingPoint::GeocodingPoint()
{
	//__init();
}

GeocodingPoint::~GeocodingPoint()
{
	//__cleanup();
}

void
GeocodingPoint::__init()
{
	//lat = double(0);
	//lng = double(0);
}

void
GeocodingPoint::__cleanup()
{
	//if(lat != NULL) {
	//
	//delete lat;
	//lat = NULL;
	//}
	//if(lng != NULL) {
	//
	//delete lng;
	//lng = NULL;
	//}
	//
}

void
GeocodingPoint::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *latKey = "lat";
	node = json_object_get_member(pJsonObject, latKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&lat, node, "double", "");
		} else {
			
		}
	}
	const gchar *lngKey = "lng";
	node = json_object_get_member(pJsonObject, lngKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&lng, node, "double", "");
		} else {
			
		}
	}
}

GeocodingPoint::GeocodingPoint(char* json)
{
	this->fromJson(json);
}

char*
GeocodingPoint::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("double")) {
		double obj = getLat();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *latKey = "lat";
	json_object_set_member(pJsonObject, latKey, node);
	if (isprimitive("double")) {
		double obj = getLng();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *lngKey = "lng";
	json_object_set_member(pJsonObject, lngKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

double
GeocodingPoint::getLat()
{
	return lat;
}

void
GeocodingPoint::setLat(double  lat)
{
	this->lat = lat;
}

double
GeocodingPoint::getLng()
{
	return lng;
}

void
GeocodingPoint::setLng(double  lng)
{
	this->lng = lng;
}


