/*
 * Break.h
 *
 * 
 */

#ifndef _Break_H_
#define _Break_H_


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

class Break : public Object {
public:
	/*! \brief Constructor.
	 */
	Break();
	Break(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Break();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get earliest start of break
	 */
	long long getEarliest();

	/*! \brief Set earliest start of break
	 */
	void setEarliest(long long  earliest);
	/*! \brief Get latest start of break
	 */
	long long getLatest();

	/*! \brief Set latest start of break
	 */
	void setLatest(long long  latest);
	/*! \brief Get duration of break
	 */
	long long getDuration();

	/*! \brief Set duration of break
	 */
	void setDuration(long long  duration);
	/*! \brief Get max driving time without break
	 */
	long long getMaxDrivingTime();

	/*! \brief Set max driving time without break
	 */
	void setMaxDrivingTime(long long  max_driving_time);
	/*! \brief Get initial driving time, i.e. the time your driver has already spent for driving
	 */
	long long getInitialDrivingTime();

	/*! \brief Set initial driving time, i.e. the time your driver has already spent for driving
	 */
	void setInitialDrivingTime(long long  initial_driving_time);
	/*! \brief Get array of splits
	 */
	std::list<long long> getPossibleSplit();

	/*! \brief Set array of splits
	 */
	void setPossibleSplit(std::list <long long> possible_split);

private:
	long long earliest;
	long long latest;
	long long duration;
	long long max_driving_time;
	long long initial_driving_time;
	std::list <long long>possible_split;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Break_H_ */
