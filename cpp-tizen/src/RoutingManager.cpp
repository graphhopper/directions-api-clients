#include <glib-object.h>
#include <json-glib/json-glib.h>

#include "RoutingManager.h"
#include "NetClient.h"
#include "Helpers.h"
#include "Error.h"
#include "RequestInfo.h"

using namespace std;
using namespace Tizen::ArtikCloud;


RoutingManager::RoutingManager()
{

}

RoutingManager::~RoutingManager()
{

}

static gboolean __RoutingManagerresponseHandler(gpointer data)
{
	RequestInfo *request = static_cast<RequestInfo*>(data);
	g_thread_join(request->thread);

	// invoke the callback function
	bool retval = request->processor(*(request->p_chunk), *(request->code), request->errormsg, request->userData, request->handler);

	delete request;
	return FALSE;
}

static gpointer __RoutingManagerthreadFunc(gpointer data)
{
	RequestInfo *request = static_cast<RequestInfo*>(data);

	// handle the request
	NetClient::easycurl(request->host, request->path, request->method, request->queryParams,
	request->mBody, request->headerList, request->p_chunk, request->code, request->errormsg);

	request->thread = g_thread_self();
	g_idle_add(__RoutingManagerresponseHandler, static_cast<gpointer>(request));

	return NULL;
}


static bool routeGetProcessor(MemoryStruct_s p_chunk, long code, char* errormsg, void* userData,
	void(* voidHandler)())
{
	void(* handler)(RouteResponse, Error, void* )
	= reinterpret_cast<void(*)(RouteResponse, Error, void* )> (voidHandler);
	
	JsonNode* pJson;
	char * data = p_chunk.memory;

	
	RouteResponse out;

	if (code >= 200 && code < 300) {
		Error error(code, string("No Error"));




		if (isprimitive("RouteResponse")) {
			pJson = json_from_string(data, NULL);
			jsonToValue(&out, pJson, "RouteResponse", "RouteResponse");
			json_node_free(pJson);

			if ("RouteResponse" == "std::string") {
				string* val = (std::string*)(&out);
				if (val->empty() && p_chunk.size>4) {
					*val = string(p_chunk.memory, p_chunk.size);
				}
			}
		} else {
			
			out.fromJson(data);
			char *jsonStr =  out.toJson();
			printf("\n%s\n", jsonStr);
			g_free(static_cast<gpointer>(jsonStr));
			
			out.fromJson(data);
			char *jsonStr =  out.toJson();
			printf("\n%s\n", jsonStr);
			g_free(static_cast<gpointer>(jsonStr));
			
		}
		handler(out, error, userData);
		return true;
		//TODO: handle case where json parsing has an error

	} else {
		Error error;
		if (errormsg != NULL) {
			error = Error(code, string(errormsg));
		} else if (p_chunk.memory != NULL) {
			error = Error(code, string(p_chunk.memory));
		} else {
			error = Error(code, string("Unknown Error"));
		}
		 handler(out, error, userData);
		return false;
			}
}

static bool routeGetHelper(char * accessToken,
	std::list<std::string> point, bool pointsEncoded, std::string key, std::string locale, bool instructions, std::string vehicle, bool elevation, bool calcPoints, std::list<std::string> pointHint, bool ch.disable, std::string weighting, bool edgeTraversal, std::string algorithm, int heading, int headingPenalty, bool passThrough, std::list<std::string> details, int roundTrip.distance, long long roundTrip.seed, int alternativeRoute.maxPaths, int alternativeRoute.maxWeightFactor, int alternativeRoute.maxShareFactor, std::string avoid, 
	void(* handler)(RouteResponse, Error, void* )
	, void* userData, bool isAsync)
{

	//TODO: maybe delete headerList after its used to free up space?
	struct curl_slist *headerList = NULL;

	
	string accessHeader = "Authorization: Bearer ";
	accessHeader.append(accessToken);
	headerList = curl_slist_append(headerList, accessHeader.c_str());
	headerList = curl_slist_append(headerList, "Content-Type: application/json");

	map <string, string> queryParams;
	string itemAtq;
	
	for (std::list
	<std::string>::iterator queryIter = point.begin(); queryIter != point.end(); ++queryIter) {
		string itemAt = stringify(&(*queryIter), "std::string");
		queryParams.insert(pair<string, string>("point", itemAt));
	}
	

	itemAtq = stringify(&locale, "std::string");
	queryParams.insert(pair<string, string>("locale", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("locale");
	}


	itemAtq = stringify(&instructions, "bool");
	queryParams.insert(pair<string, string>("instructions", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("instructions");
	}


	itemAtq = stringify(&vehicle, "std::string");
	queryParams.insert(pair<string, string>("vehicle", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("vehicle");
	}


	itemAtq = stringify(&elevation, "bool");
	queryParams.insert(pair<string, string>("elevation", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("elevation");
	}


	itemAtq = stringify(&pointsEncoded, "bool");
	queryParams.insert(pair<string, string>("points_encoded", itemAtq));


	itemAtq = stringify(&calcPoints, "bool");
	queryParams.insert(pair<string, string>("calc_points", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("calc_points");
	}

	for (std::list
	<std::string>::iterator queryIter = pointHint.begin(); queryIter != pointHint.end(); ++queryIter) {
		string itemAt = stringify(&(*queryIter), "std::string");
		if( itemAt.empty()){
			continue;
		}
		queryParams.insert(pair<string, string>("pointHint", itemAt));
	}
	

	itemAtq = stringify(&ch.disable, "bool");
	queryParams.insert(pair<string, string>("ch.disable", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("ch.disable");
	}


	itemAtq = stringify(&weighting, "std::string");
	queryParams.insert(pair<string, string>("weighting", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("weighting");
	}


	itemAtq = stringify(&edgeTraversal, "bool");
	queryParams.insert(pair<string, string>("edge_traversal", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("edge_traversal");
	}


	itemAtq = stringify(&algorithm, "std::string");
	queryParams.insert(pair<string, string>("algorithm", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("algorithm");
	}


	itemAtq = stringify(&heading, "int");
	queryParams.insert(pair<string, string>("heading", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("heading");
	}


	itemAtq = stringify(&headingPenalty, "int");
	queryParams.insert(pair<string, string>("heading_penalty", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("heading_penalty");
	}


	itemAtq = stringify(&passThrough, "bool");
	queryParams.insert(pair<string, string>("pass_through", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("pass_through");
	}

	for (std::list
	<std::string>::iterator queryIter = details.begin(); queryIter != details.end(); ++queryIter) {
		string itemAt = stringify(&(*queryIter), "std::string");
		if( itemAt.empty()){
			continue;
		}
		queryParams.insert(pair<string, string>("details", itemAt));
	}
	

	itemAtq = stringify(&roundTrip.distance, "int");
	queryParams.insert(pair<string, string>("round_trip.distance", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("round_trip.distance");
	}


	itemAtq = stringify(&roundTrip.seed, "long long");
	queryParams.insert(pair<string, string>("round_trip.seed", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("round_trip.seed");
	}


	itemAtq = stringify(&alternativeRoute.maxPaths, "int");
	queryParams.insert(pair<string, string>("alternative_route.max_paths", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("alternative_route.max_paths");
	}


	itemAtq = stringify(&alternativeRoute.maxWeightFactor, "int");
	queryParams.insert(pair<string, string>("alternative_route.max_weight_factor", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("alternative_route.max_weight_factor");
	}


	itemAtq = stringify(&alternativeRoute.maxShareFactor, "int");
	queryParams.insert(pair<string, string>("alternative_route.max_share_factor", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("alternative_route.max_share_factor");
	}


	itemAtq = stringify(&avoid, "std::string");
	queryParams.insert(pair<string, string>("avoid", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("avoid");
	}


	itemAtq = stringify(&key, "std::string");
	queryParams.insert(pair<string, string>("key", itemAtq));

	string mBody = "";
	JsonNode* node;
	JsonArray* json_array;

	string url("/route");
	int pos;


	//TODO: free memory of errormsg, memorystruct
	MemoryStruct_s* p_chunk = new MemoryStruct_s();
	long code;
	char* errormsg = NULL;
	string myhttpmethod("GET");

	if(strcmp("PUT", "GET") == 0){
		if(strcmp("", mBody.c_str()) == 0){
			mBody.append("{}");
		}
	}

	if(!isAsync){
		NetClient::easycurl(RoutingManager::getBasePath(), url, myhttpmethod, queryParams,
			mBody, headerList, p_chunk, &code, errormsg);
		bool retval = routeGetProcessor(*p_chunk, code, errormsg, userData,reinterpret_cast<void(*)()>(handler));

		curl_slist_free_all(headerList);
		if (p_chunk) {
			if(p_chunk->memory) {
				free(p_chunk->memory);
			}
			delete (p_chunk);
		}
		if (errormsg) {
			free(errormsg);
		}
		return retval;
	} else{
		GThread *thread = NULL;
		RequestInfo *requestInfo = NULL;

		requestInfo = new(nothrow) RequestInfo (RoutingManager::getBasePath(), url, myhttpmethod, queryParams,
			mBody, headerList, p_chunk, &code, errormsg, userData, reinterpret_cast<void(*)()>(handler), routeGetProcessor);;
		if(requestInfo == NULL)
			return false;

		thread = g_thread_new(NULL, __RoutingManagerthreadFunc, static_cast<gpointer>(requestInfo));
		return true;
	}
}




bool RoutingManager::routeGetAsync(char * accessToken,
	std::list<std::string> point, bool pointsEncoded, std::string key, std::string locale, bool instructions, std::string vehicle, bool elevation, bool calcPoints, std::list<std::string> pointHint, bool ch.disable, std::string weighting, bool edgeTraversal, std::string algorithm, int heading, int headingPenalty, bool passThrough, std::list<std::string> details, int roundTrip.distance, long long roundTrip.seed, int alternativeRoute.maxPaths, int alternativeRoute.maxWeightFactor, int alternativeRoute.maxShareFactor, std::string avoid, 
	void(* handler)(RouteResponse, Error, void* )
	, void* userData)
{
	return routeGetHelper(accessToken,
	point, pointsEncoded, key, locale, instructions, vehicle, elevation, calcPoints, pointHint, ch.disable, weighting, edgeTraversal, algorithm, heading, headingPenalty, passThrough, details, roundTrip.distance, roundTrip.seed, alternativeRoute.maxPaths, alternativeRoute.maxWeightFactor, alternativeRoute.maxShareFactor, avoid, 
	handler, userData, true);
}

bool RoutingManager::routeGetSync(char * accessToken,
	std::list<std::string> point, bool pointsEncoded, std::string key, std::string locale, bool instructions, std::string vehicle, bool elevation, bool calcPoints, std::list<std::string> pointHint, bool ch.disable, std::string weighting, bool edgeTraversal, std::string algorithm, int heading, int headingPenalty, bool passThrough, std::list<std::string> details, int roundTrip.distance, long long roundTrip.seed, int alternativeRoute.maxPaths, int alternativeRoute.maxWeightFactor, int alternativeRoute.maxShareFactor, std::string avoid, 
	void(* handler)(RouteResponse, Error, void* )
	, void* userData)
{
	return routeGetHelper(accessToken,
	point, pointsEncoded, key, locale, instructions, vehicle, elevation, calcPoints, pointHint, ch.disable, weighting, edgeTraversal, algorithm, heading, headingPenalty, passThrough, details, roundTrip.distance, roundTrip.seed, alternativeRoute.maxPaths, alternativeRoute.maxWeightFactor, alternativeRoute.maxShareFactor, avoid, 
	handler, userData, false);
}

