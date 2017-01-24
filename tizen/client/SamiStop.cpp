
#include "SamiStop.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiStop::SamiStop() {
    init();
}

SamiStop::~SamiStop() {
    this->cleanup();
}

void
SamiStop::init() {
    pAddress = null;
pDuration = null;
pTime_windows = null;
}

void
SamiStop::cleanup() {
    if(pAddress != null) {
        
        delete pAddress;
        pAddress = null;
    }
if(pDuration != null) {
        
        delete pDuration;
        pDuration = null;
    }
if(pTime_windows != null) {
        pTime_windows->RemoveAll(true);
        delete pTime_windows;
        pTime_windows = null;
    }
}


SamiStop*
SamiStop::fromJson(String* json) {
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
SamiStop::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pAddressKey = new JsonString(L"address");
        IJsonValue* pAddressVal = null;
        pJsonObject->GetValue(pAddressKey, pAddressVal);
        if(pAddressVal != null) {
            
            pAddress = new SamiAddress();
            jsonToValue(pAddress, pAddressVal, L"SamiAddress", L"SamiAddress");
        }
        delete pAddressKey;
JsonString* pDurationKey = new JsonString(L"duration");
        IJsonValue* pDurationVal = null;
        pJsonObject->GetValue(pDurationKey, pDurationVal);
        if(pDurationVal != null) {
            
            pDuration = new Long();
            jsonToValue(pDuration, pDurationVal, L"Long", L"Long");
        }
        delete pDurationKey;
JsonString* pTime_windowsKey = new JsonString(L"time_windows");
        IJsonValue* pTime_windowsVal = null;
        pJsonObject->GetValue(pTime_windowsKey, pTime_windowsVal);
        if(pTime_windowsVal != null) {
            pTime_windows = new ArrayList();
            
            jsonToValue(pTime_windows, pTime_windowsVal, L"IList", L"SamiTimeWindow");
        }
        delete pTime_windowsKey;
    }
}

SamiStop::SamiStop(String* json) {
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
SamiStop::asJson ()
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
SamiStop::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pAddressKey = new JsonString(L"address");
    pJsonObject->Add(pAddressKey, toJson(getPAddress(), "SamiAddress", ""));

    JsonString *pDurationKey = new JsonString(L"duration");
    pJsonObject->Add(pDurationKey, toJson(getPDuration(), "Long", ""));

    JsonString *pTime_windowsKey = new JsonString(L"time_windows");
    pJsonObject->Add(pTime_windowsKey, toJson(getPTimeWindows(), "SamiTimeWindow", "array"));

    return pJsonObject;
}

SamiAddress*
SamiStop::getPAddress() {
    return pAddress;
}
void
SamiStop::setPAddress(SamiAddress* pAddress) {
    this->pAddress = pAddress;
}

Long*
SamiStop::getPDuration() {
    return pDuration;
}
void
SamiStop::setPDuration(Long* pDuration) {
    this->pDuration = pDuration;
}

IList*
SamiStop::getPTimeWindows() {
    return pTime_windows;
}
void
SamiStop::setPTimeWindows(IList* pTime_windows) {
    this->pTime_windows = pTime_windows;
}



} /* namespace Swagger */

