#include "waitingroom.h"
#include "ui_waitingroom.h"

waitingroom::waitingroom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waitingroom)
{
    ui->setupUi(this);
    setStyleSheet("waitingroom {background-image:url(:/image/wt_meitu_1.jpg)}");
    this->setFixedSize(900,600);

}

waitingroom::~waitingroom()
{
    delete ui;
}
