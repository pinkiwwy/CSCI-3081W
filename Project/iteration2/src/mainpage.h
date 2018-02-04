/**
 * @file mainpage.h
 *
 * @copyright 2017 3081 , All rights reserved.
 */

/*! \mainpage CSCI3081 Robot Simulator Project
 *
 * \section intro_sec Introduction
 *
 * The purpose of iteration2 is to extend the robot simulation from iteration1 and add more functionalities in it. The video-game-like robot simulation is now improved with the addition of various types of sensors, user-control robot and autonomous robots.

Design of the simulation:

This time we have added a Sensor base class. When we look at the UML diagram, we know that there are four derived classes for sensor. They are the SensorDistress, SensorEntityType, SensorProximity and SensorTouch. Each of these sensors is connect with other entities for different purposes.

For the SensorTouch class, it is used for sensing collision. It has a constructor, a destructor, getters and setters for point_of_contact_ and angle_of_contact, an accept(), an output() and a reset(). The accept() will atke in an EventCollision event and check if there is collision with the use of point_of_contact_ and angle_of_contact_. If there is collision, activated_ will be true to indicate there is collision, Otherwise, activated_ will be false. At the end, the output() will print out 1 for any collision, or a 0 for nothing.

For the SensorProximity class, it is used for avoiding collision. Each automated robot will have 2 sensorProximity, and each sensor will have a cone of field of view. Instead of a circulated range, a cone limits the sensing ability of a robot. The sensor_proximity contains a constructor, a destructor, a getter for position and, a InRange(), an accept(), an output(), and a reset(). Using the InRange(), it can take in two range value and check if check if the two value are in range. The accept() will call EventProximity and calculate the distance between entities. At the end, if sensor is activated, distance will be returned.

For the SensorDistress class, it is used for emitting a distress call for frozen robots, which allow arena to deactivate the sensorProximity. This could increase the chance of collision and the frozen robots could be easier to defrost. The sensor_distress contains a constructor, a getter and setter for activated, an accept(), an out(), and a reset(). The constructor will take in a robot_params object and a range value. The sensor_distress senses entities in a circulated range with radius of the given range value. Accept() will be used for getting the position from EventDistressCall to calculate the distance and check if it is in range. If yes, sensor activated and output() will return 1. Otherwise, sensor deactivated and output() return 0.

For the SensorEntityType, it is used for getting the types for the approaching entities. The sensor_entity_type contains a constructor, a  getter and setter for activate and name, an accept(), an output(), and a reset(). The constructor will take in a robot_params object and a range. Similar to the sensor_distress, it will instead call EventEntityType to check if the approaching entities is in range. If yes, sensor activated and it will return the name through the output().

EventBaseClass is also one of the base class in this project. Its original derived classes are EventCommand, EventCollision, and EventRecharge. In iteration2, there are three more derived classes, which are EventDistressCall, EventEntityType and EventProximity. All of these three event classes together with the EventCollision class are being used by the sensor classes for different purpose as describe above.


 *
 * \section install_sec Installation
 *
 * \subsection libsimplegraphics Installing and Using libsimplegraphics
 *
 * etc...
 */
