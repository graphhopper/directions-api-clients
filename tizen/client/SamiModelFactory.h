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
#include "SamiGeocodingLocation.h"
#include "SamiGeocodingPoint.h"
#include "SamiGeocodingResponse.h"
#include "SamiIsochroneResponse.h"
#include "SamiIsochroneResponsePolygon.h"
#include "SamiIsochroneResponsePolygon_geometry.h"
#include "SamiIsochroneResponsePolygon_properties.h"
#include "SamiJobId.h"
#include "SamiLocation.h"
#include "SamiMatrixRequest.h"
#include "SamiMatrixResponse.h"
#include "SamiObjective.h"
#include "SamiRelation.h"
#include "SamiRequest.h"
#include "SamiResponse.h"
#include "SamiResponseCoordinates.h"
#include "SamiResponseCoordinatesArray.h"
#include "SamiResponseInfo.h"
#include "SamiResponseInstruction.h"
#include "SamiResponseInstructions.h"
#include "SamiRoute.h"
#include "SamiRoutePoint.h"
#include "SamiRouteResponse.h"
#include "SamiRouteResponsePath.h"
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
    if(type.Equals(L"SamiGeocodingLocation", true)) {
      return new SamiGeocodingLocation();
    }
    if(type.Equals(L"SamiGeocodingPoint", true)) {
      return new SamiGeocodingPoint();
    }
    if(type.Equals(L"SamiGeocodingResponse", true)) {
      return new SamiGeocodingResponse();
    }
    if(type.Equals(L"SamiIsochroneResponse", true)) {
      return new SamiIsochroneResponse();
    }
    if(type.Equals(L"SamiIsochroneResponsePolygon", true)) {
      return new SamiIsochroneResponsePolygon();
    }
    if(type.Equals(L"SamiIsochroneResponsePolygon_geometry", true)) {
      return new SamiIsochroneResponsePolygon_geometry();
    }
    if(type.Equals(L"SamiIsochroneResponsePolygon_properties", true)) {
      return new SamiIsochroneResponsePolygon_properties();
    }
    if(type.Equals(L"SamiJobId", true)) {
      return new SamiJobId();
    }
    if(type.Equals(L"SamiLocation", true)) {
      return new SamiLocation();
    }
    if(type.Equals(L"SamiMatrixRequest", true)) {
      return new SamiMatrixRequest();
    }
    if(type.Equals(L"SamiMatrixResponse", true)) {
      return new SamiMatrixResponse();
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
    if(type.Equals(L"SamiResponseCoordinates", true)) {
      return new SamiResponseCoordinates();
    }
    if(type.Equals(L"SamiResponseCoordinatesArray", true)) {
      return new SamiResponseCoordinatesArray();
    }
    if(type.Equals(L"SamiResponseInfo", true)) {
      return new SamiResponseInfo();
    }
    if(type.Equals(L"SamiResponseInstruction", true)) {
      return new SamiResponseInstruction();
    }
    if(type.Equals(L"SamiResponseInstructions", true)) {
      return new SamiResponseInstructions();
    }
    if(type.Equals(L"SamiRoute", true)) {
      return new SamiRoute();
    }
    if(type.Equals(L"SamiRoutePoint", true)) {
      return new SamiRoutePoint();
    }
    if(type.Equals(L"SamiRouteResponse", true)) {
      return new SamiRouteResponse();
    }
    if(type.Equals(L"SamiRouteResponsePath", true)) {
      return new SamiRouteResponsePath();
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
