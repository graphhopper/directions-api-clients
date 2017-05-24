/*
 * SamiGeocodingLocation.h
 * 
 * 
 */

#ifndef SamiGeocodingLocation_H_
#define SamiGeocodingLocation_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGeocodingPoint.h"
using Tizen::Base::String;


namespace Swagger {

class SamiGeocodingLocation: public SamiObject {
public:
    SamiGeocodingLocation();
    SamiGeocodingLocation(String* json);
    virtual ~SamiGeocodingLocation();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGeocodingLocation* fromJson(String* obj);

    SamiGeocodingPoint* getPPoint();
    void setPPoint(SamiGeocodingPoint* pPoint);
    String* getPOsmId();
    void setPOsmId(String* pOsm_id);
    String* getPOsmType();
    void setPOsmType(String* pOsm_type);
    String* getPOsmKey();
    void setPOsmKey(String* pOsm_key);
    String* getPName();
    void setPName(String* pName);
    String* getPCountry();
    void setPCountry(String* pCountry);
    String* getPCity();
    void setPCity(String* pCity);
    String* getPState();
    void setPState(String* pState);
    String* getPStreet();
    void setPStreet(String* pStreet);
    String* getPHousenumber();
    void setPHousenumber(String* pHousenumber);
    String* getPPostcode();
    void setPPostcode(String* pPostcode);

private:
    SamiGeocodingPoint* pPoint;
String* pOsm_id;
String* pOsm_type;
String* pOsm_key;
String* pName;
String* pCountry;
String* pCity;
String* pState;
String* pStreet;
String* pHousenumber;
String* pPostcode;
};

} /* namespace Swagger */

#endif /* SamiGeocodingLocation_H_ */
