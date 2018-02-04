/**
 * @file event_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_ENTITYTYPE_H_
#define SRC_EVENT_ENTITYTYPE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include <string>
#include "src/event_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
// the EventEntityType is called in the accept() to get the position and name
// from the approaching object
class EventEntityType : public EventBaseClass {
 public:
  EventEntityType(Position p, std::string n);
  Position get_pos(void);
  std::string name(void);
// no EmitMessage needed in EventEntityType


 private:
  Position pos_;
  std::string name_;
};

NAMESPACE_END(csci3081);

#endif /* SRC_EVENT_PROXIMITY_H_ */
