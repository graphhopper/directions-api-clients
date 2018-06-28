/*
 * RoutePoint.h
 *
 * 
 */

#ifndef _RoutePoint_H_
#define _RoutePoint_H_


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

class RoutePoint : public Object {
public:
	/*! \brief Constructor.
	 */
	RoutePoint();
	RoutePoint(char* str);

	/*! \brief Destructor.
	 */
	virtual ~RoutePoint();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::string getType();

	/*! \brief Set 
	 */
	void setType(std::string  type);
	/*! \brief Get 
	 */
	std::list<std::string> getCoordinates();

	/*! \brief Set 
	 */
	void setCoordinates(std::list <std::string> coordinates);

private:
	std::string type;
	std::list <std::string>coordinates;
	void __init();
	void __cleanup();

};
}
}

#endif /* _RoutePoint_H_ */
