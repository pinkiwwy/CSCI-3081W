/**
 * @file sensor_distress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_DISTRESS_H_
#define SRC_SENSOR_DISTRESS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/position.h"
#include "src/event_distress.h"
#include "src/sensor.h"
#include "src/arena_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/

/**
 * @brief A representation of a distress sensor. Sensor has a range that sense
 * robots nearby, but it has no sense about the coming direction. For our
 * purposes, the output will be 1 if distress call exists, and 0 if no robots
 * nearby.
 *
 */
class SensorDistress : public Sensor {
 public:
  // Default constructor.
   /*
    * Sensor is part of robot. Use sensorDistress to determine if this call
    * will activate sensor.
    */
  SensorDistress(player_params * player, double range);

  /**
   * @brief Get the current activation reading from the sensor.
   */
  bool activated(void);
  void activated(bool value);

   /** getter and setter for position and radius.
   * In SensorDistress, the sensor will sense if the distance between robots
   * is in range. If so, it is a distress call. The call will not be determining
   * the angle of direction.
   */

  // Updated: no need to have getter and setter for distress interface
   /**getter for radius, used for finding the range. Maybe having 2*radius as
   * the range for sensing.
   **/
  // double get_radius() { return radius_; }
  // void set_radius(double rad) { radius_=rad;}
  /** getter and setter for position, use for calculate distance between robots.
  * No direction in distress class, so no heading angle.
  */
  // Position get_pos(void) { return pos_; }
  // void set_pos(Position pos) { pos_ = pos; }

  /**
   * @brief Compute calculation of distance range between robots based on the
   * distress event.
   *
   * Note that proximity events will return 1 if there is in range distress
   * call. Or it will 0 as none.
   *
   */


  // output() is used for emit message depending on the sensor
  int Output(void);

  // check if EventDistressCall is accepted
  void Accept(EventDistressCall * e);

  /**
   * @brief Reset the distress sensor to its newly constructed state.
   */


  void Reset(void);

 private:
  double range_;  // range of sensing
  player_params * player_;
  bool activated_;
};

NAMESPACE_END(csci3081);

#endif   /* SRC_SENSOR_DISTRESS_H_ */
