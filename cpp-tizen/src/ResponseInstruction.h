/*
 * ResponseInstruction.h
 *
 * 
 */

#ifndef _ResponseInstruction_H_
#define _ResponseInstruction_H_


#include <string>
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

class ResponseInstruction : public Object {
public:
	/*! \brief Constructor.
	 */
	ResponseInstruction();
	ResponseInstruction(char* str);

	/*! \brief Destructor.
	 */
	virtual ~ResponseInstruction();

	/*! \brief Retrieve a string JSON representation of this class.
	 */
	char* toJson();

	/*! \brief Fills in members of this class from JSON string representing it.
	 */
	void fromJson(char* jsonStr);

	/*! \brief Get A description what the user has to do in order to follow the route. The language depends on the locale parameter.
	 */
	std::string getText();

	/*! \brief Set A description what the user has to do in order to follow the route. The language depends on the locale parameter.
	 */
	void setText(std::string  text);
	/*! \brief Get The name of the street to turn onto in order to follow the route.
	 */
	std::string getStreetName();

	/*! \brief Set The name of the street to turn onto in order to follow the route.
	 */
	void setStreetName(std::string  street_name);
	/*! \brief Get The distance for this instruction, in meter
	 */
	double getDistance();

	/*! \brief Set The distance for this instruction, in meter
	 */
	void setDistance(double  distance);
	/*! \brief Get The duration for this instruction, in ms
	 */
	int getTime();

	/*! \brief Set The duration for this instruction, in ms
	 */
	void setTime(int  time);
	/*! \brief Get An array containing the first and the last index (relative to paths[0].points) of the points for this instruction. This is useful to know for which part of the route the instructions are valid.
	 */
	std::list<int> getInterval();

	/*! \brief Set An array containing the first and the last index (relative to paths[0].points) of the points for this instruction. This is useful to know for which part of the route the instructions are valid.
	 */
	void setInterval(std::list <int> interval);
	/*! \brief Get A number which specifies the sign to show e.g. for right turn etc <br>TURN_SHARP_LEFT = -3<br>TURN_LEFT = -2<br>TURN_SLIGHT_LEFT = -1<br>CONTINUE_ON_STREET = 0<br>TURN_SLIGHT_RIGHT = 1<br>TURN_RIGHT = 2<br>TURN_SHARP_RIGHT = 3<br>FINISH = 4<br>VIA_REACHED = 5<br>USE_ROUNDABOUT = 6
	 */
	int getSign();

	/*! \brief Set A number which specifies the sign to show e.g. for right turn etc <br>TURN_SHARP_LEFT = -3<br>TURN_LEFT = -2<br>TURN_SLIGHT_LEFT = -1<br>CONTINUE_ON_STREET = 0<br>TURN_SLIGHT_RIGHT = 1<br>TURN_RIGHT = 2<br>TURN_SHARP_RIGHT = 3<br>FINISH = 4<br>VIA_REACHED = 5<br>USE_ROUNDABOUT = 6
	 */
	void setSign(int  sign);
	/*! \brief Get optional - A text describing the instruction in more detail, e.g. like surface of the way, warnings or involved costs.
	 */
	std::string getAnnotationText();

	/*! \brief Set optional - A text describing the instruction in more detail, e.g. like surface of the way, warnings or involved costs.
	 */
	void setAnnotationText(std::string  annotation_text);
	/*! \brief Get optional - 0 stands for INFO, 1 for warning, 2 for costs, 3 for costs and warning
	 */
	int getAnnotationImportance();

	/*! \brief Set optional - 0 stands for INFO, 1 for warning, 2 for costs, 3 for costs and warning
	 */
	void setAnnotationImportance(int  annotation_importance);
	/*! \brief Get optional - Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout.
	 */
	int getExitNumber();

	/*! \brief Set optional - Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout.
	 */
	void setExitNumber(int  exit_number);
	/*! \brief Get optional - Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout - 0&lt;r&lt;2*PI for clockwise and -2PI&lt;r&lt;0 for counterclockwise transit. Null if the direction of rotation is undefined.
	 */
	double getTurnAngle();

	/*! \brief Set optional - Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout - 0&lt;r&lt;2*PI for clockwise and -2PI&lt;r&lt;0 for counterclockwise transit. Null if the direction of rotation is undefined.
	 */
	void setTurnAngle(double  turn_angle);

private:
	std::string text;
	std::string street_name;
	double distance;
	int time;
	std::list <int>interval;
	int sign;
	std::string annotation_text;
	int annotation_importance;
	int exit_number;
	double turn_angle;
	void __init();
	void __cleanup();

};
}
}

#endif /* _ResponseInstruction_H_ */
