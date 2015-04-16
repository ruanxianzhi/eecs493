#include "widget.h"
#include <cstdio>
#include <stdlib.h>
#include "game.h"

extern QTimer *updatetimer;
extern QTimer *backtimer;
extern int justclicked;
extern bool boom;
extern bool finish;

board::board(int player, QWidget *parent)
    : QGLWidget(parent)
{
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
    numplayer = player;
    rotationX = -30.0;
    rotationY = 0.0;
    rotationZ = 0.0;

    newgame = new game(numplayer,1);

    newgame->init();

}

board::~board(){
    delete this;
}

void board::initializeGL()
{
    qglClearColor(QColor(207,237,252));
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
    bindTexture(QImage(":/image/modified.png"));
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
          qglColor(QColor(200,76,70));
          glVertex3f( 10.0f, -10.0f,  1.0f);
          glVertex3f( 0.0f, -10.0f,  1.0f);
          glVertex3f( 0.0f, -10.0f, -1.0f);
          glVertex3f( 10.0f, -10.0f, -1.0f);
          qglColor(QColor(244,188,88));
          glVertex3f( 0.0f, -10.0f,  1.0f);
          glVertex3f(-10.0f, -10.0f,  1.0f);
          glVertex3f(-10.0f, -10.0f, -1.0f);
          glVertex3f( 0.0f, -10.0f, -1.0f);

          // Back face (z = -1.0f)
          qglColor(QColor(35,148,147));
          glVertex3f( 10.0f, 10.0f, -1.0f);
          glVertex3f( 0.0f, 10.0f, -1.0f);
          glVertex3f( 0.0f, 10.0f,  1.0f);
          glVertex3f( 10.0f, 10.0f,  1.0f);
          qglColor(QColor(163,189,110));
          glVertex3f( 0.0f, 10.0f, -1.0f);
          glVertex3f(-10.0f, 10.0f, -1.0f);
          glVertex3f(-10.0f, 10.0f,  1.0f);
          glVertex3f( 0.0f, 10.0f,  1.0f);

          // Right face (x = -1.0f)
          qglColor(QColor(35,148,147));
          glVertex3f(10.0f,  10.0f,  1.0f);
          glVertex3f(10.0f,  0.0f,  1.0f);
          glVertex3f(10.0f,  0.0f, -1.0f);
          glVertex3f(10.0f,  10.0f, -1.0f);
          qglColor(QColor(200,76,70));
          glVertex3f(10.0f,  0.0f,  1.0f);
          glVertex3f(10.0f, -10.0f,  1.0f);
          glVertex3f(10.0f, -10.0f, -1.0f);
          glVertex3f(10.0f,  0.0f, -1.0f);

          // Left face (x = 1.0f)
          qglColor(QColor(163,189,110));
          glVertex3f(-10.0f,  0.0f,  1.0f);
          glVertex3f(-10.0f,  10.0f,  1.0f);
          glVertex3f(-10.0f,  10.0f, -1.0f);
          glVertex3f(-10.0f,  0.0f, -1.0f);
          qglColor(QColor(244,188,88));
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

void board::update(int numcolor, int numstep, int whichchess){
    cerr<<"color: "<<numcolor<<"roll: "<<numstep<<"number: "<<whichchess<<"\n";

    chess *inchess = newgame->allparty[numcolor]->ownchess[whichchess];
    if(numstep!=-1){
    newgame->allparty[numcolor]->ownchess[whichchess]->counter = numstep;
    newgame->allparty[numcolor]->ownchess[whichchess]->calculatingnext(numstep);
    multi.remove(newgame->allparty[numcolor]->ownchess[whichchess]->position, newgame->allparty[numcolor]->ownchess[whichchess]);
    newgame->allparty[numcolor]->ownchess[whichchess]->height = 1.0f;

             if(multi.find(newgame->allparty[numcolor]->ownchess[whichchess]->nextposition)!=multi.end() &&
                     (newgame->allparty[numcolor]->ownchess[whichchess]->nextposition!=-1))
                {
                    QList<chess*> values = multi.values(newgame->allparty[numcolor]->ownchess[whichchess]->nextposition);
                    for(int i = 0; i < values.size(); i++){
                        if(values.at(i)->color!=numcolor){
                            multi.remove(newgame->allparty[numcolor]->ownchess[whichchess]->nextposition, values.at(i));
                            values.at(i)->calculatingnext(7);
                            values.at(i)->counter = 1;

                            backtimer->setInterval(100);
                            boom=1;
                            connect(backtimer, SIGNAL(timeout()), values.at(i), SLOT(move()));
                            connect(backtimer, SIGNAL(timeout()), this, SLOT(updateGL()));
                        }
                        else{
                            newgame->allparty[numcolor]->ownchess[whichchess]->height += 0.33f;
                        }
                    }
                }
             else{
                 newgame->allparty[numcolor]->ownchess[whichchess]->height = 1.0f;
             }


             if(newgame->allparty[numcolor]->isFinish()){
                 finish = 1;
             }
        if(inchess->position!=inchess->nextposition){
            updatetimer = new QTimer();
            updatetimer->setInterval(100);
            updatetimer->start();
            multi.insert(newgame->allparty[numcolor]->ownchess[whichchess]->nextposition, newgame->allparty[numcolor]->ownchess[whichchess]);
            connect(updatetimer, SIGNAL(timeout()), newgame->allparty[numcolor]->ownchess[whichchess], SLOT(move()));
            connect(updatetimer, SIGNAL(timeout()), this, SLOT(updateGL()));
        }
    }
}



