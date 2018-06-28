#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Configuration.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Configuration::Configuration()
{
	//__init();
}

Configuration::~Configuration()
{
	//__cleanup();
}

void
Configuration::__init()
{
	//routing = new Routing();
}

void
Configuration::__cleanup()
{
	//if(routing != NULL) {
	//
	//delete routing;
	//routing = NULL;
	//}
	//
}

void
Configuration::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *routingKey = "routing";
	node = json_object_get_member(pJsonObject, routingKey);
	if (node !=NULL) {
	

		if (isprimitive("Routing")) {
			jsonToValue(&routing, node, "Routing", "Routing");
		} else {
			
			Routing* obj = static_cast<Routing*> (&routing);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

Configuration::Configuration(char* json)
{
	this->fromJson(json);
}

char*
Configuration::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("Routing")) {
		Routing obj = getRouting();
		node = converttoJson(&obj, "Routing", "");
	}
	else {
		
		Routing obj = static_cast<Routing> (getRouting());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *routingKey = "routing";
	json_object_set_member(pJsonObject, routingKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

Routing
Configuration::getRouting()
{
	return routing;
}

void
Configuration::setRouting(Routing  routing)
{
	this->routing = routing;
}


