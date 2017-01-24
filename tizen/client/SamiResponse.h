/*
 * SamiResponse.h
 * 
 * 
 */

#ifndef SamiResponse_H_
#define SamiResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiSolution.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Long;
using Tizen::Base::String;


namespace Swagger {

class SamiResponse: public SamiObject {
public:
    SamiResponse();
    SamiResponse(String* json);
    virtual ~SamiResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiResponse* fromJson(String* obj);

    IList* getPCopyrights();
    void setPCopyrights(IList* pCopyrights);
    String* getPJobId();
    void setPJobId(String* pJob_id);
    String* getPStatus();
    void setPStatus(String* pStatus);
    Long* getPWaitingInQueue();
    void setPWaitingInQueue(Long* pWaiting_in_queue);
    Long* getPProcessingTime();
    void setPProcessingTime(Long* pProcessing_time);
    SamiSolution* getPSolution();
    void setPSolution(SamiSolution* pSolution);

private:
    IList* pCopyrights;
String* pJob_id;
String* pStatus;
Long* pWaiting_in_queue;
Long* pProcessing_time;
SamiSolution* pSolution;
};

} /* namespace Swagger */

#endif /* SamiResponse_H_ */
