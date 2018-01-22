/*
 * IsochroneResponsePolygon_geometry.h
 *
 * 
 */

#ifndef _IsochroneResponsePolygon_geometry_H_
#define _IsochroneResponsePolygon_geometry_H_


#include <string>
#include "ResponseCoordinatesArray.h"
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

class IsochroneResponsePolygon_geometry : public Object {
public:
	/*! \brief Constructor.
	 */
	IsochroneResponsePolygon_geometry();
	IsochroneResponsePolygon_geometry(char* str);

	/*! \brief Destructor.
	 */
	virtual ~IsochroneResponsePolygon_geometry();

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
	std::list<ResponseCoordinatesArray> getCoordinates();

	/*! \brief Set 
	 */
	void setCoordinates(std::list <ResponseCoordinatesArray> coordinates);

private:
	std::string type;
	std::list <ResponseCoordinatesArray>coordinates;
	void __init();
	void __cleanup();

};
}
}

#endif /* _IsochroneResponsePolygon_geometry_H_ */
