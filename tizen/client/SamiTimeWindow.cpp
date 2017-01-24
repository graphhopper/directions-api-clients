
#include "SamiTimeWindow.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiTimeWindow::SamiTimeWindow() {
    init();
}

SamiTimeWindow::~SamiTimeWindow() {
    this->cleanup();
}

void
SamiTimeWindow::init() {
    pEarliest = null;
pLatest = null;
}

void
SamiTimeWindow::cleanup() {
    if(pEarliest != null) {
        
        delete pEarliest;
        pEarliest = null;
    }
if(pLatest != null) {
        
        delete pLatest;
        pLatest = null;
    }
}


SamiTimeWindow*
SamiTimeWindow::fromJson(String* json) {
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
SamiTimeWindow::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pEarliestKey = new JsonString(L"earliest");
        IJsonValue* pEarliestVal = null;
        pJsonObject->GetValue(pEarliestKey, pEarliestVal);
        if(pEarliestVal != null) {
            
            pEarliest = new Long();
            jsonToValue(pEarliest, pEarliestVal, L"Long", L"Long");
        }
        delete pEarliestKey;
JsonString* pLatestKey = new JsonString(L"latest");
        IJsonValue* pLatestVal = null;
        pJsonObject->GetValue(pLatestKey, pLatestVal);
        if(pLatestVal != null) {
            
            pLatest = new Long();
            jsonToValue(pLatest, pLatestVal, L"Long", L"Long");
        }
        delete pLatestKey;
    }
}

SamiTimeWindow::SamiTimeWindow(String* json) {
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
SamiTimeWindow::asJson ()
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
SamiTimeWindow::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pEarliestKey = new JsonString(L"earliest");
    pJsonObject->Add(pEarliestKey, toJson(getPEarliest(), "Long", ""));

    JsonString *pLatestKey = new JsonString(L"latest");
    pJsonObject->Add(pLatestKey, toJson(getPLatest(), "Long", ""));

    return pJsonObject;
}

Long*
SamiTimeWindow::getPEarliest() {
    return pEarliest;
}
void
SamiTimeWindow::setPEarliest(Long* pEarliest) {
    this->pEarliest = pEarliest;
}

Long*
SamiTimeWindow::getPLatest() {
    return pLatest;
}
void
SamiTimeWindow::setPLatest(Long* pLatest) {
    this->pLatest = pLatest;
}



} /* namespace Swagger */

