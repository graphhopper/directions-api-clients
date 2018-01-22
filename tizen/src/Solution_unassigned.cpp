#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Solution_unassigned.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Solution_unassigned::Solution_unassigned()
{
	//__init();
}

Solution_unassigned::~Solution_unassigned()
{
	//__cleanup();
}

void
Solution_unassigned::__init()
{
	//
	//new std::list()std::list> services;
	//
	//
	//new std::list()std::list> shipments;
	//
	//
}

void
Solution_unassigned::__cleanup()
{
	//if(services != NULL) {
	//services.RemoveAll(true);
	//delete services;
	//services = NULL;
	//}
	//if(shipments != NULL) {
	//shipments.RemoveAll(true);
	//delete shipments;
	//shipments = NULL;
	//}
	//
}

void
Solution_unassigned::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *servicesKey = "services";
	node = json_object_get_member(pJsonObject, servicesKey);
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
			services = new_list;
		}
		
	}
	const gchar *shipmentsKey = "shipments";
	node = json_object_get_member(pJsonObject, shipmentsKey);
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
			shipments = new_list;
		}
		
	}
}

Solution_unassigned::Solution_unassigned(char* json)
{
	this->fromJson(json);
}

char*
Solution_unassigned::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getServices());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getServices());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *servicesKey = "services";
	json_object_set_member(pJsonObject, servicesKey, node);
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getShipments());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getShipments());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *shipmentsKey = "shipments";
	json_object_set_member(pJsonObject, shipmentsKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::list<std::string>
Solution_unassigned::getServices()
{
	return services;
}

void
Solution_unassigned::setServices(std::list <std::string> services)
{
	this->services = services;
}

std::list<std::string>
Solution_unassigned::getShipments()
{
	return shipments;
}

void
Solution_unassigned::setShipments(std::list <std::string> shipments)
{
	this->shipments = shipments;
}


