/*
 * SamiGHError.h
 * 
 * 
 */

#ifndef SamiGHError_H_
#define SamiGHError_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHError_hints.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Integer;
using Tizen::Base::String;


namespace Swagger {

class SamiGHError: public SamiObject {
public:
    SamiGHError();
    SamiGHError(String* json);
    virtual ~SamiGHError();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHError* fromJson(String* obj);

    Integer* getPCode();
    void setPCode(Integer* pCode);
    String* getPMessage();
    void setPMessage(String* pMessage);
    IList* getPHints();
    void setPHints(IList* pHints);

private:
    Integer* pCode;
String* pMessage;
IList* pHints;
};

} /* namespace Swagger */

#endif /* SamiGHError_H_ */
