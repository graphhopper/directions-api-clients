/*
 * SamiActivity.h
 * 
 * 
 */

#ifndef SamiActivity_H_
#define SamiActivity_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Collection::IList;
using Tizen::Base::Integer;
using Tizen::Base::Long;
using Tizen::Base::String;


namespace Swagger {

class SamiActivity: public SamiObject {
public:
    SamiActivity();
    SamiActivity(String* json);
    virtual ~SamiActivity();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiActivity* fromJson(String* obj);

    String* getPType();
    void setPType(String* pType);
    String* getPId();
    void setPId(String* pId);
    String* getPLocationId();
    void setPLocationId(String* pLocation_id);
    Long* getPArrTime();
    void setPArrTime(Long* pArr_time);
    Long* getPEndTime();
    void setPEndTime(Long* pEnd_time);
    Long* getPWaitingTime();
    void setPWaitingTime(Long* pWaiting_time);
    Long* getPDistance();
    void setPDistance(Long* pDistance);
    Long* getPDrivingTime();
    void setPDrivingTime(Long* pDriving_time);
    IList* getPLoadBefore();
    void setPLoadBefore(IList* pLoad_before);
    IList* getPLoadAfter();
    void setPLoadAfter(IList* pLoad_after);

private:
    String* pType;
String* pId;
String* pLocation_id;
Long* pArr_time;
Long* pEnd_time;
Long* pWaiting_time;
Long* pDistance;
Long* pDriving_time;
IList* pLoad_before;
IList* pLoad_after;
};

} /* namespace Swagger */

#endif /* SamiActivity_H_ */
