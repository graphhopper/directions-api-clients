
#include "SamiGeocodingPoint.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGeocodingPoint::SamiGeocodingPoint() {
    init();
}

SamiGeocodingPoint::~SamiGeocodingPoint() {
    this->cleanup();
}

void
SamiGeocodingPoint::init() {
    pLat = null;
pLng = null;
}

void
SamiGeocodingPoint::cleanup() {
    if(pLat != null) {
        
        delete pLat;
        pLat = null;
    }
if(pLng != null) {
        
        delete pLng;
        pLng = null;
    }
}


SamiGeocodingPoint*
SamiGeocodingPoint::fromJson(String* json) {
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
SamiGeocodingPoint::fromJsonObject(IJsonValue* pJson) {
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

SamiGeocodingPoint::SamiGeocodingPoint(String* json) {
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
SamiGeocodingPoint::asJson ()
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
SamiGeocodingPoint::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pLatKey = new JsonString(L"lat");
    pJsonObject->Add(pLatKey, toJson(getPLat(), "Double", ""));

    JsonString *pLngKey = new JsonString(L"lng");
    pJsonObject->Add(pLngKey, toJson(getPLng(), "Double", ""));

    return pJsonObject;
}

Double*
SamiGeocodingPoint::getPLat() {
    return pLat;
}
void
SamiGeocodingPoint::setPLat(Double* pLat) {
    this->pLat = pLat;
}

Double*
SamiGeocodingPoint::getPLng() {
    return pLng;
}
void
SamiGeocodingPoint::setPLng(Double* pLng) {
    this->pLng = pLng;
}



} /* namespace Swagger */

