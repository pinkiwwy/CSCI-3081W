/**
 * @file event_proximity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_proximity.h"
#include "src/arena_mobile_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/

EventProximity::EventProximity(Position p) :
  pos_(p) {}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/* getter for pos - use for calculating the distance and see if the approaching
 * entities are in range
 */
Position EventProximity::get_pos(void) { return pos_; } /* get_pos() */



NAMESPACE_END(csci3081);
