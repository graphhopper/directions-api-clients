/*
 * GeocodingResponse.h
 *
 * 
 */

#ifndef _GeocodingResponse_H_
#define _GeocodingResponse_H_


#include <string>
#include "GeocodingLocation.h"
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

class GeocodingResponse : public Object {
public:
	/*! \brief Constructor.
	 */
	GeocodingResponse();
	GeocodingResponse(char* str);

	/*! \brief Destructor.
	 */
	virtual ~GeocodingResponse();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::list<GeocodingLocation> getHits();

	/*! \brief Set 
	 */
	void setHits(std::list <GeocodingLocation> hits);
	/*! \brief Get 
	 */
	std::string getLocale();

	/*! \brief Set 
	 */
	void setLocale(std::string  locale);

private:
	std::list <GeocodingLocation>hits;
	std::string locale;
	void __init();
	void __cleanup();

};
}
}

#endif /* _GeocodingResponse_H_ */
