/*
 * Stop.h
 *
 * 
 */

#ifndef _Stop_H_
#define _Stop_H_


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

class Stop : public Object {
public:
	/*! \brief Constructor.
	 */
	Stop();
	Stop(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Stop();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	Address getAddress();

	/*! \brief Set 
	 */
	void setAddress(Address  address);
	/*! \brief Get duration of stop, i.e. time in ms the corresponding activity takes
	 */
	long long getDuration();

	/*! \brief Set duration of stop, i.e. time in ms the corresponding activity takes
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

private:
	Address address;
	long long duration;
	long long preparation_time;
	std::list <TimeWindow>time_windows;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Stop_H_ */
