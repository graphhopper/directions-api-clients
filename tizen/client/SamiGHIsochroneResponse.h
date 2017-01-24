/*
 * SamiGHIsochroneResponse.h
 * 
 * 
 */

#ifndef SamiGHIsochroneResponse_H_
#define SamiGHIsochroneResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHIsochroneResponsePolygon.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::String;


namespace Swagger {

class SamiGHIsochroneResponse: public SamiObject {
public:
    SamiGHIsochroneResponse();
    SamiGHIsochroneResponse(String* json);
    virtual ~SamiGHIsochroneResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHIsochroneResponse* fromJson(String* obj);

    IList* getPPolygons();
    void setPPolygons(IList* pPolygons);
    IList* getPCopyrights();
    void setPCopyrights(IList* pCopyrights);

private:
    IList* pPolygons;
IList* pCopyrights;
};

} /* namespace Swagger */

#endif /* SamiGHIsochroneResponse_H_ */
