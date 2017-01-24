#ifndef SamiRoutingApi_H_
#define SamiRoutingApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

using Tizen::Base::Boolean;
using Tizen::Base::Integer;
using Tizen::Base::Long;
#include "SamiGHError.h"
#include "SamiGHRouteResponse.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiRoutingApi {
public:
  SamiRoutingApi();
  virtual ~SamiRoutingApi();

  SamiGHRouteResponse* 
  routeGetWithCompletion(IList* point, Boolean* pointsEncoded, String* key, String* locale, Boolean* instructions, String* vehicle, Boolean* elevation, Boolean* calcPoints, IList* pointHint, Boolean* ch.disable, String* weighting, Boolean* edgeTraversal, String* algorithm, Integer* heading, Integer* headingPenalty, Boolean* passThrough, Integer* roundTrip.distance, Long* roundTrip.seed, Integer* alternativeRoute.maxPaths, Integer* alternativeRoute.maxWeightFactor, Integer* alternativeRoute.maxShareFactor, void (* handler)(SamiGHRouteResponse*, SamiError*));
  static String getBasePath() {
    return L"https://graphhopper.com/api/1";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiRoutingApi_H_ */
