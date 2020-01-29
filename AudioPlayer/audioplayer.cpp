#include "audioplayer.h"
#include "ui_audioplayer.h"

#include <QVideoWidget>
#include <QGraphicsVideoItem>
#include <QCameraViewfinder>
#include <QFileDialog>
#include <QDebug>

AudioPlayer::AudioPlayer(QWidget *parent) : QMainWindow(parent), ui(new Ui::AudioPlayer){

    ui->setupUi(this);

    this->player = new QMediaPlayer(this);
    this->vw = new QVideoWidget(this);
    this->player->setVideoOutput(this->vw);

    this->vw->setGeometry(117, 80, ui->lb_screen->width(), ui->lb_screen->height());
    this->vw->hide();

    this->player->setVolume(ui->sl_volume->value());

    connect(player, &QMediaPlayer::durationChanged, ui->sl_tracking, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, ui->sl_tracking, &QSlider::setValue);
    connect(player, &QMediaPlayer::positionChanged, this, &AudioPlayer::positionChanged);
    connect(ui->sl_tracking, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

    ui->lcd->display("00:00:00");

    ui->bt_stop->setEnabled(false);
    ui->bt_play->setEnabled(false);
}

AudioPlayer::~AudioPlayer(){
    delete ui;
    delete vw;
    delete player;
    delete viewFinder;
}


void AudioPlayer::on_bt_stop_clicked(){

    ui->sl_tracking->setValue(0);
    player->stop();
    ui->bt_play->setText("Play");
    ui->bt_play->setIcon(QIcon(":/imgs/play.png"));

    this->isPlaying = false;

    ui->bt_stop->setEnabled(false);


    ui->lcd->display(QString::fromStdString("00:00:00"));

}

void AudioPlayer::on_bt_play_clicked(){
    if(this->player->isVideoAvailable()){
        ui->lb_screen->clear();
        this->vw->show();

    }else{
        this->vw->close();
        ui->lb_screen->setPixmap(QPixmap(":/imgs/icon.png"));
    }

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

    this->player->setMedia(QUrl::fromLocalFile(filename));

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
}

void AudioPlayer::on_sl_volume_valueChanged(int value){
    player->setVolume(value);
}
