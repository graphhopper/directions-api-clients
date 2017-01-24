/*
 * SamiGHResponseInstructions.h
 * 
 * Contains information about the instructions for this route. The last instruction is always the Finish instruction and takes 0ms and 0meter. Keep in mind that instructions are currently under active development and can sometimes contain misleading information, so, make sure you always show an image of the map at the same time when navigating your users!
 */

#ifndef SamiGHResponseInstructions_H_
#define SamiGHResponseInstructions_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiGHResponseInstruction.h"
using Tizen::Base::Collection::IList;


namespace Swagger {

class SamiGHResponseInstructions: public SamiObject {
public:
    SamiGHResponseInstructions();
    SamiGHResponseInstructions(String* json);
    virtual ~SamiGHResponseInstructions();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiGHResponseInstructions* fromJson(String* obj);


private:
    };

} /* namespace Swagger */

#endif /* SamiGHResponseInstructions_H_ */
