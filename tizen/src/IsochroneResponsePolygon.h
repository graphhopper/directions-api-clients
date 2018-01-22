/*
 * IsochroneResponsePolygon.h
 *
 * A found path
 */

#ifndef _IsochroneResponsePolygon_H_
#define _IsochroneResponsePolygon_H_


#include <string>
#include "IsochroneResponsePolygon_geometry.h"
#include "IsochroneResponsePolygon_properties.h"
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

class IsochroneResponsePolygon : public Object {
public:
	/*! \brief Constructor.
	 */
	IsochroneResponsePolygon();
	IsochroneResponsePolygon(char* str);

	/*! \brief Destructor.
	 */
	virtual ~IsochroneResponsePolygon();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	IsochroneResponsePolygon_properties getProperties();

	/*! \brief Set 
	 */
	void setProperties(IsochroneResponsePolygon_properties  properties);
	/*! \brief Get 
	 */
	std::string getType();

	/*! \brief Set 
	 */
	void setType(std::string  type);
	/*! \brief Get 
	 */
	IsochroneResponsePolygon_geometry getGeometry();

	/*! \brief Set 
	 */
	void setGeometry(IsochroneResponsePolygon_geometry  geometry);

private:
	IsochroneResponsePolygon_properties properties;
	std::string type;
	IsochroneResponsePolygon_geometry geometry;
	void __init();
	void __cleanup();

};
}
}

#endif /* _IsochroneResponsePolygon_H_ */
