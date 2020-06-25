#ifndef RACKET_H
#define RACKET_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "settings.h"

class QMediaPlayer;

class Racket: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int side;
    bool aiMode = false;
    unsigned int score;
    double speed = Global::Height/410.0 * Global::playerSpeedConst ;
    Dir direction = Stop;
    QMediaPlayer  *score_sound;

public:
    Racket(int side);
    void move();
    void moveUp();
    void moveDown();
    void changeDirection(Dir dir);
    bool getSide() const;
    bool getAIMode() const;
    unsigned int getScore() const;
    void resetScore();
    void resize();
    void mute(int sound);
    void setAIMode(bool enabled);
    ~Racket() = default;
public slots:
    void increaseScore();

};

#endif // RACKET_H

