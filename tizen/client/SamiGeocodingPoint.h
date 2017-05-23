/*
 * SamiGeocodingPoint.h
 * 
 * 
 */

#ifndef SamiGeocodingPoint_H_
#define SamiGeocodingPoint_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Double;


namespace Swagger {

class SamiGeocodingPoint: public SamiObject {
public:
    SamiGeocodingPoint();
    SamiGeocodingPoint(String* json);
    virtual ~SamiGeocodingPoint();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGeocodingPoint* fromJson(String* obj);

    Double* getPLat();
    void setPLat(Double* pLat);
    Double* getPLng();
    void setPLng(Double* pLng);

private:
    Double* pLat;
Double* pLng;
};

} /* namespace Swagger */

#endif /* SamiGeocodingPoint_H_ */
