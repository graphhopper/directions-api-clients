#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Relation.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Relation::Relation()
{
	//__init();
}

Relation::~Relation()
{
	//__cleanup();
}

void
Relation::__init()
{
	//type = std::string();
	//new std::list()std::list> ids;
	//vehicle_id = std::string();
}

void
Relation::__cleanup()
{
	//if(type != NULL) {
	//
	//delete type;
	//type = NULL;
	//}
	//if(ids != NULL) {
	//ids.RemoveAll(true);
	//delete ids;
	//ids = NULL;
	//}
	//if(vehicle_id != NULL) {
	//
	//delete vehicle_id;
	//vehicle_id = NULL;
	//}
	//
}

void
Relation::fromJson(char* jsonStr)
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
	const gchar *idsKey = "ids";
	node = json_object_get_member(pJsonObject, idsKey);
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
					
				}
				new_list.push_back(inst);
			}
			ids = new_list;
		}
		
	}
	const gchar *vehicle_idKey = "vehicle_id";
	node = json_object_get_member(pJsonObject, vehicle_idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&vehicle_id, node, "std::string", "");
		} else {
			
		}
	}
}

Relation::Relation(char* json)
{
	this->fromJson(json);
}

char*
Relation::toJson()
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
		list<std::string> new_list = static_cast<list <std::string> > (getIds());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getIds());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *idsKey = "ids";
	json_object_set_member(pJsonObject, idsKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getVehicleId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *vehicle_idKey = "vehicle_id";
	json_object_set_member(pJsonObject, vehicle_idKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
Relation::getType()
{
	return type;
}

void
Relation::setType(std::string  type)
{
	this->type = type;
}

std::list<std::string>
Relation::getIds()
{
	return ids;
}

void
Relation::setIds(std::list <std::string> ids)
{
	this->ids = ids;
}

std::string
Relation::getVehicleId()
{
	return vehicle_id;
}

void
Relation::setVehicleId(std::string  vehicle_id)
{
	this->vehicle_id = vehicle_id;
}


