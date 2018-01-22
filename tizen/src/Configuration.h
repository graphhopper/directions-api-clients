/*
 * Configuration.h
 *
 * 
 */

#ifndef _Configuration_H_
#define _Configuration_H_


#include <string>
#include "Routing.h"
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

class Configuration : public Object {
public:
	/*! \brief Constructor.
	 */
	Configuration();
	Configuration(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Configuration();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	Routing getRouting();

	/*! \brief Set 
	 */
	void setRouting(Routing  routing);

private:
	Routing routing;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Configuration_H_ */
