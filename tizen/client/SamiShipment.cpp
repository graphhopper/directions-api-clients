
#include "SamiShipment.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiShipment::SamiShipment() {
    init();
}

SamiShipment::~SamiShipment() {
    this->cleanup();
}

void
SamiShipment::init() {
    pId = null;
pName = null;
pPriority = null;
pPickup = null;
pDelivery = null;
pSize = null;
pRequired_skills = null;
pAllowed_vehicles = null;
}

void
SamiShipment::cleanup() {
    if(pId != null) {
        
        delete pId;
        pId = null;
    }
if(pName != null) {
        
        delete pName;
        pName = null;
    }
if(pPriority != null) {
        
        delete pPriority;
        pPriority = null;
    }
if(pPickup != null) {
        
        delete pPickup;
        pPickup = null;
    }
if(pDelivery != null) {
        
        delete pDelivery;
        pDelivery = null;
    }
if(pSize != null) {
        pSize->RemoveAll(true);
        delete pSize;
        pSize = null;
    }
if(pRequired_skills != null) {
        pRequired_skills->RemoveAll(true);
        delete pRequired_skills;
        pRequired_skills = null;
    }
if(pAllowed_vehicles != null) {
        pAllowed_vehicles->RemoveAll(true);
        delete pAllowed_vehicles;
        pAllowed_vehicles = null;
    }
}


SamiShipment*
SamiShipment::fromJson(String* json) {
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
SamiShipment::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pIdKey = new JsonString(L"id");
        IJsonValue* pIdVal = null;
        pJsonObject->GetValue(pIdKey, pIdVal);
        if(pIdVal != null) {
            
            pId = new String();
            jsonToValue(pId, pIdVal, L"String", L"String");
        }
        delete pIdKey;
JsonString* pNameKey = new JsonString(L"name");
        IJsonValue* pNameVal = null;
        pJsonObject->GetValue(pNameKey, pNameVal);
        if(pNameVal != null) {
            
            pName = new String();
            jsonToValue(pName, pNameVal, L"String", L"String");
        }
        delete pNameKey;
JsonString* pPriorityKey = new JsonString(L"priority");
        IJsonValue* pPriorityVal = null;
        pJsonObject->GetValue(pPriorityKey, pPriorityVal);
        if(pPriorityVal != null) {
            
            pPriority = new Integer();
            jsonToValue(pPriority, pPriorityVal, L"Integer", L"Integer");
        }
        delete pPriorityKey;
JsonString* pPickupKey = new JsonString(L"pickup");
        IJsonValue* pPickupVal = null;
        pJsonObject->GetValue(pPickupKey, pPickupVal);
        if(pPickupVal != null) {
            
            pPickup = new SamiStop();
            jsonToValue(pPickup, pPickupVal, L"SamiStop", L"SamiStop");
        }
        delete pPickupKey;
JsonString* pDeliveryKey = new JsonString(L"delivery");
        IJsonValue* pDeliveryVal = null;
        pJsonObject->GetValue(pDeliveryKey, pDeliveryVal);
        if(pDeliveryVal != null) {
            
            pDelivery = new SamiStop();
            jsonToValue(pDelivery, pDeliveryVal, L"SamiStop", L"SamiStop");
        }
        delete pDeliveryKey;
JsonString* pSizeKey = new JsonString(L"size");
        IJsonValue* pSizeVal = null;
        pJsonObject->GetValue(pSizeKey, pSizeVal);
        if(pSizeVal != null) {
            pSize = new ArrayList();
            
            jsonToValue(pSize, pSizeVal, L"IList", L"Integer");
        }
        delete pSizeKey;
JsonString* pRequired_skillsKey = new JsonString(L"required_skills");
        IJsonValue* pRequired_skillsVal = null;
        pJsonObject->GetValue(pRequired_skillsKey, pRequired_skillsVal);
        if(pRequired_skillsVal != null) {
            pRequired_skills = new ArrayList();
            
            jsonToValue(pRequired_skills, pRequired_skillsVal, L"IList", L"String");
        }
        delete pRequired_skillsKey;
JsonString* pAllowed_vehiclesKey = new JsonString(L"allowed_vehicles");
        IJsonValue* pAllowed_vehiclesVal = null;
        pJsonObject->GetValue(pAllowed_vehiclesKey, pAllowed_vehiclesVal);
        if(pAllowed_vehiclesVal != null) {
            pAllowed_vehicles = new ArrayList();
            
            jsonToValue(pAllowed_vehicles, pAllowed_vehiclesVal, L"IList", L"String");
        }
        delete pAllowed_vehiclesKey;
    }
}

SamiShipment::SamiShipment(String* json) {
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
SamiShipment::asJson ()
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
SamiShipment::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pIdKey = new JsonString(L"id");
    pJsonObject->Add(pIdKey, toJson(getPId(), "String", ""));

    JsonString *pNameKey = new JsonString(L"name");
    pJsonObject->Add(pNameKey, toJson(getPName(), "String", ""));

    JsonString *pPriorityKey = new JsonString(L"priority");
    pJsonObject->Add(pPriorityKey, toJson(getPPriority(), "Integer", ""));

    JsonString *pPickupKey = new JsonString(L"pickup");
    pJsonObject->Add(pPickupKey, toJson(getPPickup(), "SamiStop", ""));

    JsonString *pDeliveryKey = new JsonString(L"delivery");
    pJsonObject->Add(pDeliveryKey, toJson(getPDelivery(), "SamiStop", ""));

    JsonString *pSizeKey = new JsonString(L"size");
    pJsonObject->Add(pSizeKey, toJson(getPSize(), "Integer", "array"));

    JsonString *pRequired_skillsKey = new JsonString(L"required_skills");
    pJsonObject->Add(pRequired_skillsKey, toJson(getPRequiredSkills(), "String", "array"));

    JsonString *pAllowed_vehiclesKey = new JsonString(L"allowed_vehicles");
    pJsonObject->Add(pAllowed_vehiclesKey, toJson(getPAllowedVehicles(), "String", "array"));

    return pJsonObject;
}

String*
SamiShipment::getPId() {
    return pId;
}
void
SamiShipment::setPId(String* pId) {
    this->pId = pId;
}

String*
SamiShipment::getPName() {
    return pName;
}
void
SamiShipment::setPName(String* pName) {
    this->pName = pName;
}

Integer*
SamiShipment::getPPriority() {
    return pPriority;
}
void
SamiShipment::setPPriority(Integer* pPriority) {
    this->pPriority = pPriority;
}

SamiStop*
SamiShipment::getPPickup() {
    return pPickup;
}
void
SamiShipment::setPPickup(SamiStop* pPickup) {
    this->pPickup = pPickup;
}

SamiStop*
SamiShipment::getPDelivery() {
    return pDelivery;
}
void
SamiShipment::setPDelivery(SamiStop* pDelivery) {
    this->pDelivery = pDelivery;
}

IList*
SamiShipment::getPSize() {
    return pSize;
}
void
SamiShipment::setPSize(IList* pSize) {
    this->pSize = pSize;
}

IList*
SamiShipment::getPRequiredSkills() {
    return pRequired_skills;
}
void
SamiShipment::setPRequiredSkills(IList* pRequired_skills) {
    this->pRequired_skills = pRequired_skills;
}

IList*
SamiShipment::getPAllowedVehicles() {
    return pAllowed_vehicles;
}
void
SamiShipment::setPAllowedVehicles(IList* pAllowed_vehicles) {
    this->pAllowed_vehicles = pAllowed_vehicles;
}



} /* namespace Swagger */

