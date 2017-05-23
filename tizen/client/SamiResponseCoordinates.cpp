
#include "SamiResponseCoordinates.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiResponseCoordinates::SamiResponseCoordinates() {
    init();
}

SamiResponseCoordinates::~SamiResponseCoordinates() {
    this->cleanup();
}

void
SamiResponseCoordinates::init() {
    pCoordinates = null;
}

void
SamiResponseCoordinates::cleanup() {
    if(pCoordinates != null) {
        
        delete pCoordinates;
        pCoordinates = null;
    }
}


SamiResponseCoordinates*
SamiResponseCoordinates::fromJson(String* json) {
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
SamiResponseCoordinates::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pCoordinatesKey = new JsonString(L"coordinates");
        IJsonValue* pCoordinatesVal = null;
        pJsonObject->GetValue(pCoordinatesKey, pCoordinatesVal);
        if(pCoordinatesVal != null) {
            
            pCoordinates = new SamiResponseCoordinatesArray();
            jsonToValue(pCoordinates, pCoordinatesVal, L"SamiResponseCoordinatesArray", L"SamiResponseCoordinatesArray");
        }
        delete pCoordinatesKey;
    }
}

SamiResponseCoordinates::SamiResponseCoordinates(String* json) {
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
SamiResponseCoordinates::asJson ()
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
SamiResponseCoordinates::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pCoordinatesKey = new JsonString(L"coordinates");
    pJsonObject->Add(pCoordinatesKey, toJson(getPCoordinates(), "SamiResponseCoordinatesArray", ""));

    return pJsonObject;
}

SamiResponseCoordinatesArray*
SamiResponseCoordinates::getPCoordinates() {
    return pCoordinates;
}
void
SamiResponseCoordinates::setPCoordinates(SamiResponseCoordinatesArray* pCoordinates) {
    this->pCoordinates = pCoordinates;
}



} /* namespace Swagger */

