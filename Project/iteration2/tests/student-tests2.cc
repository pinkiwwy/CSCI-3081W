/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/sensor_touch.h"
#include "../src/sensor_proximity.h"
#include "../src/sensor_distress.h"
#include "../src/sensor_entity_type.h"

//#ifdef STUDENT_TESTS2_TEST

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
/**
* SensorTouch tests
*/
TEST(SensorTouch, Sanity) {
  csci3081::SensorTouch st;
  csci3081::Position *p;

  bool val = std::is_base_of<csci3081::Sensor, csci3081::SensorTouch>::value;
  EXPECT_TRUE(val);

  EXPECT_EQ(st.activated(), false);
  EXPECT_EQ(st.angle_of_contact(), 0.0);
  st.activated(true);
  EXPECT_EQ(st.activated(), true);

}

//test for getter and setter for point of contact
// TEST(SensorTouch, point_of_contact){
//   csci3081::SensorTouch *st;
//   csci3081::Position *p;
//   // st->point_of_contact_ = p(2.0,2.0);    //position type error
//   // EXPECT_EQ(st->point_of_contact(), p);
// }

//test for getter and setter for angle of contact
TEST(SensorTouch, angle_of_contact){
  csci3081::SensorTouch st;
  st.angle_of_contact(2.0);  //setter
  EXPECT_EQ(st.angle_of_contact(), 2.0); //getter
}

//test for activated
TEST(SensorTouch, activated){
  csci3081::SensorTouch st;
  st.activated(true);
  EXPECT_EQ(st.activated(), true); //activated_ become true
  st.activated(false);
  EXPECT_EQ(st.activated(), false); //activated_ become false
}


TEST(SensorTouch, Reset) {
  csci3081::SensorTouch st;
  csci3081::Position p;
  st.activated(true);
  // st->point_of_contact() = p(1.0, 1.0);
  EXPECT_EQ(st.activated(), true);
  // EXPECT_EQ(st->point_of_contact(), p);
  EXPECT_DOUBLE_EQ(st.angle_of_contact(), 45.0);

  st.Reset();
  EXPECT_EQ(st.angle_of_contact(), 0.0);
  // EXPECT_EQ(st->point_of_contact(), p);
  EXPECT_EQ(st.activated(), false);
}

TEST(SensorTouch, Output){
  csci3081::SensorTouch st;
  st.activated(true);
  EXPECT_EQ(st.Output(), 1);
  st.activated(false);
  EXPECT_EQ(st.Output(), 0);
}

/**
* SensorProximity tests
*/
 TEST(SensorProximity, Sanity) {
   csci3081::robot_params params;
   csci3081::Position p;
   params.pos = p;
   params.angle_delta = 15;
   params.battery_max_charge = 100;
   params.collision_delta = 0.1;
   params.radius = 5.0;

   csci3081::SensorProximity sp(&params, 50);

   bool val = std::is_base_of<csci3081::Sensor, csci3081::SensorProximity>::value;
   EXPECT_TRUE(val);
   //from constructor
   EXPECT_EQ(sp.activated(), false);
   sp.activated(true);
   EXPECT_EQ(sp.activated(), true);
 }


 //test for activated
 TEST(SensorProximity, activated){
   csci3081::robot_params params;
   csci3081::Position p;
   params.pos = p;
   params.angle_delta = 15;
   params.battery_max_charge = 100;
   params.collision_delta = 0.1;
   params.radius = 5.0;

   csci3081::SensorProximity sp(&params, 50);
   sp.activated(true);
   EXPECT_EQ(sp.activated(), true); //return true, sensor activated
   sp.activated(false);
   EXPECT_EQ(sp.activated(), false); //return false, sensor unactivated
 }

 //reset function reset everything to default in constructor
 TEST(SensorProximity, Reset) {
   csci3081::robot_params params;
   csci3081::Position p;
   params.pos = p;
   params.angle_delta = 15;
   params.battery_max_charge = 100;
   params.collision_delta = 0.1;
   params.radius = 5.0;

   csci3081::SensorProximity sp(&params, 50);
   //before reset, only activated_ has been changed
   sp.activated(true);

   EXPECT_EQ(sp.activated(), true);
   sp.Reset();
   EXPECT_EQ(sp.activated(), false);
 }

 TEST(SensorProximity, Output) {
   csci3081::robot_params params;
   csci3081::Position p;
   params.pos = p;
   params.angle_delta = 15;
   params.battery_max_charge = 100;
   params.collision_delta = 0.1;
   params.radius = 5.0;

   csci3081::SensorProximity sp(&params, 50);
   //before reset, only activated_ has been changed
   sp.activated(true);

   EXPECT_EQ(sp.Output(), 1);
   sp.Reset();
   EXPECT_EQ(sp.Output(), 0);
 }

/**
* SensorDistress tests
*/
TEST(SensorDistress, Sanity) {
  csci3081::robot_params params;
  csci3081::Position p;
  params.pos = p;
  params.angle_delta = 15;
  params.battery_max_charge = 100;
  params.collision_delta = 0.1;
  params.radius = 5.0;

  csci3081::SensorDistress sd(&params, 50);

  bool val = std::is_base_of<csci3081::Sensor, csci3081::SensorDistress>::value;
  EXPECT_TRUE(val);
  //from constructor
  EXPECT_EQ(sd.activated(), false);
  sd.activated(true);
  EXPECT_EQ(sd.activated(), true);
}

/*
 *  check for accept function. Sensor will be either activated or deactivated after
 *  accepting the EventDistressCall
 */
TEST(SensorDistress, accept){
  csci3081::robot_params params;
  csci3081::Position p;
  params.pos = p;
  params.angle_delta = 15;
  params.battery_max_charge = 100;
  params.collision_delta = 0.1;
  params.radius = 5.0;

//position and id are not working for EventDistressCall
  // csci3081::SensorDistress sd(&params, 50);
  // csci3081::EventDistressCall e;
  // e.pos_ = p;
  // e.id_ = 1;
  // sd.Accept(e);
  // EXPECT_EQ(sd.activated(), true);

}


//test for activate sensor
TEST(SensorDistress, activated){

  csci3081::robot_params params;
  csci3081::Position p;
  params.pos = p;
  params.angle_delta = 15;
  params.battery_max_charge = 100;
  params.collision_delta = 0.1;
  params.radius = 5.0;

  csci3081::SensorDistress sd(&params, 50);

  bool val = std::is_base_of<csci3081::Sensor, csci3081::SensorDistress>::value;
  EXPECT_TRUE(val);
  //from constructor
  EXPECT_EQ(sd.activated(), false);
  sd.activated(true);
  EXPECT_EQ(sd.activated(), true);  //set sensor to activated
  sd.activated(false);
  EXPECT_EQ(sd.activated(), false); //set sensor to deactivated
}

//reset function reset everything to default in constructor
TEST(SensorDistress, Reset) {
  csci3081::robot_params params;
  csci3081::Position p;
  params.pos = p;
  params.angle_delta = 15;
  params.battery_max_charge = 100;
  params.collision_delta = 0.1;
  params.radius = 5.0;

  csci3081::SensorDistress sd(&params, 50);
  //before reset, activated_ not in default setting
  sd.activated(true);

  EXPECT_EQ(sd.activated(), true);
  sd.Reset();
  EXPECT_EQ(sd.activated(), false);

}

//test if sensor activated or deactivated will print out the right output
TEST(SensorDistress, Output){
  csci3081::robot_params params;
  csci3081::Position p;
  params.pos = p;
  params.angle_delta = 15;
  params.battery_max_charge = 100;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::SensorDistress sd(&params, 50);
  sd.activated(true);
  EXPECT_EQ(sd.Output(), 1);
  sd.activated(false);
  EXPECT_EQ(sd.Output(), 0);
}


/**
* SensorEntityType tests
// */
TEST(SensorEntityType, Sanity) {
  csci3081::robot_params params;
  csci3081::Position p;
  params.pos = p;
  params.angle_delta = 15;
  params.battery_max_charge = 100;
  params.collision_delta = 0.1;
  params.radius = 5.0;

  csci3081::SensorEntityType se(&params, 50);

  bool val = std::is_base_of<csci3081::Sensor, csci3081::SensorEntityType>::value;
  EXPECT_TRUE(val);
  //from constructor
  EXPECT_EQ(se.activated(), false);
  se.activated(true);
  EXPECT_EQ(se.activated(), true);
}


//test for activate sensor
TEST(SensorEntityType, activate){
  csci3081::robot_params params;
  csci3081::Position p;
  params.pos = p;
  params.angle_delta = 15;
  params.battery_max_charge = 100;
  params.collision_delta = 0.1;
  params.radius = 5.0;

  csci3081::SensorEntityType se(&params, 50);
  se.activated(true);

  EXPECT_EQ(se.activated(), true); //return true if sensor activated

  se.activated(false);
  EXPECT_EQ(se.activated(), false); //return false if sensor not activated
}

//reset function reset everything to default in constructor
TEST(SensorEntityType, Reset) {
  csci3081::robot_params params;
  csci3081::Position p;
  params.pos = p;
  params.angle_delta = 15;
  params.battery_max_charge = 100;
  params.collision_delta = 0.1;
  params.radius = 5.0;

  csci3081::SensorEntityType se(&params, 50);
  se.activated(true);
  EXPECT_EQ(se.activated(), true);

  se.Reset();
  EXPECT_EQ(se.activated(), false);
}

/*
 *  Fail to assign name for EventEntityType. Output() cannot be tested.
 */
// TEST(SensorEntityType, Output) {
//   csci3081::robot_params params;
//   csci3081::Position p;
//   params.pos = p;
//   params.angle_delta = 15;
//   params.battery_max_charge = 100;
//   params.collision_delta = 0.1;
//   params.radius = 5.0;
//   csci3081::EventEntityType e;
//   e.pos = p;
//   e.name = "homebase";
//
//   csci3081::SensorEntityType se(&params, 50);
//   //before reset, only activated_ has been changed
//   se.activated(true);
//   EXPECT_EQ(se.Output(), "homebase");
// }

//#endif /* STUDENT_TESTS2_TEST */
