
#include "SamiCostMatrix_data.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiCostMatrix_data::SamiCostMatrix_data() {
    init();
}

SamiCostMatrix_data::~SamiCostMatrix_data() {
    this->cleanup();
}

void
SamiCostMatrix_data::init() {
    pTimes = null;
pDistances = null;
pInfo = null;
}

void
SamiCostMatrix_data::cleanup() {
    if(pTimes != null) {
        pTimes->RemoveAll(true);
        delete pTimes;
        pTimes = null;
    }
if(pDistances != null) {
        pDistances->RemoveAll(true);
        delete pDistances;
        pDistances = null;
    }
if(pInfo != null) {
        
        delete pInfo;
        pInfo = null;
    }
}


SamiCostMatrix_data*
SamiCostMatrix_data::fromJson(String* json) {
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
SamiCostMatrix_data::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pTimesKey = new JsonString(L"times");
        IJsonValue* pTimesVal = null;
        pJsonObject->GetValue(pTimesKey, pTimesVal);
        if(pTimesVal != null) {
            pTimes = new ArrayList();
            
            jsonToValue(pTimes, pTimesVal, L"IList", L"IList");
        }
        delete pTimesKey;
JsonString* pDistancesKey = new JsonString(L"distances");
        IJsonValue* pDistancesVal = null;
        pJsonObject->GetValue(pDistancesKey, pDistancesVal);
        if(pDistancesVal != null) {
            pDistances = new ArrayList();
            
            jsonToValue(pDistances, pDistancesVal, L"IList", L"IList");
        }
        delete pDistancesKey;
JsonString* pInfoKey = new JsonString(L"info");
        IJsonValue* pInfoVal = null;
        pJsonObject->GetValue(pInfoKey, pInfoVal);
        if(pInfoVal != null) {
            
            pInfo = new SamiCostMatrix_data_info();
            jsonToValue(pInfo, pInfoVal, L"SamiCostMatrix_data_info", L"SamiCostMatrix_data_info");
        }
        delete pInfoKey;
    }
}

SamiCostMatrix_data::SamiCostMatrix_data(String* json) {
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
SamiCostMatrix_data::asJson ()
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
SamiCostMatrix_data::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pTimesKey = new JsonString(L"times");
    pJsonObject->Add(pTimesKey, toJson(getPTimes(), "IList", "array"));

    JsonString *pDistancesKey = new JsonString(L"distances");
    pJsonObject->Add(pDistancesKey, toJson(getPDistances(), "IList", "array"));

    JsonString *pInfoKey = new JsonString(L"info");
    pJsonObject->Add(pInfoKey, toJson(getPInfo(), "SamiCostMatrix_data_info", ""));

    return pJsonObject;
}

IList*
SamiCostMatrix_data::getPTimes() {
    return pTimes;
}
void
SamiCostMatrix_data::setPTimes(IList* pTimes) {
    this->pTimes = pTimes;
}

IList*
SamiCostMatrix_data::getPDistances() {
    return pDistances;
}
void
SamiCostMatrix_data::setPDistances(IList* pDistances) {
    this->pDistances = pDistances;
}

SamiCostMatrix_data_info*
SamiCostMatrix_data::getPInfo() {
    return pInfo;
}
void
SamiCostMatrix_data::setPInfo(SamiCostMatrix_data_info* pInfo) {
    this->pInfo = pInfo;
}



} /* namespace Swagger */

