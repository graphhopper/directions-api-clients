/*
 * SamiIsochroneResponse.h
 * 
 * 
 */

#ifndef SamiIsochroneResponse_H_
#define SamiIsochroneResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiIsochroneResponsePolygon.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::String;


namespace Swagger {

class SamiIsochroneResponse: public SamiObject {
public:
    SamiIsochroneResponse();
    SamiIsochroneResponse(String* json);
    virtual ~SamiIsochroneResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiIsochroneResponse* fromJson(String* obj);

    IList* getPPolygons();
    void setPPolygons(IList* pPolygons);
    IList* getPCopyrights();
    void setPCopyrights(IList* pCopyrights);

private:
    IList* pPolygons;
IList* pCopyrights;
};

} /* namespace Swagger */

#endif /* SamiIsochroneResponse_H_ */
