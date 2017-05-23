/*
 * SamiIsochroneResponsePolygon.h
 * 
 * A found path
 */

#ifndef SamiIsochroneResponsePolygon_H_
#define SamiIsochroneResponsePolygon_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiIsochroneResponsePolygon_geometry.h"
#include "SamiIsochroneResponsePolygon_properties.h"
using Tizen::Base::String;


namespace Swagger {

class SamiIsochroneResponsePolygon: public SamiObject {
public:
    SamiIsochroneResponsePolygon();
    SamiIsochroneResponsePolygon(String* json);
    virtual ~SamiIsochroneResponsePolygon();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiIsochroneResponsePolygon* fromJson(String* obj);

    SamiIsochroneResponsePolygon_properties* getPProperties();
    void setPProperties(SamiIsochroneResponsePolygon_properties* pProperties);
    String* getPType();
    void setPType(String* pType);
    SamiIsochroneResponsePolygon_geometry* getPGeometry();
    void setPGeometry(SamiIsochroneResponsePolygon_geometry* pGeometry);

private:
    SamiIsochroneResponsePolygon_properties* pProperties;
String* pType;
SamiIsochroneResponsePolygon_geometry* pGeometry;
};

} /* namespace Swagger */

#endif /* SamiIsochroneResponsePolygon_H_ */
