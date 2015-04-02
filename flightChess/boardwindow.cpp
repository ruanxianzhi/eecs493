#include "boardwindow.h"
#include "widget.h"
#include <QSplitter>
#include <QtWidgets>
#include <QToolButton>
#include <QFrame>

extern int justclicked;
extern QTimer* timer;
extern QTimer *uptimer;
boardWindow::boardWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSplitter *splitter = new QSplitter();
    //gameplay number
    countimer = new QTimer();
    countimer->setInterval(1000);
    board *chessboard = new board(4);

    splitter->addWidget(chessboard);

    QFrame *rightbutton = new QFrame();
    QGridLayout *layout = new QGridLayout();
    rightbutton->setLayout(layout);
    timeremain = new QLabel("10");
    QFrame *innerWidget = new QFrame();
    innerLayout = new QGridLayout();
    innerWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    innerWidget->setLayout(innerLayout);
    innerLayout->addWidget(timeremain);

    for (int i=0;i<5;i++) {
        button[i] = new QToolButton();
        button[i]->setFixedSize(150,75);
        button[i]->setEnabled(false);
        innerLayout->addWidget(button[i],i,0);
    }
    button[0]->setText("0");
    button[1]->setText("1");
    button[2]->setText("2");
    button[3]->setText("3");
    button[4]->setText("Roll");
    button[4]->setEnabled(true);
    layout->addWidget(innerWidget,0,0, Qt::AlignTop);
    splitter->addWidget(rightbutton);

    connect(button[0], SIGNAL(clicked()), this, SLOT(choose1()));
    connect(button[1], SIGNAL(clicked()), this, SLOT(choose2()));
    connect(button[2], SIGNAL(clicked()), this, SLOT(choose3()));
    connect(button[3], SIGNAL(clicked()), this, SLOT(choose4()));
    connect(button[4], SIGNAL(clicked()), this, SLOT(rollclick()));

    connect(button[4], SIGNAL(clicked()), chessboard, SLOT(start()));
    connect(button[0], SIGNAL(clicked()), chessboard, SLOT(updateall()));
    connect(button[1], SIGNAL(clicked()), chessboard, SLOT(updateall()));
    connect(button[2], SIGNAL(clicked()), chessboard, SLOT(updateall()));
    connect(button[3], SIGNAL(clicked()), chessboard, SLOT(updateall()));
    connect(countimer, SIGNAL(timeout()), this, SLOT(updatelabel()));

    setStyleSheet("QSplitter {background-color: rgb(219, 226, 228);}");
    QList<int> sizeList = QList<int>() << 900 << 190;
    splitter->setSizes(sizeList);
    setCentralWidget(splitter);
    resize(900+200,900);
}

boardWindow::~boardWindow()
{
}

void boardWindow::rollclick(){
    justclicked = 0;
}

void boardWindow::choose1(){
    justclicked = 0;
    cerr<<"choose 1\n";
}

void boardWindow::choose2(){
    justclicked = 1;
    cerr<<"choose 2\n";
}

void boardWindow::choose3(){
    justclicked = 2;
}

void boardWindow::choose4(){
    justclicked = 3;
}

void boardWindow::updatelabel(){
    if(uptimer->isActive()){
        timeremain->setText(QString::number(uptimer->remainingTime()));
        innerLayout->addWidget(timeremain);
    }
}
