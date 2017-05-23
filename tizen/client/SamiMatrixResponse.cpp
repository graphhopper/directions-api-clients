
#include "SamiMatrixResponse.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiMatrixResponse::SamiMatrixResponse() {
    init();
}

SamiMatrixResponse::~SamiMatrixResponse() {
    this->cleanup();
}

void
SamiMatrixResponse::init() {
    pDistances = null;
pTimes = null;
pWeights = null;
pInfo = null;
}

void
SamiMatrixResponse::cleanup() {
    if(pDistances != null) {
        pDistances->RemoveAll(true);
        delete pDistances;
        pDistances = null;
    }
if(pTimes != null) {
        pTimes->RemoveAll(true);
        delete pTimes;
        pTimes = null;
    }
if(pWeights != null) {
        pWeights->RemoveAll(true);
        delete pWeights;
        pWeights = null;
    }
if(pInfo != null) {
        
        delete pInfo;
        pInfo = null;
    }
}


SamiMatrixResponse*
SamiMatrixResponse::fromJson(String* json) {
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
SamiMatrixResponse::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pDistancesKey = new JsonString(L"distances");
        IJsonValue* pDistancesVal = null;
        pJsonObject->GetValue(pDistancesKey, pDistancesVal);
        if(pDistancesVal != null) {
            pDistances = new ArrayList();
            
            jsonToValue(pDistances, pDistancesVal, L"IList", L"IList");
        }
        delete pDistancesKey;
JsonString* pTimesKey = new JsonString(L"times");
        IJsonValue* pTimesVal = null;
        pJsonObject->GetValue(pTimesKey, pTimesVal);
        if(pTimesVal != null) {
            pTimes = new ArrayList();
            
            jsonToValue(pTimes, pTimesVal, L"IList", L"IList");
        }
        delete pTimesKey;
JsonString* pWeightsKey = new JsonString(L"weights");
        IJsonValue* pWeightsVal = null;
        pJsonObject->GetValue(pWeightsKey, pWeightsVal);
        if(pWeightsVal != null) {
            pWeights = new ArrayList();
            
            jsonToValue(pWeights, pWeightsVal, L"IList", L"IList");
        }
        delete pWeightsKey;
JsonString* pInfoKey = new JsonString(L"info");
        IJsonValue* pInfoVal = null;
        pJsonObject->GetValue(pInfoKey, pInfoVal);
        if(pInfoVal != null) {
            
            pInfo = new SamiResponseInfo();
            jsonToValue(pInfo, pInfoVal, L"SamiResponseInfo", L"SamiResponseInfo");
        }
        delete pInfoKey;
    }
}

SamiMatrixResponse::SamiMatrixResponse(String* json) {
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
SamiMatrixResponse::asJson ()
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
SamiMatrixResponse::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pDistancesKey = new JsonString(L"distances");
    pJsonObject->Add(pDistancesKey, toJson(getPDistances(), "IList", "array"));

    JsonString *pTimesKey = new JsonString(L"times");
    pJsonObject->Add(pTimesKey, toJson(getPTimes(), "IList", "array"));

    JsonString *pWeightsKey = new JsonString(L"weights");
    pJsonObject->Add(pWeightsKey, toJson(getPWeights(), "IList", "array"));

    JsonString *pInfoKey = new JsonString(L"info");
    pJsonObject->Add(pInfoKey, toJson(getPInfo(), "SamiResponseInfo", ""));

    return pJsonObject;
}

IList*
SamiMatrixResponse::getPDistances() {
    return pDistances;
}
void
SamiMatrixResponse::setPDistances(IList* pDistances) {
    this->pDistances = pDistances;
}

IList*
SamiMatrixResponse::getPTimes() {
    return pTimes;
}
void
SamiMatrixResponse::setPTimes(IList* pTimes) {
    this->pTimes = pTimes;
}

IList*
SamiMatrixResponse::getPWeights() {
    return pWeights;
}
void
SamiMatrixResponse::setPWeights(IList* pWeights) {
    this->pWeights = pWeights;
}

SamiResponseInfo*
SamiMatrixResponse::getPInfo() {
    return pInfo;
}
void
SamiMatrixResponse::setPInfo(SamiResponseInfo* pInfo) {
    this->pInfo = pInfo;
}



} /* namespace Swagger */

