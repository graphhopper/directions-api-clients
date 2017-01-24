/*
 * SamiBreak.h
 * 
 * 
 */

#ifndef SamiBreak_H_
#define SamiBreak_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Collection::IList;
using Tizen::Base::Long;


namespace Swagger {

class SamiBreak: public SamiObject {
public:
    SamiBreak();
    SamiBreak(String* json);
    virtual ~SamiBreak();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiBreak* fromJson(String* obj);

    Long* getPEarliest();
    void setPEarliest(Long* pEarliest);
    Long* getPLatest();
    void setPLatest(Long* pLatest);
    Long* getPDuration();
    void setPDuration(Long* pDuration);
    Long* getPMaxDrivingTime();
    void setPMaxDrivingTime(Long* pMax_driving_time);
    Long* getPInitialDrivingTime();
    void setPInitialDrivingTime(Long* pInitial_driving_time);
    IList* getPPossibleSplit();
    void setPPossibleSplit(IList* pPossible_split);

private:
    Long* pEarliest;
Long* pLatest;
Long* pDuration;
Long* pMax_driving_time;
Long* pInitial_driving_time;
IList* pPossible_split;
};

} /* namespace Swagger */

#endif /* SamiBreak_H_ */
