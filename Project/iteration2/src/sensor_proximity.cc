/**
 * @file sensor_proximity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_proximity.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorProximity::SensorProximity(player_params * player, double range):
  player_(player), range_(range), activated_(false) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorProximity::Accept(EventProximity * e) {
  // Determine if the sensor should be activated or inactivated.

  /*
   *  Check if distance between sensor and the approching entities(robots)
   *  is less than the range. If yes, sensorProximity activated and distance is
   *  calculated and later return in the output()
   *  Otherwise, not activated.
   */
}

// setter for activated_
void SensorProximity::activated(bool value) {
  activated_ = value;
}

// inRange() check if the approaching entites are in range, return boolean
// value
// no functionality yet
bool InRange(double range1, double range2) {
  return true;
}

// getter for activated_
bool SensorProximity::activated(void) {
  return activated_;
}

// check if sensor activated, emit message
int SensorProximity::Output() {
  if (activated_ = true)
    return 1;  // sensor activated, return calculated distance
  else
    return -1;   // sensor not activated
}

// the only thing changed is sensor activated_. Therefore, reset() only for
// activated_.
void SensorProximity::Reset() {
  activated(false);
} /* reset() */

NAMESPACE_END(csci3081);
