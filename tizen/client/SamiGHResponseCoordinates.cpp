
#include "SamiGHResponseCoordinates.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGHResponseCoordinates::SamiGHResponseCoordinates() {
    init();
}

SamiGHResponseCoordinates::~SamiGHResponseCoordinates() {
    this->cleanup();
}

void
SamiGHResponseCoordinates::init() {
    pCoordinates = null;
}

void
SamiGHResponseCoordinates::cleanup() {
    if(pCoordinates != null) {
        
        delete pCoordinates;
        pCoordinates = null;
    }
}


SamiGHResponseCoordinates*
SamiGHResponseCoordinates::fromJson(String* json) {
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
SamiGHResponseCoordinates::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pCoordinatesKey = new JsonString(L"coordinates");
        IJsonValue* pCoordinatesVal = null;
        pJsonObject->GetValue(pCoordinatesKey, pCoordinatesVal);
        if(pCoordinatesVal != null) {
            
            pCoordinates = new SamiGHResponseCoordinatesArray();
            jsonToValue(pCoordinates, pCoordinatesVal, L"SamiGHResponseCoordinatesArray", L"SamiGHResponseCoordinatesArray");
        }
        delete pCoordinatesKey;
    }
}

SamiGHResponseCoordinates::SamiGHResponseCoordinates(String* json) {
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
SamiGHResponseCoordinates::asJson ()
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
SamiGHResponseCoordinates::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pCoordinatesKey = new JsonString(L"coordinates");
    pJsonObject->Add(pCoordinatesKey, toJson(getPCoordinates(), "SamiGHResponseCoordinatesArray", ""));

    return pJsonObject;
}

SamiGHResponseCoordinatesArray*
SamiGHResponseCoordinates::getPCoordinates() {
    return pCoordinates;
}
void
SamiGHResponseCoordinates::setPCoordinates(SamiGHResponseCoordinatesArray* pCoordinates) {
    this->pCoordinates = pCoordinates;
}



} /* namespace Swagger */

