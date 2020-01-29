/********************************************************************************
** Form generated from reading UI file 'audioplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOPLAYER_H
#define UI_AUDIOPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioPlayer
{
public:
    QAction *actionLoad_single_song;
    QAction *actionLoad_Playlist;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QPushButton *bt_stop;
    QPushButton *bt_play;
    QLCDNumber *lcd;
    QSlider *sl_tracking;
    QLabel *lb_screen;
    QSlider *sl_volume;
    QLabel *label;
    QPushButton *bt_load;

    void setupUi(QMainWindow *AudioPlayer)
    {
        if (AudioPlayer->objectName().isEmpty())
            AudioPlayer->setObjectName(QString::fromUtf8("AudioPlayer"));
        AudioPlayer->resize(900, 560);
        AudioPlayer->setMinimumSize(QSize(900, 560));
        AudioPlayer->setMaximumSize(QSize(900, 560));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        AudioPlayer->setWindowIcon(icon);
        AudioPlayer->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color: rgb(0, 0, 0);\n"
"}"));
        actionLoad_single_song = new QAction(AudioPlayer);
        actionLoad_single_song->setObjectName(QString::fromUtf8("actionLoad_single_song"));
        actionLoad_Playlist = new QAction(AudioPlayer);
        actionLoad_Playlist->setObjectName(QString::fromUtf8("actionLoad_Playlist"));
        centralWidget = new QWidget(AudioPlayer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: rgb(245, 121, 0);\n"
"}"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 861, 563));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        bt_stop = new QPushButton(layoutWidget);
        bt_stop->setObjectName(QString::fromUtf8("bt_stop"));
        bt_stop->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(85, 87, 83);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        bt_stop->setIcon(icon1);

        formLayout->setWidget(4, QFormLayout::LabelRole, bt_stop);

        bt_play = new QPushButton(layoutWidget);
        bt_play->setObjectName(QString::fromUtf8("bt_play"));
        bt_play->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(85, 87, 83);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        bt_play->setIcon(icon2);

        formLayout->setWidget(5, QFormLayout::LabelRole, bt_play);

        lcd = new QLCDNumber(layoutWidget);
        lcd->setObjectName(QString::fromUtf8("lcd"));
        lcd->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        lcd->setDigitCount(8);

        formLayout->setWidget(3, QFormLayout::LabelRole, lcd);

        sl_tracking = new QSlider(layoutWidget);
        sl_tracking->setObjectName(QString::fromUtf8("sl_tracking"));
        sl_tracking->setOrientation(Qt::Horizontal);

        formLayout->setWidget(3, QFormLayout::FieldRole, sl_tracking);

        lb_screen = new QLabel(layoutWidget);
        lb_screen->setObjectName(QString::fromUtf8("lb_screen"));
        lb_screen->setMinimumSize(QSize(760, 450));
        lb_screen->setMaximumSize(QSize(760, 450));
        lb_screen->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 0, 0);\n"
"}"));
        lb_screen->setPixmap(QPixmap(QString::fromUtf8(":/imgs/icon.png")));
        lb_screen->setScaledContents(false);
        lb_screen->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, lb_screen);

        sl_volume = new QSlider(centralWidget);
        sl_volume->setObjectName(QString::fromUtf8("sl_volume"));
        sl_volume->setGeometry(QRect(60, 130, 20, 311));
        sl_volume->setValue(99);
        sl_volume->setOrientation(Qt::Vertical);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 450, 51, 20));
        bt_load = new QPushButton(centralWidget);
        bt_load->setObjectName(QString::fromUtf8("bt_load"));
        bt_load->setGeometry(QRect(40, 494, 61, 31));
        bt_load->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(85, 87, 83);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        AudioPlayer->setCentralWidget(centralWidget);

        retranslateUi(AudioPlayer);

        QMetaObject::connectSlotsByName(AudioPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *AudioPlayer)
    {
        AudioPlayer->setWindowTitle(QCoreApplication::translate("AudioPlayer", "Qt Media Player", nullptr));
        actionLoad_single_song->setText(QCoreApplication::translate("AudioPlayer", "Load single song", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad_single_song->setShortcut(QCoreApplication::translate("AudioPlayer", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad_Playlist->setText(QCoreApplication::translate("AudioPlayer", "Load Playlist", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad_Playlist->setShortcut(QCoreApplication::translate("AudioPlayer", "Ctrl+Shift+O", nullptr));
#endif // QT_CONFIG(shortcut)
        bt_stop->setText(QCoreApplication::translate("AudioPlayer", "Stop", nullptr));
        bt_play->setText(QCoreApplication::translate("AudioPlayer", "Play", nullptr));
        lb_screen->setText(QString());
        label->setText(QCoreApplication::translate("AudioPlayer", "Volume", nullptr));
        bt_load->setText(QCoreApplication::translate("AudioPlayer", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioPlayer: public Ui_AudioPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOPLAYER_H
