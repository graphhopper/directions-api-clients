/*
 * SamiConfiguration.h
 * 
 * 
 */

#ifndef SamiConfiguration_H_
#define SamiConfiguration_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiRouting.h"


namespace Swagger {

class SamiConfiguration: public SamiObject {
public:
    SamiConfiguration();
    SamiConfiguration(String* json);
    virtual ~SamiConfiguration();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiConfiguration* fromJson(String* obj);

    SamiRouting* getPRouting();
    void setPRouting(SamiRouting* pRouting);

private:
    SamiRouting* pRouting;
};

} /* namespace Swagger */

#endif /* SamiConfiguration_H_ */
