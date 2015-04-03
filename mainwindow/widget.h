#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QMouseEvent>
#include <QColorDialog>
#include <QMultiMap>
#include <glu.h>
#include "game.h"
#include "boardwindow.h"

class board : public QGLWidget
{
    Q_OBJECT

public:
    board(int player, boardWindow* windowparent=0,QWidget *parent = 0);
    boardWindow* window;
    int clicked;
    int choose;
    game *newgame;
    int numplayer;
    void update(int numcolor, int numstep, int whichchess);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //void mouseDoubleClickEvent(QMouseEvent *event);

private:
    QMultiMap<int, chess*> multi;
    void draw();
    int lastroll = -1;
    int waitcount = 0;
    int lastcolor;

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QPoint lastPos;

public slots:
     void start();
     int beginroll();
     void wait();
     void updateall();
};
#endif // WIDGET_H
