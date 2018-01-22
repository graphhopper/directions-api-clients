/*
 * VehicleType.h
 *
 * 
 */

#ifndef _VehicleType_H_
#define _VehicleType_H_


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

class VehicleType : public Object {
public:
	/*! \brief Constructor.
	 */
	VehicleType();
	VehicleType(char* str);

	/*! \brief Destructor.
	 */
	virtual ~VehicleType();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get Unique identifier for the vehicle type
	 */
	std::string getTypeId();

	/*! \brief Set Unique identifier for the vehicle type
	 */
	void setTypeId(std::string  type_id);
	/*! \brief Get Profile of vehicle type
	 */
	std::string getProfile();

	/*! \brief Set Profile of vehicle type
	 */
	void setProfile(std::string  profile);
	/*! \brief Get array of capacity dimensions
	 */
	std::list<int> getCapacity();

	/*! \brief Set array of capacity dimensions
	 */
	void setCapacity(std::list <int> capacity);
	/*! \brief Get speed_factor of vehicle type
	 */
	double getSpeedFactor();

	/*! \brief Set speed_factor of vehicle type
	 */
	void setSpeedFactor(double  speed_factor);
	/*! \brief Get service time factor of vehicle type
	 */
	double getServiceTimeFactor();

	/*! \brief Set service time factor of vehicle type
	 */
	void setServiceTimeFactor(double  service_time_factor);
	/*! \brief Get cost parameter per distance unit, here meter is used
	 */
	double getCostPerMeter();

	/*! \brief Set cost parameter per distance unit, here meter is used
	 */
	void setCostPerMeter(double  cost_per_meter);
	/*! \brief Get cost parameter per time unit, here second is used
	 */
	double getCostPerSecond();

	/*! \brief Set cost parameter per time unit, here second is used
	 */
	void setCostPerSecond(double  cost_per_second);
	/*! \brief Get cost parameter vehicle activation, i.e. fixed costs per vehicle
	 */
	double getCostPerActivation();

	/*! \brief Set cost parameter vehicle activation, i.e. fixed costs per vehicle
	 */
	void setCostPerActivation(double  cost_per_activation);

private:
	std::string type_id;
	std::string profile;
	std::list <int>capacity;
	double speed_factor;
	double service_time_factor;
	double cost_per_meter;
	double cost_per_second;
	double cost_per_activation;
	void __init();
	void __cleanup();

};
}
}

#endif /* _VehicleType_H_ */
