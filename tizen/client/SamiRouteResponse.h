/*
 * SamiRouteResponse.h
 * 
 * 
 */

#ifndef SamiRouteResponse_H_
#define SamiRouteResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiResponseInfo.h"
#include "SamiRouteResponsePath.h"
using Tizen::Base::Collection::IList;


namespace Swagger {

class SamiRouteResponse: public SamiObject {
public:
    SamiRouteResponse();
    SamiRouteResponse(String* json);
    virtual ~SamiRouteResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiRouteResponse* fromJson(String* obj);

    IList* getPPaths();
    void setPPaths(IList* pPaths);
    SamiResponseInfo* getPInfo();
    void setPInfo(SamiResponseInfo* pInfo);

private:
    IList* pPaths;
SamiResponseInfo* pInfo;
};

} /* namespace Swagger */

#endif /* SamiRouteResponse_H_ */
