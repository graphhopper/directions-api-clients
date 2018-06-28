#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "VehicleType.h"

using namespace std;
using namespace Tizen::ArtikCloud;

VehicleType::VehicleType()
{
	//__init();
}

VehicleType::~VehicleType()
{
	//__cleanup();
}

void
VehicleType::__init()
{
	//type_id = std::string();
	//profile = std::string();
	//new std::list()std::list> capacity;
	//speed_factor = double(0);
	//service_time_factor = double(0);
	//cost_per_meter = double(0);
	//cost_per_second = double(0);
	//cost_per_activation = double(0);
}

void
VehicleType::__cleanup()
{
	//if(type_id != NULL) {
	//
	//delete type_id;
	//type_id = NULL;
	//}
	//if(profile != NULL) {
	//
	//delete profile;
	//profile = NULL;
	//}
	//if(capacity != NULL) {
	//capacity.RemoveAll(true);
	//delete capacity;
	//capacity = NULL;
	//}
	//if(speed_factor != NULL) {
	//
	//delete speed_factor;
	//speed_factor = NULL;
	//}
	//if(service_time_factor != NULL) {
	//
	//delete service_time_factor;
	//service_time_factor = NULL;
	//}
	//if(cost_per_meter != NULL) {
	//
	//delete cost_per_meter;
	//cost_per_meter = NULL;
	//}
	//if(cost_per_second != NULL) {
	//
	//delete cost_per_second;
	//cost_per_second = NULL;
	//}
	//if(cost_per_activation != NULL) {
	//
	//delete cost_per_activation;
	//cost_per_activation = NULL;
	//}
	//
}

void
VehicleType::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *type_idKey = "type_id";
	node = json_object_get_member(pJsonObject, type_idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&type_id, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *profileKey = "profile";
	node = json_object_get_member(pJsonObject, profileKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&profile, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *capacityKey = "capacity";
	node = json_object_get_member(pJsonObject, capacityKey);
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
			capacity = new_list;
		}
		
	}
	const gchar *speed_factorKey = "speed_factor";
	node = json_object_get_member(pJsonObject, speed_factorKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&speed_factor, node, "double", "");
		} else {
			
		}
	}
	const gchar *service_time_factorKey = "service_time_factor";
	node = json_object_get_member(pJsonObject, service_time_factorKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&service_time_factor, node, "double", "");
		} else {
			
		}
	}
	const gchar *cost_per_meterKey = "cost_per_meter";
	node = json_object_get_member(pJsonObject, cost_per_meterKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&cost_per_meter, node, "double", "");
		} else {
			
		}
	}
	const gchar *cost_per_secondKey = "cost_per_second";
	node = json_object_get_member(pJsonObject, cost_per_secondKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&cost_per_second, node, "double", "");
		} else {
			
		}
	}
	const gchar *cost_per_activationKey = "cost_per_activation";
	node = json_object_get_member(pJsonObject, cost_per_activationKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&cost_per_activation, node, "double", "");
		} else {
			
		}
	}
}

VehicleType::VehicleType(char* json)
{
	this->fromJson(json);
}

char*
VehicleType::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getTypeId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *type_idKey = "type_id";
	json_object_set_member(pJsonObject, type_idKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getProfile();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *profileKey = "profile";
	json_object_set_member(pJsonObject, profileKey, node);
	if (isprimitive("int")) {
		list<int> new_list = static_cast<list <int> > (getCapacity());
		node = converttoJson(&new_list, "int", "array");
	} else {
		node = json_node_alloc();
		list<int> new_list = static_cast<list <int> > (getCapacity());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *capacityKey = "capacity";
	json_object_set_member(pJsonObject, capacityKey, node);
	if (isprimitive("double")) {
		double obj = getSpeedFactor();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *speed_factorKey = "speed_factor";
	json_object_set_member(pJsonObject, speed_factorKey, node);
	if (isprimitive("double")) {
		double obj = getServiceTimeFactor();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *service_time_factorKey = "service_time_factor";
	json_object_set_member(pJsonObject, service_time_factorKey, node);
	if (isprimitive("double")) {
		double obj = getCostPerMeter();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *cost_per_meterKey = "cost_per_meter";
	json_object_set_member(pJsonObject, cost_per_meterKey, node);
	if (isprimitive("double")) {
		double obj = getCostPerSecond();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *cost_per_secondKey = "cost_per_second";
	json_object_set_member(pJsonObject, cost_per_secondKey, node);
	if (isprimitive("double")) {
		double obj = getCostPerActivation();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *cost_per_activationKey = "cost_per_activation";
	json_object_set_member(pJsonObject, cost_per_activationKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
VehicleType::getTypeId()
{
	return type_id;
}

void
VehicleType::setTypeId(std::string  type_id)
{
	this->type_id = type_id;
}

std::string
VehicleType::getProfile()
{
	return profile;
}

void
VehicleType::setProfile(std::string  profile)
{
	this->profile = profile;
}

std::list<int>
VehicleType::getCapacity()
{
	return capacity;
}

void
VehicleType::setCapacity(std::list <int> capacity)
{
	this->capacity = capacity;
}

double
VehicleType::getSpeedFactor()
{
	return speed_factor;
}

void
VehicleType::setSpeedFactor(double  speed_factor)
{
	this->speed_factor = speed_factor;
}

double
VehicleType::getServiceTimeFactor()
{
	return service_time_factor;
}

void
VehicleType::setServiceTimeFactor(double  service_time_factor)
{
	this->service_time_factor = service_time_factor;
}

double
VehicleType::getCostPerMeter()
{
	return cost_per_meter;
}

void
VehicleType::setCostPerMeter(double  cost_per_meter)
{
	this->cost_per_meter = cost_per_meter;
}

double
VehicleType::getCostPerSecond()
{
	return cost_per_second;
}

void
VehicleType::setCostPerSecond(double  cost_per_second)
{
	this->cost_per_second = cost_per_second;
}

double
VehicleType::getCostPerActivation()
{
	return cost_per_activation;
}

void
VehicleType::setCostPerActivation(double  cost_per_activation)
{
	this->cost_per_activation = cost_per_activation;
}


