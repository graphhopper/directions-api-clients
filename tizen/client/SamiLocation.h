/*
 * SamiLocation.h
 * 
 * 
 */

#ifndef SamiLocation_H_
#define SamiLocation_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Double;


namespace Swagger {

class SamiLocation: public SamiObject {
public:
    SamiLocation();
    SamiLocation(String* json);
    virtual ~SamiLocation();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiLocation* fromJson(String* obj);

    Double* getPLon();
    void setPLon(Double* pLon);
    Double* getPLat();
    void setPLat(Double* pLat);

private:
    Double* pLon;
Double* pLat;
};

} /* namespace Swagger */

#endif /* SamiLocation_H_ */
