/*
 * Vehicle.h
 *
 * 
 */

#ifndef _Vehicle_H_
#define _Vehicle_H_


#include <string>
#include "Address.h"
#include "Break.h"
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

class Vehicle : public Object {
public:
	/*! \brief Constructor.
	 */
	Vehicle();
	Vehicle(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Vehicle();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get Unique identifier of vehicle
	 */
	std::string getVehicleId();

	/*! \brief Set Unique identifier of vehicle
	 */
	void setVehicleId(std::string  vehicle_id);
	/*! \brief Get Unique identifier referring to the available vehicle types
	 */
	std::string getTypeId();

	/*! \brief Set Unique identifier referring to the available vehicle types
	 */
	void setTypeId(std::string  type_id);
	/*! \brief Get 
	 */
	Address getStartAddress();

	/*! \brief Set 
	 */
	void setStartAddress(Address  start_address);
	/*! \brief Get 
	 */
	Address getEndAddress();

	/*! \brief Set 
	 */
	void setEndAddress(Address  end_address);
	/*! \brief Get 
	 */
	Break getBreak();

	/*! \brief Set 
	 */
	void setBreak(Break  _break);
	/*! \brief Get Indicates whether vehicle should return to start address or not. If not, it can end at any service activity.
	 */
	bool getReturnToDepot();

	/*! \brief Set Indicates whether vehicle should return to start address or not. If not, it can end at any service activity.
	 */
	void setReturnToDepot(bool  return_to_depot);
	/*! \brief Get earliest start of vehicle at its start location
	 */
	long long getEarliestStart();

	/*! \brief Set earliest start of vehicle at its start location
	 */
	void setEarliestStart(long long  earliest_start);
	/*! \brief Get latest end of vehicle at its end location
	 */
	long long getLatestEnd();

	/*! \brief Set latest end of vehicle at its end location
	 */
	void setLatestEnd(long long  latest_end);
	/*! \brief Get array of skills
	 */
	std::list<std::string> getSkills();

	/*! \brief Set array of skills
	 */
	void setSkills(std::list <std::string> skills);
	/*! \brief Get max distance of vehicle
	 */
	long long getMaxDistance();

	/*! \brief Set max distance of vehicle
	 */
	void setMaxDistance(long long  max_distance);

private:
	std::string vehicle_id;
	std::string type_id;
	Address start_address;
	Address end_address;
	Break _break;
	bool return_to_depot;
	long long earliest_start;
	long long latest_end;
	std::list <std::string>skills;
	long long max_distance;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Vehicle_H_ */
