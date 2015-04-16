#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QGLWidget>
#include <QToolButton>
#include "widget.h"
class boardWindow : public QMainWindow
{
    Q_OBJECT
    QGridLayout *innerLayout;


public:
    board *in;
    boardWindow(QString redname = "",QString yellowname = "", QString greenname = "",QString bluename = "",QWidget *parent = 0);
    ~boardWindow();
    QSplitter *splitter;
    QToolButton *button[5];
    QLabel *dice;
    QLabel *currentuser;
    QLabel *hiscolor;
    QLabel *puretext;
    QLabel *uselessbutton;
    void changeturn( int color);
};

#endif // BOARDWINDOW_H
