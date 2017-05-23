#include "SamiSolutionApi.h"

#include "SamiHelpers.h"
#include "SamiError.h"

using namespace Tizen::Base;

namespace Swagger {


SamiSolutionApi::SamiSolutionApi() {

}

SamiSolutionApi::~SamiSolutionApi() {

}

void
getSolutionProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
    IJsonValue* pJson = JsonParser::ParseN(*pBuffer);

    SamiResponse* out = new SamiResponse();
    jsonToValue(out, pJson, L"SamiResponse*", L"SamiResponse");

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

SamiResponse* 
SamiSolutionApi::getSolutionWithCompletion(String* key, String* jobId, void (* success)(SamiResponse*, SamiError*)) {
  client = new SamiApiClient();

  client->success(&getSolutionProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  
  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  
    queryParams->Add(new String("key"), key);

  String* mBody = null;


  String url(L"/vrp/solution/{jobId}");

  String s_jobId(L"{");
  s_jobId.Append(L"jobId");
  s_jobId.Append(L"}");
  url.Replace(s_jobId, stringify(jobId, L"String*"));

  client->execute(SamiSolutionApi::getBasePath(), url, "GET", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  return null;
}


} /* namespace Swagger */
