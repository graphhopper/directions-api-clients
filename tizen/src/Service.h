/*
 * Service.h
 *
 * 
 */

#ifndef _Service_H_
#define _Service_H_


#include <string>
#include "Address.h"
#include "TimeWindow.h"
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

class Service : public Object {
public:
	/*! \brief Constructor.
	 */
	Service();
	Service(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Service();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get Unique identifier of service
	 */
	std::string getId();

	/*! \brief Set Unique identifier of service
	 */
	void setId(std::string  id);
	/*! \brief Get type of service
	 */
	std::string getType();

	/*! \brief Set type of service
	 */
	void setType(std::string  type);
	/*! \brief Get priority of service
	 */
	int getPriority();

	/*! \brief Set priority of service
	 */
	void setPriority(int  priority);
	/*! \brief Get name of service
	 */
	std::string getName();

	/*! \brief Set name of service
	 */
	void setName(std::string  name);
	/*! \brief Get 
	 */
	Address getAddress();

	/*! \brief Set 
	 */
	void setAddress(Address  address);
	/*! \brief Get duration of service, i.e. time in ms the corresponding activity takes
	 */
	long long getDuration();

	/*! \brief Set duration of service, i.e. time in ms the corresponding activity takes
	 */
	void setDuration(long long  duration);
	/*! \brief Get preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location
	 */
	long long getPreparationTime();

	/*! \brief Set preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location
	 */
	void setPreparationTime(long long  preparation_time);
	/*! \brief Get array of time windows. currently, only a single time window is allowed
	 */
	std::list<TimeWindow> getTimeWindows();

	/*! \brief Set array of time windows. currently, only a single time window is allowed
	 */
	void setTimeWindows(std::list <TimeWindow> time_windows);
	/*! \brief Get array of capacity dimensions
	 */
	std::list<int> getSize();

	/*! \brief Set array of capacity dimensions
	 */
	void setSize(std::list <int> size);
	/*! \brief Get array of required skills
	 */
	std::list<std::string> getRequiredSkills();

	/*! \brief Set array of required skills
	 */
	void setRequiredSkills(std::list <std::string> required_skills);
	/*! \brief Get array of allowed vehicle ids
	 */
	std::list<std::string> getAllowedVehicles();

	/*! \brief Set array of allowed vehicle ids
	 */
	void setAllowedVehicles(std::list <std::string> allowed_vehicles);

private:
	std::string id;
	std::string type;
	int priority;
	std::string name;
	Address address;
	long long duration;
	long long preparation_time;
	std::list <TimeWindow>time_windows;
	std::list <int>size;
	std::list <std::string>required_skills;
	std::list <std::string>allowed_vehicles;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Service_H_ */
