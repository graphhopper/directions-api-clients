/*
 * SamiTimeWindow.h
 * 
 * 
 */

#ifndef SamiTimeWindow_H_
#define SamiTimeWindow_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Long;


namespace Swagger {

class SamiTimeWindow: public SamiObject {
public:
    SamiTimeWindow();
    SamiTimeWindow(String* json);
    virtual ~SamiTimeWindow();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiTimeWindow* fromJson(String* obj);

    Long* getPEarliest();
    void setPEarliest(Long* pEarliest);
    Long* getPLatest();
    void setPLatest(Long* pLatest);

private:
    Long* pEarliest;
Long* pLatest;
};

} /* namespace Swagger */

#endif /* SamiTimeWindow_H_ */
