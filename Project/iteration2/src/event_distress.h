/**
 * @file event_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_DISTRESS_H_
#define SRC_EVENT_DISTRESS_H_

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
class EventDistressCall : public EventBaseClass {
 public:
  EventDistressCall(Position p, int id);
  Position get_pos();
  int get_entity_id();
// no EmitMessage needed in EventDistressCall


 private:
  Position pos_;
  int entity_id_;
};

NAMESPACE_END(csci3081);

#endif /* SRC_EVENT_PROXIMITY_H_ */
