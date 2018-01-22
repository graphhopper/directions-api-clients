/*
 * ResponseInstructions.h
 *
 * Contains information about the instructions for this route. The last instruction is always the Finish instruction and takes 0ms and 0meter. Keep in mind that instructions are currently under active development and can sometimes contain misleading information, so, make sure you always show an image of the map at the same time when navigating your users!
 */

#ifndef _ResponseInstructions_H_
#define _ResponseInstructions_H_


#include <string>
#include "ResponseInstruction.h"
#include <list>
#include "Object.h"

/** \defgroup Models Data Structures for API
 *  Classes containing all the Data Structures needed for calling/returned by API endpoints
 *
 */

namespace Tizen {
namespace ArtikCloud {


/*! \brief Contains information about the instructions for this route. The last instruction is always the Finish instruction and takes 0ms and 0meter. Keep in mind that instructions are currently under active development and can sometimes contain misleading information, so, make sure you always show an image of the map at the same time when navigating your users!
 *
 *  \ingroup Models
 *
 */

class ResponseInstructions : public Object {
public:
	/*! \brief Constructor.
	 */
	ResponseInstructions();
	ResponseInstructions(char* str);

	/*! \brief Destructor.
	 */
	virtual ~ResponseInstructions();

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

#endif /* _ResponseInstructions_H_ */
