
#include "SamiIsochroneResponsePolygon_properties.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiIsochroneResponsePolygon_properties::SamiIsochroneResponsePolygon_properties() {
    init();
}

SamiIsochroneResponsePolygon_properties::~SamiIsochroneResponsePolygon_properties() {
    this->cleanup();
}

void
SamiIsochroneResponsePolygon_properties::init() {
    pBucket = null;
}

void
SamiIsochroneResponsePolygon_properties::cleanup() {
    if(pBucket != null) {
        
        delete pBucket;
        pBucket = null;
    }
}


SamiIsochroneResponsePolygon_properties*
SamiIsochroneResponsePolygon_properties::fromJson(String* json) {
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
SamiIsochroneResponsePolygon_properties::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pBucketKey = new JsonString(L"bucket");
        IJsonValue* pBucketVal = null;
        pJsonObject->GetValue(pBucketKey, pBucketVal);
        if(pBucketVal != null) {
            
            pBucket = new Integer();
            jsonToValue(pBucket, pBucketVal, L"Integer", L"Integer");
        }
        delete pBucketKey;
    }
}

SamiIsochroneResponsePolygon_properties::SamiIsochroneResponsePolygon_properties(String* json) {
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
SamiIsochroneResponsePolygon_properties::asJson ()
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
SamiIsochroneResponsePolygon_properties::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pBucketKey = new JsonString(L"bucket");
    pJsonObject->Add(pBucketKey, toJson(getPBucket(), "Integer", ""));

    return pJsonObject;
}

Integer*
SamiIsochroneResponsePolygon_properties::getPBucket() {
    return pBucket;
}
void
SamiIsochroneResponsePolygon_properties::setPBucket(Integer* pBucket) {
    this->pBucket = pBucket;
}



} /* namespace Swagger */

