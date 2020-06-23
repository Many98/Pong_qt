#include "settings.h"
#include <random>
#include <cmath>
#include <iostream>

 unsigned int Size::Width = 1920;
 unsigned int Size::Height = 1020;
 double Size::ballSizeConst = 1.0;
 double Size::ballSpeedConst = 1.0;
 double Size::playerSizeConst = 1.0;
 double Size::playerSpeedConst = 1.0 * Size::ballSpeedConst;
 int Size::soundLevel = 100;
 int Size::oldSoundLevel = 100;
 unsigned int Size::scoreToWin = 11;
 bool Size::endlessGame = false;
 bool Size::mouseMode = false;
 bool Size::keyboardMode = true;

double random(double start, double end)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); //standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> rand_velocity(start, end); // define the range

    return rand_velocity(eng);

}
