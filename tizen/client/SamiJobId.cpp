
#include "SamiJobId.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiJobId::SamiJobId() {
    init();
}

SamiJobId::~SamiJobId() {
    this->cleanup();
}

void
SamiJobId::init() {
    pJob_id = null;
}

void
SamiJobId::cleanup() {
    if(pJob_id != null) {
        
        delete pJob_id;
        pJob_id = null;
    }
}


SamiJobId*
SamiJobId::fromJson(String* json) {
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
SamiJobId::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pJob_idKey = new JsonString(L"job_id");
        IJsonValue* pJob_idVal = null;
        pJsonObject->GetValue(pJob_idKey, pJob_idVal);
        if(pJob_idVal != null) {
            
            pJob_id = new String();
            jsonToValue(pJob_id, pJob_idVal, L"String", L"String");
        }
        delete pJob_idKey;
    }
}

SamiJobId::SamiJobId(String* json) {
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
SamiJobId::asJson ()
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
SamiJobId::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pJob_idKey = new JsonString(L"job_id");
    pJsonObject->Add(pJob_idKey, toJson(getPJobId(), "String", ""));

    return pJsonObject;
}

String*
SamiJobId::getPJobId() {
    return pJob_id;
}
void
SamiJobId::setPJobId(String* pJob_id) {
    this->pJob_id = pJob_id;
}



} /* namespace Swagger */

