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
    int score;
    double speed = Global::Height/410.0 * Global::playerSpeedConst ;
    Dir direction = Stop;
    QMediaPlayer  *score_sound;

public:
    Racket(int side);
    void move();
    void moveUp();
    void moveDown();
    bool getSide() {return side;}
    bool getAIMode() {return aiMode;}
    int getScore() {return score;}
    void resetScore();
    void resize();
    void mute(int sound);
    ~Racket() = default;
public slots:
    void increaseScore();
    void changeDirection(Dir dir);

    void setAIMode(bool enabled); 


};

#endif // RACKET_H

