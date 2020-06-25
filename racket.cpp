#include "racket.h"
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <iostream>
#include <QMediaPlayer>

Racket::Racket(int side)
    : side(side),score(0)
{
    setRect(0 , 0 , Global::Width/55.0 ,Global::Height/5.0*Global::playerSizeConst ); //set position and shape
    score_sound = new QMediaPlayer;
    score_sound->setMedia(QUrl("qrc:/sounds/coin.wav"));
}

void Racket::move()
{
    if(direction == Up)
        moveUp();
    if(direction == Down)
        moveDown();
}

void Racket::moveUp()
{
    if(y() < 0)
        setPos(x(),0);
     setPos(x(),y() - speed);
}

void Racket::moveDown()
{
    if(y()+rect().height() > Global::Height)
        setPos(x(),Global::Height-rect().height());
    setPos(x(),y() + speed);
}

bool Racket::getSide() const
{
    return side;
}

bool Racket::getAIMode() const
{
    return aiMode;
}

unsigned int Racket::getScore() const
{
    return score;
}

void Racket::resetScore()
{
    score = 0;
}

void Racket::resize()
{
    setRect(0 , 0 , Global::Width/55.0 , Global::Height/5.0*Global::playerSizeConst );
    speed = Global::Height/410.0*Global::playerSpeedConst;
}

void Racket::changeDirection(Dir dir)
{
    direction = dir;
}

void Racket::setAIMode(bool enabled)
{
    aiMode = enabled;
}

void Racket::mute(int sound)
{
    score_sound->setVolume(sound);
}

void Racket::increaseScore()
{
    score++;
    score_sound->play();

}

