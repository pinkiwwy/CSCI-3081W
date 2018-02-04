/**
 * @file event_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_PROXIMITY_H_
#define SRC_EVENT_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include "src/event_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
  class EventProximity : public EventBaseClass {
   public:
    explicit EventProximity(Position p);
    Position get_pos();

    // no EmitMessage needed in EventProximity

   private:
    Position pos_;
  };

NAMESPACE_END(csci3081);

#endif /* SRC_EVENT_PROXIMITY_H_ */
