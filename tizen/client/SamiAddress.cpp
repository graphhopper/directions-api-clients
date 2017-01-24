
#include "SamiAddress.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiAddress::SamiAddress() {
    init();
}

SamiAddress::~SamiAddress() {
    this->cleanup();
}

void
SamiAddress::init() {
    pLocation_id = null;
pLon = null;
pLat = null;
}

void
SamiAddress::cleanup() {
    if(pLocation_id != null) {
        
        delete pLocation_id;
        pLocation_id = null;
    }
if(pLon != null) {
        
        delete pLon;
        pLon = null;
    }
if(pLat != null) {
        
        delete pLat;
        pLat = null;
    }
}


SamiAddress*
SamiAddress::fromJson(String* json) {
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
SamiAddress::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pLocation_idKey = new JsonString(L"location_id");
        IJsonValue* pLocation_idVal = null;
        pJsonObject->GetValue(pLocation_idKey, pLocation_idVal);
        if(pLocation_idVal != null) {
            
            pLocation_id = new String();
            jsonToValue(pLocation_id, pLocation_idVal, L"String", L"String");
        }
        delete pLocation_idKey;
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

SamiAddress::SamiAddress(String* json) {
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
SamiAddress::asJson ()
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
SamiAddress::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pLocation_idKey = new JsonString(L"location_id");
    pJsonObject->Add(pLocation_idKey, toJson(getPLocationId(), "String", ""));

    JsonString *pLonKey = new JsonString(L"lon");
    pJsonObject->Add(pLonKey, toJson(getPLon(), "Double", ""));

    JsonString *pLatKey = new JsonString(L"lat");
    pJsonObject->Add(pLatKey, toJson(getPLat(), "Double", ""));

    return pJsonObject;
}

String*
SamiAddress::getPLocationId() {
    return pLocation_id;
}
void
SamiAddress::setPLocationId(String* pLocation_id) {
    this->pLocation_id = pLocation_id;
}

Double*
SamiAddress::getPLon() {
    return pLon;
}
void
SamiAddress::setPLon(Double* pLon) {
    this->pLon = pLon;
}

Double*
SamiAddress::getPLat() {
    return pLat;
}
void
SamiAddress::setPLat(Double* pLat) {
    this->pLat = pLat;
}



} /* namespace Swagger */

