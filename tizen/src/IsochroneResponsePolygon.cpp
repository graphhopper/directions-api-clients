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
	//
	//
	//properties = new IsochroneResponsePolygon_properties();
	//
	//
	//type = std::string();
	//
	//
	//geometry = new IsochroneResponsePolygon_geometry();
	//
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
	

		if (isprimitive("IsochroneResponsePolygon_properties")) {
			jsonToValue(&properties, node, "IsochroneResponsePolygon_properties", "IsochroneResponsePolygon_properties");
		} else {
			
			IsochroneResponsePolygon_properties* obj = static_cast<IsochroneResponsePolygon_properties*> (&properties);
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
	

		if (isprimitive("IsochroneResponsePolygon_geometry")) {
			jsonToValue(&geometry, node, "IsochroneResponsePolygon_geometry", "IsochroneResponsePolygon_geometry");
		} else {
			
			IsochroneResponsePolygon_geometry* obj = static_cast<IsochroneResponsePolygon_geometry*> (&geometry);
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
	if (isprimitive("IsochroneResponsePolygon_properties")) {
		IsochroneResponsePolygon_properties obj = getProperties();
		node = converttoJson(&obj, "IsochroneResponsePolygon_properties", "");
	}
	else {
		
		IsochroneResponsePolygon_properties obj = static_cast<IsochroneResponsePolygon_properties> (getProperties());
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
	if (isprimitive("IsochroneResponsePolygon_geometry")) {
		IsochroneResponsePolygon_geometry obj = getGeometry();
		node = converttoJson(&obj, "IsochroneResponsePolygon_geometry", "");
	}
	else {
		
		IsochroneResponsePolygon_geometry obj = static_cast<IsochroneResponsePolygon_geometry> (getGeometry());
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

IsochroneResponsePolygon_properties
IsochroneResponsePolygon::getProperties()
{
	return properties;
}

void
IsochroneResponsePolygon::setProperties(IsochroneResponsePolygon_properties  properties)
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

IsochroneResponsePolygon_geometry
IsochroneResponsePolygon::getGeometry()
{
	return geometry;
}

void
IsochroneResponsePolygon::setGeometry(IsochroneResponsePolygon_geometry  geometry)
{
	this->geometry = geometry;
}


