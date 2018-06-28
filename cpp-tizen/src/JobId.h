/*
 * JobId.h
 *
 * 
 */

#ifndef _JobId_H_
#define _JobId_H_


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

class JobId : public Object {
public:
	/*! \brief Constructor.
	 */
	JobId();
	JobId(char* str);

	/*! \brief Destructor.
	 */
	virtual ~JobId();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get unique id for your job/request with which you can fetch your solution
	 */
	std::string getJobId();

	/*! \brief Set unique id for your job/request with which you can fetch your solution
	 */
	void setJobId(std::string  job_id);

private:
	std::string job_id;
	void __init();
	void __cleanup();

};
}
}

#endif /* _JobId_H_ */
