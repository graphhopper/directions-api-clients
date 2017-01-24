
#include "SamiService.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiService::SamiService() {
    init();
}

SamiService::~SamiService() {
    this->cleanup();
}

void
SamiService::init() {
    pId = null;
pType = null;
pPriority = null;
pName = null;
pAddress = null;
pDuration = null;
pTime_windows = null;
pSize = null;
pRequired_skills = null;
pAllowed_vehicles = null;
}

void
SamiService::cleanup() {
    if(pId != null) {
        
        delete pId;
        pId = null;
    }
if(pType != null) {
        
        delete pType;
        pType = null;
    }
if(pPriority != null) {
        
        delete pPriority;
        pPriority = null;
    }
if(pName != null) {
        
        delete pName;
        pName = null;
    }
if(pAddress != null) {
        
        delete pAddress;
        pAddress = null;
    }
if(pDuration != null) {
        
        delete pDuration;
        pDuration = null;
    }
if(pTime_windows != null) {
        pTime_windows->RemoveAll(true);
        delete pTime_windows;
        pTime_windows = null;
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


SamiService*
SamiService::fromJson(String* json) {
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
SamiService::fromJsonObject(IJsonValue* pJson) {
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
JsonString* pTypeKey = new JsonString(L"type");
        IJsonValue* pTypeVal = null;
        pJsonObject->GetValue(pTypeKey, pTypeVal);
        if(pTypeVal != null) {
            
            pType = new String();
            jsonToValue(pType, pTypeVal, L"String", L"String");
        }
        delete pTypeKey;
JsonString* pPriorityKey = new JsonString(L"priority");
        IJsonValue* pPriorityVal = null;
        pJsonObject->GetValue(pPriorityKey, pPriorityVal);
        if(pPriorityVal != null) {
            
            pPriority = new Integer();
            jsonToValue(pPriority, pPriorityVal, L"Integer", L"Integer");
        }
        delete pPriorityKey;
JsonString* pNameKey = new JsonString(L"name");
        IJsonValue* pNameVal = null;
        pJsonObject->GetValue(pNameKey, pNameVal);
        if(pNameVal != null) {
            
            pName = new String();
            jsonToValue(pName, pNameVal, L"String", L"String");
        }
        delete pNameKey;
JsonString* pAddressKey = new JsonString(L"address");
        IJsonValue* pAddressVal = null;
        pJsonObject->GetValue(pAddressKey, pAddressVal);
        if(pAddressVal != null) {
            
            pAddress = new SamiAddress();
            jsonToValue(pAddress, pAddressVal, L"SamiAddress", L"SamiAddress");
        }
        delete pAddressKey;
JsonString* pDurationKey = new JsonString(L"duration");
        IJsonValue* pDurationVal = null;
        pJsonObject->GetValue(pDurationKey, pDurationVal);
        if(pDurationVal != null) {
            
            pDuration = new Long();
            jsonToValue(pDuration, pDurationVal, L"Long", L"Long");
        }
        delete pDurationKey;
JsonString* pTime_windowsKey = new JsonString(L"time_windows");
        IJsonValue* pTime_windowsVal = null;
        pJsonObject->GetValue(pTime_windowsKey, pTime_windowsVal);
        if(pTime_windowsVal != null) {
            pTime_windows = new ArrayList();
            
            jsonToValue(pTime_windows, pTime_windowsVal, L"IList", L"SamiTimeWindow");
        }
        delete pTime_windowsKey;
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

SamiService::SamiService(String* json) {
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
SamiService::asJson ()
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
SamiService::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pIdKey = new JsonString(L"id");
    pJsonObject->Add(pIdKey, toJson(getPId(), "String", ""));

    JsonString *pTypeKey = new JsonString(L"type");
    pJsonObject->Add(pTypeKey, toJson(getPType(), "String", ""));

    JsonString *pPriorityKey = new JsonString(L"priority");
    pJsonObject->Add(pPriorityKey, toJson(getPPriority(), "Integer", ""));

    JsonString *pNameKey = new JsonString(L"name");
    pJsonObject->Add(pNameKey, toJson(getPName(), "String", ""));

    JsonString *pAddressKey = new JsonString(L"address");
    pJsonObject->Add(pAddressKey, toJson(getPAddress(), "SamiAddress", ""));

    JsonString *pDurationKey = new JsonString(L"duration");
    pJsonObject->Add(pDurationKey, toJson(getPDuration(), "Long", ""));

    JsonString *pTime_windowsKey = new JsonString(L"time_windows");
    pJsonObject->Add(pTime_windowsKey, toJson(getPTimeWindows(), "SamiTimeWindow", "array"));

    JsonString *pSizeKey = new JsonString(L"size");
    pJsonObject->Add(pSizeKey, toJson(getPSize(), "Integer", "array"));

    JsonString *pRequired_skillsKey = new JsonString(L"required_skills");
    pJsonObject->Add(pRequired_skillsKey, toJson(getPRequiredSkills(), "String", "array"));

    JsonString *pAllowed_vehiclesKey = new JsonString(L"allowed_vehicles");
    pJsonObject->Add(pAllowed_vehiclesKey, toJson(getPAllowedVehicles(), "String", "array"));

    return pJsonObject;
}

String*
SamiService::getPId() {
    return pId;
}
void
SamiService::setPId(String* pId) {
    this->pId = pId;
}

String*
SamiService::getPType() {
    return pType;
}
void
SamiService::setPType(String* pType) {
    this->pType = pType;
}

Integer*
SamiService::getPPriority() {
    return pPriority;
}
void
SamiService::setPPriority(Integer* pPriority) {
    this->pPriority = pPriority;
}

String*
SamiService::getPName() {
    return pName;
}
void
SamiService::setPName(String* pName) {
    this->pName = pName;
}

SamiAddress*
SamiService::getPAddress() {
    return pAddress;
}
void
SamiService::setPAddress(SamiAddress* pAddress) {
    this->pAddress = pAddress;
}

Long*
SamiService::getPDuration() {
    return pDuration;
}
void
SamiService::setPDuration(Long* pDuration) {
    this->pDuration = pDuration;
}

IList*
SamiService::getPTimeWindows() {
    return pTime_windows;
}
void
SamiService::setPTimeWindows(IList* pTime_windows) {
    this->pTime_windows = pTime_windows;
}

IList*
SamiService::getPSize() {
    return pSize;
}
void
SamiService::setPSize(IList* pSize) {
    this->pSize = pSize;
}

IList*
SamiService::getPRequiredSkills() {
    return pRequired_skills;
}
void
SamiService::setPRequiredSkills(IList* pRequired_skills) {
    this->pRequired_skills = pRequired_skills;
}

IList*
SamiService::getPAllowedVehicles() {
    return pAllowed_vehicles;
}
void
SamiService::setPAllowedVehicles(IList* pAllowed_vehicles) {
    this->pAllowed_vehicles = pAllowed_vehicles;
}



} /* namespace Swagger */

