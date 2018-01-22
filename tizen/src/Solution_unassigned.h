/*
 * Solution_unassigned.h
 *
 * 
 */

#ifndef _Solution_unassigned_H_
#define _Solution_unassigned_H_


#include <string>
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

class Solution_unassigned : public Object {
public:
	/*! \brief Constructor.
	 */
	Solution_unassigned();
	Solution_unassigned(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Solution_unassigned();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get An array of ids of unassigned services
	 */
	std::list<std::string> getServices();

	/*! \brief Set An array of ids of unassigned services
	 */
	void setServices(std::list <std::string> services);
	/*! \brief Get An array of ids of unassigned shipments
	 */
	std::list<std::string> getShipments();

	/*! \brief Set An array of ids of unassigned shipments
	 */
	void setShipments(std::list <std::string> shipments);

private:
	std::list <std::string>services;
	std::list <std::string>shipments;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Solution_unassigned_H_ */
