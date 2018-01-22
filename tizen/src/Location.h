/*
 * Location.h
 *
 * 
 */

#ifndef _Location_H_
#define _Location_H_


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

class Location : public Object {
public:
	/*! \brief Constructor.
	 */
	Location();
	Location(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Location();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get longitude
	 */
	double getLon();

	/*! \brief Set longitude
	 */
	void setLon(double  lon);
	/*! \brief Get latitude
	 */
	double getLat();

	/*! \brief Set latitude
	 */
	void setLat(double  lat);

private:
	double lon;
	double lat;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Location_H_ */
