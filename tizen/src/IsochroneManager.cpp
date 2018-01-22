#include <glib-object.h>
#include <json-glib/json-glib.h>

#include "IsochroneManager.h"
#include "NetClient.h"
#include "Helpers.h"
#include "Error.h"
#include "RequestInfo.h"

using namespace std;
using namespace Tizen::ArtikCloud;


IsochroneManager::IsochroneManager()
{

}

IsochroneManager::~IsochroneManager()
{

}

static gboolean __IsochroneManagerresponseHandler(gpointer data)
{
	RequestInfo *request = static_cast<RequestInfo*>(data);
	g_thread_join(request->thread);

	// invoke the callback function
	bool retval = request->processor(*(request->p_chunk), *(request->code), request->errormsg, request->userData, request->handler);

	delete request;
	return FALSE;
}

static gpointer __IsochroneManagerthreadFunc(gpointer data)
{
	RequestInfo *request = static_cast<RequestInfo*>(data);

	// handle the request
	NetClient::easycurl(request->host, request->path, request->method, request->queryParams,
	request->mBody, request->headerList, request->p_chunk, request->code, request->errormsg);

	request->thread = g_thread_self();
	g_idle_add(__IsochroneManagerresponseHandler, static_cast<gpointer>(request));

	return NULL;
}


static bool isochroneGetProcessor(MemoryStruct_s p_chunk, long code, char* errormsg, void* userData,
	void(* voidHandler)())
{
	void(* handler)(IsochroneResponse, Error, void* )
	= reinterpret_cast<void(*)(IsochroneResponse, Error, void* )> (voidHandler);
	
	JsonNode* pJson;
	char * data = p_chunk.memory;

	
	IsochroneResponse out;

	if (code >= 200 && code < 300) {
		Error error(code, string("No Error"));




		if (isprimitive("IsochroneResponse")) {
			pJson = json_from_string(data, NULL);
			jsonToValue(&out, pJson, "IsochroneResponse", "IsochroneResponse");
			json_node_free(pJson);

			if ("IsochroneResponse" == "std::string") {
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

static bool isochroneGetHelper(char * accessToken,
	std::string point, std::string key, int timeLimit, int distanceLimit, std::string vehicle, int buckets, bool reverseFlow, 
	void(* handler)(IsochroneResponse, Error, void* )
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
	

	itemAtq = stringify(&point, "std::string");
	queryParams.insert(pair<string, string>("point", itemAtq));


	itemAtq = stringify(&timeLimit, "int");
	queryParams.insert(pair<string, string>("time_limit", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("time_limit");
	}


	itemAtq = stringify(&distanceLimit, "int");
	queryParams.insert(pair<string, string>("distance_limit", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("distance_limit");
	}


	itemAtq = stringify(&vehicle, "std::string");
	queryParams.insert(pair<string, string>("vehicle", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("vehicle");
	}


	itemAtq = stringify(&buckets, "int");
	queryParams.insert(pair<string, string>("buckets", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("buckets");
	}


	itemAtq = stringify(&reverseFlow, "bool");
	queryParams.insert(pair<string, string>("reverse_flow", itemAtq));
	if( itemAtq.empty()==true){
		queryParams.erase("reverse_flow");
	}


	itemAtq = stringify(&key, "std::string");
	queryParams.insert(pair<string, string>("key", itemAtq));

	string mBody = "";
	JsonNode* node;
	JsonArray* json_array;

	string url("/isochrone");
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
		NetClient::easycurl(IsochroneManager::getBasePath(), url, myhttpmethod, queryParams,
			mBody, headerList, p_chunk, &code, errormsg);
		bool retval = isochroneGetProcessor(*p_chunk, code, errormsg, userData,reinterpret_cast<void(*)()>(handler));

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

		requestInfo = new(nothrow) RequestInfo (IsochroneManager::getBasePath(), url, myhttpmethod, queryParams,
			mBody, headerList, p_chunk, &code, errormsg, userData, reinterpret_cast<void(*)()>(handler), isochroneGetProcessor);;
		if(requestInfo == NULL)
			return false;

		thread = g_thread_new(NULL, __IsochroneManagerthreadFunc, static_cast<gpointer>(requestInfo));
		return true;
	}
}




bool IsochroneManager::isochroneGetAsync(char * accessToken,
	std::string point, std::string key, int timeLimit, int distanceLimit, std::string vehicle, int buckets, bool reverseFlow, 
	void(* handler)(IsochroneResponse, Error, void* )
	, void* userData)
{
	return isochroneGetHelper(accessToken,
	point, key, timeLimit, distanceLimit, vehicle, buckets, reverseFlow, 
	handler, userData, true);
}

bool IsochroneManager::isochroneGetSync(char * accessToken,
	std::string point, std::string key, int timeLimit, int distanceLimit, std::string vehicle, int buckets, bool reverseFlow, 
	void(* handler)(IsochroneResponse, Error, void* )
	, void* userData)
{
	return isochroneGetHelper(accessToken,
	point, key, timeLimit, distanceLimit, vehicle, buckets, reverseFlow, 
	handler, userData, false);
}

