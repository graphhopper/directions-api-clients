
#include "SamiBreak.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiBreak::SamiBreak() {
    init();
}

SamiBreak::~SamiBreak() {
    this->cleanup();
}

void
SamiBreak::init() {
    pEarliest = null;
pLatest = null;
pDuration = null;
pMax_driving_time = null;
pInitial_driving_time = null;
pPossible_split = null;
}

void
SamiBreak::cleanup() {
    if(pEarliest != null) {
        
        delete pEarliest;
        pEarliest = null;
    }
if(pLatest != null) {
        
        delete pLatest;
        pLatest = null;
    }
if(pDuration != null) {
        
        delete pDuration;
        pDuration = null;
    }
if(pMax_driving_time != null) {
        
        delete pMax_driving_time;
        pMax_driving_time = null;
    }
if(pInitial_driving_time != null) {
        
        delete pInitial_driving_time;
        pInitial_driving_time = null;
    }
if(pPossible_split != null) {
        pPossible_split->RemoveAll(true);
        delete pPossible_split;
        pPossible_split = null;
    }
}


SamiBreak*
SamiBreak::fromJson(String* json) {
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
SamiBreak::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pEarliestKey = new JsonString(L"earliest");
        IJsonValue* pEarliestVal = null;
        pJsonObject->GetValue(pEarliestKey, pEarliestVal);
        if(pEarliestVal != null) {
            
            pEarliest = new Long();
            jsonToValue(pEarliest, pEarliestVal, L"Long", L"Long");
        }
        delete pEarliestKey;
JsonString* pLatestKey = new JsonString(L"latest");
        IJsonValue* pLatestVal = null;
        pJsonObject->GetValue(pLatestKey, pLatestVal);
        if(pLatestVal != null) {
            
            pLatest = new Long();
            jsonToValue(pLatest, pLatestVal, L"Long", L"Long");
        }
        delete pLatestKey;
JsonString* pDurationKey = new JsonString(L"duration");
        IJsonValue* pDurationVal = null;
        pJsonObject->GetValue(pDurationKey, pDurationVal);
        if(pDurationVal != null) {
            
            pDuration = new Long();
            jsonToValue(pDuration, pDurationVal, L"Long", L"Long");
        }
        delete pDurationKey;
JsonString* pMax_driving_timeKey = new JsonString(L"max_driving_time");
        IJsonValue* pMax_driving_timeVal = null;
        pJsonObject->GetValue(pMax_driving_timeKey, pMax_driving_timeVal);
        if(pMax_driving_timeVal != null) {
            
            pMax_driving_time = new Long();
            jsonToValue(pMax_driving_time, pMax_driving_timeVal, L"Long", L"Long");
        }
        delete pMax_driving_timeKey;
JsonString* pInitial_driving_timeKey = new JsonString(L"initial_driving_time");
        IJsonValue* pInitial_driving_timeVal = null;
        pJsonObject->GetValue(pInitial_driving_timeKey, pInitial_driving_timeVal);
        if(pInitial_driving_timeVal != null) {
            
            pInitial_driving_time = new Long();
            jsonToValue(pInitial_driving_time, pInitial_driving_timeVal, L"Long", L"Long");
        }
        delete pInitial_driving_timeKey;
JsonString* pPossible_splitKey = new JsonString(L"possible_split");
        IJsonValue* pPossible_splitVal = null;
        pJsonObject->GetValue(pPossible_splitKey, pPossible_splitVal);
        if(pPossible_splitVal != null) {
            pPossible_split = new ArrayList();
            
            jsonToValue(pPossible_split, pPossible_splitVal, L"IList", L"Long");
        }
        delete pPossible_splitKey;
    }
}

SamiBreak::SamiBreak(String* json) {
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
SamiBreak::asJson ()
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
SamiBreak::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pEarliestKey = new JsonString(L"earliest");
    pJsonObject->Add(pEarliestKey, toJson(getPEarliest(), "Long", ""));

    JsonString *pLatestKey = new JsonString(L"latest");
    pJsonObject->Add(pLatestKey, toJson(getPLatest(), "Long", ""));

    JsonString *pDurationKey = new JsonString(L"duration");
    pJsonObject->Add(pDurationKey, toJson(getPDuration(), "Long", ""));

    JsonString *pMax_driving_timeKey = new JsonString(L"max_driving_time");
    pJsonObject->Add(pMax_driving_timeKey, toJson(getPMaxDrivingTime(), "Long", ""));

    JsonString *pInitial_driving_timeKey = new JsonString(L"initial_driving_time");
    pJsonObject->Add(pInitial_driving_timeKey, toJson(getPInitialDrivingTime(), "Long", ""));

    JsonString *pPossible_splitKey = new JsonString(L"possible_split");
    pJsonObject->Add(pPossible_splitKey, toJson(getPPossibleSplit(), "Long", "array"));

    return pJsonObject;
}

Long*
SamiBreak::getPEarliest() {
    return pEarliest;
}
void
SamiBreak::setPEarliest(Long* pEarliest) {
    this->pEarliest = pEarliest;
}

Long*
SamiBreak::getPLatest() {
    return pLatest;
}
void
SamiBreak::setPLatest(Long* pLatest) {
    this->pLatest = pLatest;
}

Long*
SamiBreak::getPDuration() {
    return pDuration;
}
void
SamiBreak::setPDuration(Long* pDuration) {
    this->pDuration = pDuration;
}

Long*
SamiBreak::getPMaxDrivingTime() {
    return pMax_driving_time;
}
void
SamiBreak::setPMaxDrivingTime(Long* pMax_driving_time) {
    this->pMax_driving_time = pMax_driving_time;
}

Long*
SamiBreak::getPInitialDrivingTime() {
    return pInitial_driving_time;
}
void
SamiBreak::setPInitialDrivingTime(Long* pInitial_driving_time) {
    this->pInitial_driving_time = pInitial_driving_time;
}

IList*
SamiBreak::getPPossibleSplit() {
    return pPossible_split;
}
void
SamiBreak::setPPossibleSplit(IList* pPossible_split) {
    this->pPossible_split = pPossible_split;
}



} /* namespace Swagger */

