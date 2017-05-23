#ifndef SamiSolutionApi_H_
#define SamiSolutionApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

#include "SamiResponse.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiSolutionApi {
public:
  SamiSolutionApi();
  virtual ~SamiSolutionApi();

  SamiResponse* 
  getSolutionWithCompletion(String* key, String* jobId, void (* handler)(SamiResponse*, SamiError*));
  static String getBasePath() {
    return L"https://graphhopper.com/api/1";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiSolutionApi_H_ */
