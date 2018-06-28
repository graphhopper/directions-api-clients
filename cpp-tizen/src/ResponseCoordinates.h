/*
 * ResponseCoordinates.h
 *
 * 
 */

#ifndef _ResponseCoordinates_H_
#define _ResponseCoordinates_H_


#include <string>
#include "ResponseCoordinatesArray.h"
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

class ResponseCoordinates : public Object {
public:
	/*! \brief Constructor.
	 */
	ResponseCoordinates();
	ResponseCoordinates(char* str);

	/*! \brief Destructor.
	 */
	virtual ~ResponseCoordinates();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	ResponseCoordinatesArray getCoordinates();

	/*! \brief Set 
	 */
	void setCoordinates(ResponseCoordinatesArray  coordinates);

private:
	ResponseCoordinatesArray coordinates;
	void __init();
	void __cleanup();

};
}
}

#endif /* _ResponseCoordinates_H_ */
