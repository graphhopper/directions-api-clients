#ifndef _MatrixManager_H_
#define _MatrixManager_H_

#include <string>
#include <cstring>
#include <list>
#include <glib.h>
#include "GHError.h"
#include "MatrixRequest.h"
#include "MatrixResponse.h"
#include "Error.h"

/** \defgroup Operations API Endpoints
 *  Classes containing all the functions for calling API endpoints
 *
 */

namespace Tizen{
namespace ArtikCloud {
/** \addtogroup Matrix Matrix
 * \ingroup Operations
 *  @{
 */
class MatrixManager {
public:
	MatrixManager();
	virtual ~MatrixManager();

/*! \brief Matrix API. *Synchronous*
 *
 * The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called 'via points', which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this. 
 * \param key Get your key at graphhopper.com *Required*
 * \param point Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude.
 * \param fromPoint The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude.
 * \param toPoint The destination points for the routes. Is a string with the format latitude,longitude.
 * \param outArray Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
 * \param vehicle The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool matrixGetSync(char * accessToken,
	std::string key, std::list<std::string> point, std::list<std::string> fromPoint, std::list<std::string> toPoint, std::list<std::string> outArray, std::string vehicle, 
	void(* handler)(MatrixResponse, Error, void* )
	, void* userData);

/*! \brief Matrix API. *Asynchronous*
 *
 * The Matrix API is part of the GraphHopper Directions API and with this API you can calculate many-to-many distances, times or routes a lot more efficient than calling the Routing API multiple times. In the Routing API we support multiple points, so called 'via points', which results in one route being calculated. The Matrix API results in NxM routes or more precise NxM weights, distances or times being calculated but is a lot faster compared to NxM single requests. The most simple example is a tourist trying to decide which pizza is close to him instead of using beeline distance she can calculate a 1x4 matrix. Or a delivery service in the need of often big NxN matrices to solve vehicle routing problems. E.g. the GraphHopper Route Optimization API uses the Matrix API under the hood to achieve this. 
 * \param key Get your key at graphhopper.com *Required*
 * \param point Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format latitude,longitude.
 * \param fromPoint The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format latitude,longitude.
 * \param toPoint The destination points for the routes. Is a string with the format latitude,longitude.
 * \param outArray Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
 * \param vehicle The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool matrixGetAsync(char * accessToken,
	std::string key, std::list<std::string> point, std::list<std::string> fromPoint, std::list<std::string> toPoint, std::list<std::string> outArray, std::string vehicle, 
	void(* handler)(MatrixResponse, Error, void* )
	, void* userData);


/*! \brief Matrix API Post. *Synchronous*
 *
 * The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request. 
 * \param key Get your key at graphhopper.com *Required*
 * \param body 
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool matrixPostSync(char * accessToken,
	std::string key, MatrixRequest body, 
	void(* handler)(MatrixResponse, Error, void* )
	, void* userData);

/*! \brief Matrix API Post. *Asynchronous*
 *
 * The GET request has an URL length limitation, which hurts for many locations per request. In those cases use a HTTP POST request with JSON data as input. The only parameter in the URL will be the key which stays in the URL. Both request scenarios are identically except that all singular parameter names are named as their plural for a POST request. 
 * \param key Get your key at graphhopper.com *Required*
 * \param body 
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool matrixPostAsync(char * accessToken,
	std::string key, MatrixRequest body, 
	void(* handler)(MatrixResponse, Error, void* )
	, void* userData);



	static std::string getBasePath()
	{
		return "https://graphhopper.com/api/1";
	}
};
/** @}*/

}
}
#endif /* MatrixManager_H_ */
