#include "widget.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "game.h"

extern QTimer *timer;
extern QTimer *uptimer;
extern QTimer *updatetimer;
extern int justclicked;

board::board(int player, QWidget *parent)
    : QGLWidget(parent)
{
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
    numplayer = player;
    lastcolor = 0;
    rotationX = -30.0;
    rotationY = 0.0;
    rotationZ = 0.0;
    clicked = -1;
    choose = -1;
    newgame = new game(numplayer,1);
    newgame->init();

    timer = new QTimer();
    timer->setInterval(10000);
    connect(timer, SIGNAL(timeout()), this, SLOT(start()));

    timer->start();

}

void board::initializeGL()
{
    qglClearColor(Qt::gray);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void board::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat x = GLfloat(width) / height;
    glFrustum(-x*5.0, +x*5.0, -5.0, +5.0, 7.0, 34.0);
    glMatrixMode(GL_MODELVIEW);
}

void board::paintGL()
{
    draw();
    for (int i=0; i<numplayer; i++) {
        for (int j=0; j<4; j++) {
          newgame->allparty[i]->ownchess[j]->draw();
        }
    }
}

void board::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -24.0);
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    glRotatef(rotationZ, 0.0, 0.0, 1.0);
//------------------------------------------
    glActiveTexture(GL_TEXTURE0);
    glEnable(GL_TEXTURE_2D);
    bindTexture(QImage("/Users/chuanshunxia/Documents/courses/EECS493/Final project/493final/493_final_v0.7/image/modified.png"));
    glBegin(GL_QUADS);
          // Up face (y = 1.0f)
          qglColor(Qt::white);
          glTexCoord2f(0.0, 0.0);glVertex3f( 10.0f,  10.0f, 1.0f);
          glTexCoord2f(1.0, 0.0);glVertex3f(-10.0f,  10.0f, 1.0f);
          glTexCoord2f(1.0, 1.0);glVertex3f(-10.0f, -10.0f, 1.0f);
          glTexCoord2f(0.0, 1.0);glVertex3f( 10.0f, -10.0f, 1.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
          // Bottom face (y = 1.0f)
          qglColor(Qt::white);
          glVertex3f( 10.0f, -10.0f, -1.0f);
          glVertex3f(-10.0f, -10.0f, -1.0f);
          glVertex3f(-10.0f,  10.0f, -1.0f);
          glVertex3f( 10.0f,  10.0f, -1.0f);

          // Front face  (z = 1.0f)
          qglColor(Qt::red);
          glVertex3f( 10.0f, -10.0f,  1.0f);
          glVertex3f( 0.0f, -10.0f,  1.0f);
          glVertex3f( 0.0f, -10.0f, -1.0f);
          glVertex3f( 10.0f, -10.0f, -1.0f);
          qglColor(Qt::yellow);
          glVertex3f( 0.0f, -10.0f,  1.0f);
          glVertex3f(-10.0f, -10.0f,  1.0f);
          glVertex3f(-10.0f, -10.0f, -1.0f);
          glVertex3f( 0.0f, -10.0f, -1.0f);

          // Back face (z = -1.0f)
          qglColor(Qt::blue);
          glVertex3f( 10.0f, 10.0f, -1.0f);
          glVertex3f( 0.0f, 10.0f, -1.0f);
          glVertex3f( 0.0f, 10.0f,  1.0f);
          glVertex3f( 10.0f, 10.0f,  1.0f);
          qglColor(Qt::green);
          glVertex3f( 0.0f, 10.0f, -1.0f);
          glVertex3f(-10.0f, 10.0f, -1.0f);
          glVertex3f(-10.0f, 10.0f,  1.0f);
          glVertex3f( 0.0f, 10.0f,  1.0f);

          // Right face (x = -1.0f)
          qglColor(Qt::blue);
          glVertex3f(10.0f,  10.0f,  1.0f);
          glVertex3f(10.0f,  0.0f,  1.0f);
          glVertex3f(10.0f,  0.0f, -1.0f);
          glVertex3f(10.0f,  10.0f, -1.0f);
          qglColor(Qt::red);
          glVertex3f(10.0f,  0.0f,  1.0f);
          glVertex3f(10.0f, -10.0f,  1.0f);
          glVertex3f(10.0f, -10.0f, -1.0f);
          glVertex3f(10.0f,  0.0f, -1.0f);

          // Left face (x = 1.0f)
          qglColor(Qt::green);
          glVertex3f(-10.0f,  0.0f,  1.0f);
          glVertex3f(-10.0f,  10.0f,  1.0f);
          glVertex3f(-10.0f,  10.0f, -1.0f);
          glVertex3f(-10.0f,  0.0f, -1.0f);
          qglColor(Qt::yellow);
          glVertex3f(-10.0f, -10.0f,  1.0f);
          glVertex3f(-10.0f,  0.0f,  1.0f);
          glVertex3f(-10.0f,  0.0f, -1.0f);
          glVertex3f(-10.0f, -10.0f, -1.0f);
       glEnd();  // End of drawing color-cube

}

void board::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void board::mouseMoveEvent(QMouseEvent *event)
{
    GLfloat dx = GLfloat(event->x() - lastPos.x()) / width();
    GLfloat dy = GLfloat(event->y() - lastPos.y()) / height();
    if (event->buttons() & Qt::LeftButton) {
        rotationX += 180 * dy;
        rotationZ += 180 * dx;
        updateGL();
    } else if (event->buttons() & Qt::RightButton) {
        rotationX += 180 * dy;
        rotationY += 180 * dx;
        updateGL();
    }
    lastPos = event->pos();
}


void board::wait(){
    cerr<<"waiting\n";
    if(waitcount==10){
        waitcount = 0;
        uptimer->stop();
    }
    else{
        waitcount++;
    }
}

void board::start(){
    for(int i = 0; i < 4; i++){
        window->button[i]->setEnabled(false);
    }
    window->button[4]->setEnabled(true);
    if(newgame->isEnd()){
            updatetimer->stop();
            return;
    }
    timer->stop();
    uptimer = new QTimer();
    uptimer->start();
    uptimer->setInterval(10000);

            lastroll = beginroll();
            cerr<<lastroll<<"\n";
            int j = 0;
            if(lastroll!=6){
                for(int i = 0; i < 4; i++){
                    if(newgame->allparty[lastcolor]->ownchess[i]->state != 0 &&
                            newgame->allparty[lastcolor]->ownchess[i]->state != 4){
                        window->button[i]->setEnabled(true);
                        j++;
                    }
                }
            }
            else{
                for(int i = 0; i < 4; i++){
                    if(newgame->allparty[lastcolor]->ownchess[i]->state != 4){
                        window->button[i]->setEnabled(true);
                    }
                }
                j = 1;
            }
            if(j == 0){
                uptimer->stop();
                if(lastcolor == numplayer-1) lastcolor = 0;
                else lastcolor++;
            }
            connect(uptimer, SIGNAL(timeout()), this, SLOT(updateall()));
            multi.insert(newgame->allparty[lastcolor]->ownchess[justclicked]->nextposition, newgame->allparty[lastcolor]->ownchess[justclicked]);

}

void board::updateall(){
    update(lastcolor, lastroll, justclicked);
}

void board::update(int numcolor, int numstep, int whichchess){
    window->button[4]->setEnabled(false);
    chess *inchess = newgame->allparty[lastcolor]->ownchess[whichchess];
    if(numstep!=-1){
    newgame->allparty[numcolor]->ownchess[whichchess]->calculatingnext(numstep);
    multi.remove(newgame->allparty[numcolor]->ownchess[whichchess]->position, newgame->allparty[numcolor]->ownchess[whichchess]);


    /*          if(multi.find(newgame->allparty[lastcolor]->ownchess[0]->nextposition)!=multi.end()
    //                    && multi.value(newgame->allparty[lastcolor]->ownchess[0]->nextposition)->getcolor()!=lastcolor)
    //            {
    //                QList<chess*> values = multi.values(newgame->allparty[lastcolor]->ownchess[0]->nextposition);
    //                for(int i = 0; i < values.size(); i++){
    //                    if(values.at(i)->getcolor()!=lastcolor){
    //                        multi.remove(newgame->allparty[lastcolor]->ownchess[0]->nextposition, values.at(i));
    //                        values.at(i)->calculatingnext(7);
    //                        updateall(values.at(i));
    //                    }
    //                }
                } */

    if(inchess->position!=inchess->nextposition){
    updatetimer = new QTimer();
    updatetimer->setInterval(100);
    timer->stop();
    updatetimer->start();
    connect(updatetimer, SIGNAL(timeout()), newgame->allparty[lastcolor]->ownchess[whichchess], SLOT(move()));
    connect(updatetimer, SIGNAL(timeout()), this, SLOT(updateGL()));
    }
    if(numstep!=6){
         if(lastcolor == numplayer-1) lastcolor = 0;
         else lastcolor++;
    }
    lastroll = -1;
    }
    window->button[4]->setEnabled(true);
}

int board::beginroll(){
    return rand() % 6 +1;
}

