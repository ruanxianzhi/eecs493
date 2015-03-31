#ifndef WAITINGROOM_H
#define WAITINGROOM_H

#include <QDialog>

namespace Ui {
class waitingroom;
}

class waitingroom : public QDialog
{
    Q_OBJECT

public:
    explicit waitingroom(QWidget *parent = 0);
    ~waitingroom();
    Ui::waitingroom *ui;
    bool updateUser(QString userName,QString localHostName,QString ipAddress);
};

#endif // WAITINGROOM_H
