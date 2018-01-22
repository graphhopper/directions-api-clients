#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "ResponseCoordinates.h"

using namespace std;
using namespace Tizen::ArtikCloud;

ResponseCoordinates::ResponseCoordinates()
{
	//__init();
}

ResponseCoordinates::~ResponseCoordinates()
{
	//__cleanup();
}

void
ResponseCoordinates::__init()
{
	//
	//
	//coordinates = new ResponseCoordinatesArray();
	//
}

void
ResponseCoordinates::__cleanup()
{
	//if(coordinates != NULL) {
	//
	//delete coordinates;
	//coordinates = NULL;
	//}
	//
}

void
ResponseCoordinates::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *coordinatesKey = "coordinates";
	node = json_object_get_member(pJsonObject, coordinatesKey);
	if (node !=NULL) {
	

		if (isprimitive("ResponseCoordinatesArray")) {
			jsonToValue(&coordinates, node, "ResponseCoordinatesArray", "ResponseCoordinatesArray");
		} else {
			
			ResponseCoordinatesArray* obj = static_cast<ResponseCoordinatesArray*> (&coordinates);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

ResponseCoordinates::ResponseCoordinates(char* json)
{
	this->fromJson(json);
}

char*
ResponseCoordinates::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("ResponseCoordinatesArray")) {
		ResponseCoordinatesArray obj = getCoordinates();
		node = converttoJson(&obj, "ResponseCoordinatesArray", "");
	}
	else {
		
		ResponseCoordinatesArray obj = static_cast<ResponseCoordinatesArray> (getCoordinates());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *coordinatesKey = "coordinates";
	json_object_set_member(pJsonObject, coordinatesKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

ResponseCoordinatesArray
ResponseCoordinates::getCoordinates()
{
	return coordinates;
}

void
ResponseCoordinates::setCoordinates(ResponseCoordinatesArray  coordinates)
{
	this->coordinates = coordinates;
}


