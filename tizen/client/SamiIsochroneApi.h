#ifndef SamiIsochroneApi_H_
#define SamiIsochroneApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

using Tizen::Base::Boolean;
using Tizen::Base::Integer;
#include "SamiGHError.h"
#include "SamiGHIsochroneResponse.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiIsochroneApi {
public:
  SamiIsochroneApi();
  virtual ~SamiIsochroneApi();

  SamiGHIsochroneResponse* 
  isochroneGetWithCompletion(String* point, String* key, Integer* timeLimit, String* vehicle, Integer* buckets, Boolean* reverseFlow, void (* handler)(SamiGHIsochroneResponse*, SamiError*));
  static String getBasePath() {
    return L"https://graphhopper.com/api/1";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiIsochroneApi_H_ */
