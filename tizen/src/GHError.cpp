#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "GHError.h"

using namespace std;
using namespace Tizen::ArtikCloud;

GHError::GHError()
{
	//__init();
}

GHError::~GHError()
{
	//__cleanup();
}

void
GHError::__init()
{
	//
	//
	//code = int(0);
	//
	//
	//message = std::string();
	//
	//new std::list()std::list> hints;
	//
	//
}

void
GHError::__cleanup()
{
	//if(code != NULL) {
	//
	//delete code;
	//code = NULL;
	//}
	//if(message != NULL) {
	//
	//delete message;
	//message = NULL;
	//}
	//if(hints != NULL) {
	//hints.RemoveAll(true);
	//delete hints;
	//hints = NULL;
	//}
	//
}

void
GHError::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *codeKey = "code";
	node = json_object_get_member(pJsonObject, codeKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&code, node, "int", "");
		} else {
			
		}
	}
	const gchar *messageKey = "message";
	node = json_object_get_member(pJsonObject, messageKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&message, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *hintsKey = "hints";
	node = json_object_get_member(pJsonObject, hintsKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<GHError_hints> new_list;
			GHError_hints inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("GHError_hints")) {
					jsonToValue(&inst, temp_json, "GHError_hints", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			hints = new_list;
		}
		
	}
}

GHError::GHError(char* json)
{
	this->fromJson(json);
}

char*
GHError::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("int")) {
		int obj = getCode();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *codeKey = "code";
	json_object_set_member(pJsonObject, codeKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getMessage();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *messageKey = "message";
	json_object_set_member(pJsonObject, messageKey, node);
	if (isprimitive("GHError_hints")) {
		list<GHError_hints> new_list = static_cast<list <GHError_hints> > (getHints());
		node = converttoJson(&new_list, "GHError_hints", "array");
	} else {
		node = json_node_alloc();
		list<GHError_hints> new_list = static_cast<list <GHError_hints> > (getHints());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<GHError_hints>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			GHError_hints obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *hintsKey = "hints";
	json_object_set_member(pJsonObject, hintsKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

int
GHError::getCode()
{
	return code;
}

void
GHError::setCode(int  code)
{
	this->code = code;
}

std::string
GHError::getMessage()
{
	return message;
}

void
GHError::setMessage(std::string  message)
{
	this->message = message;
}

std::list<GHError_hints>
GHError::getHints()
{
	return hints;
}

void
GHError::setHints(std::list <GHError_hints> hints)
{
	this->hints = hints;
}


