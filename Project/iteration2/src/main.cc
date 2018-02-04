/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

#include "src/graphics_arena_viewer.h"
#include "src/arena_params.h"
#include "src/color.h"
#include "src/position.h"

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int, char **) {
  // Essential call to initiate the graphics window
  csci3081::InitGraphics();

  // Initialize default start values for various arena entities
  csci3081::player_params pparams;

  pparams.battery_max_charge = 100;
  pparams.angle_delta = 10;
  pparams.collision_delta = 1;

  /**
  * User input for position and radius of robot.
  * Position comment out -> havent design a way to avoid overlapped position
  * with other entities.
  **/
  double pposx, pposy;
  double pr;
  std::cout << "Enter Position for player(x coordinate):" << std::endl;
  std::cin >> pposx;
  std::cout << "Enter Position for player(y coordinate):" << std::endl;
  std::cin >> pposy;
  std::cout << "Enter Radius for player:" << std::endl;
  std::cin >> pr;
  pparams.radius = pr;
  pparams.pos = csci3081::Position(pposx, pposy);
  pparams.color = csci3081::Color(0, 0, 255, 255); /* blue */

  csci3081::arena_params aparams;

  aparams.player = pparams;


  /**
  * User input for radius and position of recharge station.
  * Need to revise to avoid the chance to have overlapped entities position.
  **/
  double rcr;
  std::cout << "Enter Radius for recharge station:" << std::endl;
  std::cin >> rcr;
  double cposx, cposy;
  std::cout << "Enter Position for recharge station(x coordinate):"
  << std::endl;
  std::cin >> cposx;
  std::cout << "Enter Position for recharge station(y coordinate):"
  << std::endl;
  std::cin >> cposy;
  aparams.recharge_station.radius = rcr;
  aparams.recharge_station.pos = {cposx, cposy};
  aparams.recharge_station.color = csci3081::Color(0, 128, 128, 255);
  /* green */

  /**
  * User input for radius of home base.
  * need to revise to avoid the chance to have overlapped entities position.
  **/
  double hbr;
  std::cout << "Enter Radius for home base:" << std::endl;
  std::cin >> hbr;
  double hposx, hposy;
  std::cout << "Enter Position for home base(x coordinate):" << std::endl;
  std::cin >> hposx;
  std::cout << "Enter Position for home base(y coordinate):" << std::endl;
  std::cin >> hposy;
  aparams.home_base.radius = hbr;
  aparams.home_base.pos = {hposx, hposy};
  aparams.home_base.color = csci3081::Color(255, 0, 0, 255); /* red */

  /**
  * User input for radius of obstacles and number of obstacles (1-8)
  * need to revise to avoid the chance to have overlapped entities position.
  **/
  double obr;
  std::cout << "Enter Radius for obstacle(s):" << std::endl;
  std::cin >> obr;
  int num;
  std::cout << "Enter the number of obstacles (1-8):" << std::endl;
  std::cin >> num;
  for (int i=0; i < num; i++) {
    aparams.obstacles[i].radius = num;
    // position of obstacles is assigned using random number
    // posx is range between 0 and 1024, and posy is range between 0 and 768
    aparams.obstacles[i].pos = {double(rand()%1024), double(rand()%768)};
    aparams.obstacles[i].color = csci3081::Color(255, 255, 255, 255);
    /* white */
  }
  // aparams.obstacles[0].radius = obr;
  // aparams.obstacles[0].pos = {200, 200};
  // aparams.obstacles[0].color = csci3081::Color(255, 255, 255, 255);
  /* white */
  //
  // aparams.obstacles[1].radius = obr;
  // aparams.obstacles[1].pos = {100, 600};
  // aparams.obstacles[1].color = csci3081::Color(255, 255, 255, 255);
  /* white */
  //
  // aparams.obstacles[2].radius = obr;
  // aparams.obstacles[2].pos = {1000, 200};
  // aparams.obstacles[2].color = csci3081::Color(255, 255, 255, 255);
  /* white */
  //
  // aparams.obstacles[3].radius = obr;
  // aparams.obstacles[3].pos = {800, 500};
  // aparams.obstacles[3].color = csci3081::Color(255, 255, 255, 255);
  /* white */
  //
  // aparams.obstacles[4].radius = obr;
  // aparams.obstacles[4].pos = {300, 400};
  // aparams.obstacles[4].color = csci3081::Color(255, 255, 255, 255);
  /* white */

  aparams.n_obstacles = num;
  aparams.x_dim = 1024;
  aparams.y_dim = 768;

  // Start up the graphics (which creates the arena).
  // Run will enter the nanogui::mainloop()
  csci3081::GraphicsArenaViewer *app =
    new csci3081::GraphicsArenaViewer(&aparams);
  app->Run();
  csci3081::ShutdownGraphics();
  return 0;
}
