#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Service.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Service::Service()
{
	//__init();
}

Service::~Service()
{
	//__cleanup();
}

void
Service::__init()
{
	//
	//
	//id = std::string();
	//
	//
	//type = std::string();
	//
	//
	//priority = int(0);
	//
	//
	//name = std::string();
	//
	//
	//address = new Address();
	//
	//
	//duration = long(0);
	//
	//
	//preparation_time = long(0);
	//
	//new std::list()std::list> time_windows;
	//
	//
	//new std::list()std::list> size;
	//
	//
	//new std::list()std::list> required_skills;
	//
	//
	//new std::list()std::list> allowed_vehicles;
	//
	//
}

void
Service::__cleanup()
{
	//if(id != NULL) {
	//
	//delete id;
	//id = NULL;
	//}
	//if(type != NULL) {
	//
	//delete type;
	//type = NULL;
	//}
	//if(priority != NULL) {
	//
	//delete priority;
	//priority = NULL;
	//}
	//if(name != NULL) {
	//
	//delete name;
	//name = NULL;
	//}
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
	//if(size != NULL) {
	//size.RemoveAll(true);
	//delete size;
	//size = NULL;
	//}
	//if(required_skills != NULL) {
	//required_skills.RemoveAll(true);
	//delete required_skills;
	//required_skills = NULL;
	//}
	//if(allowed_vehicles != NULL) {
	//allowed_vehicles.RemoveAll(true);
	//delete allowed_vehicles;
	//allowed_vehicles = NULL;
	//}
	//
}

void
Service::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *idKey = "id";
	node = json_object_get_member(pJsonObject, idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&id, node, "std::string", "");
		} else {
			
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
	const gchar *priorityKey = "priority";
	node = json_object_get_member(pJsonObject, priorityKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&priority, node, "int", "");
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
	const gchar *sizeKey = "size";
	node = json_object_get_member(pJsonObject, sizeKey);
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
			size = new_list;
		}
		
	}
	const gchar *required_skillsKey = "required_skills";
	node = json_object_get_member(pJsonObject, required_skillsKey);
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
			required_skills = new_list;
		}
		
	}
	const gchar *allowed_vehiclesKey = "allowed_vehicles";
	node = json_object_get_member(pJsonObject, allowed_vehiclesKey);
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
			allowed_vehicles = new_list;
		}
		
	}
}

Service::Service(char* json)
{
	this->fromJson(json);
}

char*
Service::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *idKey = "id";
	json_object_set_member(pJsonObject, idKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getType();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *typeKey = "type";
	json_object_set_member(pJsonObject, typeKey, node);
	if (isprimitive("int")) {
		int obj = getPriority();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *priorityKey = "priority";
	json_object_set_member(pJsonObject, priorityKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getName();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *nameKey = "name";
	json_object_set_member(pJsonObject, nameKey, node);
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
	if (isprimitive("int")) {
		list<int> new_list = static_cast<list <int> > (getSize());
		node = converttoJson(&new_list, "int", "array");
	} else {
		node = json_node_alloc();
		list<int> new_list = static_cast<list <int> > (getSize());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *sizeKey = "size";
	json_object_set_member(pJsonObject, sizeKey, node);
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getRequiredSkills());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getRequiredSkills());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *required_skillsKey = "required_skills";
	json_object_set_member(pJsonObject, required_skillsKey, node);
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getAllowedVehicles());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getAllowedVehicles());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *allowed_vehiclesKey = "allowed_vehicles";
	json_object_set_member(pJsonObject, allowed_vehiclesKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
Service::getId()
{
	return id;
}

void
Service::setId(std::string  id)
{
	this->id = id;
}

std::string
Service::getType()
{
	return type;
}

void
Service::setType(std::string  type)
{
	this->type = type;
}

int
Service::getPriority()
{
	return priority;
}

void
Service::setPriority(int  priority)
{
	this->priority = priority;
}

std::string
Service::getName()
{
	return name;
}

void
Service::setName(std::string  name)
{
	this->name = name;
}

Address
Service::getAddress()
{
	return address;
}

void
Service::setAddress(Address  address)
{
	this->address = address;
}

long long
Service::getDuration()
{
	return duration;
}

void
Service::setDuration(long long  duration)
{
	this->duration = duration;
}

long long
Service::getPreparationTime()
{
	return preparation_time;
}

void
Service::setPreparationTime(long long  preparation_time)
{
	this->preparation_time = preparation_time;
}

std::list<TimeWindow>
Service::getTimeWindows()
{
	return time_windows;
}

void
Service::setTimeWindows(std::list <TimeWindow> time_windows)
{
	this->time_windows = time_windows;
}

std::list<int>
Service::getSize()
{
	return size;
}

void
Service::setSize(std::list <int> size)
{
	this->size = size;
}

std::list<std::string>
Service::getRequiredSkills()
{
	return required_skills;
}

void
Service::setRequiredSkills(std::list <std::string> required_skills)
{
	this->required_skills = required_skills;
}

std::list<std::string>
Service::getAllowedVehicles()
{
	return allowed_vehicles;
}

void
Service::setAllowedVehicles(std::list <std::string> allowed_vehicles)
{
	this->allowed_vehicles = allowed_vehicles;
}


