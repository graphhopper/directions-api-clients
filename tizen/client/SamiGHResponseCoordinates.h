/*
 * SamiGHResponseCoordinates.h
 * 
 * 
 */

#ifndef SamiGHResponseCoordinates_H_
#define SamiGHResponseCoordinates_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHResponseCoordinatesArray.h"


namespace Swagger {

class SamiGHResponseCoordinates: public SamiObject {
public:
    SamiGHResponseCoordinates();
    SamiGHResponseCoordinates(String* json);
    virtual ~SamiGHResponseCoordinates();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHResponseCoordinates* fromJson(String* obj);

    SamiGHResponseCoordinatesArray* getPCoordinates();
    void setPCoordinates(SamiGHResponseCoordinatesArray* pCoordinates);

private:
    SamiGHResponseCoordinatesArray* pCoordinates;
};

} /* namespace Swagger */

#endif /* SamiGHResponseCoordinates_H_ */
