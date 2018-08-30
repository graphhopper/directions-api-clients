#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Request.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Request::Request()
{
	//__init();
}

Request::~Request()
{
	//__cleanup();
}

void
Request::__init()
{
	//
	//new std::list()std::list> vehicles;
	//
	//
	//new std::list()std::list> vehicle_types;
	//
	//
	//new std::list()std::list> services;
	//
	//
	//new std::list()std::list> shipments;
	//
	//
	//new std::list()std::list> relations;
	//
	//
	//new std::list()std::list> objectives;
	//
	//
	//new std::list()std::list> cost_matrices;
	//
	//
	//
	//configuration = new Configuration();
	//
}

void
Request::__cleanup()
{
	//if(vehicles != NULL) {
	//vehicles.RemoveAll(true);
	//delete vehicles;
	//vehicles = NULL;
	//}
	//if(vehicle_types != NULL) {
	//vehicle_types.RemoveAll(true);
	//delete vehicle_types;
	//vehicle_types = NULL;
	//}
	//if(services != NULL) {
	//services.RemoveAll(true);
	//delete services;
	//services = NULL;
	//}
	//if(shipments != NULL) {
	//shipments.RemoveAll(true);
	//delete shipments;
	//shipments = NULL;
	//}
	//if(relations != NULL) {
	//relations.RemoveAll(true);
	//delete relations;
	//relations = NULL;
	//}
	//if(objectives != NULL) {
	//objectives.RemoveAll(true);
	//delete objectives;
	//objectives = NULL;
	//}
	//if(cost_matrices != NULL) {
	//cost_matrices.RemoveAll(true);
	//delete cost_matrices;
	//cost_matrices = NULL;
	//}
	//if(configuration != NULL) {
	//
	//delete configuration;
	//configuration = NULL;
	//}
	//
}

void
Request::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *vehiclesKey = "vehicles";
	node = json_object_get_member(pJsonObject, vehiclesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<Vehicle> new_list;
			Vehicle inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("Vehicle")) {
					jsonToValue(&inst, temp_json, "Vehicle", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			vehicles = new_list;
		}
		
	}
	const gchar *vehicle_typesKey = "vehicle_types";
	node = json_object_get_member(pJsonObject, vehicle_typesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<VehicleType> new_list;
			VehicleType inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("VehicleType")) {
					jsonToValue(&inst, temp_json, "VehicleType", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			vehicle_types = new_list;
		}
		
	}
	const gchar *servicesKey = "services";
	node = json_object_get_member(pJsonObject, servicesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<Service> new_list;
			Service inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("Service")) {
					jsonToValue(&inst, temp_json, "Service", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			services = new_list;
		}
		
	}
	const gchar *shipmentsKey = "shipments";
	node = json_object_get_member(pJsonObject, shipmentsKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<Shipment> new_list;
			Shipment inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("Shipment")) {
					jsonToValue(&inst, temp_json, "Shipment", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			shipments = new_list;
		}
		
	}
	const gchar *relationsKey = "relations";
	node = json_object_get_member(pJsonObject, relationsKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<Relation> new_list;
			Relation inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("Relation")) {
					jsonToValue(&inst, temp_json, "Relation", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			relations = new_list;
		}
		
	}
	const gchar *objectivesKey = "objectives";
	node = json_object_get_member(pJsonObject, objectivesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<Objective> new_list;
			Objective inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("Objective")) {
					jsonToValue(&inst, temp_json, "Objective", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			objectives = new_list;
		}
		
	}
	const gchar *cost_matricesKey = "cost_matrices";
	node = json_object_get_member(pJsonObject, cost_matricesKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<CostMatrix> new_list;
			CostMatrix inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("CostMatrix")) {
					jsonToValue(&inst, temp_json, "CostMatrix", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			cost_matrices = new_list;
		}
		
	}
	const gchar *configurationKey = "configuration";
	node = json_object_get_member(pJsonObject, configurationKey);
	if (node !=NULL) {
	

		if (isprimitive("Configuration")) {
			jsonToValue(&configuration, node, "Configuration", "Configuration");
		} else {
			
			Configuration* obj = static_cast<Configuration*> (&configuration);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

Request::Request(char* json)
{
	this->fromJson(json);
}

char*
Request::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("Vehicle")) {
		list<Vehicle> new_list = static_cast<list <Vehicle> > (getVehicles());
		node = converttoJson(&new_list, "Vehicle", "array");
	} else {
		node = json_node_alloc();
		list<Vehicle> new_list = static_cast<list <Vehicle> > (getVehicles());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<Vehicle>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			Vehicle obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *vehiclesKey = "vehicles";
	json_object_set_member(pJsonObject, vehiclesKey, node);
	if (isprimitive("VehicleType")) {
		list<VehicleType> new_list = static_cast<list <VehicleType> > (getVehicleTypes());
		node = converttoJson(&new_list, "VehicleType", "array");
	} else {
		node = json_node_alloc();
		list<VehicleType> new_list = static_cast<list <VehicleType> > (getVehicleTypes());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<VehicleType>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			VehicleType obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *vehicle_typesKey = "vehicle_types";
	json_object_set_member(pJsonObject, vehicle_typesKey, node);
	if (isprimitive("Service")) {
		list<Service> new_list = static_cast<list <Service> > (getServices());
		node = converttoJson(&new_list, "Service", "array");
	} else {
		node = json_node_alloc();
		list<Service> new_list = static_cast<list <Service> > (getServices());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<Service>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			Service obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *servicesKey = "services";
	json_object_set_member(pJsonObject, servicesKey, node);
	if (isprimitive("Shipment")) {
		list<Shipment> new_list = static_cast<list <Shipment> > (getShipments());
		node = converttoJson(&new_list, "Shipment", "array");
	} else {
		node = json_node_alloc();
		list<Shipment> new_list = static_cast<list <Shipment> > (getShipments());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<Shipment>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			Shipment obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *shipmentsKey = "shipments";
	json_object_set_member(pJsonObject, shipmentsKey, node);
	if (isprimitive("Relation")) {
		list<Relation> new_list = static_cast<list <Relation> > (getRelations());
		node = converttoJson(&new_list, "Relation", "array");
	} else {
		node = json_node_alloc();
		list<Relation> new_list = static_cast<list <Relation> > (getRelations());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<Relation>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			Relation obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *relationsKey = "relations";
	json_object_set_member(pJsonObject, relationsKey, node);
	if (isprimitive("Objective")) {
		list<Objective> new_list = static_cast<list <Objective> > (getObjectives());
		node = converttoJson(&new_list, "Objective", "array");
	} else {
		node = json_node_alloc();
		list<Objective> new_list = static_cast<list <Objective> > (getObjectives());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<Objective>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			Objective obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *objectivesKey = "objectives";
	json_object_set_member(pJsonObject, objectivesKey, node);
	if (isprimitive("CostMatrix")) {
		list<CostMatrix> new_list = static_cast<list <CostMatrix> > (getCostMatrices());
		node = converttoJson(&new_list, "CostMatrix", "array");
	} else {
		node = json_node_alloc();
		list<CostMatrix> new_list = static_cast<list <CostMatrix> > (getCostMatrices());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<CostMatrix>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			CostMatrix obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *cost_matricesKey = "cost_matrices";
	json_object_set_member(pJsonObject, cost_matricesKey, node);
	if (isprimitive("Configuration")) {
		Configuration obj = getConfiguration();
		node = converttoJson(&obj, "Configuration", "");
	}
	else {
		
		Configuration obj = static_cast<Configuration> (getConfiguration());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *configurationKey = "configuration";
	json_object_set_member(pJsonObject, configurationKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::list<Vehicle>
Request::getVehicles()
{
	return vehicles;
}

void
Request::setVehicles(std::list <Vehicle> vehicles)
{
	this->vehicles = vehicles;
}

std::list<VehicleType>
Request::getVehicleTypes()
{
	return vehicle_types;
}

void
Request::setVehicleTypes(std::list <VehicleType> vehicle_types)
{
	this->vehicle_types = vehicle_types;
}

std::list<Service>
Request::getServices()
{
	return services;
}

void
Request::setServices(std::list <Service> services)
{
	this->services = services;
}

std::list<Shipment>
Request::getShipments()
{
	return shipments;
}

void
Request::setShipments(std::list <Shipment> shipments)
{
	this->shipments = shipments;
}

std::list<Relation>
Request::getRelations()
{
	return relations;
}

void
Request::setRelations(std::list <Relation> relations)
{
	this->relations = relations;
}

std::list<Objective>
Request::getObjectives()
{
	return objectives;
}

void
Request::setObjectives(std::list <Objective> objectives)
{
	this->objectives = objectives;
}

std::list<CostMatrix>
Request::getCostMatrices()
{
	return cost_matrices;
}

void
Request::setCostMatrices(std::list <CostMatrix> cost_matrices)
{
	this->cost_matrices = cost_matrices;
}

Configuration
Request::getConfiguration()
{
	return configuration;
}

void
Request::setConfiguration(Configuration  configuration)
{
	this->configuration = configuration;
}


