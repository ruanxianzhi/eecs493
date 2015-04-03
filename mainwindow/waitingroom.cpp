#include "waitingroom.h"
#include "ui_waitingroom.h"
#include <QDebug>
#include <QOpenGLWidget>

waitingroom::waitingroom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waitingroom)
{
    ui->setupUi(this);

    fnt.setFamily("HanziPen SC");
    setStyleSheet("waitingroom {background-image:url(:/image/tablenwait.png)}");
    this->setFixedSize(900,600);
    QStringList header;
    header<<tr("User Name");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color: QColor(189,202,242,000);border: none;}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section {background-color :QColor(189,202,242,000);border:none;}");
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    tw = ui->tableWidget;
    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    //font.setPointSize(80);
    ui->tableWidget->horizontalHeader()->setFont(font);
    ui->tableWidget->setFrameShape(QFrame::NoFrame);

    red = ui->pushButton_2;
    blue = ui->pushButton_3;
    green = ui->pushButton_4;
    yellow = ui->pushButton_5;
    leave = ui->pushButton;
    QPalette pal;
    pal.setColor(QPalette::Base, QColor(235,241,184));
    //pal.setBrush(this->backgroundRole(),QBrush(QPixmap("images/tableback.jpg")) );
    pal.setColor(QPalette::AlternateBase, QColor(184,235,241));
    ui->tableWidget->setPalette(pal);
    ui->tableWidget->setFrameShape(QFrame::NoFrame);
    ui->tableWidget->setAlternatingRowColors(true);

}

waitingroom::~waitingroom()
{
    delete ui;
}

bool waitingroom::updateUser(QString userName,QString localHostName,QString ipAddress){
    bool bb = ui->tableWidget->findItems(userName,Qt::MatchExactly).isEmpty();
    if(bb)
    {
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        //QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        //user->setBackgroundColor(QColor(184,235,241));
        //host->setBackgroundColor(QColor(184,235,241));

        fnt.setPointSize(22);
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,user);
        ui->tableWidget->item(0,0)->setFont(fnt);
        ui->tableWidget->item(0,0)->setTextAlignment(Qt::AlignCenter);
        //ui->tableWidget->setItem(0,1,host);
        //ui->tableWidget->item(0,1)->setFont(fnt);
    }
    return bb;
}

void waitingroom::updatelabel(QString userName, QString color){
    if (color == "red"){
        ui->red->setText(userName);
    }
    else if (color == "blue")
        ui->label_2->setText(userName);
    else if (color == "green")
        ui->label_3->setText(userName);

    else if (color == "yellow")
        ui->label_4->setText(userName);

}

