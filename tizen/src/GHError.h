/*
 * GHError.h
 *
 * 
 */

#ifndef _GHError_H_
#define _GHError_H_


#include <string>
#include "GHError_hints.h"
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

class GHError : public Object {
public:
	/*! \brief Constructor.
	 */
	GHError();
	GHError(char* str);

	/*! \brief Destructor.
	 */
	virtual ~GHError();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	int getCode();

	/*! \brief Set 
	 */
	void setCode(int  code);
	/*! \brief Get 
	 */
	std::string getMessage();

	/*! \brief Set 
	 */
	void setMessage(std::string  message);
	/*! \brief Get 
	 */
	std::list<GHError_hints> getHints();

	/*! \brief Set 
	 */
	void setHints(std::list <GHError_hints> hints);

private:
	int code;
	std::string message;
	std::list <GHError_hints>hints;
	void __init();
	void __cleanup();

};
}
}

#endif /* _GHError_H_ */
