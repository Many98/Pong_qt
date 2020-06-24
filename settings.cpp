#include "settings.h"
#include <random>
#include <cmath>
#include <iostream>

 unsigned int Global::Width = 1920;
 unsigned int Global::Height = 1020;
 double Global::ballSizeConst = 1.0;
 double Global::ballSpeedConst = 1.0;
 double Global::playerSizeConst = 1.0;
 double Global::playerSpeedConst = 1.0 * Global::ballSpeedConst;  //change of ball and player speed are connected
 int Global::soundLevel = 100;
 int Global::oldSoundLevel = 100;
 unsigned int Global::scoreToWin = 11;
 bool Global::endlessGame = false;
 bool Global::mouseMode = false;
 bool Global::keyboardMode = true;

double random(double start, double end)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); //standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> rand_velocity(start, end); // define the range

    return rand_velocity(eng);

}
