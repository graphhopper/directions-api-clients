/*
 * SamiSolution.h
 * 
 * 
 */

#ifndef SamiSolution_H_
#define SamiSolution_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiRoute.h"
#include "SamiSolution_unassigned.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Integer;
using Tizen::Base::Long;


namespace Swagger {

class SamiSolution: public SamiObject {
public:
    SamiSolution();
    SamiSolution(String* json);
    virtual ~SamiSolution();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiSolution* fromJson(String* obj);

    Integer* getPCosts();
    void setPCosts(Integer* pCosts);
    Integer* getPDistance();
    void setPDistance(Integer* pDistance);
    Long* getPTime();
    void setPTime(Long* pTime);
    Long* getPTransportTime();
    void setPTransportTime(Long* pTransport_time);
    Long* getPMaxOperationTime();
    void setPMaxOperationTime(Long* pMax_operation_time);
    Long* getPWaitingTime();
    void setPWaitingTime(Long* pWaiting_time);
    Integer* getPNoVehicles();
    void setPNoVehicles(Integer* pNo_vehicles);
    Integer* getPNoUnassigned();
    void setPNoUnassigned(Integer* pNo_unassigned);
    IList* getPRoutes();
    void setPRoutes(IList* pRoutes);
    SamiSolution_unassigned* getPUnassigned();
    void setPUnassigned(SamiSolution_unassigned* pUnassigned);

private:
    Integer* pCosts;
Integer* pDistance;
Long* pTime;
Long* pTransport_time;
Long* pMax_operation_time;
Long* pWaiting_time;
Integer* pNo_vehicles;
Integer* pNo_unassigned;
IList* pRoutes;
SamiSolution_unassigned* pUnassigned;
};

} /* namespace Swagger */

#endif /* SamiSolution_H_ */
