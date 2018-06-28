/*
 * Detail.h
 *
 * 
 */

#ifndef _Detail_H_
#define _Detail_H_


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

class Detail : public Object {
public:
	/*! \brief Constructor.
	 */
	Detail();
	Detail(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Detail();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get id of unassigned service/shipment
	 */
	std::string getId();

	/*! \brief Set id of unassigned service/shipment
	 */
	void setId(std::string  id);
	/*! \brief Get reason code
	 */
	int getCode();

	/*! \brief Set reason code
	 */
	void setCode(int  code);
	/*! \brief Get human readable reason
	 */
	std::string getReason();

	/*! \brief Set human readable reason
	 */
	void setReason(std::string  reason);

private:
	std::string id;
	int code;
	std::string reason;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Detail_H_ */
