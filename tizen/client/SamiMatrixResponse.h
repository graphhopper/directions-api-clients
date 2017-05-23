/*
 * SamiMatrixResponse.h
 * 
 * 
 */

#ifndef SamiMatrixResponse_H_
#define SamiMatrixResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiResponseInfo.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Double;
using Tizen::Base::Long;


namespace Swagger {

class SamiMatrixResponse: public SamiObject {
public:
    SamiMatrixResponse();
    SamiMatrixResponse(String* json);
    virtual ~SamiMatrixResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiMatrixResponse* fromJson(String* obj);

    IList* getPDistances();
    void setPDistances(IList* pDistances);
    IList* getPTimes();
    void setPTimes(IList* pTimes);
    IList* getPWeights();
    void setPWeights(IList* pWeights);
    SamiResponseInfo* getPInfo();
    void setPInfo(SamiResponseInfo* pInfo);

private:
    IList* pDistances;
IList* pTimes;
IList* pWeights;
SamiResponseInfo* pInfo;
};

} /* namespace Swagger */

#endif /* SamiMatrixResponse_H_ */
