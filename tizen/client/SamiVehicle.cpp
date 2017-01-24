
#include "SamiVehicle.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiVehicle::SamiVehicle() {
    init();
}

SamiVehicle::~SamiVehicle() {
    this->cleanup();
}

void
SamiVehicle::init() {
    pVehicle_id = null;
pType_id = null;
pStart_address = null;
pEnd_address = null;
pBreak = null;
pReturn_to_depot = null;
pEarliest_start = null;
pLatest_end = null;
pSkills = null;
}

void
SamiVehicle::cleanup() {
    if(pVehicle_id != null) {
        
        delete pVehicle_id;
        pVehicle_id = null;
    }
if(pType_id != null) {
        
        delete pType_id;
        pType_id = null;
    }
if(pStart_address != null) {
        
        delete pStart_address;
        pStart_address = null;
    }
if(pEnd_address != null) {
        
        delete pEnd_address;
        pEnd_address = null;
    }
if(pBreak != null) {
        
        delete pBreak;
        pBreak = null;
    }
if(pReturn_to_depot != null) {
        
        delete pReturn_to_depot;
        pReturn_to_depot = null;
    }
if(pEarliest_start != null) {
        
        delete pEarliest_start;
        pEarliest_start = null;
    }
if(pLatest_end != null) {
        
        delete pLatest_end;
        pLatest_end = null;
    }
if(pSkills != null) {
        pSkills->RemoveAll(true);
        delete pSkills;
        pSkills = null;
    }
}


SamiVehicle*
SamiVehicle::fromJson(String* json) {
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
SamiVehicle::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pVehicle_idKey = new JsonString(L"vehicle_id");
        IJsonValue* pVehicle_idVal = null;
        pJsonObject->GetValue(pVehicle_idKey, pVehicle_idVal);
        if(pVehicle_idVal != null) {
            
            pVehicle_id = new String();
            jsonToValue(pVehicle_id, pVehicle_idVal, L"String", L"String");
        }
        delete pVehicle_idKey;
JsonString* pType_idKey = new JsonString(L"type_id");
        IJsonValue* pType_idVal = null;
        pJsonObject->GetValue(pType_idKey, pType_idVal);
        if(pType_idVal != null) {
            
            pType_id = new String();
            jsonToValue(pType_id, pType_idVal, L"String", L"String");
        }
        delete pType_idKey;
JsonString* pStart_addressKey = new JsonString(L"start_address");
        IJsonValue* pStart_addressVal = null;
        pJsonObject->GetValue(pStart_addressKey, pStart_addressVal);
        if(pStart_addressVal != null) {
            
            pStart_address = new SamiAddress();
            jsonToValue(pStart_address, pStart_addressVal, L"SamiAddress", L"SamiAddress");
        }
        delete pStart_addressKey;
JsonString* pEnd_addressKey = new JsonString(L"end_address");
        IJsonValue* pEnd_addressVal = null;
        pJsonObject->GetValue(pEnd_addressKey, pEnd_addressVal);
        if(pEnd_addressVal != null) {
            
            pEnd_address = new SamiAddress();
            jsonToValue(pEnd_address, pEnd_addressVal, L"SamiAddress", L"SamiAddress");
        }
        delete pEnd_addressKey;
JsonString* pBreakKey = new JsonString(L"break");
        IJsonValue* pBreakVal = null;
        pJsonObject->GetValue(pBreakKey, pBreakVal);
        if(pBreakVal != null) {
            
            pBreak = new SamiBreak();
            jsonToValue(pBreak, pBreakVal, L"SamiBreak", L"SamiBreak");
        }
        delete pBreakKey;
JsonString* pReturn_to_depotKey = new JsonString(L"return_to_depot");
        IJsonValue* pReturn_to_depotVal = null;
        pJsonObject->GetValue(pReturn_to_depotKey, pReturn_to_depotVal);
        if(pReturn_to_depotVal != null) {
            
            pReturn_to_depot = new Boolean(false);
            jsonToValue(pReturn_to_depot, pReturn_to_depotVal, L"Boolean", L"Boolean");
        }
        delete pReturn_to_depotKey;
JsonString* pEarliest_startKey = new JsonString(L"earliest_start");
        IJsonValue* pEarliest_startVal = null;
        pJsonObject->GetValue(pEarliest_startKey, pEarliest_startVal);
        if(pEarliest_startVal != null) {
            
            pEarliest_start = new Long();
            jsonToValue(pEarliest_start, pEarliest_startVal, L"Long", L"Long");
        }
        delete pEarliest_startKey;
JsonString* pLatest_endKey = new JsonString(L"latest_end");
        IJsonValue* pLatest_endVal = null;
        pJsonObject->GetValue(pLatest_endKey, pLatest_endVal);
        if(pLatest_endVal != null) {
            
            pLatest_end = new Long();
            jsonToValue(pLatest_end, pLatest_endVal, L"Long", L"Long");
        }
        delete pLatest_endKey;
JsonString* pSkillsKey = new JsonString(L"skills");
        IJsonValue* pSkillsVal = null;
        pJsonObject->GetValue(pSkillsKey, pSkillsVal);
        if(pSkillsVal != null) {
            pSkills = new ArrayList();
            
            jsonToValue(pSkills, pSkillsVal, L"IList", L"String");
        }
        delete pSkillsKey;
    }
}

SamiVehicle::SamiVehicle(String* json) {
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
SamiVehicle::asJson ()
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
SamiVehicle::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pVehicle_idKey = new JsonString(L"vehicle_id");
    pJsonObject->Add(pVehicle_idKey, toJson(getPVehicleId(), "String", ""));

    JsonString *pType_idKey = new JsonString(L"type_id");
    pJsonObject->Add(pType_idKey, toJson(getPTypeId(), "String", ""));

    JsonString *pStart_addressKey = new JsonString(L"start_address");
    pJsonObject->Add(pStart_addressKey, toJson(getPStartAddress(), "SamiAddress", ""));

    JsonString *pEnd_addressKey = new JsonString(L"end_address");
    pJsonObject->Add(pEnd_addressKey, toJson(getPEndAddress(), "SamiAddress", ""));

    JsonString *pBreakKey = new JsonString(L"break");
    pJsonObject->Add(pBreakKey, toJson(getPBreak(), "SamiBreak", ""));

    JsonString *pReturn_to_depotKey = new JsonString(L"return_to_depot");
    pJsonObject->Add(pReturn_to_depotKey, toJson(getPReturnToDepot(), "Boolean", ""));

    JsonString *pEarliest_startKey = new JsonString(L"earliest_start");
    pJsonObject->Add(pEarliest_startKey, toJson(getPEarliestStart(), "Long", ""));

    JsonString *pLatest_endKey = new JsonString(L"latest_end");
    pJsonObject->Add(pLatest_endKey, toJson(getPLatestEnd(), "Long", ""));

    JsonString *pSkillsKey = new JsonString(L"skills");
    pJsonObject->Add(pSkillsKey, toJson(getPSkills(), "String", "array"));

    return pJsonObject;
}

String*
SamiVehicle::getPVehicleId() {
    return pVehicle_id;
}
void
SamiVehicle::setPVehicleId(String* pVehicle_id) {
    this->pVehicle_id = pVehicle_id;
}

String*
SamiVehicle::getPTypeId() {
    return pType_id;
}
void
SamiVehicle::setPTypeId(String* pType_id) {
    this->pType_id = pType_id;
}

SamiAddress*
SamiVehicle::getPStartAddress() {
    return pStart_address;
}
void
SamiVehicle::setPStartAddress(SamiAddress* pStart_address) {
    this->pStart_address = pStart_address;
}

SamiAddress*
SamiVehicle::getPEndAddress() {
    return pEnd_address;
}
void
SamiVehicle::setPEndAddress(SamiAddress* pEnd_address) {
    this->pEnd_address = pEnd_address;
}

SamiBreak*
SamiVehicle::getPBreak() {
    return pBreak;
}
void
SamiVehicle::setPBreak(SamiBreak* pBreak) {
    this->pBreak = pBreak;
}

Boolean*
SamiVehicle::getPReturnToDepot() {
    return pReturn_to_depot;
}
void
SamiVehicle::setPReturnToDepot(Boolean* pReturn_to_depot) {
    this->pReturn_to_depot = pReturn_to_depot;
}

Long*
SamiVehicle::getPEarliestStart() {
    return pEarliest_start;
}
void
SamiVehicle::setPEarliestStart(Long* pEarliest_start) {
    this->pEarliest_start = pEarliest_start;
}

Long*
SamiVehicle::getPLatestEnd() {
    return pLatest_end;
}
void
SamiVehicle::setPLatestEnd(Long* pLatest_end) {
    this->pLatest_end = pLatest_end;
}

IList*
SamiVehicle::getPSkills() {
    return pSkills;
}
void
SamiVehicle::setPSkills(IList* pSkills) {
    this->pSkills = pSkills;
}



} /* namespace Swagger */

