#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "ResponseInfo.h"

using namespace std;
using namespace Tizen::ArtikCloud;

ResponseInfo::ResponseInfo()
{
	//__init();
}

ResponseInfo::~ResponseInfo()
{
	//__cleanup();
}

void
ResponseInfo::__init()
{
	//new std::list()std::list> copyrights;
	//took = double(0);
}

void
ResponseInfo::__cleanup()
{
	//if(copyrights != NULL) {
	//copyrights.RemoveAll(true);
	//delete copyrights;
	//copyrights = NULL;
	//}
	//if(took != NULL) {
	//
	//delete took;
	//took = NULL;
	//}
	//
}

void
ResponseInfo::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
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
	const gchar *tookKey = "took";
	node = json_object_get_member(pJsonObject, tookKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&took, node, "double", "");
		} else {
			
		}
	}
}

ResponseInfo::ResponseInfo(char* json)
{
	this->fromJson(json);
}

char*
ResponseInfo::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
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
	if (isprimitive("double")) {
		double obj = getTook();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *tookKey = "took";
	json_object_set_member(pJsonObject, tookKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::list<std::string>
ResponseInfo::getCopyrights()
{
	return copyrights;
}

void
ResponseInfo::setCopyrights(std::list <std::string> copyrights)
{
	this->copyrights = copyrights;
}

double
ResponseInfo::getTook()
{
	return took;
}

void
ResponseInfo::setTook(double  took)
{
	this->took = took;
}


