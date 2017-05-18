
#include "SamiLocation.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiLocation::SamiLocation() {
    init();
}

SamiLocation::~SamiLocation() {
    this->cleanup();
}

void
SamiLocation::init() {
    pLon = null;
pLat = null;
}

void
SamiLocation::cleanup() {
    if(pLon != null) {
        
        delete pLon;
        pLon = null;
    }
if(pLat != null) {
        
        delete pLat;
        pLat = null;
    }
}


SamiLocation*
SamiLocation::fromJson(String* json) {
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
SamiLocation::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pLonKey = new JsonString(L"lon");
        IJsonValue* pLonVal = null;
        pJsonObject->GetValue(pLonKey, pLonVal);
        if(pLonVal != null) {
            
            pLon = new Double();
            jsonToValue(pLon, pLonVal, L"Double", L"Double");
        }
        delete pLonKey;
JsonString* pLatKey = new JsonString(L"lat");
        IJsonValue* pLatVal = null;
        pJsonObject->GetValue(pLatKey, pLatVal);
        if(pLatVal != null) {
            
            pLat = new Double();
            jsonToValue(pLat, pLatVal, L"Double", L"Double");
        }
        delete pLatKey;
    }
}

SamiLocation::SamiLocation(String* json) {
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
SamiLocation::asJson ()
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
SamiLocation::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pLonKey = new JsonString(L"lon");
    pJsonObject->Add(pLonKey, toJson(getPLon(), "Double", ""));

    JsonString *pLatKey = new JsonString(L"lat");
    pJsonObject->Add(pLatKey, toJson(getPLat(), "Double", ""));

    return pJsonObject;
}

Double*
SamiLocation::getPLon() {
    return pLon;
}
void
SamiLocation::setPLon(Double* pLon) {
    this->pLon = pLon;
}

Double*
SamiLocation::getPLat() {
    return pLat;
}
void
SamiLocation::setPLat(Double* pLat) {
    this->pLat = pLat;
}



} /* namespace Swagger */

