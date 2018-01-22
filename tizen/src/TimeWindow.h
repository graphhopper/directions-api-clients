/*
 * TimeWindow.h
 *
 * 
 */

#ifndef _TimeWindow_H_
#define _TimeWindow_H_


#include <string>
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

class TimeWindow : public Object {
public:
	/*! \brief Constructor.
	 */
	TimeWindow();
	TimeWindow(char* str);

	/*! \brief Destructor.
	 */
	virtual ~TimeWindow();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get earliest start time of corresponding activity
	 */
	long long getEarliest();

	/*! \brief Set earliest start time of corresponding activity
	 */
	void setEarliest(long long  earliest);
	/*! \brief Get latest start time of corresponding activity
	 */
	long long getLatest();

	/*! \brief Set latest start time of corresponding activity
	 */
	void setLatest(long long  latest);

private:
	long long earliest;
	long long latest;
	void __init();
	void __cleanup();

};
}
}

#endif /* _TimeWindow_H_ */
