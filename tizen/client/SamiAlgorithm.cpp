
#include "SamiAlgorithm.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiAlgorithm::SamiAlgorithm() {
    init();
}

SamiAlgorithm::~SamiAlgorithm() {
    this->cleanup();
}

void
SamiAlgorithm::init() {
    pProblem_type = null;
pObjective = null;
}

void
SamiAlgorithm::cleanup() {
    if(pProblem_type != null) {
        
        delete pProblem_type;
        pProblem_type = null;
    }
if(pObjective != null) {
        
        delete pObjective;
        pObjective = null;
    }
}


SamiAlgorithm*
SamiAlgorithm::fromJson(String* json) {
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
SamiAlgorithm::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pProblem_typeKey = new JsonString(L"problem_type");
        IJsonValue* pProblem_typeVal = null;
        pJsonObject->GetValue(pProblem_typeKey, pProblem_typeVal);
        if(pProblem_typeVal != null) {
            
            pProblem_type = new String();
            jsonToValue(pProblem_type, pProblem_typeVal, L"String", L"String");
        }
        delete pProblem_typeKey;
JsonString* pObjectiveKey = new JsonString(L"objective");
        IJsonValue* pObjectiveVal = null;
        pJsonObject->GetValue(pObjectiveKey, pObjectiveVal);
        if(pObjectiveVal != null) {
            
            pObjective = new String();
            jsonToValue(pObjective, pObjectiveVal, L"String", L"String");
        }
        delete pObjectiveKey;
    }
}

SamiAlgorithm::SamiAlgorithm(String* json) {
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
SamiAlgorithm::asJson ()
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
SamiAlgorithm::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pProblem_typeKey = new JsonString(L"problem_type");
    pJsonObject->Add(pProblem_typeKey, toJson(getPProblemType(), "String", ""));

    JsonString *pObjectiveKey = new JsonString(L"objective");
    pJsonObject->Add(pObjectiveKey, toJson(getPObjective(), "String", ""));

    return pJsonObject;
}

String*
SamiAlgorithm::getPProblemType() {
    return pProblem_type;
}
void
SamiAlgorithm::setPProblemType(String* pProblem_type) {
    this->pProblem_type = pProblem_type;
}

String*
SamiAlgorithm::getPObjective() {
    return pObjective;
}
void
SamiAlgorithm::setPObjective(String* pObjective) {
    this->pObjective = pObjective;
}



} /* namespace Swagger */

