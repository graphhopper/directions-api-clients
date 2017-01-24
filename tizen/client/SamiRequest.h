/*
 * SamiRequest.h
 * 
 * 
 */

#ifndef SamiRequest_H_
#define SamiRequest_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiAlgorithm.h"
#include "SamiCostMatrix.h"
#include "SamiObjective.h"
#include "SamiRelation.h"
#include "SamiService.h"
#include "SamiShipment.h"
#include "SamiVehicle.h"
#include "SamiVehicleType.h"
using Tizen::Base::Collection::IList;


namespace Swagger {

class SamiRequest: public SamiObject {
public:
    SamiRequest();
    SamiRequest(String* json);
    virtual ~SamiRequest();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiRequest* fromJson(String* obj);

    IList* getPVehicles();
    void setPVehicles(IList* pVehicles);
    IList* getPVehicleTypes();
    void setPVehicleTypes(IList* pVehicle_types);
    IList* getPServices();
    void setPServices(IList* pServices);
    IList* getPShipments();
    void setPShipments(IList* pShipments);
    IList* getPRelations();
    void setPRelations(IList* pRelations);
    SamiAlgorithm* getPAlgorithm();
    void setPAlgorithm(SamiAlgorithm* pAlgorithm);
    IList* getPObjectives();
    void setPObjectives(IList* pObjectives);
    IList* getPCostMatrices();
    void setPCostMatrices(IList* pCost_matrices);

private:
    IList* pVehicles;
IList* pVehicle_types;
IList* pServices;
IList* pShipments;
IList* pRelations;
SamiAlgorithm* pAlgorithm;
IList* pObjectives;
IList* pCost_matrices;
};

} /* namespace Swagger */

#endif /* SamiRequest_H_ */
