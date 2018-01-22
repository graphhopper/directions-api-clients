#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Break.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Break::Break()
{
	//__init();
}

Break::~Break()
{
	//__cleanup();
}

void
Break::__init()
{
	//
	//
	//earliest = long(0);
	//
	//
	//latest = long(0);
	//
	//
	//duration = long(0);
	//
	//
	//max_driving_time = long(0);
	//
	//
	//initial_driving_time = long(0);
	//
	//new std::list()std::list> possible_split;
	//
	//
}

void
Break::__cleanup()
{
	//if(earliest != NULL) {
	//
	//delete earliest;
	//earliest = NULL;
	//}
	//if(latest != NULL) {
	//
	//delete latest;
	//latest = NULL;
	//}
	//if(duration != NULL) {
	//
	//delete duration;
	//duration = NULL;
	//}
	//if(max_driving_time != NULL) {
	//
	//delete max_driving_time;
	//max_driving_time = NULL;
	//}
	//if(initial_driving_time != NULL) {
	//
	//delete initial_driving_time;
	//initial_driving_time = NULL;
	//}
	//if(possible_split != NULL) {
	//possible_split.RemoveAll(true);
	//delete possible_split;
	//possible_split = NULL;
	//}
	//
}

void
Break::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *earliestKey = "earliest";
	node = json_object_get_member(pJsonObject, earliestKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&earliest, node, "long long", "");
		} else {
			
		}
	}
	const gchar *latestKey = "latest";
	node = json_object_get_member(pJsonObject, latestKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&latest, node, "long long", "");
		} else {
			
		}
	}
	const gchar *durationKey = "duration";
	node = json_object_get_member(pJsonObject, durationKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&duration, node, "long long", "");
		} else {
			
		}
	}
	const gchar *max_driving_timeKey = "max_driving_time";
	node = json_object_get_member(pJsonObject, max_driving_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&max_driving_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *initial_driving_timeKey = "initial_driving_time";
	node = json_object_get_member(pJsonObject, initial_driving_timeKey);
	if (node !=NULL) {
	

		if (isprimitive("long long")) {
			jsonToValue(&initial_driving_time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *possible_splitKey = "possible_split";
	node = json_object_get_member(pJsonObject, possible_splitKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<long long> new_list;
			long long inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("long long")) {
					jsonToValue(&inst, temp_json, "long long", "");
				} else {
					
				}
				new_list.push_back(inst);
			}
			possible_split = new_list;
		}
		
	}
}

Break::Break(char* json)
{
	this->fromJson(json);
}

char*
Break::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("long long")) {
		long long obj = getEarliest();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *earliestKey = "earliest";
	json_object_set_member(pJsonObject, earliestKey, node);
	if (isprimitive("long long")) {
		long long obj = getLatest();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *latestKey = "latest";
	json_object_set_member(pJsonObject, latestKey, node);
	if (isprimitive("long long")) {
		long long obj = getDuration();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *durationKey = "duration";
	json_object_set_member(pJsonObject, durationKey, node);
	if (isprimitive("long long")) {
		long long obj = getMaxDrivingTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *max_driving_timeKey = "max_driving_time";
	json_object_set_member(pJsonObject, max_driving_timeKey, node);
	if (isprimitive("long long")) {
		long long obj = getInitialDrivingTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *initial_driving_timeKey = "initial_driving_time";
	json_object_set_member(pJsonObject, initial_driving_timeKey, node);
	if (isprimitive("long long")) {
		list<long long> new_list = static_cast<list <long long> > (getPossibleSplit());
		node = converttoJson(&new_list, "long long", "array");
	} else {
		node = json_node_alloc();
		list<long long> new_list = static_cast<list <long long> > (getPossibleSplit());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *possible_splitKey = "possible_split";
	json_object_set_member(pJsonObject, possible_splitKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

long long
Break::getEarliest()
{
	return earliest;
}

void
Break::setEarliest(long long  earliest)
{
	this->earliest = earliest;
}

long long
Break::getLatest()
{
	return latest;
}

void
Break::setLatest(long long  latest)
{
	this->latest = latest;
}

long long
Break::getDuration()
{
	return duration;
}

void
Break::setDuration(long long  duration)
{
	this->duration = duration;
}

long long
Break::getMaxDrivingTime()
{
	return max_driving_time;
}

void
Break::setMaxDrivingTime(long long  max_driving_time)
{
	this->max_driving_time = max_driving_time;
}

long long
Break::getInitialDrivingTime()
{
	return initial_driving_time;
}

void
Break::setInitialDrivingTime(long long  initial_driving_time)
{
	this->initial_driving_time = initial_driving_time;
}

std::list<long long>
Break::getPossibleSplit()
{
	return possible_split;
}

void
Break::setPossibleSplit(std::list <long long> possible_split)
{
	this->possible_split = possible_split;
}


