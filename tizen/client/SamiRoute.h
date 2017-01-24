/*
 * SamiRoute.h
 * 
 * 
 */

#ifndef SamiRoute_H_
#define SamiRoute_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiActivity.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Long;
using Tizen::Base::String;


namespace Swagger {

class SamiRoute: public SamiObject {
public:
    SamiRoute();
    SamiRoute(String* json);
    virtual ~SamiRoute();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiRoute* fromJson(String* obj);

    String* getPVehicleId();
    void setPVehicleId(String* pVehicle_id);
    Long* getPDistance();
    void setPDistance(Long* pDistance);
    Long* getPTransportTime();
    void setPTransportTime(Long* pTransport_time);
    Long* getPCompletionTime();
    void setPCompletionTime(Long* pCompletion_time);
    Long* getPWaitingTime();
    void setPWaitingTime(Long* pWaiting_time);
    IList* getPActivities();
    void setPActivities(IList* pActivities);

private:
    String* pVehicle_id;
Long* pDistance;
Long* pTransport_time;
Long* pCompletion_time;
Long* pWaiting_time;
IList* pActivities;
};

} /* namespace Swagger */

#endif /* SamiRoute_H_ */
