#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "JobId.h"

using namespace std;
using namespace Tizen::ArtikCloud;

JobId::JobId()
{
	//__init();
}

JobId::~JobId()
{
	//__cleanup();
}

void
JobId::__init()
{
	//
	//
	//job_id = std::string();
	//
}

void
JobId::__cleanup()
{
	//if(job_id != NULL) {
	//
	//delete job_id;
	//job_id = NULL;
	//}
	//
}

void
JobId::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *job_idKey = "job_id";
	node = json_object_get_member(pJsonObject, job_idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&job_id, node, "std::string", "");
		} else {
			
		}
	}
}

JobId::JobId(char* json)
{
	this->fromJson(json);
}

char*
JobId::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getJobId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *job_idKey = "job_id";
	json_object_set_member(pJsonObject, job_idKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
JobId::getJobId()
{
	return job_id;
}

void
JobId::setJobId(std::string  job_id)
{
	this->job_id = job_id;
}


