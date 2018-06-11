#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Shipment.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Shipment::Shipment()
{
	//__init();
}

Shipment::~Shipment()
{
	//__cleanup();
}

void
Shipment::__init()
{
	//
	//
	//id = std::string();
	//
	//
	//name = std::string();
	//
	//
	//priority = int(0);
	//
	//
	//pickup = new Stop();
	//
	//
	//delivery = new Stop();
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
	//new std::list()std::list> disallowed_vehicles;
	//
	//
	//
	//max_time_in_vehicle = long(0);
	//
}

void
Shipment::__cleanup()
{
	//if(id != NULL) {
	//
	//delete id;
	//id = NULL;
	//}
	//if(name != NULL) {
	//
	//delete name;
	//name = NULL;
	//}
	//if(priority != NULL) {
	//
	//delete priority;
	//priority = NULL;
	//}
	//if(pickup != NULL) {
	//
	//delete pickup;
	//pickup = NULL;
	//}
	//if(delivery != NULL) {
	//
	//delete delivery;
	//delivery = NULL;
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
	//if(disallowed_vehicles != NULL) {
	//disallowed_vehicles.RemoveAll(true);
	//delete disallowed_vehicles;
	//disallowed_vehicles = NULL;
	//}
	//if(max_time_in_vehicle != NULL) {
	//
	//delete max_time_in_vehicle;
	//max_time_in_vehicle = NULL;
	//}
	//
}

void
Shipment::fromJson(char* jsonStr)
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
	const gchar *nameKey = "name";
	node = json_object_get_member(pJsonObject, nameKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&name, node, "std::string", "");
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
	const gchar *pickupKey = "pickup";
	node = json_object_get_member(pJsonObject, pickupKey);
	if (node !=NULL) {
	

		if (isprimitive("Stop")) {
			jsonToValue(&pickup, node, "Stop", "Stop");
		} else {
			
			Stop* obj = static_cast<Stop*> (&pickup);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *deliveryKey = "delivery";
	node = json_object_get_member(pJsonObject, deliveryKey);
	if (node !=NULL) {
	

		if (isprimitive("Stop")) {
			jsonToValue(&delivery, node, "Stop", "Stop");
		} else {
			
			Stop* obj = static_cast<Stop*> (&delivery);
			obj->fromJson(json_to_string(node, false));
			
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
	const gchar *disallowed_vehiclesKey = "disallowed_vehicles";
	node = json_object_get_member(pJsonObject, disallowed_vehiclesKey);
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
			disallowed_vehicles = new_list;
		}
		
	}
	const gchar *max_time_in_vehicleKey = "max_time_in_vehicle";
	node = json_object_get_member(pJsonObject, max_time_in_vehicleKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&max_time_in_vehicle, node, "long long", "");
		} else {
			
		}
	}
}

Shipment::Shipment(char* json)
{
	this->fromJson(json);
}

char*
Shipment::toJson()
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
		std::string obj = getName();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *nameKey = "name";
	json_object_set_member(pJsonObject, nameKey, node);
	if (isprimitive("int")) {
		int obj = getPriority();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *priorityKey = "priority";
	json_object_set_member(pJsonObject, priorityKey, node);
	if (isprimitive("Stop")) {
		Stop obj = getPickup();
		node = converttoJson(&obj, "Stop", "");
	}
	else {
		
		Stop obj = static_cast<Stop> (getPickup());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *pickupKey = "pickup";
	json_object_set_member(pJsonObject, pickupKey, node);
	if (isprimitive("Stop")) {
		Stop obj = getDelivery();
		node = converttoJson(&obj, "Stop", "");
	}
	else {
		
		Stop obj = static_cast<Stop> (getDelivery());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *deliveryKey = "delivery";
	json_object_set_member(pJsonObject, deliveryKey, node);
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
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getDisallowedVehicles());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getDisallowedVehicles());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *disallowed_vehiclesKey = "disallowed_vehicles";
	json_object_set_member(pJsonObject, disallowed_vehiclesKey, node);
	if (isprimitive("long long")) {
		long long obj = getMaxTimeInVehicle();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *max_time_in_vehicleKey = "max_time_in_vehicle";
	json_object_set_member(pJsonObject, max_time_in_vehicleKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
Shipment::getId()
{
	return id;
}

void
Shipment::setId(std::string  id)
{
	this->id = id;
}

std::string
Shipment::getName()
{
	return name;
}

void
Shipment::setName(std::string  name)
{
	this->name = name;
}

int
Shipment::getPriority()
{
	return priority;
}

void
Shipment::setPriority(int  priority)
{
	this->priority = priority;
}

Stop
Shipment::getPickup()
{
	return pickup;
}

void
Shipment::setPickup(Stop  pickup)
{
	this->pickup = pickup;
}

Stop
Shipment::getDelivery()
{
	return delivery;
}

void
Shipment::setDelivery(Stop  delivery)
{
	this->delivery = delivery;
}

std::list<int>
Shipment::getSize()
{
	return size;
}

void
Shipment::setSize(std::list <int> size)
{
	this->size = size;
}

std::list<std::string>
Shipment::getRequiredSkills()
{
	return required_skills;
}

void
Shipment::setRequiredSkills(std::list <std::string> required_skills)
{
	this->required_skills = required_skills;
}

std::list<std::string>
Shipment::getAllowedVehicles()
{
	return allowed_vehicles;
}

void
Shipment::setAllowedVehicles(std::list <std::string> allowed_vehicles)
{
	this->allowed_vehicles = allowed_vehicles;
}

std::list<std::string>
Shipment::getDisallowedVehicles()
{
	return disallowed_vehicles;
}

void
Shipment::setDisallowedVehicles(std::list <std::string> disallowed_vehicles)
{
	this->disallowed_vehicles = disallowed_vehicles;
}

long long
Shipment::getMaxTimeInVehicle()
{
	return max_time_in_vehicle;
}

void
Shipment::setMaxTimeInVehicle(long long  max_time_in_vehicle)
{
	this->max_time_in_vehicle = max_time_in_vehicle;
}


