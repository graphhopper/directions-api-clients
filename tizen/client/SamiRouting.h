/*
 * SamiRouting.h
 * 
 * 
 */

#ifndef SamiRouting_H_
#define SamiRouting_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Boolean;


namespace Swagger {

class SamiRouting: public SamiObject {
public:
    SamiRouting();
    SamiRouting(String* json);
    virtual ~SamiRouting();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiRouting* fromJson(String* obj);

    Boolean* getPCalcPoints();
    void setPCalcPoints(Boolean* pCalc_points);

private:
    Boolean* pCalc_points;
};

} /* namespace Swagger */

#endif /* SamiRouting_H_ */
