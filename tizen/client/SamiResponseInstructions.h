/*
 * SamiResponseInstructions.h
 * 
 * Contains information about the instructions for this route. The last instruction is always the Finish instruction and takes 0ms and 0meter. Keep in mind that instructions are currently under active development and can sometimes contain misleading information, so, make sure you always show an image of the map at the same time when navigating your users!
 */

#ifndef SamiResponseInstructions_H_
#define SamiResponseInstructions_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiResponseInstruction.h"
using Tizen::Base::Collection::IList;


namespace Swagger {

class SamiResponseInstructions: public SamiObject {
public:
    SamiResponseInstructions();
    SamiResponseInstructions(String* json);
    virtual ~SamiResponseInstructions();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiResponseInstructions* fromJson(String* obj);


private:
    };

} /* namespace Swagger */

#endif /* SamiResponseInstructions_H_ */
