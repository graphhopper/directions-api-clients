#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Routing.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Routing::Routing()
{
	//__init();
}

Routing::~Routing()
{
	//__cleanup();
}

void
Routing::__init()
{
	//calc_points = bool(false);
	//consider_traffic = bool(false);
	//network_data_provider = std::string();
	//fail_fast = bool(false);
}

void
Routing::__cleanup()
{
	//if(calc_points != NULL) {
	//
	//delete calc_points;
	//calc_points = NULL;
	//}
	//if(consider_traffic != NULL) {
	//
	//delete consider_traffic;
	//consider_traffic = NULL;
	//}
	//if(network_data_provider != NULL) {
	//
	//delete network_data_provider;
	//network_data_provider = NULL;
	//}
	//if(fail_fast != NULL) {
	//
	//delete fail_fast;
	//fail_fast = NULL;
	//}
	//
}

void
Routing::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *calc_pointsKey = "calc_points";
	node = json_object_get_member(pJsonObject, calc_pointsKey);
	if (node !=NULL) {
	

		if (isprimitive("bool")) {
			jsonToValue(&calc_points, node, "bool", "");
		} else {
			
		}
	}
	const gchar *consider_trafficKey = "consider_traffic";
	node = json_object_get_member(pJsonObject, consider_trafficKey);
	if (node !=NULL) {
	

		if (isprimitive("bool")) {
			jsonToValue(&consider_traffic, node, "bool", "");
		} else {
			
		}
	}
	const gchar *network_data_providerKey = "network_data_provider";
	node = json_object_get_member(pJsonObject, network_data_providerKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&network_data_provider, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *fail_fastKey = "fail_fast";
	node = json_object_get_member(pJsonObject, fail_fastKey);
	if (node !=NULL) {
	

		if (isprimitive("bool")) {
			jsonToValue(&fail_fast, node, "bool", "");
		} else {
			
		}
	}
}

Routing::Routing(char* json)
{
	this->fromJson(json);
}

char*
Routing::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("bool")) {
		bool obj = getCalcPoints();
		node = converttoJson(&obj, "bool", "");
	}
	else {
		
	}
	const gchar *calc_pointsKey = "calc_points";
	json_object_set_member(pJsonObject, calc_pointsKey, node);
	if (isprimitive("bool")) {
		bool obj = getConsiderTraffic();
		node = converttoJson(&obj, "bool", "");
	}
	else {
		
	}
	const gchar *consider_trafficKey = "consider_traffic";
	json_object_set_member(pJsonObject, consider_trafficKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getNetworkDataProvider();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *network_data_providerKey = "network_data_provider";
	json_object_set_member(pJsonObject, network_data_providerKey, node);
	if (isprimitive("bool")) {
		bool obj = getFailFast();
		node = converttoJson(&obj, "bool", "");
	}
	else {
		
	}
	const gchar *fail_fastKey = "fail_fast";
	json_object_set_member(pJsonObject, fail_fastKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

bool
Routing::getCalcPoints()
{
	return calc_points;
}

void
Routing::setCalcPoints(bool  calc_points)
{
	this->calc_points = calc_points;
}

bool
Routing::getConsiderTraffic()
{
	return consider_traffic;
}

void
Routing::setConsiderTraffic(bool  consider_traffic)
{
	this->consider_traffic = consider_traffic;
}

std::string
Routing::getNetworkDataProvider()
{
	return network_data_provider;
}

void
Routing::setNetworkDataProvider(std::string  network_data_provider)
{
	this->network_data_provider = network_data_provider;
}

bool
Routing::getFailFast()
{
	return fail_fast;
}

void
Routing::setFailFast(bool  fail_fast)
{
	this->fail_fast = fail_fast;
}


