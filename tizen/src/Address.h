/*
 * Address.h
 *
 * 
 */

#ifndef _Address_H_
#define _Address_H_


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

class Address : public Object {
public:
	/*! \brief Constructor.
	 */
	Address();
	Address(char* str);

	/*! \brief Destructor.
	 */
	virtual ~Address();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get Unique identifier of location
	 */
	std::string getLocationId();

	/*! \brief Set Unique identifier of location
	 */
	void setLocationId(std::string  location_id);
	/*! \brief Get name of location, e.g. street name plus house number
	 */
	std::string getName();

	/*! \brief Set name of location, e.g. street name plus house number
	 */
	void setName(std::string  name);
	/*! \brief Get longitude
	 */
	double getLon();

	/*! \brief Set longitude
	 */
	void setLon(double  lon);
	/*! \brief Get latitude
	 */
	double getLat();

	/*! \brief Set latitude
	 */
	void setLat(double  lat);

private:
	std::string location_id;
	std::string name;
	double lon;
	double lat;
	void __init();
	void __cleanup();

};
}
}

#endif /* _Address_H_ */
