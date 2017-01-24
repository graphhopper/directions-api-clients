/*
 * SamiRelation.h
 * 
 * 
 */

#ifndef SamiRelation_H_
#define SamiRelation_H_

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

class SamiRelation: public SamiObject {
public:
    SamiRelation();
    SamiRelation(String* json);
    virtual ~SamiRelation();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiRelation* fromJson(String* obj);

    String* getPType();
    void setPType(String* pType);
    IList* getPIds();
    void setPIds(IList* pIds);
    String* getPVehicleId();
    void setPVehicleId(String* pVehicle_id);

private:
    String* pType;
IList* pIds;
String* pVehicle_id;
};

} /* namespace Swagger */

#endif /* SamiRelation_H_ */
