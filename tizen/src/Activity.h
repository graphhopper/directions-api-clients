/*
 * Activity.h
 *
 * 
 */

#ifndef _Activity_H_
#define _Activity_H_


#include <string>
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

class Activity : public Object {
public:
	/*! \brief Constructor.
	 */
	Activity();
	Activity(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Activity();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get type of activity
	 */
	std::string getType();

	/*! \brief Set type of activity
	 */
	void setType(std::string  type);
	/*! \brief Get id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to
	 */
	std::string getId();

	/*! \brief Set id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to
	 */
	void setId(std::string  id);
	/*! \brief Get id that refers to address
	 */
	std::string getLocationId();

	/*! \brief Set id that refers to address
	 */
	void setLocationId(std::string  location_id);
	/*! \brief Get arrival time at this activity in ms
	 */
	long long getArrTime();

	/*! \brief Set arrival time at this activity in ms
	 */
	void setArrTime(long long  arr_time);
	/*! \brief Get end time of and thus departure time at this activity
	 */
	long long getEndTime();

	/*! \brief Set end time of and thus departure time at this activity
	 */
	void setEndTime(long long  end_time);
	/*! \brief Get waiting time at this activity in ms
	 */
	long long getWaitingTime();

	/*! \brief Set waiting time at this activity in ms
	 */
	void setWaitingTime(long long  waiting_time);
	/*! \brief Get cumulated distance from start to this activity in m
	 */
	long long getDistance();

	/*! \brief Set cumulated distance from start to this activity in m
	 */
	void setDistance(long long  distance);
	/*! \brief Get driving time of driver in ms
	 */
	long long getDrivingTime();

	/*! \brief Set driving time of driver in ms
	 */
	void setDrivingTime(long long  driving_time);
	/*! \brief Get Array with size/capacity dimensions before this activity
	 */
	std::list<int> getLoadBefore();

	/*! \brief Set Array with size/capacity dimensions before this activity
	 */
	void setLoadBefore(std::list <int> load_before);
	/*! \brief Get Array with size/capacity dimensions after this activity
	 */
	std::list<int> getLoadAfter();

	/*! \brief Set Array with size/capacity dimensions after this activity
	 */
	void setLoadAfter(std::list <int> load_after);

private:
	std::string type;
	std::string id;
	std::string location_id;
	long long arr_time;
	long long end_time;
	long long waiting_time;
	long long distance;
	long long driving_time;
	std::list <int>load_before;
	std::list <int>load_after;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Activity_H_ */
