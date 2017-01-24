/*
 * SamiShipment.h
 * 
 * 
 */

#ifndef SamiShipment_H_
#define SamiShipment_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiStop.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Integer;
using Tizen::Base::String;


namespace Swagger {

class SamiShipment: public SamiObject {
public:
    SamiShipment();
    SamiShipment(String* json);
    virtual ~SamiShipment();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiShipment* fromJson(String* obj);

    String* getPId();
    void setPId(String* pId);
    String* getPName();
    void setPName(String* pName);
    Integer* getPPriority();
    void setPPriority(Integer* pPriority);
    SamiStop* getPPickup();
    void setPPickup(SamiStop* pPickup);
    SamiStop* getPDelivery();
    void setPDelivery(SamiStop* pDelivery);
    IList* getPSize();
    void setPSize(IList* pSize);
    IList* getPRequiredSkills();
    void setPRequiredSkills(IList* pRequired_skills);
    IList* getPAllowedVehicles();
    void setPAllowedVehicles(IList* pAllowed_vehicles);

private:
    String* pId;
String* pName;
Integer* pPriority;
SamiStop* pPickup;
SamiStop* pDelivery;
IList* pSize;
IList* pRequired_skills;
IList* pAllowed_vehicles;
};

} /* namespace Swagger */

#endif /* SamiShipment_H_ */
