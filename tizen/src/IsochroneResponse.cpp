#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "IsochroneResponse.h"

using namespace std;
using namespace Tizen::ArtikCloud;

IsochroneResponse::IsochroneResponse()
{
	//__init();
}

IsochroneResponse::~IsochroneResponse()
{
	//__cleanup();
}

void
IsochroneResponse::__init()
{
	//
	//new std::list()std::list> polygons;
	//
	//
	//new std::list()std::list> copyrights;
	//
	//
}

void
IsochroneResponse::__cleanup()
{
	//if(polygons != NULL) {
	//polygons.RemoveAll(true);
	//delete polygons;
	//polygons = NULL;
	//}
	//if(copyrights != NULL) {
	//copyrights.RemoveAll(true);
	//delete copyrights;
	//copyrights = NULL;
	//}
	//
}

void
IsochroneResponse::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *polygonsKey = "polygons";
	node = json_object_get_member(pJsonObject, polygonsKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<IsochroneResponsePolygon> new_list;
			IsochroneResponsePolygon inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("IsochroneResponsePolygon")) {
					jsonToValue(&inst, temp_json, "IsochroneResponsePolygon", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			polygons = new_list;
		}
		
	}
	const gchar *copyrightsKey = "copyrights";
	node = json_object_get_member(pJsonObject, copyrightsKey);
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
			copyrights = new_list;
		}
		
	}
}

IsochroneResponse::IsochroneResponse(char* json)
{
	this->fromJson(json);
}

char*
IsochroneResponse::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("IsochroneResponsePolygon")) {
		list<IsochroneResponsePolygon> new_list = static_cast<list <IsochroneResponsePolygon> > (getPolygons());
		node = converttoJson(&new_list, "IsochroneResponsePolygon", "array");
	} else {
		node = json_node_alloc();
		list<IsochroneResponsePolygon> new_list = static_cast<list <IsochroneResponsePolygon> > (getPolygons());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<IsochroneResponsePolygon>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			IsochroneResponsePolygon obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *polygonsKey = "polygons";
	json_object_set_member(pJsonObject, polygonsKey, node);
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getCopyrights());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getCopyrights());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *copyrightsKey = "copyrights";
	json_object_set_member(pJsonObject, copyrightsKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::list<IsochroneResponsePolygon>
IsochroneResponse::getPolygons()
{
	return polygons;
}

void
IsochroneResponse::setPolygons(std::list <IsochroneResponsePolygon> polygons)
{
	this->polygons = polygons;
}

std::list<std::string>
IsochroneResponse::getCopyrights()
{
	return copyrights;
}

void
IsochroneResponse::setCopyrights(std::list <std::string> copyrights)
{
	this->copyrights = copyrights;
}


