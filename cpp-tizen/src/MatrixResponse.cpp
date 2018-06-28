#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "MatrixResponse.h"

using namespace std;
using namespace Tizen::ArtikCloud;

MatrixResponse::MatrixResponse()
{
	//__init();
}

MatrixResponse::~MatrixResponse()
{
	//__cleanup();
}

void
MatrixResponse::__init()
{
	//new std::list()std::list> distances;
	//new std::list()std::list> times;
	//new std::list()std::list> weights;
	//info = new ResponseInfo();
}

void
MatrixResponse::__cleanup()
{
	//if(distances != NULL) {
	//distances.RemoveAll(true);
	//delete distances;
	//distances = NULL;
	//}
	//if(times != NULL) {
	//times.RemoveAll(true);
	//delete times;
	//times = NULL;
	//}
	//if(weights != NULL) {
	//weights.RemoveAll(true);
	//delete weights;
	//weights = NULL;
	//}
	//if(info != NULL) {
	//
	//delete info;
	//info = NULL;
	//}
	//
}

void
MatrixResponse::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
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
	const gchar *weightsKey = "weights";
	node = json_object_get_member(pJsonObject, weightsKey);
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
			weights = new_list;
		}
		
	}
	const gchar *infoKey = "info";
	node = json_object_get_member(pJsonObject, infoKey);
	if (node !=NULL) {
	

		if (isprimitive("ResponseInfo")) {
			jsonToValue(&info, node, "ResponseInfo", "ResponseInfo");
		} else {
			
			ResponseInfo* obj = static_cast<ResponseInfo*> (&info);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

MatrixResponse::MatrixResponse(char* json)
{
	this->fromJson(json);
}

char*
MatrixResponse::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
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
		list<std::list> new_list = static_cast<list <std::list> > (getWeights());
		node = converttoJson(&new_list, "std::list", "array");
	} else {
		node = json_node_alloc();
		list<std::list> new_list = static_cast<list <std::list> > (getWeights());
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


	
	const gchar *weightsKey = "weights";
	json_object_set_member(pJsonObject, weightsKey, node);
	if (isprimitive("ResponseInfo")) {
		ResponseInfo obj = getInfo();
		node = converttoJson(&obj, "ResponseInfo", "");
	}
	else {
		
		ResponseInfo obj = static_cast<ResponseInfo> (getInfo());
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
MatrixResponse::getDistances()
{
	return distances;
}

void
MatrixResponse::setDistances(std::list <std::list> distances)
{
	this->distances = distances;
}

std::list<std::list>
MatrixResponse::getTimes()
{
	return times;
}

void
MatrixResponse::setTimes(std::list <std::list> times)
{
	this->times = times;
}

std::list<std::list>
MatrixResponse::getWeights()
{
	return weights;
}

void
MatrixResponse::setWeights(std::list <std::list> weights)
{
	this->weights = weights;
}

ResponseInfo
MatrixResponse::getInfo()
{
	return info;
}

void
MatrixResponse::setInfo(ResponseInfo  info)
{
	this->info = info;
}


