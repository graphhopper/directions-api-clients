/*
 * Relation.h
 *
 * 
 */

#ifndef _Relation_H_
#define _Relation_H_


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

class Relation : public Object {
public:
	/*! \brief Constructor.
	 */
	Relation();
	Relation(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Relation();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get identifier of relation
	 */
	std::string getType();

	/*! \brief Set identifier of relation
	 */
	void setType(std::string  type);
	/*! \brief Get An array of ids that should be related
	 */
	std::list<std::string> getIds();

	/*! \brief Set An array of ids that should be related
	 */
	void setIds(std::list <std::string> ids);
	/*! \brief Get vehicle id
	 */
	std::string getVehicleId();

	/*! \brief Set vehicle id
	 */
	void setVehicleId(std::string  vehicle_id);

private:
	std::string type;
	std::list <std::string>ids;
	std::string vehicle_id;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Relation_H_ */
