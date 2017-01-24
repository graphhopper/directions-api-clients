
#include "SamiGHError.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGHError::SamiGHError() {
    init();
}

SamiGHError::~SamiGHError() {
    this->cleanup();
}

void
SamiGHError::init() {
    pCode = null;
pMessage = null;
pHints = null;
}

void
SamiGHError::cleanup() {
    if(pCode != null) {
        
        delete pCode;
        pCode = null;
    }
if(pMessage != null) {
        
        delete pMessage;
        pMessage = null;
    }
if(pHints != null) {
        pHints->RemoveAll(true);
        delete pHints;
        pHints = null;
    }
}


SamiGHError*
SamiGHError::fromJson(String* json) {
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
SamiGHError::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pCodeKey = new JsonString(L"code");
        IJsonValue* pCodeVal = null;
        pJsonObject->GetValue(pCodeKey, pCodeVal);
        if(pCodeVal != null) {
            
            pCode = new Integer();
            jsonToValue(pCode, pCodeVal, L"Integer", L"Integer");
        }
        delete pCodeKey;
JsonString* pMessageKey = new JsonString(L"message");
        IJsonValue* pMessageVal = null;
        pJsonObject->GetValue(pMessageKey, pMessageVal);
        if(pMessageVal != null) {
            
            pMessage = new String();
            jsonToValue(pMessage, pMessageVal, L"String", L"String");
        }
        delete pMessageKey;
JsonString* pHintsKey = new JsonString(L"hints");
        IJsonValue* pHintsVal = null;
        pJsonObject->GetValue(pHintsKey, pHintsVal);
        if(pHintsVal != null) {
            pHints = new ArrayList();
            
            jsonToValue(pHints, pHintsVal, L"IList", L"SamiGHError_hints");
        }
        delete pHintsKey;
    }
}

SamiGHError::SamiGHError(String* json) {
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
SamiGHError::asJson ()
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
SamiGHError::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pCodeKey = new JsonString(L"code");
    pJsonObject->Add(pCodeKey, toJson(getPCode(), "Integer", ""));

    JsonString *pMessageKey = new JsonString(L"message");
    pJsonObject->Add(pMessageKey, toJson(getPMessage(), "String", ""));

    JsonString *pHintsKey = new JsonString(L"hints");
    pJsonObject->Add(pHintsKey, toJson(getPHints(), "SamiGHError_hints", "array"));

    return pJsonObject;
}

Integer*
SamiGHError::getPCode() {
    return pCode;
}
void
SamiGHError::setPCode(Integer* pCode) {
    this->pCode = pCode;
}

String*
SamiGHError::getPMessage() {
    return pMessage;
}
void
SamiGHError::setPMessage(String* pMessage) {
    this->pMessage = pMessage;
}

IList*
SamiGHError::getPHints() {
    return pHints;
}
void
SamiGHError::setPHints(IList* pHints) {
    this->pHints = pHints;
}



} /* namespace Swagger */

