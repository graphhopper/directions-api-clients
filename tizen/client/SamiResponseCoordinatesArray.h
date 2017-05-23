/*
 * SamiResponseCoordinatesArray.h
 * 
 * An array containing coordinates
 */

#ifndef SamiResponseCoordinatesArray_H_
#define SamiResponseCoordinatesArray_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Collection::IList;


namespace Swagger {

class SamiResponseCoordinatesArray: public SamiObject {
public:
    SamiResponseCoordinatesArray();
    SamiResponseCoordinatesArray(String* json);
    virtual ~SamiResponseCoordinatesArray();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiResponseCoordinatesArray* fromJson(String* obj);


private:
    };

} /* namespace Swagger */

#endif /* SamiResponseCoordinatesArray_H_ */
