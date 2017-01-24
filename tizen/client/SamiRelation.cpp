
#include "SamiRelation.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiRelation::SamiRelation() {
    init();
}

SamiRelation::~SamiRelation() {
    this->cleanup();
}

void
SamiRelation::init() {
    pType = null;
pIds = null;
pVehicle_id = null;
}

void
SamiRelation::cleanup() {
    if(pType != null) {
        
        delete pType;
        pType = null;
    }
if(pIds != null) {
        pIds->RemoveAll(true);
        delete pIds;
        pIds = null;
    }
if(pVehicle_id != null) {
        
        delete pVehicle_id;
        pVehicle_id = null;
    }
}


SamiRelation*
SamiRelation::fromJson(String* json) {
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
SamiRelation::fromJsonObject(IJsonValue* pJson) {
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
JsonString* pIdsKey = new JsonString(L"ids");
        IJsonValue* pIdsVal = null;
        pJsonObject->GetValue(pIdsKey, pIdsVal);
        if(pIdsVal != null) {
            pIds = new ArrayList();
            
            jsonToValue(pIds, pIdsVal, L"IList", L"String");
        }
        delete pIdsKey;
JsonString* pVehicle_idKey = new JsonString(L"vehicle_id");
        IJsonValue* pVehicle_idVal = null;
        pJsonObject->GetValue(pVehicle_idKey, pVehicle_idVal);
        if(pVehicle_idVal != null) {
            
            pVehicle_id = new String();
            jsonToValue(pVehicle_id, pVehicle_idVal, L"String", L"String");
        }
        delete pVehicle_idKey;
    }
}

SamiRelation::SamiRelation(String* json) {
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
SamiRelation::asJson ()
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
SamiRelation::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pTypeKey = new JsonString(L"type");
    pJsonObject->Add(pTypeKey, toJson(getPType(), "String", ""));

    JsonString *pIdsKey = new JsonString(L"ids");
    pJsonObject->Add(pIdsKey, toJson(getPIds(), "String", "array"));

    JsonString *pVehicle_idKey = new JsonString(L"vehicle_id");
    pJsonObject->Add(pVehicle_idKey, toJson(getPVehicleId(), "String", ""));

    return pJsonObject;
}

String*
SamiRelation::getPType() {
    return pType;
}
void
SamiRelation::setPType(String* pType) {
    this->pType = pType;
}

IList*
SamiRelation::getPIds() {
    return pIds;
}
void
SamiRelation::setPIds(IList* pIds) {
    this->pIds = pIds;
}

String*
SamiRelation::getPVehicleId() {
    return pVehicle_id;
}
void
SamiRelation::setPVehicleId(String* pVehicle_id) {
    this->pVehicle_id = pVehicle_id;
}



} /* namespace Swagger */

