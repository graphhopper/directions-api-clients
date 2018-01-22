#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "ResponseInstruction.h"

using namespace std;
using namespace Tizen::ArtikCloud;

ResponseInstruction::ResponseInstruction()
{
	//__init();
}

ResponseInstruction::~ResponseInstruction()
{
	//__cleanup();
}

void
ResponseInstruction::__init()
{
	//
	//
	//text = std::string();
	//
	//
	//street_name = std::string();
	//
	//
	//distance = double(0);
	//
	//
	//time = int(0);
	//
	//new std::list()std::list> interval;
	//
	//
	//
	//sign = int(0);
	//
	//
	//annotation_text = std::string();
	//
	//
	//annotation_importance = int(0);
	//
	//
	//exit_number = int(0);
	//
	//
	//turn_angle = double(0);
	//
}

void
ResponseInstruction::__cleanup()
{
	//if(text != NULL) {
	//
	//delete text;
	//text = NULL;
	//}
	//if(street_name != NULL) {
	//
	//delete street_name;
	//street_name = NULL;
	//}
	//if(distance != NULL) {
	//
	//delete distance;
	//distance = NULL;
	//}
	//if(time != NULL) {
	//
	//delete time;
	//time = NULL;
	//}
	//if(interval != NULL) {
	//interval.RemoveAll(true);
	//delete interval;
	//interval = NULL;
	//}
	//if(sign != NULL) {
	//
	//delete sign;
	//sign = NULL;
	//}
	//if(annotation_text != NULL) {
	//
	//delete annotation_text;
	//annotation_text = NULL;
	//}
	//if(annotation_importance != NULL) {
	//
	//delete annotation_importance;
	//annotation_importance = NULL;
	//}
	//if(exit_number != NULL) {
	//
	//delete exit_number;
	//exit_number = NULL;
	//}
	//if(turn_angle != NULL) {
	//
	//delete turn_angle;
	//turn_angle = NULL;
	//}
	//
}

void
ResponseInstruction::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
	const gchar *textKey = "text";
	node = json_object_get_member(pJsonObject, textKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&text, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *street_nameKey = "street_name";
	node = json_object_get_member(pJsonObject, street_nameKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&street_name, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *distanceKey = "distance";
	node = json_object_get_member(pJsonObject, distanceKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&distance, node, "double", "");
		} else {
			
		}
	}
	const gchar *timeKey = "time";
	node = json_object_get_member(pJsonObject, timeKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&time, node, "int", "");
		} else {
			
		}
	}
	const gchar *intervalKey = "interval";
	node = json_object_get_member(pJsonObject, intervalKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<int> new_list;
			int inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("int")) {
					jsonToValue(&inst, temp_json, "int", "");
				} else {
					
				}
				new_list.push_back(inst);
			}
			interval = new_list;
		}
		
	}
	const gchar *signKey = "sign";
	node = json_object_get_member(pJsonObject, signKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&sign, node, "int", "");
		} else {
			
		}
	}
	const gchar *annotation_textKey = "annotation_text";
	node = json_object_get_member(pJsonObject, annotation_textKey);
	if (node !=NULL) {
	

		if (isprimitive("std::string")) {
			jsonToValue(&annotation_text, node, "std::string", "");
		} else {
			
		}
	}
	const gchar *annotation_importanceKey = "annotation_importance";
	node = json_object_get_member(pJsonObject, annotation_importanceKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&annotation_importance, node, "int", "");
		} else {
			
		}
	}
	const gchar *exit_numberKey = "exit_number";
	node = json_object_get_member(pJsonObject, exit_numberKey);
	if (node !=NULL) {
	

		if (isprimitive("int")) {
			jsonToValue(&exit_number, node, "int", "");
		} else {
			
		}
	}
	const gchar *turn_angleKey = "turn_angle";
	node = json_object_get_member(pJsonObject, turn_angleKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&turn_angle, node, "double", "");
		} else {
			
		}
	}
}

ResponseInstruction::ResponseInstruction(char* json)
{
	this->fromJson(json);
}

char*
ResponseInstruction::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("std::string")) {
		std::string obj = getText();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *textKey = "text";
	json_object_set_member(pJsonObject, textKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getStreetName();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *street_nameKey = "street_name";
	json_object_set_member(pJsonObject, street_nameKey, node);
	if (isprimitive("double")) {
		double obj = getDistance();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *distanceKey = "distance";
	json_object_set_member(pJsonObject, distanceKey, node);
	if (isprimitive("int")) {
		int obj = getTime();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *timeKey = "time";
	json_object_set_member(pJsonObject, timeKey, node);
	if (isprimitive("int")) {
		list<int> new_list = static_cast<list <int> > (getInterval());
		node = converttoJson(&new_list, "int", "array");
	} else {
		node = json_node_alloc();
		list<int> new_list = static_cast<list <int> > (getInterval());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *intervalKey = "interval";
	json_object_set_member(pJsonObject, intervalKey, node);
	if (isprimitive("int")) {
		int obj = getSign();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *signKey = "sign";
	json_object_set_member(pJsonObject, signKey, node);
	if (isprimitive("std::string")) {
		std::string obj = getAnnotationText();
		node = converttoJson(&obj, "std::string", "");
	}
	else {
		
	}
	const gchar *annotation_textKey = "annotation_text";
	json_object_set_member(pJsonObject, annotation_textKey, node);
	if (isprimitive("int")) {
		int obj = getAnnotationImportance();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *annotation_importanceKey = "annotation_importance";
	json_object_set_member(pJsonObject, annotation_importanceKey, node);
	if (isprimitive("int")) {
		int obj = getExitNumber();
		node = converttoJson(&obj, "int", "");
	}
	else {
		
	}
	const gchar *exit_numberKey = "exit_number";
	json_object_set_member(pJsonObject, exit_numberKey, node);
	if (isprimitive("double")) {
		double obj = getTurnAngle();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *turn_angleKey = "turn_angle";
	json_object_set_member(pJsonObject, turn_angleKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

std::string
ResponseInstruction::getText()
{
	return text;
}

void
ResponseInstruction::setText(std::string  text)
{
	this->text = text;
}

std::string
ResponseInstruction::getStreetName()
{
	return street_name;
}

void
ResponseInstruction::setStreetName(std::string  street_name)
{
	this->street_name = street_name;
}

double
ResponseInstruction::getDistance()
{
	return distance;
}

void
ResponseInstruction::setDistance(double  distance)
{
	this->distance = distance;
}

int
ResponseInstruction::getTime()
{
	return time;
}

void
ResponseInstruction::setTime(int  time)
{
	this->time = time;
}

std::list<int>
ResponseInstruction::getInterval()
{
	return interval;
}

void
ResponseInstruction::setInterval(std::list <int> interval)
{
	this->interval = interval;
}

int
ResponseInstruction::getSign()
{
	return sign;
}

void
ResponseInstruction::setSign(int  sign)
{
	this->sign = sign;
}

std::string
ResponseInstruction::getAnnotationText()
{
	return annotation_text;
}

void
ResponseInstruction::setAnnotationText(std::string  annotation_text)
{
	this->annotation_text = annotation_text;
}

int
ResponseInstruction::getAnnotationImportance()
{
	return annotation_importance;
}

void
ResponseInstruction::setAnnotationImportance(int  annotation_importance)
{
	this->annotation_importance = annotation_importance;
}

int
ResponseInstruction::getExitNumber()
{
	return exit_number;
}

void
ResponseInstruction::setExitNumber(int  exit_number)
{
	this->exit_number = exit_number;
}

double
ResponseInstruction::getTurnAngle()
{
	return turn_angle;
}

void
ResponseInstruction::setTurnAngle(double  turn_angle)
{
	this->turn_angle = turn_angle;
}


