/*
 * IsochroneResponse.h
 *
 * 
 */

#ifndef _IsochroneResponse_H_
#define _IsochroneResponse_H_


#include <string>
#include "IsochroneResponsePolygon.h"
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

class IsochroneResponse : public Object {
public:
	/*! \brief Constructor.
	 */
	IsochroneResponse();
	IsochroneResponse(char* str);

	/*! \brief Destructor.
	 */
	virtual ~IsochroneResponse();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get 
	 */
	std::list<IsochroneResponsePolygon> getPolygons();

	/*! \brief Set 
	 */
	void setPolygons(std::list <IsochroneResponsePolygon> polygons);
	/*! \brief Get 
	 */
	std::list<std::string> getCopyrights();

	/*! \brief Set 
	 */
	void setCopyrights(std::list <std::string> copyrights);

private:
	std::list <IsochroneResponsePolygon>polygons;
	std::list <std::string>copyrights;
	void __init();
	void __cleanup();

};
}
}

#endif /* _IsochroneResponse_H_ */
