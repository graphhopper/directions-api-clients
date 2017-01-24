/*
 * SamiGHResponseInfo.h
 * 
 * Additional information for your request
 */

#ifndef SamiGHResponseInfo_H_
#define SamiGHResponseInfo_H_

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

class SamiGHResponseInfo: public SamiObject {
public:
    SamiGHResponseInfo();
    SamiGHResponseInfo(String* json);
    virtual ~SamiGHResponseInfo();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHResponseInfo* fromJson(String* obj);

    IList* getPCopyrights();
    void setPCopyrights(IList* pCopyrights);
    Integer* getPTook();
    void setPTook(Integer* pTook);

private:
    IList* pCopyrights;
Integer* pTook;
};

} /* namespace Swagger */

#endif /* SamiGHResponseInfo_H_ */
