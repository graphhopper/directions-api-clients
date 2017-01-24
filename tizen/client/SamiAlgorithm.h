/*
 * SamiAlgorithm.h
 * 
 * 
 */

#ifndef SamiAlgorithm_H_
#define SamiAlgorithm_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::String;


namespace Swagger {

class SamiAlgorithm: public SamiObject {
public:
    SamiAlgorithm();
    SamiAlgorithm(String* json);
    virtual ~SamiAlgorithm();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiAlgorithm* fromJson(String* obj);

    String* getPProblemType();
    void setPProblemType(String* pProblem_type);
    String* getPObjective();
    void setPObjective(String* pObjective);

private:
    String* pProblem_type;
String* pObjective;
};

} /* namespace Swagger */

#endif /* SamiAlgorithm_H_ */
