#ifndef CHESS_H
#define CHESS_H
#include <QWidget>
#include <QGLWidget>
#include <QMouseEvent>
#include <QColorDialog>
#include <glu.h>


class chess : public QGLWidget
{
    Q_OBJECT
    int number;
    bool passstart;
    bool state2;//nextoneminus
    float currentx;
    float currenty;
    float speedx;
    float speedy;
    int t;
    int forward;
    int nextone;
    int jumposition;
    float height2;
public:
    int counter;
    int color;
    int state;
    int position;
    int nextposition;
    float height;
    chess(int colorint, int order, QGLWidget *parent = 0);
    ~chess();
    void draw();
    void calculatingnext(int forward);
    void calculatingnextone();
public slots:
    void move();

};

#endif // CHESS_H

