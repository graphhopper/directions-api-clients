/*
 * SamiGHIsochroneResponsePolygon_geometry.h
 * 
 * 
 */

#ifndef SamiGHIsochroneResponsePolygon_geometry_H_
#define SamiGHIsochroneResponsePolygon_geometry_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHResponseCoordinatesArray.h"
using Tizen::Base::String;


namespace Swagger {

class SamiGHIsochroneResponsePolygon_geometry: public SamiObject {
public:
    SamiGHIsochroneResponsePolygon_geometry();
    SamiGHIsochroneResponsePolygon_geometry(String* json);
    virtual ~SamiGHIsochroneResponsePolygon_geometry();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHIsochroneResponsePolygon_geometry* fromJson(String* obj);

    String* getPType();
    void setPType(String* pType);
    SamiGHResponseCoordinatesArray* getPCoordinates();
    void setPCoordinates(SamiGHResponseCoordinatesArray* pCoordinates);

private:
    String* pType;
SamiGHResponseCoordinatesArray* pCoordinates;
};

} /* namespace Swagger */

#endif /* SamiGHIsochroneResponsePolygon_geometry_H_ */
