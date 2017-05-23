
#include "SamiIsochroneResponse.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiIsochroneResponse::SamiIsochroneResponse() {
    init();
}

SamiIsochroneResponse::~SamiIsochroneResponse() {
    this->cleanup();
}

void
SamiIsochroneResponse::init() {
    pPolygons = null;
pCopyrights = null;
}

void
SamiIsochroneResponse::cleanup() {
    if(pPolygons != null) {
        pPolygons->RemoveAll(true);
        delete pPolygons;
        pPolygons = null;
    }
if(pCopyrights != null) {
        pCopyrights->RemoveAll(true);
        delete pCopyrights;
        pCopyrights = null;
    }
}


SamiIsochroneResponse*
SamiIsochroneResponse::fromJson(String* json) {
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
SamiIsochroneResponse::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pPolygonsKey = new JsonString(L"polygons");
        IJsonValue* pPolygonsVal = null;
        pJsonObject->GetValue(pPolygonsKey, pPolygonsVal);
        if(pPolygonsVal != null) {
            pPolygons = new ArrayList();
            
            jsonToValue(pPolygons, pPolygonsVal, L"IList", L"SamiIsochroneResponsePolygon");
        }
        delete pPolygonsKey;
JsonString* pCopyrightsKey = new JsonString(L"copyrights");
        IJsonValue* pCopyrightsVal = null;
        pJsonObject->GetValue(pCopyrightsKey, pCopyrightsVal);
        if(pCopyrightsVal != null) {
            pCopyrights = new ArrayList();
            
            jsonToValue(pCopyrights, pCopyrightsVal, L"IList", L"String");
        }
        delete pCopyrightsKey;
    }
}

SamiIsochroneResponse::SamiIsochroneResponse(String* json) {
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
SamiIsochroneResponse::asJson ()
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
SamiIsochroneResponse::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pPolygonsKey = new JsonString(L"polygons");
    pJsonObject->Add(pPolygonsKey, toJson(getPPolygons(), "SamiIsochroneResponsePolygon", "array"));

    JsonString *pCopyrightsKey = new JsonString(L"copyrights");
    pJsonObject->Add(pCopyrightsKey, toJson(getPCopyrights(), "String", "array"));

    return pJsonObject;
}

IList*
SamiIsochroneResponse::getPPolygons() {
    return pPolygons;
}
void
SamiIsochroneResponse::setPPolygons(IList* pPolygons) {
    this->pPolygons = pPolygons;
}

IList*
SamiIsochroneResponse::getPCopyrights() {
    return pCopyrights;
}
void
SamiIsochroneResponse::setPCopyrights(IList* pCopyrights) {
    this->pCopyrights = pCopyrights;
}



} /* namespace Swagger */

