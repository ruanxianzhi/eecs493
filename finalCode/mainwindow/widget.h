#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QMouseEvent>
#include <QColorDialog>
#include <QMultiMap>
#include <glu.h>
#include "game.h"


class board : public QGLWidget
{
    Q_OBJECT

public:
    board(int player, QWidget *parent = 0);
    ~board();
    game *newgame;
    int numplayer;
    GLfloat rotationZ;
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

    GLfloat rotationX;
    GLfloat rotationY;
    QPoint lastPos;
};
#endif // WIDGET_H
