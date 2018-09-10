#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Route.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Route::Route()
{
	//__init();
}

Route::~Route()
{
	//__cleanup();
}

void
Route::__init()
{
	//
	//
	//vehicle_id = std::string();
	//
	//
	//distance = long(0);
	//
	//
	//transport_time = long(0);
	//
	//
	//completion_time = long(0);
	//
	//
	//waiting_time = long(0);
	//
	//
	//service_duration = long(0);
	//
	//
	//preparation_time = long(0);
	//
	//new std::list()std::list> activities;
	//
	//
	//new std::list()std::list> points;
	//
	//
}

void
Route::__cleanup()
{
	//if(vehicle_id != NULL) {
	//
	//delete vehicle_id;
	//vehicle_id = NULL;
	//}
	//if(distance != NULL) {
	//
	//delete distance;
	//distance = NULL;
	//}
	//if(transport_time != NULL) {
	//
	//delete transport_time;
	//transport_time = NULL;
	//}
	//if(completion_time != NULL) {
	//
	//delete completion_time;
	//completion_time = NULL;
	//}
	//if(waiting_time != NULL) {
	//
	//delete waiting_time;
	//waiting_time = NULL;
	//}
	//if(service_duration != NULL) {
	//
	//delete service_duration;
	//service_duration = NULL;
	//}
	//if(preparation_time != NULL) {
	//
	//delete preparation_time;
	//preparation_time = NULL;
	//}
	//if(activities != NULL) {
	//activities.RemoveAll(true);
	//delete activities;
	//activities = NULL;
	//}
	//if(points != NULL) {
	//points.RemoveAll(true);
	//delete points;
	//points = NULL;
	//}
	//
}

void
Route::fromJson(char* jsonStr)
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
	const gchar *distanceKey = "distance";
	node = json_object_get_member(pJsonObject, distanceKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&distance, node, "long long", "");
		} else {
			
		}
	}
	const gchar *transport_timeKey = "transport_time";
	node = json_object_get_member(pJsonObject, transport_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&transport_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *completion_timeKey = "completion_time";
	node = json_object_get_member(pJsonObject, completion_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&completion_time, node, "long long", "");
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
	const gchar *service_durationKey = "service_duration";
	node = json_object_get_member(pJsonObject, service_durationKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&service_duration, node, "long long", "");
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
	const gchar *activitiesKey = "activities";
	node = json_object_get_member(pJsonObject, activitiesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<Activity> new_list;
			Activity inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("Activity")) {
					jsonToValue(&inst, temp_json, "Activity", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			activities = new_list;
		}
		
	}
	const gchar *pointsKey = "points";
	node = json_object_get_member(pJsonObject, pointsKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<RoutePoint> new_list;
			RoutePoint inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("RoutePoint")) {
					jsonToValue(&inst, temp_json, "RoutePoint", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			points = new_list;
		}
		
	}
}

Route::Route(char* json)
{
	this->fromJson(json);
}

char*
Route::toJson()
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
	if (isprimitive("long long")) {
		long long obj = getDistance();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *distanceKey = "distance";
	json_object_set_member(pJsonObject, distanceKey, node);
	if (isprimitive("long long")) {
		long long obj = getTransportTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *transport_timeKey = "transport_time";
	json_object_set_member(pJsonObject, transport_timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getCompletionTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *completion_timeKey = "completion_time";
	json_object_set_member(pJsonObject, completion_timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getWaitingTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *waiting_timeKey = "waiting_time";
	json_object_set_member(pJsonObject, waiting_timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getServiceDuration();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *service_durationKey = "service_duration";
	json_object_set_member(pJsonObject, service_durationKey, node);
	if (isprimitive("long long")) {
		long long obj = getPreparationTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *preparation_timeKey = "preparation_time";
	json_object_set_member(pJsonObject, preparation_timeKey, node);
	if (isprimitive("Activity")) {
		list<Activity> new_list = static_cast<list <Activity> > (getActivities());
		node = converttoJson(&new_list, "Activity", "array");
	} else {
		node = json_node_alloc();
		list<Activity> new_list = static_cast<list <Activity> > (getActivities());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<Activity>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			Activity obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *activitiesKey = "activities";
	json_object_set_member(pJsonObject, activitiesKey, node);
	if (isprimitive("RoutePoint")) {
		list<RoutePoint> new_list = static_cast<list <RoutePoint> > (getPoints());
		node = converttoJson(&new_list, "RoutePoint", "array");
	} else {
		node = json_node_alloc();
		list<RoutePoint> new_list = static_cast<list <RoutePoint> > (getPoints());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<RoutePoint>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			RoutePoint obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *pointsKey = "points";
	json_object_set_member(pJsonObject, pointsKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
Route::getVehicleId()
{
	return vehicle_id;
}

void
Route::setVehicleId(std::string  vehicle_id)
{
	this->vehicle_id = vehicle_id;
}

long long
Route::getDistance()
{
	return distance;
}

void
Route::setDistance(long long  distance)
{
	this->distance = distance;
}

long long
Route::getTransportTime()
{
	return transport_time;
}

void
Route::setTransportTime(long long  transport_time)
{
	this->transport_time = transport_time;
}

long long
Route::getCompletionTime()
{
	return completion_time;
}

void
Route::setCompletionTime(long long  completion_time)
{
	this->completion_time = completion_time;
}

long long
Route::getWaitingTime()
{
	return waiting_time;
}

void
Route::setWaitingTime(long long  waiting_time)
{
	this->waiting_time = waiting_time;
}

long long
Route::getServiceDuration()
{
	return service_duration;
}

void
Route::setServiceDuration(long long  service_duration)
{
	this->service_duration = service_duration;
}

long long
Route::getPreparationTime()
{
	return preparation_time;
}

void
Route::setPreparationTime(long long  preparation_time)
{
	this->preparation_time = preparation_time;
}

std::list<Activity>
Route::getActivities()
{
	return activities;
}

void
Route::setActivities(std::list <Activity> activities)
{
	this->activities = activities;
}

std::list<RoutePoint>
Route::getPoints()
{
	return points;
}

void
Route::setPoints(std::list <RoutePoint> points)
{
	this->points = points;
}


