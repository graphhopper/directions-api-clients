
#include "SamiGHRouteResponsePath.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGHRouteResponsePath::SamiGHRouteResponsePath() {
    init();
}

SamiGHRouteResponsePath::~SamiGHRouteResponsePath() {
    this->cleanup();
}

void
SamiGHRouteResponsePath::init() {
    pDistance = null;
pTime = null;
pAscend = null;
pDescend = null;
pPoints = null;
pPoints_encoded = null;
pBbox = null;
pSnapped_waypoints = null;
pInstructions = null;
}

void
SamiGHRouteResponsePath::cleanup() {
    if(pDistance != null) {
        
        delete pDistance;
        pDistance = null;
    }
if(pTime != null) {
        
        delete pTime;
        pTime = null;
    }
if(pAscend != null) {
        
        delete pAscend;
        pAscend = null;
    }
if(pDescend != null) {
        
        delete pDescend;
        pDescend = null;
    }
if(pPoints != null) {
        
        delete pPoints;
        pPoints = null;
    }
if(pPoints_encoded != null) {
        
        delete pPoints_encoded;
        pPoints_encoded = null;
    }
if(pBbox != null) {
        pBbox->RemoveAll(true);
        delete pBbox;
        pBbox = null;
    }
if(pSnapped_waypoints != null) {
        
        delete pSnapped_waypoints;
        pSnapped_waypoints = null;
    }
if(pInstructions != null) {
        
        delete pInstructions;
        pInstructions = null;
    }
}


SamiGHRouteResponsePath*
SamiGHRouteResponsePath::fromJson(String* json) {
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
SamiGHRouteResponsePath::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pDistanceKey = new JsonString(L"distance");
        IJsonValue* pDistanceVal = null;
        pJsonObject->GetValue(pDistanceKey, pDistanceVal);
        if(pDistanceVal != null) {
            
            pDistance = new Double();
            jsonToValue(pDistance, pDistanceVal, L"Double", L"Double");
        }
        delete pDistanceKey;
JsonString* pTimeKey = new JsonString(L"time");
        IJsonValue* pTimeVal = null;
        pJsonObject->GetValue(pTimeKey, pTimeVal);
        if(pTimeVal != null) {
            
            pTime = new Long();
            jsonToValue(pTime, pTimeVal, L"Long", L"Long");
        }
        delete pTimeKey;
JsonString* pAscendKey = new JsonString(L"ascend");
        IJsonValue* pAscendVal = null;
        pJsonObject->GetValue(pAscendKey, pAscendVal);
        if(pAscendVal != null) {
            
            pAscend = new Double();
            jsonToValue(pAscend, pAscendVal, L"Double", L"Double");
        }
        delete pAscendKey;
JsonString* pDescendKey = new JsonString(L"descend");
        IJsonValue* pDescendVal = null;
        pJsonObject->GetValue(pDescendKey, pDescendVal);
        if(pDescendVal != null) {
            
            pDescend = new Double();
            jsonToValue(pDescend, pDescendVal, L"Double", L"Double");
        }
        delete pDescendKey;
JsonString* pPointsKey = new JsonString(L"points");
        IJsonValue* pPointsVal = null;
        pJsonObject->GetValue(pPointsKey, pPointsVal);
        if(pPointsVal != null) {
            
            pPoints = new SamiGHResponseCoordinates();
            jsonToValue(pPoints, pPointsVal, L"SamiGHResponseCoordinates", L"SamiGHResponseCoordinates");
        }
        delete pPointsKey;
JsonString* pPoints_encodedKey = new JsonString(L"points_encoded");
        IJsonValue* pPoints_encodedVal = null;
        pJsonObject->GetValue(pPoints_encodedKey, pPoints_encodedVal);
        if(pPoints_encodedVal != null) {
            
            pPoints_encoded = new Boolean(false);
            jsonToValue(pPoints_encoded, pPoints_encodedVal, L"Boolean", L"Boolean");
        }
        delete pPoints_encodedKey;
JsonString* pBboxKey = new JsonString(L"bbox");
        IJsonValue* pBboxVal = null;
        pJsonObject->GetValue(pBboxKey, pBboxVal);
        if(pBboxVal != null) {
            pBbox = new ArrayList();
            
            jsonToValue(pBbox, pBboxVal, L"IList", L"Double");
        }
        delete pBboxKey;
JsonString* pSnapped_waypointsKey = new JsonString(L"snapped_waypoints");
        IJsonValue* pSnapped_waypointsVal = null;
        pJsonObject->GetValue(pSnapped_waypointsKey, pSnapped_waypointsVal);
        if(pSnapped_waypointsVal != null) {
            
            pSnapped_waypoints = new SamiGHResponseCoordinates();
            jsonToValue(pSnapped_waypoints, pSnapped_waypointsVal, L"SamiGHResponseCoordinates", L"SamiGHResponseCoordinates");
        }
        delete pSnapped_waypointsKey;
JsonString* pInstructionsKey = new JsonString(L"instructions");
        IJsonValue* pInstructionsVal = null;
        pJsonObject->GetValue(pInstructionsKey, pInstructionsVal);
        if(pInstructionsVal != null) {
            
            pInstructions = new SamiGHResponseInstructions();
            jsonToValue(pInstructions, pInstructionsVal, L"SamiGHResponseInstructions", L"SamiGHResponseInstructions");
        }
        delete pInstructionsKey;
    }
}

SamiGHRouteResponsePath::SamiGHRouteResponsePath(String* json) {
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
SamiGHRouteResponsePath::asJson ()
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
SamiGHRouteResponsePath::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pDistanceKey = new JsonString(L"distance");
    pJsonObject->Add(pDistanceKey, toJson(getPDistance(), "Double", ""));

    JsonString *pTimeKey = new JsonString(L"time");
    pJsonObject->Add(pTimeKey, toJson(getPTime(), "Long", ""));

    JsonString *pAscendKey = new JsonString(L"ascend");
    pJsonObject->Add(pAscendKey, toJson(getPAscend(), "Double", ""));

    JsonString *pDescendKey = new JsonString(L"descend");
    pJsonObject->Add(pDescendKey, toJson(getPDescend(), "Double", ""));

    JsonString *pPointsKey = new JsonString(L"points");
    pJsonObject->Add(pPointsKey, toJson(getPPoints(), "SamiGHResponseCoordinates", ""));

    JsonString *pPoints_encodedKey = new JsonString(L"points_encoded");
    pJsonObject->Add(pPoints_encodedKey, toJson(getPPointsEncoded(), "Boolean", ""));

    JsonString *pBboxKey = new JsonString(L"bbox");
    pJsonObject->Add(pBboxKey, toJson(getPBbox(), "Double", "array"));

    JsonString *pSnapped_waypointsKey = new JsonString(L"snapped_waypoints");
    pJsonObject->Add(pSnapped_waypointsKey, toJson(getPSnappedWaypoints(), "SamiGHResponseCoordinates", ""));

    JsonString *pInstructionsKey = new JsonString(L"instructions");
    pJsonObject->Add(pInstructionsKey, toJson(getPInstructions(), "SamiGHResponseInstructions", ""));

    return pJsonObject;
}

Double*
SamiGHRouteResponsePath::getPDistance() {
    return pDistance;
}
void
SamiGHRouteResponsePath::setPDistance(Double* pDistance) {
    this->pDistance = pDistance;
}

Long*
SamiGHRouteResponsePath::getPTime() {
    return pTime;
}
void
SamiGHRouteResponsePath::setPTime(Long* pTime) {
    this->pTime = pTime;
}

Double*
SamiGHRouteResponsePath::getPAscend() {
    return pAscend;
}
void
SamiGHRouteResponsePath::setPAscend(Double* pAscend) {
    this->pAscend = pAscend;
}

Double*
SamiGHRouteResponsePath::getPDescend() {
    return pDescend;
}
void
SamiGHRouteResponsePath::setPDescend(Double* pDescend) {
    this->pDescend = pDescend;
}

SamiGHResponseCoordinates*
SamiGHRouteResponsePath::getPPoints() {
    return pPoints;
}
void
SamiGHRouteResponsePath::setPPoints(SamiGHResponseCoordinates* pPoints) {
    this->pPoints = pPoints;
}

Boolean*
SamiGHRouteResponsePath::getPPointsEncoded() {
    return pPoints_encoded;
}
void
SamiGHRouteResponsePath::setPPointsEncoded(Boolean* pPoints_encoded) {
    this->pPoints_encoded = pPoints_encoded;
}

IList*
SamiGHRouteResponsePath::getPBbox() {
    return pBbox;
}
void
SamiGHRouteResponsePath::setPBbox(IList* pBbox) {
    this->pBbox = pBbox;
}

SamiGHResponseCoordinates*
SamiGHRouteResponsePath::getPSnappedWaypoints() {
    return pSnapped_waypoints;
}
void
SamiGHRouteResponsePath::setPSnappedWaypoints(SamiGHResponseCoordinates* pSnapped_waypoints) {
    this->pSnapped_waypoints = pSnapped_waypoints;
}

SamiGHResponseInstructions*
SamiGHRouteResponsePath::getPInstructions() {
    return pInstructions;
}
void
SamiGHRouteResponsePath::setPInstructions(SamiGHResponseInstructions* pInstructions) {
    this->pInstructions = pInstructions;
}



} /* namespace Swagger */

