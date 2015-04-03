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
    bool passstart;
    float currentx;
    float currenty;
    float speedx;
    float speedy;
    QImage *image;

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[4];
    QPoint lastPos;

public:
    int state;
    bool state2;//nextoneminus
    int t;
    int forward;
    int number;
    int position;
    int nextone;
    int nextposition;
    //At home:0, Normal:1; In "protection":2;
    chess(int colorint, int order, QGLWidget *parent = 0);
    ~chess();
    void draw();
    int getcolor(){
        return color;
    }

    void calculatingnext(int forward);
    void calculatingnextone();
public slots:
    void move();

protected:

};

#endif // CHESS_H

