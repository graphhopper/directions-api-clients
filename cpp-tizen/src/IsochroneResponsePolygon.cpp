#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "IsochroneResponsePolygon.h"

using namespace std;
using namespace Tizen::ArtikCloud;

IsochroneResponsePolygon::IsochroneResponsePolygon()
{
	//__init();
}

IsochroneResponsePolygon::~IsochroneResponsePolygon()
{
	//__cleanup();
}

void
IsochroneResponsePolygon::__init()
{
	//properties = null;
	//type = std::string();
	//geometry = null;
}

void
IsochroneResponsePolygon::__cleanup()
{
	//if(properties != NULL) {
	//
	//delete properties;
	//properties = NULL;
	//}
	//if(type != NULL) {
	//
	//delete type;
	//type = NULL;
	//}
	//if(geometry != NULL) {
	//
	//delete geometry;
	//geometry = NULL;
	//}
	//
}

void
IsochroneResponsePolygon::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *propertiesKey = "properties";
	node = json_object_get_member(pJsonObject, propertiesKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&properties, node, "std::string", "");
		} else {
			
			std::string* obj = static_cast<std::string*> (&properties);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *typeKey = "type";
	node = json_object_get_member(pJsonObject, typeKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&type, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *geometryKey = "geometry";
	node = json_object_get_member(pJsonObject, geometryKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&geometry, node, "std::string", "");
		} else {
			
			std::string* obj = static_cast<std::string*> (&geometry);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

IsochroneResponsePolygon::IsochroneResponsePolygon(char* json)
{
	this->fromJson(json);
}

char*
IsochroneResponsePolygon::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getProperties();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
		std::string obj = static_cast<std::string> (getProperties());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *propertiesKey = "properties";
	json_object_set_member(pJsonObject, propertiesKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getType();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *typeKey = "type";
	json_object_set_member(pJsonObject, typeKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getGeometry();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
		std::string obj = static_cast<std::string> (getGeometry());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *geometryKey = "geometry";
	json_object_set_member(pJsonObject, geometryKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
IsochroneResponsePolygon::getProperties()
{
	return properties;
}

void
IsochroneResponsePolygon::setProperties(std::string  properties)
{
	this->properties = properties;
}

std::string
IsochroneResponsePolygon::getType()
{
	return type;
}

void
IsochroneResponsePolygon::setType(std::string  type)
{
	this->type = type;
}

std::string
IsochroneResponsePolygon::getGeometry()
{
	return geometry;
}

void
IsochroneResponsePolygon::setGeometry(std::string  geometry)
{
	this->geometry = geometry;
}


