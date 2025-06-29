/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QPushButton *setting;
    QPushButton *choosetoplay;
    QPushButton *playlist;

    void setupUi(QDialog *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(331, 200);
        setting = new QPushButton(menu);
        setting->setObjectName(QString::fromUtf8("setting"));
        setting->setGeometry(QRect(20, 80, 91, 41));
        choosetoplay = new QPushButton(menu);
        choosetoplay->setObjectName(QString::fromUtf8("choosetoplay"));
        choosetoplay->setGeometry(QRect(120, 80, 91, 41));
        playlist = new QPushButton(menu);
        playlist->setObjectName(QString::fromUtf8("playlist"));
        playlist->setGeometry(QRect(220, 80, 91, 41));

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QDialog *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "Dialog", nullptr));
        setting->setText(QCoreApplication::translate("menu", "setting", nullptr));
        choosetoplay->setText(QCoreApplication::translate("menu", "choose to play", nullptr));
        playlist->setText(QCoreApplication::translate("menu", "playlist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
