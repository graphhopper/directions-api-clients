
#include "SamiSolution_unassigned.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiSolution_unassigned::SamiSolution_unassigned() {
    init();
}

SamiSolution_unassigned::~SamiSolution_unassigned() {
    this->cleanup();
}

void
SamiSolution_unassigned::init() {
    pServices = null;
pShipments = null;
}

void
SamiSolution_unassigned::cleanup() {
    if(pServices != null) {
        pServices->RemoveAll(true);
        delete pServices;
        pServices = null;
    }
if(pShipments != null) {
        pShipments->RemoveAll(true);
        delete pShipments;
        pShipments = null;
    }
}


SamiSolution_unassigned*
SamiSolution_unassigned::fromJson(String* json) {
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
SamiSolution_unassigned::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pServicesKey = new JsonString(L"services");
        IJsonValue* pServicesVal = null;
        pJsonObject->GetValue(pServicesKey, pServicesVal);
        if(pServicesVal != null) {
            pServices = new ArrayList();
            
            jsonToValue(pServices, pServicesVal, L"IList", L"String");
        }
        delete pServicesKey;
JsonString* pShipmentsKey = new JsonString(L"shipments");
        IJsonValue* pShipmentsVal = null;
        pJsonObject->GetValue(pShipmentsKey, pShipmentsVal);
        if(pShipmentsVal != null) {
            pShipments = new ArrayList();
            
            jsonToValue(pShipments, pShipmentsVal, L"IList", L"String");
        }
        delete pShipmentsKey;
    }
}

SamiSolution_unassigned::SamiSolution_unassigned(String* json) {
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
SamiSolution_unassigned::asJson ()
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
SamiSolution_unassigned::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pServicesKey = new JsonString(L"services");
    pJsonObject->Add(pServicesKey, toJson(getPServices(), "String", "array"));

    JsonString *pShipmentsKey = new JsonString(L"shipments");
    pJsonObject->Add(pShipmentsKey, toJson(getPShipments(), "String", "array"));

    return pJsonObject;
}

IList*
SamiSolution_unassigned::getPServices() {
    return pServices;
}
void
SamiSolution_unassigned::setPServices(IList* pServices) {
    this->pServices = pServices;
}

IList*
SamiSolution_unassigned::getPShipments() {
    return pShipments;
}
void
SamiSolution_unassigned::setPShipments(IList* pShipments) {
    this->pShipments = pShipments;
}



} /* namespace Swagger */

