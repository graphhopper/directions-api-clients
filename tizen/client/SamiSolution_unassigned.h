/*
 * SamiSolution_unassigned.h
 * 
 * 
 */

#ifndef SamiSolution_unassigned_H_
#define SamiSolution_unassigned_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Collection::IList;
using Tizen::Base::String;


namespace Swagger {

class SamiSolution_unassigned: public SamiObject {
public:
    SamiSolution_unassigned();
    SamiSolution_unassigned(String* json);
    virtual ~SamiSolution_unassigned();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiSolution_unassigned* fromJson(String* obj);

    IList* getPServices();
    void setPServices(IList* pServices);
    IList* getPShipments();
    void setPShipments(IList* pShipments);

private:
    IList* pServices;
IList* pShipments;
};

} /* namespace Swagger */

#endif /* SamiSolution_unassigned_H_ */
