/*
 * SamiGHIsochroneResponsePolygon.h
 * 
 * A found path
 */

#ifndef SamiGHIsochroneResponsePolygon_H_
#define SamiGHIsochroneResponsePolygon_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHIsochroneResponsePolygon_geometry.h"
#include "SamiGHIsochroneResponsePolygon_properties.h"
using Tizen::Base::String;


namespace Swagger {

class SamiGHIsochroneResponsePolygon: public SamiObject {
public:
    SamiGHIsochroneResponsePolygon();
    SamiGHIsochroneResponsePolygon(String* json);
    virtual ~SamiGHIsochroneResponsePolygon();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHIsochroneResponsePolygon* fromJson(String* obj);

    SamiGHIsochroneResponsePolygon_properties* getPProperties();
    void setPProperties(SamiGHIsochroneResponsePolygon_properties* pProperties);
    String* getPType();
    void setPType(String* pType);
    SamiGHIsochroneResponsePolygon_geometry* getPGeometry();
    void setPGeometry(SamiGHIsochroneResponsePolygon_geometry* pGeometry);

private:
    SamiGHIsochroneResponsePolygon_properties* pProperties;
String* pType;
SamiGHIsochroneResponsePolygon_geometry* pGeometry;
};

} /* namespace Swagger */

#endif /* SamiGHIsochroneResponsePolygon_H_ */
