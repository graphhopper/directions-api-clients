/*
 * SamiVehicleType.h
 * 
 * 
 */

#ifndef SamiVehicleType_H_
#define SamiVehicleType_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Collection::IList;
using Tizen::Base::Double;
using Tizen::Base::Integer;
using Tizen::Base::String;


namespace Swagger {

class SamiVehicleType: public SamiObject {
public:
    SamiVehicleType();
    SamiVehicleType(String* json);
    virtual ~SamiVehicleType();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiVehicleType* fromJson(String* obj);

    String* getPTypeId();
    void setPTypeId(String* pType_id);
    String* getPProfile();
    void setPProfile(String* pProfile);
    IList* getPCapacity();
    void setPCapacity(IList* pCapacity);
    Double* getPSpeedFactor();
    void setPSpeedFactor(Double* pSpeed_factor);
    Double* getPServiceTimeFactor();
    void setPServiceTimeFactor(Double* pService_time_factor);

private:
    String* pType_id;
String* pProfile;
IList* pCapacity;
Double* pSpeed_factor;
Double* pService_time_factor;
};

} /* namespace Swagger */

#endif /* SamiVehicleType_H_ */
