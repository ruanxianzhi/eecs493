#include "waitingroom.h"
#include "ui_waitingroom.h"
#include <QDebug>

waitingroom::waitingroom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waitingroom)
{
    ui->setupUi(this);
    setStyleSheet("waitingroom {background-image:url(:/image/wt_meitu_1.jpg)}");
    this->setFixedSize(900,600);
    QPalette pal;
    pal.setColor(QPalette::Base, QColor(235,241,184));
    pal.setColor(QPalette::AlternateBase, QColor(184,235,241));
    ui->tableWidget->setPalette(pal);
    ui->tableWidget->setAlternatingRowColors(true);
}

waitingroom::~waitingroom()
{
    delete ui;
}

bool waitingroom::updateUser(QString userName,QString localHostName,QString ipAddress){
    bool bb = ui->tableWidget->findItems(localHostName,Qt::MatchExactly).isEmpty();
    if(bb)
    {
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        //user->setBackgroundColor(QColor(184,235,241));
        //host->setBackgroundColor(QColor(184,235,241));
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,user);
        ui->tableWidget->setItem(0,1,host);
    }
    return bb;
}
