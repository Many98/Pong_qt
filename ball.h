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
    double speed = Size::Height/343.0 * Size::ballSpeedConst;
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
    void mute(int sound);

public slots:

    void reflectX();
    void reflectY();
    void changeDY();  //random change after racket collision
    void soundPlay();
    void changeTurn();

signals:
    void ballMovedUp();
    void ballMovedDown();

};

#endif // BALL_H
