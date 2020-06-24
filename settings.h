#ifndef SETTINGS_H
#define SETTINGS_H


enum Side{Left =1,Right = 2};
enum Dir{Up = -1, Down = 1, Stop = 0};

class Global  //needs better name
{
public:
    static unsigned int Width;   //initial game window width
    static unsigned int Height;  //initial game window height
    static double ballSizeConst;
    static double ballSpeedConst;
    static double playerSizeConst;
    static double playerSpeedConst;
    static int soundLevel;
    static int oldSoundLevel;
    static unsigned int scoreToWin;
    static bool endlessGame;
    static bool mouseMode;
    static bool keyboardMode;

};
double random(double start,double end);

#endif // SETTINGS_H
