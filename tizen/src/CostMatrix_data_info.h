/*
 * CostMatrix_data_info.h
 *
 * Additional information for your request
 */

#ifndef _CostMatrix_data_info_H_
#define _CostMatrix_data_info_H_


#include <string>
#include <list>
#include "Object.h"

/** \defgroup Models Data Structures for API
 *  Classes containing all the Data Structures needed for calling/returned by API endpoints
 *
 */

namespace Tizen {
namespace ArtikCloud {


/*! \brief Additional information for your request
 *
 *  \ingroup Models
 *
 */

class CostMatrix_data_info : public Object {
public:
	/*! \brief Constructor.
	 */
	CostMatrix_data_info();
	CostMatrix_data_info(char* str);

	/*! \brief Destructor.
	 */
	virtual ~CostMatrix_data_info();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::list<std::string> getCopyrights();

	/*! \brief Set 
	 */
	void setCopyrights(std::list <std::string> copyrights);
	/*! \brief Get 
	 */
	double getTook();

	/*! \brief Set 
	 */
	void setTook(double  took);

private:
	std::list <std::string>copyrights;
	double took;
	void __init();
	void __cleanup();

};
}
}

#endif /* _CostMatrix_data_info_H_ */
