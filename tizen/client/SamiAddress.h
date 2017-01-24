/*
 * SamiAddress.h
 * 
 * 
 */

#ifndef SamiAddress_H_
#define SamiAddress_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Double;
using Tizen::Base::String;


namespace Swagger {

class SamiAddress: public SamiObject {
public:
    SamiAddress();
    SamiAddress(String* json);
    virtual ~SamiAddress();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiAddress* fromJson(String* obj);

    String* getPLocationId();
    void setPLocationId(String* pLocation_id);
    Double* getPLon();
    void setPLon(Double* pLon);
    Double* getPLat();
    void setPLat(Double* pLat);

private:
    String* pLocation_id;
Double* pLon;
Double* pLat;
};

} /* namespace Swagger */

#endif /* SamiAddress_H_ */
