/*
 * Solution.h
 *
 * 
 */

#ifndef _Solution_H_
#define _Solution_H_


#include <string>
#include "Route.h"
#include "Solution_unassigned.h"
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

class Solution : public Object {
public:
	/*! \brief Constructor.
	 */
	Solution();
	Solution(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Solution();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get overall costs of solution
	 */
	int getCosts();

	/*! \brief Set overall costs of solution
	 */
	void setCosts(int  costs);
	/*! \brief Get overall travel distance in meters
	 */
	int getDistance();

	/*! \brief Set overall travel distance in meters
	 */
	void setDistance(int  distance);
	/*! \brief Get overall transport time in ms
	 */
	long long getTime();

	/*! \brief Set overall transport time in ms
	 */
	void setTime(long long  time);
	/*! \brief Get overall transport time in ms
	 */
	long long getTransportTime();

	/*! \brief Set overall transport time in ms
	 */
	void setTransportTime(long long  transport_time);
	/*! \brief Get operation time of the longest route in ms
	 */
	long long getMaxOperationTime();

	/*! \brief Set operation time of the longest route in ms
	 */
	void setMaxOperationTime(long long  max_operation_time);
	/*! \brief Get total waiting time in ms
	 */
	long long getWaitingTime();

	/*! \brief Set total waiting time in ms
	 */
	void setWaitingTime(long long  waiting_time);
	/*! \brief Get number of employed vehicles
	 */
	int getNoVehicles();

	/*! \brief Set number of employed vehicles
	 */
	void setNoVehicles(int  no_vehicles);
	/*! \brief Get number of jobs that could not be assigned to final solution
	 */
	int getNoUnassigned();

	/*! \brief Set number of jobs that could not be assigned to final solution
	 */
	void setNoUnassigned(int  no_unassigned);
	/*! \brief Get An array of routes
	 */
	std::list<Route> getRoutes();

	/*! \brief Set An array of routes
	 */
	void setRoutes(std::list <Route> routes);
	/*! \brief Get 
	 */
	Solution_unassigned getUnassigned();

	/*! \brief Set 
	 */
	void setUnassigned(Solution_unassigned  unassigned);

private:
	int costs;
	int distance;
	long long time;
	long long transport_time;
	long long max_operation_time;
	long long waiting_time;
	int no_vehicles;
	int no_unassigned;
	std::list <Route>routes;
	Solution_unassigned unassigned;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Solution_H_ */
