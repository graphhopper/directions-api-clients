#ifndef SamiMatrixApi_H_
#define SamiMatrixApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

#include "SamiGHError.h"
#include "SamiGHMatrixRequest.h"
#include "SamiGHMatrixResponse.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiMatrixApi {
public:
  SamiMatrixApi();
  virtual ~SamiMatrixApi();

  SamiGHMatrixResponse* 
  matrixGetWithCompletion(String* key, IList* point, String* fromPoint, String* toPoint, IList* outArray, String* vehicle, void (* handler)(SamiGHMatrixResponse*, SamiError*));
  SamiGHMatrixResponse* 
  matrixPostWithCompletion(String* key, SamiGHMatrixRequest* body, void (* handler)(SamiGHMatrixResponse*, SamiError*));
  static String getBasePath() {
    return L"https://graphhopper.com/api/1";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiMatrixApi_H_ */
