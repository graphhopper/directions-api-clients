/*
 * Route.h
 *
 * 
 */

#ifndef _Route_H_
#define _Route_H_


#include <string>
#include "Activity.h"
#include "RoutePoint.h"
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

class Route : public Object {
public:
	/*! \brief Constructor.
	 */
	Route();
	Route(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Route();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get id of vehicle that operates route
	 */
	std::string getVehicleId();

	/*! \brief Set id of vehicle that operates route
	 */
	void setVehicleId(std::string  vehicle_id);
	/*! \brief Get distance of route in meter
	 */
	long long getDistance();

	/*! \brief Set distance of route in meter
	 */
	void setDistance(long long  distance);
	/*! \brief Get transport time of route in seconds
	 */
	long long getTransportTime();

	/*! \brief Set transport time of route in seconds
	 */
	void setTransportTime(long long  transport_time);
	/*! \brief Get completion time of route in seconds
	 */
	long long getCompletionTime();

	/*! \brief Set completion time of route in seconds
	 */
	void setCompletionTime(long long  completion_time);
	/*! \brief Get waiting time of route in seconds
	 */
	long long getWaitingTime();

	/*! \brief Set waiting time of route in seconds
	 */
	void setWaitingTime(long long  waiting_time);
	/*! \brief Get array of activities
	 */
	std::list<Activity> getActivities();

	/*! \brief Set array of activities
	 */
	void setActivities(std::list <Activity> activities);
	/*! \brief Get array of route planning points
	 */
	std::list<RoutePoint> getPoints();

	/*! \brief Set array of route planning points
	 */
	void setPoints(std::list <RoutePoint> points);

private:
	std::string vehicle_id;
	long long distance;
	long long transport_time;
	long long completion_time;
	long long waiting_time;
	std::list <Activity>activities;
	std::list <RoutePoint>points;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Route_H_ */
