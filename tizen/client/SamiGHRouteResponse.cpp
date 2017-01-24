
#include "SamiGHRouteResponse.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGHRouteResponse::SamiGHRouteResponse() {
    init();
}

SamiGHRouteResponse::~SamiGHRouteResponse() {
    this->cleanup();
}

void
SamiGHRouteResponse::init() {
    pPaths = null;
pInfo = null;
}

void
SamiGHRouteResponse::cleanup() {
    if(pPaths != null) {
        pPaths->RemoveAll(true);
        delete pPaths;
        pPaths = null;
    }
if(pInfo != null) {
        
        delete pInfo;
        pInfo = null;
    }
}


SamiGHRouteResponse*
SamiGHRouteResponse::fromJson(String* json) {
    this->cleanup();
    String str(json->GetPointer());
    int length = str.GetLength();

    ByteBuffer buffer;
    buffer.Construct(length);

    for (int i = 0; i < length; ++i) {
       byte b = str[i];
       buffer.SetByte(b);
    }

    IJsonValue* pJson = JsonParser::ParseN(buffer);
    fromJsonObject(pJson);
    if (pJson->GetType() == JSON_TYPE_OBJECT) {
       JsonObject* pObject = static_cast< JsonObject* >(pJson);
       pObject->RemoveAll(true);
    }
    else if (pJson->GetType() == JSON_TYPE_ARRAY) {
       JsonArray* pArray = static_cast< JsonArray* >(pJson);
       pArray->RemoveAll(true);
    }
    delete pJson;
    return this;
}


void
SamiGHRouteResponse::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pPathsKey = new JsonString(L"paths");
        IJsonValue* pPathsVal = null;
        pJsonObject->GetValue(pPathsKey, pPathsVal);
        if(pPathsVal != null) {
            pPaths = new ArrayList();
            
            jsonToValue(pPaths, pPathsVal, L"IList", L"SamiGHRouteResponsePath");
        }
        delete pPathsKey;
JsonString* pInfoKey = new JsonString(L"info");
        IJsonValue* pInfoVal = null;
        pJsonObject->GetValue(pInfoKey, pInfoVal);
        if(pInfoVal != null) {
            
            pInfo = new SamiGHResponseInfo();
            jsonToValue(pInfo, pInfoVal, L"SamiGHResponseInfo", L"SamiGHResponseInfo");
        }
        delete pInfoKey;
    }
}

SamiGHRouteResponse::SamiGHRouteResponse(String* json) {
    init();
    String str(json->GetPointer());
    int length = str.GetLength();

    ByteBuffer buffer;
    buffer.Construct(length);

    for (int i = 0; i < length; ++i) {
       byte b = str[i];
       buffer.SetByte(b);
    }

    IJsonValue* pJson = JsonParser::ParseN(buffer);
    fromJsonObject(pJson);
    if (pJson->GetType() == JSON_TYPE_OBJECT) {
       JsonObject* pObject = static_cast< JsonObject* >(pJson);
       pObject->RemoveAll(true);
    }
    else if (pJson->GetType() == JSON_TYPE_ARRAY) {
       JsonArray* pArray = static_cast< JsonArray* >(pJson);
       pArray->RemoveAll(true);
    }
    delete pJson;
}

String
SamiGHRouteResponse::asJson ()
{
    JsonObject* pJsonObject = asJsonObject();

    char *pComposeBuf = new char[256];
    JsonWriter::Compose(pJsonObject, pComposeBuf, 256);
    String s = String(pComposeBuf);

    delete pComposeBuf;
    pJsonObject->RemoveAll(true);
    delete pJsonObject;

    return s;
}

JsonObject*
SamiGHRouteResponse::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pPathsKey = new JsonString(L"paths");
    pJsonObject->Add(pPathsKey, toJson(getPPaths(), "SamiGHRouteResponsePath", "array"));

    JsonString *pInfoKey = new JsonString(L"info");
    pJsonObject->Add(pInfoKey, toJson(getPInfo(), "SamiGHResponseInfo", ""));

    return pJsonObject;
}

IList*
SamiGHRouteResponse::getPPaths() {
    return pPaths;
}
void
SamiGHRouteResponse::setPPaths(IList* pPaths) {
    this->pPaths = pPaths;
}

SamiGHResponseInfo*
SamiGHRouteResponse::getPInfo() {
    return pInfo;
}
void
SamiGHRouteResponse::setPInfo(SamiGHResponseInfo* pInfo) {
    this->pInfo = pInfo;
}



} /* namespace Swagger */

