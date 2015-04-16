#include "endwindow.h"
#include "ui_endwindow.h"

endwindow::endwindow(int wincolor, QString winnername, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endwindow)
{
    ui->setupUi(this);
    move (150,50);
    setWindowTitle("3D Flight Chess");
    setFixedSize(900,600);
    setStyleSheet("endwindow {background-image:url(:/image/vic.jpg)}");
    ui->toolButton->setEnabled(false);
    QPixmap pixmap(":/image/plane.png");
    QIcon icon(pixmap);
    ui->toolButton->setIcon(icon);
    ui->toolButton->setIconSize(QSize(65,65));
    ui->label_2->setText(winnername);
    if(wincolor == 0){
        ui->toolButton->setStyleSheet("background-color:rgb(201,2,2);border: 2px solid #8f8f91; border-radius: 20px");
    }
    else if(wincolor==1){
        ui->toolButton->setStyleSheet("background-color:rgb(255,191,00);border: 2px solid #8f8f91; border-radius: 20px");
    }
    else if(wincolor==2){
        ui->toolButton->setStyleSheet("background-color: rgb(70,222,40);border: 2px solid #8f8f91; border-radius: 20px");
    }
    else{
        ui->toolButton->setStyleSheet("background-color: rgb(0,33,250);border: 2px solid #8f8f91; border-radius: 20px");
    }

}

endwindow::~endwindow()
{
    delete ui;
}

void endwindow::on_pushButton_2_clicked()
{
    exit(1);
}

