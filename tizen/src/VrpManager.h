#ifndef _VrpManager_H_
#define _VrpManager_H_

#include <string>
#include <cstring>
#include <list>
#include <glib.h>
#include "JobId.h"
#include "Request.h"
#include "Error.h"

/** \defgroup Operations API Endpoints
 *  Classes containing all the functions for calling API endpoints
 *
 */

namespace Tizen{
namespace ArtikCloud {
/** \addtogroup Vrp Vrp
 * \ingroup Operations
 *  @{
 */
class VrpManager {
public:
	VrpManager();
	virtual ~VrpManager();

/*! \brief Solves vehicle routing problems. *Synchronous*
 *
 * This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.
 * \param key your API key *Required*
 * \param body Request object that contains the problem to be solved *Required*
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool postVrpSync(char * accessToken,
	std::string key, Request body, 
	void(* handler)(JobId, Error, void* )
	, void* userData);

/*! \brief Solves vehicle routing problems. *Asynchronous*
 *
 * This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution.
 * \param key your API key *Required*
 * \param body Request object that contains the problem to be solved *Required*
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool postVrpAsync(char * accessToken,
	std::string key, Request body, 
	void(* handler)(JobId, Error, void* )
	, void* userData);



	static std::string getBasePath()
	{
		return "https://graphhopper.com/api/1";
	}
};
/** @}*/

}
}
#endif /* VrpManager_H_ */
