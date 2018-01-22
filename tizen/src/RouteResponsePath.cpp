#include <map>
#include <cstdlib>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "Helpers.h"


#include "RouteResponsePath.h"

using namespace std;
using namespace Tizen::ArtikCloud;

RouteResponsePath::RouteResponsePath()
{
	//__init();
}

RouteResponsePath::~RouteResponsePath()
{
	//__cleanup();
}

void
RouteResponsePath::__init()
{
	//
	//
	//distance = double(0);
	//
	//
	//time = long(0);
	//
	//
	//ascend = double(0);
	//
	//
	//descend = double(0);
	//
	//
	//points = new ResponseCoordinates();
	//
	//
	//points_encoded = bool(false);
	//
	//new std::list()std::list> bbox;
	//
	//
	//
	//snapped_waypoints = new ResponseCoordinates();
	//
	//
	//instructions = new ResponseInstructions();
	//
}

void
RouteResponsePath::__cleanup()
{
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
	//if(ascend != NULL) {
	//
	//delete ascend;
	//ascend = NULL;
	//}
	//if(descend != NULL) {
	//
	//delete descend;
	//descend = NULL;
	//}
	//if(points != NULL) {
	//
	//delete points;
	//points = NULL;
	//}
	//if(points_encoded != NULL) {
	//
	//delete points_encoded;
	//points_encoded = NULL;
	//}
	//if(bbox != NULL) {
	//bbox.RemoveAll(true);
	//delete bbox;
	//bbox = NULL;
	//}
	//if(snapped_waypoints != NULL) {
	//
	//delete snapped_waypoints;
	//snapped_waypoints = NULL;
	//}
	//if(instructions != NULL) {
	//
	//delete instructions;
	//instructions = NULL;
	//}
	//
}

void
RouteResponsePath::fromJson(char* jsonStr)
{
	JsonObject *pJsonObject = json_node_get_object(json_from_string(jsonStr,NULL));
	JsonNode *node;
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
	

		if (isprimitive("long long")) {
			jsonToValue(&time, node, "long long", "");
		} else {
			
		}
	}
	const gchar *ascendKey = "ascend";
	node = json_object_get_member(pJsonObject, ascendKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&ascend, node, "double", "");
		} else {
			
		}
	}
	const gchar *descendKey = "descend";
	node = json_object_get_member(pJsonObject, descendKey);
	if (node !=NULL) {
	

		if (isprimitive("double")) {
			jsonToValue(&descend, node, "double", "");
		} else {
			
		}
	}
	const gchar *pointsKey = "points";
	node = json_object_get_member(pJsonObject, pointsKey);
	if (node !=NULL) {
	

		if (isprimitive("ResponseCoordinates")) {
			jsonToValue(&points, node, "ResponseCoordinates", "ResponseCoordinates");
		} else {
			
			ResponseCoordinates* obj = static_cast<ResponseCoordinates*> (&points);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *points_encodedKey = "points_encoded";
	node = json_object_get_member(pJsonObject, points_encodedKey);
	if (node !=NULL) {
	

		if (isprimitive("bool")) {
			jsonToValue(&points_encoded, node, "bool", "");
		} else {
			
		}
	}
	const gchar *bboxKey = "bbox";
	node = json_object_get_member(pJsonObject, bboxKey);
	if (node !=NULL) {
	
		{
			JsonArray* arr = json_node_get_array(node);
			JsonNode*  temp_json;
			list<double> new_list;
			double inst;
			for (guint i=0;i<json_array_get_length(arr);i++) {
				temp_json = json_array_get_element(arr,i);
				if (isprimitive("double")) {
					jsonToValue(&inst, temp_json, "double", "");
				} else {
					
				}
				new_list.push_back(inst);
			}
			bbox = new_list;
		}
		
	}
	const gchar *snapped_waypointsKey = "snapped_waypoints";
	node = json_object_get_member(pJsonObject, snapped_waypointsKey);
	if (node !=NULL) {
	

		if (isprimitive("ResponseCoordinates")) {
			jsonToValue(&snapped_waypoints, node, "ResponseCoordinates", "ResponseCoordinates");
		} else {
			
			ResponseCoordinates* obj = static_cast<ResponseCoordinates*> (&snapped_waypoints);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
	const gchar *instructionsKey = "instructions";
	node = json_object_get_member(pJsonObject, instructionsKey);
	if (node !=NULL) {
	

		if (isprimitive("ResponseInstructions")) {
			jsonToValue(&instructions, node, "ResponseInstructions", "ResponseInstructions");
		} else {
			
			ResponseInstructions* obj = static_cast<ResponseInstructions*> (&instructions);
			obj->fromJson(json_to_string(node, false));
			
		}
	}
}

RouteResponsePath::RouteResponsePath(char* json)
{
	this->fromJson(json);
}

char*
RouteResponsePath::toJson()
{
	JsonObject *pJsonObject = json_object_new();
	JsonNode *node;
	if (isprimitive("double")) {
		double obj = getDistance();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *distanceKey = "distance";
	json_object_set_member(pJsonObject, distanceKey, node);
	if (isprimitive("long long")) {
		long long obj = getTime();
		node = converttoJson(&obj, "long long", "");
	}
	else {
		
	}
	const gchar *timeKey = "time";
	json_object_set_member(pJsonObject, timeKey, node);
	if (isprimitive("double")) {
		double obj = getAscend();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *ascendKey = "ascend";
	json_object_set_member(pJsonObject, ascendKey, node);
	if (isprimitive("double")) {
		double obj = getDescend();
		node = converttoJson(&obj, "double", "");
	}
	else {
		
	}
	const gchar *descendKey = "descend";
	json_object_set_member(pJsonObject, descendKey, node);
	if (isprimitive("ResponseCoordinates")) {
		ResponseCoordinates obj = getPoints();
		node = converttoJson(&obj, "ResponseCoordinates", "");
	}
	else {
		
		ResponseCoordinates obj = static_cast<ResponseCoordinates> (getPoints());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *pointsKey = "points";
	json_object_set_member(pJsonObject, pointsKey, node);
	if (isprimitive("bool")) {
		bool obj = getPointsEncoded();
		node = converttoJson(&obj, "bool", "");
	}
	else {
		
	}
	const gchar *points_encodedKey = "points_encoded";
	json_object_set_member(pJsonObject, points_encodedKey, node);
	if (isprimitive("double")) {
		list<double> new_list = static_cast<list <double> > (getBbox());
		node = converttoJson(&new_list, "double", "array");
	} else {
		node = json_node_alloc();
		list<double> new_list = static_cast<list <double> > (getBbox());
		JsonArray* json_array = json_array_new();
		GError *mygerror;
		
	}


	
	const gchar *bboxKey = "bbox";
	json_object_set_member(pJsonObject, bboxKey, node);
	if (isprimitive("ResponseCoordinates")) {
		ResponseCoordinates obj = getSnappedWaypoints();
		node = converttoJson(&obj, "ResponseCoordinates", "");
	}
	else {
		
		ResponseCoordinates obj = static_cast<ResponseCoordinates> (getSnappedWaypoints());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *snapped_waypointsKey = "snapped_waypoints";
	json_object_set_member(pJsonObject, snapped_waypointsKey, node);
	if (isprimitive("ResponseInstructions")) {
		ResponseInstructions obj = getInstructions();
		node = converttoJson(&obj, "ResponseInstructions", "");
	}
	else {
		
		ResponseInstructions obj = static_cast<ResponseInstructions> (getInstructions());
		GError *mygerror;
		mygerror = NULL;
		node = json_from_string(obj.toJson(), &mygerror);
		
	}
	const gchar *instructionsKey = "instructions";
	json_object_set_member(pJsonObject, instructionsKey, node);
	node = json_node_alloc();
	json_node_init(node, JSON_NODE_OBJECT);
	json_node_take_object(node, pJsonObject);
	char * ret = json_to_string(node, false);
	json_node_free(node);
	return ret;
}

double
RouteResponsePath::getDistance()
{
	return distance;
}

void
RouteResponsePath::setDistance(double  distance)
{
	this->distance = distance;
}

long long
RouteResponsePath::getTime()
{
	return time;
}

void
RouteResponsePath::setTime(long long  time)
{
	this->time = time;
}

double
RouteResponsePath::getAscend()
{
	return ascend;
}

void
RouteResponsePath::setAscend(double  ascend)
{
	this->ascend = ascend;
}

double
RouteResponsePath::getDescend()
{
	return descend;
}

void
RouteResponsePath::setDescend(double  descend)
{
	this->descend = descend;
}

ResponseCoordinates
RouteResponsePath::getPoints()
{
	return points;
}

void
RouteResponsePath::setPoints(ResponseCoordinates  points)
{
	this->points = points;
}

bool
RouteResponsePath::getPointsEncoded()
{
	return points_encoded;
}

void
RouteResponsePath::setPointsEncoded(bool  points_encoded)
{
	this->points_encoded = points_encoded;
}

std::list<double>
RouteResponsePath::getBbox()
{
	return bbox;
}

void
RouteResponsePath::setBbox(std::list <double> bbox)
{
	this->bbox = bbox;
}

ResponseCoordinates
RouteResponsePath::getSnappedWaypoints()
{
	return snapped_waypoints;
}

void
RouteResponsePath::setSnappedWaypoints(ResponseCoordinates  snapped_waypoints)
{
	this->snapped_waypoints = snapped_waypoints;
}

ResponseInstructions
RouteResponsePath::getInstructions()
{
	return instructions;
}

void
RouteResponsePath::setInstructions(ResponseInstructions  instructions)
{
	this->instructions = instructions;
}


