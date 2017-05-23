#include "SamiRoutingApi.h"

#include "SamiHelpers.h"
#include "SamiError.h"

using namespace Tizen::Base;

namespace Swagger {


SamiRoutingApi::SamiRoutingApi() {

}

SamiRoutingApi::~SamiRoutingApi() {

}

void
routeGetProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
    IJsonValue* pJson = JsonParser::ParseN(*pBuffer);

    SamiRouteResponse* out = new SamiRouteResponse();
    jsonToValue(out, pJson, L"SamiRouteResponse*", L"SamiRouteResponse");

    if (pJson) {
      if (pJson->GetType() == JSON_TYPE_OBJECT) {
         JsonObject* pObject = static_cast< JsonObject* >(pJson);
         pObject->RemoveAll(true);
      }
      else if (pJson->GetType() == JSON_TYPE_ARRAY) {
         JsonArray* pArray = static_cast< JsonArray* >(pJson);
         pArray->RemoveAll(true);
      }
      handler(out, null);
    }
    else {
      SamiError* error = new SamiError(0, new String(L"No parsable response received"));
      handler(null, error);
    }
    
  }
  else {
    SamiError* error = new SamiError(code, new String(pHttpResponse->GetStatusText()));
    handler(null, error);
    
  }
}

SamiRouteResponse* 
SamiRoutingApi::routeGetWithCompletion(IList* point, Boolean* pointsEncoded, String* key, String* locale, Boolean* instructions, String* vehicle, Boolean* elevation, Boolean* calcPoints, IList* pointHint, Boolean* ch.disable, String* weighting, Boolean* edgeTraversal, String* algorithm, Integer* heading, Integer* headingPenalty, Boolean* passThrough, Integer* roundTrip.distance, Long* roundTrip.seed, Integer* alternativeRoute.maxPaths, Integer* alternativeRoute.maxWeightFactor, Integer* alternativeRoute.maxShareFactor, void (* success)(SamiRouteResponse*, SamiError*)) {
  client = new SamiApiClient();

  client->success(&routeGetProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  
  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  
  int sz = point->GetCount();
  for(int i = 0; i < sz; i++) {
    String itemAt = stringify(point->GetAt(i), "String*");
    queryParams->Add(new String("point"), new String(itemAt));
  }
  
    queryParams->Add(new String("locale"), locale);

    queryParams->Add(new String("instructions"), instructions);

    queryParams->Add(new String("vehicle"), vehicle);

    queryParams->Add(new String("elevation"), elevation);

    queryParams->Add(new String("points_encoded"), pointsEncoded);

    queryParams->Add(new String("calc_points"), calcPoints);

  int sz = pointHint->GetCount();
  for(int i = 0; i < sz; i++) {
    String itemAt = stringify(pointHint->GetAt(i), "String*");
    queryParams->Add(new String("pointHint"), new String(itemAt));
  }
  
    queryParams->Add(new String("ch.disable"), ch.disable);

    queryParams->Add(new String("weighting"), weighting);

    queryParams->Add(new String("edge_traversal"), edgeTraversal);

    queryParams->Add(new String("algorithm"), algorithm);

    queryParams->Add(new String("heading"), heading);

    queryParams->Add(new String("heading_penalty"), headingPenalty);

    queryParams->Add(new String("pass_through"), passThrough);

    queryParams->Add(new String("round_trip.distance"), roundTrip.distance);

    queryParams->Add(new String("round_trip.seed"), roundTrip.seed);

    queryParams->Add(new String("alternative_route.max_paths"), alternativeRoute.maxPaths);

    queryParams->Add(new String("alternative_route.max_weight_factor"), alternativeRoute.maxWeightFactor);

    queryParams->Add(new String("alternative_route.max_share_factor"), alternativeRoute.maxShareFactor);

    queryParams->Add(new String("key"), key);

  String* mBody = null;


  String url(L"/route");


  client->execute(SamiRoutingApi::getBasePath(), url, "GET", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  return null;
}


} /* namespace Swagger */
