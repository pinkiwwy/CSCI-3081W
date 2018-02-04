/**
 * @file sensor_entity_type.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_entity_type.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorEntityType::SensorEntityType(player_params * player, double range):
  player_(player), range_(range), activated_(false) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorEntityType::Accept(EventEntityType * e) {
  // Determine if the sensor should be activated or inactivated.

  /*
   *  Check if distance between sensor and the approching entities(robots) is
   *  less than the range. If yes, SensorEntityType activated. Otherwise, not
   *  activated. It acts similar to sensorDistress, but the output is different.
   */
  if (std::sqrt (std::pow(e->get_pos().x-player_->pos.x, 2) +
  std::pow(e->get_pos().y-player_->pos.y, 2))  <= range_) {
    activated(true);
    name_ = e->name();
  } else {
    activated(false);
  }
}


// check if sensor activated, emit message
std::string SensorEntityType::Output() {
  if (activated_ = true)
    return name_;   // sensor activated, returned the entity types
  // enumerated type entity_type not setup yet. Only return name here
  // cannot return nothing
  // else
  //   return;   // sensor not activated, nothing return
}

// the only thing changed is sensor activated_.
// Therefore, reset() only for activated_.
void SensorEntityType::Reset() {
  activated(false);
} /* reset() */

NAMESPACE_END(csci3081);
