/*
 * Response.h
 *
 * 
 */

#ifndef _Response_H_
#define _Response_H_


#include <string>
#include "Solution.h"
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

class Response : public Object {
public:
	/*! \brief Constructor.
	 */
	Response();
	Response(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Response();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::list<std::string> getCopyrights();

	/*! \brief Set 
	 */
	void setCopyrights(std::list <std::string> copyrights);
	/*! \brief Get unique identify of job - which you get when posting your request to the large problem solver
	 */
	std::string getJobId();

	/*! \brief Set unique identify of job - which you get when posting your request to the large problem solver
	 */
	void setJobId(std::string  job_id);
	/*! \brief Get indicates the current status of the job
	 */
	std::string getStatus();

	/*! \brief Set indicates the current status of the job
	 */
	void setStatus(std::string  status);
	/*! \brief Get waiting time in ms
	 */
	long long getWaitingInQueue();

	/*! \brief Set waiting time in ms
	 */
	void setWaitingInQueue(long long  waiting_in_queue);
	/*! \brief Get processing time in ms. if job is still waiting in queue, processing_time is 0
	 */
	long long getProcessingTime();

	/*! \brief Set processing time in ms. if job is still waiting in queue, processing_time is 0
	 */
	void setProcessingTime(long long  processing_time);
	/*! \brief Get 
	 */
	Solution getSolution();

	/*! \brief Set 
	 */
	void setSolution(Solution  solution);

private:
	std::list <std::string>copyrights;
	std::string job_id;
	std::string status;
	long long waiting_in_queue;
	long long processing_time;
	Solution solution;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Response_H_ */
