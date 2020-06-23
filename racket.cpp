#include "racket.h"
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <iostream>
#include <QMediaPlayer>

Racket::Racket(int side)
    : side(side),score(0)
{
    setRect(0 , 0 , Size::Width/55.0 ,Size::Height/5.0*Size::playerSizeConst ); //set position and shape
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
    if(y()+rect().height() > Size::Height)
        setPos(x(),Size::Height-rect().height());
    setPos(x(),y() + speed);
}

void Racket::resetScore()
{
    score = 0;
}

void Racket::resize()
{
    setRect(0 , 0 , Size::Width/55.0 , Size::Height/5.0*Size::playerSizeConst );
    speed = Size::Height/410.0*Size::playerSpeedConst;
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

