/**
 * @file sensor_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_PROXIMITY_H_
#define SRC_SENSOR_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/position.h"
#include "src/event_proximity.h"
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
 * @brief A representation of a proximity sensor. Sensor has a range and field
 * of view that sense objects. For our purposes, the output will be the distance
 * from any nearby obstacles. If no obstacles nearby, return -1.
 *
 */
class SensorProximity : public Sensor {
 public:
  // Default constructor.
  SensorProximity(player_params * player, double range);

  /**
   * @brief Get the current activation reading from the sensor.
   */
  bool activated(void);
  void activated(bool value);

   /** getter and setter for heading angle, radius and position. [updated] no need to use getter and setter here
   */

  // getter for heading angles, used for field of view.
  // double get_heading_angle() { return heading_angle_; }
  // void set_heading_angle(double ha) { heading_angle_=ha;}
  //
  //  //getter for radius, used for forming the sensor cone.
  // double get_radius() { return radius_; }
  // void set_radius(double rad) { radius_=rad;}
  //
  //


  // getter for position, use for calculate distance between entities
  Position get_pos(void);

  // inRange() check if the approaching entites are in range, return boolean
  // value
  bool InRange(double range1, double range2);
  /**
   * @brief Compute calculation of distance range between entities based on the
   * proximity event.
   *
   * Note that proximity events will return 1 if two entities are in
   * range. Or it will return -1 if not in range. [updated]: message not emitted
   * in accept()
   *
   */

  void Accept(EventProximity * e);

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
  void Reset(void);

  // emit message
  int Output(void);

 private:
  double range_;   // range of sensing
  player_params * player_;
  bool activated_;
  double dist;
};

NAMESPACE_END(csci3081);

#endif   /* SRC_SENSOR_PROXIMITY_H_ */
