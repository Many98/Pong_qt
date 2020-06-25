#ifndef PONG_H
#define PONG_H
#include "settings.h"
#include <QGraphicsView>
#include <QMessageBox>

class QGraphicsScene;
class Racket;
class Ball;
class QMainWindow;
class QTimer;
class QMediaPlayer;
class Button;
class QToolBar;
class QAction;
class Options;
class Info;


class PONG : public QGraphicsView //PONG is class for game
{
    Q_OBJECT
private:
    QMainWindow *main;
    QGraphicsScene *scene; //The QGraphicsScene class provides a surface for managing a large number of 2D graphical items.
                           //The QGraphicsView class provides a widget for displaying the contents of a QGraphicsScene.
    Racket *rRacket, *lRacket;
    Ball *ball;
    QTimer *timer;
    QGraphicsTextItem *rScore, *lScore;
    Button *btnOnePlayer, *btnTwoPlayers, *btnOptions, *btnQuit,
            *btnNewGame, *btnResume;
    QMediaPlayer *borderSound, *gameLoopSound, *clickedSound;
    QToolBar *toolBar;
    QAction *actNewGame, *actPause, *actOptions, *actQuit,
            *actMute, *actInfo;
    Options *opt;
    Info *info;
    QMessageBox *msg;

    static unsigned int oldWidth,oldHeight;  // width and height used for resizing purpose
    static bool running;                     //game states
    static bool paused;

    void addGameItems();
    void addMainMenuItems();
    void addPauseMenuItems();
    void removeGameItems();
    void removeMainMenuItems();
    void removePauseMenuItems();

    void setupConnections();
    void setupStuff();
    void setPositions();
    void init();

    void collision();  //emites all kinds of signals if some collision has occured
    void AIPlayer();
    void run();


protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);

public:
    PONG(QWidget *parent = 0);
    void setVolume();
    ~PONG();

private slots:
    void update();
    void displayNewScore();
    void centerPosition();
    void newGame();
    void singlePlay();
    void multiPlay();
    void resizeItems();
    void playBorderSound();
    void playClickedSound();
    void mute();  //also unmute game
    void showDialogWindow(QDialog &dialog);
    void processNewSettings();
    void pauseGame();  //also resume game according to static variable running
    void resumeAfterDialogWindow(); //resume but unlike pauseGame this function differentiate
                                    //between PAUSED,RUNNING and MAINMENU(!PAUSED && !RUNNING) state
signals:
    void ballRacketCollision();
    void ballLeftBorderCollision();
    void ballRightBorderCollision();
    void ballHorizontalBorderCollision();
    void windowResized();

};

#endif // PONG_H
