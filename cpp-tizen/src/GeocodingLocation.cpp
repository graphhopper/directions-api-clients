#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "GeocodingLocation.h"

using namespace std;
using namespace Tizen::ArtikCloud;

GeocodingLocation::GeocodingLocation()
{
	//__init();
}

GeocodingLocation::~GeocodingLocation()
{
	//__cleanup();
}

void
GeocodingLocation::__init()
{
	//point = new GeocodingPoint();
	//osm_id = std::string();
	//osm_type = std::string();
	//osm_key = std::string();
	//name = std::string();
	//country = std::string();
	//city = std::string();
	//state = std::string();
	//street = std::string();
	//housenumber = std::string();
	//postcode = std::string();
}

void
GeocodingLocation::__cleanup()
{
	//if(point != NULL) {
	//
	//delete point;
	//point = NULL;
	//}
	//if(osm_id != NULL) {
	//
	//delete osm_id;
	//osm_id = NULL;
	//}
	//if(osm_type != NULL) {
	//
	//delete osm_type;
	//osm_type = NULL;
	//}
	//if(osm_key != NULL) {
	//
	//delete osm_key;
	//osm_key = NULL;
	//}
	//if(name != NULL) {
	//
	//delete name;
	//name = NULL;
	//}
	//if(country != NULL) {
	//
	//delete country;
	//country = NULL;
	//}
	//if(city != NULL) {
	//
	//delete city;
	//city = NULL;
	//}
	//if(state != NULL) {
	//
	//delete state;
	//state = NULL;
	//}
	//if(street != NULL) {
	//
	//delete street;
	//street = NULL;
	//}
	//if(housenumber != NULL) {
	//
	//delete housenumber;
	//housenumber = NULL;
	//}
	//if(postcode != NULL) {
	//
	//delete postcode;
	//postcode = NULL;
	//}
	//
}

void
GeocodingLocation::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *pointKey = "point";
	node = json_object_get_member(pJsonObject, pointKey);
	if (node !=NULL) {
	

		if (isprimitive("GeocodingPoint")) {
			jsonToValue(&point, node, "GeocodingPoint", "GeocodingPoint");
		} else {
			
			GeocodingPoint* obj = static_cast<GeocodingPoint*> (&point);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *osm_idKey = "osm_id";
	node = json_object_get_member(pJsonObject, osm_idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&osm_id, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *osm_typeKey = "osm_type";
	node = json_object_get_member(pJsonObject, osm_typeKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&osm_type, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *osm_keyKey = "osm_key";
	node = json_object_get_member(pJsonObject, osm_keyKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&osm_key, node, "std::string", "");
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
	const gchar *countryKey = "country";
	node = json_object_get_member(pJsonObject, countryKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&country, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *cityKey = "city";
	node = json_object_get_member(pJsonObject, cityKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&city, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *stateKey = "state";
	node = json_object_get_member(pJsonObject, stateKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&state, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *streetKey = "street";
	node = json_object_get_member(pJsonObject, streetKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&street, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *housenumberKey = "housenumber";
	node = json_object_get_member(pJsonObject, housenumberKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&housenumber, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *postcodeKey = "postcode";
	node = json_object_get_member(pJsonObject, postcodeKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&postcode, node, "std::string", "");
		} else {
			
		}
	}
}

GeocodingLocation::GeocodingLocation(char* json)
{
	this->fromJson(json);
}

char*
GeocodingLocation::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("GeocodingPoint")) {
		GeocodingPoint obj = getPoint();
		node = converttoJson(&obj, "GeocodingPoint", "");
	}
	else {
		
		GeocodingPoint obj = static_cast<GeocodingPoint> (getPoint());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *pointKey = "point";
	json_object_set_member(pJsonObject, pointKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getOsmId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *osm_idKey = "osm_id";
	json_object_set_member(pJsonObject, osm_idKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getOsmType();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *osm_typeKey = "osm_type";
	json_object_set_member(pJsonObject, osm_typeKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getOsmKey();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *osm_keyKey = "osm_key";
	json_object_set_member(pJsonObject, osm_keyKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getName();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *nameKey = "name";
	json_object_set_member(pJsonObject, nameKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getCountry();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *countryKey = "country";
	json_object_set_member(pJsonObject, countryKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getCity();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *cityKey = "city";
	json_object_set_member(pJsonObject, cityKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getState();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *stateKey = "state";
	json_object_set_member(pJsonObject, stateKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getStreet();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *streetKey = "street";
	json_object_set_member(pJsonObject, streetKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getHousenumber();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *housenumberKey = "housenumber";
	json_object_set_member(pJsonObject, housenumberKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getPostcode();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *postcodeKey = "postcode";
	json_object_set_member(pJsonObject, postcodeKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

GeocodingPoint
GeocodingLocation::getPoint()
{
	return point;
}

void
GeocodingLocation::setPoint(GeocodingPoint  point)
{
	this->point = point;
}

std::string
GeocodingLocation::getOsmId()
{
	return osm_id;
}

void
GeocodingLocation::setOsmId(std::string  osm_id)
{
	this->osm_id = osm_id;
}

std::string
GeocodingLocation::getOsmType()
{
	return osm_type;
}

void
GeocodingLocation::setOsmType(std::string  osm_type)
{
	this->osm_type = osm_type;
}

std::string
GeocodingLocation::getOsmKey()
{
	return osm_key;
}

void
GeocodingLocation::setOsmKey(std::string  osm_key)
{
	this->osm_key = osm_key;
}

std::string
GeocodingLocation::getName()
{
	return name;
}

void
GeocodingLocation::setName(std::string  name)
{
	this->name = name;
}

std::string
GeocodingLocation::getCountry()
{
	return country;
}

void
GeocodingLocation::setCountry(std::string  country)
{
	this->country = country;
}

std::string
GeocodingLocation::getCity()
{
	return city;
}

void
GeocodingLocation::setCity(std::string  city)
{
	this->city = city;
}

std::string
GeocodingLocation::getState()
{
	return state;
}

void
GeocodingLocation::setState(std::string  state)
{
	this->state = state;
}

std::string
GeocodingLocation::getStreet()
{
	return street;
}

void
GeocodingLocation::setStreet(std::string  street)
{
	this->street = street;
}

std::string
GeocodingLocation::getHousenumber()
{
	return housenumber;
}

void
GeocodingLocation::setHousenumber(std::string  housenumber)
{
	this->housenumber = housenumber;
}

std::string
GeocodingLocation::getPostcode()
{
	return postcode;
}

void
GeocodingLocation::setPostcode(std::string  postcode)
{
	this->postcode = postcode;
}


