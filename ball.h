#ifndef BALL_H
#define BALL_H

#include "settings.h"

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class QMediaPlayer;


class Ball : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    double speed = Global::Height/343.0 * Global::ballSpeedConst;
    double dx = speed * 1.80;
    double dy = random(-speed,speed);
    Side Turn = Left;
    QMediaPlayer *reflect_sound;

public:
    Ball(QGraphicsItem *parent = nullptr);
    ~Ball() = default;
    void move();
    double getDX() const;
    void resize();
    void setVolume(int sound);  //set volume
    void changeTurn();

public slots:

    void reflectX();
    void reflectY();
    void changeDY();  //random change after racket collision
    void soundPlay();

signals:
    void ballMovedUp();
    void ballMovedDown();

};

#endif // BALL_H
