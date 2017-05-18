
#include "SamiConfiguration.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiConfiguration::SamiConfiguration() {
    init();
}

SamiConfiguration::~SamiConfiguration() {
    this->cleanup();
}

void
SamiConfiguration::init() {
    pRouting = null;
}

void
SamiConfiguration::cleanup() {
    if(pRouting != null) {
        
        delete pRouting;
        pRouting = null;
    }
}


SamiConfiguration*
SamiConfiguration::fromJson(String* json) {
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
SamiConfiguration::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pRoutingKey = new JsonString(L"routing");
        IJsonValue* pRoutingVal = null;
        pJsonObject->GetValue(pRoutingKey, pRoutingVal);
        if(pRoutingVal != null) {
            
            pRouting = new SamiRouting();
            jsonToValue(pRouting, pRoutingVal, L"SamiRouting", L"SamiRouting");
        }
        delete pRoutingKey;
    }
}

SamiConfiguration::SamiConfiguration(String* json) {
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
SamiConfiguration::asJson ()
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
SamiConfiguration::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pRoutingKey = new JsonString(L"routing");
    pJsonObject->Add(pRoutingKey, toJson(getPRouting(), "SamiRouting", ""));

    return pJsonObject;
}

SamiRouting*
SamiConfiguration::getPRouting() {
    return pRouting;
}
void
SamiConfiguration::setPRouting(SamiRouting* pRouting) {
    this->pRouting = pRouting;
}



} /* namespace Swagger */

