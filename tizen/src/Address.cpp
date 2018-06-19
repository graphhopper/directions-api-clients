#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Address.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Address::Address()
{
	//__init();
}

Address::~Address()
{
	//__cleanup();
}

void
Address::__init()
{
	//
	//
	//location_id = std::string();
	//
	//
	//name = std::string();
	//
	//
	//lon = double(0);
	//
	//
	//lat = double(0);
	//
	//
	//street_hint = std::string();
	//
}

void
Address::__cleanup()
{
	//if(location_id != NULL) {
	//
	//delete location_id;
	//location_id = NULL;
	//}
	//if(name != NULL) {
	//
	//delete name;
	//name = NULL;
	//}
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
	//if(street_hint != NULL) {
	//
	//delete street_hint;
	//street_hint = NULL;
	//}
	//
}

void
Address::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *location_idKey = "location_id";
	node = json_object_get_member(pJsonObject, location_idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&location_id, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *nameKey = "name";
	node = json_object_get_member(pJsonObject, nameKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&name, node, "std::string", "");
		} else {
			
		}
	}
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
	const gchar *street_hintKey = "street_hint";
	node = json_object_get_member(pJsonObject, street_hintKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&street_hint, node, "std::string", "");
		} else {
			
		}
	}
}

Address::Address(char* json)
{
	this->fromJson(json);
}

char*
Address::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getLocationId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *location_idKey = "location_id";
	json_object_set_member(pJsonObject, location_idKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getName();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *nameKey = "name";
	json_object_set_member(pJsonObject, nameKey, node);
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
	if (isprimitive("std::string")) {
		std::string obj = getStreetHint();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *street_hintKey = "street_hint";
	json_object_set_member(pJsonObject, street_hintKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
Address::getLocationId()
{
	return location_id;
}

void
Address::setLocationId(std::string  location_id)
{
	this->location_id = location_id;
}

std::string
Address::getName()
{
	return name;
}

void
Address::setName(std::string  name)
{
	this->name = name;
}

double
Address::getLon()
{
	return lon;
}

void
Address::setLon(double  lon)
{
	this->lon = lon;
}

double
Address::getLat()
{
	return lat;
}

void
Address::setLat(double  lat)
{
	this->lat = lat;
}

std::string
Address::getStreetHint()
{
	return street_hint;
}

void
Address::setStreetHint(std::string  street_hint)
{
	this->street_hint = street_hint;
}


