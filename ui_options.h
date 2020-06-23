/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_13;
    QTabWidget *tabWidget;
    QWidget *ball_tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *ball_size_label;
    QSlider *ball_size_slider;
    QLineEdit *ball_size_edit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *ball_speed_label;
    QSlider *ball_speed_slider;
    QLineEdit *ball_speed_edit;
    QWidget *player_tab;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *player_size_label;
    QSlider *player_size_slider;
    QLineEdit *player_size_edit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *player_speed_label;
    QSlider *player_speed_slider;
    QLineEdit *player_speed_edit;
    QWidget *sound_tab;
    QCheckBox *mute_check_box;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *sound_label;
    QSlider *sound_slider;
    QLineEdit *sound_edit;
    QWidget *controls_tab;
    QRadioButton *keyboard_mode_radio_button;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *score_to_win_label;
    QSpinBox *score_to_win_spin_box;
    QCheckBox *endless_check_box;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout;
    QRadioButton *mouse_mode_radio_button;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QStringLiteral("Options"));
        Options->resize(323, 307);
        verticalLayout = new QVBoxLayout(Options);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        tabWidget = new QTabWidget(Options);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        ball_tab = new QWidget();
        ball_tab->setObjectName(QStringLiteral("ball_tab"));
        layoutWidget = new QWidget(ball_tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(13, 11, 292, 62));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        ball_size_label = new QLabel(layoutWidget);
        ball_size_label->setObjectName(QStringLiteral("ball_size_label"));

        horizontalLayout_8->addWidget(ball_size_label);

        ball_size_slider = new QSlider(layoutWidget);
        ball_size_slider->setObjectName(QStringLiteral("ball_size_slider"));
        ball_size_slider->setMinimum(5);
        ball_size_slider->setMaximum(30);
        ball_size_slider->setValue(10);
        ball_size_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(ball_size_slider);

        ball_size_edit = new QLineEdit(layoutWidget);
        ball_size_edit->setObjectName(QStringLiteral("ball_size_edit"));
        ball_size_edit->setReadOnly(true);

        horizontalLayout_8->addWidget(ball_size_edit);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        ball_speed_label = new QLabel(layoutWidget);
        ball_speed_label->setObjectName(QStringLiteral("ball_speed_label"));

        horizontalLayout_9->addWidget(ball_speed_label);

        ball_speed_slider = new QSlider(layoutWidget);
        ball_speed_slider->setObjectName(QStringLiteral("ball_speed_slider"));
        ball_speed_slider->setMinimum(5);
        ball_speed_slider->setMaximum(30);
        ball_speed_slider->setValue(10);
        ball_speed_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(ball_speed_slider);

        ball_speed_edit = new QLineEdit(layoutWidget);
        ball_speed_edit->setObjectName(QStringLiteral("ball_speed_edit"));
        ball_speed_edit->setReadOnly(true);

        horizontalLayout_9->addWidget(ball_speed_edit);


        verticalLayout_2->addLayout(horizontalLayout_9);

        tabWidget->addTab(ball_tab, QString());
        player_tab = new QWidget();
        player_tab->setObjectName(QStringLiteral("player_tab"));
        layoutWidget1 = new QWidget(player_tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(13, 11, 292, 62));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        player_size_label = new QLabel(layoutWidget1);
        player_size_label->setObjectName(QStringLiteral("player_size_label"));

        horizontalLayout_6->addWidget(player_size_label);

        player_size_slider = new QSlider(layoutWidget1);
        player_size_slider->setObjectName(QStringLiteral("player_size_slider"));
        player_size_slider->setAutoFillBackground(true);
        player_size_slider->setMinimum(5);
        player_size_slider->setMaximum(30);
        player_size_slider->setSliderPosition(10);
        player_size_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(player_size_slider);

        player_size_edit = new QLineEdit(layoutWidget1);
        player_size_edit->setObjectName(QStringLiteral("player_size_edit"));
        player_size_edit->setReadOnly(true);

        horizontalLayout_6->addWidget(player_size_edit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        player_speed_label = new QLabel(layoutWidget1);
        player_speed_label->setObjectName(QStringLiteral("player_speed_label"));

        horizontalLayout_7->addWidget(player_speed_label);

        player_speed_slider = new QSlider(layoutWidget1);
        player_speed_slider->setObjectName(QStringLiteral("player_speed_slider"));
        player_speed_slider->setMinimum(5);
        player_speed_slider->setMaximum(30);
        player_speed_slider->setSliderPosition(10);
        player_speed_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(player_speed_slider);

        player_speed_edit = new QLineEdit(layoutWidget1);
        player_speed_edit->setObjectName(QStringLiteral("player_speed_edit"));
        player_speed_edit->setReadOnly(true);

        horizontalLayout_7->addWidget(player_speed_edit);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tabWidget->addTab(player_tab, QString());
        sound_tab = new QWidget();
        sound_tab->setObjectName(QStringLiteral("sound_tab"));
        mute_check_box = new QCheckBox(sound_tab);
        mute_check_box->setObjectName(QStringLiteral("mute_check_box"));
        mute_check_box->setGeometry(QRect(3, 46, 61, 23));
        layoutWidget2 = new QWidget(sound_tab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(3, 13, 287, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sound_label = new QLabel(layoutWidget2);
        sound_label->setObjectName(QStringLiteral("sound_label"));

        horizontalLayout_3->addWidget(sound_label);

        sound_slider = new QSlider(layoutWidget2);
        sound_slider->setObjectName(QStringLiteral("sound_slider"));
        sound_slider->setMaximum(100);
        sound_slider->setSliderPosition(100);
        sound_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sound_slider);

        sound_edit = new QLineEdit(layoutWidget2);
        sound_edit->setObjectName(QStringLiteral("sound_edit"));
        sound_edit->setReadOnly(true);

        horizontalLayout_3->addWidget(sound_edit);

        tabWidget->addTab(sound_tab, QString());
        controls_tab = new QWidget();
        controls_tab->setObjectName(QStringLiteral("controls_tab"));
        keyboard_mode_radio_button = new QRadioButton(controls_tab);
        keyboard_mode_radio_button->setObjectName(QStringLiteral("keyboard_mode_radio_button"));
        keyboard_mode_radio_button->setGeometry(QRect(12, 33, 133, 23));
        keyboard_mode_radio_button->setChecked(true);
        keyboard_mode_radio_button->setAutoRepeat(false);
        keyboard_mode_radio_button->setAutoExclusive(true);
        layoutWidget3 = new QWidget(controls_tab);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(12, 62, 269, 28));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        score_to_win_label = new QLabel(layoutWidget3);
        score_to_win_label->setObjectName(QStringLiteral("score_to_win_label"));

        horizontalLayout_2->addWidget(score_to_win_label);

        score_to_win_spin_box = new QSpinBox(layoutWidget3);
        score_to_win_spin_box->setObjectName(QStringLiteral("score_to_win_spin_box"));
        score_to_win_spin_box->setMinimum(5);
        score_to_win_spin_box->setMaximum(50);
        score_to_win_spin_box->setValue(11);

        horizontalLayout_2->addWidget(score_to_win_spin_box);

        endless_check_box = new QCheckBox(layoutWidget3);
        endless_check_box->setObjectName(QStringLiteral("endless_check_box"));

        horizontalLayout_2->addWidget(endless_check_box);

        layoutWidget4 = new QWidget(controls_tab);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(12, 2, 245, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mouse_mode_radio_button = new QRadioButton(layoutWidget4);
        mouse_mode_radio_button->setObjectName(QStringLiteral("mouse_mode_radio_button"));
        mouse_mode_radio_button->setAutoRepeat(false);
        mouse_mode_radio_button->setAutoExclusive(true);

        horizontalLayout->addWidget(mouse_mode_radio_button);

        label = new QLabel(layoutWidget4);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        tabWidget->addTab(controls_tab, QString());

        verticalLayout_13->addWidget(tabWidget);

        verticalSpacer = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(Options);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_13->addWidget(buttonBox);


        verticalLayout->addLayout(verticalLayout_13);

#ifndef QT_NO_SHORTCUT
        ball_size_label->setBuddy(ball_size_slider);
        ball_speed_label->setBuddy(ball_speed_slider);
        player_size_label->setBuddy(player_size_slider);
        player_speed_label->setBuddy(player_speed_slider);
        sound_label->setBuddy(sound_slider);
        score_to_win_label->setBuddy(score_to_win_spin_box);
#endif // QT_NO_SHORTCUT

        retranslateUi(Options);
        QObject::connect(buttonBox, SIGNAL(accepted()), Options, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Options, SLOT(reject()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Settings", Q_NULLPTR));
        ball_size_label->setText(QApplication::translate("Options", "Size:     ", Q_NULLPTR));
        ball_size_edit->setInputMask(QString());
        ball_size_edit->setText(QApplication::translate("Options", "1.0", Q_NULLPTR));
        ball_speed_label->setText(QApplication::translate("Options", "Speed: ", Q_NULLPTR));
        ball_speed_edit->setInputMask(QString());
        ball_speed_edit->setText(QApplication::translate("Options", "1.0", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(ball_tab), QApplication::translate("Options", "Ball", Q_NULLPTR));
        player_size_label->setText(QApplication::translate("Options", "Size:     ", Q_NULLPTR));
        player_size_edit->setInputMask(QString());
        player_size_edit->setText(QApplication::translate("Options", "1.0", Q_NULLPTR));
        player_speed_label->setText(QApplication::translate("Options", "Speed: ", Q_NULLPTR));
        player_speed_edit->setInputMask(QString());
        player_speed_edit->setText(QApplication::translate("Options", "1.0", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(player_tab), QApplication::translate("Options", "Player", Q_NULLPTR));
        mute_check_box->setText(QApplication::translate("Options", "Mute", Q_NULLPTR));
        sound_label->setText(QApplication::translate("Options", "Sound:", Q_NULLPTR));
        sound_edit->setInputMask(QString());
        sound_edit->setText(QApplication::translate("Options", "100", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(sound_tab), QApplication::translate("Options", "Sound", Q_NULLPTR));
        keyboard_mode_radio_button->setText(QApplication::translate("Options", "Keyboard mode", Q_NULLPTR));
        score_to_win_label->setText(QApplication::translate("Options", "Score to win:", Q_NULLPTR));
        endless_check_box->setText(QApplication::translate("Options", "Endless game", Q_NULLPTR));
        mouse_mode_radio_button->setText(QApplication::translate("Options", "Mouse mode", Q_NULLPTR));
        label->setText(QApplication::translate("Options", "(Accelerating ball)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(controls_tab), QApplication::translate("Options", "Controls", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
