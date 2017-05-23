
#include "SamiGeocodingLocation.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiGeocodingLocation::SamiGeocodingLocation() {
    init();
}

SamiGeocodingLocation::~SamiGeocodingLocation() {
    this->cleanup();
}

void
SamiGeocodingLocation::init() {
    pPoint = null;
pOsm_id = null;
pOsm_type = null;
pName = null;
pCountry = null;
pCity = null;
pState = null;
pStreet = null;
pHousenumber = null;
pPostcode = null;
}

void
SamiGeocodingLocation::cleanup() {
    if(pPoint != null) {
        
        delete pPoint;
        pPoint = null;
    }
if(pOsm_id != null) {
        
        delete pOsm_id;
        pOsm_id = null;
    }
if(pOsm_type != null) {
        
        delete pOsm_type;
        pOsm_type = null;
    }
if(pName != null) {
        
        delete pName;
        pName = null;
    }
if(pCountry != null) {
        
        delete pCountry;
        pCountry = null;
    }
if(pCity != null) {
        
        delete pCity;
        pCity = null;
    }
if(pState != null) {
        
        delete pState;
        pState = null;
    }
if(pStreet != null) {
        
        delete pStreet;
        pStreet = null;
    }
if(pHousenumber != null) {
        
        delete pHousenumber;
        pHousenumber = null;
    }
if(pPostcode != null) {
        
        delete pPostcode;
        pPostcode = null;
    }
}


SamiGeocodingLocation*
SamiGeocodingLocation::fromJson(String* json) {
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
SamiGeocodingLocation::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pPointKey = new JsonString(L"point");
        IJsonValue* pPointVal = null;
        pJsonObject->GetValue(pPointKey, pPointVal);
        if(pPointVal != null) {
            
            pPoint = new SamiGeocodingPoint();
            jsonToValue(pPoint, pPointVal, L"SamiGeocodingPoint", L"SamiGeocodingPoint");
        }
        delete pPointKey;
JsonString* pOsm_idKey = new JsonString(L"osm_id");
        IJsonValue* pOsm_idVal = null;
        pJsonObject->GetValue(pOsm_idKey, pOsm_idVal);
        if(pOsm_idVal != null) {
            
            pOsm_id = new String();
            jsonToValue(pOsm_id, pOsm_idVal, L"String", L"String");
        }
        delete pOsm_idKey;
JsonString* pOsm_typeKey = new JsonString(L"osm_type");
        IJsonValue* pOsm_typeVal = null;
        pJsonObject->GetValue(pOsm_typeKey, pOsm_typeVal);
        if(pOsm_typeVal != null) {
            
            pOsm_type = new String();
            jsonToValue(pOsm_type, pOsm_typeVal, L"String", L"String");
        }
        delete pOsm_typeKey;
JsonString* pNameKey = new JsonString(L"name");
        IJsonValue* pNameVal = null;
        pJsonObject->GetValue(pNameKey, pNameVal);
        if(pNameVal != null) {
            
            pName = new String();
            jsonToValue(pName, pNameVal, L"String", L"String");
        }
        delete pNameKey;
JsonString* pCountryKey = new JsonString(L"country");
        IJsonValue* pCountryVal = null;
        pJsonObject->GetValue(pCountryKey, pCountryVal);
        if(pCountryVal != null) {
            
            pCountry = new String();
            jsonToValue(pCountry, pCountryVal, L"String", L"String");
        }
        delete pCountryKey;
JsonString* pCityKey = new JsonString(L"city");
        IJsonValue* pCityVal = null;
        pJsonObject->GetValue(pCityKey, pCityVal);
        if(pCityVal != null) {
            
            pCity = new String();
            jsonToValue(pCity, pCityVal, L"String", L"String");
        }
        delete pCityKey;
JsonString* pStateKey = new JsonString(L"state");
        IJsonValue* pStateVal = null;
        pJsonObject->GetValue(pStateKey, pStateVal);
        if(pStateVal != null) {
            
            pState = new String();
            jsonToValue(pState, pStateVal, L"String", L"String");
        }
        delete pStateKey;
JsonString* pStreetKey = new JsonString(L"street");
        IJsonValue* pStreetVal = null;
        pJsonObject->GetValue(pStreetKey, pStreetVal);
        if(pStreetVal != null) {
            
            pStreet = new String();
            jsonToValue(pStreet, pStreetVal, L"String", L"String");
        }
        delete pStreetKey;
JsonString* pHousenumberKey = new JsonString(L"housenumber");
        IJsonValue* pHousenumberVal = null;
        pJsonObject->GetValue(pHousenumberKey, pHousenumberVal);
        if(pHousenumberVal != null) {
            
            pHousenumber = new String();
            jsonToValue(pHousenumber, pHousenumberVal, L"String", L"String");
        }
        delete pHousenumberKey;
JsonString* pPostcodeKey = new JsonString(L"postcode");
        IJsonValue* pPostcodeVal = null;
        pJsonObject->GetValue(pPostcodeKey, pPostcodeVal);
        if(pPostcodeVal != null) {
            
            pPostcode = new String();
            jsonToValue(pPostcode, pPostcodeVal, L"String", L"String");
        }
        delete pPostcodeKey;
    }
}

SamiGeocodingLocation::SamiGeocodingLocation(String* json) {
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
SamiGeocodingLocation::asJson ()
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
SamiGeocodingLocation::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pPointKey = new JsonString(L"point");
    pJsonObject->Add(pPointKey, toJson(getPPoint(), "SamiGeocodingPoint", ""));

    JsonString *pOsm_idKey = new JsonString(L"osm_id");
    pJsonObject->Add(pOsm_idKey, toJson(getPOsmId(), "String", ""));

    JsonString *pOsm_typeKey = new JsonString(L"osm_type");
    pJsonObject->Add(pOsm_typeKey, toJson(getPOsmType(), "String", ""));

    JsonString *pNameKey = new JsonString(L"name");
    pJsonObject->Add(pNameKey, toJson(getPName(), "String", ""));

    JsonString *pCountryKey = new JsonString(L"country");
    pJsonObject->Add(pCountryKey, toJson(getPCountry(), "String", ""));

    JsonString *pCityKey = new JsonString(L"city");
    pJsonObject->Add(pCityKey, toJson(getPCity(), "String", ""));

    JsonString *pStateKey = new JsonString(L"state");
    pJsonObject->Add(pStateKey, toJson(getPState(), "String", ""));

    JsonString *pStreetKey = new JsonString(L"street");
    pJsonObject->Add(pStreetKey, toJson(getPStreet(), "String", ""));

    JsonString *pHousenumberKey = new JsonString(L"housenumber");
    pJsonObject->Add(pHousenumberKey, toJson(getPHousenumber(), "String", ""));

    JsonString *pPostcodeKey = new JsonString(L"postcode");
    pJsonObject->Add(pPostcodeKey, toJson(getPPostcode(), "String", ""));

    return pJsonObject;
}

SamiGeocodingPoint*
SamiGeocodingLocation::getPPoint() {
    return pPoint;
}
void
SamiGeocodingLocation::setPPoint(SamiGeocodingPoint* pPoint) {
    this->pPoint = pPoint;
}

String*
SamiGeocodingLocation::getPOsmId() {
    return pOsm_id;
}
void
SamiGeocodingLocation::setPOsmId(String* pOsm_id) {
    this->pOsm_id = pOsm_id;
}

String*
SamiGeocodingLocation::getPOsmType() {
    return pOsm_type;
}
void
SamiGeocodingLocation::setPOsmType(String* pOsm_type) {
    this->pOsm_type = pOsm_type;
}

String*
SamiGeocodingLocation::getPName() {
    return pName;
}
void
SamiGeocodingLocation::setPName(String* pName) {
    this->pName = pName;
}

String*
SamiGeocodingLocation::getPCountry() {
    return pCountry;
}
void
SamiGeocodingLocation::setPCountry(String* pCountry) {
    this->pCountry = pCountry;
}

String*
SamiGeocodingLocation::getPCity() {
    return pCity;
}
void
SamiGeocodingLocation::setPCity(String* pCity) {
    this->pCity = pCity;
}

String*
SamiGeocodingLocation::getPState() {
    return pState;
}
void
SamiGeocodingLocation::setPState(String* pState) {
    this->pState = pState;
}

String*
SamiGeocodingLocation::getPStreet() {
    return pStreet;
}
void
SamiGeocodingLocation::setPStreet(String* pStreet) {
    this->pStreet = pStreet;
}

String*
SamiGeocodingLocation::getPHousenumber() {
    return pHousenumber;
}
void
SamiGeocodingLocation::setPHousenumber(String* pHousenumber) {
    this->pHousenumber = pHousenumber;
}

String*
SamiGeocodingLocation::getPPostcode() {
    return pPostcode;
}
void
SamiGeocodingLocation::setPPostcode(String* pPostcode) {
    this->pPostcode = pPostcode;
}



} /* namespace Swagger */

