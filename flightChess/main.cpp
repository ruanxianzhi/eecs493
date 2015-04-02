#include "boardwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    boardWindow w;
    w.setWindowTitle(QObject::tr("Flight Chess"));
    w.show();

    return a.exec();
}
