/*
 * SamiGHResponseCoordinatesArray.h
 * 
 * An array containing coordinates
 */

#ifndef SamiGHResponseCoordinatesArray_H_
#define SamiGHResponseCoordinatesArray_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Collection::IList;


namespace Swagger {

class SamiGHResponseCoordinatesArray: public SamiObject {
public:
    SamiGHResponseCoordinatesArray();
    SamiGHResponseCoordinatesArray(String* json);
    virtual ~SamiGHResponseCoordinatesArray();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHResponseCoordinatesArray* fromJson(String* obj);


private:
    };

} /* namespace Swagger */

#endif /* SamiGHResponseCoordinatesArray_H_ */
