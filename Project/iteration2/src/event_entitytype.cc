/**
 * @file event_entitytype.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_entitytype.h"
#include "src/arena_mobile_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/


EventEntityType::EventEntityType(Position p, std::string n) :
  pos_(p), name_(n) {}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/* getter for pos - use for calculating the distance and see if the approaching
 * entities are in range
 */
Position EventEntityType::get_pos(void) { return pos_; } /* get_pos() */

// get name
std::string EventEntityType::name(void) { return name_; }

NAMESPACE_END(csci3081);
