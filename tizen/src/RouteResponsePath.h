/*
 * RouteResponsePath.h
 *
 * A found path
 */

#ifndef _RouteResponsePath_H_
#define _RouteResponsePath_H_


#include <string>
#include "ResponseCoordinates.h"
#include "ResponseInstructions.h"
#include <list>
#include "Object.h"

/** \defgroup Models Data Structures for API
 *  Classes containing all the Data Structures needed for calling/returned by API endpoints
 *
 */

namespace Tizen {
namespace ArtikCloud {


/*! \brief A found path
 *
 *  \ingroup Models
 *
 */

class RouteResponsePath : public Object {
public:
	/*! \brief Constructor.
	 */
	RouteResponsePath();
	RouteResponsePath(char* str);

	/*! \brief Destructor.
	 */
	virtual ~RouteResponsePath();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get The total distance of the route, in meter
	 */
	double getDistance();

	/*! \brief Set The total distance of the route, in meter
	 */
	void setDistance(double  distance);
	/*! \brief Get The total time of the route, in ms
	 */
	long long getTime();

	/*! \brief Set The total time of the route, in ms
	 */
	void setTime(long long  time);
	/*! \brief Get 
	 */
	double getAscend();

	/*! \brief Set 
	 */
	void setAscend(double  ascend);
	/*! \brief Get The total descend (downhill) of the route, in meter
	 */
	double getDescend();

	/*! \brief Set The total descend (downhill) of the route, in meter
	 */
	void setDescend(double  descend);
	/*! \brief Get 
	 */
	ResponseCoordinates getPoints();

	/*! \brief Set 
	 */
	void setPoints(ResponseCoordinates  points);
	/*! \brief Get Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version
	 */
	bool getPointsEncoded();

	/*! \brief Set Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version
	 */
	void setPointsEncoded(bool  points_encoded);
	/*! \brief Get The bounding box of the route, format <br> minLon, minLat, maxLon, maxLat
	 */
	std::list<double> getBbox();

	/*! \brief Set The bounding box of the route, format <br> minLon, minLat, maxLon, maxLat
	 */
	void setBbox(std::list <double> bbox);
	/*! \brief Get 
	 */
	ResponseCoordinates getSnappedWaypoints();

	/*! \brief Set 
	 */
	void setSnappedWaypoints(ResponseCoordinates  snapped_waypoints);
	/*! \brief Get 
	 */
	ResponseInstructions getInstructions();

	/*! \brief Set 
	 */
	void setInstructions(ResponseInstructions  instructions);

private:
	double distance;
	long long time;
	double ascend;
	double descend;
	ResponseCoordinates points;
	bool points_encoded;
	std::list <double>bbox;
	ResponseCoordinates snapped_waypoints;
	ResponseInstructions instructions;
	void __init();
	void __cleanup();

};
}
}

#endif /* _RouteResponsePath_H_ */
