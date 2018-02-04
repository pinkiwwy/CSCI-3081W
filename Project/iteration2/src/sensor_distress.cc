/**
 * @file sensor_distress.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_distress.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorDistress::SensorDistress(player_params * player, double range):
  player_(player), range_(range), activated_(false) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorDistress::Accept(EventDistressCall * e) {
  // Determine if the sensor should be activated or inactivated.

  /*
   *  Check if distance between sensor and the approching entities(robots) is
   *  less than
   *  the range. If yes, sensorDistress activated. Otherwise, not activated.
   */
  if (std::sqrt (std::pow(e->get_pos().x-player_->pos.x, 2) +
  std::pow(e->get_pos().y-player_->pos.y, 2))  <= range_) {
    activated(true);
  } else {
    activated(false);
  }
}
// setter for activated_
void SensorDistress::activated(bool value) {
  activated_ = value;
}

// getter for activated_
bool SensorDistress::activated(void) {
  return activated_;
}

// check if sensor activated, emit message
int SensorDistress::Output() {
  if (activated_ = true)
    return 1;   // sensor activated
  else
    return 0;   // sensor not activated
}

// the only thing changed is sensor activated_.
// Therefore, reset() only for activated_.
void SensorDistress::Reset() {
  activated(false);
} /* reset() */

NAMESPACE_END(csci3081);
