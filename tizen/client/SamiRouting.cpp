
#include "SamiRouting.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiRouting::SamiRouting() {
    init();
}

SamiRouting::~SamiRouting() {
    this->cleanup();
}

void
SamiRouting::init() {
    pCalc_points = null;
}

void
SamiRouting::cleanup() {
    if(pCalc_points != null) {
        
        delete pCalc_points;
        pCalc_points = null;
    }
}


SamiRouting*
SamiRouting::fromJson(String* json) {
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
SamiRouting::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pCalc_pointsKey = new JsonString(L"calc_points");
        IJsonValue* pCalc_pointsVal = null;
        pJsonObject->GetValue(pCalc_pointsKey, pCalc_pointsVal);
        if(pCalc_pointsVal != null) {
            
            pCalc_points = new Boolean(false);
            jsonToValue(pCalc_points, pCalc_pointsVal, L"Boolean", L"Boolean");
        }
        delete pCalc_pointsKey;
    }
}

SamiRouting::SamiRouting(String* json) {
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
SamiRouting::asJson ()
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
SamiRouting::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pCalc_pointsKey = new JsonString(L"calc_points");
    pJsonObject->Add(pCalc_pointsKey, toJson(getPCalcPoints(), "Boolean", ""));

    return pJsonObject;
}

Boolean*
SamiRouting::getPCalcPoints() {
    return pCalc_points;
}
void
SamiRouting::setPCalcPoints(Boolean* pCalc_points) {
    this->pCalc_points = pCalc_points;
}



} /* namespace Swagger */

