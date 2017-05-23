#ifndef SamiVrpApi_H_
#define SamiVrpApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

#include "SamiJobId.h"
#include "SamiRequest.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiVrpApi {
public:
  SamiVrpApi();
  virtual ~SamiVrpApi();

  SamiJobId* 
  postVrpWithCompletion(String* key, SamiRequest* body, void (* handler)(SamiJobId*, SamiError*));
  static String getBasePath() {
    return L"https://graphhopper.com/api/1";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiVrpApi_H_ */
