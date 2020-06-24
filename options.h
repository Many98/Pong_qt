#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT
    static int voiceLevel;
    void setUpConnections();

public:
    explicit Options(QWidget *parent = 0);
    ~Options();
    double getBallSize();
    double getBallSpeed();
    double getPlayerSize();
    double getPlayerSpeed();
    int getSound();
    bool getMouseMode();
    bool getKeyboardMode();
    bool getEndlessGame();
    unsigned int getScoreToWin();
    static int getVoiceLevel();

public slots:
    void setSound(int volume);


private:
    Ui::Options *ui;

};

#endif // OPTIONS_H
