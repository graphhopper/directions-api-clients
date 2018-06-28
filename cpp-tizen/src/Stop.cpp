#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Stop.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Stop::Stop()
{
	//__init();
}

Stop::~Stop()
{
	//__cleanup();
}

void
Stop::__init()
{
	//address = new Address();
	//duration = long(0);
	//preparation_time = long(0);
	//new std::list()std::list> time_windows;
}

void
Stop::__cleanup()
{
	//if(address != NULL) {
	//
	//delete address;
	//address = NULL;
	//}
	//if(duration != NULL) {
	//
	//delete duration;
	//duration = NULL;
	//}
	//if(preparation_time != NULL) {
	//
	//delete preparation_time;
	//preparation_time = NULL;
	//}
	//if(time_windows != NULL) {
	//time_windows.RemoveAll(true);
	//delete time_windows;
	//time_windows = NULL;
	//}
	//
}

void
Stop::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *addressKey = "address";
	node = json_object_get_member(pJsonObject, addressKey);
	if (node !=NULL) {
	

		if (isprimitive("Address")) {
			jsonToValue(&address, node, "Address", "Address");
		} else {
			
			Address* obj = static_cast<Address*> (&address);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *durationKey = "duration";
	node = json_object_get_member(pJsonObject, durationKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&duration, node, "long long", "");
		} else {
			
		}
	}
	const gchar *preparation_timeKey = "preparation_time";
	node = json_object_get_member(pJsonObject, preparation_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&preparation_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *time_windowsKey = "time_windows";
	node = json_object_get_member(pJsonObject, time_windowsKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<TimeWindow> new_list;
			TimeWindow inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("TimeWindow")) {
					jsonToValue(&inst, temp_json, "TimeWindow", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			time_windows = new_list;
		}
		
	}
}

Stop::Stop(char* json)
{
	this->fromJson(json);
}

char*
Stop::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("Address")) {
		Address obj = getAddress();
		node = converttoJson(&obj, "Address", "");
	}
	else {
		
		Address obj = static_cast<Address> (getAddress());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *addressKey = "address";
	json_object_set_member(pJsonObject, addressKey, node);
	if (isprimitive("long long")) {
		long long obj = getDuration();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *durationKey = "duration";
	json_object_set_member(pJsonObject, durationKey, node);
	if (isprimitive("long long")) {
		long long obj = getPreparationTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *preparation_timeKey = "preparation_time";
	json_object_set_member(pJsonObject, preparation_timeKey, node);
	if (isprimitive("TimeWindow")) {
		list<TimeWindow> new_list = static_cast<list <TimeWindow> > (getTimeWindows());
		node = converttoJson(&new_list, "TimeWindow", "array");
	} else {
		node = json_node_alloc();
		list<TimeWindow> new_list = static_cast<list <TimeWindow> > (getTimeWindows());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<TimeWindow>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			TimeWindow obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *time_windowsKey = "time_windows";
	json_object_set_member(pJsonObject, time_windowsKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

Address
Stop::getAddress()
{
	return address;
}

void
Stop::setAddress(Address  address)
{
	this->address = address;
}

long long
Stop::getDuration()
{
	return duration;
}

void
Stop::setDuration(long long  duration)
{
	this->duration = duration;
}

long long
Stop::getPreparationTime()
{
	return preparation_time;
}

void
Stop::setPreparationTime(long long  preparation_time)
{
	this->preparation_time = preparation_time;
}

std::list<TimeWindow>
Stop::getTimeWindows()
{
	return time_windows;
}

void
Stop::setTimeWindows(std::list <TimeWindow> time_windows)
{
	this->time_windows = time_windows;
}


