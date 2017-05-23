/*
 * SamiResponseCoordinates.h
 * 
 * 
 */

#ifndef SamiResponseCoordinates_H_
#define SamiResponseCoordinates_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiResponseCoordinatesArray.h"


namespace Swagger {

class SamiResponseCoordinates: public SamiObject {
public:
    SamiResponseCoordinates();
    SamiResponseCoordinates(String* json);
    virtual ~SamiResponseCoordinates();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiResponseCoordinates* fromJson(String* obj);

    SamiResponseCoordinatesArray* getPCoordinates();
    void setPCoordinates(SamiResponseCoordinatesArray* pCoordinates);

private:
    SamiResponseCoordinatesArray* pCoordinates;
};

} /* namespace Swagger */

#endif /* SamiResponseCoordinates_H_ */
