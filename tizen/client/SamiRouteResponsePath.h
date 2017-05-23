/*
 * SamiRouteResponsePath.h
 * 
 * A found path
 */

#ifndef SamiRouteResponsePath_H_
#define SamiRouteResponsePath_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiResponseCoordinates.h"
#include "SamiResponseInstructions.h"
using Tizen::Base::Boolean;
using Tizen::Base::Collection::IList;
using Tizen::Base::Double;
using Tizen::Base::Long;


namespace Swagger {

class SamiRouteResponsePath: public SamiObject {
public:
    SamiRouteResponsePath();
    SamiRouteResponsePath(String* json);
    virtual ~SamiRouteResponsePath();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiRouteResponsePath* fromJson(String* obj);

    Double* getPDistance();
    void setPDistance(Double* pDistance);
    Long* getPTime();
    void setPTime(Long* pTime);
    Double* getPAscend();
    void setPAscend(Double* pAscend);
    Double* getPDescend();
    void setPDescend(Double* pDescend);
    SamiResponseCoordinates* getPPoints();
    void setPPoints(SamiResponseCoordinates* pPoints);
    Boolean* getPPointsEncoded();
    void setPPointsEncoded(Boolean* pPoints_encoded);
    IList* getPBbox();
    void setPBbox(IList* pBbox);
    SamiResponseCoordinates* getPSnappedWaypoints();
    void setPSnappedWaypoints(SamiResponseCoordinates* pSnapped_waypoints);
    SamiResponseInstructions* getPInstructions();
    void setPInstructions(SamiResponseInstructions* pInstructions);

private:
    Double* pDistance;
Long* pTime;
Double* pAscend;
Double* pDescend;
SamiResponseCoordinates* pPoints;
Boolean* pPoints_encoded;
IList* pBbox;
SamiResponseCoordinates* pSnapped_waypoints;
SamiResponseInstructions* pInstructions;
};

} /* namespace Swagger */

#endif /* SamiRouteResponsePath_H_ */
