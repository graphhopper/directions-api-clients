/*
 * SamiStop.h
 * 
 * 
 */

#ifndef SamiStop_H_
#define SamiStop_H_

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
using Tizen::Base::Long;


namespace Swagger {

class SamiStop: public SamiObject {
public:
    SamiStop();
    SamiStop(String* json);
    virtual ~SamiStop();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiStop* fromJson(String* obj);

    SamiAddress* getPAddress();
    void setPAddress(SamiAddress* pAddress);
    Long* getPDuration();
    void setPDuration(Long* pDuration);
    IList* getPTimeWindows();
    void setPTimeWindows(IList* pTime_windows);

private:
    SamiAddress* pAddress;
Long* pDuration;
IList* pTime_windows;
};

} /* namespace Swagger */

#endif /* SamiStop_H_ */
