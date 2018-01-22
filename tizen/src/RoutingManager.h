#ifndef _RoutingManager_H_
#define _RoutingManager_H_

#include <string>
#include <cstring>
#include <list>
#include <glib.h>
#include "GHError.h"
#include "RouteResponse.h"
#include "Error.h"

/** \defgroup Operations API Endpoints
 *  Classes containing all the functions for calling API endpoints
 *
 */

namespace Tizen{
namespace ArtikCloud {
/** \addtogroup Routing Routing
 * \ingroup Operations
 *  @{
 */
class RoutingManager {
public:
	RoutingManager();
	virtual ~RoutingManager();

/*! \brief Routing Request. *Synchronous*
 *
 * The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions
 * \param point Specify multiple points for which the route should be calculated. The order is important. Specify at least two points. *Required*
 * \param pointsEncoded IMPORTANT- TODO - currently you have to pass false for the swagger client - Have not found a way to force add a parameter. If `false` the coordinates in `point` and `snapped_waypoints` are returned as array using the order [lon,lat,elevation] for every point. If `true` the coordinates will be encoded as string leading to less bandwith usage. You'll need a special handling for the decoding of this string on the client-side. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/java/com/graphhopper/http/WebHelper.java#L43) and [JavaScript](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/webapp/js/ghrequest.js#L139). It is especially important to use no 3rd party client if you set `elevation=true`! *Required*
 * \param key Get your key at graphhopper.com *Required*
 * \param locale The locale of the resulting turn instructions. E.g. `pt_PT` for Portuguese or `de` for German
 * \param instructions If instruction should be calculated and returned
 * \param vehicle The vehicle for which the route should be calculated. Other vehicles are foot, small_truck, ...
 * \param elevation If `true` a third dimension - the elevation - is included in the polyline or in the GeoJson. If enabled you have to use a modified version of the decoding method or set points_encoded to `false`. See the points_encoded attribute for more details. Additionally a request can fail if the vehicle does not support elevation. See the features object for every vehicle.
 * \param calcPoints If the points for the route should be calculated at all printing out only distance and time.
 * \param pointHint Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up.
 * \param ch.disable Use this parameter in combination with one or more parameters of this table
 * \param weighting Which kind of 'best' route calculation you need. Other option is `shortest` (e.g. for `vehicle=foot` or `bike`), `short_fastest` if time and distance is expensive e.g. for `vehicle=truck`
 * \param edgeTraversal Use `true` if you want to consider turn restrictions for bike and motor vehicles. Keep in mind that the response time is roughly 2 times slower.
 * \param algorithm The algorithm to calculate the route. Other options are `dijkstra`, `astar`, `astarbi`, `alternative_route` and `round_trip`
 * \param heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with `algorithm=round_trip` and force the initial direction.
 * \param headingPenalty Penalty for omitting a specified heading. The penalty corresponds to the accepted time delay in seconds in comparison to the route without a heading.
 * \param passThrough If `true` u-turns are avoided at via-points with regard to the `heading_penalty`.
 * \param roundTrip.distance If `algorithm=round_trip` this parameter configures approximative length of the resulting round trip
 * \param roundTrip.seed If `algorithm=round_trip` this parameter introduces randomness if e.g. the first try wasn't good.
 * \param alternativeRoute.maxPaths If `algorithm=alternative_route` this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.
 * \param alternativeRoute.maxWeightFactor If `algorithm=alternative_route` this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.
 * \param alternativeRoute.maxShareFactor If `algorithm=alternative_route` this parameter specifies how much alternatives routes can have maximum in common with the optimal route. Increasing can lead to worse alternatives.
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool routeGetSync(char * accessToken,
	std::list<std::string> point, bool pointsEncoded, std::string key, std::string locale, bool instructions, std::string vehicle, bool elevation, bool calcPoints, std::list<std::string> pointHint, bool ch.disable, std::string weighting, bool edgeTraversal, std::string algorithm, int heading, int headingPenalty, bool passThrough, int roundTrip.distance, long long roundTrip.seed, int alternativeRoute.maxPaths, int alternativeRoute.maxWeightFactor, int alternativeRoute.maxShareFactor, 
	void(* handler)(RouteResponse, Error, void* )
	, void* userData);

/*! \brief Routing Request. *Asynchronous*
 *
 * The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions
 * \param point Specify multiple points for which the route should be calculated. The order is important. Specify at least two points. *Required*
 * \param pointsEncoded IMPORTANT- TODO - currently you have to pass false for the swagger client - Have not found a way to force add a parameter. If `false` the coordinates in `point` and `snapped_waypoints` are returned as array using the order [lon,lat,elevation] for every point. If `true` the coordinates will be encoded as string leading to less bandwith usage. You'll need a special handling for the decoding of this string on the client-side. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/java/com/graphhopper/http/WebHelper.java#L43) and [JavaScript](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/webapp/js/ghrequest.js#L139). It is especially important to use no 3rd party client if you set `elevation=true`! *Required*
 * \param key Get your key at graphhopper.com *Required*
 * \param locale The locale of the resulting turn instructions. E.g. `pt_PT` for Portuguese or `de` for German
 * \param instructions If instruction should be calculated and returned
 * \param vehicle The vehicle for which the route should be calculated. Other vehicles are foot, small_truck, ...
 * \param elevation If `true` a third dimension - the elevation - is included in the polyline or in the GeoJson. If enabled you have to use a modified version of the decoding method or set points_encoded to `false`. See the points_encoded attribute for more details. Additionally a request can fail if the vehicle does not support elevation. See the features object for every vehicle.
 * \param calcPoints If the points for the route should be calculated at all printing out only distance and time.
 * \param pointHint Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up.
 * \param ch.disable Use this parameter in combination with one or more parameters of this table
 * \param weighting Which kind of 'best' route calculation you need. Other option is `shortest` (e.g. for `vehicle=foot` or `bike`), `short_fastest` if time and distance is expensive e.g. for `vehicle=truck`
 * \param edgeTraversal Use `true` if you want to consider turn restrictions for bike and motor vehicles. Keep in mind that the response time is roughly 2 times slower.
 * \param algorithm The algorithm to calculate the route. Other options are `dijkstra`, `astar`, `astarbi`, `alternative_route` and `round_trip`
 * \param heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with `algorithm=round_trip` and force the initial direction.
 * \param headingPenalty Penalty for omitting a specified heading. The penalty corresponds to the accepted time delay in seconds in comparison to the route without a heading.
 * \param passThrough If `true` u-turns are avoided at via-points with regard to the `heading_penalty`.
 * \param roundTrip.distance If `algorithm=round_trip` this parameter configures approximative length of the resulting round trip
 * \param roundTrip.seed If `algorithm=round_trip` this parameter introduces randomness if e.g. the first try wasn't good.
 * \param alternativeRoute.maxPaths If `algorithm=alternative_route` this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives.
 * \param alternativeRoute.maxWeightFactor If `algorithm=alternative_route` this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives.
 * \param alternativeRoute.maxShareFactor If `algorithm=alternative_route` this parameter specifies how much alternatives routes can have maximum in common with the optimal route. Increasing can lead to worse alternatives.
 * \param handler The callback function to be invoked on completion. *Required*
 * \param accessToken The Authorization token. *Required*
 * \param userData The user data to be passed to the callback function.
 */
bool routeGetAsync(char * accessToken,
	std::list<std::string> point, bool pointsEncoded, std::string key, std::string locale, bool instructions, std::string vehicle, bool elevation, bool calcPoints, std::list<std::string> pointHint, bool ch.disable, std::string weighting, bool edgeTraversal, std::string algorithm, int heading, int headingPenalty, bool passThrough, int roundTrip.distance, long long roundTrip.seed, int alternativeRoute.maxPaths, int alternativeRoute.maxWeightFactor, int alternativeRoute.maxShareFactor, 
	void(* handler)(RouteResponse, Error, void* )
	, void* userData);



	static std::string getBasePath()
	{
		return "https://graphhopper.com/api/1";
	}
};
/** @}*/

}
}
#endif /* RoutingManager_H_ */
