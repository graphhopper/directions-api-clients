/*
 * SamiGHRouteResponsePath.h
 * 
 * A found path
 */

#ifndef SamiGHRouteResponsePath_H_
#define SamiGHRouteResponsePath_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHResponseCoordinates.h"
#include "SamiGHResponseInstructions.h"
using Tizen::Base::Boolean;
using Tizen::Base::Collection::IList;
using Tizen::Base::Double;
using Tizen::Base::Long;


namespace Swagger {

class SamiGHRouteResponsePath: public SamiObject {
public:
    SamiGHRouteResponsePath();
    SamiGHRouteResponsePath(String* json);
    virtual ~SamiGHRouteResponsePath();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHRouteResponsePath* fromJson(String* obj);

    Double* getPDistance();
    void setPDistance(Double* pDistance);
    Long* getPTime();
    void setPTime(Long* pTime);
    Double* getPAscend();
    void setPAscend(Double* pAscend);
    Double* getPDescend();
    void setPDescend(Double* pDescend);
    SamiGHResponseCoordinates* getPPoints();
    void setPPoints(SamiGHResponseCoordinates* pPoints);
    Boolean* getPPointsEncoded();
    void setPPointsEncoded(Boolean* pPoints_encoded);
    IList* getPBbox();
    void setPBbox(IList* pBbox);
    SamiGHResponseCoordinates* getPSnappedWaypoints();
    void setPSnappedWaypoints(SamiGHResponseCoordinates* pSnapped_waypoints);
    SamiGHResponseInstructions* getPInstructions();
    void setPInstructions(SamiGHResponseInstructions* pInstructions);

private:
    Double* pDistance;
Long* pTime;
Double* pAscend;
Double* pDescend;
SamiGHResponseCoordinates* pPoints;
Boolean* pPoints_encoded;
IList* pBbox;
SamiGHResponseCoordinates* pSnapped_waypoints;
SamiGHResponseInstructions* pInstructions;
};

} /* namespace Swagger */

#endif /* SamiGHRouteResponsePath_H_ */
