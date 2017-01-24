/*
 * SamiCostMatrix.h
 * 
 * 
 */

#ifndef SamiCostMatrix_H_
#define SamiCostMatrix_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::String;


namespace Swagger {

class SamiCostMatrix: public SamiObject {
public:
    SamiCostMatrix();
    SamiCostMatrix(String* json);
    virtual ~SamiCostMatrix();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiCostMatrix* fromJson(String* obj);

    String* getPType();
    void setPType(String* pType);
    String* getPUrl();
    void setPUrl(String* pUrl);
    String* getPProfile();
    void setPProfile(String* pProfile);

private:
    String* pType;
String* pUrl;
String* pProfile;
};

} /* namespace Swagger */

#endif /* SamiCostMatrix_H_ */
