
#include "SamiResponse.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiResponse::SamiResponse() {
    init();
}

SamiResponse::~SamiResponse() {
    this->cleanup();
}

void
SamiResponse::init() {
    pCopyrights = null;
pJob_id = null;
pStatus = null;
pWaiting_in_queue = null;
pProcessing_time = null;
pSolution = null;
}

void
SamiResponse::cleanup() {
    if(pCopyrights != null) {
        pCopyrights->RemoveAll(true);
        delete pCopyrights;
        pCopyrights = null;
    }
if(pJob_id != null) {
        
        delete pJob_id;
        pJob_id = null;
    }
if(pStatus != null) {
        
        delete pStatus;
        pStatus = null;
    }
if(pWaiting_in_queue != null) {
        
        delete pWaiting_in_queue;
        pWaiting_in_queue = null;
    }
if(pProcessing_time != null) {
        
        delete pProcessing_time;
        pProcessing_time = null;
    }
if(pSolution != null) {
        
        delete pSolution;
        pSolution = null;
    }
}


SamiResponse*
SamiResponse::fromJson(String* json) {
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
SamiResponse::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pCopyrightsKey = new JsonString(L"copyrights");
        IJsonValue* pCopyrightsVal = null;
        pJsonObject->GetValue(pCopyrightsKey, pCopyrightsVal);
        if(pCopyrightsVal != null) {
            pCopyrights = new ArrayList();
            
            jsonToValue(pCopyrights, pCopyrightsVal, L"IList", L"String");
        }
        delete pCopyrightsKey;
JsonString* pJob_idKey = new JsonString(L"job_id");
        IJsonValue* pJob_idVal = null;
        pJsonObject->GetValue(pJob_idKey, pJob_idVal);
        if(pJob_idVal != null) {
            
            pJob_id = new String();
            jsonToValue(pJob_id, pJob_idVal, L"String", L"String");
        }
        delete pJob_idKey;
JsonString* pStatusKey = new JsonString(L"status");
        IJsonValue* pStatusVal = null;
        pJsonObject->GetValue(pStatusKey, pStatusVal);
        if(pStatusVal != null) {
            
            pStatus = new String();
            jsonToValue(pStatus, pStatusVal, L"String", L"String");
        }
        delete pStatusKey;
JsonString* pWaiting_in_queueKey = new JsonString(L"waiting_in_queue");
        IJsonValue* pWaiting_in_queueVal = null;
        pJsonObject->GetValue(pWaiting_in_queueKey, pWaiting_in_queueVal);
        if(pWaiting_in_queueVal != null) {
            
            pWaiting_in_queue = new Long();
            jsonToValue(pWaiting_in_queue, pWaiting_in_queueVal, L"Long", L"Long");
        }
        delete pWaiting_in_queueKey;
JsonString* pProcessing_timeKey = new JsonString(L"processing_time");
        IJsonValue* pProcessing_timeVal = null;
        pJsonObject->GetValue(pProcessing_timeKey, pProcessing_timeVal);
        if(pProcessing_timeVal != null) {
            
            pProcessing_time = new Long();
            jsonToValue(pProcessing_time, pProcessing_timeVal, L"Long", L"Long");
        }
        delete pProcessing_timeKey;
JsonString* pSolutionKey = new JsonString(L"solution");
        IJsonValue* pSolutionVal = null;
        pJsonObject->GetValue(pSolutionKey, pSolutionVal);
        if(pSolutionVal != null) {
            
            pSolution = new SamiSolution();
            jsonToValue(pSolution, pSolutionVal, L"SamiSolution", L"SamiSolution");
        }
        delete pSolutionKey;
    }
}

SamiResponse::SamiResponse(String* json) {
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
SamiResponse::asJson ()
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
SamiResponse::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pCopyrightsKey = new JsonString(L"copyrights");
    pJsonObject->Add(pCopyrightsKey, toJson(getPCopyrights(), "String", "array"));

    JsonString *pJob_idKey = new JsonString(L"job_id");
    pJsonObject->Add(pJob_idKey, toJson(getPJobId(), "String", ""));

    JsonString *pStatusKey = new JsonString(L"status");
    pJsonObject->Add(pStatusKey, toJson(getPStatus(), "String", ""));

    JsonString *pWaiting_in_queueKey = new JsonString(L"waiting_in_queue");
    pJsonObject->Add(pWaiting_in_queueKey, toJson(getPWaitingInQueue(), "Long", ""));

    JsonString *pProcessing_timeKey = new JsonString(L"processing_time");
    pJsonObject->Add(pProcessing_timeKey, toJson(getPProcessingTime(), "Long", ""));

    JsonString *pSolutionKey = new JsonString(L"solution");
    pJsonObject->Add(pSolutionKey, toJson(getPSolution(), "SamiSolution", ""));

    return pJsonObject;
}

IList*
SamiResponse::getPCopyrights() {
    return pCopyrights;
}
void
SamiResponse::setPCopyrights(IList* pCopyrights) {
    this->pCopyrights = pCopyrights;
}

String*
SamiResponse::getPJobId() {
    return pJob_id;
}
void
SamiResponse::setPJobId(String* pJob_id) {
    this->pJob_id = pJob_id;
}

String*
SamiResponse::getPStatus() {
    return pStatus;
}
void
SamiResponse::setPStatus(String* pStatus) {
    this->pStatus = pStatus;
}

Long*
SamiResponse::getPWaitingInQueue() {
    return pWaiting_in_queue;
}
void
SamiResponse::setPWaitingInQueue(Long* pWaiting_in_queue) {
    this->pWaiting_in_queue = pWaiting_in_queue;
}

Long*
SamiResponse::getPProcessingTime() {
    return pProcessing_time;
}
void
SamiResponse::setPProcessingTime(Long* pProcessing_time) {
    this->pProcessing_time = pProcessing_time;
}

SamiSolution*
SamiResponse::getPSolution() {
    return pSolution;
}
void
SamiResponse::setPSolution(SamiSolution* pSolution) {
    this->pSolution = pSolution;
}



} /* namespace Swagger */

