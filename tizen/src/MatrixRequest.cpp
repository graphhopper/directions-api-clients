#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "MatrixRequest.h"

using namespace std;
using namespace Tizen::ArtikCloud;

MatrixRequest::MatrixRequest()
{
	//__init();
}

MatrixRequest::~MatrixRequest()
{
	//__cleanup();
}

void
MatrixRequest::__init()
{
	//
	//new std::list()std::list> points;
	//
	//
	//
	//from_points = std::string();
	//
	//
	//to_points = std::string();
	//
	//new std::list()std::list> out_arrays;
	//
	//
	//
	//vehicle = std::string();
	//
}

void
MatrixRequest::__cleanup()
{
	//if(points != NULL) {
	//points.RemoveAll(true);
	//delete points;
	//points = NULL;
	//}
	//if(from_points != NULL) {
	//
	//delete from_points;
	//from_points = NULL;
	//}
	//if(to_points != NULL) {
	//
	//delete to_points;
	//to_points = NULL;
	//}
	//if(out_arrays != NULL) {
	//out_arrays.RemoveAll(true);
	//delete out_arrays;
	//out_arrays = NULL;
	//}
	//if(vehicle != NULL) {
	//
	//delete vehicle;
	//vehicle = NULL;
	//}
	//
}

void
MatrixRequest::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *pointsKey = "points";
	node = json_object_get_member(pJsonObject, pointsKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<std::list> new_list;
			std::list inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("std::list")) {
					jsonToValue(&inst, temp_json, "std::list", "");
				} else {
					
					inst.fromJson(json_to_string(temp_json, false));
					
				}
				new_list.push_back(inst);
			}
			points = new_list;
		}
		
	}
	const gchar *from_pointsKey = "from_points";
	node = json_object_get_member(pJsonObject, from_pointsKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&from_points, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *to_pointsKey = "to_points";
	node = json_object_get_member(pJsonObject, to_pointsKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&to_points, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *out_arraysKey = "out_arrays";
	node = json_object_get_member(pJsonObject, out_arraysKey);
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
			out_arrays = new_list;
		}
		
	}
	const gchar *vehicleKey = "vehicle";
	node = json_object_get_member(pJsonObject, vehicleKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&vehicle, node, "std::string", "");
		} else {
			
		}
	}
}

MatrixRequest::MatrixRequest(char* json)
{
	this->fromJson(json);
}

char*
MatrixRequest::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::list")) {
		list<std::list> new_list = static_cast<list <std::list> > (getPoints());
		node = converttoJson(&new_list, "std::list", "array");
	} else {
		node = json_node_alloc();
		list<std::list> new_list = static_cast<list <std::list> > (getPoints());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
		for (list<std::list>::iterator it = new_list.begin(); it != new_list.end(); it++) {
			mygerror = NULL;
			std::list obj = *it;
			JsonNode *node_temp = json_from_string(obj.toJson(), &mygerror);
			json_array_add_element(json_array, node_temp);
			g_clear_error(&mygerror);
		}
		json_node_init_array(node, json_array);
		json_array_unref(json_array);
		
	}


	
	const gchar *pointsKey = "points";
	json_object_set_member(pJsonObject, pointsKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getFromPoints();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *from_pointsKey = "from_points";
	json_object_set_member(pJsonObject, from_pointsKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getToPoints();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *to_pointsKey = "to_points";
	json_object_set_member(pJsonObject, to_pointsKey, node);
	if (isprimitive("std::string")) {
		list<std::string> new_list = static_cast<list <std::string> > (getOutArrays());
		node = converttoJson(&new_list, "std::string", "array");
	} else {
		node = json_node_alloc();
		list<std::string> new_list = static_cast<list <std::string> > (getOutArrays());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *out_arraysKey = "out_arrays";
	json_object_set_member(pJsonObject, out_arraysKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getVehicle();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *vehicleKey = "vehicle";
	json_object_set_member(pJsonObject, vehicleKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::list<std::list>
MatrixRequest::getPoints()
{
	return points;
}

void
MatrixRequest::setPoints(std::list <std::list> points)
{
	this->points = points;
}

std::string
MatrixRequest::getFromPoints()
{
	return from_points;
}

void
MatrixRequest::setFromPoints(std::string  from_points)
{
	this->from_points = from_points;
}

std::string
MatrixRequest::getToPoints()
{
	return to_points;
}

void
MatrixRequest::setToPoints(std::string  to_points)
{
	this->to_points = to_points;
}

std::list<std::string>
MatrixRequest::getOutArrays()
{
	return out_arrays;
}

void
MatrixRequest::setOutArrays(std::list <std::string> out_arrays)
{
	this->out_arrays = out_arrays;
}

std::string
MatrixRequest::getVehicle()
{
	return vehicle;
}

void
MatrixRequest::setVehicle(std::string  vehicle)
{
	this->vehicle = vehicle;
}


