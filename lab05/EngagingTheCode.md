# Submit Answer
## Exercise to Engage the Code

These are questions that ask you to explore the code in a specific way. They highlight important functionality and flow-of-control. You might want to jot down the answers for your own use as you spend time learning the code. It will probably take you a minimum of 2 hours just to understand how all the pieces fit together. We highly recommend you spend time understanding the framework before adding a single line of code.

# Answer the Following Questions Based on Iteration1 Code

1. What does GraphicsArenaViewer::DrawUsingNanoVG() do?

Ans: For drawing all entities in the arena
   
2. When does this get called?

Ans: It requires an active nanovg drawing context (ctx), so it should only be called from with \ref DrawUsingNanoVG().

3. How is it that the Recharge Station is being drawn - there is no command to draw it?

Ans:It is initalize in the main as part of rparams with radius, postion and color.

4. What entities exist in the Arena?
    - For each entity, what is it's base (parent) class?

Ans: ArenaEntity is the base class. ArenaMobileEntry, ArenaImmobileEntity are in the arena.

5. Where does the system check for collisions (look in Arena.cc)?

Ans: Inside the Arena.cc, it create an instance ec from EventCollision, which calls the function CheckForEntityCollision to check for collision at recharge station.

6. When does this happen (i.e. where is it in flow-of-control)?

Ans: Before the general collision.

7. What is the logic for checking for colliding with walls?

Ans: To check if it is out of bounds using the function CheckForEntityOutOfBounds.

8. What is the logic for checking for colliding with other entities?

Ans: First check if that is at wall, then check if it collide with other entities using the CheckForEntityCollision.

9. Trace the EventCollision from the point at which it is created in Arena to
the robot sensor. What does the sensor record when a collision happens?

Ans: When collision happens, the EventCollision object is passed to the SensorTouch class, which use a bool variable to check if it is collided. If yes, call point_of_contact and angle_of_contact. Otherwise, nothing changed.

10. The RobotMotionHandler reads the touch sensor. What does it do with this information?

Ans: It reads the touch sensor and see if there is collision. If yes, it will use the negative angle_of_contact from the touch sensor class as the new heading_angle of the robot.

11. Identify the method (function) that updates the robot position. Trace flow-of-control
from the call UpdateSimulation in GraphicsArenaViewer.

Ans: When it calls UpdateSimulation in GraphicArenaViewer, it sends a message to the arena "arena->advancedTime(1)". The arena will update themselves each timestep using TimestepUpdate. The robot_motion_handler will call on UpdateVelocity and the RobotMotionBehavior will call on UpdatePosition.

12. What is the equation used to calculate the deltaX and deltaY for the robot
and update the position?

Ans: deltaX = Distance*cos(heading_angle);
     deltaY = Distance*sin(heading_angle);