#include "quit.h"
#include "ui_quit.h"

quit::quit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quit)
{
    ui->setupUi(this);
    move (150,50);
    setWindowTitle("3D Flight Chess");
    setStyleSheet("quit {background-image:url(:/image/11159.jpg)}");
    setFixedSize(900,600);
}

quit::~quit()
{
    delete ui;
}

void quit::on_pushButton_clicked()
{
    this->hide();
}

void quit::on_pushButton_2_clicked()
{
    exit(1);
}
