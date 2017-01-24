/*
 * SamiGHGeocodingLocation.h
 * 
 * 
 */

#ifndef SamiGHGeocodingLocation_H_
#define SamiGHGeocodingLocation_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHGeocodingPoint.h"
using Tizen::Base::String;


namespace Swagger {

class SamiGHGeocodingLocation: public SamiObject {
public:
    SamiGHGeocodingLocation();
    SamiGHGeocodingLocation(String* json);
    virtual ~SamiGHGeocodingLocation();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHGeocodingLocation* fromJson(String* obj);

    SamiGHGeocodingPoint* getPPoint();
    void setPPoint(SamiGHGeocodingPoint* pPoint);
    String* getPOsmId();
    void setPOsmId(String* pOsm_id);
    String* getPOsmType();
    void setPOsmType(String* pOsm_type);
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
    SamiGHGeocodingPoint* pPoint;
String* pOsm_id;
String* pOsm_type;
String* pName;
String* pCountry;
String* pCity;
String* pState;
String* pStreet;
String* pHousenumber;
String* pPostcode;
};

} /* namespace Swagger */

#endif /* SamiGHGeocodingLocation_H_ */
