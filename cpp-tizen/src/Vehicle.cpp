#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Vehicle.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Vehicle::Vehicle()
{
	//__init();
}

Vehicle::~Vehicle()
{
	//__cleanup();
}

void
Vehicle::__init()
{
	//vehicle_id = std::string();
	//type_id = std::string();
	//start_address = new Address();
	//end_address = new Address();
	//_break = new Break();
	//return_to_depot = bool(false);
	//earliest_start = long(0);
	//latest_end = long(0);
	//new std::list()std::list> skills;
	//max_distance = long(0);
	//max_driving_time = long(0);
	//max_jobs = int(0);
	//max_activities = int(0);
}

void
Vehicle::__cleanup()
{
	//if(vehicle_id != NULL) {
	//
	//delete vehicle_id;
	//vehicle_id = NULL;
	//}
	//if(type_id != NULL) {
	//
	//delete type_id;
	//type_id = NULL;
	//}
	//if(start_address != NULL) {
	//
	//delete start_address;
	//start_address = NULL;
	//}
	//if(end_address != NULL) {
	//
	//delete end_address;
	//end_address = NULL;
	//}
	//if(_break != NULL) {
	//
	//delete _break;
	//_break = NULL;
	//}
	//if(return_to_depot != NULL) {
	//
	//delete return_to_depot;
	//return_to_depot = NULL;
	//}
	//if(earliest_start != NULL) {
	//
	//delete earliest_start;
	//earliest_start = NULL;
	//}
	//if(latest_end != NULL) {
	//
	//delete latest_end;
	//latest_end = NULL;
	//}
	//if(skills != NULL) {
	//skills.RemoveAll(true);
	//delete skills;
	//skills = NULL;
	//}
	//if(max_distance != NULL) {
	//
	//delete max_distance;
	//max_distance = NULL;
	//}
	//if(max_driving_time != NULL) {
	//
	//delete max_driving_time;
	//max_driving_time = NULL;
	//}
	//if(max_jobs != NULL) {
	//
	//delete max_jobs;
	//max_jobs = NULL;
	//}
	//if(max_activities != NULL) {
	//
	//delete max_activities;
	//max_activities = NULL;
	//}
	//
}

void
Vehicle::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *vehicle_idKey = "vehicle_id";
	node = json_object_get_member(pJsonObject, vehicle_idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&vehicle_id, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *type_idKey = "type_id";
	node = json_object_get_member(pJsonObject, type_idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&type_id, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *start_addressKey = "start_address";
	node = json_object_get_member(pJsonObject, start_addressKey);
	if (node !=NULL) {
	

		if (isprimitive("Address")) {
			jsonToValue(&start_address, node, "Address", "Address");
		} else {
			
			Address* obj = static_cast<Address*> (&start_address);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *end_addressKey = "end_address";
	node = json_object_get_member(pJsonObject, end_addressKey);
	if (node !=NULL) {
	

		if (isprimitive("Address")) {
			jsonToValue(&end_address, node, "Address", "Address");
		} else {
			
			Address* obj = static_cast<Address*> (&end_address);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *_breakKey = "break";
	node = json_object_get_member(pJsonObject, _breakKey);
	if (node !=NULL) {
	

		if (isprimitive("Break")) {
			jsonToValue(&_break, node, "Break", "Break");
		} else {
			
			Break* obj = static_cast<Break*> (&_break);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *return_to_depotKey = "return_to_depot";
	node = json_object_get_member(pJsonObject, return_to_depotKey);
	if (node !=NULL) {
	

		if (isprimitive("bool")) {
			jsonToValue(&return_to_depot, node, "bool", "");
		} else {
			
		}
	}
	const gchar *earliest_startKey = "earliest_start";
	node = json_object_get_member(pJsonObject, earliest_startKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&earliest_start, node, "long long", "");
		} else {
			
		}
	}
	const gchar *latest_endKey = "latest_end";
	node = json_object_get_member(pJsonObject, latest_endKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&latest_end, node, "long long", "");
		} else {
			
		}
	}
	const gchar *skillsKey = "skills";
	node = json_object_get_member(pJsonObject, skillsKey);
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
			skills = new_list;
		}
		
	}
	const gchar *max_distanceKey = "max_distance";
	node = json_object_get_member(pJsonObject, max_distanceKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&max_distance, node, "long long", "");
		} else {
			
		}
	}
	const gchar *max_driving_timeKey = "max_driving_time";
	node = json_object_get_member(pJsonObject, max_driving_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&max_driving_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *max_jobsKey = "max_jobs";
	node = json_object_get_member(pJsonObject, max_jobsKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&max_jobs, node, "int", "");
		} else {
			
		}
	}
	const gchar *max_activitiesKey = "max_activities";
	node = json_object_get_member(pJsonObject, max_activitiesKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&max_activities, node, "int", "");
		} else {
			
		}
	}
}

Vehicle::Vehicle(char* json)
{
	this->fromJson(json);
}

char*
Vehicle::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getVehicleId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *vehicle_idKey = "vehicle_id";
	json_object_set_member(pJsonObject, vehicle_idKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getTypeId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *type_idKey = "type_id";
	json_object_set_member(pJsonObject, type_idKey, node);
	if (isprimitive("Address")) {
		Address obj = getStartAddress();
		node = converttoJson(&obj, "Address", "");
	}
	else {
		
		Address obj = static_cast<Address> (getStartAddress());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *start_addressKey = "start_address";
	json_object_set_member(pJsonObject, start_addressKey, node);
	if (isprimitive("Address")) {
		Address obj = getEndAddress();
		node = converttoJson(&obj, "Address", "");
	}
	else {
		
		Address obj = static_cast<Address> (getEndAddress());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *end_addressKey = "end_address";
	json_object_set_member(pJsonObject, end_addressKey, node);
	if (isprimitive("Break")) {
		Break obj = getBreak();
		node = converttoJson(&obj, "Break", "");
	}
	else {
		
		Break obj = static_cast<Break> (getBreak());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *_breakKey = "break";
	json_object_set_member(pJsonObject, _breakKey, node);
	if (isprimitive("bool")) {
		bool obj = getReturnToDepot();
		node = converttoJson(&obj, "bool", "");
	}
	else {
		
	}
	const gchar *return_to_depotKey = "return_to_depot";
	json_object_set_member(pJsonObject, return_to_depotKey, node);
	if (isprimitive("long long")) {
		long long obj = getEarliestStart();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *earliest_startKey = "earliest_start";
	json_object_set_member(pJsonObject, earliest_startKey, node);
	if (isprimitive("long long")) {
		long long obj = getLatestEnd();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *latest_endKey = "latest_end";
	json_object_set_member(pJsonObject, latest_endKey, node);
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getSkills());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getSkills());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *skillsKey = "skills";
	json_object_set_member(pJsonObject, skillsKey, node);
	if (isprimitive("long long")) {
		long long obj = getMaxDistance();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *max_distanceKey = "max_distance";
	json_object_set_member(pJsonObject, max_distanceKey, node);
	if (isprimitive("long long")) {
		long long obj = getMaxDrivingTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *max_driving_timeKey = "max_driving_time";
	json_object_set_member(pJsonObject, max_driving_timeKey, node);
	if (isprimitive("int")) {
		int obj = getMaxJobs();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *max_jobsKey = "max_jobs";
	json_object_set_member(pJsonObject, max_jobsKey, node);
	if (isprimitive("int")) {
		int obj = getMaxActivities();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *max_activitiesKey = "max_activities";
	json_object_set_member(pJsonObject, max_activitiesKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
Vehicle::getVehicleId()
{
	return vehicle_id;
}

void
Vehicle::setVehicleId(std::string  vehicle_id)
{
	this->vehicle_id = vehicle_id;
}

std::string
Vehicle::getTypeId()
{
	return type_id;
}

void
Vehicle::setTypeId(std::string  type_id)
{
	this->type_id = type_id;
}

Address
Vehicle::getStartAddress()
{
	return start_address;
}

void
Vehicle::setStartAddress(Address  start_address)
{
	this->start_address = start_address;
}

Address
Vehicle::getEndAddress()
{
	return end_address;
}

void
Vehicle::setEndAddress(Address  end_address)
{
	this->end_address = end_address;
}

Break
Vehicle::getBreak()
{
	return _break;
}

void
Vehicle::setBreak(Break  _break)
{
	this->_break = _break;
}

bool
Vehicle::getReturnToDepot()
{
	return return_to_depot;
}

void
Vehicle::setReturnToDepot(bool  return_to_depot)
{
	this->return_to_depot = return_to_depot;
}

long long
Vehicle::getEarliestStart()
{
	return earliest_start;
}

void
Vehicle::setEarliestStart(long long  earliest_start)
{
	this->earliest_start = earliest_start;
}

long long
Vehicle::getLatestEnd()
{
	return latest_end;
}

void
Vehicle::setLatestEnd(long long  latest_end)
{
	this->latest_end = latest_end;
}

std::list<std::string>
Vehicle::getSkills()
{
	return skills;
}

void
Vehicle::setSkills(std::list <std::string> skills)
{
	this->skills = skills;
}

long long
Vehicle::getMaxDistance()
{
	return max_distance;
}

void
Vehicle::setMaxDistance(long long  max_distance)
{
	this->max_distance = max_distance;
}

long long
Vehicle::getMaxDrivingTime()
{
	return max_driving_time;
}

void
Vehicle::setMaxDrivingTime(long long  max_driving_time)
{
	this->max_driving_time = max_driving_time;
}

int
Vehicle::getMaxJobs()
{
	return max_jobs;
}

void
Vehicle::setMaxJobs(int  max_jobs)
{
	this->max_jobs = max_jobs;
}

int
Vehicle::getMaxActivities()
{
	return max_activities;
}

void
Vehicle::setMaxActivities(int  max_activities)
{
	this->max_activities = max_activities;
}


