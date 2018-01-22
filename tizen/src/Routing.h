/*
 * Routing.h
 *
 * 
 */

#ifndef _Routing_H_
#define _Routing_H_


#include <string>
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

class Routing : public Object {
public:
	/*! \brief Constructor.
	 */
	Routing();
	Routing(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Routing();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get indicates whether solution should come with route geometries
	 */
	bool getCalcPoints();

	/*! \brief Set indicates whether solution should come with route geometries
	 */
	void setCalcPoints(bool  calc_points);

private:
	bool calc_points;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Routing_H_ */
