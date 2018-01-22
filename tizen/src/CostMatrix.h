/*
 * CostMatrix.h
 *
 * 
 */

#ifndef _CostMatrix_H_
#define _CostMatrix_H_


#include <string>
#include "CostMatrix_data.h"
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

class CostMatrix : public Object {
public:
	/*! \brief Constructor.
	 */
	CostMatrix();
	CostMatrix(char* str);

	/*! \brief Destructor.
	 */
	virtual ~CostMatrix();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get type of cost matrix, currently default or google are supported
	 */
	std::string getType();

	/*! \brief Set type of cost matrix, currently default or google are supported
	 */
	void setType(std::string  type);
	/*! \brief Get URL of matrix service
	 */
	std::string getUrl();

	/*! \brief Set URL of matrix service
	 */
	void setUrl(std::string  url);
	/*! \brief Get 
	 */
	std::list<std::string> getLocationIds();

	/*! \brief Set 
	 */
	void setLocationIds(std::list <std::string> location_ids);
	/*! \brief Get 
	 */
	CostMatrix_data getData();

	/*! \brief Set 
	 */
	void setData(CostMatrix_data  data);
	/*! \brief Get vehicle profile or empty if catch all fallback
	 */
	std::string getProfile();

	/*! \brief Set vehicle profile or empty if catch all fallback
	 */
	void setProfile(std::string  profile);

private:
	std::string type;
	std::string url;
	std::list <std::string>location_ids;
	CostMatrix_data data;
	std::string profile;
	void __init();
	void __cleanup();

};
}
}

#endif /* _CostMatrix_H_ */
