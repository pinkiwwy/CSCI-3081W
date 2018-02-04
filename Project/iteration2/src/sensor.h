/**
 * @file sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_H_
#define SRC_SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "src/event_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/

/**
 * @brief Base class for sensors.
 *
 */
class Sensor {
 public:
  // Constructor.
  Sensor() : activated_(false) {}

  /**
   * @brief Set the current activation as deactivated.
   */

  virtual ~Sensor() = default;

  // getter and setter for sensor status
  bool activated() const { return activated_; }
  void activated(bool v) {
    activated_ = v;
  }

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
  virtual void Reset() = 0;

 private:
  bool activated_;
};

NAMESPACE_END(csci3081);

#endif   /* SRC_SENSOR_H_ */
