/*
 * SamiCostMatrix_data.h
 * 
 * JSON data of matrix response
 */

#ifndef SamiCostMatrix_data_H_
#define SamiCostMatrix_data_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiCostMatrix_data_info.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Double;
using Tizen::Base::Long;


namespace Swagger {

class SamiCostMatrix_data: public SamiObject {
public:
    SamiCostMatrix_data();
    SamiCostMatrix_data(String* json);
    virtual ~SamiCostMatrix_data();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiCostMatrix_data* fromJson(String* obj);

    IList* getPTimes();
    void setPTimes(IList* pTimes);
    IList* getPDistances();
    void setPDistances(IList* pDistances);
    SamiCostMatrix_data_info* getPInfo();
    void setPInfo(SamiCostMatrix_data_info* pInfo);

private:
    IList* pTimes;
IList* pDistances;
SamiCostMatrix_data_info* pInfo;
};

} /* namespace Swagger */

#endif /* SamiCostMatrix_data_H_ */
