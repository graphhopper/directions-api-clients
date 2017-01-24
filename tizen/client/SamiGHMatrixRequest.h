/*
 * SamiGHMatrixRequest.h
 * 
 * 
 */

#ifndef SamiGHMatrixRequest_H_
#define SamiGHMatrixRequest_H_

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

class SamiGHMatrixRequest: public SamiObject {
public:
    SamiGHMatrixRequest();
    SamiGHMatrixRequest(String* json);
    virtual ~SamiGHMatrixRequest();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHMatrixRequest* fromJson(String* obj);

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

#endif /* SamiGHMatrixRequest_H_ */
