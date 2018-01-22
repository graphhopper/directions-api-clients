#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "RouteResponse.h"

using namespace std;
using namespace Tizen::ArtikCloud;

RouteResponse::RouteResponse()
{
	//__init();
}

RouteResponse::~RouteResponse()
{
	//__cleanup();
}

void
RouteResponse::__init()
{
	//
	//new std::list()std::list> paths;
	//
	//
	//
	//info = new ResponseInfo();
	//
}

void
RouteResponse::__cleanup()
{
	//if(paths != NULL) {
	//paths.RemoveAll(true);
	//delete paths;
	//paths = NULL;
	//}
	//if(info != NULL) {
	//
	//delete info;
	//info = NULL;
	//}
	//
}

void
RouteResponse::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *pathsKey = "paths";
	node = json_object_get_member(pJsonObject, pathsKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<RouteResponsePath> new_list;
			RouteResponsePath inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("RouteResponsePath")) {
					jsonToValue(&inst, temp_json, "RouteResponsePath", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			paths = new_list;
		}
		
	}
	const gchar *infoKey = "info";
	node = json_object_get_member(pJsonObject, infoKey);
	if (node !=NULL) {
	

		if (isprimitive("ResponseInfo")) {
			jsonToValue(&info, node, "ResponseInfo", "ResponseInfo");
		} else {
			
			ResponseInfo* obj = static_cast<ResponseInfo*> (&info);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

RouteResponse::RouteResponse(char* json)
{
	this->fromJson(json);
}

char*
RouteResponse::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("RouteResponsePath")) {
		list<RouteResponsePath> new_list = static_cast<list <RouteResponsePath> > (getPaths());
		node = converttoJson(&new_list, "RouteResponsePath", "array");
	} else {
		node = json_node_alloc();
		list<RouteResponsePath> new_list = static_cast<list <RouteResponsePath> > (getPaths());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<RouteResponsePath>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			RouteResponsePath obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *pathsKey = "paths";
	json_object_set_member(pJsonObject, pathsKey, node);
	if (isprimitive("ResponseInfo")) {
		ResponseInfo obj = getInfo();
		node = converttoJson(&obj, "ResponseInfo", "");
	}
	else {
		
		ResponseInfo obj = static_cast<ResponseInfo> (getInfo());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *infoKey = "info";
	json_object_set_member(pJsonObject, infoKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::list<RouteResponsePath>
RouteResponse::getPaths()
{
	return paths;
}

void
RouteResponse::setPaths(std::list <RouteResponsePath> paths)
{
	this->paths = paths;
}

ResponseInfo
RouteResponse::getInfo()
{
	return info;
}

void
RouteResponse::setInfo(ResponseInfo  info)
{
	this->info = info;
}


