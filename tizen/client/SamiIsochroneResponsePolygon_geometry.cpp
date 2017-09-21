
#include "SamiIsochroneResponsePolygon_geometry.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiIsochroneResponsePolygon_geometry::SamiIsochroneResponsePolygon_geometry() {
    init();
}

SamiIsochroneResponsePolygon_geometry::~SamiIsochroneResponsePolygon_geometry() {
    this->cleanup();
}

void
SamiIsochroneResponsePolygon_geometry::init() {
    pType = null;
pCoordinates = null;
}

void
SamiIsochroneResponsePolygon_geometry::cleanup() {
    if(pType != null) {
        
        delete pType;
        pType = null;
    }
if(pCoordinates != null) {
        pCoordinates->RemoveAll(true);
        delete pCoordinates;
        pCoordinates = null;
    }
}


SamiIsochroneResponsePolygon_geometry*
SamiIsochroneResponsePolygon_geometry::fromJson(String* json) {
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
SamiIsochroneResponsePolygon_geometry::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pTypeKey = new JsonString(L"type");
        IJsonValue* pTypeVal = null;
        pJsonObject->GetValue(pTypeKey, pTypeVal);
        if(pTypeVal != null) {
            
            pType = new String();
            jsonToValue(pType, pTypeVal, L"String", L"String");
        }
        delete pTypeKey;
JsonString* pCoordinatesKey = new JsonString(L"coordinates");
        IJsonValue* pCoordinatesVal = null;
        pJsonObject->GetValue(pCoordinatesKey, pCoordinatesVal);
        if(pCoordinatesVal != null) {
            pCoordinates = new ArrayList();
            
            jsonToValue(pCoordinates, pCoordinatesVal, L"IList", L"SamiResponseCoordinatesArray");
        }
        delete pCoordinatesKey;
    }
}

SamiIsochroneResponsePolygon_geometry::SamiIsochroneResponsePolygon_geometry(String* json) {
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
SamiIsochroneResponsePolygon_geometry::asJson ()
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
SamiIsochroneResponsePolygon_geometry::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pTypeKey = new JsonString(L"type");
    pJsonObject->Add(pTypeKey, toJson(getPType(), "String", ""));

    JsonString *pCoordinatesKey = new JsonString(L"coordinates");
    pJsonObject->Add(pCoordinatesKey, toJson(getPCoordinates(), "SamiResponseCoordinatesArray", "array"));

    return pJsonObject;
}

String*
SamiIsochroneResponsePolygon_geometry::getPType() {
    return pType;
}
void
SamiIsochroneResponsePolygon_geometry::setPType(String* pType) {
    this->pType = pType;
}

IList*
SamiIsochroneResponsePolygon_geometry::getPCoordinates() {
    return pCoordinates;
}
void
SamiIsochroneResponsePolygon_geometry::setPCoordinates(IList* pCoordinates) {
    this->pCoordinates = pCoordinates;
}



} /* namespace Swagger */

