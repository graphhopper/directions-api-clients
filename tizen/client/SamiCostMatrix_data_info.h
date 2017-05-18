/*
 * SamiCostMatrix_data_info.h
 * 
 * Additional information for your request
 */

#ifndef SamiCostMatrix_data_info_H_
#define SamiCostMatrix_data_info_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Collection::IList;
using Tizen::Base::Double;
using Tizen::Base::String;


namespace Swagger {

class SamiCostMatrix_data_info: public SamiObject {
public:
    SamiCostMatrix_data_info();
    SamiCostMatrix_data_info(String* json);
    virtual ~SamiCostMatrix_data_info();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiCostMatrix_data_info* fromJson(String* obj);

    IList* getPCopyrights();
    void setPCopyrights(IList* pCopyrights);
    Double* getPTook();
    void setPTook(Double* pTook);

private:
    IList* pCopyrights;
Double* pTook;
};

} /* namespace Swagger */

#endif /* SamiCostMatrix_data_info_H_ */
