#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "IsochroneResponsePolygon_properties.h"

using namespace std;
using namespace Tizen::ArtikCloud;

IsochroneResponsePolygon_properties::IsochroneResponsePolygon_properties()
{
	//__init();
}

IsochroneResponsePolygon_properties::~IsochroneResponsePolygon_properties()
{
	//__cleanup();
}

void
IsochroneResponsePolygon_properties::__init()
{
	//
	//
	//bucket = int(0);
	//
}

void
IsochroneResponsePolygon_properties::__cleanup()
{
	//if(bucket != NULL) {
	//
	//delete bucket;
	//bucket = NULL;
	//}
	//
}

void
IsochroneResponsePolygon_properties::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *bucketKey = "bucket";
	node = json_object_get_member(pJsonObject, bucketKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&bucket, node, "int", "");
		} else {
			
		}
	}
}

IsochroneResponsePolygon_properties::IsochroneResponsePolygon_properties(char* json)
{
	this->fromJson(json);
}

char*
IsochroneResponsePolygon_properties::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("int")) {
		int obj = getBucket();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *bucketKey = "bucket";
	json_object_set_member(pJsonObject, bucketKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

int
IsochroneResponsePolygon_properties::getBucket()
{
	return bucket;
}

void
IsochroneResponsePolygon_properties::setBucket(int  bucket)
{
	this->bucket = bucket;
}


