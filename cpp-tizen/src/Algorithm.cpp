#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "Algorithm.h"

using namespace std;
using namespace Tizen::ArtikCloud;

Algorithm::Algorithm()
{
	//__init();
}

Algorithm::~Algorithm()
{
	//__cleanup();
}

void
Algorithm::__init()
{
	//problem_type = std::string();
	//objective = std::string();
}

void
Algorithm::__cleanup()
{
	//if(problem_type != NULL) {
	//
	//delete problem_type;
	//problem_type = NULL;
	//}
	//if(objective != NULL) {
	//
	//delete objective;
	//objective = NULL;
	//}
	//
}

void
Algorithm::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *problem_typeKey = "problem_type";
	node = json_object_get_member(pJsonObject, problem_typeKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&problem_type, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *objectiveKey = "objective";
	node = json_object_get_member(pJsonObject, objectiveKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&objective, node, "std::string", "");
		} else {
			
		}
	}
}

Algorithm::Algorithm(char* json)
{
	this->fromJson(json);
}

char*
Algorithm::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getProblemType();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *problem_typeKey = "problem_type";
	json_object_set_member(pJsonObject, problem_typeKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getObjective();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *objectiveKey = "objective";
	json_object_set_member(pJsonObject, objectiveKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
Algorithm::getProblemType()
{
	return problem_type;
}

void
Algorithm::setProblemType(std::string  problem_type)
{
	this->problem_type = problem_type;
}

std::string
Algorithm::getObjective()
{
	return objective;
}

void
Algorithm::setObjective(std::string  objective)
{
	this->objective = objective;
}


