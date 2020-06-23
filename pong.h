#ifndef PONG_H
#define PONG_H
#include "settings.h"
#include <QGraphicsView>

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


class PONG : public QGraphicsView //PONG is class for game
{
    Q_OBJECT
private:
    QMainWindow *main;
    QGraphicsScene *scene;
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

    static unsigned int oldWidth,oldHeight;
    static bool running;
    static bool paused;
    static bool mainMenu;
    static bool dialogWindow;  //looks like it is not necessary
    static bool muted;

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
    void mute();  //also unmute game according to static variable muted
    void setSound();
    void showInfo();
    void showSettings();
    void processNewSettings();
    void pauseGame();  //also resume game according to static variable running (ONLY GAME)
    void resumeAfterDialogWindow(); //resume but unlike pauseGame this function differentiete
                                    //between PAUSED,RUNNING and MAINMENU state
signals:
    void ballRacketCollision();
    void ballLeftBorderCollision();
    void ballRightBorderCollision();
    void ballHorizontalBorderCollision();
    void windowResized();

};

#endif // PONG_H
