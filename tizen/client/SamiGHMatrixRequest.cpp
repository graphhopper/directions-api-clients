
#include "SamiGHMatrixRequest.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGHMatrixRequest::SamiGHMatrixRequest() {
    init();
}

SamiGHMatrixRequest::~SamiGHMatrixRequest() {
    this->cleanup();
}

void
SamiGHMatrixRequest::init() {
    pPoints = null;
pFrom_points = null;
pTo_points = null;
pOut_arrays = null;
pVehicle = null;
}

void
SamiGHMatrixRequest::cleanup() {
    if(pPoints != null) {
        pPoints->RemoveAll(true);
        delete pPoints;
        pPoints = null;
    }
if(pFrom_points != null) {
        
        delete pFrom_points;
        pFrom_points = null;
    }
if(pTo_points != null) {
        
        delete pTo_points;
        pTo_points = null;
    }
if(pOut_arrays != null) {
        pOut_arrays->RemoveAll(true);
        delete pOut_arrays;
        pOut_arrays = null;
    }
if(pVehicle != null) {
        
        delete pVehicle;
        pVehicle = null;
    }
}


SamiGHMatrixRequest*
SamiGHMatrixRequest::fromJson(String* json) {
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
SamiGHMatrixRequest::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pPointsKey = new JsonString(L"points");
        IJsonValue* pPointsVal = null;
        pJsonObject->GetValue(pPointsKey, pPointsVal);
        if(pPointsVal != null) {
            pPoints = new ArrayList();
            
            jsonToValue(pPoints, pPointsVal, L"IList", L"IList");
        }
        delete pPointsKey;
JsonString* pFrom_pointsKey = new JsonString(L"from_points");
        IJsonValue* pFrom_pointsVal = null;
        pJsonObject->GetValue(pFrom_pointsKey, pFrom_pointsVal);
        if(pFrom_pointsVal != null) {
            
            pFrom_points = new String();
            jsonToValue(pFrom_points, pFrom_pointsVal, L"String", L"String");
        }
        delete pFrom_pointsKey;
JsonString* pTo_pointsKey = new JsonString(L"to_points");
        IJsonValue* pTo_pointsVal = null;
        pJsonObject->GetValue(pTo_pointsKey, pTo_pointsVal);
        if(pTo_pointsVal != null) {
            
            pTo_points = new String();
            jsonToValue(pTo_points, pTo_pointsVal, L"String", L"String");
        }
        delete pTo_pointsKey;
JsonString* pOut_arraysKey = new JsonString(L"out_arrays");
        IJsonValue* pOut_arraysVal = null;
        pJsonObject->GetValue(pOut_arraysKey, pOut_arraysVal);
        if(pOut_arraysVal != null) {
            pOut_arrays = new ArrayList();
            
            jsonToValue(pOut_arrays, pOut_arraysVal, L"IList", L"String");
        }
        delete pOut_arraysKey;
JsonString* pVehicleKey = new JsonString(L"vehicle");
        IJsonValue* pVehicleVal = null;
        pJsonObject->GetValue(pVehicleKey, pVehicleVal);
        if(pVehicleVal != null) {
            
            pVehicle = new String();
            jsonToValue(pVehicle, pVehicleVal, L"String", L"String");
        }
        delete pVehicleKey;
    }
}

SamiGHMatrixRequest::SamiGHMatrixRequest(String* json) {
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
SamiGHMatrixRequest::asJson ()
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
SamiGHMatrixRequest::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pPointsKey = new JsonString(L"points");
    pJsonObject->Add(pPointsKey, toJson(getPPoints(), "IList", "array"));

    JsonString *pFrom_pointsKey = new JsonString(L"from_points");
    pJsonObject->Add(pFrom_pointsKey, toJson(getPFromPoints(), "String", ""));

    JsonString *pTo_pointsKey = new JsonString(L"to_points");
    pJsonObject->Add(pTo_pointsKey, toJson(getPToPoints(), "String", ""));

    JsonString *pOut_arraysKey = new JsonString(L"out_arrays");
    pJsonObject->Add(pOut_arraysKey, toJson(getPOutArrays(), "String", "array"));

    JsonString *pVehicleKey = new JsonString(L"vehicle");
    pJsonObject->Add(pVehicleKey, toJson(getPVehicle(), "String", ""));

    return pJsonObject;
}

IList*
SamiGHMatrixRequest::getPPoints() {
    return pPoints;
}
void
SamiGHMatrixRequest::setPPoints(IList* pPoints) {
    this->pPoints = pPoints;
}

String*
SamiGHMatrixRequest::getPFromPoints() {
    return pFrom_points;
}
void
SamiGHMatrixRequest::setPFromPoints(String* pFrom_points) {
    this->pFrom_points = pFrom_points;
}

String*
SamiGHMatrixRequest::getPToPoints() {
    return pTo_points;
}
void
SamiGHMatrixRequest::setPToPoints(String* pTo_points) {
    this->pTo_points = pTo_points;
}

IList*
SamiGHMatrixRequest::getPOutArrays() {
    return pOut_arrays;
}
void
SamiGHMatrixRequest::setPOutArrays(IList* pOut_arrays) {
    this->pOut_arrays = pOut_arrays;
}

String*
SamiGHMatrixRequest::getPVehicle() {
    return pVehicle;
}
void
SamiGHMatrixRequest::setPVehicle(String* pVehicle) {
    this->pVehicle = pVehicle;
}



} /* namespace Swagger */

