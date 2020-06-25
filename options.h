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
    double getBallSize() const;
    double getBallSpeed() const;
    double getPlayerSize() const;
    double getPlayerSpeed() const;
    int getSound() const;
    bool getMouseMode() const;
    bool getKeyboardMode() const;
    bool getEndlessGame() const;
    unsigned int getScoreToWin() const;
    static int getVoiceLevel();
    void setVolume(int volume);

private:
    Ui::Options *ui;

};

#endif // OPTIONS_H
