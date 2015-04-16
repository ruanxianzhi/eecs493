#include "set.h"
#include "ui_set.h"
#include <QMediaPlayer>

set::set(QMediaPlayer *input, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::set)
{
    ui->setupUi(this);
    move (150,50);
    setWindowTitle("3D Flight Chess");
    play=input;
    fnt.setFamily("HanziPen SC");
    setStyleSheet("set {background-image:url(:/image/11159.jpg)}");
    setFixedSize(900,600);
    ui->slider->setRange(0, 100);
    ui->slider->setValue(play->volume());
}

set::~set()
{
    delete ui;
}

void set::on_pushButton_clicked()
{
    this->hide();
    play->setVolume(ui->slider->value());
}

void set::on_pushButton_2_clicked()
{
    this->hide();
    ui->slider->setValue(play->volume());
}
