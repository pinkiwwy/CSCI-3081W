I didn't use the given base code to complete the iteration 1 functionality. My iteration2 is an extension from my iteration1 code.

I have finished the interface for sensorProximity, sensorDistress, sensorEntityType and sensorTouch in Priority Level 1. I have created unit tests for the sensors, and I have also completed the functionality of the sensors, except for sensorProximity. I have not finished any requirements from Priority level 3. I have included my progress of fixing the bug for each requirement. Each point represent an attempt to revise.

Unittest:
1. all the unittests for sensors has been created by the checkin day. Each sensor interface only contains a constructor, and the getters and setters. All the tests from ieration1 is still here. Everything can be compiled, but the tests for student-tests2.cc do not show up.
2. I delete all the tests from iter1 and re-compile. Still nothing is showing up. I deleted the #ifndef and #endif from the student-tests2, and it starts to show some errors.
3. Comment out all the test and redo it one by one.
4. sensorDistress has problem using the position struct. All the tests with position is commented out.
5. Error for constructor with input arguments
6. Fixed. Need to define the arguments first before using it. constructor now works.
7. All tests can be created, except for the one with Position.

sensorTouch:
1. The original sensorTouch has a constructor, a destructor, getters and setters for point_of_contact and angle_of_contact, an emit Message and a reset function. This doesn't work for the new design. Cannot be compiled without errors.
2. Remove the EmitMessage function and put it inside EventCollision. Instead, add an output().
3. Everything is set. Functionable with no errors
.
sensorDistress:
1. sensorDistress interface contains a constructor, getters and setters for radius and position, which are unnecessary.
2. Remove all the setters and getters.
3. Fixed the constructor. Instead of empty parameter, now it takes in a robot_params and the range. But, accept is not working. Previous design is wrong.
4. Redo the interface design.
5. Fixed EventDistress and accept().
6. Now the sensorDistress can be "make". Fix the unittest for it.
7. All set for sensorDistress.

sensorProximity:
1. sensorProximity interface contains a constructor, getters and setters for heading_angles, radius, and positions, a calculation function, a reset function and a accept function. Not work this way.
2. Delete all the getters and setters. Follow sensorDistress functions.
3. Add a InRange() that take in two ranges and generate a boolean value to indicate if it is in range.
4. Not sure how the cone field of view could be implemented.
5. Interface is done without functionality for sensorProximity. Can be compiled.

sensorEntityType:
1. sensorEntityType interface contains a constructor, getters and setters for radius , position and name, an accept function, an emitMessage() and a reset(). Not work in this way.
2. Since sensorEntityType also need to sense incoming objects, it uses same functions as sensorDistress. Also, added a getter for name to return entity type.
3. Use the name() within the accept() and store the name in a private variable name_.
4. Interface and functionality both work.

All the sensors haven't be assigned in the entities. Therefore, it doesn't make a difference when run arenaviewer.

EventDistress, EventCollision, EventEntityType all works.

EventProximity:
1. sensorProximity has not be fully created. EventProximity is following EventDistress for the design.
2. Can be compiled and it works.

Robot:
1. Try to add sensor into robot like the sensorTouch, but failed.
2. Add sensor_distress object to robot. There is an error stating that id(-1) cannot be defined from sensor_distress.
3. Commented out sensor_distress, it now works.

All the unittest for sensors can be "make". All the sensors can be compiled. But, some of the tests still failed.
1. Fix SensorTouch constructor, still failed.
2. Fixed the activated(), still failed.
3. Cannot figure out the reasons yet. 
