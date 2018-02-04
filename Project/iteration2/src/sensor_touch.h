/**
 * @file sensor_touch.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_TOUCH_H_
#define SRC_SENSOR_TOUCH_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/position.h"
#include "src/event_collision.h"
#include "src/sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/

/**
 * @brief A representation of a touch sensor. Touch or "bump" sensors are
 * "active" when pressed. For our purposes, imagine a series of bump sensors
 * around the perimeter of the robot. A collision will activate the sensor
 * at a particular point of contact, which translates to an angle of contact
 *
 */
class SensorTouch : public Sensor {
 public:
  // Default constructor.
  SensorTouch();

  /**
   * @brief Get the current activation reading from the sensor.
   */
  bool activated(void) { return activated_; }
  void activated(bool value) { activated_ = value; }


  // getter and setter for point of contact
  Position point_of_contact() { return point_of_contact_; }
  void point_of_contact(Position p) {
    point_of_contact_ = p;
  }

  // getter and setter for angle of contact
  double angle_of_contact(void) { return angle_of_contact_; }
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

  /**
   * @brief Compute a new reading based on the collision event.
   *
   * Note that collision events can emit 0 when no collision, and 1 when
   * collision is sensed.
   *
   */

  void Accept(EventCollision * e);

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
  void Reset(void);

  // check if sensor activated, emit message
  int Output();

 private:
  Position point_of_contact_;
  double angle_of_contact_;
  bool activated_;
};



NAMESPACE_END(csci3081);

#endif   /* SRC_SENSOR_TOUCH_H_ */
