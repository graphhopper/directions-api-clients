#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "TimeWindow.h"

using namespace std;
using namespace Tizen::ArtikCloud;

TimeWindow::TimeWindow()
{
	//__init();
}

TimeWindow::~TimeWindow()
{
	//__cleanup();
}

void
TimeWindow::__init()
{
	//earliest = long(0);
	//latest = long(0);
}

void
TimeWindow::__cleanup()
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
	//
}

void
TimeWindow::fromJson(char* jsonStr)
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
}

TimeWindow::TimeWindow(char* json)
{
	this->fromJson(json);
}

char*
TimeWindow::toJson()
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
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

long long
TimeWindow::getEarliest()
{
	return earliest;
}

void
TimeWindow::setEarliest(long long  earliest)
{
	this->earliest = earliest;
}

long long
TimeWindow::getLatest()
{
	return latest;
}

void
TimeWindow::setLatest(long long  latest)
{
	this->latest = latest;
}


