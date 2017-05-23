/*
 * SamiRoutePoint.h
 * 
 * 
 */

#ifndef SamiRoutePoint_H_
#define SamiRoutePoint_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiObject.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::String;


namespace Swagger {

class SamiRoutePoint: public SamiObject {
public:
    SamiRoutePoint();
    SamiRoutePoint(String* json);
    virtual ~SamiRoutePoint();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiRoutePoint* fromJson(String* obj);

    String* getPType();
    void setPType(String* pType);
    IList* getPCoordinates();
    void setPCoordinates(IList* pCoordinates);

private:
    String* pType;
IList* pCoordinates;
};

} /* namespace Swagger */

#endif /* SamiRoutePoint_H_ */
