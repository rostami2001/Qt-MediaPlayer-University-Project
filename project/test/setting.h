#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QMediaPlaylist>
#include"playlist.h"


namespace Ui {
class setting;
}

class setting : public QDialog
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = nullptr);
    ~setting();


private:
    Ui::setting *ui;
    QMediaPlaylist* plylist;
    playlist* plt;
};

#endif // SETTING_H
