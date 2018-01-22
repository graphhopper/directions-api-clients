#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "CostMatrix_data.h"

using namespace std;
using namespace Tizen::ArtikCloud;

CostMatrix_data::CostMatrix_data()
{
	//__init();
}

CostMatrix_data::~CostMatrix_data()
{
	//__cleanup();
}

void
CostMatrix_data::__init()
{
	//
	//new std::list()std::list> times;
	//
	//
	//new std::list()std::list> distances;
	//
	//
	//
	//info = new CostMatrix_data_info();
	//
}

void
CostMatrix_data::__cleanup()
{
	//if(times != NULL) {
	//times.RemoveAll(true);
	//delete times;
	//times = NULL;
	//}
	//if(distances != NULL) {
	//distances.RemoveAll(true);
	//delete distances;
	//distances = NULL;
	//}
	//if(info != NULL) {
	//
	//delete info;
	//info = NULL;
	//}
	//
}

void
CostMatrix_data::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *timesKey = "times";
	node = json_object_get_member(pJsonObject, timesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<std::list> new_list;
			std::list inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("std::list")) {
					jsonToValue(&inst, temp_json, "std::list", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			times = new_list;
		}
		
	}
	const gchar *distancesKey = "distances";
	node = json_object_get_member(pJsonObject, distancesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<std::list> new_list;
			std::list inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("std::list")) {
					jsonToValue(&inst, temp_json, "std::list", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			distances = new_list;
		}
		
	}
	const gchar *infoKey = "info";
	node = json_object_get_member(pJsonObject, infoKey);
	if (node !=NULL) {
	

		if (isprimitive("CostMatrix_data_info")) {
			jsonToValue(&info, node, "CostMatrix_data_info", "CostMatrix_data_info");
		} else {
			
			CostMatrix_data_info* obj = static_cast<CostMatrix_data_info*> (&info);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

CostMatrix_data::CostMatrix_data(char* json)
{
	this->fromJson(json);
}

char*
CostMatrix_data::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::list")) {
		list<std::list> new_list = static_cast<list <std::list> > (getTimes());
		node = converttoJson(&new_list, "std::list", "array");
	} else {
		node = json_node_alloc();
		list<std::list> new_list = static_cast<list <std::list> > (getTimes());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<std::list>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			std::list obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *timesKey = "times";
	json_object_set_member(pJsonObject, timesKey, node);
	if (isprimitive("std::list")) {
		list<std::list> new_list = static_cast<list <std::list> > (getDistances());
		node = converttoJson(&new_list, "std::list", "array");
	} else {
		node = json_node_alloc();
		list<std::list> new_list = static_cast<list <std::list> > (getDistances());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<std::list>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			std::list obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *distancesKey = "distances";
	json_object_set_member(pJsonObject, distancesKey, node);
	if (isprimitive("CostMatrix_data_info")) {
		CostMatrix_data_info obj = getInfo();
		node = converttoJson(&obj, "CostMatrix_data_info", "");
	}
	else {
		
		CostMatrix_data_info obj = static_cast<CostMatrix_data_info> (getInfo());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *infoKey = "info";
	json_object_set_member(pJsonObject, infoKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::list<std::list>
CostMatrix_data::getTimes()
{
	return times;
}

void
CostMatrix_data::setTimes(std::list <std::list> times)
{
	this->times = times;
}

std::list<std::list>
CostMatrix_data::getDistances()
{
	return distances;
}

void
CostMatrix_data::setDistances(std::list <std::list> distances)
{
	this->distances = distances;
}

CostMatrix_data_info
CostMatrix_data::getInfo()
{
	return info;
}

void
CostMatrix_data::setInfo(CostMatrix_data_info  info)
{
	this->info = info;
}


