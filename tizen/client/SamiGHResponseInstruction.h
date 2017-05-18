/*
 * SamiGHResponseInstruction.h
 * 
 * 
 */

#ifndef SamiGHResponseInstruction_H_
#define SamiGHResponseInstruction_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Collection::IList;
using Tizen::Base::Double;
using Tizen::Base::Integer;
using Tizen::Base::String;


namespace Swagger {

class SamiGHResponseInstruction: public SamiObject {
public:
    SamiGHResponseInstruction();
    SamiGHResponseInstruction(String* json);
    virtual ~SamiGHResponseInstruction();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHResponseInstruction* fromJson(String* obj);

    String* getPText();
    void setPText(String* pText);
    String* getPStreetName();
    void setPStreetName(String* pStreet_name);
    Double* getPDistance();
    void setPDistance(Double* pDistance);
    Integer* getPTime();
    void setPTime(Integer* pTime);
    IList* getPInterval();
    void setPInterval(IList* pInterval);
    Integer* getPSign();
    void setPSign(Integer* pSign);
    String* getPAnnotationText();
    void setPAnnotationText(String* pAnnotation_text);
    Integer* getPAnnotationImportance();
    void setPAnnotationImportance(Integer* pAnnotation_importance);
    Integer* getPExitNumber();
    void setPExitNumber(Integer* pExit_number);
    Double* getPTurnAngle();
    void setPTurnAngle(Double* pTurn_angle);

private:
    String* pText;
String* pStreet_name;
Double* pDistance;
Integer* pTime;
IList* pInterval;
Integer* pSign;
String* pAnnotation_text;
Integer* pAnnotation_importance;
Integer* pExit_number;
Double* pTurn_angle;
};

} /* namespace Swagger */

#endif /* SamiGHResponseInstruction_H_ */
