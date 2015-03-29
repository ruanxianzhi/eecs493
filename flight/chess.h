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
    int color;
    //Red:0, Yellow:1, Green:2, Blue:3
    int position;
    int nextposition;
    int number;
    bool passstart;
    QImage *image;

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[4];
    QPoint lastPos;

public:
    int state;
    //At home:0, Normal:1; In "protection":2;
    chess(int colorint, int order);
    ~chess();
    void calculatingnext(int);

public slots:
    void move();

};

#endif // CHESS_H

