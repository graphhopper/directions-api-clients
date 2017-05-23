#ifndef SamiGeocodingApi_H_
#define SamiGeocodingApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

using Tizen::Base::Boolean;
using Tizen::Base::Integer;
#include "SamiGHError.h"
#include "SamiGeocodingResponse.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiGeocodingApi {
public:
  SamiGeocodingApi();
  virtual ~SamiGeocodingApi();

  SamiGeocodingResponse* 
  geocodeGetWithCompletion(String* key, String* q, String* locale, Integer* limit, Boolean* reverse, String* point, String* provider, void (* handler)(SamiGeocodingResponse*, SamiError*));
  static String getBasePath() {
    return L"https://graphhopper.com/api/1";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiGeocodingApi_H_ */
