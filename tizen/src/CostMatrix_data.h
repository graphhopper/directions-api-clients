/*
 * CostMatrix_data.h
 *
 * JSON data of matrix response
 */

#ifndef _CostMatrix_data_H_
#define _CostMatrix_data_H_


#include <string>
#include "CostMatrix_data_info.h"
#include <list>
#include "Object.h"

/** \defgroup Models Data Structures for API
 *  Classes containing all the Data Structures needed for calling/returned by API endpoints
 *
 */

namespace Tizen {
namespace ArtikCloud {


/*! \brief JSON data of matrix response
 *
 *  \ingroup Models
 *
 */

class CostMatrix_data : public Object {
public:
	/*! \brief Constructor.
	 */
	CostMatrix_data();
	CostMatrix_data(char* str);

	/*! \brief Destructor.
	 */
	virtual ~CostMatrix_data();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::list<std::list> getTimes();

	/*! \brief Set 
	 */
	void setTimes(std::list <std::list> times);
	/*! \brief Get 
	 */
	std::list<std::list> getDistances();

	/*! \brief Set 
	 */
	void setDistances(std::list <std::list> distances);
	/*! \brief Get 
	 */
	CostMatrix_data_info getInfo();

	/*! \brief Set 
	 */
	void setInfo(CostMatrix_data_info  info);

private:
	std::list <std::list>times;
	std::list <std::list>distances;
	CostMatrix_data_info info;
	void __init();
	void __cleanup();

};
}
}

#endif /* _CostMatrix_data_H_ */
