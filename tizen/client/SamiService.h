/*
 * SamiService.h
 * 
 * 
 */

#ifndef SamiService_H_
#define SamiService_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiAddress.h"
#include "SamiTimeWindow.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Integer;
using Tizen::Base::Long;
using Tizen::Base::String;


namespace Swagger {

class SamiService: public SamiObject {
public:
    SamiService();
    SamiService(String* json);
    virtual ~SamiService();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiService* fromJson(String* obj);

    String* getPId();
    void setPId(String* pId);
    String* getPType();
    void setPType(String* pType);
    Integer* getPPriority();
    void setPPriority(Integer* pPriority);
    String* getPName();
    void setPName(String* pName);
    SamiAddress* getPAddress();
    void setPAddress(SamiAddress* pAddress);
    Long* getPDuration();
    void setPDuration(Long* pDuration);
    IList* getPTimeWindows();
    void setPTimeWindows(IList* pTime_windows);
    IList* getPSize();
    void setPSize(IList* pSize);
    IList* getPRequiredSkills();
    void setPRequiredSkills(IList* pRequired_skills);
    IList* getPAllowedVehicles();
    void setPAllowedVehicles(IList* pAllowed_vehicles);

private:
    String* pId;
String* pType;
Integer* pPriority;
String* pName;
SamiAddress* pAddress;
Long* pDuration;
IList* pTime_windows;
IList* pSize;
IList* pRequired_skills;
IList* pAllowed_vehicles;
};

} /* namespace Swagger */

#endif /* SamiService_H_ */
