/*
 * RouteResponse.h
 *
 * 
 */

#ifndef _RouteResponse_H_
#define _RouteResponse_H_


#include <string>
#include "ResponseInfo.h"
#include "RouteResponsePath.h"
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

class RouteResponse : public Object {
public:
	/*! \brief Constructor.
	 */
	RouteResponse();
	RouteResponse(char* str);

	/*! \brief Destructor.
	 */
	virtual ~RouteResponse();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::list<RouteResponsePath> getPaths();

	/*! \brief Set 
	 */
	void setPaths(std::list <RouteResponsePath> paths);
	/*! \brief Get 
	 */
	ResponseInfo getInfo();

	/*! \brief Set 
	 */
	void setInfo(ResponseInfo  info);

private:
	std::list <RouteResponsePath>paths;
	ResponseInfo info;
	void __init();
	void __cleanup();

};
}
}

#endif /* _RouteResponse_H_ */
