#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <waitingroom.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("MainWindow {background-image:url(:/image/blue.png)}");
    this->setFixedSize(900,600);
    waitui = new waitingroom;

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
    waitui->exec();
    this->show();
}
