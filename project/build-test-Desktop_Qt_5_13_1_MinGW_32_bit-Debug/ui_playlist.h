/********************************************************************************
** Form generated from reading UI file 'playlist.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_H
#define UI_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_playlist
{
public:
    QLabel *label;
    QPushButton *add;
    QPushButton *load;
    QPushButton *save;
    QPushButton *remove;
    QPushButton *reset;
    QTableView *list;

    void setupUi(QDialog *playlist)
    {
        if (playlist->objectName().isEmpty())
            playlist->setObjectName(QString::fromUtf8("playlist"));
        playlist->resize(468, 421);
        label = new QLabel(playlist);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 301, 16));
        add = new QPushButton(playlist);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(330, 30, 80, 21));
        load = new QPushButton(playlist);
        load->setObjectName(QString::fromUtf8("load"));
        load->setGeometry(QRect(330, 60, 80, 21));
        save = new QPushButton(playlist);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(330, 90, 80, 21));
        remove = new QPushButton(playlist);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(330, 120, 80, 21));
        reset = new QPushButton(playlist);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(330, 150, 80, 21));
        list = new QTableView(playlist);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 30, 311, 391));

        retranslateUi(playlist);

        QMetaObject::connectSlotsByName(playlist);
    } // setupUi

    void retranslateUi(QDialog *playlist)
    {
        playlist->setWindowTitle(QCoreApplication::translate("playlist", "Dialog", nullptr));
        label->setText(QString());
        add->setText(QCoreApplication::translate("playlist", "add", nullptr));
        load->setText(QCoreApplication::translate("playlist", "load", nullptr));
        save->setText(QCoreApplication::translate("playlist", "save", nullptr));
        remove->setText(QCoreApplication::translate("playlist", "remove", nullptr));
        reset->setText(QCoreApplication::translate("playlist", "reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playlist: public Ui_playlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_H
