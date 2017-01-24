#ifndef SamiRouteOptimizationApi_H_
#define SamiRouteOptimizationApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

#include "SamiJobId.h"
#include "SamiRequest.h"
#include "SamiResponse.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiRouteOptimizationApi {
public:
  SamiRouteOptimizationApi();
  virtual ~SamiRouteOptimizationApi();

  SamiResponse* 
  getSolutionWithCompletion(String* key, String* jobId, void (* handler)(SamiResponse*, SamiError*));
  SamiJobId* 
  postVrpWithCompletion(String* key, SamiRequest* body, void (* handler)(SamiJobId*, SamiError*));
  static String getBasePath() {
    return L"https://graphhopper.com/api/1";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiRouteOptimizationApi_H_ */
