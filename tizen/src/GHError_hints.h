/*
 * GHError_hints.h
 *
 * 
 */

#ifndef _GHError_hints_H_
#define _GHError_hints_H_


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

class GHError_hints : public Object {
public:
	/*! \brief Constructor.
	 */
	GHError_hints();
	GHError_hints(char* str);

	/*! \brief Destructor.
	 */
	virtual ~GHError_hints();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::string getMessage();

	/*! \brief Set 
	 */
	void setMessage(std::string  message);

private:
	std::string message;
	void __init();
	void __cleanup();

};
}
}

#endif /* _GHError_hints_H_ */
