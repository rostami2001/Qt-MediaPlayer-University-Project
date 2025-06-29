/* in file marbot be meno aval mibashad va az tamami class ha dar in file object sakhte shode ast
*/

#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow.h"
#include "playlist.h"
#include "setting.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_playlist_clicked();

    void on_choosetoplay_clicked();

    void on_setting_clicked();

private:
    Ui::menu *ui;
    MainWindow* m;
    playlist* pl;
    setting* st;
};

#endif // MENU_H
