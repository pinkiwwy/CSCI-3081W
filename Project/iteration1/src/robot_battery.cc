/**
 * @file robot_battery.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include "src/robot_battery.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double RobotBattery::Deplete(__unused Position old_pos,
  __unused Position new_pos, __unused double dt) {
  /* @todo deplete battery by some value based on movement and speed */
   double temp = sqrt(pow(old_pos.x - new_pos.x,2)+pow(old_pos.y - new_pos.y,2));
   if (temp!=0 && charge_ != 0){
     charge_ = charge_ - kLINEAR_SCALE_FACTOR*temp;
     if (charge_ < 0){
       charge_ = 0;
     }
   }
   else if (temp ==0 && charge_ != 0 && dt !=0){
     charge_= charge_ - kBASE_DEPLETION;
     if (charge_ < 0){
       charge_ = 0;
     }
   }

  return charge_;
} /* deplete() */

void Accept(__unused EventCollision * e) {
  /* @todo deplete battery by some value -- arbitrary selected for bumping */
}


NAMESPACE_END(csci3081);
