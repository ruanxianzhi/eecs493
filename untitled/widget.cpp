#include "widget.h"
#include <iostream>
#include <cstdio>
#include <QMovie>
#include "game.h"

extern QTimer* timer;

Tetrahedron::Tetrahedron(QWidget *parent)
    : QGLWidget(parent)
{
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));

    rotationX = 57.0;
    rotationY = -77.0;
    rotationZ = 0.0;
}

void Tetrahedron::initializeGL()
{
    qglClearColor(Qt::gray);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void Tetrahedron::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat x = GLfloat(width) / height;
    glFrustum(-x, +x, -1.0, +1.0, 4.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

void Tetrahedron::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();
}

void Tetrahedron::draw()
{
    GLuint texture;

    //setStyleSheet("background-image: /Users/muyidi/Desktop/untitled/image/7.png;");
    glActiveTexture(GL_TEXTURE0);
<<<<<<< HEAD
=======
    glEnable(GL_TEXTURE_2D);
    //QMovie *movie = new QMovie("/Users/muyidi/Desktop/untitled/image/3.gif");
    texture = bindTexture(QImage(":/image/3.gif"));
    //movie->start();
    glBegin(GL_QUADS);
          // Top face (y = 0.1f)
          qglColor(Qt::white);
          glTexCoord2f(0.0, 0.0);glVertex2f(-5.0f, -5.0f);
          glTexCoord2f(1.0, 0.0);glVertex2f(-5.0f, 5.0f);
          glTexCoord2f(1.0, 1.0);glVertex2f(5.0f, 5.0f);
          glTexCoord2f(0.0, 1.0);glVertex2f(5.0f, -5.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
>>>>>>> origin/master

    glEnable(GL_TEXTURE_2D);
    texture = bindTexture(QImage(":/image/modified.png"));

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    glRotatef(rotationZ, 0.0, 0.0, 1.0);
//------------------------------------------
    glBegin(GL_QUADS);
          // Top face (y = 0.1f)
          qglColor(Qt::white);
          glTexCoord2f(0.0, 0.0);glVertex3f( 1.0f, 0.1f, -1.0f);
          glTexCoord2f(1.0, 0.0);glVertex3f(-1.0f, 0.1f, -1.0f);
          glTexCoord2f(1.0, 1.0);glVertex3f(-1.0f, 0.1f,  1.0f);
          glTexCoord2f(0.0, 1.0);glVertex3f( 1.0f, 0.1f,  1.0f);

          // Bottom face (y = -0.1f)
          qglColor(Qt::white);
          glVertex3f( 1.0f, -0.1f,  1.0f);
          glVertex3f(-1.0f, -0.1f,  1.0f);
          glVertex3f(-1.0f, -0.1f, -1.0f);
          glVertex3f( 1.0f, -0.1f, -1.0f);

          // Front face  (z = 1.0f)
          qglColor(Qt::red);
          glTexCoord2f(0.0, 0.0);glVertex3f( 1.0f,  0.1f, 1.0f);
          glTexCoord2f(1.0, 0.0);glVertex3f( 0.0f,  0.1f, 1.0f);
          glTexCoord2f(1.0, 1.0);glVertex3f( 0.0f, -0.1f, 1.0f);
          glTexCoord2f(0.0, 1.0);glVertex3f( 1.0f, -0.1f, 1.0f);
          // Front face  (z = 1.0f)
          qglColor(Qt::yellow);
          glVertex3f( 0.0f,  0.1f, 1.0f);
          glVertex3f(-1.0f,  0.1f, 1.0f);
          glVertex3f(-1.0f, -0.1f, 1.0f);
          glVertex3f( 0.0f, -0.1f, 1.0f);

          // Back face (z = -1.0f)
          qglColor(Qt::green);
          glVertex3f( 1.0f, -0.1f, -1.0f);
          glVertex3f( 0.0f, -0.1f, -1.0f);
          glVertex3f( 0.0f,  0.1f, -1.0f);
          glVertex3f( 1.0f,  0.1f, -1.0f);
          // Back face (z = -1.0f)
          qglColor(Qt::blue);
          glVertex3f( 0.0f, -0.1f, -1.0f);
          glVertex3f(-1.0f, -0.1f, -1.0f);
          glVertex3f(-1.0f,  0.1f, -1.0f);
          glVertex3f( 0.0f,  0.1f, -1.0f);

          // Left face (x = -1.0f)
          qglColor(Qt::yellow);
          glVertex3f(-1.0f,  0.1f,  1.0f);
          glVertex3f(-1.0f,  0.1f,  0.0f);
          glVertex3f(-1.0f, -0.1f,  0.0f);
          glVertex3f(-1.0f, -0.1f,  1.0f);
          // Left face (x = -1.0f)
          qglColor(Qt::blue);
          glVertex3f(-1.0f,  0.1f,  0.0f);
          glVertex3f(-1.0f,  0.1f, -1.0f);
          glVertex3f(-1.0f, -0.1f, -1.0f);
          glVertex3f(-1.0f, -0.1f,  0.0f);

          // Right face (x = 1.0f)
          qglColor(Qt::red);
          glVertex3f(1.0f,  0.1f,  0.0f);
          glVertex3f(1.0f,  0.1f,  1.0f);
          glVertex3f(1.0f, -0.1f,  1.0f);
          glVertex3f(1.0f, -0.1f,  0.0f);
          // Right face (x = 1.0f)
          qglColor(Qt::green);
          glVertex3f(1.0f,  0.1f, -1.0f);
          glVertex3f(1.0f,  0.1f,  0.0f);
          glVertex3f(1.0f, -0.1f,  0.0f);
          glVertex3f(1.0f, -0.1f, -1.0f);
       glEnd();  // End of drawing color-cube
  //--------------------------------------------
       glBegin(GL_QUADS);
             // Top face (y = 0.1f)

             qglColor(Qt::white);
             glTexCoord2f(0.0, 0.0);glVertex3f( 0.2f, 0.11f, 0.1f);
             glTexCoord2f(1.0, 0.0);glVertex3f(0.1f, 0.11f, 0.1f);
             glTexCoord2f(1.0, 1.0);glVertex3f(0.1f, 0.11f,  0.2f);
             glTexCoord2f(0.0, 1.0);glVertex3f( 0.2f, 0.11f,  0.2f);
             //connect(timer, SIGNAL(timeout()), this, SLOT(move()));

             game *newgame = new game(1,1);
             newgame->init();
       glEnd();
       glDisable(GL_TEXTURE_2D);
}

void Tetrahedron::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void Tetrahedron::mouseMoveEvent(QMouseEvent *event)
{
    GLfloat dx = GLfloat(event->x() - lastPos.x()) / width();
    GLfloat dy = GLfloat(event->y() - lastPos.y()) / height();
    if (event->buttons() & Qt::LeftButton) {
        rotationX += 180 * dy;
        rotationY += 180 * dx;
        updateGL();
    } else if (event->buttons() & Qt::RightButton) {
        rotationX += 180 * dy;
        rotationZ += 180 * dx;
        updateGL();
    }
    lastPos = event->pos();
}

void Tetrahedron::mouseDoubleClickEvent(QMouseEvent *event)
{
    int face = faceAtPosition(event->pos());
    if (face != -1) {
        QColor color = QColorDialog::getColor(faceColors[face], this);
        if (color.isValid()) {
            faceColors[face] = color;
            updateGL();
        }
    }
}

int Tetrahedron::faceAtPosition(const QPoint &pos)
{
    const int MaxSize = 512;
    GLuint buffer[MaxSize];
    GLint viewport[4];

    makeCurrent();

    glGetIntegerv(GL_VIEWPORT, viewport);
    glSelectBuffer(MaxSize, buffer);
    glRenderMode(GL_SELECT);

    glInitNames();
    glPushName(0);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix(GLdouble(pos.x()), GLdouble(viewport[3] - pos.y()),
                  5.0, 5.0, viewport);
    GLfloat x = GLfloat(width()) / height();
    glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0);
    draw();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    if (!glRenderMode(GL_RENDER))
        return -1;
    return buffer[3];
}
