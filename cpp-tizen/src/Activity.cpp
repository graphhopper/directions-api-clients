#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Activity.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Activity::Activity()
{
	//__init();
}

Activity::~Activity()
{
	//__cleanup();
}

void
Activity::__init()
{
	//type = std::string();
	//id = std::string();
	//location_id = std::string();
	//arr_time = long(0);
	//end_time = long(0);
	//waiting_time = long(0);
	//distance = long(0);
	//driving_time = long(0);
	//new std::list()std::list> load_before;
	//new std::list()std::list> load_after;
}

void
Activity::__cleanup()
{
	//if(type != NULL) {
	//
	//delete type;
	//type = NULL;
	//}
	//if(id != NULL) {
	//
	//delete id;
	//id = NULL;
	//}
	//if(location_id != NULL) {
	//
	//delete location_id;
	//location_id = NULL;
	//}
	//if(arr_time != NULL) {
	//
	//delete arr_time;
	//arr_time = NULL;
	//}
	//if(end_time != NULL) {
	//
	//delete end_time;
	//end_time = NULL;
	//}
	//if(waiting_time != NULL) {
	//
	//delete waiting_time;
	//waiting_time = NULL;
	//}
	//if(distance != NULL) {
	//
	//delete distance;
	//distance = NULL;
	//}
	//if(driving_time != NULL) {
	//
	//delete driving_time;
	//driving_time = NULL;
	//}
	//if(load_before != NULL) {
	//load_before.RemoveAll(true);
	//delete load_before;
	//load_before = NULL;
	//}
	//if(load_after != NULL) {
	//load_after.RemoveAll(true);
	//delete load_after;
	//load_after = NULL;
	//}
	//
}

void
Activity::fromJson(char* jsonStr)
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
	const gchar *idKey = "id";
	node = json_object_get_member(pJsonObject, idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&id, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *location_idKey = "location_id";
	node = json_object_get_member(pJsonObject, location_idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&location_id, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *arr_timeKey = "arr_time";
	node = json_object_get_member(pJsonObject, arr_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&arr_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *end_timeKey = "end_time";
	node = json_object_get_member(pJsonObject, end_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&end_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *waiting_timeKey = "waiting_time";
	node = json_object_get_member(pJsonObject, waiting_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&waiting_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *distanceKey = "distance";
	node = json_object_get_member(pJsonObject, distanceKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&distance, node, "long long", "");
		} else {
			
		}
	}
	const gchar *driving_timeKey = "driving_time";
	node = json_object_get_member(pJsonObject, driving_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&driving_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *load_beforeKey = "load_before";
	node = json_object_get_member(pJsonObject, load_beforeKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<int> new_list;
			int inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("int")) {
					jsonToValue(&inst, temp_json, "int", "");
				} else {
					
				}
				new_list.push_back(inst);
			}
			load_before = new_list;
		}
		
	}
	const gchar *load_afterKey = "load_after";
	node = json_object_get_member(pJsonObject, load_afterKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<int> new_list;
			int inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("int")) {
					jsonToValue(&inst, temp_json, "int", "");
				} else {
					
				}
				new_list.push_back(inst);
			}
			load_after = new_list;
		}
		
	}
}

Activity::Activity(char* json)
{
	this->fromJson(json);
}

char*
Activity::toJson()
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
		std::string obj = getId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *idKey = "id";
	json_object_set_member(pJsonObject, idKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getLocationId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *location_idKey = "location_id";
	json_object_set_member(pJsonObject, location_idKey, node);
	if (isprimitive("long long")) {
		long long obj = getArrTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *arr_timeKey = "arr_time";
	json_object_set_member(pJsonObject, arr_timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getEndTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *end_timeKey = "end_time";
	json_object_set_member(pJsonObject, end_timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getWaitingTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *waiting_timeKey = "waiting_time";
	json_object_set_member(pJsonObject, waiting_timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getDistance();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *distanceKey = "distance";
	json_object_set_member(pJsonObject, distanceKey, node);
	if (isprimitive("long long")) {
		long long obj = getDrivingTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *driving_timeKey = "driving_time";
	json_object_set_member(pJsonObject, driving_timeKey, node);
	if (isprimitive("int")) {
		list<int> new_list = static_cast<list <int> > (getLoadBefore());
		node = converttoJson(&new_list, "int", "array");
	} else {
		node = json_node_alloc();
		list<int> new_list = static_cast<list <int> > (getLoadBefore());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *load_beforeKey = "load_before";
	json_object_set_member(pJsonObject, load_beforeKey, node);
	if (isprimitive("int")) {
		list<int> new_list = static_cast<list <int> > (getLoadAfter());
		node = converttoJson(&new_list, "int", "array");
	} else {
		node = json_node_alloc();
		list<int> new_list = static_cast<list <int> > (getLoadAfter());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *load_afterKey = "load_after";
	json_object_set_member(pJsonObject, load_afterKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
Activity::getType()
{
	return type;
}

void
Activity::setType(std::string  type)
{
	this->type = type;
}

std::string
Activity::getId()
{
	return id;
}

void
Activity::setId(std::string  id)
{
	this->id = id;
}

std::string
Activity::getLocationId()
{
	return location_id;
}

void
Activity::setLocationId(std::string  location_id)
{
	this->location_id = location_id;
}

long long
Activity::getArrTime()
{
	return arr_time;
}

void
Activity::setArrTime(long long  arr_time)
{
	this->arr_time = arr_time;
}

long long
Activity::getEndTime()
{
	return end_time;
}

void
Activity::setEndTime(long long  end_time)
{
	this->end_time = end_time;
}

long long
Activity::getWaitingTime()
{
	return waiting_time;
}

void
Activity::setWaitingTime(long long  waiting_time)
{
	this->waiting_time = waiting_time;
}

long long
Activity::getDistance()
{
	return distance;
}

void
Activity::setDistance(long long  distance)
{
	this->distance = distance;
}

long long
Activity::getDrivingTime()
{
	return driving_time;
}

void
Activity::setDrivingTime(long long  driving_time)
{
	this->driving_time = driving_time;
}

std::list<int>
Activity::getLoadBefore()
{
	return load_before;
}

void
Activity::setLoadBefore(std::list <int> load_before)
{
	this->load_before = load_before;
}

std::list<int>
Activity::getLoadAfter()
{
	return load_after;
}

void
Activity::setLoadAfter(std::list <int> load_after)
{
	this->load_after = load_after;
}


