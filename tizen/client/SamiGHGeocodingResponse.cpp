
#include "SamiGHGeocodingResponse.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGHGeocodingResponse::SamiGHGeocodingResponse() {
    init();
}

SamiGHGeocodingResponse::~SamiGHGeocodingResponse() {
    this->cleanup();
}

void
SamiGHGeocodingResponse::init() {
    pHits = null;
pLocale = null;
}

void
SamiGHGeocodingResponse::cleanup() {
    if(pHits != null) {
        pHits->RemoveAll(true);
        delete pHits;
        pHits = null;
    }
if(pLocale != null) {
        
        delete pLocale;
        pLocale = null;
    }
}


SamiGHGeocodingResponse*
SamiGHGeocodingResponse::fromJson(String* json) {
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
SamiGHGeocodingResponse::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pHitsKey = new JsonString(L"hits");
        IJsonValue* pHitsVal = null;
        pJsonObject->GetValue(pHitsKey, pHitsVal);
        if(pHitsVal != null) {
            pHits = new ArrayList();
            
            jsonToValue(pHits, pHitsVal, L"IList", L"SamiGHGeocodingLocation");
        }
        delete pHitsKey;
JsonString* pLocaleKey = new JsonString(L"locale");
        IJsonValue* pLocaleVal = null;
        pJsonObject->GetValue(pLocaleKey, pLocaleVal);
        if(pLocaleVal != null) {
            
            pLocale = new String();
            jsonToValue(pLocale, pLocaleVal, L"String", L"String");
        }
        delete pLocaleKey;
    }
}

SamiGHGeocodingResponse::SamiGHGeocodingResponse(String* json) {
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
SamiGHGeocodingResponse::asJson ()
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
SamiGHGeocodingResponse::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pHitsKey = new JsonString(L"hits");
    pJsonObject->Add(pHitsKey, toJson(getPHits(), "SamiGHGeocodingLocation", "array"));

    JsonString *pLocaleKey = new JsonString(L"locale");
    pJsonObject->Add(pLocaleKey, toJson(getPLocale(), "String", ""));

    return pJsonObject;
}

IList*
SamiGHGeocodingResponse::getPHits() {
    return pHits;
}
void
SamiGHGeocodingResponse::setPHits(IList* pHits) {
    this->pHits = pHits;
}

String*
SamiGHGeocodingResponse::getPLocale() {
    return pLocale;
}
void
SamiGHGeocodingResponse::setPLocale(String* pLocale) {
    this->pLocale = pLocale;
}



} /* namespace Swagger */

