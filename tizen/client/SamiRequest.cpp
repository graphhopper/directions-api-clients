
#include "SamiRequest.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiRequest::SamiRequest() {
    init();
}

SamiRequest::~SamiRequest() {
    this->cleanup();
}

void
SamiRequest::init() {
    pVehicles = null;
pVehicle_types = null;
pServices = null;
pShipments = null;
pRelations = null;
pAlgorithm = null;
pObjectives = null;
pCost_matrices = null;
}

void
SamiRequest::cleanup() {
    if(pVehicles != null) {
        pVehicles->RemoveAll(true);
        delete pVehicles;
        pVehicles = null;
    }
if(pVehicle_types != null) {
        pVehicle_types->RemoveAll(true);
        delete pVehicle_types;
        pVehicle_types = null;
    }
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
if(pRelations != null) {
        pRelations->RemoveAll(true);
        delete pRelations;
        pRelations = null;
    }
if(pAlgorithm != null) {
        
        delete pAlgorithm;
        pAlgorithm = null;
    }
if(pObjectives != null) {
        pObjectives->RemoveAll(true);
        delete pObjectives;
        pObjectives = null;
    }
if(pCost_matrices != null) {
        pCost_matrices->RemoveAll(true);
        delete pCost_matrices;
        pCost_matrices = null;
    }
}


SamiRequest*
SamiRequest::fromJson(String* json) {
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
SamiRequest::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pVehiclesKey = new JsonString(L"vehicles");
        IJsonValue* pVehiclesVal = null;
        pJsonObject->GetValue(pVehiclesKey, pVehiclesVal);
        if(pVehiclesVal != null) {
            pVehicles = new ArrayList();
            
            jsonToValue(pVehicles, pVehiclesVal, L"IList", L"SamiVehicle");
        }
        delete pVehiclesKey;
JsonString* pVehicle_typesKey = new JsonString(L"vehicle_types");
        IJsonValue* pVehicle_typesVal = null;
        pJsonObject->GetValue(pVehicle_typesKey, pVehicle_typesVal);
        if(pVehicle_typesVal != null) {
            pVehicle_types = new ArrayList();
            
            jsonToValue(pVehicle_types, pVehicle_typesVal, L"IList", L"SamiVehicleType");
        }
        delete pVehicle_typesKey;
JsonString* pServicesKey = new JsonString(L"services");
        IJsonValue* pServicesVal = null;
        pJsonObject->GetValue(pServicesKey, pServicesVal);
        if(pServicesVal != null) {
            pServices = new ArrayList();
            
            jsonToValue(pServices, pServicesVal, L"IList", L"SamiService");
        }
        delete pServicesKey;
JsonString* pShipmentsKey = new JsonString(L"shipments");
        IJsonValue* pShipmentsVal = null;
        pJsonObject->GetValue(pShipmentsKey, pShipmentsVal);
        if(pShipmentsVal != null) {
            pShipments = new ArrayList();
            
            jsonToValue(pShipments, pShipmentsVal, L"IList", L"SamiShipment");
        }
        delete pShipmentsKey;
JsonString* pRelationsKey = new JsonString(L"relations");
        IJsonValue* pRelationsVal = null;
        pJsonObject->GetValue(pRelationsKey, pRelationsVal);
        if(pRelationsVal != null) {
            pRelations = new ArrayList();
            
            jsonToValue(pRelations, pRelationsVal, L"IList", L"SamiRelation");
        }
        delete pRelationsKey;
JsonString* pAlgorithmKey = new JsonString(L"algorithm");
        IJsonValue* pAlgorithmVal = null;
        pJsonObject->GetValue(pAlgorithmKey, pAlgorithmVal);
        if(pAlgorithmVal != null) {
            
            pAlgorithm = new SamiAlgorithm();
            jsonToValue(pAlgorithm, pAlgorithmVal, L"SamiAlgorithm", L"SamiAlgorithm");
        }
        delete pAlgorithmKey;
JsonString* pObjectivesKey = new JsonString(L"objectives");
        IJsonValue* pObjectivesVal = null;
        pJsonObject->GetValue(pObjectivesKey, pObjectivesVal);
        if(pObjectivesVal != null) {
            pObjectives = new ArrayList();
            
            jsonToValue(pObjectives, pObjectivesVal, L"IList", L"SamiObjective");
        }
        delete pObjectivesKey;
JsonString* pCost_matricesKey = new JsonString(L"cost_matrices");
        IJsonValue* pCost_matricesVal = null;
        pJsonObject->GetValue(pCost_matricesKey, pCost_matricesVal);
        if(pCost_matricesVal != null) {
            pCost_matrices = new ArrayList();
            
            jsonToValue(pCost_matrices, pCost_matricesVal, L"IList", L"SamiCostMatrix");
        }
        delete pCost_matricesKey;
    }
}

SamiRequest::SamiRequest(String* json) {
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
SamiRequest::asJson ()
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
SamiRequest::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pVehiclesKey = new JsonString(L"vehicles");
    pJsonObject->Add(pVehiclesKey, toJson(getPVehicles(), "SamiVehicle", "array"));

    JsonString *pVehicle_typesKey = new JsonString(L"vehicle_types");
    pJsonObject->Add(pVehicle_typesKey, toJson(getPVehicleTypes(), "SamiVehicleType", "array"));

    JsonString *pServicesKey = new JsonString(L"services");
    pJsonObject->Add(pServicesKey, toJson(getPServices(), "SamiService", "array"));

    JsonString *pShipmentsKey = new JsonString(L"shipments");
    pJsonObject->Add(pShipmentsKey, toJson(getPShipments(), "SamiShipment", "array"));

    JsonString *pRelationsKey = new JsonString(L"relations");
    pJsonObject->Add(pRelationsKey, toJson(getPRelations(), "SamiRelation", "array"));

    JsonString *pAlgorithmKey = new JsonString(L"algorithm");
    pJsonObject->Add(pAlgorithmKey, toJson(getPAlgorithm(), "SamiAlgorithm", ""));

    JsonString *pObjectivesKey = new JsonString(L"objectives");
    pJsonObject->Add(pObjectivesKey, toJson(getPObjectives(), "SamiObjective", "array"));

    JsonString *pCost_matricesKey = new JsonString(L"cost_matrices");
    pJsonObject->Add(pCost_matricesKey, toJson(getPCostMatrices(), "SamiCostMatrix", "array"));

    return pJsonObject;
}

IList*
SamiRequest::getPVehicles() {
    return pVehicles;
}
void
SamiRequest::setPVehicles(IList* pVehicles) {
    this->pVehicles = pVehicles;
}

IList*
SamiRequest::getPVehicleTypes() {
    return pVehicle_types;
}
void
SamiRequest::setPVehicleTypes(IList* pVehicle_types) {
    this->pVehicle_types = pVehicle_types;
}

IList*
SamiRequest::getPServices() {
    return pServices;
}
void
SamiRequest::setPServices(IList* pServices) {
    this->pServices = pServices;
}

IList*
SamiRequest::getPShipments() {
    return pShipments;
}
void
SamiRequest::setPShipments(IList* pShipments) {
    this->pShipments = pShipments;
}

IList*
SamiRequest::getPRelations() {
    return pRelations;
}
void
SamiRequest::setPRelations(IList* pRelations) {
    this->pRelations = pRelations;
}

SamiAlgorithm*
SamiRequest::getPAlgorithm() {
    return pAlgorithm;
}
void
SamiRequest::setPAlgorithm(SamiAlgorithm* pAlgorithm) {
    this->pAlgorithm = pAlgorithm;
}

IList*
SamiRequest::getPObjectives() {
    return pObjectives;
}
void
SamiRequest::setPObjectives(IList* pObjectives) {
    this->pObjectives = pObjectives;
}

IList*
SamiRequest::getPCostMatrices() {
    return pCost_matrices;
}
void
SamiRequest::setPCostMatrices(IList* pCost_matrices) {
    this->pCost_matrices = pCost_matrices;
}



} /* namespace Swagger */

