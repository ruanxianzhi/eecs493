#include "rules.h"
#include "ui_rules.h"

rules::rules(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rules)
{
    ui->setupUi(this);
    move (150,50);
    setWindowTitle("3D Flight Chess");
    counter = 0;
    front = ui->toolButton;
    back = ui->toolButton_2;
    image1 = ui->label;
    image2 = ui->label_2;
    text1 = ui->label_3;
    text2 = ui->label_4;
    front->setEnabled(false);
    back->setEnabled(true);
    QPixmap *newmap1 = new QPixmap(":/image/rule1.png");
    image1->setPixmap(((*newmap1).scaled(300,300,Qt::KeepAspectRatio)));
    image1->setFixedSize(300,300);
    QPixmap *newmap2 = new QPixmap(":/image/rule2.jpeg");
    image2->setPixmap(((*newmap2).scaled(300,300,Qt::KeepAspectRatio)));
    image2->setFixedSize(300,300);
    text1->setText("The game has a capacity of four players, and each player \n has four airplanes at their bases at the start of the game");
    text2->setText("Every time the dice turns to be six, the player can choose to \n move one airplane out of base and get ready to start. Also, \n they get an extra chance to roll.");
    fnt.setFamily("HanziPen SC");
    setStyleSheet("rules {background-image:url(:/image/11159.jpg)}");

    setFixedSize(900,600);
}

rules::~rules()
{
    delete ui;
}

void rules::on_toolButton_clicked()
{
    if(counter == 1){
        front->setEnabled(false);
        QPixmap *newmap1 = new QPixmap(":/image/rule1.png");
        image1->setPixmap(((*newmap1).scaled(300,300,Qt::KeepAspectRatio)));
        image1->setFixedSize(300,300);
        QPixmap *newmap2 = new QPixmap(":/image/rule2.jpeg");
        image2->setPixmap(((*newmap2).scaled(300,300,Qt::KeepAspectRatio)));
        image2->setFixedSize(300,300);
        text1->setText("The game has a capacity of four players, and each player \n has four airplanes at their bases at the start of the game");
        text2->setText("Every time the dice turns to be six, the player can choose to \n move one airplane out of base and get ready to start. Also, \n they get an extra chance to roll.");
        counter--;
    }
    else if(counter == 2){
        back->setEnabled(true);
        QPixmap *newmap1 = new QPixmap(":/image/rule3.jpeg");
        image1->setPixmap(((*newmap1).scaled(300,300,Qt::KeepAspectRatio)));
        image1->setFixedSize(300,300);
        text1->setText("When airplane lands on the grid with same color, it can \n jump to next grid with same color");
        QPixmap *newmap2 = new QPixmap(":/image/rule4.jpeg");
        image2->setPixmap(((*newmap2).scaled(300,300,Qt::KeepAspectRatio)));
        image2->setFixedSize(300,300);
        text2->setText("When airplane hits on another plane with different color, \n the hitted plane has to go back to base");
        counter--;
    }
}

void rules::on_toolButton_2_clicked()
{
    if(counter == 0){
        front->setEnabled(true);
        QPixmap *newmap1 = new QPixmap(":/image/rule3.jpeg");
        image1->setPixmap(((*newmap1).scaled(300,300,Qt::KeepAspectRatio)));
        image1->setFixedSize(300,300);
        text1->setText("When airplane lands on the grid with same color, it can \n jump to next grid with same color");
        QPixmap *newmap2 = new QPixmap(":/image/rule4.jpeg");
        image2->setPixmap(((*newmap2).scaled(300,300,Qt::KeepAspectRatio)));
        image2->setFixedSize(300,300);
        text2->setText("When airplane hits on another plane with different color, \n the hitted plane has to go back to base");
        counter++;
    }
    else if(counter == 1){
        back->setEnabled(false);
        QPixmap *newmap1 = new QPixmap(":/image/rule5.jpeg");
        image1->setPixmap(((*newmap1).scaled(300,300,Qt::KeepAspectRatio)));
        image1->setFixedSize(300,300);
        text1->setText("        The center of the board is destination");
        QPixmap *newmap2 = new QPixmap(":/image/rule6.jpeg");
        image2->setPixmap(((*newmap2).scaled(300,300,Qt::KeepAspectRatio)));
        image2->setFixedSize(300,300);
        text2->setText("After all of airplanes go to destinations, that player won \n and the rest of players continue their game");
        counter++;
    }
}

void rules::on_toolButton_3_clicked()
{
    this->hide();
}
