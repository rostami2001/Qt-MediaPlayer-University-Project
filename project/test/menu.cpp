#include "menu.h"
#include "ui_menu.h"


menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

// farakhani playlist tavasot in function anjam mishavad
void menu::on_playlist_clicked()
{
    this->hide();
    m = new MainWindow(this);
    m->show();
}

// farakhani mediaplayer tavasot in function anjam mishavad
void menu::on_choosetoplay_clicked()
{
    this->hide();
    m = new MainWindow(this);
    m->show();
}

// farakhani setting tavasot in function anjam mishavad
void menu::on_setting_clicked()
{
    this->hide();
    st = new setting(this);
    st->show();
}
