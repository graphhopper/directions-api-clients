#include "SamiMatrixApi.h"

#include "SamiHelpers.h"
#include "SamiError.h"

using namespace Tizen::Base;

namespace Swagger {


SamiMatrixApi::SamiMatrixApi() {

}

SamiMatrixApi::~SamiMatrixApi() {

}

void
matrixGetProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
    IJsonValue* pJson = JsonParser::ParseN(*pBuffer);

    SamiMatrixResponse* out = new SamiMatrixResponse();
    jsonToValue(out, pJson, L"SamiMatrixResponse*", L"SamiMatrixResponse");

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

SamiMatrixResponse* 
SamiMatrixApi::matrixGetWithCompletion(String* key, IList* point, String* fromPoint, String* toPoint, IList* outArray, String* vehicle, void (* success)(SamiMatrixResponse*, SamiError*)) {
  client = new SamiApiClient();

  client->success(&matrixGetProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  
  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  
  int sz = point->GetCount();
  for(int i = 0; i < sz; i++) {
    String itemAt = stringify(point->GetAt(i), "String*");
    queryParams->Add(new String("point"), new String(itemAt));
  }
  
    queryParams->Add(new String("from_point"), fromPoint);

    queryParams->Add(new String("to_point"), toPoint);

  int sz = outArray->GetCount();
  for(int i = 0; i < sz; i++) {
    String itemAt = stringify(outArray->GetAt(i), "String*");
    queryParams->Add(new String("outArray"), new String(itemAt));
  }
  
    queryParams->Add(new String("vehicle"), vehicle);

    queryParams->Add(new String("key"), key);

  String* mBody = null;


  String url(L"/matrix");


  client->execute(SamiMatrixApi::getBasePath(), url, "GET", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  return null;
}

void
matrixPostProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
    IJsonValue* pJson = JsonParser::ParseN(*pBuffer);

    SamiMatrixResponse* out = new SamiMatrixResponse();
    jsonToValue(out, pJson, L"SamiMatrixResponse*", L"SamiMatrixResponse");

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

SamiMatrixResponse* 
SamiMatrixApi::matrixPostWithCompletion(String* key, SamiMatrixRequest* body, void (* success)(SamiMatrixResponse*, SamiError*)) {
  client = new SamiApiClient();

  client->success(&matrixPostProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  
  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  
    queryParams->Add(new String("key"), key);

  String* mBody = null;

  if(body != null) {
    mBody = new String(body->asJson());
    headerParams->Add(new String("Content-Type"), new String("application/json"));
  }

  String url(L"/matrix");


  client->execute(SamiMatrixApi::getBasePath(), url, "POST", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  return null;
}


} /* namespace Swagger */
