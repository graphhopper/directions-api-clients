#ifndef _SolutionManager_H_
#define _SolutionManager_H_

#include <string>
#include <cstring>
#include <list>
#include <glib.h>
#include "Response.h"
#include "Error.h"

/** \defgroup Operations API Endpoints
 *  Classes containing all the functions for calling API endpoints
 *
 */

namespace Tizen{
namespace ArtikCloud {
/** \addtogroup Solution Solution
 * \ingroup Operations
 *  @{
 */
class SolutionManager {
public:
	SolutionManager();
	virtual ~SolutionManager();

/*! \brief Return the solution associated to the jobId. *Synchronous*
 *
 * This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 
 * \param key your API key *Required*
 * \param jobId Request solution with jobId *Required*
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool getSolutionSync(char * accessToken,
	std::string key, std::string jobId, 
	void(* handler)(Response, Error, void* )
	, void* userData);

/*! \brief Return the solution associated to the jobId. *Asynchronous*
 *
 * This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 
 * \param key your API key *Required*
 * \param jobId Request solution with jobId *Required*
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool getSolutionAsync(char * accessToken,
	std::string key, std::string jobId, 
	void(* handler)(Response, Error, void* )
	, void* userData);



	static std::string getBasePath()
	{
		return "https://graphhopper.com/api/1";
	}
};
/** @}*/

}
}
#endif /* SolutionManager_H_ */
