/*
 * GeocodingPoint.h
 *
 * 
 */

#ifndef _GeocodingPoint_H_
#define _GeocodingPoint_H_


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

class GeocodingPoint : public Object {
public:
	/*! \brief Constructor.
	 */
	GeocodingPoint();
	GeocodingPoint(char* str);

	/*! \brief Destructor.
	 */
	virtual ~GeocodingPoint();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get Latitude
	 */
	double getLat();

	/*! \brief Set Latitude
	 */
	void setLat(double  lat);
	/*! \brief Get Longitude
	 */
	double getLng();

	/*! \brief Set Longitude
	 */
	void setLng(double  lng);

private:
	double lat;
	double lng;
	void __init();
	void __cleanup();

};
}
}

#endif /* _GeocodingPoint_H_ */
