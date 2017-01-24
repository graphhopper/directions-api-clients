/*
 * SamiGHGeocodingPoint.h
 * 
 * 
 */

#ifndef SamiGHGeocodingPoint_H_
#define SamiGHGeocodingPoint_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Double;


namespace Swagger {

class SamiGHGeocodingPoint: public SamiObject {
public:
    SamiGHGeocodingPoint();
    SamiGHGeocodingPoint(String* json);
    virtual ~SamiGHGeocodingPoint();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHGeocodingPoint* fromJson(String* obj);

    Double* getPLat();
    void setPLat(Double* pLat);
    Double* getPLng();
    void setPLng(Double* pLng);

private:
    Double* pLat;
Double* pLng;
};

} /* namespace Swagger */

#endif /* SamiGHGeocodingPoint_H_ */
