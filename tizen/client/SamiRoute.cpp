
#include "SamiRoute.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiRoute::SamiRoute() {
    init();
}

SamiRoute::~SamiRoute() {
    this->cleanup();
}

void
SamiRoute::init() {
    pVehicle_id = null;
pDistance = null;
pTransport_time = null;
pCompletion_time = null;
pWaiting_time = null;
pActivities = null;
}

void
SamiRoute::cleanup() {
    if(pVehicle_id != null) {
        
        delete pVehicle_id;
        pVehicle_id = null;
    }
if(pDistance != null) {
        
        delete pDistance;
        pDistance = null;
    }
if(pTransport_time != null) {
        
        delete pTransport_time;
        pTransport_time = null;
    }
if(pCompletion_time != null) {
        
        delete pCompletion_time;
        pCompletion_time = null;
    }
if(pWaiting_time != null) {
        
        delete pWaiting_time;
        pWaiting_time = null;
    }
if(pActivities != null) {
        pActivities->RemoveAll(true);
        delete pActivities;
        pActivities = null;
    }
}


SamiRoute*
SamiRoute::fromJson(String* json) {
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
SamiRoute::fromJsonObject(IJsonValue* pJson) {
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
JsonString* pDistanceKey = new JsonString(L"distance");
        IJsonValue* pDistanceVal = null;
        pJsonObject->GetValue(pDistanceKey, pDistanceVal);
        if(pDistanceVal != null) {
            
            pDistance = new Long();
            jsonToValue(pDistance, pDistanceVal, L"Long", L"Long");
        }
        delete pDistanceKey;
JsonString* pTransport_timeKey = new JsonString(L"transport_time");
        IJsonValue* pTransport_timeVal = null;
        pJsonObject->GetValue(pTransport_timeKey, pTransport_timeVal);
        if(pTransport_timeVal != null) {
            
            pTransport_time = new Long();
            jsonToValue(pTransport_time, pTransport_timeVal, L"Long", L"Long");
        }
        delete pTransport_timeKey;
JsonString* pCompletion_timeKey = new JsonString(L"completion_time");
        IJsonValue* pCompletion_timeVal = null;
        pJsonObject->GetValue(pCompletion_timeKey, pCompletion_timeVal);
        if(pCompletion_timeVal != null) {
            
            pCompletion_time = new Long();
            jsonToValue(pCompletion_time, pCompletion_timeVal, L"Long", L"Long");
        }
        delete pCompletion_timeKey;
JsonString* pWaiting_timeKey = new JsonString(L"waiting_time");
        IJsonValue* pWaiting_timeVal = null;
        pJsonObject->GetValue(pWaiting_timeKey, pWaiting_timeVal);
        if(pWaiting_timeVal != null) {
            
            pWaiting_time = new Long();
            jsonToValue(pWaiting_time, pWaiting_timeVal, L"Long", L"Long");
        }
        delete pWaiting_timeKey;
JsonString* pActivitiesKey = new JsonString(L"activities");
        IJsonValue* pActivitiesVal = null;
        pJsonObject->GetValue(pActivitiesKey, pActivitiesVal);
        if(pActivitiesVal != null) {
            pActivities = new ArrayList();
            
            jsonToValue(pActivities, pActivitiesVal, L"IList", L"SamiActivity");
        }
        delete pActivitiesKey;
    }
}

SamiRoute::SamiRoute(String* json) {
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
SamiRoute::asJson ()
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
SamiRoute::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pVehicle_idKey = new JsonString(L"vehicle_id");
    pJsonObject->Add(pVehicle_idKey, toJson(getPVehicleId(), "String", ""));

    JsonString *pDistanceKey = new JsonString(L"distance");
    pJsonObject->Add(pDistanceKey, toJson(getPDistance(), "Long", ""));

    JsonString *pTransport_timeKey = new JsonString(L"transport_time");
    pJsonObject->Add(pTransport_timeKey, toJson(getPTransportTime(), "Long", ""));

    JsonString *pCompletion_timeKey = new JsonString(L"completion_time");
    pJsonObject->Add(pCompletion_timeKey, toJson(getPCompletionTime(), "Long", ""));

    JsonString *pWaiting_timeKey = new JsonString(L"waiting_time");
    pJsonObject->Add(pWaiting_timeKey, toJson(getPWaitingTime(), "Long", ""));

    JsonString *pActivitiesKey = new JsonString(L"activities");
    pJsonObject->Add(pActivitiesKey, toJson(getPActivities(), "SamiActivity", "array"));

    return pJsonObject;
}

String*
SamiRoute::getPVehicleId() {
    return pVehicle_id;
}
void
SamiRoute::setPVehicleId(String* pVehicle_id) {
    this->pVehicle_id = pVehicle_id;
}

Long*
SamiRoute::getPDistance() {
    return pDistance;
}
void
SamiRoute::setPDistance(Long* pDistance) {
    this->pDistance = pDistance;
}

Long*
SamiRoute::getPTransportTime() {
    return pTransport_time;
}
void
SamiRoute::setPTransportTime(Long* pTransport_time) {
    this->pTransport_time = pTransport_time;
}

Long*
SamiRoute::getPCompletionTime() {
    return pCompletion_time;
}
void
SamiRoute::setPCompletionTime(Long* pCompletion_time) {
    this->pCompletion_time = pCompletion_time;
}

Long*
SamiRoute::getPWaitingTime() {
    return pWaiting_time;
}
void
SamiRoute::setPWaitingTime(Long* pWaiting_time) {
    this->pWaiting_time = pWaiting_time;
}

IList*
SamiRoute::getPActivities() {
    return pActivities;
}
void
SamiRoute::setPActivities(IList* pActivities) {
    this->pActivities = pActivities;
}



} /* namespace Swagger */

