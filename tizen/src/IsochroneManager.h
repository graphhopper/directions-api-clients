#ifndef _IsochroneManager_H_
#define _IsochroneManager_H_

#include <string>
#include <cstring>
#include <list>
#include <glib.h>
#include "GHError.h"
#include "IsochroneResponse.h"
#include "Error.h"

/** \defgroup Operations API Endpoints
 *  Classes containing all the functions for calling API endpoints
 *
 */

namespace Tizen{
namespace ArtikCloud {
/** \addtogroup Isochrone Isochrone
 * \ingroup Operations
 *  @{
 */
class IsochroneManager {
public:
	IsochroneManager();
	virtual ~IsochroneManager();

/*! \brief Isochrone Request. *Synchronous*
 *
 * The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 
 * \param point Specify the start coordinate *Required*
 * \param key Get your key at graphhopper.com *Required*
 * \param timeLimit Specify which time the vehicle should travel. In seconds.
 * \param distanceLimit Specify which distance the vehicle should travel. In meter.
 * \param vehicle Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/)
 * \param buckets For how many sub intervals an additional polygon should be calculated.
 * \param reverseFlow If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool isochroneGetSync(char * accessToken,
	std::string point, std::string key, int timeLimit, int distanceLimit, std::string vehicle, int buckets, bool reverseFlow, 
	void(* handler)(IsochroneResponse, Error, void* )
	, void* userData);

/*! \brief Isochrone Request. *Asynchronous*
 *
 * The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 
 * \param point Specify the start coordinate *Required*
 * \param key Get your key at graphhopper.com *Required*
 * \param timeLimit Specify which time the vehicle should travel. In seconds.
 * \param distanceLimit Specify which distance the vehicle should travel. In meter.
 * \param vehicle Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/)
 * \param buckets For how many sub intervals an additional polygon should be calculated.
 * \param reverseFlow If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.*
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool isochroneGetAsync(char * accessToken,
	std::string point, std::string key, int timeLimit, int distanceLimit, std::string vehicle, int buckets, bool reverseFlow, 
	void(* handler)(IsochroneResponse, Error, void* )
	, void* userData);



	static std::string getBasePath()
	{
		return "https://graphhopper.com/api/1";
	}
};
/** @}*/

}
}
#endif /* IsochroneManager_H_ */
