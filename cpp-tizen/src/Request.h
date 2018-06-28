/*
 * Request.h
 *
 * 
 */

#ifndef _Request_H_
#define _Request_H_


#include <string>
#include "Algorithm.h"
#include "Configuration.h"
#include "CostMatrix.h"
#include "Objective.h"
#include "Relation.h"
#include "Service.h"
#include "Shipment.h"
#include "Vehicle.h"
#include "VehicleType.h"
#include <list>
#include "Object.h"

/** \defgroup Models Data Structures for API
 *  Classes containing all the Data Structures needed for calling/returned by API endpoints
 *
 */

namespace Tizen {
namespace ArtikCloud {


/*! \brief 
 *
 *  \ingroup Models
 *
 */

class Request : public Object {
public:
	/*! \brief Constructor.
	 */
	Request();
	Request(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Request();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get An array of vehicles that can be employed
	 */
	std::list<Vehicle> getVehicles();

	/*! \brief Set An array of vehicles that can be employed
	 */
	void setVehicles(std::list <Vehicle> vehicles);
	/*! \brief Get An array of vehicle types
	 */
	std::list<VehicleType> getVehicleTypes();

	/*! \brief Set An array of vehicle types
	 */
	void setVehicleTypes(std::list <VehicleType> vehicle_types);
	/*! \brief Get An array of services
	 */
	std::list<Service> getServices();

	/*! \brief Set An array of services
	 */
	void setServices(std::list <Service> services);
	/*! \brief Get An array of shipments
	 */
	std::list<Shipment> getShipments();

	/*! \brief Set An array of shipments
	 */
	void setShipments(std::list <Shipment> shipments);
	/*! \brief Get An array of relations
	 */
	std::list<Relation> getRelations();

	/*! \brief Set An array of relations
	 */
	void setRelations(std::list <Relation> relations);
	/*! \brief Get 
	 */
	Algorithm getAlgorithm();

	/*! \brief Set 
	 */
	void setAlgorithm(Algorithm  algorithm);
	/*! \brief Get An array of objectives
	 */
	std::list<Objective> getObjectives();

	/*! \brief Set An array of objectives
	 */
	void setObjectives(std::list <Objective> objectives);
	/*! \brief Get An array of cost matrices
	 */
	std::list<CostMatrix> getCostMatrices();

	/*! \brief Set An array of cost matrices
	 */
	void setCostMatrices(std::list <CostMatrix> cost_matrices);
	/*! \brief Get 
	 */
	Configuration getConfiguration();

	/*! \brief Set 
	 */
	void setConfiguration(Configuration  configuration);

private:
	std::list <Vehicle>vehicles;
	std::list <VehicleType>vehicle_types;
	std::list <Service>services;
	std::list <Shipment>shipments;
	std::list <Relation>relations;
	Algorithm algorithm;
	std::list <Objective>objectives;
	std::list <CostMatrix>cost_matrices;
	Configuration configuration;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Request_H_ */
