#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "RoutePoint.h"

using namespace std;
using namespace Tizen::ArtikCloud;

RoutePoint::RoutePoint()
{
	//__init();
}

RoutePoint::~RoutePoint()
{
	//__cleanup();
}

void
RoutePoint::__init()
{
	//type = std::string();
	//new std::list()std::list> coordinates;
}

void
RoutePoint::__cleanup()
{
	//if(type != NULL) {
	//
	//delete type;
	//type = NULL;
	//}
	//if(coordinates != NULL) {
	//coordinates.RemoveAll(true);
	//delete coordinates;
	//coordinates = NULL;
	//}
	//
}

void
RoutePoint::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *typeKey = "type";
	node = json_object_get_member(pJsonObject, typeKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&type, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *coordinatesKey = "coordinates";
	node = json_object_get_member(pJsonObject, coordinatesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<std::string> new_list;
			std::string inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("std::string")) {
					jsonToValue(&inst, temp_json, "std::string", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			coordinates = new_list;
		}
		
	}
}

RoutePoint::RoutePoint(char* json)
{
	this->fromJson(json);
}

char*
RoutePoint::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getType();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *typeKey = "type";
	json_object_set_member(pJsonObject, typeKey, node);
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getCoordinates());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getCoordinates());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<std::string>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			std::string obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *coordinatesKey = "coordinates";
	json_object_set_member(pJsonObject, coordinatesKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
RoutePoint::getType()
{
	return type;
}

void
RoutePoint::setType(std::string  type)
{
	this->type = type;
}

std::list<std::string>
RoutePoint::getCoordinates()
{
	return coordinates;
}

void
RoutePoint::setCoordinates(std::list <std::string> coordinates)
{
	this->coordinates = coordinates;
}


