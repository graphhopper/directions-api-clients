/*
 * Objective.h
 *
 * 
 */

#ifndef _Objective_H_
#define _Objective_H_


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

class Objective : public Object {
public:
	/*! \brief Constructor.
	 */
	Objective();
	Objective(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Objective();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get type of objective function, i.e. min or min-max 
	 */
	std::string getType();

	/*! \brief Set type of objective function, i.e. min or min-max 
	 */
	void setType(std::string  type);
	/*! \brief Get objective function value
	 */
	std::string getValue();

	/*! \brief Set objective function value
	 */
	void setValue(std::string  value);

private:
	std::string type;
	std::string value;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Objective_H_ */
