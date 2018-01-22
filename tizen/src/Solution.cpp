#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Solution.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Solution::Solution()
{
	//__init();
}

Solution::~Solution()
{
	//__cleanup();
}

void
Solution::__init()
{
	//
	//
	//costs = int(0);
	//
	//
	//distance = int(0);
	//
	//
	//time = long(0);
	//
	//
	//transport_time = long(0);
	//
	//
	//max_operation_time = long(0);
	//
	//
	//waiting_time = long(0);
	//
	//
	//no_vehicles = int(0);
	//
	//
	//no_unassigned = int(0);
	//
	//new std::list()std::list> routes;
	//
	//
	//
	//unassigned = new Solution_unassigned();
	//
}

void
Solution::__cleanup()
{
	//if(costs != NULL) {
	//
	//delete costs;
	//costs = NULL;
	//}
	//if(distance != NULL) {
	//
	//delete distance;
	//distance = NULL;
	//}
	//if(time != NULL) {
	//
	//delete time;
	//time = NULL;
	//}
	//if(transport_time != NULL) {
	//
	//delete transport_time;
	//transport_time = NULL;
	//}
	//if(max_operation_time != NULL) {
	//
	//delete max_operation_time;
	//max_operation_time = NULL;
	//}
	//if(waiting_time != NULL) {
	//
	//delete waiting_time;
	//waiting_time = NULL;
	//}
	//if(no_vehicles != NULL) {
	//
	//delete no_vehicles;
	//no_vehicles = NULL;
	//}
	//if(no_unassigned != NULL) {
	//
	//delete no_unassigned;
	//no_unassigned = NULL;
	//}
	//if(routes != NULL) {
	//routes.RemoveAll(true);
	//delete routes;
	//routes = NULL;
	//}
	//if(unassigned != NULL) {
	//
	//delete unassigned;
	//unassigned = NULL;
	//}
	//
}

void
Solution::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *costsKey = "costs";
	node = json_object_get_member(pJsonObject, costsKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&costs, node, "int", "");
		} else {
			
		}
	}
	const gchar *distanceKey = "distance";
	node = json_object_get_member(pJsonObject, distanceKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&distance, node, "int", "");
		} else {
			
		}
	}
	const gchar *timeKey = "time";
	node = json_object_get_member(pJsonObject, timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&time, node, "long long", "");
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
	const gchar *max_operation_timeKey = "max_operation_time";
	node = json_object_get_member(pJsonObject, max_operation_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&max_operation_time, node, "long long", "");
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
	const gchar *no_vehiclesKey = "no_vehicles";
	node = json_object_get_member(pJsonObject, no_vehiclesKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&no_vehicles, node, "int", "");
		} else {
			
		}
	}
	const gchar *no_unassignedKey = "no_unassigned";
	node = json_object_get_member(pJsonObject, no_unassignedKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&no_unassigned, node, "int", "");
		} else {
			
		}
	}
	const gchar *routesKey = "routes";
	node = json_object_get_member(pJsonObject, routesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<Route> new_list;
			Route inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("Route")) {
					jsonToValue(&inst, temp_json, "Route", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			routes = new_list;
		}
		
	}
	const gchar *unassignedKey = "unassigned";
	node = json_object_get_member(pJsonObject, unassignedKey);
	if (node !=NULL) {
	

		if (isprimitive("Solution_unassigned")) {
			jsonToValue(&unassigned, node, "Solution_unassigned", "Solution_unassigned");
		} else {
			
			Solution_unassigned* obj = static_cast<Solution_unassigned*> (&unassigned);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

Solution::Solution(char* json)
{
	this->fromJson(json);
}

char*
Solution::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("int")) {
		int obj = getCosts();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *costsKey = "costs";
	json_object_set_member(pJsonObject, costsKey, node);
	if (isprimitive("int")) {
		int obj = getDistance();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *distanceKey = "distance";
	json_object_set_member(pJsonObject, distanceKey, node);
	if (isprimitive("long long")) {
		long long obj = getTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *timeKey = "time";
	json_object_set_member(pJsonObject, timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getTransportTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *transport_timeKey = "transport_time";
	json_object_set_member(pJsonObject, transport_timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getMaxOperationTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *max_operation_timeKey = "max_operation_time";
	json_object_set_member(pJsonObject, max_operation_timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getWaitingTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *waiting_timeKey = "waiting_time";
	json_object_set_member(pJsonObject, waiting_timeKey, node);
	if (isprimitive("int")) {
		int obj = getNoVehicles();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *no_vehiclesKey = "no_vehicles";
	json_object_set_member(pJsonObject, no_vehiclesKey, node);
	if (isprimitive("int")) {
		int obj = getNoUnassigned();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *no_unassignedKey = "no_unassigned";
	json_object_set_member(pJsonObject, no_unassignedKey, node);
	if (isprimitive("Route")) {
		list<Route> new_list = static_cast<list <Route> > (getRoutes());
		node = converttoJson(&new_list, "Route", "array");
	} else {
		node = json_node_alloc();
		list<Route> new_list = static_cast<list <Route> > (getRoutes());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<Route>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			Route obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *routesKey = "routes";
	json_object_set_member(pJsonObject, routesKey, node);
	if (isprimitive("Solution_unassigned")) {
		Solution_unassigned obj = getUnassigned();
		node = converttoJson(&obj, "Solution_unassigned", "");
	}
	else {
		
		Solution_unassigned obj = static_cast<Solution_unassigned> (getUnassigned());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *unassignedKey = "unassigned";
	json_object_set_member(pJsonObject, unassignedKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

int
Solution::getCosts()
{
	return costs;
}

void
Solution::setCosts(int  costs)
{
	this->costs = costs;
}

int
Solution::getDistance()
{
	return distance;
}

void
Solution::setDistance(int  distance)
{
	this->distance = distance;
}

long long
Solution::getTime()
{
	return time;
}

void
Solution::setTime(long long  time)
{
	this->time = time;
}

long long
Solution::getTransportTime()
{
	return transport_time;
}

void
Solution::setTransportTime(long long  transport_time)
{
	this->transport_time = transport_time;
}

long long
Solution::getMaxOperationTime()
{
	return max_operation_time;
}

void
Solution::setMaxOperationTime(long long  max_operation_time)
{
	this->max_operation_time = max_operation_time;
}

long long
Solution::getWaitingTime()
{
	return waiting_time;
}

void
Solution::setWaitingTime(long long  waiting_time)
{
	this->waiting_time = waiting_time;
}

int
Solution::getNoVehicles()
{
	return no_vehicles;
}

void
Solution::setNoVehicles(int  no_vehicles)
{
	this->no_vehicles = no_vehicles;
}

int
Solution::getNoUnassigned()
{
	return no_unassigned;
}

void
Solution::setNoUnassigned(int  no_unassigned)
{
	this->no_unassigned = no_unassigned;
}

std::list<Route>
Solution::getRoutes()
{
	return routes;
}

void
Solution::setRoutes(std::list <Route> routes)
{
	this->routes = routes;
}

Solution_unassigned
Solution::getUnassigned()
{
	return unassigned;
}

void
Solution::setUnassigned(Solution_unassigned  unassigned)
{
	this->unassigned = unassigned;
}


