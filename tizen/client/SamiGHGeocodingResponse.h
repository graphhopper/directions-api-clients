/*
 * SamiGHGeocodingResponse.h
 * 
 * 
 */

#ifndef SamiGHGeocodingResponse_H_
#define SamiGHGeocodingResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHGeocodingLocation.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::String;


namespace Swagger {

class SamiGHGeocodingResponse: public SamiObject {
public:
    SamiGHGeocodingResponse();
    SamiGHGeocodingResponse(String* json);
    virtual ~SamiGHGeocodingResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHGeocodingResponse* fromJson(String* obj);

    IList* getPHits();
    void setPHits(IList* pHits);
    String* getPLocale();
    void setPLocale(String* pLocale);

private:
    IList* pHits;
String* pLocale;
};

} /* namespace Swagger */

#endif /* SamiGHGeocodingResponse_H_ */
