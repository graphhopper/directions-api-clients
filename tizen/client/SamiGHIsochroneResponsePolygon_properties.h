/*
 * SamiGHIsochroneResponsePolygon_properties.h
 * 
 * 
 */

#ifndef SamiGHIsochroneResponsePolygon_properties_H_
#define SamiGHIsochroneResponsePolygon_properties_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Integer;


namespace Swagger {

class SamiGHIsochroneResponsePolygon_properties: public SamiObject {
public:
    SamiGHIsochroneResponsePolygon_properties();
    SamiGHIsochroneResponsePolygon_properties(String* json);
    virtual ~SamiGHIsochroneResponsePolygon_properties();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHIsochroneResponsePolygon_properties* fromJson(String* obj);

    Integer* getPBucket();
    void setPBucket(Integer* pBucket);

private:
    Integer* pBucket;
};

} /* namespace Swagger */

#endif /* SamiGHIsochroneResponsePolygon_properties_H_ */
