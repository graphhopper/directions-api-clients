/*
 * SamiGHMatrixResponse.h
 * 
 * 
 */

#ifndef SamiGHMatrixResponse_H_
#define SamiGHMatrixResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHResponseInfo.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Double;
using Tizen::Base::Long;


namespace Swagger {

class SamiGHMatrixResponse: public SamiObject {
public:
    SamiGHMatrixResponse();
    SamiGHMatrixResponse(String* json);
    virtual ~SamiGHMatrixResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHMatrixResponse* fromJson(String* obj);

    IList* getPDistances();
    void setPDistances(IList* pDistances);
    IList* getPTimes();
    void setPTimes(IList* pTimes);
    IList* getPWeights();
    void setPWeights(IList* pWeights);
    SamiGHResponseInfo* getPInfo();
    void setPInfo(SamiGHResponseInfo* pInfo);

private:
    IList* pDistances;
IList* pTimes;
IList* pWeights;
SamiGHResponseInfo* pInfo;
};

} /* namespace Swagger */

#endif /* SamiGHMatrixResponse_H_ */
