#include "SamiIsochroneApi.h"

#include "SamiHelpers.h"
#include "SamiError.h"

using namespace Tizen::Base;

namespace Swagger {


SamiIsochroneApi::SamiIsochroneApi() {

}

SamiIsochroneApi::~SamiIsochroneApi() {

}

void
isochroneGetProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
    IJsonValue* pJson = JsonParser::ParseN(*pBuffer);

    SamiIsochroneResponse* out = new SamiIsochroneResponse();
    jsonToValue(out, pJson, L"SamiIsochroneResponse*", L"SamiIsochroneResponse");

    if (pJson) {
      if (pJson->GetType() == JSON_TYPE_OBJECT) {
         JsonObject* pObject = static_cast< JsonObject* >(pJson);
         pObject->RemoveAll(true);
      }
      else if (pJson->GetType() == JSON_TYPE_ARRAY) {
         JsonArray* pArray = static_cast< JsonArray* >(pJson);
         pArray->RemoveAll(true);
      }
      handler(out, null);
    }
    else {
      SamiError* error = new SamiError(0, new String(L"No parsable response received"));
      handler(null, error);
    }
    
  }
  else {
    SamiError* error = new SamiError(code, new String(pHttpResponse->GetStatusText()));
    handler(null, error);
    
  }
}

SamiIsochroneResponse* 
SamiIsochroneApi::isochroneGetWithCompletion(String* point, String* key, Integer* timeLimit, Integer* distanceLimit, String* vehicle, Integer* buckets, Boolean* reverseFlow, void (* success)(SamiIsochroneResponse*, SamiError*)) {
  client = new SamiApiClient();

  client->success(&isochroneGetProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  
  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  
    queryParams->Add(new String("point"), point);

    queryParams->Add(new String("time_limit"), timeLimit);

    queryParams->Add(new String("distance_limit"), distanceLimit);

    queryParams->Add(new String("vehicle"), vehicle);

    queryParams->Add(new String("buckets"), buckets);

    queryParams->Add(new String("reverse_flow"), reverseFlow);

    queryParams->Add(new String("key"), key);

  String* mBody = null;


  String url(L"/isochrone");


  client->execute(SamiIsochroneApi::getBasePath(), url, "GET", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  return null;
}


} /* namespace Swagger */
