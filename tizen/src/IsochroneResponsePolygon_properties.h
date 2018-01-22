/*
 * IsochroneResponsePolygon_properties.h
 *
 * 
 */

#ifndef _IsochroneResponsePolygon_properties_H_
#define _IsochroneResponsePolygon_properties_H_


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

class IsochroneResponsePolygon_properties : public Object {
public:
	/*! \brief Constructor.
	 */
	IsochroneResponsePolygon_properties();
	IsochroneResponsePolygon_properties(char* str);

	/*! \brief Destructor.
	 */
	virtual ~IsochroneResponsePolygon_properties();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	int getBucket();

	/*! \brief Set 
	 */
	void setBucket(int  bucket);

private:
	int bucket;
	void __init();
	void __cleanup();

};
}
}

#endif /* _IsochroneResponsePolygon_properties_H_ */
