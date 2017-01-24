/*
 * SamiVehicle.h
 * 
 * 
 */

#ifndef SamiVehicle_H_
#define SamiVehicle_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiAddress.h"
#include "SamiBreak.h"
using Tizen::Base::Boolean;
using Tizen::Base::Collection::IList;
using Tizen::Base::Long;
using Tizen::Base::String;


namespace Swagger {

class SamiVehicle: public SamiObject {
public:
    SamiVehicle();
    SamiVehicle(String* json);
    virtual ~SamiVehicle();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiVehicle* fromJson(String* obj);

    String* getPVehicleId();
    void setPVehicleId(String* pVehicle_id);
    String* getPTypeId();
    void setPTypeId(String* pType_id);
    SamiAddress* getPStartAddress();
    void setPStartAddress(SamiAddress* pStart_address);
    SamiAddress* getPEndAddress();
    void setPEndAddress(SamiAddress* pEnd_address);
    SamiBreak* getPBreak();
    void setPBreak(SamiBreak* pBreak);
    Boolean* getPReturnToDepot();
    void setPReturnToDepot(Boolean* pReturn_to_depot);
    Long* getPEarliestStart();
    void setPEarliestStart(Long* pEarliest_start);
    Long* getPLatestEnd();
    void setPLatestEnd(Long* pLatest_end);
    IList* getPSkills();
    void setPSkills(IList* pSkills);

private:
    String* pVehicle_id;
String* pType_id;
SamiAddress* pStart_address;
SamiAddress* pEnd_address;
SamiBreak* pBreak;
Boolean* pReturn_to_depot;
Long* pEarliest_start;
Long* pLatest_end;
IList* pSkills;
};

} /* namespace Swagger */

#endif /* SamiVehicle_H_ */
