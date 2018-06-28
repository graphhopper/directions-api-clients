#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "GeocodingResponse.h"

using namespace std;
using namespace Tizen::ArtikCloud;

GeocodingResponse::GeocodingResponse()
{
	//__init();
}

GeocodingResponse::~GeocodingResponse()
{
	//__cleanup();
}

void
GeocodingResponse::__init()
{
	//new std::list()std::list> hits;
	//locale = std::string();
}

void
GeocodingResponse::__cleanup()
{
	//if(hits != NULL) {
	//hits.RemoveAll(true);
	//delete hits;
	//hits = NULL;
	//}
	//if(locale != NULL) {
	//
	//delete locale;
	//locale = NULL;
	//}
	//
}

void
GeocodingResponse::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *hitsKey = "hits";
	node = json_object_get_member(pJsonObject, hitsKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<GeocodingLocation> new_list;
			GeocodingLocation inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("GeocodingLocation")) {
					jsonToValue(&inst, temp_json, "GeocodingLocation", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			hits = new_list;
		}
		
	}
	const gchar *localeKey = "locale";
	node = json_object_get_member(pJsonObject, localeKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&locale, node, "std::string", "");
		} else {
			
		}
	}
}

GeocodingResponse::GeocodingResponse(char* json)
{
	this->fromJson(json);
}

char*
GeocodingResponse::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("GeocodingLocation")) {
		list<GeocodingLocation> new_list = static_cast<list <GeocodingLocation> > (getHits());
		node = converttoJson(&new_list, "GeocodingLocation", "array");
	} else {
		node = json_node_alloc();
		list<GeocodingLocation> new_list = static_cast<list <GeocodingLocation> > (getHits());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<GeocodingLocation>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			GeocodingLocation obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *hitsKey = "hits";
	json_object_set_member(pJsonObject, hitsKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getLocale();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *localeKey = "locale";
	json_object_set_member(pJsonObject, localeKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::list<GeocodingLocation>
GeocodingResponse::getHits()
{
	return hits;
}

void
GeocodingResponse::setHits(std::list <GeocodingLocation> hits)
{
	this->hits = hits;
}

std::string
GeocodingResponse::getLocale()
{
	return locale;
}

void
GeocodingResponse::setLocale(std::string  locale)
{
	this->locale = locale;
}


