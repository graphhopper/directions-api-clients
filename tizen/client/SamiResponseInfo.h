/*
 * SamiResponseInfo.h
 * 
 * Additional information for your request
 */

#ifndef SamiResponseInfo_H_
#define SamiResponseInfo_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Collection::IList;
using Tizen::Base::Integer;
using Tizen::Base::String;


namespace Swagger {

class SamiResponseInfo: public SamiObject {
public:
    SamiResponseInfo();
    SamiResponseInfo(String* json);
    virtual ~SamiResponseInfo();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiResponseInfo* fromJson(String* obj);

    IList* getPCopyrights();
    void setPCopyrights(IList* pCopyrights);
    Integer* getPTook();
    void setPTook(Integer* pTook);

private:
    IList* pCopyrights;
Integer* pTook;
};

} /* namespace Swagger */

#endif /* SamiResponseInfo_H_ */
