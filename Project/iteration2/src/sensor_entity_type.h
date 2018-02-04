/**
 * @file sensor_entity_type.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_ENTITY_TYPE_H_
#define SRC_SENSOR_ENTITY_TYPE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>
#include <string>

#include "src/position.h"
#include "src/event_entitytype.h"
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
 * @brief A representation of a entity type sensor. Sensor has a range that
 * sense emit the type of the nearby entity. For our purposes, the output will
 * be the enumerated entity types of the entities that entered the defined
 * range.
 *
 */
class SensorEntityType : public Sensor {
 public:
  // Default constructor.
  SensorEntityType(player_params * player, double range);

  /**
   * @brief Get the current activation reading from the sensor.
   */
  bool activated(void) { return activated_; }
  void activated(bool value) { activated_ = value; }


  /**getter and setter for neme, use for getting the entity types when it is
  * sesored in range..
  */
  std::string name(void) { return name_; }
  void name(std::string n) {name_ = n;}

  /**
   * @brief Compute calculation of distance range between entities based on the
   * entity type emit event.
   *
   *
   */
  // output() is used for emit message depending on the sensor
  std::string Output(void);

  void Accept(EventEntityType * e);

  /**
   * @brief Reset the entity type sensor to its newly constructed state.
   */
  void Reset(void);

 private:
  double range_;  // range of sensing
  player_params * player_;
  bool activated_;
  std::string name_;
};

NAMESPACE_END(csci3081);

#endif   /* SRC_SENSOR_ENTITY_TYPE_H_ */
