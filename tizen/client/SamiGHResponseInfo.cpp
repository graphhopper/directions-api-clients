
#include "SamiGHResponseInfo.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGHResponseInfo::SamiGHResponseInfo() {
    init();
}

SamiGHResponseInfo::~SamiGHResponseInfo() {
    this->cleanup();
}

void
SamiGHResponseInfo::init() {
    pCopyrights = null;
pTook = null;
}

void
SamiGHResponseInfo::cleanup() {
    if(pCopyrights != null) {
        pCopyrights->RemoveAll(true);
        delete pCopyrights;
        pCopyrights = null;
    }
if(pTook != null) {
        
        delete pTook;
        pTook = null;
    }
}


SamiGHResponseInfo*
SamiGHResponseInfo::fromJson(String* json) {
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
SamiGHResponseInfo::fromJsonObject(IJsonValue* pJson) {
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
JsonString* pTookKey = new JsonString(L"took");
        IJsonValue* pTookVal = null;
        pJsonObject->GetValue(pTookKey, pTookVal);
        if(pTookVal != null) {
            
            pTook = new Integer();
            jsonToValue(pTook, pTookVal, L"Integer", L"Integer");
        }
        delete pTookKey;
    }
}

SamiGHResponseInfo::SamiGHResponseInfo(String* json) {
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
SamiGHResponseInfo::asJson ()
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
SamiGHResponseInfo::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pCopyrightsKey = new JsonString(L"copyrights");
    pJsonObject->Add(pCopyrightsKey, toJson(getPCopyrights(), "String", "array"));

    JsonString *pTookKey = new JsonString(L"took");
    pJsonObject->Add(pTookKey, toJson(getPTook(), "Integer", ""));

    return pJsonObject;
}

IList*
SamiGHResponseInfo::getPCopyrights() {
    return pCopyrights;
}
void
SamiGHResponseInfo::setPCopyrights(IList* pCopyrights) {
    this->pCopyrights = pCopyrights;
}

Integer*
SamiGHResponseInfo::getPTook() {
    return pTook;
}
void
SamiGHResponseInfo::setPTook(Integer* pTook) {
    this->pTook = pTook;
}



} /* namespace Swagger */

