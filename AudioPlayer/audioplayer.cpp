#include "audioplayer.h"
#include "ui_audioplayer.h"

#include <QVideoWidget>
#include <QGraphicsVideoItem>
#include <QCameraViewfinder>
#include <QFileDialog>
#include <QDebug>

AudioPlayer::AudioPlayer(QWidget *parent) : QMainWindow(parent), ui(new Ui::AudioPlayer){

    ui->setupUi(this);

    player = new QMediaPlayer();
    vw = new QVideoWidget(this);

    init();

    ui->lcd->display("00:00:00");

    ui->bt_stop->setEnabled(false);
    ui->bt_play->setEnabled(false);
}

void AudioPlayer::init(QString path){
    delete vw;
    delete player;

    player = new QMediaPlayer();
    vw = new QVideoWidget(this);

    if(player->isVideoAvailable()){
        player->setVideoOutput(vw);
        vw->setGeometry(ui->lb_screen->geometry());
        vw->show();
    }


    player->setMedia(QUrl::fromLocalFile(path));
    player->setVolume(ui->sl_volume->value());

    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    connect(player, SIGNAL(audioAvailableChanged(bool)), this, SLOT(stopSong(bool)));
}

AudioPlayer::~AudioPlayer(){
    delete ui;
    delete vw;
    delete player;
    delete viewFinder;
}


void AudioPlayer::on_bt_stop_clicked(){
    this->stopSong(false);
}

void AudioPlayer::on_bt_play_clicked(){

    if(this->isPlaying == true){
        player->pause();
        this->isPlaying = false;
        ui->bt_play->setText("Play");
        ui->bt_play->setIcon(QIcon(":/imgs/play.png"));
    }else{
        player->play();
        this->isPlaying = true;
        ui->bt_play->setText("Pause");
        ui->bt_play->setIcon(QIcon(":/imgs/pause.png"));
    }
    ui->bt_stop->setEnabled(true);
}

void AudioPlayer::on_bt_load_clicked(){
    const QString filename = QFileDialog::getOpenFileName(this, "Open");
    if(filename.isEmpty()){
        return;
    }

    init(filename);

    ui->bt_play->setEnabled(true);
    on_bt_stop_clicked();
}

void AudioPlayer::positionChanged(qint64 value){
    if(value/Fs < 600){
        if((value/Fs)%60 < 10){
            query = "0" + QString::number(value/(3600*Fs)) + ":0" + QString::number(value/(60*Fs)) + ":0" + QString::number((value/Fs)%60);
        }else{
            query = "0" + QString::number(value/(3600*Fs)) + ":0" + QString::number(value/(60*Fs)) + ":" + QString::number((value/Fs)%60);
        }
    }else{
        if(value/Fs < 10){
            query = "0" + QString::number(value/(3600*Fs)) + ":" + QString::number(value/(60*Fs)) + ":0" + QString::number((value/Fs)%60);
        }else{
            query = "0" + QString::number(value/(3600*Fs)) + ":" + QString::number(value/(60*Fs)) + ":" + QString::number((value/Fs)%60);
        }
    }
    if(!isPlaying){
        query = "00:00:00";
    }
    ui->lcd->display(query);
    ui->progressBar->setValue(((100*value)/player->duration()));
}

void AudioPlayer::stopSong(bool stop){
    if(!stop){
        player->stop();
        ui->bt_play->setText("Play");

        this->isPlaying = false;

        ui->bt_stop->setEnabled(false);
        ui->progressBar->setValue(0);

        ui->lcd->display(QString::fromStdString("00:00:00"));
    }

}

void AudioPlayer::on_sl_volume_valueChanged(int value){
    player->setVolume(value);
}
