
#include "SamiVehicleType.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiVehicleType::SamiVehicleType() {
    init();
}

SamiVehicleType::~SamiVehicleType() {
    this->cleanup();
}

void
SamiVehicleType::init() {
    pType_id = null;
pProfile = null;
pCapacity = null;
pSpeed_factor = null;
pService_time_factor = null;
}

void
SamiVehicleType::cleanup() {
    if(pType_id != null) {
        
        delete pType_id;
        pType_id = null;
    }
if(pProfile != null) {
        
        delete pProfile;
        pProfile = null;
    }
if(pCapacity != null) {
        pCapacity->RemoveAll(true);
        delete pCapacity;
        pCapacity = null;
    }
if(pSpeed_factor != null) {
        
        delete pSpeed_factor;
        pSpeed_factor = null;
    }
if(pService_time_factor != null) {
        
        delete pService_time_factor;
        pService_time_factor = null;
    }
}


SamiVehicleType*
SamiVehicleType::fromJson(String* json) {
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
SamiVehicleType::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pType_idKey = new JsonString(L"type_id");
        IJsonValue* pType_idVal = null;
        pJsonObject->GetValue(pType_idKey, pType_idVal);
        if(pType_idVal != null) {
            
            pType_id = new String();
            jsonToValue(pType_id, pType_idVal, L"String", L"String");
        }
        delete pType_idKey;
JsonString* pProfileKey = new JsonString(L"profile");
        IJsonValue* pProfileVal = null;
        pJsonObject->GetValue(pProfileKey, pProfileVal);
        if(pProfileVal != null) {
            
            pProfile = new String();
            jsonToValue(pProfile, pProfileVal, L"String", L"String");
        }
        delete pProfileKey;
JsonString* pCapacityKey = new JsonString(L"capacity");
        IJsonValue* pCapacityVal = null;
        pJsonObject->GetValue(pCapacityKey, pCapacityVal);
        if(pCapacityVal != null) {
            pCapacity = new ArrayList();
            
            jsonToValue(pCapacity, pCapacityVal, L"IList", L"Integer");
        }
        delete pCapacityKey;
JsonString* pSpeed_factorKey = new JsonString(L"speed_factor");
        IJsonValue* pSpeed_factorVal = null;
        pJsonObject->GetValue(pSpeed_factorKey, pSpeed_factorVal);
        if(pSpeed_factorVal != null) {
            
            pSpeed_factor = new Double();
            jsonToValue(pSpeed_factor, pSpeed_factorVal, L"Double", L"Double");
        }
        delete pSpeed_factorKey;
JsonString* pService_time_factorKey = new JsonString(L"service_time_factor");
        IJsonValue* pService_time_factorVal = null;
        pJsonObject->GetValue(pService_time_factorKey, pService_time_factorVal);
        if(pService_time_factorVal != null) {
            
            pService_time_factor = new Double();
            jsonToValue(pService_time_factor, pService_time_factorVal, L"Double", L"Double");
        }
        delete pService_time_factorKey;
    }
}

SamiVehicleType::SamiVehicleType(String* json) {
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
SamiVehicleType::asJson ()
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
SamiVehicleType::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pType_idKey = new JsonString(L"type_id");
    pJsonObject->Add(pType_idKey, toJson(getPTypeId(), "String", ""));

    JsonString *pProfileKey = new JsonString(L"profile");
    pJsonObject->Add(pProfileKey, toJson(getPProfile(), "String", ""));

    JsonString *pCapacityKey = new JsonString(L"capacity");
    pJsonObject->Add(pCapacityKey, toJson(getPCapacity(), "Integer", "array"));

    JsonString *pSpeed_factorKey = new JsonString(L"speed_factor");
    pJsonObject->Add(pSpeed_factorKey, toJson(getPSpeedFactor(), "Double", ""));

    JsonString *pService_time_factorKey = new JsonString(L"service_time_factor");
    pJsonObject->Add(pService_time_factorKey, toJson(getPServiceTimeFactor(), "Double", ""));

    return pJsonObject;
}

String*
SamiVehicleType::getPTypeId() {
    return pType_id;
}
void
SamiVehicleType::setPTypeId(String* pType_id) {
    this->pType_id = pType_id;
}

String*
SamiVehicleType::getPProfile() {
    return pProfile;
}
void
SamiVehicleType::setPProfile(String* pProfile) {
    this->pProfile = pProfile;
}

IList*
SamiVehicleType::getPCapacity() {
    return pCapacity;
}
void
SamiVehicleType::setPCapacity(IList* pCapacity) {
    this->pCapacity = pCapacity;
}

Double*
SamiVehicleType::getPSpeedFactor() {
    return pSpeed_factor;
}
void
SamiVehicleType::setPSpeedFactor(Double* pSpeed_factor) {
    this->pSpeed_factor = pSpeed_factor;
}

Double*
SamiVehicleType::getPServiceTimeFactor() {
    return pService_time_factor;
}
void
SamiVehicleType::setPServiceTimeFactor(Double* pService_time_factor) {
    this->pService_time_factor = pService_time_factor;
}



} /* namespace Swagger */

