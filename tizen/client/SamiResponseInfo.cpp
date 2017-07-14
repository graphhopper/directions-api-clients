
#include "SamiResponseInfo.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiResponseInfo::SamiResponseInfo() {
    init();
}

SamiResponseInfo::~SamiResponseInfo() {
    this->cleanup();
}

void
SamiResponseInfo::init() {
    pCopyrights = null;
pTook = null;
}

void
SamiResponseInfo::cleanup() {
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


SamiResponseInfo*
SamiResponseInfo::fromJson(String* json) {
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
SamiResponseInfo::fromJsonObject(IJsonValue* pJson) {
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
            
            pTook = new Double();
            jsonToValue(pTook, pTookVal, L"Double", L"Double");
        }
        delete pTookKey;
    }
}

SamiResponseInfo::SamiResponseInfo(String* json) {
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
SamiResponseInfo::asJson ()
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
SamiResponseInfo::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pCopyrightsKey = new JsonString(L"copyrights");
    pJsonObject->Add(pCopyrightsKey, toJson(getPCopyrights(), "String", "array"));

    JsonString *pTookKey = new JsonString(L"took");
    pJsonObject->Add(pTookKey, toJson(getPTook(), "Double", ""));

    return pJsonObject;
}

IList*
SamiResponseInfo::getPCopyrights() {
    return pCopyrights;
}
void
SamiResponseInfo::setPCopyrights(IList* pCopyrights) {
    this->pCopyrights = pCopyrights;
}

Double*
SamiResponseInfo::getPTook() {
    return pTook;
}
void
SamiResponseInfo::setPTook(Double* pTook) {
    this->pTook = pTook;
}



} /* namespace Swagger */

