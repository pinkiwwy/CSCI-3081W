I have finished all functions in Priority Level 1 and passed all 16 units test. I have only finished some functions from Priority level 2 and 3.

In Priority One, I have implemented the arrow keypressed handlers functions. When up and down arrow is pressed, the speed will increase and decrease respectively. The speed will only increase up to MAX_SPEED or decrease down to zero, which the robot will stop. To make this work, I completed the code under AcceptCommand() in robot_motion_handler.cc. See robot_motion_handler.cc for more detail.

Home base is now inherited from ArenaMobileEntity instead of ArenaImmobileEntity. Basically it contains most of the functions like the Robot class. I only took out the battery-related functions and keep everything similar.

In Priority Level 2, I have tried to add restart function. I followed the way that pause button is created. I added a boolean restart_ to check if restart button is pressed. So, inside the graphics_arena_viewer.cc in the UpdateSimulation function, when restart_ not pressed, nothing happened and time keeps going. Otherwise, arena-> reset. When look into arena class, robot's heading angle changes back to the original and battery become max. I was able to make to turn to the original angle but wasnt able to make it return to the original position. My pause button works fine, but after I put homebase under ArenaMobileEntity, pause is not functioning well.

Win/lose function - If it collide with homebase, it will print a "Win" in the terminal. I add the printf line inside CheckForEntityCollision(robot_, home_base_, &ec, robot_->collision_delta()) in arena.cc. But it doesn't seem to work well. Lose function is not done yet, since CHeckForEnityCollision(robot_, n_obstacles_, &ec, robot_->collision_delta()) is not functioning well. I have commented it out inside arena.cc.

Fix bounce behavior off of left and right walls (it should reflect at angle of incidence.)
I was trying to add a formular to fix the reflection at angle of incidence. But when I add it to arena.cc inside the CheckForEntityOutOfBounds(), the arena.o cannot be made. It states that setter from arena_entity is const and it cannot be modify. I have been to Office hour to ask for help on this, but due to lack of time, I wasn't able to fix it. Therefore, I deleted the four equations for top, bottom, left and right walls.

Visualize battery level (can be through GUI or something on the robot)
I print out the battery_level inside robot.cc but it o=include all the decimal numbers, which I have no clues how to show sig.fig. in C++. 

I dont have chance to work on the color part yet.

Priority Level 3

Deplete battery when robot bumps into obstacles.
Deplete battery function for collision with obstacle is not done yet, since CHeckForEnityCollision(robot_, n_obstacles_, &ec, robot_->collision_delta()) is not functioning well. I have commented it out inside arena.cc.

Slow the robot down when it bumps into obstacles.
Decrease speed function for collision with obstacle is not done yet, since CHeckForEnityCollision(robot_, n_obstacles_, &ec, robot_->collision_delta()) is not functioning well. I have commented it out inside arena.cc.

Create a total of 5 obstacles in the environment.
I have created 5 obstacles in the main.cc, which all have different positions.
