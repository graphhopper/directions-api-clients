/*
 * SamiGHError_hints.h
 * 
 * 
 */

#ifndef SamiGHError_hints_H_
#define SamiGHError_hints_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::String;


namespace Swagger {

class SamiGHError_hints: public SamiObject {
public:
    SamiGHError_hints();
    SamiGHError_hints(String* json);
    virtual ~SamiGHError_hints();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHError_hints* fromJson(String* obj);

    String* getPMessage();
    void setPMessage(String* pMessage);

private:
    String* pMessage;
};

} /* namespace Swagger */

#endif /* SamiGHError_hints_H_ */
