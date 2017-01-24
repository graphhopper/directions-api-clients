/*
 * SamiJobId.h
 * 
 * 
 */

#ifndef SamiJobId_H_
#define SamiJobId_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::String;


namespace Swagger {

class SamiJobId: public SamiObject {
public:
    SamiJobId();
    SamiJobId(String* json);
    virtual ~SamiJobId();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiJobId* fromJson(String* obj);

    String* getPJobId();
    void setPJobId(String* pJob_id);

private:
    String* pJob_id;
};

} /* namespace Swagger */

#endif /* SamiJobId_H_ */
