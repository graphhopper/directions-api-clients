/*
 * SamiObjective.h
 * 
 * 
 */

#ifndef SamiObjective_H_
#define SamiObjective_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::String;


namespace Swagger {

class SamiObjective: public SamiObject {
public:
    SamiObjective();
    SamiObjective(String* json);
    virtual ~SamiObjective();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiObjective* fromJson(String* obj);

    String* getPType();
    void setPType(String* pType);
    String* getPValue();
    void setPValue(String* pValue);

private:
    String* pType;
String* pValue;
};

} /* namespace Swagger */

#endif /* SamiObjective_H_ */
