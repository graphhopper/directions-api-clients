#ifndef ModelFactory_H_
#define ModelFactory_H_

#include "SamiObject.h"

#include "SamiActivity.h"
#include "SamiAddress.h"
#include "SamiAlgorithm.h"
#include "SamiBreak.h"
#include "SamiConfiguration.h"
#include "SamiCostMatrix.h"
#include "SamiCostMatrix_data.h"
#include "SamiCostMatrix_data_info.h"
#include "SamiGHError.h"
#include "SamiGHError_hints.h"
#include "SamiGHGeocodingLocation.h"
#include "SamiGHGeocodingPoint.h"
#include "SamiGHGeocodingResponse.h"
#include "SamiGHIsochroneResponse.h"
#include "SamiGHIsochroneResponsePolygon.h"
#include "SamiGHIsochroneResponsePolygon_geometry.h"
#include "SamiGHIsochroneResponsePolygon_properties.h"
#include "SamiGHMatrixRequest.h"
#include "SamiGHMatrixResponse.h"
#include "SamiGHResponseCoordinates.h"
#include "SamiGHResponseCoordinatesArray.h"
#include "SamiGHResponseInfo.h"
#include "SamiGHResponseInstruction.h"
#include "SamiGHResponseInstructions.h"
#include "SamiGHRouteResponse.h"
#include "SamiGHRouteResponsePath.h"
#include "SamiJobId.h"
#include "SamiLocation.h"
#include "SamiObjective.h"
#include "SamiRelation.h"
#include "SamiRequest.h"
#include "SamiResponse.h"
#include "SamiRoute.h"
#include "SamiRouting.h"
#include "SamiService.h"
#include "SamiShipment.h"
#include "SamiSolution.h"
#include "SamiSolution_unassigned.h"
#include "SamiStop.h"
#include "SamiTimeWindow.h"
#include "SamiVehicle.h"
#include "SamiVehicleType.h"

namespace Swagger {
  void*
  create(String type) {
    if(type.Equals(L"SamiActivity", true)) {
      return new SamiActivity();
    }
    if(type.Equals(L"SamiAddress", true)) {
      return new SamiAddress();
    }
    if(type.Equals(L"SamiAlgorithm", true)) {
      return new SamiAlgorithm();
    }
    if(type.Equals(L"SamiBreak", true)) {
      return new SamiBreak();
    }
    if(type.Equals(L"SamiConfiguration", true)) {
      return new SamiConfiguration();
    }
    if(type.Equals(L"SamiCostMatrix", true)) {
      return new SamiCostMatrix();
    }
    if(type.Equals(L"SamiCostMatrix_data", true)) {
      return new SamiCostMatrix_data();
    }
    if(type.Equals(L"SamiCostMatrix_data_info", true)) {
      return new SamiCostMatrix_data_info();
    }
    if(type.Equals(L"SamiGHError", true)) {
      return new SamiGHError();
    }
    if(type.Equals(L"SamiGHError_hints", true)) {
      return new SamiGHError_hints();
    }
    if(type.Equals(L"SamiGHGeocodingLocation", true)) {
      return new SamiGHGeocodingLocation();
    }
    if(type.Equals(L"SamiGHGeocodingPoint", true)) {
      return new SamiGHGeocodingPoint();
    }
    if(type.Equals(L"SamiGHGeocodingResponse", true)) {
      return new SamiGHGeocodingResponse();
    }
    if(type.Equals(L"SamiGHIsochroneResponse", true)) {
      return new SamiGHIsochroneResponse();
    }
    if(type.Equals(L"SamiGHIsochroneResponsePolygon", true)) {
      return new SamiGHIsochroneResponsePolygon();
    }
    if(type.Equals(L"SamiGHIsochroneResponsePolygon_geometry", true)) {
      return new SamiGHIsochroneResponsePolygon_geometry();
    }
    if(type.Equals(L"SamiGHIsochroneResponsePolygon_properties", true)) {
      return new SamiGHIsochroneResponsePolygon_properties();
    }
    if(type.Equals(L"SamiGHMatrixRequest", true)) {
      return new SamiGHMatrixRequest();
    }
    if(type.Equals(L"SamiGHMatrixResponse", true)) {
      return new SamiGHMatrixResponse();
    }
    if(type.Equals(L"SamiGHResponseCoordinates", true)) {
      return new SamiGHResponseCoordinates();
    }
    if(type.Equals(L"SamiGHResponseCoordinatesArray", true)) {
      return new SamiGHResponseCoordinatesArray();
    }
    if(type.Equals(L"SamiGHResponseInfo", true)) {
      return new SamiGHResponseInfo();
    }
    if(type.Equals(L"SamiGHResponseInstruction", true)) {
      return new SamiGHResponseInstruction();
    }
    if(type.Equals(L"SamiGHResponseInstructions", true)) {
      return new SamiGHResponseInstructions();
    }
    if(type.Equals(L"SamiGHRouteResponse", true)) {
      return new SamiGHRouteResponse();
    }
    if(type.Equals(L"SamiGHRouteResponsePath", true)) {
      return new SamiGHRouteResponsePath();
    }
    if(type.Equals(L"SamiJobId", true)) {
      return new SamiJobId();
    }
    if(type.Equals(L"SamiLocation", true)) {
      return new SamiLocation();
    }
    if(type.Equals(L"SamiObjective", true)) {
      return new SamiObjective();
    }
    if(type.Equals(L"SamiRelation", true)) {
      return new SamiRelation();
    }
    if(type.Equals(L"SamiRequest", true)) {
      return new SamiRequest();
    }
    if(type.Equals(L"SamiResponse", true)) {
      return new SamiResponse();
    }
    if(type.Equals(L"SamiRoute", true)) {
      return new SamiRoute();
    }
    if(type.Equals(L"SamiRouting", true)) {
      return new SamiRouting();
    }
    if(type.Equals(L"SamiService", true)) {
      return new SamiService();
    }
    if(type.Equals(L"SamiShipment", true)) {
      return new SamiShipment();
    }
    if(type.Equals(L"SamiSolution", true)) {
      return new SamiSolution();
    }
    if(type.Equals(L"SamiSolution_unassigned", true)) {
      return new SamiSolution_unassigned();
    }
    if(type.Equals(L"SamiStop", true)) {
      return new SamiStop();
    }
    if(type.Equals(L"SamiTimeWindow", true)) {
      return new SamiTimeWindow();
    }
    if(type.Equals(L"SamiVehicle", true)) {
      return new SamiVehicle();
    }
    if(type.Equals(L"SamiVehicleType", true)) {
      return new SamiVehicleType();
    }
    
    if(type.Equals(L"String", true)) {
      return new String();
    }
    if(type.Equals(L"Integer", true)) {
      return new Integer();
    }
    if(type.Equals(L"Long", true)) {
      return new Long();
    }
    if(type.Equals(L"DateTime", true)) {
      return new DateTime();
    }
    return null;
  }
} /* namespace Swagger */

#endif /* ModelFactory_H_ */
