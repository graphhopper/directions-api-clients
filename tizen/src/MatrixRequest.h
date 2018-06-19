/*
 * MatrixRequest.h
 *
 * 
 */

#ifndef _MatrixRequest_H_
#define _MatrixRequest_H_


#include <string>
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

class MatrixRequest : public Object {
public:
	/*! \brief Constructor.
	 */
	MatrixRequest();
	MatrixRequest(char* str);

	/*! \brief Destructor.
	 */
	virtual ~MatrixRequest();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format longitude,latitude.
	 */
	std::list<std::list> getPoints();

	/*! \brief Set Specifiy multiple points for which the weight-, route-, time- or distance-matrix should be calculated. In this case the starts are identical to the destinations. If there are N points, then NxN entries will be calculated. The order of the point parameter is important. Specify at least three points. Cannot be used together with from_point or to_point. Is a string with the format longitude,latitude.
	 */
	void setPoints(std::list <std::list> points);
	/*! \brief Get The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format longitude,latitude.
	 */
	std::list<std::list> getFromPoints();

	/*! \brief Set The starting points for the routes. E.g. if you want to calculate the three routes A-&gt;1, A-&gt;2, A-&gt;3 then you have one from_point parameter and three to_point parameters. Is a string with the format longitude,latitude.
	 */
	void setFromPoints(std::list <std::list> from_points);
	/*! \brief Get The destination points for the routes. Is a string with the format longitude,latitude.
	 */
	std::list<std::list> getToPoints();

	/*! \brief Set The destination points for the routes. Is a string with the format longitude,latitude.
	 */
	void setToPoints(std::list <std::list> to_points);
	/*! \brief Get Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&amp;out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
	 */
	std::list<std::string> getOutArrays();

	/*! \brief Set Specifies which arrays should be included in the response. Specify one or more of the following options 'weights', 'times', 'distances'. To specify more than one array use e.g. out_array=times&amp;out_array=distances. The units of the entries of distances are meters, of times are seconds and of weights is arbitrary and it can differ for different vehicles or versions of this API.
	 */
	void setOutArrays(std::list <std::string> out_arrays);
	/*! \brief Get Optional parameter. Specifies a hint for each point in the `points` array to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up.
	 */
	std::list<std::string> getPointHints();

	/*! \brief Set Optional parameter. Specifies a hint for each point in the `points` array to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up.
	 */
	void setPointHints(std::list <std::string> point_hints);
	/*! \brief Get More information for the `from_points` array. See `point_hints`
	 */
	std::list<std::string> getFromPointHints();

	/*! \brief Set More information for the `from_points` array. See `point_hints`
	 */
	void setFromPointHints(std::list <std::string> from_point_hints);
	/*! \brief Get More information for the `to_points` array. See `point_hints`
	 */
	std::list<std::string> getToPointHints();

	/*! \brief Set More information for the `to_points` array. See `point_hints`
	 */
	void setToPointHints(std::list <std::string> to_point_hints);
	/*! \brief Get The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc, see here for the details.
	 */
	std::string getVehicle();

	/*! \brief Set The vehicle for which the route should be calculated. Other vehicles are foot, small_truck etc, see here for the details.
	 */
	void setVehicle(std::string  vehicle);

private:
	std::list <std::list>points;
	std::list <std::list>from_points;
	std::list <std::list>to_points;
	std::list <std::string>out_arrays;
	std::list <std::string>point_hints;
	std::list <std::string>from_point_hints;
	std::list <std::string>to_point_hints;
	std::string vehicle;
	void __init();
	void __cleanup();

};
}
}

#endif /* _MatrixRequest_H_ */
