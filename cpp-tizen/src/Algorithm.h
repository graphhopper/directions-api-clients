/*
 * Algorithm.h
 *
 * 
 */

#ifndef _Algorithm_H_
#define _Algorithm_H_


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

class Algorithm : public Object {
public:
	/*! \brief Constructor.
	 */
	Algorithm();
	Algorithm(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Algorithm();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::string getProblemType();

	/*! \brief Set 
	 */
	void setProblemType(std::string  problem_type);
	/*! \brief Get 
	 */
	std::string getObjective();

	/*! \brief Set 
	 */
	void setObjective(std::string  objective);

private:
	std::string problem_type;
	std::string objective;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Algorithm_H_ */
