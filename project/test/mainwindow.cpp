/* dar in file har yek az tavabe file .h tarif va piyade sazi shode ast
 * dar kenar har function tozih marboot dade shode ast
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMediaMetaData>
#include <QMessageBox>
#include <QSaveFile>
#include <QTime>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pl = new QMediaPlaylist();
    pl->setPlaybackMode(QMediaPlaylist::Sequential);

    p = new QMediaPlayer(this);

    p->setPlaylist(pl);

    playl = new playlist();
    playl->setPlaylist(pl);

    v = new QVideoWidget(this);
    l = new QVBoxLayout();

    l->addWidget(v);
    ui->box->setLayout(l);
    p->setVideoOutput(v);

    // bargharar kardan ertebat ha be vasile signal va slot
    // signal ya metodi ke mikhahim ra midahim
    // slot ya chizi ke mikhahim ham moshakhas mikonim
    connect(p, SIGNAL(mutedChanged(bool)), SLOT(muted(bool)));
    connect(p, SIGNAL(volumeChanged(int)), SLOT(volumeChanged(int)));
    connect(p, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(stateChanged(QMediaPlayer::State)));
    connect(p, SIGNAL(durationChanged(qint64)), SLOT(durationChanged(qint64)));
    connect(p, SIGNAL(positionChanged(qint64)), SLOT(progressChanged(qint64)));
    connect(p, SIGNAL(metaDataChanged()), SLOT(metaDataChanged()));
    connect(p, SIGNAL(error(QMediaPlayer::Error)), SLOT(displayErrorMessage()));

    connect(pl, SIGNAL(currentIndexChanged(int)), SLOT(playlistPositionChanged(int)));

    // set kardan item hay har botten
     ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
     ui->previous->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
     ui->next->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
     ui->stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
     ui->mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));


     ui->list->setModel(playl);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// mute kardan
void MainWindow::muted(bool muted)
{
    if (muted) {
        ui->volume->setValue(0);
        ui->volumeDisplay->display(0);
    } else {
        ui->volume->setValue(p->volume());
        ui->volumeDisplay->display(p->volume());
    }

    // taghir icon
    ui->mute->setIcon(muted ? style()->standardIcon(QStyle::SP_MediaVolumeMuted)
                            : style()->standardIcon(QStyle::SP_MediaVolume));
}

// taghir mizan seda
void MainWindow::volumeChanged(int volume)
{
    ui->volume->setValue(p->volume());
    ui->volumeDisplay->display(p->volume());
}

// taghir vazeiat
void MainWindow::stateChanged(QMediaPlayer::State state)
{
    switch (state) {
    case QMediaPlayer::PlayingState:
        // agar dar hal pakhsh bood va pause shod icon taghir kone va slider motevaghef beshe
        ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        ui->duration->setEnabled(true);
        break;

    case QMediaPlayer::PausedState:
        // agar pause bood play beshe va icon taghir kone va slider shoro be harkat kone
        ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        ui->duration->setEnabled(true);
        break;

    case QMediaPlayer::StoppedState:
        // agar stop bood play beshe va icon taghir kone va slider shoro be harkat kone
        ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        ui->duration->setEnabled(false);

        // taghir time gozashte va baghi mande
        ui->currentDuration->setText("--:--:--");
        ui->maxDuration->setText("--:--:--");
        break;
    }
}

// taghir slider video
void MainWindow::durationChanged(qint64 duration)
{
    ui->duration->setMaximum(duration / 1000);
}

void MainWindow::progressChanged(qint64 progress)
{
    // taghir dadan slider video
    if (!ui->duration->isSliderDown()) {
        ui->duration->setValue(progress / 1000);
    }

    if (progress) {
        qint64 duration = p->duration() / 1000;
        qint64 current = progress / 1000;

        QTime currentTime((current/3600)%60, (current/60)%60, current%60, (current*1000)%1000);
        QTime totalTime((duration/3600)%60, (duration/60)%60, duration%60, (duration*1000)%1000);

        QString format = duration < 3600 ? "mm:ss" : "hh:mm:ss";

        ui->currentDuration->setText(currentTime.toString(format));
        ui->maxDuration->setText(totalTime.toString(format));
    }
}

void MainWindow::metaDataChanged()
{
    if (p->state() == QMediaPlayer::PlayingState ||
        p->state() == QMediaPlayer::PausedState)
    {
        // taghir titel
        setWindowTitle(QString("Media Player: %1 - %2")
                       .arg(p->metaData(QMediaMetaData::AlbumArtist).toString())
                       .arg(p->metaData(QMediaMetaData::Title).toString()));
    } else {
        setWindowTitle("Media Player");
    }
}

// taghir vaziat playlist
void MainWindow::playlistPositionChanged(int position)
{
    ui->list->setCurrentIndex(playl->index(position, 0));
}


void MainWindow::on_tracks_activated(const QModelIndex& index)
{
    if (index.isValid()) {
        pl->setCurrentIndex(index.row());
    }
}

// mute kardan
void MainWindow::on_mute_clicked()
{
    if (p->isMuted())
            p->setMuted(false);
        else
            p->setMuted(true);
}

// raftan be file badi
void MainWindow::on_next_clicked()
{
    pl->next();
}

// play kardan
void MainWindow::on_play_clicked()
{
    if (p->state() == QMediaPlayer::PlayingState) {
            p->pause();
        } else {
            p->play();
        }

}

// raftan ba file ghabli
void MainWindow::on_previous_clicked()
{
    pl->previous();

}

// stop kardan
void MainWindow::on_stop_clicked()
{
    if (p->state() == QMediaPlayer::PlayingState) {
            ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            p->stop();

            // Reset the window title.
            setWindowTitle("Media Player");
        }

}

// taghir seda
void MainWindow::on_volume_valueChanged(int volume)
{
    if (volume == 0) {
            p->setMuted(true);
        } else {
            p->setMuted(false);
            p->setVolume(volume);
        }

}

// taghir makan slider film
void MainWindow::on_duration_sliderMoved(int position)
{
        p->setPosition(position * 1000);
}

// upload file
void MainWindow::on_open_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a file","","video file (" ")");
    on_stop_clicked();
    p->setMedia(QUrl::fromLocalFile(filename));
    on_play_clicked();

}

void MainWindow::on_save_clicked()
{

    // taein esm baray playlist
        QString filename = QFileDialog::getSaveFileName(
                    this,
                    QString("Save Playlist As..."),
                    QDir::homePath(),
                    QString("Simple Playlist Files (*.spf);;All Files and Folders (*.*)"));

        if (filename.isEmpty())
            return;

        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            out << "Simple Playlist Format 1.0\n";

            for (int i = 0; i < pl->mediaCount(); ++i) {
                // gereftan etelaat file
                QMediaContent content = pl->media(i);
                QUrl location = content.canonicalUrl();
                QFileInfo info(location.path());
                QString path = info.filePath();


                out << path.right(path.length() - 1) << "\n";
            }

            // payam save shodam ya nashodan
            QMessageBox messageBox;
            messageBox.setText("Playlist successfully saved.");
            messageBox.setIcon(QMessageBox::Information);
            messageBox.exec();
        } else {
            QMessageBox messageBox;
            messageBox.setText("An error occurred while saving the playlist.");
            messageBox.setIcon(QMessageBox::Critical);
            messageBox.exec();
        }

}

// ezafe kardan file be playlist
void MainWindow::on_add_clicked()
{
        QStringList filenames = QFileDialog::getOpenFileNames(
                    this,
                    QString("Add Tracks"),
                    QDir::homePath(),
                    QString("Audio Files (*.mp3 *.m3u);;All Files and Folders (*.*)"));
        appendPlaylist(filenames);
}


void MainWindow::appendPlaylist(const QStringList& filenames)
{
        // Load kardan file entekhab shode
        foreach (const QString& filename, filenames) {
            QFileInfo info(filename);

            if (info.exists()) {
                QUrl url = QUrl::fromLocalFile(info.absoluteFilePath());

                if (info.suffix().toLower() == QString("m3u")) {
                    pl->load(url);
                } else {
                    pl->addMedia(url);
                }
            } else {
                QUrl url(filename);

                if (url.isValid()) {
                    pl->addMedia(url);
                }
            }
        }

}

// remove kardan file entekhab shode
void MainWindow::on_remove_clicked()
{
        QModelIndexList selection = ui->list->selectionModel()->selectedIndexes();
        pl->removeMedia(selection.first().row());
}

// remove kardan hame playlist
void MainWindow::on_reset_clicked()
{
        if (p->state() == QMediaPlayer::PlayingState ||
            p->state() == QMediaPlayer::PausedState)
        {
            p->stop();
        }

        pl->clear();

}

// pakhsh kardan file
void MainWindow::on_load_clicked()
{
    on_stop_clicked();
    QModelIndexList selection = ui->list->selectionModel()->selectedIndexes();
    p->play();
}

// 10 sec jolo raftan
void MainWindow::on_forward_clicked()
{
    p->setPosition(p->position() + 10000);
    p->play();
}

// 10 sec aghab raftam
void MainWindow::on_backward_clicked()
{
    p->setPosition(p->position() - 10000);
    p->play();
}

// tanzim sorat normal
void MainWindow::on_normal_clicked()
{
    p->setPlaybackRate(1);
}

// tanzim sorat ziyad
void MainWindow::on_radioButton_2_clicked()
{
    p->setPlaybackRate(2);
}

// tanzim sorat kam
void MainWindow::on_slow_clicked()
{
    p->setPlaybackRate(0.5);
}

//ragtan be setting
void MainWindow::on_setting_clicked()
{
   // this->hide();
    se = new setting(this);
    se->show();
}
