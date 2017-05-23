/*
 * SamiGeocodingResponse.h
 * 
 * 
 */

#ifndef SamiGeocodingResponse_H_
#define SamiGeocodingResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGeocodingLocation.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::String;


namespace Swagger {

class SamiGeocodingResponse: public SamiObject {
public:
    SamiGeocodingResponse();
    SamiGeocodingResponse(String* json);
    virtual ~SamiGeocodingResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGeocodingResponse* fromJson(String* obj);

    IList* getPHits();
    void setPHits(IList* pHits);
    String* getPLocale();
    void setPLocale(String* pLocale);

private:
    IList* pHits;
String* pLocale;
};

} /* namespace Swagger */

#endif /* SamiGeocodingResponse_H_ */
