#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    plylist = new QMediaPlaylist();
}

setting::~setting()
{
    delete ui;
}
