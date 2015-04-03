#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QGLWidget>
#include <QToolButton>

class boardWindow : public QMainWindow
{
    Q_OBJECT
    QLabel *timeremain;
    QTimer *countimer;
    QGridLayout *innerLayout;

    //board *in;
public:
    boardWindow(QWidget *parent = 0);
    ~boardWindow();
    QToolButton *button[5];
public slots:
    void rollclick();
    void choose1();
    void choose2();
    void choose3();
    void choose4();
    void updatelabel();
};

#endif // BOARDWINDOW_H
