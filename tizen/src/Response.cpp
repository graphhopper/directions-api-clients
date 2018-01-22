#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Response.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Response::Response()
{
	//__init();
}

Response::~Response()
{
	//__cleanup();
}

void
Response::__init()
{
	//
	//new std::list()std::list> copyrights;
	//
	//
	//
	//job_id = std::string();
	//
	//
	//status = std::string();
	//
	//
	//waiting_in_queue = long(0);
	//
	//
	//processing_time = long(0);
	//
	//
	//solution = new Solution();
	//
}

void
Response::__cleanup()
{
	//if(copyrights != NULL) {
	//copyrights.RemoveAll(true);
	//delete copyrights;
	//copyrights = NULL;
	//}
	//if(job_id != NULL) {
	//
	//delete job_id;
	//job_id = NULL;
	//}
	//if(status != NULL) {
	//
	//delete status;
	//status = NULL;
	//}
	//if(waiting_in_queue != NULL) {
	//
	//delete waiting_in_queue;
	//waiting_in_queue = NULL;
	//}
	//if(processing_time != NULL) {
	//
	//delete processing_time;
	//processing_time = NULL;
	//}
	//if(solution != NULL) {
	//
	//delete solution;
	//solution = NULL;
	//}
	//
}

void
Response::fromJson(char* jsonStr)
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
	const gchar *job_idKey = "job_id";
	node = json_object_get_member(pJsonObject, job_idKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&job_id, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *statusKey = "status";
	node = json_object_get_member(pJsonObject, statusKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&status, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *waiting_in_queueKey = "waiting_in_queue";
	node = json_object_get_member(pJsonObject, waiting_in_queueKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&waiting_in_queue, node, "long long", "");
		} else {
			
		}
	}
	const gchar *processing_timeKey = "processing_time";
	node = json_object_get_member(pJsonObject, processing_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&processing_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *solutionKey = "solution";
	node = json_object_get_member(pJsonObject, solutionKey);
	if (node !=NULL) {
	

		if (isprimitive("Solution")) {
			jsonToValue(&solution, node, "Solution", "Solution");
		} else {
			
			Solution* obj = static_cast<Solution*> (&solution);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

Response::Response(char* json)
{
	this->fromJson(json);
}

char*
Response::toJson()
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
	if (isprimitive("std::string")) {
		std::string obj = getJobId();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *job_idKey = "job_id";
	json_object_set_member(pJsonObject, job_idKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getStatus();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *statusKey = "status";
	json_object_set_member(pJsonObject, statusKey, node);
	if (isprimitive("long long")) {
		long long obj = getWaitingInQueue();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *waiting_in_queueKey = "waiting_in_queue";
	json_object_set_member(pJsonObject, waiting_in_queueKey, node);
	if (isprimitive("long long")) {
		long long obj = getProcessingTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *processing_timeKey = "processing_time";
	json_object_set_member(pJsonObject, processing_timeKey, node);
	if (isprimitive("Solution")) {
		Solution obj = getSolution();
		node = converttoJson(&obj, "Solution", "");
	}
	else {
		
		Solution obj = static_cast<Solution> (getSolution());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *solutionKey = "solution";
	json_object_set_member(pJsonObject, solutionKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::list<std::string>
Response::getCopyrights()
{
	return copyrights;
}

void
Response::setCopyrights(std::list <std::string> copyrights)
{
	this->copyrights = copyrights;
}

std::string
Response::getJobId()
{
	return job_id;
}

void
Response::setJobId(std::string  job_id)
{
	this->job_id = job_id;
}

std::string
Response::getStatus()
{
	return status;
}

void
Response::setStatus(std::string  status)
{
	this->status = status;
}

long long
Response::getWaitingInQueue()
{
	return waiting_in_queue;
}

void
Response::setWaitingInQueue(long long  waiting_in_queue)
{
	this->waiting_in_queue = waiting_in_queue;
}

long long
Response::getProcessingTime()
{
	return processing_time;
}

void
Response::setProcessingTime(long long  processing_time)
{
	this->processing_time = processing_time;
}

Solution
Response::getSolution()
{
	return solution;
}

void
Response::setSolution(Solution  solution)
{
	this->solution = solution;
}


