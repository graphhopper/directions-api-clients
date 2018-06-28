/*
 * MatrixResponse.h
 *
 * 
 */

#ifndef _MatrixResponse_H_
#define _MatrixResponse_H_


#include <string>
#include "ResponseInfo.h"
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

class MatrixResponse : public Object {
public:
	/*! \brief Constructor.
	 */
	MatrixResponse();
	MatrixResponse(char* str);

	/*! \brief Destructor.
	 */
	virtual ~MatrixResponse();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::list<std::list> getDistances();

	/*! \brief Set 
	 */
	void setDistances(std::list <std::list> distances);
	/*! \brief Get 
	 */
	std::list<std::list> getTimes();

	/*! \brief Set 
	 */
	void setTimes(std::list <std::list> times);
	/*! \brief Get 
	 */
	std::list<std::list> getWeights();

	/*! \brief Set 
	 */
	void setWeights(std::list <std::list> weights);
	/*! \brief Get 
	 */
	ResponseInfo getInfo();

	/*! \brief Set 
	 */
	void setInfo(ResponseInfo  info);

private:
	std::list <std::list>distances;
	std::list <std::list>times;
	std::list <std::list>weights;
	ResponseInfo info;
	void __init();
	void __cleanup();

};
}
}

#endif /* _MatrixResponse_H_ */
