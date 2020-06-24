#include "ball.h"
#include "settings.h"
#include <QMediaPlayer>
#include <cmath>

Ball::Ball(QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    setRect(0 , 0 , Global::Height/41*Global::ballSizeConst , Global::Height/41*Global::ballSizeConst);
    reflect_sound = new QMediaPlayer;
    reflect_sound->setMedia(QUrl("qrc:/sounds/reflect.mp3"));

}

void Ball::resize()
{
    setRect(0 , 0 , Global::Height/41*Global::ballSizeConst , Global::Height/41*Global::ballSizeConst);
    speed = Global::Height/343.0 * Global::ballSpeedConst;
    dx = speed*1.80;
    dy = random(-speed,speed);
}

void Ball::soundPlay()
{
    reflect_sound->play();
}

void Ball::setVolume(int sound)
{
    reflect_sound->setVolume(sound);
}


void Ball::move()
{
    setPos(x()+dx,y()+dy);
}

void Ball::changeTurn()
{
    if(Turn == Left)
    {
        Turn = Right;
        dx = -abs(dx);
    }
    else
    {
        Turn = Left;
        dx = abs(dx);
    }

    dy = 0;
}


double Ball::getDX() const
{
    return dx;
}

void Ball::reflectY()
{
    dy = -dy;
}

void Ball::changeDY()
{
    dy = random(-speed,speed);
}


void Ball::reflectX()
{
    dx = -dx;
}


