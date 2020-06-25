#include "pong.h"
#include "racket.h"
#include "ball.h"
#include "settings.h"
#include "button.h"
#include "options.h"
#include "info.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include <QMediaPlayer>
#include <QToolBar>
#include <QAction>
#include <QMessageBox>

bool PONG::running =false;
bool PONG::paused = false;

unsigned int PONG::oldWidth = Global::Width;
unsigned int PONG::oldHeight = Global::Height;


PONG::PONG(QWidget *parent)
    : QGraphicsView(parent)
{

    init();
    setPositions();
    setupStuff();
    setupConnections(); //must be after setUpStuff()

    // Ta-Daaaa
    this->addMainMenuItems();
    main->show();

}


void PONG::resizeItems()
{
    scene->setSceneRect(0,0,Global::Width,Global::Height);

    //resize game items
    ball->resize();
    rRacket->resize();
    lRacket->resize();

    //resize menus
    btnOnePlayer->resize();
    btnTwoPlayers->resize();
    btnOptions->resize();
    btnQuit->resize();
    btnNewGame->resize();
    btnResume->resize();

    setPositions();

}


void PONG::setPositions()
{
    centerPosition();

    btnOnePlayer->setPos(Global::Width/2.7,Global::Height/20.5);
    btnTwoPlayers->setPos(Global::Width/2.7,Global::Height/4.1);
    btnOptions->setPos(Global::Width/2.7,Global::Height/2.28);
    btnQuit->setPos(Global::Width/2.7,Global::Height/1.58);
    btnNewGame->setPos(Global::Width/2.7,Global::Height/20.5);
    btnResume->setPos(Global::Width/2.7,Global::Height/4.1);

    rScore->setPos(Global::Width*6.5/10.0,0);
    lScore->setPos(Global::Width*3.1/10.0,0);
    rScore->setFont(QFont("Times", Global::Height/20.0 + Global::Width/80.0, QFont::Bold));
    lScore->setFont(QFont("Times", Global::Height/20.0 + Global::Width/80.0, QFont::Bold));

}

void PONG::init()
{
    //game items
    ball = new Ball();
    rRacket = new Racket(Right);
    lRacket = new Racket(Left);
    //score
    rScore = new QGraphicsTextItem(QString::number(rRacket->getScore()));
    lScore = new QGraphicsTextItem(QString::number(lRacket->getScore()));
    //items
    timer = new QTimer(this);
    opt = new Options();
    info = new Info();
    scene = new QGraphicsScene(0,0,Global::Width,Global::Height);
    main = new QMainWindow();
    //buttons
    btnOnePlayer = new Button("One Player");
    btnTwoPlayers = new Button("Two Players");
    btnOptions = new Button("Settings");
    btnQuit = new Button("Quit");
    btnNewGame = new Button("New Game");
    btnResume = new Button("Resume");
    //sounds
    borderSound = new QMediaPlayer;
    gameLoopSound = new QMediaPlayer;
    clickedSound = new QMediaPlayer;

    //actions
    actNewGame = new QAction(tr("&New Game"));
    actPause = new QAction(tr("Pause/Resume"));
    actOptions = new QAction(tr("Settings"));
    actQuit = new QAction(tr("Quit"));
    actMute = new QAction(tr("Mute/Unmute"));
    actInfo = new QAction(tr("Info"));
}

void PONG::setupStuff()
{

    //graphical view
    this->setScene(scene);
    this->setBackgroundBrush(Qt::black);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //game items
    ball->setBrush(Qt::white);
    rRacket->setBrush(Qt::white);
    lRacket->setBrush(Qt::white);
    //score
    rScore->setDefaultTextColor(Qt::white);
    lScore->setDefaultTextColor(Qt::white);

    //sounds
    borderSound->setMedia(QUrl("qrc:/sounds/border.mp3"));
    gameLoopSound->setMedia(QUrl("qrc:/sounds/game-loop.wav"));
    clickedSound->setMedia(QUrl("qrc:/sounds/decrase.wav"));

    //main window
    main->setGeometry(0,0,Global::Width,Global::Height);
    main->setWindowTitle("PONG");
    main->setCentralWidget(this);

    //actions
    actNewGame->setIcon(QIcon(":/icons/Play.png"));  //possibly change to ":/icons/gaming.png"
    actNewGame->setShortcut(QKeySequence(tr("Ctrl+N")));
    actPause->setIcon(QIcon(":/icons/Button-Pause-icon.png"));
    actQuit->setIcon(QIcon(":/icons/Button-Close.png"));
    actOptions->setIcon(QIcon(":/icons/Settings-5-icon.png"));
    actMute->setIcon(QIcon(":/icons/Sound-off-icon.png"));
    actInfo->setIcon(QIcon(":/icons/Info-icon.png"));

    //toolbar
    toolBar = main->addToolBar("toolBar");
    toolBar->addAction(actNewGame);
    toolBar->addSeparator();
    toolBar->addAction(actPause);
    toolBar->addSeparator();
    toolBar->addAction(actMute);
    toolBar->addSeparator();
    toolBar->addAction(actOptions);
    toolBar->addAction(actInfo);
    toolBar->addSeparator();
    toolBar->addAction(actQuit);

    actPause->setEnabled(false);

}

void PONG::setupConnections()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(this, SIGNAL(windowResized()), this, SLOT(resizeItems()));

    connect(this, SIGNAL(ballHorizontalBorderCollision()), ball, SLOT(reflectY()));
    connect(this, SIGNAL(ballHorizontalBorderCollision()), this, SLOT(playBorderSound()));

    connect(this, SIGNAL(ballLeftBorderCollision()), rRacket, SLOT(increaseScore()));
    connect(this, SIGNAL(ballLeftBorderCollision()), this, SLOT(displayNewScore()));
    connect(this, SIGNAL(ballLeftBorderCollision()), this, SLOT(centerPosition()));

    connect(this, SIGNAL(ballRightBorderCollision()), lRacket, SLOT(increaseScore()));
    connect(this, SIGNAL(ballRightBorderCollision()), this, SLOT(displayNewScore()));
    connect(this, SIGNAL(ballRightBorderCollision()), this, SLOT(centerPosition()));

    connect(this, SIGNAL(ballRacketCollision()), ball, SLOT(reflectX()));
    connect(this, SIGNAL(ballRacketCollision()), ball, SLOT(changeDY()));
    connect(this, SIGNAL(ballRacketCollision()), ball, SLOT(soundPlay()));

    connect(btnOnePlayer, SIGNAL(clicked()), this, SLOT(singlePlay()));
    connect(btnOnePlayer, SIGNAL(clicked()), btnOnePlayer, SLOT(playClickedSound()));
    connect(btnTwoPlayers, SIGNAL(clicked()), this, SLOT(multiPlay()));
    connect(btnTwoPlayers, SIGNAL(clicked()), btnTwoPlayers, SLOT(playClickedSound()));
    connect(btnResume, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(btnResume, SIGNAL(clicked()), btnResume, SLOT(playClickedSound()));
    connect(btnNewGame, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(btnNewGame, SIGNAL(clicked()), btnNewGame, SLOT(playClickedSound()));
    connect(btnOptions, &Button::clicked,
            [this]()->void{
                              showDialogWindow(*opt);
                          }
            );
    connect(btnOptions, SIGNAL(clicked()), this, SLOT(playClickedSound()));
    connect(btnQuit, SIGNAL(clicked()), this, SLOT(close()));

    connect(actNewGame, SIGNAL(triggered(bool)), this, SLOT(newGame()));
    connect(actNewGame, SIGNAL(triggered(bool)), this, SLOT(playClickedSound()));
    connect(actQuit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(actPause, SIGNAL(triggered(bool)), this, SLOT(pauseGame()));
    connect(actPause, SIGNAL(triggered(bool)), this, SLOT(playClickedSound()));
    connect(actMute, SIGNAL(triggered(bool)), this, SLOT(mute()));
    connect(actMute, SIGNAL(triggered(bool)), this, SLOT(playClickedSound()));
    connect(actOptions, SIGNAL(triggered(bool)), this, SLOT(playClickedSound()));
    connect(actOptions, &QAction::triggered,
            [this]()->void{
                              showDialogWindow(*opt);
                          }
            );
    connect(actInfo, &QAction::triggered,
            [this]()->void{
                              showDialogWindow(*info);
                          }
            );
    connect(actInfo, SIGNAL(triggered(bool)), this, SLOT(playClickedSound()));
    connect(info, SIGNAL(finished(int)), this, SLOT(resumeAfterDialogWindow()));

    connect(opt, SIGNAL(rejected()), this, SLOT(resumeAfterDialogWindow()));
    connect(opt, SIGNAL(accepted()), this, SLOT(resumeAfterDialogWindow()));
    connect(opt, SIGNAL(accepted()), this, SLOT(processNewSettings()));
}

void PONG::mute()
{
    if(Global::soundLevel)
    {
        Global::soundLevel = 0;
        actMute->setIcon(QIcon(":/icons/Sound-on.png"));
    }
    else
    {
        Global::soundLevel = opt->getVoiceLevel();
        actMute->setIcon(QIcon(":/icons/Sound-off-icon.png"));
    }

    this->setVolume(); //sets volume level on all items

    opt->setVolume(Global::soundLevel); //sets volume level in settings
}

void PONG::setVolume()
{

    borderSound->setVolume(Global::soundLevel);
    gameLoopSound->setVolume(Global::soundLevel);
    if(Global::soundLevel && PONG::running)
        gameLoopSound->play();
    else
        gameLoopSound->stop();
    clickedSound->setVolume(Global::soundLevel);
    ball->setVolume(Global::soundLevel);
    rRacket->mute(Global::soundLevel);
    lRacket->mute(Global::soundLevel);
    btnNewGame->setVolume(Global::soundLevel);
    btnOnePlayer->setVolume(Global::soundLevel);
    btnTwoPlayers->setVolume(Global::soundLevel);
    btnOptions->setVolume(Global::soundLevel);
    btnResume->setVolume(Global::soundLevel);
    btnQuit->setVolume(Global::soundLevel);

}

void PONG::processNewSettings()
{
    Global::ballSizeConst = opt->getBallSize();
    Global::ballSpeedConst = opt->getBallSpeed();
    Global::playerSizeConst = opt->getPlayerSize();
    Global::playerSpeedConst = opt->getPlayerSpeed() * Global::ballSpeedConst;
    if(!Global::soundLevel && opt->getSound())
        actMute->setIcon(QIcon(":/icons/Sound-off-icon.png"));
    if(Global::soundLevel && !opt->getSound())
        actMute->setIcon(QIcon(":/icons/Sound-on.png"));
    Global::soundLevel = opt->getSound();
    Global::scoreToWin = opt->getScoreToWin();
    Global::endlessGame = opt->getEndlessGame();
    Global::mouseMode = opt->getMouseMode();
    Global::keyboardMode = opt->getKeyboardMode();

    ball->resize();
    lRacket->resize();
    rRacket->resize();
    this->setVolume();
}

void PONG::showDialogWindow(QDialog &dialog)
{
    if(PONG::running)
    {
        timer->stop();
        gameLoopSound->stop();
    }
    if(PONG::paused)
    {
        removePauseMenuItems();
    }
    if(!PONG::running && !PONG::paused)  //if is in main menu..
    {
        removeMainMenuItems();
    }
    actNewGame->setEnabled(false);
    actOptions->setEnabled(false);
    actPause->setEnabled(false);
    actInfo->setEnabled(false);
    actMute->setEnabled(false);

    dialog.show();
}

void PONG::resumeAfterDialogWindow()
{
    if(PONG::running)
    {
        timer->start(5);
        gameLoopSound->play();
        actPause->setEnabled(true);
    }
    if(PONG::paused)
    {
        addPauseMenuItems();
        actPause->setEnabled(true);
    }
    if(!PONG::running && !PONG::paused) //if is in main menu
    {
        addMainMenuItems();
    }

    actNewGame->setEnabled(true);
    actOptions->setEnabled(true);
    actInfo->setEnabled(true);
    actMute->setEnabled(true);
}

void PONG::pauseGame()
{
    if(PONG::running)
    {
        paused = true;
        running = false;
        gameLoopSound->stop();
        timer->stop();
        removeGameItems();
        addPauseMenuItems();
        actPause->setIcon(QIcon(":/icons/Button-Play-icon.png"));
    }
    else
    {
        run();
        removePauseMenuItems();
        actPause->setIcon(QIcon(":/icons/Button-Pause-icon.png"));
    }
}


void PONG::AIPlayer()
{
    if(lRacket->getAIMode() && ball->getDX() < 0)
    {
        if(ball->y() <= lRacket->y())
            lRacket->moveUp();
        else if(ball->y() + ball->rect().height() >= lRacket->y() + lRacket->rect().height())
            lRacket->moveDown();
    }
    if(rRacket->getAIMode() && ball->getDX() > 0)
    {
        if(ball->y() <= rRacket->y())
            rRacket->moveUp();
        else if(ball->y() + ball->rect().height() >= rRacket->y() + rRacket->rect().height())
            rRacket->moveDown();
    }
}

void PONG::addGameItems()
{
    scene->addItem(ball);
    scene->addItem(lRacket);
    scene->addItem(rRacket);
    scene->addItem(rScore);
    scene->addItem(lScore);
}

void PONG::removeGameItems()
{
    scene->removeItem(ball);
    scene->removeItem(lRacket);
    scene->removeItem(rRacket);
    scene->removeItem(rScore);
    scene->removeItem(lScore);
}

void PONG::addMainMenuItems()
{
    scene->addItem(btnOnePlayer);
    scene->addItem(btnTwoPlayers);
    scene->addItem(btnOptions);
    scene->addItem(btnQuit);
}

void PONG::removeMainMenuItems()
{
    scene->removeItem(btnOnePlayer);
    scene->removeItem(btnTwoPlayers);
    scene->removeItem(btnOptions);
    scene->removeItem(btnQuit);
}

void PONG::addPauseMenuItems()
{
    scene->addItem(btnNewGame);
    scene->addItem(btnResume);
    scene->addItem(btnOptions);
    scene->addItem(btnQuit);
}

void PONG::removePauseMenuItems()
{
    scene->removeItem(btnNewGame);
    scene->removeItem(btnResume);
    scene->removeItem(btnOptions);
    scene->removeItem(btnQuit);
}

void PONG::run()
{
    if(!PONG::running)
    {
        addGameItems();
        timer->start(5);
        running = true;
        paused = false;
        actPause->setEnabled(true);
    }

}

void PONG::singlePlay()
{
    if(!PONG::running && !PONG::paused)
        removeMainMenuItems();
    lRacket->setAIMode(true);
    rRacket->setAIMode(false);
    run();
}

void PONG::multiPlay()
{
    if(!PONG::running && !PONG::paused)
        removeMainMenuItems();
    lRacket->setAIMode(false);
    rRacket->setAIMode(false);
    run();
}


void PONG::playBorderSound()
{
    borderSound->play();
}

void PONG::playClickedSound()
{
    clickedSound->play();
}

void PONG::update()
{
    collision(); //check for collision
    gameLoopSound->play();
    ball->move();
    if(!lRacket->getAIMode())
        lRacket->move();
    if(!rRacket->getAIMode())
        rRacket->move();

    AIPlayer();
}


void PONG::newGame()
{

    centerPosition();
    rRacket->resetScore();
    lRacket->resetScore();
    displayNewScore();

    if(PONG::running)
    {
        removeGameItems();
        addMainMenuItems();
        gameLoopSound->stop();
        timer->stop();
        running = false;
    }
    if(PONG::paused)
    {
        removePauseMenuItems();
        addMainMenuItems();
        paused = false;
    }

    actPause->setEnabled(false);
    actPause->setIcon(QIcon(":/icons/Button-Pause-icon.png"));
}

void PONG::collision()
{
    if(ball->collidesWithItem(lRacket))
    {
        emit ballRacketCollision();
        ball->setPos(lRacket->x()+lRacket->rect().width(),ball->y());
    }
    else if(ball->collidesWithItem(rRacket))
    {
        emit ballRacketCollision();
        ball->setPos(rRacket->x()-ball->rect().width(),ball->y());
    }
    else if(ball->y() < scene->sceneRect().y())
    {
        emit ballHorizontalBorderCollision();
        ball->setPos(ball->x(),scene->sceneRect().y());
    }
    else if(ball->y()+ball->rect().height() > scene->height())
    {
        emit ballHorizontalBorderCollision();
        ball->setPos(ball->x(),scene->height()-ball->rect().height());
    }
    else if(ball->x() < scene->sceneRect().x())
        emit ballLeftBorderCollision();
    else if(ball->x()+ball->rect().width() > scene->width())
        emit ballRightBorderCollision();
}

void PONG::displayNewScore()
{
    rScore->setPlainText(QString::number(rRacket->getScore()));
    lScore->setPlainText(QString::number(lRacket->getScore()));
}

void PONG::centerPosition()
{
    rRacket->setPos(this->sceneRect().width() - rRacket->rect().width()-1,scene->sceneRect().height()/2 - rRacket->rect().height()/2);
    lRacket->setPos(this->sceneRect().x(),scene->sceneRect().height()/2 - lRacket->rect().height()/2);
    ball->setPos(Global::Width/2,Global::Height/2);
    ball->changeTurn();
}

void PONG::keyPressEvent(QKeyEvent *event)
{
    if(PONG::running)
    {
        if(event->key() == Qt::Key_Up)
        {
            rRacket->changeDirection(Up);
        }
        else if(event->key() == Qt::Key_Down)
        {
            rRacket->changeDirection(Down);
        }
        else if(event->key() == Qt::Key_W)
        {
            lRacket->changeDirection(Up);
        }
        else if(event->key() == Qt::Key_S)
        {
            lRacket->changeDirection(Down);
        }
        else if(event->key() == Qt::Key_R )
        {
            ball->changeTurn();
            this->centerPosition();
        }
        else if(event->key() == Qt::Key_Escape )
        {
             pauseGame();
        }
    }

}

void PONG::keyReleaseEvent(QKeyEvent *event)
{
    if(PONG::running)
    {
        if(event->key() == Qt::Key_Up)
        {
            rRacket->changeDirection(Stop);
        }
        else if(event->key() == Qt::Key_Down)
        {
            rRacket->changeDirection(Stop);
        }
        else if(event->key() == Qt::Key_W)
        {
            lRacket->changeDirection(Stop);
        }
        else if(event->key() == Qt::Key_S)
        {
            lRacket->changeDirection(Stop);
        }
    }

}

void PONG::resizeEvent(QResizeEvent* event)
{
   QGraphicsView::resizeEvent(event);
   PONG::oldWidth = Global::Width;
   PONG::oldHeight = Global::Height;
   Global::Width = this->rect().width();
   Global::Height = this->rect().height();
   emit windowResized();
}

void PONG::closeEvent(QCloseEvent *event)
{
    timer->stop();
    gameLoopSound->stop();
    if(
        QMessageBox::question(this,tr("Quit?"),
                             tr("Do you really want to quit?"))
        == QMessageBox::Yes){

        event->accept();
        main->close();

    }
    else
    {
        event->ignore();
        if(PONG::running)
        {
            timer->start(5);
            gameLoopSound->play();

        }
    }
}


PONG::~PONG()
{

}
