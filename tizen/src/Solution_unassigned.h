/*
 * Solution_unassigned.h
 *
 * 
 */

#ifndef _Solution_unassigned_H_
#define _Solution_unassigned_H_


#include <string>
#include "Detail.h"
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
	/*! \brief Get An array of ids of unassigned breaks
	 */
	std::list<std::string> getBreaks();

	/*! \brief Set An array of ids of unassigned breaks
	 */
	void setBreaks(std::list <std::string> breaks);
	/*! \brief Get An array of details, i.e. reason for unassigned services or shipments
	 */
	std::list<Detail> getDetails();

	/*! \brief Set An array of details, i.e. reason for unassigned services or shipments
	 */
	void setDetails(std::list <Detail> details);

private:
	std::list <std::string>services;
	std::list <std::string>shipments;
	std::list <std::string>breaks;
	std::list <Detail>details;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Solution_unassigned_H_ */
