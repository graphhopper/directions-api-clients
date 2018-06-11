/*
 * Shipment.h
 *
 * 
 */

#ifndef _Shipment_H_
#define _Shipment_H_


#include <string>
#include "Stop.h"
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

class Shipment : public Object {
public:
	/*! \brief Constructor.
	 */
	Shipment();
	Shipment(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Shipment();

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
	/*! \brief Get name of shipment
	 */
	std::string getName();

	/*! \brief Set name of shipment
	 */
	void setName(std::string  name);
	/*! \brief Get priority of service, i.e. 1 = high, 2 = normal, 3 = low. default is 2.
	 */
	int getPriority();

	/*! \brief Set priority of service, i.e. 1 = high, 2 = normal, 3 = low. default is 2.
	 */
	void setPriority(int  priority);
	/*! \brief Get 
	 */
	Stop getPickup();

	/*! \brief Set 
	 */
	void setPickup(Stop  pickup);
	/*! \brief Get 
	 */
	Stop getDelivery();

	/*! \brief Set 
	 */
	void setDelivery(Stop  delivery);
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
	/*! \brief Get array of disallowed vehicle ids
	 */
	std::list<std::string> getDisallowedVehicles();

	/*! \brief Set array of disallowed vehicle ids
	 */
	void setDisallowedVehicles(std::list <std::string> disallowed_vehicles);
	/*! \brief Get max time shipment can stay in vehicle
	 */
	long long getMaxTimeInVehicle();

	/*! \brief Set max time shipment can stay in vehicle
	 */
	void setMaxTimeInVehicle(long long  max_time_in_vehicle);

private:
	std::string id;
	std::string name;
	int priority;
	Stop pickup;
	Stop delivery;
	std::list <int>size;
	std::list <std::string>required_skills;
	std::list <std::string>allowed_vehicles;
	std::list <std::string>disallowed_vehicles;
	long long max_time_in_vehicle;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Shipment_H_ */
