/*
 * Routing.h
 *
 * 
 */

#ifndef _Routing_H_
#define _Routing_H_


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

class Routing : public Object {
public:
	/*! \brief Constructor.
	 */
	Routing();
	Routing(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Routing();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get indicates whether solution should come with route geometries
	 */
	bool getCalcPoints();

	/*! \brief Set indicates whether solution should come with route geometries
	 */
	void setCalcPoints(bool  calc_points);
	/*! \brief Get indicates whether historical traffic information should be considered
	 */
	bool getConsiderTraffic();

	/*! \brief Set indicates whether historical traffic information should be considered
	 */
	void setConsiderTraffic(bool  consider_traffic);
	/*! \brief Get specifies the data provider
	 */
	std::string getNetworkDataProvider();

	/*! \brief Set specifies the data provider
	 */
	void setNetworkDataProvider(std::string  network_data_provider);
	/*! \brief Get indicates whether matrix calculation should fail fast when points cannot be connected
	 */
	bool getFailFast();

	/*! \brief Set indicates whether matrix calculation should fail fast when points cannot be connected
	 */
	void setFailFast(bool  fail_fast);

private:
	bool calc_points;
	bool consider_traffic;
	std::string network_data_provider;
	bool fail_fast;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Routing_H_ */
