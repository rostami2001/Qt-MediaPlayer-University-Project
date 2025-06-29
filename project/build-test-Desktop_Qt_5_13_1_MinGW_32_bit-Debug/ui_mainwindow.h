/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *stop;
    QPushButton *previous;
    QPushButton *play;
    QPushButton *next;
    QPushButton *mute;
    QLCDNumber *volumeDisplay;
    QSlider *volume;
    QLabel *currentDuration;
    QSlider *duration;
    QLabel *maxDuration;
    QPushButton *open;
    QGroupBox *box;
    QListView *list;
    QPushButton *save;
    QPushButton *add;
    QPushButton *remove;
    QPushButton *reset;
    QPushButton *load;
    QLabel *label;
    QPushButton *forward;
    QPushButton *backward;
    QRadioButton *normal;
    QRadioButton *radioButton_2;
    QRadioButton *slow;
    QPushButton *setting;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1011, 469);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stop = new QPushButton(centralwidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(10, 440, 71, 21));
        previous = new QPushButton(centralwidget);
        previous->setObjectName(QString::fromUtf8("previous"));
        previous->setGeometry(QRect(80, 440, 71, 21));
        play = new QPushButton(centralwidget);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(150, 440, 71, 21));
        next = new QPushButton(centralwidget);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(220, 440, 71, 21));
        mute = new QPushButton(centralwidget);
        mute->setObjectName(QString::fromUtf8("mute"));
        mute->setGeometry(QRect(290, 440, 71, 21));
        volumeDisplay = new QLCDNumber(centralwidget);
        volumeDisplay->setObjectName(QString::fromUtf8("volumeDisplay"));
        volumeDisplay->setGeometry(QRect(560, 440, 64, 23));
        volumeDisplay->setProperty("value", QVariant(50.000000000000000));
        volumeDisplay->setProperty("intValue", QVariant(50));
        volume = new QSlider(centralwidget);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setGeometry(QRect(370, 440, 171, 20));
        volume->setValue(50);
        volume->setOrientation(Qt::Horizontal);
        currentDuration = new QLabel(centralwidget);
        currentDuration->setObjectName(QString::fromUtf8("currentDuration"));
        currentDuration->setGeometry(QRect(100, 410, 51, 16));
        duration = new QSlider(centralwidget);
        duration->setObjectName(QString::fromUtf8("duration"));
        duration->setGeometry(QRect(180, 410, 451, 20));
        duration->setOrientation(Qt::Horizontal);
        maxDuration = new QLabel(centralwidget);
        maxDuration->setObjectName(QString::fromUtf8("maxDuration"));
        maxDuration->setGeometry(QRect(670, 410, 51, 20));
        open = new QPushButton(centralwidget);
        open->setObjectName(QString::fromUtf8("open"));
        open->setGeometry(QRect(10, 410, 80, 21));
        box = new QGroupBox(centralwidget);
        box->setObjectName(QString::fromUtf8("box"));
        box->setGeometry(QRect(0, -20, 721, 421));
        list = new QListView(centralwidget);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(730, 20, 271, 381));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(730, 410, 80, 21));
        add = new QPushButton(centralwidget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(820, 410, 80, 21));
        remove = new QPushButton(centralwidget);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(910, 410, 80, 21));
        reset = new QPushButton(centralwidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(730, 440, 80, 21));
        load = new QPushButton(centralwidget);
        load->setObjectName(QString::fromUtf8("load"));
        load->setGeometry(QRect(820, 440, 80, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(720, 0, 281, 16));
        forward = new QPushButton(centralwidget);
        forward->setObjectName(QString::fromUtf8("forward"));
        forward->setGeometry(QRect(640, 410, 21, 21));
        backward = new QPushButton(centralwidget);
        backward->setObjectName(QString::fromUtf8("backward"));
        backward->setGeometry(QRect(150, 410, 21, 21));
        normal = new QRadioButton(centralwidget);
        normal->setObjectName(QString::fromUtf8("normal"));
        normal->setGeometry(QRect(650, 430, 61, 19));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(630, 450, 51, 19));
        slow = new QRadioButton(centralwidget);
        slow->setObjectName(QString::fromUtf8("slow"));
        slow->setGeometry(QRect(680, 450, 51, 19));
        setting = new QPushButton(centralwidget);
        setting->setObjectName(QString::fromUtf8("setting"));
        setting->setGeometry(QRect(910, 440, 80, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        stop->setText(QString());
        previous->setText(QString());
        play->setText(QString());
        next->setText(QString());
        mute->setText(QString());
        currentDuration->setText(QCoreApplication::translate("MainWindow", "  --:--:--", nullptr));
        maxDuration->setText(QCoreApplication::translate("MainWindow", "  --:--:--", nullptr));
        open->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
        box->setTitle(QString());
        save->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        remove->setText(QCoreApplication::translate("MainWindow", "remove", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        load->setText(QCoreApplication::translate("MainWindow", "load", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "playlist:", nullptr));
        forward->setText(QCoreApplication::translate("MainWindow", "f", nullptr));
        backward->setText(QCoreApplication::translate("MainWindow", "b", nullptr));
        normal->setText(QCoreApplication::translate("MainWindow", "normal", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "fast", nullptr));
        slow->setText(QCoreApplication::translate("MainWindow", "slow", nullptr));
        setting->setText(QCoreApplication::translate("MainWindow", "setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
