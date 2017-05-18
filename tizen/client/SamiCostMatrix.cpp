
#include "SamiCostMatrix.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiCostMatrix::SamiCostMatrix() {
    init();
}

SamiCostMatrix::~SamiCostMatrix() {
    this->cleanup();
}

void
SamiCostMatrix::init() {
    pType = null;
pUrl = null;
pLocation_ids = null;
pData = null;
pProfile = null;
}

void
SamiCostMatrix::cleanup() {
    if(pType != null) {
        
        delete pType;
        pType = null;
    }
if(pUrl != null) {
        
        delete pUrl;
        pUrl = null;
    }
if(pLocation_ids != null) {
        pLocation_ids->RemoveAll(true);
        delete pLocation_ids;
        pLocation_ids = null;
    }
if(pData != null) {
        
        delete pData;
        pData = null;
    }
if(pProfile != null) {
        
        delete pProfile;
        pProfile = null;
    }
}


SamiCostMatrix*
SamiCostMatrix::fromJson(String* json) {
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
SamiCostMatrix::fromJsonObject(IJsonValue* pJson) {
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
JsonString* pUrlKey = new JsonString(L"url");
        IJsonValue* pUrlVal = null;
        pJsonObject->GetValue(pUrlKey, pUrlVal);
        if(pUrlVal != null) {
            
            pUrl = new String();
            jsonToValue(pUrl, pUrlVal, L"String", L"String");
        }
        delete pUrlKey;
JsonString* pLocation_idsKey = new JsonString(L"location_ids");
        IJsonValue* pLocation_idsVal = null;
        pJsonObject->GetValue(pLocation_idsKey, pLocation_idsVal);
        if(pLocation_idsVal != null) {
            pLocation_ids = new ArrayList();
            
            jsonToValue(pLocation_ids, pLocation_idsVal, L"IList", L"String");
        }
        delete pLocation_idsKey;
JsonString* pDataKey = new JsonString(L"data");
        IJsonValue* pDataVal = null;
        pJsonObject->GetValue(pDataKey, pDataVal);
        if(pDataVal != null) {
            
            pData = new SamiCostMatrix_data();
            jsonToValue(pData, pDataVal, L"SamiCostMatrix_data", L"SamiCostMatrix_data");
        }
        delete pDataKey;
JsonString* pProfileKey = new JsonString(L"profile");
        IJsonValue* pProfileVal = null;
        pJsonObject->GetValue(pProfileKey, pProfileVal);
        if(pProfileVal != null) {
            
            pProfile = new String();
            jsonToValue(pProfile, pProfileVal, L"String", L"String");
        }
        delete pProfileKey;
    }
}

SamiCostMatrix::SamiCostMatrix(String* json) {
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
SamiCostMatrix::asJson ()
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
SamiCostMatrix::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pTypeKey = new JsonString(L"type");
    pJsonObject->Add(pTypeKey, toJson(getPType(), "String", ""));

    JsonString *pUrlKey = new JsonString(L"url");
    pJsonObject->Add(pUrlKey, toJson(getPUrl(), "String", ""));

    JsonString *pLocation_idsKey = new JsonString(L"location_ids");
    pJsonObject->Add(pLocation_idsKey, toJson(getPLocationIds(), "String", "array"));

    JsonString *pDataKey = new JsonString(L"data");
    pJsonObject->Add(pDataKey, toJson(getPData(), "SamiCostMatrix_data", ""));

    JsonString *pProfileKey = new JsonString(L"profile");
    pJsonObject->Add(pProfileKey, toJson(getPProfile(), "String", ""));

    return pJsonObject;
}

String*
SamiCostMatrix::getPType() {
    return pType;
}
void
SamiCostMatrix::setPType(String* pType) {
    this->pType = pType;
}

String*
SamiCostMatrix::getPUrl() {
    return pUrl;
}
void
SamiCostMatrix::setPUrl(String* pUrl) {
    this->pUrl = pUrl;
}

IList*
SamiCostMatrix::getPLocationIds() {
    return pLocation_ids;
}
void
SamiCostMatrix::setPLocationIds(IList* pLocation_ids) {
    this->pLocation_ids = pLocation_ids;
}

SamiCostMatrix_data*
SamiCostMatrix::getPData() {
    return pData;
}
void
SamiCostMatrix::setPData(SamiCostMatrix_data* pData) {
    this->pData = pData;
}

String*
SamiCostMatrix::getPProfile() {
    return pProfile;
}
void
SamiCostMatrix::setPProfile(String* pProfile) {
    this->pProfile = pProfile;
}



} /* namespace Swagger */

