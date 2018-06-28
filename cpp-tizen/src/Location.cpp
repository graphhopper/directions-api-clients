#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Location.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Location::Location()
{
	//__init();
}

Location::~Location()
{
	//__cleanup();
}

void
Location::__init()
{
	//lon = double(0);
	//lat = double(0);
}

void
Location::__cleanup()
{
	//if(lon != NULL) {
	//
	//delete lon;
	//lon = NULL;
	//}
	//if(lat != NULL) {
	//
	//delete lat;
	//lat = NULL;
	//}
	//
}

void
Location::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *lonKey = "lon";
	node = json_object_get_member(pJsonObject, lonKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&lon, node, "double", "");
		} else {
			
		}
	}
	const gchar *latKey = "lat";
	node = json_object_get_member(pJsonObject, latKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&lat, node, "double", "");
		} else {
			
		}
	}
}

Location::Location(char* json)
{
	this->fromJson(json);
}

char*
Location::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("double")) {
		double obj = getLon();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *lonKey = "lon";
	json_object_set_member(pJsonObject, lonKey, node);
	if (isprimitive("double")) {
		double obj = getLat();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *latKey = "lat";
	json_object_set_member(pJsonObject, latKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

double
Location::getLon()
{
	return lon;
}

void
Location::setLon(double  lon)
{
	this->lon = lon;
}

double
Location::getLat()
{
	return lat;
}

void
Location::setLat(double  lat)
{
	this->lat = lat;
}


