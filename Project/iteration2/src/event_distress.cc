/**
 * @file event_distress.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_distress.h"
#include "src/arena_mobile_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/
/*
 *  The distress call was emitted in the arena when sensorDistress accept the
 * EventDistressCall.
 */

EventDistressCall::EventDistressCall(Position p, int id) :
  pos_(p), entity_id_(id) {}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/* getter for pos - use for calculating the distance and see if the approaching
 * entities are in range
 */
Position EventDistressCall::get_pos(void) { return pos_; } /* get_pos() */

// get entity id
int EventDistressCall::get_entity_id(void) { return entity_id_; }
// get_entity_id()

NAMESPACE_END(csci3081);
