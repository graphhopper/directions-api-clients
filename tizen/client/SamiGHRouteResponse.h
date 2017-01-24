/*
 * SamiGHRouteResponse.h
 * 
 * 
 */

#ifndef SamiGHRouteResponse_H_
#define SamiGHRouteResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHResponseInfo.h"
#include "SamiGHRouteResponsePath.h"
using Tizen::Base::Collection::IList;


namespace Swagger {

class SamiGHRouteResponse: public SamiObject {
public:
    SamiGHRouteResponse();
    SamiGHRouteResponse(String* json);
    virtual ~SamiGHRouteResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHRouteResponse* fromJson(String* obj);

    IList* getPPaths();
    void setPPaths(IList* pPaths);
    SamiGHResponseInfo* getPInfo();
    void setPInfo(SamiGHResponseInfo* pInfo);

private:
    IList* pPaths;
SamiGHResponseInfo* pInfo;
};

} /* namespace Swagger */

#endif /* SamiGHRouteResponse_H_ */
