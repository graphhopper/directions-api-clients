/*
 * GeocodingLocation.h
 *
 * 
 */

#ifndef _GeocodingLocation_H_
#define _GeocodingLocation_H_


#include <string>
#include "GeocodingPoint.h"
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

class GeocodingLocation : public Object {
public:
	/*! \brief Constructor.
	 */
	GeocodingLocation();
	GeocodingLocation(char* str);

	/*! \brief Destructor.
	 */
	virtual ~GeocodingLocation();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	GeocodingPoint getPoint();

	/*! \brief Set 
	 */
	void setPoint(GeocodingPoint  point);
	/*! \brief Get OSM Id
	 */
	std::string getOsmId();

	/*! \brief Set OSM Id
	 */
	void setOsmId(std::string  osm_id);
	/*! \brief Get N = node, R = relation, W = way
	 */
	std::string getOsmType();

	/*! \brief Set N = node, R = relation, W = way
	 */
	void setOsmType(std::string  osm_type);
	/*! \brief Get The osm key of the result like `place` or `amenity`
	 */
	std::string getOsmKey();

	/*! \brief Set The osm key of the result like `place` or `amenity`
	 */
	void setOsmKey(std::string  osm_key);
	/*! \brief Get 
	 */
	std::string getName();

	/*! \brief Set 
	 */
	void setName(std::string  name);
	/*! \brief Get 
	 */
	std::string getCountry();

	/*! \brief Set 
	 */
	void setCountry(std::string  country);
	/*! \brief Get 
	 */
	std::string getCity();

	/*! \brief Set 
	 */
	void setCity(std::string  city);
	/*! \brief Get 
	 */
	std::string getState();

	/*! \brief Set 
	 */
	void setState(std::string  state);
	/*! \brief Get 
	 */
	std::string getStreet();

	/*! \brief Set 
	 */
	void setStreet(std::string  street);
	/*! \brief Get 
	 */
	std::string getHousenumber();

	/*! \brief Set 
	 */
	void setHousenumber(std::string  housenumber);
	/*! \brief Get 
	 */
	std::string getPostcode();

	/*! \brief Set 
	 */
	void setPostcode(std::string  postcode);

private:
	GeocodingPoint point;
	std::string osm_id;
	std::string osm_type;
	std::string osm_key;
	std::string name;
	std::string country;
	std::string city;
	std::string state;
	std::string street;
	std::string housenumber;
	std::string postcode;
	void __init();
	void __cleanup();

};
}
}

#endif /* _GeocodingLocation_H_ */
