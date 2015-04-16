#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <waitingroom.h>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move (150,50);
    setWindowTitle("3D Flight Chess");
    play = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    play->setVolume(50);
//    please put the background music under /Users, and uncomment the following code
//    playlist->addMedia(QUrl::fromLocalFile("/Users/qqt.mp3"));
//    playlist->setCurrentIndex(1);
//    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
//    play->setPlaylist(playlist);
//    play->play();
    setStyleSheet("MainWindow {background-image:url(:/image/blue.png)}");
    setFixedSize(900,600);
    waitui = new waitingroom;
    setui = new set(play);
    ruleui = new rules;
    quitui = new quit;
    n = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    this->hide();
    waitui->show();
    if (!n)
        n = new netWork(waitui);
    else
        n->joinAgain();
    waitui->exec();
    n->isLeft = true;
    this->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    ruleui->show();
    ruleui->exec();
    this->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->hide();
    setui->show();
    setui->exec();
    this->show();

}

void MainWindow::on_pushButton_4_clicked()
{
    this->hide();
    quitui->show();
    quitui->exec();
    this->show();
}

void MainWindow::closeEvent(QCloseEvent *){
    if (n)
        n->sendMessage(PlayerLeft);
    qDebug()<<"playerLeft";
}
