#include "options.h"
#include "ui_options.h"
#include <iostream>


int Options::voiceLevel = 100;

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    this->setFixedSize(350,300);
    ui->setupUi(this);
    setUpConnections();

}

void Options::setUpConnections()
{
    //game items properties
    connect(ui->ball_size_slider,&QSlider::valueChanged,
            [this](const int &val)->void{ui->ball_size_edit->setText(QString::number(val/10.0));});
    connect(ui->ball_speed_slider,&QSlider::valueChanged,
            [this](const int &val)->void{ui->ball_speed_edit->setText(QString::number(val/10.0));});
    connect(ui->player_size_slider,&QSlider::valueChanged,
            [this](const int &val)->void{ui->player_size_edit->setText(QString::number(val/10.0));});
    connect(ui->player_speed_slider,&QSlider::valueChanged,
            [this](const int &val)->void{ui->player_speed_edit->setText(QString::number(val/10.0));});

    //sounds
    connect(ui->sound_slider, &QSlider::valueChanged,
            [this](const int &val)->void{
                                             if(val==0)
                                                 ui->mute_check_box->setChecked(true);
                                             else
                                             {
                                                 ui->mute_check_box->setChecked(false);
                                                 voiceLevel = val;
                                             }
                                             ui->sound_edit->setText(QString::number(val));
                                         }
            );
    connect(ui->mute_check_box, &QCheckBox::stateChanged,
            [this]()->void{
                               if(ui->mute_check_box->isChecked())
                                   ui->sound_slider->setValue(0);
                               else
                                   ui->sound_slider->setValue(voiceLevel);
                           }
            );

    //game control
    connect(ui->endless_check_box, &QCheckBox::stateChanged,
            [this]()->void{
                               if(ui->endless_check_box->isChecked())
                                   ui->score_to_win_spin_box->setEnabled(false);
                               else
                                   ui->score_to_win_spin_box->setEnabled(true);
                          }
            );

    connect(ui->mouse_mode_radio_button, &QRadioButton::clicked,
            [this](const bool &val)->void{
                                             if(val == false)
                                             {
                                                 ui->keyboard_mode_radio_button->setChecked(val);
                                                 ui->mouse_mode_radio_button->setChecked(!val);
                                             }
                                             else
                                             {
                                                 ui->keyboard_mode_radio_button->setChecked(!val);
                                                 ui->mouse_mode_radio_button->setChecked(val);
                                             }
                                          }
            );
    connect(ui->keyboard_mode_radio_button, &QRadioButton::clicked,
            [this](const bool &val)->void{
                                             if(val == false)
                                             {
                                                 ui->keyboard_mode_radio_button->setChecked(!val);
                                                 ui->mouse_mode_radio_button->setChecked(val);
                                             }
                                             else
                                             {
                                                 ui->keyboard_mode_radio_button->setChecked(val);
                                                 ui->mouse_mode_radio_button->setChecked(!val);
                                             }
                                          }
            );
}

int Options::getVoiceLevel()
{
    return voiceLevel;
}

double Options::getBallSize() const
{
    return ui->ball_size_edit->text().toDouble();
}

double Options::getBallSpeed() const
{
    return ui->ball_speed_edit->text().toDouble();
}

double Options::getPlayerSize() const
{
    return ui->player_size_edit->text().toDouble();
}

double Options::getPlayerSpeed() const
{
    return ui->player_speed_edit->text().toDouble();
}

int Options::getSound() const
{
    return ui->sound_edit->text().toInt();
}


bool Options::getMouseMode() const
{
    return ui->mouse_mode_radio_button->isChecked();
}

bool Options::getKeyboardMode() const
{
    return ui->keyboard_mode_radio_button->isChecked();
}

bool Options::getEndlessGame() const
{
    return ui->endless_check_box->isChecked();
}

unsigned int Options::getScoreToWin() const
{
    return ui->score_to_win_spin_box->value();
}

void Options::setVolume(int volume)
{
    ui->sound_slider->setValue(volume);
}

Options::~Options()
{
    delete ui;
}


