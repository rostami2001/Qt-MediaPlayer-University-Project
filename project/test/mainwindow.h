/* dar in file function hayi ke dar file cpp mord estefade gharar migiradamade shode ke dar file cpp
 * har kodam tarif mishavad
 * hamchenin az class hay setting va playlist ham onject baray dastrasi be function haeshan sakhte shode ast
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QLayout>
#include"playlist.h"
#include "setting.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void muted(bool muted);
    void volumeChanged(int volume);
    void stateChanged(QMediaPlayer::State state);
    void durationChanged(qint64 duration);
    void progressChanged(qint64 progress);
    void metaDataChanged();
    void playlistPositionChanged(int position);

    void on_mute_clicked();
    void on_next_clicked();
    void on_play_clicked();
    void on_previous_clicked();
    void on_stop_clicked();
    void on_volume_valueChanged(int volume);
    void on_duration_sliderMoved(int position);
    void on_open_clicked();

    void on_tracks_activated(const QModelIndex &index);
    void on_save_clicked();
    void on_add_clicked();
    void on_remove_clicked();
    void on_reset_clicked();
    void on_load_clicked();

    void on_forward_clicked();
    void on_backward_clicked();
    void on_normal_clicked();
    void on_radioButton_2_clicked();
    void on_slow_clicked();
    void on_setting_clicked();

private:
    void appendPlaylist(const QStringList& filenames);
    Ui::MainWindow *ui;
    QMediaPlayer* p;
    QVideoWidget* v;
    QMediaPlaylist* pl;
    playlist* playl;
    QLayout* l;
    setting* se;
};
#endif // MAINWINDOW_H
