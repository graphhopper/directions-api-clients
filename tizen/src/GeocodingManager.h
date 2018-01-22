#ifndef _GeocodingManager_H_
#define _GeocodingManager_H_

#include <string>
#include <cstring>
#include <list>
#include <glib.h>
#include "GHError.h"
#include "GeocodingResponse.h"
#include "Error.h"

/** \defgroup Operations API Endpoints
 *  Classes containing all the functions for calling API endpoints
 *
 */

namespace Tizen{
namespace ArtikCloud {
/** \addtogroup Geocoding Geocoding
 * \ingroup Operations
 *  @{
 */
class GeocodingManager {
public:
	GeocodingManager();
	virtual ~GeocodingManager();

/*! \brief Execute a Geocoding request. *Synchronous*
 *
 * This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 
 * \param key Get your key at graphhopper.com *Required*
 * \param q If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon.
 * \param locale Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
 * \param limit Specify the maximum number of returned results
 * \param reverse Set to true to do a reverse Geocoding request
 * \param point The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803
 * \param provider Can be either, default, nominatim, opencagedata
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool geocodeGetSync(char * accessToken,
	std::string key, std::string q, std::string locale, int limit, bool reverse, std::string point, std::string provider, 
	void(* handler)(GeocodingResponse, Error, void* )
	, void* userData);

/*! \brief Execute a Geocoding request. *Asynchronous*
 *
 * This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 
 * \param key Get your key at graphhopper.com *Required*
 * \param q If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon.
 * \param locale Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used.
 * \param limit Specify the maximum number of returned results
 * \param reverse Set to true to do a reverse Geocoding request
 * \param point The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803
 * \param provider Can be either, default, nominatim, opencagedata
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool geocodeGetAsync(char * accessToken,
	std::string key, std::string q, std::string locale, int limit, bool reverse, std::string point, std::string provider, 
	void(* handler)(GeocodingResponse, Error, void* )
	, void* userData);



	static std::string getBasePath()
	{
		return "https://graphhopper.com/api/1";
	}
};
/** @}*/

}
}
#endif /* GeocodingManager_H_ */
