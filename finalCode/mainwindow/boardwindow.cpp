#include "boardwindow.h"
#include "widget.h"
#include <QSplitter>
#include <QtWidgets>
#include <QToolButton>
#include <QFrame>

extern int justclicked;
extern QString username[4];

boardWindow::boardWindow(QString redname,QString yellowname, QString greenname,QString bluename,QWidget *parent)
    : QMainWindow(parent)
{
    move (150,50);
    setWindowTitle("3D Flight Chess");
    splitter = new QSplitter();
    in = new board(4);
    splitter->addWidget(in);

    QFrame *rightbutton = new QFrame();
    QGridLayout *layout = new QGridLayout();
    rightbutton->setLayout(layout);
    QFrame *innerWidget = new QFrame();
    innerLayout = new QGridLayout();
    innerWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    innerWidget->setLayout(innerLayout);
    innerLayout->setRowStretch(3,1);
    username[0] = redname;
    username[1] = yellowname;
    username[2] = greenname;
    username[3] = bluename;
    uselessbutton = new QLabel;

    puretext = new QLabel();
    puretext->setFixedSize(70,30);
    puretext->setText("Turn:");
    hiscolor = new QLabel();
    currentuser = new QLabel();
    currentuser->setFixedSize(100,50);
    hiscolor->setFixedSize(20,20);
    hiscolor->setStyleSheet("QLabel { background-color : red;}");
    currentuser->setText(username[0]);
    QFont font;
    font.setFamily("HanziPen SC");
    font.setPointSize(26);
    currentuser->setFont(font);
    puretext->setFont(font);
    

    for (int i=0;i<4;i++) {
        button[i] = new QToolButton();
        button[i]->setFixedSize(75,75);
        button[i]->setEnabled(false);
        innerLayout->addWidget(button[i],i/2,i%2);
    }


    button[4] = new QToolButton();
    button[4]->setFixedSize(75,75);
    button[4]->setEnabled(false);

    button[0]->setText("0");
    button[1]->setText("1");
    button[2]->setText("2");
    button[3]->setText("3");
    button[4]->setText("ROLL");
    button[4]->setEnabled(true);

    innerLayout->addWidget(button[4],3,0,1,2,Qt::AlignCenter);
    uselessbutton->setFixedSize(30,80);
    innerLayout->addWidget(uselessbutton,4,0);
    button[4]->setStyleSheet("border: 2px solid #8f8f91; border-radius: 20px");
    button[4]->setFont(font);
    innerLayout->addWidget(puretext,5,0,1,2,Qt::AlignLeft);
    innerLayout->addWidget(hiscolor,6,0);
    innerLayout->addWidget(currentuser,6,1,Qt::AlignLeft);
    dice = new QLabel();
    dice->setFixedSize(75, 75);
    innerLayout->addWidget(dice,7,0,1,2,Qt::AlignCenter);

    layout->addWidget(innerWidget,0,0, Qt::AlignTop);
    splitter->addWidget(rightbutton);


    QList<int> sizeList = QList<int>() << 600 << 300;
    splitter->setSizes(sizeList);
    setCentralWidget(splitter);
    resize(900,600);
}

boardWindow::~boardWindow()
{
}

void boardWindow:: changeturn( int color){
    if (color == 0){
        hiscolor->setStyleSheet("QLabel { background-color : red;}");
    }
    else if (color == 1)
        hiscolor->setStyleSheet("QLabel { background-color : yellow;}");
    else if (color == 2)
        hiscolor->setStyleSheet("QLabel { background-color : green;}");
    else if (color == 3)
        hiscolor->setStyleSheet("QLabel { background-color : blue;}");
    if(color >=0 && color <4)
        currentuser->setText(username[color]);
}
