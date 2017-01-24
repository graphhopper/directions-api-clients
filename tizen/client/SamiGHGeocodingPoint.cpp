
#include "SamiGHGeocodingPoint.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGHGeocodingPoint::SamiGHGeocodingPoint() {
    init();
}

SamiGHGeocodingPoint::~SamiGHGeocodingPoint() {
    this->cleanup();
}

void
SamiGHGeocodingPoint::init() {
    pLat = null;
pLng = null;
}

void
SamiGHGeocodingPoint::cleanup() {
    if(pLat != null) {
        
        delete pLat;
        pLat = null;
    }
if(pLng != null) {
        
        delete pLng;
        pLng = null;
    }
}


SamiGHGeocodingPoint*
SamiGHGeocodingPoint::fromJson(String* json) {
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
SamiGHGeocodingPoint::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pLatKey = new JsonString(L"lat");
        IJsonValue* pLatVal = null;
        pJsonObject->GetValue(pLatKey, pLatVal);
        if(pLatVal != null) {
            
            pLat = new Double();
            jsonToValue(pLat, pLatVal, L"Double", L"Double");
        }
        delete pLatKey;
JsonString* pLngKey = new JsonString(L"lng");
        IJsonValue* pLngVal = null;
        pJsonObject->GetValue(pLngKey, pLngVal);
        if(pLngVal != null) {
            
            pLng = new Double();
            jsonToValue(pLng, pLngVal, L"Double", L"Double");
        }
        delete pLngKey;
    }
}

SamiGHGeocodingPoint::SamiGHGeocodingPoint(String* json) {
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
SamiGHGeocodingPoint::asJson ()
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
SamiGHGeocodingPoint::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pLatKey = new JsonString(L"lat");
    pJsonObject->Add(pLatKey, toJson(getPLat(), "Double", ""));

    JsonString *pLngKey = new JsonString(L"lng");
    pJsonObject->Add(pLngKey, toJson(getPLng(), "Double", ""));

    return pJsonObject;
}

Double*
SamiGHGeocodingPoint::getPLat() {
    return pLat;
}
void
SamiGHGeocodingPoint::setPLat(Double* pLat) {
    this->pLat = pLat;
}

Double*
SamiGHGeocodingPoint::getPLng() {
    return pLng;
}
void
SamiGHGeocodingPoint::setPLng(Double* pLng) {
    this->pLng = pLng;
}



} /* namespace Swagger */

