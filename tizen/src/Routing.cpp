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
	//
	//
	//calc_points = bool(false);
	//
}

void
Routing::__cleanup()
{
	//if(calc_points != NULL) {
	//
	//delete calc_points;
	//calc_points = NULL;
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


