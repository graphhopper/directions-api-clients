
#include "SamiRouteResponse.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiRouteResponse::SamiRouteResponse() {
    init();
}

SamiRouteResponse::~SamiRouteResponse() {
    this->cleanup();
}

void
SamiRouteResponse::init() {
    pPaths = null;
pInfo = null;
}

void
SamiRouteResponse::cleanup() {
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


SamiRouteResponse*
SamiRouteResponse::fromJson(String* json) {
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
SamiRouteResponse::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pPathsKey = new JsonString(L"paths");
        IJsonValue* pPathsVal = null;
        pJsonObject->GetValue(pPathsKey, pPathsVal);
        if(pPathsVal != null) {
            pPaths = new ArrayList();
            
            jsonToValue(pPaths, pPathsVal, L"IList", L"SamiRouteResponsePath");
        }
        delete pPathsKey;
JsonString* pInfoKey = new JsonString(L"info");
        IJsonValue* pInfoVal = null;
        pJsonObject->GetValue(pInfoKey, pInfoVal);
        if(pInfoVal != null) {
            
            pInfo = new SamiResponseInfo();
            jsonToValue(pInfo, pInfoVal, L"SamiResponseInfo", L"SamiResponseInfo");
        }
        delete pInfoKey;
    }
}

SamiRouteResponse::SamiRouteResponse(String* json) {
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
SamiRouteResponse::asJson ()
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
SamiRouteResponse::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pPathsKey = new JsonString(L"paths");
    pJsonObject->Add(pPathsKey, toJson(getPPaths(), "SamiRouteResponsePath", "array"));

    JsonString *pInfoKey = new JsonString(L"info");
    pJsonObject->Add(pInfoKey, toJson(getPInfo(), "SamiResponseInfo", ""));

    return pJsonObject;
}

IList*
SamiRouteResponse::getPPaths() {
    return pPaths;
}
void
SamiRouteResponse::setPPaths(IList* pPaths) {
    this->pPaths = pPaths;
}

SamiResponseInfo*
SamiRouteResponse::getPInfo() {
    return pInfo;
}
void
SamiRouteResponse::setPInfo(SamiResponseInfo* pInfo) {
    this->pInfo = pInfo;
}



} /* namespace Swagger */

