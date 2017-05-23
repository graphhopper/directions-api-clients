/*
 * SamiIsochroneResponsePolygon_properties.h
 * 
 * 
 */

#ifndef SamiIsochroneResponsePolygon_properties_H_
#define SamiIsochroneResponsePolygon_properties_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Integer;


namespace Swagger {

class SamiIsochroneResponsePolygon_properties: public SamiObject {
public:
    SamiIsochroneResponsePolygon_properties();
    SamiIsochroneResponsePolygon_properties(String* json);
    virtual ~SamiIsochroneResponsePolygon_properties();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiIsochroneResponsePolygon_properties* fromJson(String* obj);

    Integer* getPBucket();
    void setPBucket(Integer* pBucket);

private:
    Integer* pBucket;
};

} /* namespace Swagger */

#endif /* SamiIsochroneResponsePolygon_properties_H_ */
