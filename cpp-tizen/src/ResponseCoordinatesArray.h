/*
 * ResponseCoordinatesArray.h
 *
 * An array containing coordinates
 */

#ifndef _ResponseCoordinatesArray_H_
#define _ResponseCoordinatesArray_H_


#include <string>
#include <list>
#include "Object.h"

/** \defgroup Models Data Structures for API
 *  Classes containing all the Data Structures needed for calling/returned by API endpoints
 *
 */

namespace Tizen {
namespace ArtikCloud {


/*! \brief An array containing coordinates
 *
 *  \ingroup Models
 *
 */

class ResponseCoordinatesArray : public Object {
public:
	/*! \brief Constructor.
	 */
	ResponseCoordinatesArray();
	ResponseCoordinatesArray(char* str);

	/*! \brief Destructor.
	 */
	virtual ~ResponseCoordinatesArray();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);


private:
	void __init();
	void __cleanup();

};
}
}

#endif /* _ResponseCoordinatesArray_H_ */
