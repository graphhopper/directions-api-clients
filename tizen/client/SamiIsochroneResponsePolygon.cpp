
#include "SamiIsochroneResponsePolygon.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiIsochroneResponsePolygon::SamiIsochroneResponsePolygon() {
    init();
}

SamiIsochroneResponsePolygon::~SamiIsochroneResponsePolygon() {
    this->cleanup();
}

void
SamiIsochroneResponsePolygon::init() {
    pProperties = null;
pType = null;
pGeometry = null;
}

void
SamiIsochroneResponsePolygon::cleanup() {
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


SamiIsochroneResponsePolygon*
SamiIsochroneResponsePolygon::fromJson(String* json) {
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
SamiIsochroneResponsePolygon::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pPropertiesKey = new JsonString(L"properties");
        IJsonValue* pPropertiesVal = null;
        pJsonObject->GetValue(pPropertiesKey, pPropertiesVal);
        if(pPropertiesVal != null) {
            
            pProperties = new SamiIsochroneResponsePolygon_properties();
            jsonToValue(pProperties, pPropertiesVal, L"SamiIsochroneResponsePolygon_properties", L"SamiIsochroneResponsePolygon_properties");
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
            
            pGeometry = new SamiIsochroneResponsePolygon_geometry();
            jsonToValue(pGeometry, pGeometryVal, L"SamiIsochroneResponsePolygon_geometry", L"SamiIsochroneResponsePolygon_geometry");
        }
        delete pGeometryKey;
    }
}

SamiIsochroneResponsePolygon::SamiIsochroneResponsePolygon(String* json) {
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
SamiIsochroneResponsePolygon::asJson ()
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
SamiIsochroneResponsePolygon::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pPropertiesKey = new JsonString(L"properties");
    pJsonObject->Add(pPropertiesKey, toJson(getPProperties(), "SamiIsochroneResponsePolygon_properties", ""));

    JsonString *pTypeKey = new JsonString(L"type");
    pJsonObject->Add(pTypeKey, toJson(getPType(), "String", ""));

    JsonString *pGeometryKey = new JsonString(L"geometry");
    pJsonObject->Add(pGeometryKey, toJson(getPGeometry(), "SamiIsochroneResponsePolygon_geometry", ""));

    return pJsonObject;
}

SamiIsochroneResponsePolygon_properties*
SamiIsochroneResponsePolygon::getPProperties() {
    return pProperties;
}
void
SamiIsochroneResponsePolygon::setPProperties(SamiIsochroneResponsePolygon_properties* pProperties) {
    this->pProperties = pProperties;
}

String*
SamiIsochroneResponsePolygon::getPType() {
    return pType;
}
void
SamiIsochroneResponsePolygon::setPType(String* pType) {
    this->pType = pType;
}

SamiIsochroneResponsePolygon_geometry*
SamiIsochroneResponsePolygon::getPGeometry() {
    return pGeometry;
}
void
SamiIsochroneResponsePolygon::setPGeometry(SamiIsochroneResponsePolygon_geometry* pGeometry) {
    this->pGeometry = pGeometry;
}



} /* namespace Swagger */

