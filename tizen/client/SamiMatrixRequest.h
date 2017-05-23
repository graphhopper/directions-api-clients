/*
 * SamiMatrixRequest.h
 * 
 * 
 */

#ifndef SamiMatrixRequest_H_
#define SamiMatrixRequest_H_

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

class SamiMatrixRequest: public SamiObject {
public:
    SamiMatrixRequest();
    SamiMatrixRequest(String* json);
    virtual ~SamiMatrixRequest();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiMatrixRequest* fromJson(String* obj);

    IList* getPPoints();
    void setPPoints(IList* pPoints);
    String* getPFromPoints();
    void setPFromPoints(String* pFrom_points);
    String* getPToPoints();
    void setPToPoints(String* pTo_points);
    IList* getPOutArrays();
    void setPOutArrays(IList* pOut_arrays);
    String* getPVehicle();
    void setPVehicle(String* pVehicle);

private:
    IList* pPoints;
String* pFrom_points;
String* pTo_points;
IList* pOut_arrays;
String* pVehicle;
};

} /* namespace Swagger */

#endif /* SamiMatrixRequest_H_ */
