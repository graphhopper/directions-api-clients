
#include "SamiActivity.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiActivity::SamiActivity() {
    init();
}

SamiActivity::~SamiActivity() {
    this->cleanup();
}

void
SamiActivity::init() {
    pType = null;
pId = null;
pLocation_id = null;
pArr_time = null;
pEnd_time = null;
pWaiting_time = null;
pDistance = null;
pDriving_time = null;
pLoad_before = null;
pLoad_after = null;
}

void
SamiActivity::cleanup() {
    if(pType != null) {
        
        delete pType;
        pType = null;
    }
if(pId != null) {
        
        delete pId;
        pId = null;
    }
if(pLocation_id != null) {
        
        delete pLocation_id;
        pLocation_id = null;
    }
if(pArr_time != null) {
        
        delete pArr_time;
        pArr_time = null;
    }
if(pEnd_time != null) {
        
        delete pEnd_time;
        pEnd_time = null;
    }
if(pWaiting_time != null) {
        
        delete pWaiting_time;
        pWaiting_time = null;
    }
if(pDistance != null) {
        
        delete pDistance;
        pDistance = null;
    }
if(pDriving_time != null) {
        
        delete pDriving_time;
        pDriving_time = null;
    }
if(pLoad_before != null) {
        pLoad_before->RemoveAll(true);
        delete pLoad_before;
        pLoad_before = null;
    }
if(pLoad_after != null) {
        pLoad_after->RemoveAll(true);
        delete pLoad_after;
        pLoad_after = null;
    }
}


SamiActivity*
SamiActivity::fromJson(String* json) {
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
SamiActivity::fromJsonObject(IJsonValue* pJson) {
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
JsonString* pIdKey = new JsonString(L"id");
        IJsonValue* pIdVal = null;
        pJsonObject->GetValue(pIdKey, pIdVal);
        if(pIdVal != null) {
            
            pId = new String();
            jsonToValue(pId, pIdVal, L"String", L"String");
        }
        delete pIdKey;
JsonString* pLocation_idKey = new JsonString(L"location_id");
        IJsonValue* pLocation_idVal = null;
        pJsonObject->GetValue(pLocation_idKey, pLocation_idVal);
        if(pLocation_idVal != null) {
            
            pLocation_id = new String();
            jsonToValue(pLocation_id, pLocation_idVal, L"String", L"String");
        }
        delete pLocation_idKey;
JsonString* pArr_timeKey = new JsonString(L"arr_time");
        IJsonValue* pArr_timeVal = null;
        pJsonObject->GetValue(pArr_timeKey, pArr_timeVal);
        if(pArr_timeVal != null) {
            
            pArr_time = new Long();
            jsonToValue(pArr_time, pArr_timeVal, L"Long", L"Long");
        }
        delete pArr_timeKey;
JsonString* pEnd_timeKey = new JsonString(L"end_time");
        IJsonValue* pEnd_timeVal = null;
        pJsonObject->GetValue(pEnd_timeKey, pEnd_timeVal);
        if(pEnd_timeVal != null) {
            
            pEnd_time = new Long();
            jsonToValue(pEnd_time, pEnd_timeVal, L"Long", L"Long");
        }
        delete pEnd_timeKey;
JsonString* pWaiting_timeKey = new JsonString(L"waiting_time");
        IJsonValue* pWaiting_timeVal = null;
        pJsonObject->GetValue(pWaiting_timeKey, pWaiting_timeVal);
        if(pWaiting_timeVal != null) {
            
            pWaiting_time = new Long();
            jsonToValue(pWaiting_time, pWaiting_timeVal, L"Long", L"Long");
        }
        delete pWaiting_timeKey;
JsonString* pDistanceKey = new JsonString(L"distance");
        IJsonValue* pDistanceVal = null;
        pJsonObject->GetValue(pDistanceKey, pDistanceVal);
        if(pDistanceVal != null) {
            
            pDistance = new Long();
            jsonToValue(pDistance, pDistanceVal, L"Long", L"Long");
        }
        delete pDistanceKey;
JsonString* pDriving_timeKey = new JsonString(L"driving_time");
        IJsonValue* pDriving_timeVal = null;
        pJsonObject->GetValue(pDriving_timeKey, pDriving_timeVal);
        if(pDriving_timeVal != null) {
            
            pDriving_time = new Long();
            jsonToValue(pDriving_time, pDriving_timeVal, L"Long", L"Long");
        }
        delete pDriving_timeKey;
JsonString* pLoad_beforeKey = new JsonString(L"load_before");
        IJsonValue* pLoad_beforeVal = null;
        pJsonObject->GetValue(pLoad_beforeKey, pLoad_beforeVal);
        if(pLoad_beforeVal != null) {
            pLoad_before = new ArrayList();
            
            jsonToValue(pLoad_before, pLoad_beforeVal, L"IList", L"Integer");
        }
        delete pLoad_beforeKey;
JsonString* pLoad_afterKey = new JsonString(L"load_after");
        IJsonValue* pLoad_afterVal = null;
        pJsonObject->GetValue(pLoad_afterKey, pLoad_afterVal);
        if(pLoad_afterVal != null) {
            pLoad_after = new ArrayList();
            
            jsonToValue(pLoad_after, pLoad_afterVal, L"IList", L"Integer");
        }
        delete pLoad_afterKey;
    }
}

SamiActivity::SamiActivity(String* json) {
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
SamiActivity::asJson ()
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
SamiActivity::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pTypeKey = new JsonString(L"type");
    pJsonObject->Add(pTypeKey, toJson(getPType(), "String", ""));

    JsonString *pIdKey = new JsonString(L"id");
    pJsonObject->Add(pIdKey, toJson(getPId(), "String", ""));

    JsonString *pLocation_idKey = new JsonString(L"location_id");
    pJsonObject->Add(pLocation_idKey, toJson(getPLocationId(), "String", ""));

    JsonString *pArr_timeKey = new JsonString(L"arr_time");
    pJsonObject->Add(pArr_timeKey, toJson(getPArrTime(), "Long", ""));

    JsonString *pEnd_timeKey = new JsonString(L"end_time");
    pJsonObject->Add(pEnd_timeKey, toJson(getPEndTime(), "Long", ""));

    JsonString *pWaiting_timeKey = new JsonString(L"waiting_time");
    pJsonObject->Add(pWaiting_timeKey, toJson(getPWaitingTime(), "Long", ""));

    JsonString *pDistanceKey = new JsonString(L"distance");
    pJsonObject->Add(pDistanceKey, toJson(getPDistance(), "Long", ""));

    JsonString *pDriving_timeKey = new JsonString(L"driving_time");
    pJsonObject->Add(pDriving_timeKey, toJson(getPDrivingTime(), "Long", ""));

    JsonString *pLoad_beforeKey = new JsonString(L"load_before");
    pJsonObject->Add(pLoad_beforeKey, toJson(getPLoadBefore(), "Integer", "array"));

    JsonString *pLoad_afterKey = new JsonString(L"load_after");
    pJsonObject->Add(pLoad_afterKey, toJson(getPLoadAfter(), "Integer", "array"));

    return pJsonObject;
}

String*
SamiActivity::getPType() {
    return pType;
}
void
SamiActivity::setPType(String* pType) {
    this->pType = pType;
}

String*
SamiActivity::getPId() {
    return pId;
}
void
SamiActivity::setPId(String* pId) {
    this->pId = pId;
}

String*
SamiActivity::getPLocationId() {
    return pLocation_id;
}
void
SamiActivity::setPLocationId(String* pLocation_id) {
    this->pLocation_id = pLocation_id;
}

Long*
SamiActivity::getPArrTime() {
    return pArr_time;
}
void
SamiActivity::setPArrTime(Long* pArr_time) {
    this->pArr_time = pArr_time;
}

Long*
SamiActivity::getPEndTime() {
    return pEnd_time;
}
void
SamiActivity::setPEndTime(Long* pEnd_time) {
    this->pEnd_time = pEnd_time;
}

Long*
SamiActivity::getPWaitingTime() {
    return pWaiting_time;
}
void
SamiActivity::setPWaitingTime(Long* pWaiting_time) {
    this->pWaiting_time = pWaiting_time;
}

Long*
SamiActivity::getPDistance() {
    return pDistance;
}
void
SamiActivity::setPDistance(Long* pDistance) {
    this->pDistance = pDistance;
}

Long*
SamiActivity::getPDrivingTime() {
    return pDriving_time;
}
void
SamiActivity::setPDrivingTime(Long* pDriving_time) {
    this->pDriving_time = pDriving_time;
}

IList*
SamiActivity::getPLoadBefore() {
    return pLoad_before;
}
void
SamiActivity::setPLoadBefore(IList* pLoad_before) {
    this->pLoad_before = pLoad_before;
}

IList*
SamiActivity::getPLoadAfter() {
    return pLoad_after;
}
void
SamiActivity::setPLoadAfter(IList* pLoad_after) {
    this->pLoad_after = pLoad_after;
}



} /* namespace Swagger */

