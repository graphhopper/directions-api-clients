/*
 * SamiIsochroneResponsePolygon_geometry.h
 * 
 * 
 */

#ifndef SamiIsochroneResponsePolygon_geometry_H_
#define SamiIsochroneResponsePolygon_geometry_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiResponseCoordinatesArray.h"
using Tizen::Base::String;


namespace Swagger {

class SamiIsochroneResponsePolygon_geometry: public SamiObject {
public:
    SamiIsochroneResponsePolygon_geometry();
    SamiIsochroneResponsePolygon_geometry(String* json);
    virtual ~SamiIsochroneResponsePolygon_geometry();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiIsochroneResponsePolygon_geometry* fromJson(String* obj);

    String* getPType();
    void setPType(String* pType);
    SamiResponseCoordinatesArray* getPCoordinates();
    void setPCoordinates(SamiResponseCoordinatesArray* pCoordinates);

private:
    String* pType;
SamiResponseCoordinatesArray* pCoordinates;
};

} /* namespace Swagger */

#endif /* SamiIsochroneResponsePolygon_geometry_H_ */
