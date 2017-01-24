
#include "SamiGHIsochroneResponsePolygon.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGHIsochroneResponsePolygon::SamiGHIsochroneResponsePolygon() {
    init();
}

SamiGHIsochroneResponsePolygon::~SamiGHIsochroneResponsePolygon() {
    this->cleanup();
}

void
SamiGHIsochroneResponsePolygon::init() {
    pProperties = null;
pType = null;
pGeometry = null;
}

void
SamiGHIsochroneResponsePolygon::cleanup() {
    if(pProperties != null) {
        
        delete pProperties;
        pProperties = null;
    }
if(pType != null) {
        
        delete pType;
        pType = null;
    }
if(pGeometry != null) {
        
        delete pGeometry;
        pGeometry = null;
    }
}


SamiGHIsochroneResponsePolygon*
SamiGHIsochroneResponsePolygon::fromJson(String* json) {
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
SamiGHIsochroneResponsePolygon::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pPropertiesKey = new JsonString(L"properties");
        IJsonValue* pPropertiesVal = null;
        pJsonObject->GetValue(pPropertiesKey, pPropertiesVal);
        if(pPropertiesVal != null) {
            
            pProperties = new SamiGHIsochroneResponsePolygon_properties();
            jsonToValue(pProperties, pPropertiesVal, L"SamiGHIsochroneResponsePolygon_properties", L"SamiGHIsochroneResponsePolygon_properties");
        }
        delete pPropertiesKey;
JsonString* pTypeKey = new JsonString(L"type");
        IJsonValue* pTypeVal = null;
        pJsonObject->GetValue(pTypeKey, pTypeVal);
        if(pTypeVal != null) {
            
            pType = new String();
            jsonToValue(pType, pTypeVal, L"String", L"String");
        }
        delete pTypeKey;
JsonString* pGeometryKey = new JsonString(L"geometry");
        IJsonValue* pGeometryVal = null;
        pJsonObject->GetValue(pGeometryKey, pGeometryVal);
        if(pGeometryVal != null) {
            
            pGeometry = new SamiGHIsochroneResponsePolygon_geometry();
            jsonToValue(pGeometry, pGeometryVal, L"SamiGHIsochroneResponsePolygon_geometry", L"SamiGHIsochroneResponsePolygon_geometry");
        }
        delete pGeometryKey;
    }
}

SamiGHIsochroneResponsePolygon::SamiGHIsochroneResponsePolygon(String* json) {
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
SamiGHIsochroneResponsePolygon::asJson ()
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
SamiGHIsochroneResponsePolygon::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pPropertiesKey = new JsonString(L"properties");
    pJsonObject->Add(pPropertiesKey, toJson(getPProperties(), "SamiGHIsochroneResponsePolygon_properties", ""));

    JsonString *pTypeKey = new JsonString(L"type");
    pJsonObject->Add(pTypeKey, toJson(getPType(), "String", ""));

    JsonString *pGeometryKey = new JsonString(L"geometry");
    pJsonObject->Add(pGeometryKey, toJson(getPGeometry(), "SamiGHIsochroneResponsePolygon_geometry", ""));

    return pJsonObject;
}

SamiGHIsochroneResponsePolygon_properties*
SamiGHIsochroneResponsePolygon::getPProperties() {
    return pProperties;
}
void
SamiGHIsochroneResponsePolygon::setPProperties(SamiGHIsochroneResponsePolygon_properties* pProperties) {
    this->pProperties = pProperties;
}

String*
SamiGHIsochroneResponsePolygon::getPType() {
    return pType;
}
void
SamiGHIsochroneResponsePolygon::setPType(String* pType) {
    this->pType = pType;
}

SamiGHIsochroneResponsePolygon_geometry*
SamiGHIsochroneResponsePolygon::getPGeometry() {
    return pGeometry;
}
void
SamiGHIsochroneResponsePolygon::setPGeometry(SamiGHIsochroneResponsePolygon_geometry* pGeometry) {
    this->pGeometry = pGeometry;
}



} /* namespace Swagger */

