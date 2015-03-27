#include "widget.h"
#include "time.h"
#include <QtWidgets>

#include <QApplication>

extern QTimer* timer;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!QGLFormat::hasOpenGL()) {
        //std::cerr << "This system has no OpenGL support" << std::endl;
        return 1;
    }

    Tetrahedron tetrahedron;
    tetrahedron.setWindowTitle(QObject::tr("Tetrahedron"));
    tetrahedron.resize(900, 900);

    tetrahedron.show();
    //QTimer *ti = new QTimer();
    timer->start(1000);

    return app.exec();
}
