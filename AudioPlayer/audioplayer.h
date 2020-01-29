#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QCameraViewfinder>
namespace Ui {
class AudioPlayer;
}

class AudioPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit AudioPlayer(QWidget *parent = nullptr);
    ~AudioPlayer();

private slots:
    // sets new QMediaPlayer to play music and video
    void init(QString path = "");
    // Stops execution of QMediaPlayer
    void on_bt_stop_clicked();
    // Starts/Pauses the QMediaPlayer execution
    void on_bt_play_clicked();
    // Loads a file into application
    void on_bt_load_clicked();
    // Track time of song and display in progress bar
    void positionChanged(qint64);
    // Stops QMediaPlayer execution
    void stopSong(bool stop);
    // Change volume through slider
    void on_sl_volume_valueChanged(int value);

private:
    Ui::AudioPlayer *ui;
    QMediaPlayer *player;
    QCameraViewfinder *viewFinder;
    QVideoWidget *vw;

    bool isPlaying = false;
    int Fs = 956;
    QString query;
};

#endif // AUDIOPLAYER_H
