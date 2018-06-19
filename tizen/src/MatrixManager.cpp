#include <glib-object.h>
#include <json-glib/json-glib.h>

#include "MatrixManager.h"
#include "NetClient.h"
#include "Helpers.h"
#include "Error.h"
#include "RequestInfo.h"

using namespace std;
using namespace Tizen::ArtikCloud;


MatrixManager::MatrixManager()
{

}

MatrixManager::~MatrixManager()
{

}

static gboolean __MatrixManagerresponseHandler(gpointer data)
{
	RequestInfo *request = static_cast<RequestInfo*>(data);
	g_thread_join(request->thread);

	// invoke the callback function
	bool retval = request->processor(*(request->p_chunk), *(request->code), request->errormsg, request->userData, request->handler);

	delete request;
	return FALSE;
}

static gpointer __MatrixManagerthreadFunc(gpointer data)
{
	RequestInfo *request = static_cast<RequestInfo*>(data);

	// handle the request
	NetClient::easycurl(request->host, request->path, request->method, request->queryParams,
	request->mBody, request->headerList, request->p_chunk, request->code, request->errormsg);

	request->thread = g_thread_self();
	g_idle_add(__MatrixManagerresponseHandler, static_cast<gpointer>(request));

	return NULL;
}


static bool matrixGetProcessor(MemoryStruct_s p_chunk, long code, char* errormsg, void* userData,
	void(* voidHandler)())
{
	void(* handler)(MatrixResponse, Error, void* )
	= reinterpret_cast<void(*)(MatrixResponse, Error, void* )> (voidHandler);
	
	JsonNode* pJson;
	char * data = p_chunk.memory;

	
	MatrixResponse out;

	if (code >= 200 && code < 300) {
		Error error(code, string("No Error"));




		if (isprimitive("MatrixResponse")) {
			pJson = json_from_string(data, NULL);
			jsonToValue(&out, pJson, "MatrixResponse", "MatrixResponse");
			json_node_free(pJson);

			if ("MatrixResponse" == "std::string") {
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

static bool matrixGetHelper(char * accessToken,
	std::string key, std::list<std::string> point, std::list<std::string> fromPoint, std::list<std::string> toPoint, std::list<std::string> outArray, std::list<std::string> pointHint, std::list<std::string> toPointHint, std::list<std::string> fromPointHint, std::string vehicle, 
	void(* handler)(MatrixResponse, Error, void* )
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
		if( itemAt.empty()){
			continue;
		}
		queryParams.insert(pair<string, string>("point", itemAt));
	}
	
	for (std::list
	<std::string>::iterator queryIter = fromPoint.begin(); queryIter != fromPoint.end(); ++queryIter) {
		string itemAt = stringify(&(*queryIter), "std::string");
		if( itemAt.empty()){
			continue;
		}
		queryParams.insert(pair<string, string>("fromPoint", itemAt));
	}
	
	for (std::list
	<std::string>::iterator queryIter = toPoint.begin(); queryIter != toPoint.end(); ++queryIter) {
		string itemAt = stringify(&(*queryIter), "std::string");
		if( itemAt.empty()){
			continue;
		}
		queryParams.insert(pair<string, string>("toPoint", itemAt));
	}
	
	for (std::list
	<std::string>::iterator queryIter = outArray.begin(); queryIter != outArray.end(); ++queryIter) {
		string itemAt = stringify(&(*queryIter), "std::string");
		if( itemAt.empty()){
			continue;
		}
		queryParams.insert(pair<string, string>("outArray", itemAt));
	}
	
	for (std::list
	<std::string>::iterator queryIter = pointHint.begin(); queryIter != pointHint.end(); ++queryIter) {
		string itemAt = stringify(&(*queryIter), "std::string");
		if( itemAt.empty()){
			continue;
		}
		queryParams.insert(pair<string, string>("pointHint", itemAt));
	}
	
	for (std::list
	<std::string>::iterator queryIter = toPointHint.begin(); queryIter != toPointHint.end(); ++queryIter) {
		string itemAt = stringify(&(*queryIter), "std::string");
		if( itemAt.empty()){
			continue;
		}
		queryParams.insert(pair<string, string>("toPointHint", itemAt));
	}
	
	for (std::list
	<std::string>::iterator queryIter = fromPointHint.begin(); queryIter != fromPointHint.end(); ++queryIter) {
		string itemAt = stringify(&(*queryIter), "std::string");
		if( itemAt.empty()){
			continue;
		}
		queryParams.insert(pair<string, string>("fromPointHint", itemAt));
	}
	

	itemAtq = stringify(&vehicle, "std::string");
	queryParams.insert(pair<string, string>("vehicle", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("vehicle");
	}


	itemAtq = stringify(&key, "std::string");
	queryParams.insert(pair<string, string>("key", itemAtq));

	string mBody = "";
	JsonNode* node;
	JsonArray* json_array;

	string url("/matrix");
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
		NetClient::easycurl(MatrixManager::getBasePath(), url, myhttpmethod, queryParams,
			mBody, headerList, p_chunk, &code, errormsg);
		bool retval = matrixGetProcessor(*p_chunk, code, errormsg, userData,reinterpret_cast<void(*)()>(handler));

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

		requestInfo = new(nothrow) RequestInfo (MatrixManager::getBasePath(), url, myhttpmethod, queryParams,
			mBody, headerList, p_chunk, &code, errormsg, userData, reinterpret_cast<void(*)()>(handler), matrixGetProcessor);;
		if(requestInfo == NULL)
			return false;

		thread = g_thread_new(NULL, __MatrixManagerthreadFunc, static_cast<gpointer>(requestInfo));
		return true;
	}
}




bool MatrixManager::matrixGetAsync(char * accessToken,
	std::string key, std::list<std::string> point, std::list<std::string> fromPoint, std::list<std::string> toPoint, std::list<std::string> outArray, std::list<std::string> pointHint, std::list<std::string> toPointHint, std::list<std::string> fromPointHint, std::string vehicle, 
	void(* handler)(MatrixResponse, Error, void* )
	, void* userData)
{
	return matrixGetHelper(accessToken,
	key, point, fromPoint, toPoint, outArray, pointHint, toPointHint, fromPointHint, vehicle, 
	handler, userData, true);
}

bool MatrixManager::matrixGetSync(char * accessToken,
	std::string key, std::list<std::string> point, std::list<std::string> fromPoint, std::list<std::string> toPoint, std::list<std::string> outArray, std::list<std::string> pointHint, std::list<std::string> toPointHint, std::list<std::string> fromPointHint, std::string vehicle, 
	void(* handler)(MatrixResponse, Error, void* )
	, void* userData)
{
	return matrixGetHelper(accessToken,
	key, point, fromPoint, toPoint, outArray, pointHint, toPointHint, fromPointHint, vehicle, 
	handler, userData, false);
}

static bool matrixPostProcessor(MemoryStruct_s p_chunk, long code, char* errormsg, void* userData,
	void(* voidHandler)())
{
	void(* handler)(MatrixResponse, Error, void* )
	= reinterpret_cast<void(*)(MatrixResponse, Error, void* )> (voidHandler);
	
	JsonNode* pJson;
	char * data = p_chunk.memory;

	
	MatrixResponse out;

	if (code >= 200 && code < 300) {
		Error error(code, string("No Error"));




		if (isprimitive("MatrixResponse")) {
			pJson = json_from_string(data, NULL);
			jsonToValue(&out, pJson, "MatrixResponse", "MatrixResponse");
			json_node_free(pJson);

			if ("MatrixResponse" == "std::string") {
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

static bool matrixPostHelper(char * accessToken,
	std::string key, MatrixRequest body, 
	void(* handler)(MatrixResponse, Error, void* )
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
	

	itemAtq = stringify(&key, "std::string");
	queryParams.insert(pair<string, string>("key", itemAtq));

	string mBody = "";
	JsonNode* node;
	JsonArray* json_array;

	if (isprimitive("MatrixRequest")) {
		node = converttoJson(&body, "MatrixRequest", "");
	}
	
	char *jsonStr =  body.toJson();
	node = json_from_string(jsonStr, NULL);
	g_free(static_cast<gpointer>(jsonStr));
	

	char *jsonStr1 =  json_to_string(node, false);
	mBody.append(jsonStr1);
	g_free(static_cast<gpointer>(jsonStr1));

	string url("/matrix");
	int pos;


	//TODO: free memory of errormsg, memorystruct
	MemoryStruct_s* p_chunk = new MemoryStruct_s();
	long code;
	char* errormsg = NULL;
	string myhttpmethod("POST");

	if(strcmp("PUT", "POST") == 0){
		if(strcmp("", mBody.c_str()) == 0){
			mBody.append("{}");
		}
	}

	if(!isAsync){
		NetClient::easycurl(MatrixManager::getBasePath(), url, myhttpmethod, queryParams,
			mBody, headerList, p_chunk, &code, errormsg);
		bool retval = matrixPostProcessor(*p_chunk, code, errormsg, userData,reinterpret_cast<void(*)()>(handler));

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

		requestInfo = new(nothrow) RequestInfo (MatrixManager::getBasePath(), url, myhttpmethod, queryParams,
			mBody, headerList, p_chunk, &code, errormsg, userData, reinterpret_cast<void(*)()>(handler), matrixPostProcessor);;
		if(requestInfo == NULL)
			return false;

		thread = g_thread_new(NULL, __MatrixManagerthreadFunc, static_cast<gpointer>(requestInfo));
		return true;
	}
}




bool MatrixManager::matrixPostAsync(char * accessToken,
	std::string key, MatrixRequest body, 
	void(* handler)(MatrixResponse, Error, void* )
	, void* userData)
{
	return matrixPostHelper(accessToken,
	key, body, 
	handler, userData, true);
}

bool MatrixManager::matrixPostSync(char * accessToken,
	std::string key, MatrixRequest body, 
	void(* handler)(MatrixResponse, Error, void* )
	, void* userData)
{
	return matrixPostHelper(accessToken,
	key, body, 
	handler, userData, false);
}

