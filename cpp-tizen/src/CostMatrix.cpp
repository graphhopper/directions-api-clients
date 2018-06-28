#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "CostMatrix.h"

using namespace std;
using namespace Tizen::ArtikCloud;

CostMatrix::CostMatrix()
{
	//__init();
}

CostMatrix::~CostMatrix()
{
	//__cleanup();
}

void
CostMatrix::__init()
{
	//type = std::string();
	//url = std::string();
	//new std::list()std::list> location_ids;
	//data = null;
	//profile = std::string();
}

void
CostMatrix::__cleanup()
{
	//if(type != NULL) {
	//
	//delete type;
	//type = NULL;
	//}
	//if(url != NULL) {
	//
	//delete url;
	//url = NULL;
	//}
	//if(location_ids != NULL) {
	//location_ids.RemoveAll(true);
	//delete location_ids;
	//location_ids = NULL;
	//}
	//if(data != NULL) {
	//
	//delete data;
	//data = NULL;
	//}
	//if(profile != NULL) {
	//
	//delete profile;
	//profile = NULL;
	//}
	//
}

void
CostMatrix::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *typeKey = "type";
	node = json_object_get_member(pJsonObject, typeKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&type, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *urlKey = "url";
	node = json_object_get_member(pJsonObject, urlKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&url, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *location_idsKey = "location_ids";
	node = json_object_get_member(pJsonObject, location_idsKey);
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
			location_ids = new_list;
		}
		
	}
	const gchar *dataKey = "data";
	node = json_object_get_member(pJsonObject, dataKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&data, node, "std::string", "");
		} else {
			
			std::string* obj = static_cast<std::string*> (&data);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *profileKey = "profile";
	node = json_object_get_member(pJsonObject, profileKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&profile, node, "std::string", "");
		} else {
			
		}
	}
}

CostMatrix::CostMatrix(char* json)
{
	this->fromJson(json);
}

char*
CostMatrix::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getType();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *typeKey = "type";
	json_object_set_member(pJsonObject, typeKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getUrl();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *urlKey = "url";
	json_object_set_member(pJsonObject, urlKey, node);
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getLocationIds());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getLocationIds());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *location_idsKey = "location_ids";
	json_object_set_member(pJsonObject, location_idsKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getData();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
		std::string obj = static_cast<std::string> (getData());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *dataKey = "data";
	json_object_set_member(pJsonObject, dataKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getProfile();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *profileKey = "profile";
	json_object_set_member(pJsonObject, profileKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
CostMatrix::getType()
{
	return type;
}

void
CostMatrix::setType(std::string  type)
{
	this->type = type;
}

std::string
CostMatrix::getUrl()
{
	return url;
}

void
CostMatrix::setUrl(std::string  url)
{
	this->url = url;
}

std::list<std::string>
CostMatrix::getLocationIds()
{
	return location_ids;
}

void
CostMatrix::setLocationIds(std::list <std::string> location_ids)
{
	this->location_ids = location_ids;
}

std::string
CostMatrix::getData()
{
	return data;
}

void
CostMatrix::setData(std::string  data)
{
	this->data = data;
}

std::string
CostMatrix::getProfile()
{
	return profile;
}

void
CostMatrix::setProfile(std::string  profile)
{
	this->profile = profile;
}


